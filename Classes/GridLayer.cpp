//
//  GridLayer.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/2/24.
//
//

#include "GridLayer.h"
#include "Global.h"
#include "FoodSprite.h"
#include "SpikeSprite.h"
#include "MainScene.h"
#include "PlayerSprite.h"
#include "Common.h"
#include "MainSprite.h"
#include "Resources.h"

#define BACKGROUND_WIDTH winSize.width * 10
#define BACKGROUND_HEIGHT winSize.height * 10
#define GRID_SIDE 20

#define BACK_IMG_FILE_PRE  "Big_color_"
#define FRONT_IMG_FILE_PRE  "hero_"
#define NEED_ANIM_SCALE_DIFF    25
#define UPDATE_SPRITE_SCALE_DURATION    0.004

GridLayer::GridLayer()
{
    eats.clear();
    nodes.clear();
    unVisibles.clear();
    mBatch.clear();
    m_cameraScale = 1;
    
//    m_node_win_diff = ccp(winSize.width * 0.5f, winSize.height * 0.5f);
    m_node_win_diff = ccp(0,0);
    //setScale(1.14);
    
    // test
//    tempTime = 0;
//    currentTime= 0;
//    index = 0;
    
#ifdef EditEXE
    mass = 10;
    schedule(schedule_selector(GridLayer::updateMain), 0.3f);
#endif
}

GridLayer::~GridLayer()
{
    eats.clear();
    nodes.clear();
    unVisibles.clear();
    mBatch.clear();
}

bool GridLayer::init()
{
    if(!CCLayer::init())
        return false;
    
    width = Global::getInstance()->GetGridSize().width;
    height = Global::getInstance()->GetGridSize().height;
    m_topNum = width / GRID_SIDE;
    m_leftNum = height / GRID_SIDE;
    
    createMap();
    
    char temp[32] = {0};
    for (int i = 0; i<8; i++) {
        sprintf(temp, "color_%d.png",i);
        CCSpriteBatchNode* bach = CCSpriteBatchNode::create(temp);
        addChild(bach,3);
        mBatch.push_back(bach);
    }
    //CCSprite* center = CCSprite::create("hecheng-xx-01.png");
    //addChild(center, 200, 0);
    return true;
}

/*
void GridLayer::draw()
{
    float beginX = 0;
    float endX = width;
    float beginY = 0;
    float endY = height;
    float difY = beginY;
    
    for(int i = 0; i < m_leftNum; ++i)
    {
        //ccDrawColor4B(200, 200, 200, 50);
        ccDrawColor4B(255, 0, 0, 255);
        ccDrawLine(ccp(beginX, difY), ccp(endX, difY));
        difY += GRID_SIDE;
    }
    
    float difX = beginX;
    for(int i = 0; i < m_topNum; ++i)
    {
        ccDrawColor4B(255, 0, 0, 255);
        //ccDrawColor4B(200, 200, 200, 50);
        ccDrawLine(ccp(difX, beginY), ccp(difX, endY));
        difX += GRID_SIDE;
    }
}
 */

void GridLayer::createMap()
{
    //CCLayerColor* color = CCLayerColor::create(ccc4(237, 242, 221, 255), width + 2000, height + 2000);
    //color->setPosition(ccp(-1000,-1000));
    //addChild(color,1);
    
    // 创建底图 随便大小
    CCSprite* bg1 = CCSprite::create("bg1.png");
    CCSize content = bg1->getContentSize();
    
    CCSize gridSize = Global::getInstance()->GetGridSize();
    
    CCPoint posB = ccp(content.width * 0.5, content.height * 0.5);
    int xcount = gridSize.width / content.width + 1;
    int ycount = gridSize.height / content.height + 1;
    for (int i = 0; i < xcount; i++)
    {
        for(int j = 0; j < xcount; j++)
        {
            CCPoint chunkPos;
            chunkPos = ccp(posB.x + content.width * i, posB.y + content.height * j);
            CCSprite* sp = CCSprite::create("bg1.png");
            sp->setPosition(chunkPos);
            addChild(sp, 2);
        }
    }
}

void GridLayer::removeOtherChild()
{
    this->removeAllChildren();
    createMap();
}

void GridLayer::updateNodes(const WebSocket::Data &data)
{
//    struct cc_timeval now;
//    CCTime::gettimeofdayCocos2d(&now, NULL);
//    currentTime = now.tv_sec * 1000 + now.tv_usec / 1000;
//    if(currentTime - tempTime > 1000)
//    {
//        CCLog("current index is:::%d", index);
//        tempTime = currentTime;
//        index = 0;
//    }
//    else
//    {
//        index++;
//    }
    
    int headSize = sizeof(uint8_t);
    
    uint16_t desCount, unVisCount, count;
//    CCLog("data len is:%d, head size is:%d", data.len, headSize);
    if(data.len >= 4096)
    {
        CCLog("henda:::%d",data.len);
    }
    memcpy(&desCount, data.bytes + headSize , sizeof(uint16_t));
    headSize += sizeof(uint16_t);
    for(int i = 0; i < desCount; i++)
    {
        uint32_t eatID, eatedID;
        memcpy(&eatID, data.bytes + headSize, sizeof(uint32_t));
        headSize += sizeof(uint32_t);
        memcpy(&eatedID, data.bytes + headSize, sizeof(uint32_t));
        headSize += sizeof(uint32_t);
        
        eatInfo eat;
        eat.eatID = eatID;
        eat.eatedID = eatedID;
        //eats.push_back(eat);
        
        DeleteNode(eatedID);
    }
    
    memcpy(&unVisCount, data.bytes + headSize, sizeof(uint16_t));
    headSize += sizeof(uint16_t);
    for(int i = 0; i < unVisCount; i++)
    {
        uint32_t nodeid;
        memcpy(&nodeid, data.bytes + headSize, sizeof(uint32_t));
        headSize += sizeof(uint32_t);
        
//        unVisibles.push_back(nodeid);
        DeleteNode(nodeid);
    }
    
    memcpy(&count, data.bytes + headSize, sizeof(uint16_t));
    headSize += sizeof(uint16_t);
    //CCLog("update count is:%d", count);
    for(int i = 0; i < count; i++)
    {
        //release 编不过
//        nodeInfo info;
//        memcpy(&info, data.bytes + headSize, sizeof(nodeInfo));
//        //CCLog("posx is : %d, posy is: %d, id is: %d", info.posx, info.posy, info.nodeID);
//        headSize += sizeof(nodeInfo);
//        CCLog("node name len is%d", info.name_len);
//        if(info.name_len > 0)
//        {
//            memcpy(info.name, data.bytes + headSize, info.name_len);
//            headSize += info.name_len;
//        }
//        
//        CNodeInfo* node = new CNodeInfo;
//        node->SetNodeInfo(info);
//        uint32_t node_id = info.nodeID;
//        ChangeNodes(node_id, node);
        
        // 2016-3-22
        uint32_t nid;
        int32_t posx, posy;
        int16_t size;
        uint16_t index, mass;
        uint8_t r,g,b,spike,len;
        uint8_t isPlayer;
        uint32_t heroid,heroleve,guanghuan,baozi,canying,huahuan;
        
        nodeInfo info;
        
        memcpy(&nid, data.bytes + headSize, sizeof(uint32_t));
        headSize += sizeof(uint32_t);
        memcpy(&posx, data.bytes + headSize, sizeof(int32_t));
        headSize += sizeof(int32_t);
        memcpy(&posy, data.bytes + headSize, sizeof(int32_t));
        headSize += sizeof(int32_t);
        memcpy(&size, data.bytes + headSize, sizeof(int16_t));
        headSize += sizeof(int16_t);
        memcpy(&index, data.bytes + headSize, sizeof(uint16_t));
        headSize += sizeof(uint16_t);
        memcpy(&r, data.bytes + headSize, sizeof(uint8_t));
        headSize += sizeof(uint8_t);
        memcpy(&g, data.bytes + headSize, sizeof(uint8_t));
        headSize += sizeof(uint8_t);
        memcpy(&b, data.bytes + headSize, sizeof(uint8_t));
        headSize += sizeof(uint8_t);
        memcpy(&spike, data.bytes + headSize, sizeof(uint8_t));
        headSize += sizeof(uint8_t);
        memcpy(&mass, data.bytes + headSize, sizeof(uint16_t));
        headSize += sizeof(uint16_t);
        
        memcpy(&isPlayer, data.bytes + headSize, sizeof(uint8_t));
        headSize += sizeof(uint8_t);
        
        if (isPlayer) {
            memcpy(&heroid, data.bytes + headSize, sizeof(int32_t));
            headSize += sizeof(int32_t);
            
            memcpy(&heroleve, data.bytes + headSize, sizeof(int32_t));
            headSize += sizeof(int32_t);
            
            memcpy(&guanghuan, data.bytes + headSize, sizeof(int32_t));
            headSize += sizeof(int32_t);
            
            memcpy(&baozi, data.bytes + headSize, sizeof(int32_t));
            headSize += sizeof(int32_t);
            
            memcpy(&canying, data.bytes + headSize, sizeof(int32_t));
            headSize += sizeof(int32_t);
            
            memcpy(&huahuan, data.bytes + headSize, sizeof(int32_t));
            headSize += sizeof(int32_t);
        }
        
        memcpy(&len, data.bytes + headSize, sizeof(uint8_t));
        headSize += sizeof(uint8_t);
        
 //       CCLog("index is:%d, id is:%d, posx is:%d, posy is:%d, size is:%d, index is:%d, r is:%d, g is:%d, b is:%d, spike is:%d, len is:%d", i, nid, posx, posy, size, index, r, g, b, spike, len);
        
        info.nodeID = nid;
        info.posx = posx;
        info.posy = posy;
        info.size = size;
        info.indx = index;
        info.r = r;
        info.g = g;
        info.b = b;
        info.spike = spike;
        info.mass = mass;
        info.name_len = len;
        info.isPlayer = isPlayer;
        info.heroid = heroid;
        info.heroleve = heroleve;
        info.guanghuan = guanghuan;
        info.baozi = baozi;
        info.canying = canying;
        info.huahuan = huahuan;
        //CCLog("pos:%d,%d",info.posx,info.posy);
#ifdef EditEXE
        if(Global::getInstance()->IsMainNode(info.nodeID)) {
            
            float power = 0.01;
            float value = powf(mass, power);
            float size = 8354.33821 * value -8484.93574;
            info.size = size/2;
            CCLog("qiuqiu:%d",info.size);
        }
#endif
        if(len > 0)
        {
            char temp[len+1];
//            CCLog("12345:::::size if:%d, len is: %d, id is:%d", info.size, info.name_len, info.nodeID);
            memcpy(temp, data.bytes + headSize, len);
            temp[len] = '\0';
            //CCLog("temp len is:%d, temp name is:%s", len, temp);
            headSize += len;
            info.name = temp;
        }
        
//        CCLog("head size is:%d", headSize);
        
        CNodeInfo* node = new CNodeInfo;
        node->SetNodeInfo(info);
        uint32_t node_id = info.nodeID;
        ChangeNodes(node_id, node);
    }
//    CCLog("end!!!!!");

}
#ifdef EditEXE
void GridLayer::updateMain(float ft)
{
    if(mass < 22500)
        mass += 100;
    
    MainScene* pScene = dynamic_cast<MainScene*>(getParent());
    if(pScene)
    {
        pScene->UpdataWeight(mass);
    }
}
int GridLayer::getMass()
{
    return mass;
}
#endif
void GridLayer::ChangeNodes(uint32_t nodeId, CNodeInfo *node)
{
    /*
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.find(nodeId);
    if(it == nodes.end())
    {
        nodes[nodeId] = node;
        AddNode(node);
        
    }
    else
    {
        CNodeInfo* tempNode = it->second;
        it->second = node;
        delete tempNode;
        
        updateNodeState(node);
    }
    */
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.begin();
    for (; it!=nodes.end(); it++) {
        if (it->first == nodeId) {
            CNodeInfo* tempNode = it->second;
            it->second = node;
            delete tempNode;
            
            updateNodeState(node);
            break;
        }
    }

    if(it == nodes.end())
    {
        nodes[nodeId] = node;
        AddNode(node);
        
    }
}

void GridLayer::DeleteNode(uint32_t nodeID)
{
    //std::map<uint32_t, CNodeInfo*>::iterator it = nodes.find(nodeID);
    
    for (std::map<uint32_t, CNodeInfo*>::iterator i = nodes.begin(); i!=nodes.end(); ) {
        if (i->first == nodeID) {
            if(Global::getInstance()->IsMainNode(nodeID))
            {
                deleteMainNode(nodeID);
                nodes.erase(i++);
            }
            else
            {
                CCNode* other = getChildByTag(nodeID);
                if(other)
                {
                    removeChildByTag(nodeID);
                    
                }else{
                    for (int i = 0; i<8; i++) {
                        CCNode* food = mBatch[i]->getChildByTag(nodeID);
                        if(food)
                        {
                            mBatch[i]->removeChildByTag(nodeID);
                            break;
                        }
                    }
                }
                
                nodes.erase(i++);
                //CCLog("delete node node id is:%d", nodeID);
            }
        }else{
            i++;
        }
    }
    /*
    if( it != nodes.end() )
    {
        if(Global::getInstance()->IsMainNode(nodeID))
        {
            deleteMainNode(nodeID);
            nodes.erase(it);
        }
        else
        {
            removeChildByTag(nodeID);
            nodes.erase(it);
            //CCLog("delete node node id is:%d", nodeID);
        }
    }
     */
}

void GridLayer::deleteMainNode(uint32_t nodeID)
{
//    uint32_t mainNodeId = Global::getInstance()->GetMainNodeID();
//    if(nodeID == mainNodeId)
//    {
//        std::vector<uint32_t> ids = Global::getInstance()->getMainNodes();
//        std::vector<uint32_t>::iterator it = ids.begin();
//        for(; it != ids.end(); ++it)
//        {
//            uint32_t otherMainID = *it;
//            if(otherMainID != nodeID)
//            {
//                Global::getInstance()->SetMainNodeID(otherMainID);
//                std::map<uint32_t, CNodeInfo*>::iterator iter = nodes.find(otherMainID);
//                if(iter != nodes.end())
//                {
//                    CNodeInfo* node_info = iter->second;
//                    nodeInfo info = node_info->GetNodeInfo();
//                    Global::getInstance()->setMainNodeInfo(info);
//                    Global::getInstance()->SetMainPos(ccp(info.posx, info.posy));
//                }
//            }
//        }
//    }
    
    removeChildByTag(nodeID);
    MainScene* pScene = dynamic_cast<MainScene*>(getParent());
    pScene->deleteMainNode(nodeID);
    //CCLog("delete main node id is:%d", nodeID);
}

void GridLayer::AddNode(CNodeInfo* node)
{
    nodeInfo info = node->GetNodeInfo();
    
    //CCLog("node id is:%d, posx is:%d, posy is:%d size is:%d", info.nodeID, info.posx, info.posy, info.size);
    
    if(info.spike == 1)
    {
        // 刺
        SpikeSprite* spike = SpikeSprite::createSpike();
        CCPoint destPos = ccpAdd(ccp(info.posx, info.posy), m_node_win_diff);
        spike->setPosition(destPos);
        float size = (float)info.size / CI_PIX_SIZE;
        spike->setScale(size);
        addChild(spike, info.size, info.nodeID);
        
        spike->runAction(
                         CCRepeatForever::create(
                         CCSequence::create(
                         CCRotateBy::create(0.1f, -5.0f),NULL)));
    }
    else
    {
        if(info.size <= 10)
        {
            // 吃的
            
            /*
            FoodSprite* foodSprite = FoodSprite::create();

            //FoodSprite* foodSprite = FoodSprite::createWithRGB(info.indx, true);
            CCPoint destPos = ccpAdd(ccp(info.posx, info.posy), m_node_win_diff);
            foodSprite->setPosition(destPos);
            float size = (float)info.size / FOOD_PIX_SIZE;
            foodSprite->setScale(size);
            //foodSprite->setWaiguan(info.heroid, info.guanghuan, info.baozi, info.canying);
            addChild(foodSprite, 3, info.nodeID);
            item ite = Resource::sharedResource()->getItemForID(info.baozi);
            foodSprite->createWithRGB(info.indx, true,info.baozi,ite.itemIcon,info.name);
            //CCLog("food posx is:::%d, food posy is:%d", info.posx, info.posy);
             */
            
            int idx = info.indx%40;
            idx = idx%8;
            CCSprite* food = CCSprite::createWithTexture(mBatch[idx]->getTexture());
            CCPoint destPos = ccpAdd(ccp(info.posx,info.posy), m_node_win_diff);
            food->setPosition(destPos);
            float size = (float)info.size / FOOD_PIX_SIZE;
            food->setScale(size);
            mBatch[idx]->addChild(food, 0, info.nodeID);
        }
        else
        {
            // 其他player
            if(!Global::getInstance()->IsMainNode(info.nodeID))
            {
               // CCLog("other id is:%d, other size is:%d", info.nodeID, info.size);
//                PlayerSprite* other = PlayerSprite::createWithPlayerIndex(info.indx);
                //FoodSprite* other = FoodSprite::createWithRGB(info.indx, false);
                FoodSprite* other = FoodSprite::create();
                CCPoint destPos = ccpAdd(ccp(info.posx, info.posy), m_node_win_diff);
                other->setPosition(destPos);
                //CCLog("dest pos x is:%f, dest pos y is:%f", destPos.x, destPos.y);
                float size = (float)info.size / PLAYER_PIX_SIZE;
                other->setScale(size);
                addChild(other, info.size, info.nodeID);
                //other->setWaiguan(info.heroid, info.guanghuan, info.baozi, info.canying);
                other->setWaiguan(info.heroid, info.guanghuan, 29, info.canying);
                //other->createWithRGB(info.indx, false,info.baozi);
                item ite = Resource::sharedResource()->getItemForID(info.baozi);
                //CCLOG("item:%s",ite.itemIcon.c_str());
                other->createWithRGB(info.indx, false,info.baozi,ite.itemIcon,info.name);
                other->setName(info.name.c_str());
//                CCLog("ADD name is::%s", info.name.c_str());
            }
        }
    }
}

CCPoint GridLayer::GetMainPos(uint32_t nodeId)
{
    /*
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.find(nodeId);
    CCPoint pos;
    if(it!=nodes.end())
    {
        CNodeInfo* node = it->second;
        nodeInfo info = node->GetNodeInfo();
        pos = ccp(info.posx, info.posy);
    }
     */
    CCPoint pos;
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.begin();
    for (; it!=nodes.end(); it++) {
        if (it->first == nodeId) {
            CNodeInfo* node = it->second;
            nodeInfo info = node->GetNodeInfo();
            pos = ccp(info.posx, info.posy);
            break;
        }
    }
    return pos;
}

void GridLayer::updateNodeState(CNodeInfo *node)
{
    nodeInfo info = node->GetNodeInfo();
    
    // 更新主角
    if(Global::getInstance()->IsMainNode(info.nodeID))
    {
         updateMainNodes(info);
    }
    else if(info.spike == 1)
    {
        SpikeSprite* other = dynamic_cast<SpikeSprite*>(getChildByTag(info.nodeID));
        if(other == NULL)
            return;
        
        CCPoint destPos = ccpAdd(ccp(info.posx, info.posy), m_node_win_diff);
        other->setPosition(destPos);
        float size = (float)info.size / CI_PIX_SIZE;
        other->setScale(size);
    }
    else if(info.size > 10)// 其他移动的就是其他玩家了
    {
        FoodSprite* other = dynamic_cast<FoodSprite*>(getChildByTag(info.nodeID));
        if(other == NULL)
            return;
        
        //CCLog("other sprite is::%d", info.nodeID);
        //float size = info.size * MINMUN_PLAYER_SCALE_OR / MINIMUM_SIZE;
        float size = (float)info.size / PLAYER_PIX_SIZE;
        other->setScale(size);
        other->setZOrder(info.size);
        // 改变形体
        if(info.size > Global::getInstance()->getJsonImageHead() && !other->getImageHead())
        {
            other->setImageHead(true);
            item ite = Resource::sharedResource()->getItemForID(info.guanghuan);
            other->addPlayerImage(info.heroid,info.guanghuan,info.baozi,info.canying,ite.itemIcon);
        }
        else if(info.size < Global::getInstance()->getJsonImageHead() && other->getImageHead())
        {
            other->setImageHead(false);
            other->removePlayerImage();
        }
        
        CCPoint oldPos = other->getPosition();
        CCPoint destPos = ccpAdd(ccp(info.posx, info.posy), m_node_win_diff);
//        CCPoint midPos = ccpAdd(oldPos, ccpSub(destPos, oldPos) * 0.5f);
//        if(midPos.getLength() > 2)
//        {
//            other->setPosition(midPos);
//            other->setUpdateInfo(info.nodeID, destPos);
//        }
//        else
        //2016-4-16
//        {
//            other->setPosition(destPos);
//        }
        {
            other->setUpdateInfo(info.nodeID, oldPos, destPos);
        }
        // end
        //CCLog("other id is:%d, posx is:%d, posy is:%d", info.nodeID, info.posx, info.posy);
    }
}

void GridLayer::updateOtherPos(uint32_t nodeID, cocos2d::CCPoint destPos)
{
    FoodSprite* other = dynamic_cast<FoodSprite*>(getChildByTag(nodeID));
    other->setPosition(destPos);
}

void GridLayer::updateMainNodes(nodeInfo info)
{
    CCLog("mainsize::%d", info.size);
    uint32_t mNode = Global::getInstance()->GetMainNodeID();
    if(mNode == info.nodeID)
        Global::getInstance()->setMainNodeInfo(info);
    
    //CCLog("main node id is:%d, posx is:%d, posy is:%d", info.nodeID, info.posx, info.posy);
    // 设置面积
    MainSprite* spr = dynamic_cast<MainSprite*>(getChildByTag(info.nodeID));
    if(spr)
    {
        //设置体积
        //spr->setScale(info.size * MINMUN_PLAYER_SCALE_OR / MINIMUM_SIZE);
        float oldSize = spr->getSpSize();
        if(info.size -  oldSize> NEED_ANIM_SCALE_DIFF)
        {
            float siz = (float)info.size / PLAYER_PIX_SIZE;
            CCAction* seq = CCSpawn::create(CCScaleTo::create(UPDATE_SPRITE_SCALE_DURATION, siz), NULL);
            spr->runAction(seq);
        }
        else
        {
            spr->setScale((float)info.size / PLAYER_PIX_SIZE);
        }
        spr->setZOrder(info.size);
        spr->setSpSize(info.size);
        
        //CCLog("sprite scale is::%d", info.size);
        // 改变形体
        if(info.size > Global::getInstance()->getJsonImageHead() && !spr->getIamgeHead())
        {
//            int index = Global::getInstance()->GetMainPicIndex();
//            char temp[32];
//            sprintf(temp, "%s%d.png", FRONT_IMG_FILE_PRE, index);
//            CCTexture2D* aText = CCTextureCache::sharedTextureCache()->addImage(temp);
//            if(aText)
//            {
//                spr->setTexture(aText);
//                spr->setIamgeHead(true);
//            }
            spr->setIamgeHead(true);
            spr->addPlayerImage(info.heroid,info.guanghuan,info.baozi,info.canying);
        }
        else if(info.size < Global::getInstance()->getJsonImageHead() && spr->getIamgeHead())
        {
//            int index = Global::getInstance()->GetMainPicIndex();
//            char temp[32];
//            sprintf(temp, "%s%d.png", BACK_IMG_FILE_PRE, index);
//            CCTexture2D* aText = CCTextureCache::sharedTextureCache()->addImage(temp);
//            if(aText)
//            {
//                spr->setTexture(aText);
//                spr->setIamgeHead(false);
//            }
            spr->setIamgeHead(false);
            spr->removePlayerImage();
        }
        // 做多次插值
        CCPoint oldPos = spr->getPosition();
        CCPoint destPos = ccp(info.posx, info.posy);
        //CCLog("oldpos x is:%f, oldpos y is:%f", oldPos.x, oldPos.y);
        //CCPoint diff = ccpSub(destPos, oldPos);
        //CCLog("the diff length is: %f", diff.getLength());
        //if(diff.getLength() > 5)
        // 2016-4-16
        // 主调
//        if(oldPos.x > 10 && oldPos.y > 10)
//        {
//            //CCLog("destPos x is:%f, destPos y is:%f",destPos.x, destPos.y);
            spr->setUpdateInfo(info.nodeID, oldPos, destPos);
//        }
//        else
//        {
//            spr->setPosition(destPos);
//            
//            MainScene* pScene = dynamic_cast<MainScene*>(getParent());
//            if(Global::getInstance()->getMainNodeNum() == 1)
//                pScene->updateMainState(destPos);
//            else
//                pScene->updateMainState(getMainNodesCenterPos());
//        }
        // end
    }
    else
    {
        addMainNode(info);
        
//        MainScene* pScene = dynamic_cast<MainScene*>(getParent());
//        pScene->updateMainState(ccp(info.posx, info.posy));
        //pScene->updateMainState(getMainNodesCenterPos());
    }
}

void GridLayer::addMainNode(nodeInfo info)
{
    uint32_t mNode = Global::getInstance()->GetMainNodeID();
    if(info.nodeID == mNode)  // 主节点
    {
        //MainSprite* pMainPlayer = MainSprite::createWithIDX();
        Global::getInstance()->SetMainPicIndex(info.indx);
        MainSprite* pMainPlayer = MainSprite::create();
        pMainPlayer->setPosition(ccp(info.posx, info.posy));
        //pMainPlayer->setScale(MINMUN_PLAYER_SCALE_OR);
        pMainPlayer->setScale((float)info.size / PLAYER_PIX_SIZE);
        pMainPlayer->setSpSize(info.size);
        pMainPlayer->setName(info.name);
        //pMainPlayer->setWaiguan(info.heroid, info.guanghuan, info.baozi, info.canying);
        pMainPlayer->setWaiguan(1, 41, 29, 0);
        addChild(pMainPlayer, 10, info.nodeID);
        
//        scheduleOnce(schedule_selector(GridLayer::delayUpdateCameraSize), 0.2f);
    }
    else    // 分裂出来的节点
    {
        //CCLog("node id is:%d, posx is:%d, posy is%d", info.nodeID, info.posx, info.posy);
        Global::getInstance()->SetMainPicIndex(info.indx);
        nodeInfo mainInfo = Global::getInstance()->getMainNodeInfo();
        //MainSprite* pPlayer = MainSprite::createWithIDX();
        MainSprite* pPlayer = MainSprite::create();
//        CCPoint pos = ccpSub(ccp(info.posx, info.posy), ccp(mainInfo.posx, mainInfo.posy));
//        pPlayer->setPosition(ccp(pos.x, pos.y));
        pPlayer->setPosition(ccp(info.posx, info.posy));
        //pPlayer->setScale(info.size * MINMUN_PLAYER_SCALE_OR / MINIMUM_SIZE);
        pPlayer->setScale((float)info.size / PLAYER_PIX_SIZE);
        pPlayer->setSpSize(info.size);
        pPlayer->setName(info.name);
        //pPlayer->setWaiguan(info.heroid, info.guanghuan, info.baozi, info.canying);
        pPlayer->setWaiguan(1, 41, 29, 0);
        addChild(pPlayer, 10, info.nodeID);
        
//        scheduleOnce(schedule_selector(GridLayer::delayUpdateCameraSize), 0.2f);
    }
}

void GridLayer::delayUpdateCameraSize(float ft)
{
    MainScene* pScene = dynamic_cast<MainScene*>(getParent());
    if(pScene)
    {
        pScene->UpdateScaleByMainNodes();
    }
}

void GridLayer::setMainNodePos(cocos2d::CCPoint pos)
{
    uint32_t mNode = Global::getInstance()->GetMainNodeID();
    MainSprite* mainPlayer = dynamic_cast<MainSprite*>(getChildByTag(mNode));
    if(mainPlayer)
    {
        mainPlayer->setPosition(pos);
    }
}

void GridLayer::updateMainPos(uint32_t sprID, cocos2d::CCPoint pos)
{
    MainSprite* spr = dynamic_cast<MainSprite*>(getChildByTag(sprID));
    if(spr)
        spr->setPosition(pos);
    
    MainScene* pScene = dynamic_cast<MainScene*>(getParent());
    
    if(Global::getInstance()->getMainNodeNum() == 1)
        pScene->updateMainState(pos);
    else
        pScene->updateMainState(getMainNodesCenterPos());
}

void GridLayer::resetMainState()
{
    std::vector<uint32_t> nodes = Global::getInstance()->getMainNodes();
    std::vector<uint32_t>::iterator it = nodes.begin();
    for (; it != nodes.end(); ++it)
    {
        uint32_t nodeId = *it;
        MainSprite* spr = dynamic_cast<MainSprite*>(getChildByTag(nodeId));
        if(spr)
        {
            spr->resetState();
        }
    }
}

int GridLayer::getMainNodeSize(uint32_t nodeID)
{
    int size = 0;
    /*
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.find(nodeID);
    if( it != nodes.end())
    {
        CNodeInfo* node = it->second;
        nodeInfo info = node->GetNodeInfo();
        size = info.size;
        //CCLog("node size is:%d",size);
    }
    */
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.begin();
    for (; it!=nodes.end(); it++) {
        if (it->first == nodeID) {
            CNodeInfo* node = it->second;
            nodeInfo info = node->GetNodeInfo();
            size = info.size;
            break;
        }
    }
    return size;
}
int GridLayer::getMainMass(uint32_t nodeID)
{
    int size = 0;
    /*
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.find(nodeID);
    if( it != nodes.end())
    {
        CNodeInfo* node = it->second;
        nodeInfo info = node->GetNodeInfo();
        size = info.mass;
        //CCLog("node size is:%d",size);
    }
    */
    std::map<uint32_t, CNodeInfo*>::iterator it = nodes.begin();
    for (; it!=nodes.end(); it++) {
        if (it->first == nodeID) {
            CNodeInfo* node = it->second;
            nodeInfo info = node->GetNodeInfo();
            size = info.mass;
            break;
        }
    }
    return size;
}
CCPoint GridLayer::getMainNodesCenterPos()
{
    
    float x = 0;
    float y = 0;
    std::vector<uint32_t> mainIDS = Global::getInstance()->getMainNodes();
    int idex = 0;
    std::vector<uint32_t>::iterator it = mainIDS.begin();
    for (; it != mainIDS.end(); ++it) {
        uint32_t mainID = *it;
        MainSprite* mSprite = dynamic_cast<MainSprite*>(getChildByTag(mainID));
        if(mSprite)
        {
            x += mSprite->getPositionX();
            y += mSprite->getPositionY();
            idex++;
        }
    }
    CCPoint pos = CCPointZero;
    if(idex == 0)
    {
        
    }
    else
    {
        pos = ccp(x / idex, y / idex);
    }
    
    //CCLog("pos x is:%f, pos y is:%f, num is: %d", pos.x, pos.y, idex);
    
    //CCLog("main:(x = %f , y = %f)", pos.x, pos.y);
    return pos;
}

float GridLayer::getMainNodeDiff()
{
    //float templen = 0;
    float len = 64;
    CCPoint tempDiff = CCPointZero;
    //CCPoint diff = CCPointZero;
    std::vector<uint32_t> mainIDS = Global::getInstance()->getMainNodes();
    //std::vector<uint32_t>::iterator it = mainIDS.begin();
    std::vector<uint32_t>::iterator iter = mainIDS.begin();
    int num = (int)mainIDS.size();
    if(num == 1)
        return len;
    /*
    if( it != mainIDS.end())
    {
        for(int j=0;j<num;j++)
        {
            uint32_t mainID = *it;
            MainSprite* mSprite = dynamic_cast<MainSprite*>(getChildByTag(mainID));
            if(mSprite)
            {
                for(int i = 0; i < num; i++ )
                {
                    uint32_t otherID = *iter;
                    if(mainID == otherID)
                        continue;
                    MainSprite* oSprite = dynamic_cast<MainSprite*>(getChildByTag(otherID));
                    if(oSprite)
                    {
                        tempDiff = ccpSub(mSprite->getPosition() , oSprite->getPosition());
                        float templen = tempDiff.getLength()+getMainNodeSize(mainID)+getMainNodeSize(otherID);
                        if(templen > len)
                        {
                            len = templen;
                            //diff = tempDiff;
                        }
                    }
                    ++iter;
                }
            }
            ++it;
        }
    }
    */
    CCPoint mainPos = Global::getInstance()->GetMainPos();
    for(int i = 0; i < num; i++ )
    {
        uint32_t otherID = *iter;
        MainSprite* oSprite = dynamic_cast<MainSprite*>(getChildByTag(otherID));
        if(oSprite)
        {
            tempDiff = ccpSub(mainPos , oSprite->getPosition());
            float templen = (tempDiff.getLength()+getMainNodeSize(otherID))*2;
            if(templen > len)
            {
                len = templen;
                //diff = tempDiff;
            }
        }
        ++iter;
    }

    
    return len;
}
