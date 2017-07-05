//
//  SceneLayer.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/2/25.
//
//

#include "SceneLayer.h"
#include "GridLayer.h"
#include "MainScene.h"
#include "JoystickLayer.h"
#include "MainSprite.h"
#include "Common.h"

SceneLayer::SceneLayer()
{
    
}

SceneLayer::~SceneLayer()
{
    
}

bool SceneLayer::init()
{
    if(!CCLayer::init())
        return false;
    
//    setTouchEnabled(true);
//    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    JoystickLayer* joy = JoystickLayer::create();
    joy->setVisible(false);
    addChild(joy, 1, 10);
    
    Button* pop = Button::createBtnWithSpriteFrameName("vomitPop.png", false);
    pop->setPosition(ccp(winSize.width - 200, 40));
    pop->setScale(0.6f);
    pop->setOnClickCallback(callfuncO_selector(SceneLayer::clickPopBtn), this);
    addChild(pop);
    
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey("Stuqiu", 0) == 1){
        pop->setIsCanTouchMoreTime(true);
    }
    
    Button* split = Button::createBtnWithSpriteFrameName("split.png", false);
    split->setPosition(ccp(winSize.width - 80, 70));
    split->setScale(0.6f);
    split->setOnClickCallback(callfuncO_selector(SceneLayer::clickSplitBtn), this);
    addChild(split);
    
    
    CCSprite* sprite = CCSprite::create("weight_back.png");
    sprite->setPosition(ccp(150, winSize.height - 60));
    sprite->setScale(0.6f);
    addChild(sprite);
    
    CCSize spSize = sprite->getContentSize();
    m_weight = CCLabelTTF::create(Global::getInstance()->getString("69"), "STXingkai.ttf", 60);
    //label->setColor(ccc3(0, 0, 0));
    m_weight->setPosition(ccp(spSize.width * 0.5f, spSize.height * 0.5));
    sprite->addChild(m_weight, 2);
    
    ZhanDouPaiMing* paiming = ZhanDouPaiMing::create();
    paiming->setPosition(ccp(winSize.width - 200, winSize.height - 400));
    addChild(paiming, 2, 121);
    
    CCLabelTTF* clock = CCLabelTTF::create("", "STXingkai.ttf", 30);
    clock->setPosition(ccp(winSize.width * 0.5f, winSize.height - 20));
    clock->setColor(ccc3(0, 0, 0));
    addChild(clock, 2, 131);
    
    return true;
}

void SceneLayer::addEndUI(const char* lab,int sec)
{
    ZhanDouFuhuo* fuhuo = ZhanDouFuhuo::create();
    addChild(fuhuo, 20,TAG_FUHUO);
    fuhuo->setLab(lab,sec);
}
//void SceneLayer::ccTouchesBegan(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent)
//{
//
//    CCLog("cc touches began 123456");
//    CCTouch* touch = (CCTouch*)pTouch->anyObject();
//    
//    CCPoint pos = touch->getLocation();
//    JoystickLayer* joy = dynamic_cast<JoystickLayer*>(getChildByTag(10));
//    joy->setVisible(true);
//    
//    joy->setOutPos(pos);
//}

//void SceneLayer::ccTouchesMoved(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent)
//{
//    CCTouch* touch = (CCTouch*)pTouch->anyObject();
//    
//    CCPoint diff = touch->getDelta();
//    CCScene* pScene = dynamic_cast<CCScene*>(getParent());
//    GridLayer* node = dynamic_cast<GridLayer*>(pScene->getChildByTag(MainScene::TAG_LAYER_GRID));
//    CCPoint currentPos = node->getPosition();
//    CCPoint destPos = ccpSub(currentPos, diff);
//    node->setPosition(destPos);
// 
//    JoystickLayer* joy = dynamic_cast<JoystickLayer*>(getChildByTag(10));
//    joy->updateJoystick(diff);
//}

//void SceneLayer::ccTouchesEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent)
//{
//    JoystickLayer* joy = dynamic_cast<JoystickLayer*>(getChildByTag(10));
//    joy->setVisible(false);
//}

void SceneLayer::setJoystickPos(cocos2d::CCPoint pos)
{
    JoystickLayer* joy = dynamic_cast<JoystickLayer*>(getChildByTag(10));
    joy->setVisible(true);
    
    m_joystickPos = pos;
    joy->setOutPos(pos);
}

void SceneLayer::updateJoystickPos(cocos2d::CCPoint diff)
{
    JoystickLayer* joy = dynamic_cast<JoystickLayer*>(getChildByTag(10));
    joy->updateJoystick(diff);
}

void SceneLayer::moveEndJoystick()
{
    JoystickLayer* joy = dynamic_cast<JoystickLayer*>(getChildByTag(10));
    joy->setVisible(false);
}
void SceneLayer::ViewLife(int count)
{
    if (Global::getInstance()->GetFightType() == 0) {
        return;
    }
    removeChildByTag(TAG_LIFELAYER, true);
    
    CCLayer* layer = CCLayer::create();
    addChild(layer,0,TAG_LIFELAYER);
    
    int i = 0;
    CCSprite* back = CCSprite::create("hongxin-01.png");
    back->setPosition(ccp(winSize.width * 0.5f-230+i*40, winSize.height * 0.5f+260));
    back->setScale(0.6f);
    layer->addChild(back);
    
    i++;
    back = CCSprite::create("hongxin-01.png");
    back->setPosition(ccp(winSize.width * 0.5f-230+i*40, winSize.height * 0.5f+260));
    back->setScale(0.6f);
    layer->addChild(back);
    if(count > 3)
        back->setVisible(false);
    
    i++;
    back = CCSprite::create("hongxin-01.png");
    back->setPosition(ccp(winSize.width * 0.5f-230+i*40, winSize.height * 0.5f+260));
    back->setScale(0.6f);
    layer->addChild(back);
    if(count > 3)
        back->setVisible(false);
    
    char menpiao[64] = {0};
    sprintf(menpiao, "%d",count);
    CCLabelTTF* useName = CCLabelTTF::create(menpiao, "STXingkai.ttf", 30);
    useName->setPosition(ccp(winSize.width * 0.5f-190, winSize.height * 0.5f+260));
    layer->addChild(useName);
    if(count <= 3)
        useName->setVisible(false);
}
void SceneLayer::addSelfNode(nodeInfo info)
{
    uint32_t mNode = Global::getInstance()->GetMainNodeID();
    if(info.nodeID == mNode)  // 主节点
    {
        //MainSprite* pMainPlayer = MainSprite::createWithIDX();
        MainSprite* pMainPlayer = MainSprite::create();
        pMainPlayer->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5));
        //pMainPlayer->setScale(MINMUN_PLAYER_SCALE_OR);
        pMainPlayer->setScale((float)info.size / PLAYER_PIX_SIZE);
        //pMainPlayer->setWaiguan(info.heroid, info.guanghuan, info.baozi, info.canying);
        //pMainPlayer->setWaiguan(1, 41, 29, info.canying);
        addChild(pMainPlayer, 0, info.nodeID);
    }
    else    // 分裂出来的节点
    {
        //CCLog("node id is:%d, posx is:%d, posy is%d", info.nodeID, info.posx, info.posy);
        nodeInfo mainInfo = Global::getInstance()->getMainNodeInfo();
        //MainSprite* pPlayer = MainSprite::createWithIDX();
        MainSprite* pPlayer = MainSprite::create();
        CCPoint pos = ccpSub(ccp(info.posx, info.posy), ccp(mainInfo.posx, mainInfo.posy));
        pPlayer->setPosition(ccp(winSize.width * 0.5f + pos.x, winSize.height * 0.5f + pos.y));
        //pPlayer->setScale(info.size * MINMUN_PLAYER_SCALE_OR / MINIMUM_SIZE);
        pPlayer->setScale((float)info.size / PLAYER_PIX_SIZE);
        //pPlayer->setWaiguan(info.heroid, info.guanghuan, info.baozi, info.canying);
        //pPlayer->setWaiguan(1, 41, 29, info.canying);
        addChild(pPlayer, 0, info.nodeID);
    }
}

void SceneLayer::updateMainInfo(nodeInfo info)
{
    uint32_t mNode = Global::getInstance()->GetMainNodeID();
    if(mNode == info.nodeID)
        Global::getInstance()->setMainNodeInfo(info);
    
    //CCLog("main node id is:%d, posx is:%d, posy is:%d", info.nodeID, info.posx, info.posy);
    // 设置面积
    MainSprite* spr = dynamic_cast<MainSprite*>(getChildByTag(info.nodeID));
    if(spr)
    {
        uint32_t mNode = Global::getInstance()->GetMainNodeID();
        if(info.nodeID == mNode)  // 主节点
        {
            //float size = info.size * MINMUN_PLAYER_SCALE_OR / MINIMUM_SIZE;
            float size = (float)info.size / PLAYER_PIX_SIZE;
            spr->setScale(size);
            //CCLog("main node id is:%d, posx is:%d, posy is:%d", info.nodeID, info.posx, info.posy);
        }
        else
        {
            nodeInfo mainInfo = Global::getInstance()->getMainNodeInfo();
            CCPoint pos = ccpSub(ccp(info.posx, info.posy), ccp(mainInfo.posx, mainInfo.posy));
            spr->setPosition(ccp(winSize.width * 0.5f + pos.x, winSize.height * 0.5f + pos.y));
            //spr->setScale(info.size * MINMUN_PLAYER_SCALE_OR / MINIMUM_SIZE);
            spr->setScale((float)info.size / PLAYER_PIX_SIZE);
            //CCLog("child node id is:%d, posx is:%d, posy is:%d", info.nodeID, info.posx, info.posy);
        }
    }
    else
    {
        addSelfNode(info);
    }
}

CCPoint SceneLayer::GetJoyDiff()
{
    JoystickLayer* joy = dynamic_cast<JoystickLayer*>(getChildByTag(10));
    CCPoint joyPos = joy->GetJoyPos();
    CCPoint diff = ccpSub(joyPos, m_joystickPos);
    return diff;
}

void SceneLayer::clickPopBtn(cocos2d::CCObject *pSender)
{
#ifndef EditEXE
    MainScene* pMain = dynamic_cast<MainScene*>(getParent());
    pMain->notifyEject();
#endif
}

void SceneLayer::clickSplitBtn(cocos2d::CCObject *pSender)
{
#ifndef EditEXE
    MainScene* pMain = dynamic_cast<MainScene*>(getParent());
    pMain->notifySplite();
#endif
}

void SceneLayer::deleteMainNode(uint32_t nodeID)
{
    removeChildByTag(nodeID);
}

void SceneLayer::updateSceneScale(float scale)
{
    std::vector<uint32_t> nodes = Global::getInstance()->getMainNodes();
    std::vector<uint32_t>::iterator it = nodes.begin();
    for(; it != nodes.end(); ++it)
    {
        uint32_t ids = *it;
        MainSprite* sprite = dynamic_cast<MainSprite*>(getChildByTag(ids));
        if(sprite)
        {
            sprite->setScale(scale);
        }
    }
}

void SceneLayer::updateWeightLabel(int mass)
{
    //mass = 20000;
    if(m_weight)
    {
        char temp[64];
        
        unsigned long long eMass = 0.000173415299158326*(pow(mass, 5))-7.34152991583261;
        
        if (eMass < 10000) {
            sprintf(temp, Global::getInstance()->getString("69"), eMass);
        }else if(eMass < 1000000)
        {
            unsigned long long tMa = eMass/100;
            sprintf(temp, Global::getInstance()->getString("70"), tMa);
        }else if(eMass < 1000000000)
        {
            unsigned long long tMa = eMass/100000;
            sprintf(temp, Global::getInstance()->getString("71"), tMa);
        }else if(eMass < 1000000000000)
        {
            unsigned long long tMa = eMass/100000000;
            sprintf(temp, Global::getInstance()->getString("72"), tMa);
        }else if(eMass < 1000000000000000)
        {
            unsigned long long tMa = eMass/100000000000;
            sprintf(temp, Global::getInstance()->getString("73"), tMa);
        }else if(eMass < 1000000000000000000)
        {
            unsigned long long tMa = eMass/100000000000000;
            sprintf(temp, Global::getInstance()->getString("74"), tMa);
        }else{
            unsigned long long tMa = eMass/100000000000000000;
            sprintf(temp, Global::getInstance()->getString("75"), tMa);
        }
   
    
        m_weight->setString(temp);
    }
}

void SceneLayer::updateFightRanking(std::vector<fight_rank> ranks)
{
    ZhanDouPaiMing* zdpm = dynamic_cast<ZhanDouPaiMing*>(getChildByTag(121));
    if(zdpm)
        zdpm->updatpaiming(ranks);
}

void SceneLayer::setDuration(int duration)
{
    m_duration = duration;
    setDurationText(m_duration);
    schedule(schedule_selector(SceneLayer::updateDuration), 1);
}

void SceneLayer::updateDuration(float ft)
{
    if(m_duration > 0)
    {
        m_duration--;
        setDurationText(m_duration);
    }
    else
    {
        unschedule(schedule_selector(SceneLayer::updateDuration));
    }
}

void SceneLayer::setDurationText(int duration)
{
    int mins = duration / 60;
    int sec = duration % 60;
    
    char temp[16];
    if(mins >= 10)
    {
        if(sec >= 10)
            sprintf(temp, "%d:%d", mins, sec);
        else
            sprintf(temp, "%d:0%d", mins, sec);
    }
    else if(mins < 10)
    {
        if(sec >= 10)
            sprintf(temp, "0%d:%d", mins, sec);
        else
            sprintf(temp, "0%d:0%d", mins, sec);
    }
    
    CCLabelTTF* label = dynamic_cast<CCLabelTTF*>(getChildByTag(131));
    label->setString(temp);
}




///////////////////////////////////////////////////////////
ZhanDouPaiMing::ZhanDouPaiMing()
{
    
}
ZhanDouPaiMing::~ZhanDouPaiMing()
{
    
}

bool ZhanDouPaiMing::init()
{
    if(!CCLayer::init())
        return false;
    
    //CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 50), 200, 400);
    //addChild(layer);
    
    CCSprite* line = CCSprite::create("rankback.png");
    line->setScale(0.5f);
    line->setAnchorPoint(ccp(0,0));
    line->setPosition(ccp(-50,0));
    addChild(line);
    
    CCLabelTTF* lab = CCLabelTTF::create(Global::getInstance()->getString("76"), "STXingkai.ttf", 40);
    lab->setPosition(ccp(100,375));
    lab->setColor(ccc3(0, 0, 0));
    addChild(lab);
    
    line = CCSprite::create("ranksplit.png");
    line->setScale(0.6f);
    line->setPosition(ccp(100,350));
    addChild(line);
    
    line = CCSprite::create("ranksplit.png");
    line->setPosition(ccp(100,80));
    line->setScale(0.6f);
    addChild(line);
    
    line = CCSprite::create("ranksplit.png");
    line->setPosition(ccp(100,40));
    line->setScale(0.6f);
    addChild(line);
    
    //line = CCSprite::create("ranksplit.png");
    //line->setPosition(ccp(100,0));
    //line->setScale(0.6f);
    //addChild(line);
    
    initLabels();
    //schedule(schedule_selector(ZhanDouPaiMing::updatpaiming), 0.5);
    return true;
}

void ZhanDouPaiMing::initLabels()
{
    for(int i = 0; i < 10; i++)
    {
        CCLabelTTF* lab = CCLabelTTF::create("", "STXingkai.ttf", 25);
        lab->setPosition(ccp(20,320 - 26 * i));
        lab->setColor(ccc3(0, 0, 0));
        lab->setAnchorPoint(CCPointZero);
        addChild(lab, 1, 100 + i);
    }
    
    CCLabelTTF* labm = CCLabelTTF::create("", "STXingkai.ttf", 25);
    labm->setPosition(ccp(20,45));
    labm->setAnchorPoint(CCPointZero);
    addChild(labm, 1, 121);
   
}

void ZhanDouPaiMing::clearLabels()
{
    for(int i = 0; i < 10; i++)
    {
        CCLabelTTF* lab = dynamic_cast<CCLabelTTF*>(getChildByTag(100 + 1));
        lab->setString("");
    }
}

void ZhanDouPaiMing::updatpaiming(std::vector<fight_rank> ranks)
{
    clearLabels();
    std::vector<fight_rank>::iterator iter = ranks.begin();
    int index = 0;
    int begin = 100;
    for(; iter != ranks.end(); ++iter)
    {
        fight_rank rank = *iter;
        
        if( index < 10)
        {
            NameColor color = Global::getInstance()->GetNameColor(rank.name);
        
            char temp[32];
            sprintf(temp, "  %d:   %s", index + 1, rank.name.c_str());
       
            CCLabelTTF* lab = dynamic_cast<CCLabelTTF*>(getChildByTag(begin + index));
            if(lab)
            {
                lab->setString(temp);
                lab->setColor(ccc3(color.colorR, color.colorG, color.colorB));
            }
        }
        
        if (rank.rankID == Global::getInstance()->GetUserInfo().roleID) {
            NameColor color = Global::getInstance()->GetNameColor(rank.name);
            
            char temp[32];
            sprintf(temp, "  %d:   %s", index + 1, rank.name.c_str());
            
            CCLabelTTF* lab = dynamic_cast<CCLabelTTF*>(getChildByTag(121));
            if(lab)
            {
                lab->setString(temp);
                lab->setColor(ccc3(color.colorR, color.colorG, color.colorB));
            }
        }
        index++;
    }
}
/////////////////////////////
ZhanDouFuhuo::ZhanDouFuhuo()
{
    mDaojishi = 0;
}
ZhanDouFuhuo::~ZhanDouFuhuo()
{
    
}

bool ZhanDouFuhuo::init()
{
    if (!CPZLayer::init()) {
        return false;
    }
    
    CCSprite* back = CCSprite::create("datingbeijing-01.png");
    back->setPosition(ccp(winSize.width/2,winSize.height/2));
    back->setScaleX(0.8f);
    addChild(back);
    
    Button* split = Button::createBtnWithSpriteFrameName("dating-01.png", false);
    split->setPosition(ccp(winSize.width/2+180, winSize.height/2));
    //split->setScale(0.6f);
    split->setOnClickCallback(callfuncO_selector(ZhanDouFuhuo::clickEndBtn), this);
    addChild(split);
    
    split = Button::createBtnWithSpriteFrameName("lijifuhuo-01.png", false);
    split->setPosition(ccp(winSize.width/2-90, winSize.height/2-20));
    split->setScale(0.4f);
    split->setPressIcon("lijifuhuo-02.png", false);
    split->setOnClickCallback(callfuncO_selector(ZhanDouFuhuo::clickFuhuo), this);
    addChild(split);
    return true;
}
void ZhanDouFuhuo::setLab(const char* lab,int sec)
{
    mDaojishi = sec;
    
    CCLabelTTF* labn = CCLabelTTF::create(lab, "STXingkai.ttf", 35);
    labn->setPosition(ccp(winSize.width/2-60, winSize.height/2+35));
    labn->setColor(ccc3(0, 0, 0));
    addChild(labn);
    
    char temp[10] = {0};
    sprintf(temp, "%d",mDaojishi);
    
    CCLabelTTF* secL = CCLabelTTF::create(temp, "STXingkai.ttf", 35);
    secL->setPosition(ccp(winSize.width/2+60, winSize.height/2-20));
    secL->setColor(ccc3(0, 0, 0));
    addChild(secL,0,10);
    
    schedule(schedule_selector(ZhanDouFuhuo::updatTime), 1.0f);
}
void ZhanDouFuhuo::updatTime(float ft)
{
    if (mDaojishi <= 0 ) {
        unschedule(schedule_selector(ZhanDouFuhuo::updatTime));
        MainScene* pMain = dynamic_cast<MainScene*>(getParent()->getParent());
        pMain->reRebirth();
        getParent()->removeChild(this, true);
        return;
    }
    mDaojishi--;
    char temp[10] = {0};
    sprintf(temp, "%d",mDaojishi);
    
    CCLabelTTF* lab = (CCLabelTTF*)getChildByTag(10);
    lab->setString(temp);
}
void ZhanDouFuhuo::clickEndBtn(CCObject* pSender)
{
    MainScene* pMain = dynamic_cast<MainScene*>(getParent()->getParent());
    pMain->reqExitFight();
    //pMain->CloseWebNet();
    //pMain->BackToLoginLayer(MainScene::TAG_LAYER_SCENE);
}
void ZhanDouFuhuo::clickFuhuo(CCObject* pSender)
{
    MainScene* pMain = dynamic_cast<MainScene*>(getParent()->getParent());
    pMain->reRebirth();
    getParent()->removeChild(this, true);
}