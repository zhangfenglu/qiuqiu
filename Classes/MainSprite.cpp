//
//  MainSprite.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/2/29.
//
//

#include "MainSprite.h"
#include "Global.h"
#include "GridLayer.h"
#include "Resources.h"
#include "MainScene.h"

#define BACK_IMG_FILE_PRE  "Big_color_"
#define FRONT_IMG_FILE_PRE  "hero_"
#define DURATION_TIMES  6

MainSprite::MainSprite()
{
    this->scheduleUpdate();
    m_isImageHead = false;
    m_sp_scale = 1;
    m_times = DURATION_TIMES + 1;
    heroID = 0;
    mBaozi = 0;
    mGuanghuan = 0;
    mCanying = 0;
}

MainSprite::~MainSprite()
{
    
}
bool MainSprite::init()
{
    if(!CCNode::init())
        return false;
    
    int index = Global::getInstance()->GetMainPicIndex();
    
    char temp[32];
    sprintf(temp, "%s%d.png", BACK_IMG_FILE_PRE, index);
    //sprintf(temp, "%s%d.png", FRONT_IMG_FILE_PRE, index);
    //MainSprite* sprite = new MainSprite();
    //if(sprite && sprite->initWithFile(temp))
        //if(sprite)
    //{
    CCSprite* image = CCSprite::create(temp);
    //image->setAnchorPoint(ccp(0, 0));
    addChild(image, 1, 14);
    //}
  
    
    return true;
}
/*
MainSprite* MainSprite::createWithIDX()
{
    int index = Global::getInstance()->GetMainPicIndex();
    
    char temp[32];
    sprintf(temp, "%s%d.png", BACK_IMG_FILE_PRE, index);
    MainSprite* sprite = new MainSprite();
    //if(sprite && sprite->initWithFile(temp))
    //if(sprite)
    {
        //CCSprite* image = CCSprite::create(temp);
        //image->setAnchorPoint(ccp(0, 0));
        //sprite->addChild(image, 2, 14);
        
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}
*/
void MainSprite::setUpdateInfo(uint32_t nodeId, cocos2d::CCPoint oldPos, cocos2d::CCPoint destPos)
{
    m_sprID = nodeId;
    m_oldPos = oldPos;
    m_destPos = destPos;
    m_diff = ccpSub(destPos, oldPos) / DURATION_TIMES;
    m_times = 1;
}

void MainSprite::resetState()
{
    m_times = DURATION_TIMES + 1;
}

void MainSprite::update(float ft)
{
    //CCLog("float update duration is:%f", ft);
    if(m_times > DURATION_TIMES)
    {
        return;
    }
    
    CCPoint pos ;
    MainScene* scene = (MainScene*)getParent()->getParent();
    
    if( m_times == DURATION_TIMES )
    {
        pos = m_destPos;
    }
    else
    {
        pos = ccpAdd(m_oldPos, m_diff * m_times);
    }
    GridLayer* grid = dynamic_cast<GridLayer*>(getParent());
    grid->updateMainPos(m_sprID, pos);
    
    //CCLog("pos:(%f,%f)",pos.x,pos.y);
    
    m_times++;
    
}

void MainSprite::setPlayerUpdate(uint32_t nodeId, cocos2d::CCPoint destPos)
{
    m_sprID = nodeId;
    m_destPos = destPos;
    
    CCDelayTime * delayAction = CCDelayTime::create(0.02f);
    CCCallFunc * callFunc = CCCallFunc::create(this, callfunc_selector(MainSprite::updateMainPos));
    this->runAction(CCSequence::createWithTwoActions(delayAction, callFunc));
}

void MainSprite::updateMainPos()
{
    GridLayer* grid = dynamic_cast<GridLayer*>(getParent());
    grid->updateMainPos(m_sprID, m_destPos);
}

void MainSprite::setIamgeHead(bool flag)
{
    m_isImageHead = flag;
}

bool MainSprite::getIamgeHead()
{
    return m_isImageHead;
}

void MainSprite::addPlayerImage(int hero,int guanghuan,int baozi,int canying)
{
    heroID = hero;
    mGuanghuan = guanghuan;
    mBaozi = baozi;
    mCanying = canying;
    //int index = Global::getInstance()->GetMainPicIndex();
    
    //char temp[32];
    //sprintf(temp, "%s%d.png", FRONT_IMG_FILE_PRE, index);
    //CCSprite* image = CCSprite::create(temp);
    //if(image)
    //{
        //image->setAnchorPoint(ccp(0, 0));
        //addChild(image, 2, 11);
    //}
    //else
    //{
        //m_isImageHead = false;
    //}
    bool isShowIcon = false;
    //Shenshou++;
    if (heroID) {
        isShowIcon = true;
        char imagName[128] = {0};
        sprintf(imagName, "shenshou-%d-3.png",heroID);
        CCSprite* image = CCSprite::create(imagName);
        if(image)
        {
            getChildByTag(14)->setVisible(false);
            
            //image->setAnchorPoint(ccp(0.5f, 0.5f));
            //image->setPosition(ccp(150,150));
            addChild(image, 2, 11);
            
            
            image->runAction(
                             CCRepeatForever::create(
                                                     CCSequence::create(
                                                                        CCRotateBy::create(0.1f, 5.0f),NULL)));
            
            sprintf(imagName, "shenshou-%d-2.png",heroID);
            CCSprite* texiao = CCSprite::create(imagName);
            //texiao->setAnchorPoint(ccp(0.5f, 0.5f));
            //texiao->setPosition(ccp(150,150));
            addChild(texiao, 3, 12);
            
            texiao->runAction(
                              CCRepeatForever::create(
                                                      CCSequence::create(
                                                                         CCRotateBy::create(0.1f, 5.0f),NULL)));
            
            sprintf(imagName, "shenshou-%d-1.png",heroID);
            CCSprite* qlong = CCSprite::create(imagName);
            //qlong->setAnchorPoint(ccp(0, 0));
            addChild(qlong, 4, 13);
        }
    }
    
    if (mGuanghuan)
    {
        isShowIcon = true;
        item ite = Resource::sharedResource()->getItemForID(mGuanghuan);
        CCSprite* image = CCSprite::create(ite.itemIcon.c_str());
        
        addChild(image, 2, 15);
        
        
        image->runAction(
                         CCRepeatForever::create(
                                                 CCSequence::create(
                                                                    CCRotateBy::create(0.1f, 5.0f),NULL)));
    }
    
    if(isShowIcon == false)
    {
        m_isImageHead = false;
    }
}

void MainSprite::removePlayerImage()
{
    removeChildByTag(11);
    removeChildByTag(12);
    removeChildByTag(13);
    removeChildByTag(15);
    getChildByTag(14)->setVisible(true);
}

void MainSprite::setName(std::string name)
{
    NameColor color = Global::getInstance()->GetNameColor(name);
    std::string icon = Global::getInstance()->ComPlayerName(name);
    if (strcmp(icon.c_str(), "") != 0) {
        removeChildByTag(14, true);
        CCSprite* image = CCSprite::create(icon.c_str());
        //image->setAnchorPoint(ccp(0, 0));
        addChild(image, 1, 14);
    }
    //CCSize size = getContentSize();
    int nameLen = (int)name.length();
    
    int nameSize = 0;
    if (nameLen) {
        nameSize = 600/nameLen;
    }
    
    //CCLOG("name:%s",name.c_str());
    CCLabelTTF* namelb = CCLabelTTF::create(name.c_str(), "STXingkai.ttf", nameSize);
    namelb->setColor(ccc3(color.colorR, color.colorG, color.colorB));
    //namelb->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
    //namelb->setAnchorPoint(ccp(0,-2));
    addChild(namelb, 5);
    
    
}

void MainSprite::setSpSize(float size)
{
    m_sp_scale = size;
}

float MainSprite::getSpSize()
{
    return m_sp_scale;
}

void MainSprite::setOriginPos(cocos2d::CCPoint pos)
{
    
}

void MainSprite::setSize(cocos2d::CCSize size)
{
    
}

void MainSprite::updatePos(cocos2d::CCPoint pos)
{
    
}


