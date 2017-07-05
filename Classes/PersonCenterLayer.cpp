//
//  PersonCenterLayer.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/4/1.
//
//

#include "PersonCenterLayer.h"
//#include "InputLabel.h"
#include "MainScene.h"

#define CHILD_OFFSET_X      50
#define CHILD_OFFSET_Y      100
#define MAIN_TABLEVIEW_ACTIVE   -120


//////////////////////////////////////////////////////
// base
//////////////////////////////////////////////////////
PersonCenterBase::PersonCenterBase()
{
    
}

PersonCenterBase::~PersonCenterBase()
{
    
}

bool PersonCenterBase::init()
{
    if(!CCLayer::init())
        return false;
    
    initUI();
    
    return true;
}

void PersonCenterBase::initUI()
{
    CCSprite* back = CCSprite::create("center_back.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.6f);
    addChild(back);
    
    ziliao = Button::createBtnWithSpriteFrameName("gerenziliao-01.png", false);
    ziliao->setPosition(ccp(200, winSize.height - 50));
    ziliao->setScale(0.6f);
    ziliao->setOnClickCallback(callfuncO_selector(PersonCenterBase::ZiliaoClick), this);
    ziliao->setPressIcon("gerenziliao-02.png", false);
    ziliao->setPressIconShow(true);
    addChild(ziliao, 1);
    
    xinxi = Button::createBtnWithSpriteFrameName("yonghuxinxi-01.png", false);
    xinxi->setPosition(ccp(400, winSize.height - 50));
    xinxi->setScale(0.6f);
    xinxi->setOnClickCallback(callfuncO_selector(PersonCenterBase::XinxiClick), this);
    xinxi->setPressIcon("yonghuxinxi-02.png", false);
    addChild(xinxi, 1);
    
    rongyu = Button::createBtnWithSpriteFrameName("gerenrongyu-01.png", false);
    rongyu->setPosition(ccp(600, winSize.height - 50));
    rongyu->setScale(0.6f);
    rongyu->setOnClickCallback(callfuncO_selector(PersonCenterBase::RongyuClick), this);
    rongyu->setPressIcon("gerenrongyu-02.png", false);
    addChild(rongyu, 1);
    
    bisai = Button::createBtnWithSpriteFrameName("bisaijilu-01.png", false);
    bisai->setPosition(ccp(800, winSize.height - 50));
    bisai->setScale(0.6f);
    bisai->setOnClickCallback(callfuncO_selector(PersonCenterBase::BisaiClick), this);
    bisai->setPressIcon("bisaijilu-02.png", false);
    addChild(bisai, 1);
    
    Button* set = Button::createBtnWithSpriteFrameName("set_btn.png", false);
    set->setPosition(ccp(winSize.width - 200, 50));
    set->setScale(0.6f);
    set->setOnClickCallback(callfuncO_selector(PersonCenterBase::SetClick), this);
    addChild(set, 1);
    
    Button* backBtn = Button::createBtnWithSpriteFrameName("back_btn.png", false);
    backBtn->setPosition(ccp(winSize.width - 100, 50));
    backBtn->setScale(0.6f);
    backBtn->setOnClickCallback(callfuncO_selector(PersonCenterBase::BackClick), this);
    addChild(backBtn, 1);
    
    m_currentTag = TAG_NONE;
    
    ZiliaoClick(ziliao);
}

void PersonCenterBase::resetBtnState()
{
    ziliao->setPressIconShow(false);
    xinxi->setPressIconShow(false);
    rongyu->setPressIconShow(false);
    bisai->setPressIconShow(false);
    
    if(getChildByTag(TAG_ZILIAO))
    {
        removeChildByTag(TAG_ZILIAO);
    }
    else if(getChildByTag(TAG_XINXI))
    {
        removeChildByTag(TAG_XINXI);
    }
    else if(getChildByTag(TAG_BISAI))
    {
        removeChildByTag(TAG_BISAI);
    }
    else if(getChildByTag(TAG_RONGYU))
    {
        removeChildByTag(TAG_RONGYU);
    }
}

void PersonCenterBase::XinxiClick(cocos2d::CCObject *pSender)
{
    if(TAG_XINXI == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_XINXI;
    xinxi->setPressIconShow(true);
    
    PersonXinxi* xinxi = PersonXinxi::create();
    xinxi->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(xinxi, 10, TAG_XINXI);
    
}

void PersonCenterBase::ZiliaoClick(cocos2d::CCObject *pSender)
{
    if(TAG_ZILIAO == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_ZILIAO;
    ziliao->setPressIconShow(true);
    
    PersonInfo* info = PersonInfo::create();
    info->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(info, 10, TAG_ZILIAO);
}

void PersonCenterBase::RongyuClick(cocos2d::CCObject *pSender)
{
    if(TAG_RONGYU == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_RONGYU;
    rongyu->setPressIconShow(true);
    
    PersonRongyu* rongyu = PersonRongyu::create();
    rongyu->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(rongyu, 10, TAG_RONGYU);
}

void PersonCenterBase::BisaiClick(cocos2d::CCObject *pSender)
{
    if(TAG_BISAI == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_BISAI;
    bisai->setPressIconShow(true);
    
    PersonCenterLayer* layer = PersonCenterLayer::create();
    layer->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(layer, 10, TAG_BISAI);
}

void PersonCenterBase::SetClick(cocos2d::CCObject *pSender)
{
    
}

void PersonCenterBase::BackClick(cocos2d::CCObject *pSender)
{
    MainScene* main = dynamic_cast<MainScene*>(getParent());
    main->BackToLoginLayer(MainScene::TAG_LAYER_PERSON);
}

////////////////////////////////////////////////////////////////////
// 个人资料
////////////////////////////////////////////////////////////////////
PersonInfo::PersonInfo()
{
    
}

PersonInfo::~PersonInfo()
{
    
}

bool PersonInfo::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* iconBack = CCSprite::create("touxiang002.png");
    iconBack->setPosition(ccp(winSize.width * 0.5f - 350, winSize.height * 0.5f + 20));
    iconBack->setScale(0.6f);
    addChild(iconBack);
    
    //CCSprite* icon = CCSprite::create("morentouxiang01.png");
    //icon->setPosition(ccp(winSize.width * 0.5f - 350, winSize.height * 0.5f + 20));
    //icon->setScale(0.6f);
    //addChild(icon, 1);
    
    Button* changeHead = Button::createBtnWithSpriteFrameName("set_head_lb.png", false);
    changeHead->setPosition(ccp(winSize.width * 0.5f - 350, winSize.height * 0.5f - 80));
    changeHead->setOnClickCallback(callfuncO_selector(PersonInfo::ChangeHead), this);
    changeHead->setScale(0.6f);
    addChild(changeHead, 1);
    
    CCSprite* male = CCSprite::create("male.png");
    male->setPosition(ccp(winSize.width * 0.5f - 450, winSize.height * 0.5f - 150));
    male->setScale(0.6f);
    addChild(male, 1);
    
    CCLabelTTF* name = CCLabelTTF::create("B0B69845026", "STXingkai.ttf", 36);
    name->setColor(ccc3(1, 1, 1));
    name->setAnchorPoint(ccp(0,0));
    name->setPosition(ccp(winSize.width * 0.5f - 430, winSize.height * 0.5f - 170));
    addChild(name, 1);
    
    CCSprite* disBack = CCSprite::create("dis_frame.png");
    disBack->setPosition(ccp(winSize.width * 0.5f - 340, winSize.height * 0.5f - 220));
    disBack->setScale(0.6f);
    addChild(disBack, 1);
    
    CCSprite* guoqi = CCSprite::create("guoqi-001.png");
    CCSize disSize = disBack->getContentSize();
    guoqi->setPosition(ccp(disSize.width * 0.5f, disSize.height * 0.5f));
    //guoqi->setScale(0.6f);
    disBack->addChild(guoqi, 1);
    
    CCSprite* conBack = CCSprite::create("dis_frame.png");
    conBack->setPosition(ccp(winSize.width * 0.5f - 340, winSize.height * 0.5f - 290));
    conBack->setScale(0.6f);
    addChild(conBack, 1);
    
    CCLabelTTF* content = CCLabelTTF::create("这家伙很懒，什么都没有留下", "STXingkai.ttf", 36);
    content->setColor(ccc3(1, 1, 1));
    //content->setAnchorPoint(ccp(0,0));
    content->setPosition(ccp(disSize.width * 0.5f, disSize.height * 0.5f));
    conBack->addChild(content, 1);
    
    // splite
    CCSprite* splite = CCSprite::create("splite.png");
    splite->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    splite->setScale(0.6f);
    addChild(splite, 1);
    
    //右侧
    CCSprite* dengjiTitle = CCSprite::create("jinhuadengji01.png");
    dengjiTitle->setPosition(ccp(winSize.width * 0.5f + 80, winSize.height * 0.5f + 80));
    dengjiTitle->setScale(0.6f);
    addChild(dengjiTitle, 1);
    
    //铜钱
    CCSprite* copperlb = CCSprite::create("tongqian001.png");
    copperlb->setPosition(ccp(winSize.width * 0.5f + 55, winSize.height * 0.5f + 35));
    copperlb->setScale(0.6f);
    addChild(copperlb, 1);
    
    CCLabelTTF* copLabel = CCLabelTTF::create("2", "STXingkai.ttf", 29);
    copLabel->setColor(ccc3(1, 1, 1));
    copLabel->setPosition(ccp(winSize.width * 0.5f + 130, winSize.height * 0.5f + 35));
    addChild(copLabel, 1);
    
    CCSprite* copIcon = CCSprite::create("copper.png");
    copIcon->setPosition(ccp(winSize.width * 0.5f + 180, winSize.height * 0.5f + 35));
    copIcon->setScale(0.6f);
    addChild(copIcon, 1);
    
    //段位
    CCSprite* duanweilb = CCSprite::create("duanwei001.png");
    duanweilb->setPosition(ccp(winSize.width * 0.5f + 55, winSize.height * 0.5f - 10));
    duanweilb->setScale(0.6f);
    addChild(duanweilb, 1);
    
    //此处先写死
    CCSprite* dwIcon = CCSprite::create("001duanwei.png");
    dwIcon->setPosition(ccp(winSize.width * 0.5f + 115, winSize.height * 0.5f - 10));
    dwIcon->setScale(0.6f);
    addChild(dwIcon, 1);
    
    CCSprite* dwtext = CCSprite::create("001duanwei02.png");
    dwtext->setPosition(ccp(winSize.width * 0.5f + 155, winSize.height * 0.5f -10));
    dwtext->setScale(0.6f);
    addChild(dwtext, 1);
    
    
    // mvp数
    CCSprite* mvplb = CCSprite::create("zongMVPshu001.png");
    mvplb->setPosition(ccp(winSize.width * 0.5f + 80, winSize.height * 0.5f - 55));
    mvplb->setScale(0.6f);
    addChild(mvplb, 1);
    
    CCSprite* mvpIcon = CCSprite::create("mvp.png");
    mvpIcon->setPosition(ccp(winSize.width * 0.5f + 160, winSize.height * 0.5f - 55));
    mvpIcon->setScale(0.6f);
    addChild(mvpIcon, 1);
    
    CCLabelTTF* mvpLabel = CCLabelTTF::create("0", "STXingkai.ttf", 29);
    mvpLabel->setColor(ccc3(1, 1, 1));
    mvpLabel->setPosition(ccp(winSize.width * 0.5f + 200, winSize.height * 0.5f - 55));
    addChild(mvpLabel, 1);
    
    
    // 总轮数
    CCSprite* lunshulb = CCSprite::create("zonglunshu001.png");
    lunshulb->setPosition(ccp(winSize.width * 0.5f + 70, winSize.height * 0.5f - 95));
    lunshulb->setScale(0.6f);
    addChild(lunshulb, 1);
    
    CCLabelTTF* lunLabel = CCLabelTTF::create("1", "STXingkai.ttf", 29);
    lunLabel->setColor(ccc3(1, 1, 1));
    lunLabel->setPosition(ccp(winSize.width * 0.5f + 140, winSize.height * 0.5f - 95));
    addChild(lunLabel, 1);
    
    // 总冠军数
    CCSprite* winlb = CCSprite::create("zongguanjunshu001.png");
    winlb->setPosition(ccp(winSize.width * 0.5f + 80, winSize.height * 0.5f - 140));
    winlb->setScale(0.6f);
    addChild(winlb, 1);
    
    CCLabelTTF* winLabel = CCLabelTTF::create("1", "STXingkai.ttf", 29);
    winLabel->setColor(ccc3(1, 1, 1));
    winLabel->setPosition(ccp(winSize.width * 0.5f + 150, winSize.height * 0.5f - 140));
    addChild(winLabel, 1);
    
    
    // 总吞噬人数
    CCSprite* playerlb = CCSprite::create("zongtunshirenshu001.png");
    playerlb->setPosition(ccp(winSize.width * 0.5f + 90, winSize.height * 0.5f - 185));
    playerlb->setScale(0.6f);
    addChild(playerlb, 1);
    
    CCLabelTTF* playerLabel = CCLabelTTF::create("48", "STXingkai.ttf", 29);
    playerLabel->setColor(ccc3(1, 1, 1));
    playerLabel->setPosition(ccp(winSize.width * 0.5f + 190, winSize.height * 0.5f - 185));
    addChild(playerLabel, 1);
    
    // 总吞噬数
    CCSprite* eatlb = CCSprite::create("zongtunshishu001.png");
    eatlb->setPosition(ccp(winSize.width * 0.5f + 80, winSize.height * 0.5f - 225));
    eatlb->setScale(0.6f);
    addChild(eatlb, 1);
    
    CCLabelTTF* eatLabel = CCLabelTTF::create("48", "STXingkai.ttf", 29);
    eatLabel->setColor(ccc3(1, 1, 1));
    eatLabel->setPosition(ccp(winSize.width * 0.5f + 170, winSize.height * 0.5f - 225));
    addChild(eatLabel, 1);
    
    // 最大体重
    CCSprite* weightlb = CCSprite::create("zuidatizhong.png");
    weightlb->setPosition(ccp(winSize.width * 0.5f + 80, winSize.height * 0.5f - 270));
    weightlb->setScale(0.6f);
    addChild(weightlb, 1);
    
    CCLabelTTF* weightLabel = CCLabelTTF::create("50千克", "STXingkai.ttf", 29);
    weightLabel->setColor(ccc3(1, 1, 1));
    weightLabel->setPosition(ccp(winSize.width * 0.5f + 200, winSize.height * 0.5f - 270));
    addChild(weightLabel, 1);
    
//    InputLabel* nick = InputLabel::createText("", CCPointMake(0, -3.0f), CCSizeMake(400, 80));
//    nick->setPosition(ccp(winSize.width * 0.5f - 350, winSize.height * 0.5 - 200));
//    nick->setFontSize(25.0f);
//    addChild(nick, 1, 101);
    
    
    
    return true;
}

void PersonInfo::ChangeHead(cocos2d::CCObject *pSender)
{
    
}


////////////////////////////////////////////////////////
///PersonXinix
////////////////////////////////////////////////////////
PersonXinxi::PersonXinxi()
{
    
}

PersonXinxi::~PersonXinxi()
{
    
}

bool PersonXinxi::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* iconBack = CCSprite::create("touxiang002.png");
    iconBack->setPosition(ccp(winSize.width * 0.5f - 350, winSize.height * 0.5f - 10));
    iconBack->setScale(0.6f);
    addChild(iconBack);
    
    //CCSprite* icon = CCSprite::create("morentouxiang01.png");
    //icon->setPosition(ccp(winSize.width * 0.5f - 350, winSize.height * 0.5f - 10));
    //icon->setScale(0.6f);
    //addChild(icon, 1);
    
    CCSprite* guoqi = CCSprite::create("guoqi-001.png");
    guoqi->setPosition(ccp(winSize.width * 0.5f - 350, winSize.height * 0.5f - 110));
    //guoqi->setScale(0.6f);
    addChild(guoqi, 1);
    
    CCSprite* changeTitle = CCSprite::create("qiehuanyonghu01.png");
    changeTitle->setPosition(ccp(winSize.width * 0.5f - 430, winSize.height * 0.5f - 180));
    changeTitle->setScale(0.6f);
    addChild(changeTitle, 1);
    
    CCSprite* changeFrame = CCSprite::create("change_frame.png");
    changeFrame->setPosition(ccp(winSize.width * 0.5f - 310, winSize.height * 0.5f - 250));
    changeFrame->setScale(0.6f);
    addChild(changeFrame, 1);
    
    CCLabelTTF* name = CCLabelTTF::create("B0B69845026", "STXingkai.ttf", 60);
    name->setColor(ccc3(255, 255, 255));
    CCSize size = changeFrame->getContentSize();
    name->setPosition(ccp(size.width * 0.5f - 80, size.height * 0.5f));
    changeFrame->addChild(name, 1);
    
    Button* downBtn = Button::createBtnWithSpriteFrameName("change_down.png", false);
    downBtn->setPosition(ccp(size.width * 0.5f + 190, size.height * 0.5f));
    downBtn->setOnClickCallback(callfuncO_selector(PersonXinxi::ChangePlayer), this);
    changeFrame->addChild(downBtn, 1);
    
    // splite
    CCSprite* splite = CCSprite::create("splite.png");
    splite->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    splite->setScale(0.6f);
    addChild(splite, 1);
    
    // 右侧
    CCSprite* registTitle = CCSprite::create("zhucechengzhengshiyonghu001.png");
    registTitle->setPosition(ccp(winSize.width * 0.5 + 200, winSize.height * 0.5f + 60));
    registTitle->setScale(0.6f);
    addChild(registTitle, 1);
    
    CCSprite* registCont = CCSprite::create("yonghuzhucexiangqing002.png");
    registCont->setPosition(ccp(winSize.width * 0.5 + 200, winSize.height * 0.5f - 100));
    registCont->setScale(0.6f);
    addChild(registCont, 1);
    
    Button* registBtn = Button::createBtnWithSpriteFrameName("register_btn.png", false);
    registBtn->setPosition(ccp(winSize.width * 0.5f + 200, winSize.height * 0.5f - 250));
    registBtn->setScale(0.6f);
    registBtn->setOnClickCallback(callfuncO_selector(PersonXinxi::RegisterClick), this);
    addChild(registBtn, 1);
    
    return true;
}

void PersonXinxi::ChangePlayer(cocos2d::CCObject *pSender)
{
    
}

void PersonXinxi::RegisterClick(cocos2d::CCObject *pSender)
{
    
}

////////////////////////////////////////////////////////
/// personrongyu
////////////////////////////////////////////////////////
PersonRongyu::PersonRongyu()
{
    
}

PersonRongyu::~PersonRongyu()
{
    
}

bool PersonRongyu::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* rongyu_base = CCSprite::create("rongyu_base.png");
    rongyu_base->setPosition(ccp(winSize.width * 0.5 - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    rongyu_base->setScale(0.6f);
    addChild(rongyu_base, 1);
    
    CCLabelTTF* name = CCLabelTTF::create("第7赛季", "STXingkai.ttf", 36);
    name->setColor(ccc3(0, 0, 0));
    name->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f + 20));
    addChild(name, 1);
    
    CCSprite* star = CCSprite::create("xingxing1.png");
    star->setPosition(ccp(winSize.width * 0.5 - CHILD_OFFSET_X, winSize.height * 0.5f - 20));
    //star->setScale(0.6f);
    addChild(star, 1);
    
    CCSprite* icon = CCSprite::create("001duanwei.png");
    icon->setPosition(ccp(winSize.width * 0.5 - CHILD_OFFSET_X, winSize.height * 0.5f - 100));
    icon->setScale(3.0f);
    addChild(icon, 1);
    
    CCSprite* qulity = CCSprite::create("001duanwei02.png");
    qulity->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - 220));
    qulity->setScale(1.2f);
    addChild(qulity, 1);
    
    CCLabelTTF* dengji = CCLabelTTF::create("未上榜", "STXingkai.ttf", 36);
    dengji->setColor(ccc3(0, 0, 0));
    dengji->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - 255));
    addChild(dengji, 1);
    
    return true;
}


////////////////////////////////////////////////////////
// 记录
PersonCenterLayer::PersonCenterLayer()
{
    infos.clear();
    
    bisaiInfo info1;
    info1.m_id = 1;
    info1.m_nickName = "了不起的球球";
    info1.m_lastTime = "5天前";
    info1.m_rank = "37";
    info1.m_weight = "0毫克";
    info1.m_number = "0";
    info1.m_duration = "33秒";
    info1.m_copper = "0";
    infos.push_back(info1);
    
    bisaiInfo info2;
    info2.m_id = 2;
    info2.m_nickName = "武大也疯狂";
    info2.m_lastTime = "8天前";
    info2.m_rank = "17";
    info2.m_weight = "0毫克";
    info2.m_number = "89";
    info2.m_duration = "1分58秒";
    info2.m_copper = "0";
    infos.push_back(info2);
    
    bisaiInfo info3;
    info3.m_id = 3;
    info3.m_nickName = "阳光下的日子";
    info3.m_lastTime = "9天前";
    info3.m_rank = "56";
    info3.m_weight = "0毫克";
    info3.m_number = "45";
    info3.m_duration = "48秒";
    info3.m_copper = "0";
    infos.push_back(info3);
    
    bisaiInfo info4;
    info4.m_id = 4;
    info4.m_nickName = "飞行日记";
    info4.m_lastTime = "10天前";
    info4.m_rank = "28";
    info4.m_weight = "0毫克";
    info4.m_number = "5";
    info4.m_duration = "55秒";
    info4.m_copper = "4";
    infos.push_back(info4);
    
    bisaiInfo info5;
    info5.m_id = 5;
    info5.m_nickName = "批发初吻";
    info5.m_lastTime = "11天前";
    info5.m_rank = "30";
    info5.m_weight = "10毫克";
    info5.m_number = "10";
    info5.m_duration = "2分钟";
    info5.m_copper = "1";
    infos.push_back(info5);
}

PersonCenterLayer::~PersonCenterLayer()
{
    
}

bool PersonCenterLayer::init()
{
    if(!CCLayer::init())
        return false;
    
    //CCLayerColor* color = CCLayerColor::create(ccc4(255, 0, 0, 100), 1036, 460);
//    CCLayerColor* color = CCLayerColor::create(ccc4(0, 0, 0, 255), 1036, 460);
//    color->setPosition(ccp(0,0));
//    addChild(color,0);
    
    CCSprite* title_base = CCSprite::create("title_back.png");
    title_base->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height - 200 ));
    title_base->setScale(0.6f);
    addChild(title_base, 1);
    
    CCSprite* title_nick = CCSprite::create("title_nick.png");
    title_nick->setPosition(ccp(180, winSize.height - 200));
    title_nick->setScale(0.6f);
    addChild(title_nick, 1);
    
    CCSprite* title_rank = CCSprite::create("rank_title.png");
    title_rank->setPosition(ccp(330, winSize.height - 200));
    title_rank->setScale(0.6f);
    addChild(title_rank, 1);
    
    CCSprite* title_weight = CCSprite::create("title_weight.png");
    title_weight->setPosition(ccp(450, winSize.height - 200));
    title_weight->setScale(0.6f);
    addChild(title_weight, 1);
    
    CCSprite* title_num = CCSprite::create("tunshirenshu-002.png");
    title_num->setPosition(ccp(600, winSize.height - 200));
    title_num->setScale(0.6f);
    addChild(title_num, 1);
    
    CCSprite* title_duration = CCSprite::create("cunhuoshijian-002.png");
    title_duration->setPosition(ccp(750, winSize.height - 200));
    title_duration->setScale(0.6f);
    addChild(title_duration, 1);
    
    CCSprite* title_copper = CCSprite::create("tongqian-002.png");
    title_copper->setPosition(ccp(900, winSize.height - 200));
    title_copper->setScale(0.6f);
    addChild(title_copper, 1);
    
    CCTableView* tableView = CCTableView::create(this, getTableSize());
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(-20,0));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 2, 101);
    tableView->reloadData();
    
    return true;
}

CCSize PersonCenterLayer::getTableSize()
{
    return CCSizeMake(winSize.width - 2 * CHILD_OFFSET_X+40, winSize.height - 2 * CHILD_OFFSET_Y - 20);
}

void PersonCenterLayer::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell)
{
    
}

CCTableViewCell* PersonCenterLayer::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idex)
{
    CCTableViewCell* cell = table->dequeueCell();
    if(!cell)
    {
        cell = new CCTableViewCell();
        cell->autorelease();
        
        CCNode* cellNode = CCNode::create();
        //cellNode->setAnchorPoint(CCPointZero);
        cellNode->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, 0));
        
        createTableViewCell(cellNode, table, idex);
        cellNode->setTag(100);
        cell->addChild(cellNode, 20);
    }
    else
    {
        CCNode* cellNode = (CCNode*)cell->getChildByTag(100);
        cellNode->removeAllChildrenWithCleanup(true);
        createTableViewCell(cellNode, table, idex);
    }
    return cell;
}

void PersonCenterLayer::createTableViewCell(cocos2d::CCNode *cell, cocos2d::extension::CCTableView *table, int idex)
{
    int left = idex % 2;
    CCSprite* table_bg = NULL;
    if(left == 0)
        table_bg = CCSprite::create("bisai_cell_back1.png");
    else
        table_bg = CCSprite::create("bisai_cell_back2.png");
    if(table)
    {
        table_bg->setScale(0.6f);
        table_bg->setPosition(ccp(20,40));
        cell->addChild(table_bg,1);
        
        CCSize size = table_bg->getContentSize() * 0.6;
        
        bisaiInfo info = infos[idex];
        
        //CCSprite* icon = CCSprite::create("morentouxiang01.png");
        //icon->setPosition(ccp(70 - size.width * 0.5f+20, 40));
        //icon->setScale(0.4f);
        //cell->addChild(icon, 1);
        
        CCLabelTTF* nick_name = CCLabelTTF::create(info.m_nickName.c_str(), "STXingkai.ttf", 29);
        nick_name->setColor(ccc3(255, 255, 255));
        nick_name->setAnchorPoint(ccp(0,0));
        nick_name->setPosition(ccp(130 - size.width * 0.5f+20, 50));
        cell->addChild(nick_name, 1);
        
        CCLabelTTF* last_Time = CCLabelTTF::create(info.m_lastTime.c_str(), "STXingkai.ttf", 24);
        last_Time->setColor(ccc3(255, 255, 255));
        last_Time->setAnchorPoint(ccp(0,0));
        last_Time->setPosition(ccp(130 - size.width * 0.5f+20, 10));
        cell->addChild(last_Time, 1);
        
        CCLabelTTF* rank = CCLabelTTF::create(info.m_rank.c_str(), "STXingkai.ttf", 29);
        rank->setColor(ccc3(255, 255, 255));
        rank->setAnchorPoint(ccp(0,0));
        rank->setPosition(ccp(320 - size.width * 0.5f+20, 30));
        cell->addChild(rank, 1);
        
        CCLabelTTF* weight = CCLabelTTF::create(info.m_weight.c_str(), "STXingkai.ttf", 29);
        weight->setColor(ccc3(255, 255, 255));
        weight->setAnchorPoint(ccp(0,0));
        weight->setPosition(ccp(420 - size.width * 0.5f+20, 30));
        cell->addChild(weight, 1);
        
        CCLabelTTF* num = CCLabelTTF::create(info.m_number.c_str(), "STXingkai.ttf", 29);
        num->setColor(ccc3(255, 255, 255));
        num->setAnchorPoint(ccp(0,0));
        num->setPosition(ccp(90, 30));
        cell->addChild(num, 1);
        
        CCLabelTTF* duration = CCLabelTTF::create(info.m_duration.c_str(), "STXingkai.ttf", 29);
        duration->setColor(ccc3(255, 255, 255));
        duration->setAnchorPoint(ccp(0,0));
        duration->setPosition(ccp(220, 30));
        cell->addChild(duration, 1);
        
        CCLabelTTF* coppor = CCLabelTTF::create(info.m_copper.c_str(), "STXingkai.ttf", 29);
        coppor->setColor(ccc3(255, 255, 255));
        coppor->setAnchorPoint(ccp(0,0));
        coppor->setPosition(ccp(400, 30));
        cell->addChild(coppor, 1);
    }
}

CCSize PersonCenterLayer::cellSizeForTable(cocos2d::extension::CCTableView *table)
{
    CCSize tableSize = getTableSize();
    return CCSizeMake(tableSize.width, tableSize.height / 5);
}

unsigned int PersonCenterLayer::numberOfCellsInTableView(cocos2d::extension::CCTableView *table)
{
    return infos.size();
}

void PersonCenterLayer::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
    
}

void PersonCenterLayer::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
    
}




