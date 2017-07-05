//
//  FoodSprite.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/3/2.
//1
//

#include "FoodSprite.h"
#include "Common.h"
#include "GridLayer.h"

#define IMAGE_PRE "color_"
#define BACK_IMG_FILE_PRE  "Big_color_"
#define FRONT_IMG_FILE_PRE  "hero_"
#define DURATION_TIMES  3

FoodSprite::FoodSprite()
{
    m_spriteID = 0;
    m_isImageHead = false;
    m_times = DURATION_TIMES + 1;
    m_isFood = true;
    heroID = 0;
    mBaozi = 0;
    mGuanghuan = 0;
    mCanying = 0;
    this->scheduleUpdate();
}

FoodSprite::~FoodSprite()
{
    
}
bool FoodSprite::init()
{
    if(!CCNode::init())
        return false;
    
    return true;
}
void FoodSprite::createWithRGB(uint16_t index, bool isFood,int baozi,std::string icon,std::string name)
{
    int idx = index % MAXIMUM_PICTURE_NUM;
    setImageIndex(idx, isFood);
    char temp[32]={0};
    if(isFood)
    {
        sprintf(temp, "%s%d.png", IMAGE_PRE, idx%8);
        CCSprite* image = CCSprite::create(temp);
        //image->setAnchorPoint(ccp(0, 0));
        addChild(image, 1, 14);
    }
    else if(name == "")
    {
        if(baozi)
        {
            CCSprite* image = CCSprite::create(icon.c_str());
            //image->setAnchorPoint(ccp(0, 0));
            addChild(image, 1, 14);
        }else{
            sprintf(temp, "%s%d.png", BACK_IMG_FILE_PRE, 12);
            CCSprite* image = CCSprite::create(temp);
            //image->setAnchorPoint(ccp(0, 0));
            addChild(image, 1, 14);
            //CCLOG("tuqiu:%s",temp);
        }
    }else{
        sprintf(temp, "%s%d.png", BACK_IMG_FILE_PRE, index);
        CCSprite* image = CCSprite::create(temp);
        //image->setAnchorPoint(ccp(0, 0));
        addChild(image, 1, 14);
        //CCLOG("tuqiu:%s",temp);
    }
    /*
    if (sprite && sprite->initWithFile(temp))
    {
        sprite->setImageIndex(idx, isFood);
        sprite->autorelease();
        return sprite;
    }
     */
}

void FoodSprite::setUpdateInfo(uint32_t nodeId, cocos2d::CCPoint oldPos, cocos2d::CCPoint destPos)
{
    m_spriteID = nodeId;
    m_destPos = destPos;
    m_oldPos = oldPos;
    
    m_diff = ccpSub(destPos, oldPos) / DURATION_TIMES;
    m_times = 1;
}

void FoodSprite::update(float ft)
{
    if(m_times > DURATION_TIMES)
        return;
    
    CCPoint pos;
    if(m_times == DURATION_TIMES)
    {
        pos = m_destPos;
    }
    else
    {
        pos = ccpAdd(m_oldPos, m_diff * m_times);
    }
    
    GridLayer* grid = dynamic_cast<GridLayer*>(getParent());
    grid->updateOtherPos(m_spriteID, pos);
    
    m_times++;
}

void FoodSprite::setImageHead(bool flag)
{
    m_isImageHead = flag;
}

bool FoodSprite::getImageHead()
{
    return m_isImageHead;
}

void FoodSprite::setImageIndex(int index, bool isFood)
{
    m_imageIndex = index;
    m_isFood = isFood;
}

int FoodSprite::getImageIndex()
{
    return m_imageIndex;
}

void FoodSprite::addPlayerImage(int hero,int guanghuan,int baozi,int canying,std::string icon)
{
    //char temp[32];
    //sprintf(temp, "%s%d.png", FRONT_IMG_FILE_PRE, m_imageIndex);
    //CCSprite* image = CCSprite::create(temp);
    //image->setAnchorPoint(ccp(0,0));
    //addChild(image, 2, 11);
    
    // 暂时主调
    heroID = hero;
    mGuanghuan = guanghuan;
    mBaozi = baozi;
    mCanying = canying;
    bool isShowIcon = false;
    if (heroID)
    {
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
            qlong->setAnchorPoint(ccp(0, 0));
            addChild(qlong, 4, 13);
        }
    }
    
    if (mGuanghuan)
    {
        isShowIcon = true;
        //item ite = Resource::sharedResource()->getItemForID(mGuanghuan);
        CCSprite* image = CCSprite::create(icon.c_str());
        
        addChild(image, 2, 15);
        
        
        image->runAction(
                         CCRepeatForever::create(
                                                 CCSequence::create(
                                                                    CCRotateBy::create(0.1f, 5.0f),NULL)));
    }
    
    if (isShowIcon == false) {
        m_isImageHead = false;
    }
}

void FoodSprite::removePlayerImage()
{
    removeChildByTag(11);
    removeChildByTag(12);
    removeChildByTag(13);
    removeChildByTag(15);
    
    getChildByTag(14)->setVisible(true);
}

void FoodSprite::setName(const char* name)
{
    std::string nameColor = name;
    NameColor color = Global::getInstance()->GetNameColor(nameColor);
    std::string icon = Global::getInstance()->ComPlayerName(nameColor);
    if (strcmp(icon.c_str(), "") != 0) {
        removeChildByTag(14, true);
        CCSprite* image = CCSprite::create(icon.c_str());
        //image->setAnchorPoint(ccp(0, 0));
        addChild(image, 1, 14);
    }
    
    //CCSize size = getContentSize();
    int nameLen = (int)strlen(name);
    int nameSize = 0;
    if (nameLen) {
        nameSize = 600/nameLen;
    }
    CCLabelTTF* namelb = CCLabelTTF::create(nameColor.c_str(), "STXingkai.ttf", nameSize);
    namelb->setColor(ccc3(color.colorR, color.colorG, color.colorB));
    //namelb->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
    //namelb->setAnchorPoint(ccp(0,-2));
    addChild(namelb, 3);
}
