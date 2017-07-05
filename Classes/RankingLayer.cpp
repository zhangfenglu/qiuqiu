//
//  RankingLayer.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/4/9.
//
//

#include "RankingLayer.h"
#include "MainScene.h"
#include "RichLabel.h"

#define CHILD_OFFSET_X      50
#define CHILD_OFFSET_Y      100

#include "msg_client.pb.h"
#include "struct.pb.h"
#include "ExchangeInfo.h"
#include "msg_error.pb.h"

#include "Resources.h"
#include "CurCularNode.h"

/////////////////////////////////////////////////
///base
////////////////////////////////////////////////////

RankingLayerBase::RankingLayerBase()
{
    
}

RankingLayerBase::~RankingLayerBase()
{
    
}

bool RankingLayerBase::init()
{
    if(!CCLayer::init())
        return false;
    
    initUI();
    
    return true;
}

void RankingLayerBase::initUI()
{
    CCSprite* back = CCSprite::create("center_back.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.6f);
    addChild(back);
    
    jhdwBtn = Button::createBtnWithSpriteFrameName("jianghudiwei-01.png", false);
    jhdwBtn->setPosition(ccp(130, winSize.height - 50));
    jhdwBtn->setScale(0.6f);
    jhdwBtn->setOnClickCallback(callfuncO_selector(RankingLayerBase::JhdwClick), this);
    jhdwBtn->setPressIcon("jianghudiwei-02.png", false);
    jhdwBtn->setPressIconShow(true);
    addChild(jhdwBtn, 1);
    
    cbzBtn = Button::createBtnWithSpriteFrameName("chongbaizhe-01.png", false);
    cbzBtn->setPosition(ccp(330, winSize.height - 50));
    cbzBtn->setScale(0.6f);
    cbzBtn->setOnClickCallback(callfuncO_selector(RankingLayerBase::CbzClick), this);
    cbzBtn->setPressIcon("chongbaizhe-02.png", false);
    addChild(cbzBtn, 1);
    
    ymzBtn = Button::createBtnWithSpriteFrameName("yangmuzhe-01.png", false);
    ymzBtn->setPosition(ccp(480, winSize.height - 50));
    ymzBtn->setScale(0.6f);
    ymzBtn->setOnClickCallback(callfuncO_selector(RankingLayerBase::YmzClick), this);
    ymzBtn->setPressIcon("yangmuzhe-02.png", false);
    addChild(ymzBtn, 1);
    
    //xzzBtn = Button::createBtnWithSpriteFrameName("xiaozhenzhu-01.png", false);
    //xzzBtn->setPosition(ccp(630, winSize.height - 50));
    //xzzBtn->setScale(0.6f);
    //xzzBtn->setOnClickCallback(callfuncO_selector(RankingLayerBase::XzzClick), this);
    //xzzBtn->setPressIcon("xiaozhenzhu-02.png", false);
    //addChild(xzzBtn, 1);
    
    jssBtn = Button::createBtnWithSpriteFrameName("jishashu-01.png", false);
    jssBtn->setPosition(ccp(630, winSize.height - 50));
    jssBtn->setScale(0.6f);
    jssBtn->setOnClickCallback(callfuncO_selector(RankingLayerBase::JssClick), this);
    jssBtn->setPressIcon("jishashu-02.png", false);
    addChild(jssBtn, 1);
    
    Button* backBtn = Button::createBtnWithSpriteFrameName("rankingback.png", false);
    backBtn->setPosition(ccp(winSize.width - 60, 40));
    backBtn->setScale(0.6f);
    backBtn->setOnClickCallback(callfuncO_selector(RankingLayerBase::BackClick), this);
    addChild(backBtn, 1);
    
    m_rankTag = TAG_NONE;
    
    scheduleOnce(schedule_selector(RankingLayerBase::SenMSG), 0.01f);
}
void RankingLayerBase::SenMSG(float ft)
{
    JhdwClick(jhdwBtn);
}
void RankingLayerBase::resetBtnState()
{
    jhdwBtn->setPressIconShow(false);
    cbzBtn->setPressIconShow(false);
    ymzBtn->setPressIconShow(false);
    //xzzBtn->setPressIconShow(false);
    jssBtn->setPressIconShow(false);
    
    if(getChildByTag(TAG_JHDW))
    {
        removeChildByTag(TAG_JHDW);
    }
    else if(getChildByTag(TAG_CBZ))
    {
        removeChildByTag(TAG_CBZ);
    }
    else if(getChildByTag(TAG_YMZ))
    {
        removeChildByTag(TAG_YMZ);
    }
    //else if(getChildByTag(TAG_XZZ))
    //{
        //removeChildByTag(TAG_XZZ);
    //}
    else if(getChildByTag(TAG_JSS))
    {
        removeChildByTag(TAG_JSS);
    }
}

void RankingLayerBase::JhdwClick(cocos2d::CCObject *pSender)
{
    if(TAG_JHDW == m_rankTag)
        return;
    
    resetBtnState();
    m_rankTag = TAG_JHDW;
    jhdwBtn->setPressIconShow(true);
    
    RankingLayerChild* child = RankingLayerChild::create();
    child->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(child, 10, TAG_JHDW);
    
    ((MainScene*)getParent())->reqRanks(1, 1);
}

void RankingLayerBase::CbzClick(cocos2d::CCObject *pSender)
{
    if(TAG_CBZ == m_rankTag)
        return;
    
    resetBtnState();
    m_rankTag = TAG_CBZ;
    cbzBtn->setPressIconShow(true);
    
    RankingLayerChild* child = RankingLayerChild::create();
    child->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(child, 10, TAG_CBZ);
    
    ((MainScene*)getParent())->reqRanks(2, 1);
}

void RankingLayerBase::YmzClick(cocos2d::CCObject *pSender)
{
    if(TAG_YMZ == m_rankTag)
        return;
    
    resetBtnState();
    m_rankTag = TAG_YMZ;
    ymzBtn->setPressIconShow(true);
    
    RankingLayerChild* child = RankingLayerChild::create();
    child->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(child, 10, TAG_YMZ);
    
    ((MainScene*)getParent())->reqRanks(3, 1);
}

void RankingLayerBase::XzzClick(cocos2d::CCObject *pSender)
{
    /*
    if(TAG_XZZ == m_rankTag)
        return;
    
    resetBtnState();
    m_rankTag = TAG_XZZ;
    xzzBtn->setPressIconShow(true);
    
    RankingLayerChild* child = RankingLayerChild::create();
    child->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(child, 10, TAG_XZZ);
    
    ((MainScene*)getParent())->reqRanks(4, 1);
     */
}

void RankingLayerBase::JssClick(cocos2d::CCObject *pSender)
{
    if(TAG_JSS == m_rankTag)
        return;
    
    resetBtnState();
    m_rankTag = TAG_JSS;
    jssBtn->setPressIconShow(true);
    
    RankingLayerChild* child = RankingLayerChild::create();
    child->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(child, 10, TAG_JSS);
    
    ((MainScene*)getParent())->reqRanks(5, 1);
}

void RankingLayerBase::BackClick(cocos2d::CCObject *pSender)
{
    MainScene* main = dynamic_cast<MainScene*>(getParent());
    main->BackToLoginLayer(MainScene::TAG_LAYER_RANKING);
}
void RankingLayerBase::respRanks(const WebSocket::Data &data)
{
    // 此处需要纪录有头像的
    std::vector<int> icons;
    icons.clear();
    
    UM_Ranks resp;
    bool re = resp.ParseFromArray(data.bytes + 2, data.len - 2);
    if(re)
    {
        //std::vector<rank_info> items;
        std::vector<TestRank> ranks;
        std::vector<TestRank> ranks1;
        int num = resp.list_size();
        //CCLog("list number is:%d", num);
        for( int i = 0; i < num; i++)
        {
            TestRank  rank;
            rank_info item = resp.list(i);
            //items.push_back(item);
            
            rank.m_id = item.roleid();
            rank.m_iconDex = item.icon();
            rank.m_sex = item.sex();
            rank.m_rank = item.rank();
            rank.m_name = item.name();
            
            int value1 = item.value1();
            int value2 = item.value2();
            char strlab[128] = {0};
            
            switch (m_rankTag)
            {
                case TAG_JHDW:
                {
                    uint8_t right, left; // right星级，left 段位
                    right = value1 & 0x00ff;
                    left = value1 >> 8;
                    
                    //duanweiInfo duan = Resource::sharedResource()->GetDuanweiInfo(left);
                    //CCLog("left is:%d, right is:%d", left, right);
                    
                    rank.m_duanwei = left;
                    rank.m_xing = right;
                }
                    break;
                case TAG_CBZ:
                {
                    sprintf(strlab, "%d",value1);
                    rank.m_zjrs = strlab;
                    sprintf(strlab, "%d",value2);
                    rank.m_zcbs = strlab;
                }
                    break;
                case TAG_YMZ:
                {
                    sprintf(strlab, "%d",value1);
                    rank.m_zjymz = strlab;
                    sprintf(strlab, "%d",value2);
                    rank.m_zymz = strlab;
                }
                    break;
                //case TAG_XZZ:
                //{
                    //sprintf(strlab, "%d",value1);
                    //rank.m_zjhds = strlab;
                    //sprintf(strlab, "%d",value2);
                    //rank.m_hdzs = strlab;
                //}
                    break;
                case TAG_JSS:
                {
                    sprintf(strlab, "%d",value1);
                    rank.m_zjjss = strlab;
                    sprintf(strlab, "%d",value2);
                    rank.m_zjss = strlab;
                }
                    break;
                default:
                    break;
            }
            if(rank.m_iconDex < 101)
            {
                icons.push_back(rank.m_id);
            }
            
            ranks.push_back(rank);
        }
        
        ((RankingLayerChild*)getChildByTag(m_rankTag))->setRanks(ranks);
        
        // 活的icons
        if(icons.size() > 0)
        {
            MainScene* main = dynamic_cast<MainScene*>(getParent());
            main->reqIcons(icons);
            
        }else{
            ((RankingLayerChild*)getChildByTag(m_rankTag))->initTableView();
        }
    }
}

void RankingLayerBase::respRankIcons(std::vector<icon_data> icons)
{
    ((RankingLayerChild*)getChildByTag(m_rankTag))->updateRanks(icons);
}

///////////////////////////////////////////////////////////////////
////RankingLayerChild
///////////////////////////////////////////////////////////////////
RankingLayerChild::RankingLayerChild()
{
    m_atts.clear();
    /*
    TestRank rank1;
    rank1.m_id = 1;
    rank1.m_sex = 1;
    rank1.m_name = "B0B69845026";
    rank1.m_diwei = "超神127杀";
    rank1.m_zjrs = "5123";
    rank1.m_zcbs = "14233";
    rank1.m_zjymz = "5123";
    rank1.m_zymz = "14233";
    rank1.m_zjhds = "5123";
    rank1.m_hdzs = "14233";
    rank1.m_zjjss = "5123";
    rank1.m_zjss = "14233";
    m_atts.push_back(rank1);
    
    TestRank rank2;
    rank2.m_id = 2;
    rank2.m_sex = 1;
    rank2.m_name = "B0B69845027";
    rank2.m_diwei = "超神88杀";
    rank2.m_zjrs = "4534";
    rank2.m_zcbs = "8845";
    m_atts.push_back(rank2);
    
    TestRank rank3;
    rank3.m_id = 3;
    rank3.m_sex = 1;
    rank3.m_name = "B0B69845028";
    rank3.m_diwei = "超神68杀";
    rank3.m_zjrs = "4533";
    rank3.m_zcbs = "5334";
    m_atts.push_back(rank3);
    
    TestRank rank4;
    rank4.m_id = 4;
    rank4.m_sex = 1;
    rank4.m_name = "B0B69845029";
    rank4.m_diwei = "超神54杀";
    rank4.m_zjrs = "3245";
    rank4.m_zcbs = "4335";
    m_atts.push_back(rank4);
    
    TestRank rank5;
    rank5.m_id = 5;
    rank5.m_sex = 1;
    rank5.m_name = "B0B69845030";
    rank5.m_diwei = "超神33杀";
    rank5.m_zjrs = "2415";
    rank5.m_zcbs = "3322";
    m_atts.push_back(rank5);
    
    TestRank rank6;
    rank6.m_id = 6;
    rank6.m_sex = 1;
    rank6.m_name = "B0B69845031";
    rank6.m_diwei = "超神12杀";
    rank6.m_zjrs = "1223";
    rank6.m_zcbs = "2089";
    m_atts.push_back(rank6);
    */
}

RankingLayerChild::~RankingLayerChild()
{
    
}

bool RankingLayerChild::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* title_back = CCSprite::create("title_frame.png");
    title_back->setPosition(ccp(winSize.width * 0.5f-20, winSize.height - CHILD_OFFSET_Y - 100));
    title_back->setScale(0.55f);
    addChild((title_back));
    
    CCSprite* back = CCSprite::create("dikuangbeijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f -20, winSize.height * 0.5f - CHILD_OFFSET_Y - 30));
    back->setScale(0.55f);
    addChild(back);
    
    CCSprite* rank_lb = CCSprite::create("paiming-01.png");
    rank_lb->setPosition(ccp(winSize.width * 0.5f - 420, winSize.height - CHILD_OFFSET_Y - 100));
    rank_lb->setScale(0.55f);
    addChild(rank_lb, 1);
    
    CCSprite* name_lb = CCSprite::create("yonghuming-01.png");
    name_lb->setPosition(ccp(winSize.width * 0.5f - 180, winSize.height - CHILD_OFFSET_Y - 100));
    name_lb->setScale(0.55f);
    addChild(name_lb, 1);
    
    //scheduleOnce(schedule_selector(RankingLayerChild::initTableView), 0.1);
    
    return true;
}

void RankingLayerChild::setRanks(std::vector<TestRank> ranks)
{
    m_atts.clear();
    m_atts = ranks;
}

void RankingLayerChild::updateRanks(std::vector<icon_data> datas)
{
    std::vector<TestRank>::iterator it = m_atts.begin();
    for(; it != m_atts.end(); ++it)
    {
        if((*it).m_iconDex < 101)
        {
            (*it).m_iconStr = getIconString((*it).m_id, datas);
        }
    }
    
    initTableView();
}

std::string RankingLayerChild::getIconString(int roleID, std::vector<icon_data>datas)
{
    std::vector<icon_data>::iterator it = datas.begin();
    for(; it != datas.end(); ++it)
    {
        icon_data data = *it;
        if(data.roleid() == roleID)
        {
            return data.data();
        }
    }
    
    return "";
}

void RankingLayerChild::initTableView()
{
    if (getChildByTag(101)) {
        ((CCTableView*)getChildByTag(101))->reloadData();
        return;
    }
    RankingLayerBase* base = dynamic_cast<RankingLayerBase*>(getParent());
    m_tag = base->GetCurrentTag();
    
    if(m_tag == RankingLayerBase::TAG_JHDW)
    {
        CCSprite* dw_lb = CCSprite::create("jianghudiwei-01.png");
        dw_lb->setPosition(ccp(winSize.width * 0.5f + 180, winSize.height - CHILD_OFFSET_Y - 100));
        dw_lb->setScale(0.4f);
        addChild(dw_lb, 1);
        
        btn1 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn1->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 160));
        btn1->setScale(0.55f);
        btn1->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn1), this);
        btn1->setPressIcon("kuang1_1.png", false);
        btn1->setPressIconShow(true);
        addChild(btn1, 1, 111);
        current_click_index = 1;
        
        RichLabel* lab1 = RichLabel::create(Global::getInstance()->getString("50"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab1->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 210));
        lab1->setAnchorPoint(CCPointZero);
        addChild(lab1, 2);
        
        btn2 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn2->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 310));
        btn2->setScaleX(0.55f);
        btn2->setScaleY(0.4f);
        btn2->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn2), this);
        btn2->setPressIcon("kuang1_1.png", false);
        addChild(btn2, 1, 112);
        
        RichLabel* lab2 = RichLabel::create(Global::getInstance()->getString("51"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab2->setAnchorPoint(CCPointZero);
        lab2->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 385));
        addChild(lab2, 2);
        
        btn3 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn3->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 475));
        btn3->setScaleX(0.55f);
        btn3->setScaleY(0.65f);
        btn3->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn3), this);
        btn3->setPressIcon("kuang1_1.png", false);
        addChild(btn3, 1, 113);
        
        RichLabel* lab3 = RichLabel::create(Global::getInstance()->getString("52"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 120),false,false);
        lab3->setAnchorPoint(CCPointZero);
        lab3->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 535));
        addChild(lab3, 2);

    }
    else if(m_tag == RankingLayerBase::TAG_CBZ)
    {
        CCSprite* zj_lb = CCSprite::create("zuijinhuoderenshu-01.png");
        zj_lb->setPosition(ccp(winSize.width * 0.5f + 130, winSize.height - CHILD_OFFSET_Y - 100));
        zj_lb->setScale(0.55f);
        addChild(zj_lb, 1);
        
        CCSprite* zcbz_lb = CCSprite::create("zongchongbaizheshu-01.png");
        zcbz_lb->setPosition(ccp(winSize.width * 0.5f + 280, winSize.height - CHILD_OFFSET_Y - 100));
        zcbz_lb->setScale(0.55f);
        addChild(zcbz_lb, 1);
        
        btn1 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn1->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 160));
        btn1->setScale(0.55f);
        btn1->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn1), this);
        btn1->setPressIcon("kuang1_1.png", false);
        btn1->setPressIconShow(true);
        addChild(btn1, 1, 111);
        current_click_index = 1;
        
        RichLabel* lab1 = RichLabel::create(Global::getInstance()->getString("53"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab1->setAnchorPoint(CCPointZero);
        lab1->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 210));
        addChild(lab1, 2);
        
        btn2 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn2->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 330));
        btn2->setScale(0.55f);
        btn2->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn2), this);
        btn2->setPressIcon("kuang1_1.png", false);
        addChild(btn2, 1, 112);
        
        RichLabel* lab2 = RichLabel::create(Global::getInstance()->getString("54"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab2->setAnchorPoint(CCPointZero);
        lab2->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 380));
        addChild(lab2, 2);
        
        btn3 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn3->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 500));
        btn3->setScale(0.55f);
        btn3->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn3), this);
        btn3->setPressIcon("kuang1_1.png", false);
        addChild(btn3, 1, 113);
        
        RichLabel* lab3 = RichLabel::create(Global::getInstance()->getString("55"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab3->setAnchorPoint(CCPointZero);
        lab3->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 555));
        addChild(lab3, 2);
    }
    else if(m_tag == RankingLayerBase::TAG_YMZ)
    {
        CCSprite* zjym_lb = CCSprite::create("zuijinhuodeyangmu-01.png");
        zjym_lb->setPosition(ccp(winSize.width * 0.5f + 130, winSize.height - CHILD_OFFSET_Y - 100));
        zjym_lb->setScale(0.55f);
        addChild(zjym_lb, 1);
        
        CCSprite* zymz_lb = CCSprite::create("zonghuodeyangmu-01.png");
        zymz_lb->setPosition(ccp(winSize.width * 0.5f + 280, winSize.height - CHILD_OFFSET_Y - 100));
        zymz_lb->setScale(0.55f);
        addChild(zymz_lb, 1);
        
        btn1 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn1->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 200));
        btn1->setScaleX(0.55f);
        btn1->setScaleY(0.8f);
        btn1->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn1), this);
        btn1->setPressIcon("kuang1_1.png", false);
        btn1->setPressIconShow(true);
        addChild(btn1, 1, 111);
        current_click_index = 1;
        
        RichLabel* lab1 = RichLabel::create(Global::getInstance()->getString("50"), "STXingkai.ttf", 40.0f, CCSizeMake(50, 100),false,false);
        lab1->setAnchorPoint(CCPointZero);
        lab1->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 250));
        addChild(lab1, 2);
        
        btn2 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn2->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 450));
        btn2->setScaleX(0.55f);
        btn2->setScaleY(0.8f);
        btn2->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn2), this);
        btn2->setPressIcon("kuang1_1.png", false);
        addChild(btn2, 1, 112);
        
        RichLabel* lab2 = RichLabel::create(Global::getInstance()->getString("51"), "STXingkai.ttf", 40.0f, CCSizeMake(50, 100),false,false);
        lab2->setAnchorPoint(CCPointZero);
        lab2->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 520));
        addChild(lab2, 2);

    }
    /*
    else if(m_tag == RankingLayerBase::TAG_XZZ)
    {
        CCSprite* zjzz_lb = CCSprite::create("zuijinhuodeshu-01.png");
        zjzz_lb->setPosition(ccp(winSize.width * 0.5f + 130, winSize.height - CHILD_OFFSET_Y - 100));
        zjzz_lb->setScale(0.55f);
        addChild(zjzz_lb, 1);
        
        CCSprite* zzz_lb = CCSprite::create("zonghuodeshu-01.png");
        zzz_lb->setPosition(ccp(winSize.width * 0.5f + 280, winSize.height - CHILD_OFFSET_Y - 100));
        zzz_lb->setScale(0.55f);
        addChild(zzz_lb, 1);
        
        btn1 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn1->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 200));
        btn1->setScaleX(0.55f);
        btn1->setScaleY(0.8f);
        btn1->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn1), this);
        btn1->setPressIcon("kuang1_1.png", false);
        btn1->setPressIconShow(true);
        addChild(btn1, 1, 111);
        current_click_index = 1;
        
        RichLabel* lab1 = RichLabel::create("上海榜", "STXingkai.ttf", 40.0f, CCSizeMake(50, 100),false,false);
        lab1->setAnchorPoint(CCPointZero);
        lab1->setPosition(ccp(10, winSize.height - CHILD_OFFSET_Y - 230));
        addChild(lab1, 2);
        
        btn2 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn2->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 450));
        btn2->setScaleX(0.55f);
        btn2->setScaleY(0.8f);
        btn2->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn2), this);
        btn2->setPressIcon("kuang1_1.png", false);
        addChild(btn2, 1, 112);
        
        RichLabel* lab2 = RichLabel::create("总榜", "STXingkai.ttf", 40.0f, CCSizeMake(50, 100),false,false);
        lab2->setAnchorPoint(CCPointZero);
        lab2->setPosition(ccp(10, winSize.height - CHILD_OFFSET_Y - 500));
        addChild(lab2, 2);
    }*/
    else if(m_tag == RankingLayerBase::TAG_JSS)
    {
        CCSprite* zjjs_lb = CCSprite::create("zuijinjishashu-01.png");
        zjjs_lb->setPosition(ccp(winSize.width * 0.5f + 130, winSize.height - CHILD_OFFSET_Y - 100));
        zjjs_lb->setScale(0.55f);
        addChild(zjjs_lb, 1);
        
        CCSprite* zjs_lb = CCSprite::create("zongjishashu-01.png");
        zjs_lb->setPosition(ccp(winSize.width * 0.5f + 280, winSize.height - CHILD_OFFSET_Y - 100));
        zjs_lb->setScale(0.55f);
        addChild(zjs_lb, 1);
        
        btn1 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn1->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 160));
        btn1->setScale(0.55f);
        btn1->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn1), this);
        btn1->setPressIcon("kuang1_1.png", false);
        btn1->setPressIconShow(true);
        addChild(btn1, 1, 111);
        current_click_index = 1;
        
        RichLabel* lab1 = RichLabel::create(Global::getInstance()->getString("53"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab1->setAnchorPoint(CCPointZero);
        lab1->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 210));
        addChild(lab1, 2);
        
        btn2 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn2->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 330));
        btn2->setScale(0.55f);
        btn2->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn2), this);
        btn2->setPressIcon("kuang1_1.png", false);
        addChild(btn2, 1, 112);
        
        RichLabel* lab2 = RichLabel::create(Global::getInstance()->getString("54"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab2->setAnchorPoint(CCPointZero);
        lab2->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 380));
        addChild(lab2, 2);
        
        btn3 = Button::createBtnWithSpriteFrameName("kuang1_2.png", false);
        btn3->setPosition(ccp(30, winSize.height - CHILD_OFFSET_Y - 500));
        btn3->setScale(0.55f);
        btn3->setOnClickCallback(callfuncO_selector(RankingLayerChild::clickBtn3), this);
        btn3->setPressIcon("kuang1_1.png", false);
        addChild(btn3, 1, 113);
        
        RichLabel* lab3 = RichLabel::create(Global::getInstance()->getString("55"), "STXingkai.ttf", 36.0f, CCSizeMake(50, 100),false,false);
        lab3->setAnchorPoint(CCPointZero);
        lab3->setPosition(ccp(15, winSize.height - CHILD_OFFSET_Y - 555));
        addChild(lab3, 2);
    }
    
    CCTableView* tableView = CCTableView::create(this, getTableSize());
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(40,0));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 2, 101);
    tableView->reloadData();
}

void RankingLayerChild::resetBtnState()
{
    RankingLayerBase* base = dynamic_cast<RankingLayerBase*>(getParent());
    RankingLayerBase::R_TAG tag = base->GetCurrentTag();
    if(tag == RankingLayerBase::TAG_JHDW || tag == RankingLayerBase::TAG_CBZ || tag == RankingLayerBase::TAG_JSS)
    {
        btn1->setPressIconShow(false);
        btn2->setPressIconShow(false);
        btn3->setPressIconShow(false);
    }
    else
    {
        btn1->setPressIconShow(false);
        btn2->setPressIconShow(false);
    }
}

void RankingLayerChild::clickBtn1(cocos2d::CCObject *pSender)
{
    Button* btn = dynamic_cast<Button*>(pSender);
    int index = btn->getTag()-110;
    if(index == current_click_index)
        return;
    
    resetBtnState();
    current_click_index = index;
    btn1->setPressIconShow(true);
    
    // 掉协议
    RankingLayerBase* base = dynamic_cast<RankingLayerBase*>(getParent());
    m_tag = base->GetCurrentTag();
    
    if(m_tag == RankingLayerBase::TAG_JHDW)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(1, 1);
    }
    
    if(m_tag == RankingLayerBase::TAG_CBZ)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(2, 1);
    }
    
    if(m_tag == RankingLayerBase::TAG_YMZ)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(3, 1);
    }
    /*
    if(m_tag == RankingLayerBase::TAG_XZZ)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(4, 1);
    }
    */
    if(m_tag == RankingLayerBase::TAG_JSS)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(5, 1);
    }
}

void RankingLayerChild::clickBtn2(cocos2d::CCObject *pSender)
{
    Button* btn = dynamic_cast<Button*>(pSender);
    int index = btn->getTag() - 110;
    if(index == current_click_index)
        return;
    
    resetBtnState();
    current_click_index = index;
    btn2->setPressIconShow(true);
    
    RankingLayerBase* base = dynamic_cast<RankingLayerBase*>(getParent());
    m_tag = base->GetCurrentTag();
    
    if(m_tag == RankingLayerBase::TAG_JHDW)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(1, 4);
    }
    
    if(m_tag == RankingLayerBase::TAG_CBZ)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(2, 2);
    }
    
    if(m_tag == RankingLayerBase::TAG_YMZ)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(3, 4);
    }
    /*
    if(m_tag == RankingLayerBase::TAG_XZZ)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(4, 4);
    }
    */
    if(m_tag == RankingLayerBase::TAG_JSS)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(5, 2);
    }
}

void RankingLayerChild::clickBtn3(cocos2d::CCObject *pSender)
{
    Button* btn = dynamic_cast<Button*>(pSender);
    int index = btn->getTag() - 110;
    if(index == current_click_index)
        return;
    
    resetBtnState();
    current_click_index = index;
    btn3->setPressIconShow(true);
    
    if(m_tag == RankingLayerBase::TAG_JHDW)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(1, 5);
    }
    
    if(m_tag == RankingLayerBase::TAG_CBZ)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(2, 4);
    }
    
    if(m_tag == RankingLayerBase::TAG_JSS)
    {
        ((MainScene*)getParent()->getParent())->reqRanks(5, 4);
    }
}

CCSize RankingLayerChild::getTableSize()
{
    return CCSizeMake(winSize.width - 2 * CHILD_OFFSET_X, winSize.height - 2 * CHILD_OFFSET_Y - 40);
}

void RankingLayerChild::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell)
{
    int idx = cell->getIdx();
    TestRank info = m_atts[idx];
    
    ((MainScene*)getParent()->getParent())->reqRole(info.m_id);
}

CCTableViewCell* RankingLayerChild::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idex)
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

void RankingLayerChild::createTableViewCell(cocos2d::CCNode *cell, cocos2d::extension::CCTableView *table, int idex)
{
    int left = idex % 2;
    CCSprite* table_bg = NULL;
    if(left == 0)
        table_bg = CCSprite::create("dikuangbaixian-01.png");
    else
        table_bg = CCSprite::create("dikuangbaixian-01.png");
    if(table)
    {
        table_bg->setScaleX(2.0);
        cell->addChild(table_bg,1);
        
       
        TestRank info = m_atts[idex];
        
        char temp[8];
        sprintf(temp, "%d", info.m_rank);
        CCLabelTTF* index = CCLabelTTF::create(temp, "STXingkai.ttf", 29);
        index->setColor(ccc3(255, 255, 255));
        index->setPosition(ccp( -430, 30));
        cell->addChild(index, 1);
        
        char temp1[32];
        CCSprite* icon;
        CirCularNode* iconCir;
        if(info.m_iconDex < 101)
        {
            CCTexture2D* tex = ExchangeInfo::GetTextureForData(info.m_iconStr.c_str());
            icon = CCSprite::createWithTexture(tex);
            icon->setScale(0.75f);
            iconCir = CirCularNode::create(25, icon);
        }
        else
        {
            sprintf(temp1, "hero_%d.png", info.m_iconDex);
            icon = CCSprite::create(temp1);
            icon->setScale(0.2f);
            iconCir = CirCularNode::create(25, icon);
        }
        
        iconCir->setPosition(ccp(-320, 32));
        cell->addChild(iconCir, 1);

        if (info.m_sex == 0) {
            CCSprite* sex = CCSprite::create("male.png");
            sex->setPosition(ccp(-260, 30));
            sex->setScale(0.8f);
            cell->addChild(sex, 1);
        }else{
            CCSprite* sex = CCSprite::create("female.png");
            sex->setPosition(ccp(-260, 30));
            sex->setScale(0.8f);
            cell->addChild(sex, 1);
        }
        
        if (info.m_name == "") {
            char namlab[64] = {0};
            sprintf(namlab, "S%d",info.m_id);
            info.m_name = namlab;
        }
        CCLabelTTF* nick_name = CCLabelTTF::create(info.m_name.c_str(), "STXingkai.ttf", 29);
        nick_name->setColor(ccc3(255, 255, 255));
        nick_name->setAnchorPoint(ccp(0,0));
        nick_name->setPosition(ccp(-200, 10));
        cell->addChild(nick_name, 1);
        
        if(m_tag == RankingLayerBase::TAG_JHDW)
        {
            duanweiInfo duan = Resource::sharedResource()->GetDuanweiInfo(info.m_duanwei);
            
            icon = CCSprite::create(duan.icon.c_str());
            icon->setPosition(ccp(130, 30));
            icon->setScale(0.3f);
            cell->addChild(icon, 1);
            
            CCLabelTTF* rank = CCLabelTTF::create(duan.name.c_str(), "STXingkai.ttf", 29);
            rank->setColor(ccc3(255, 255, 255));
            rank->setAnchorPoint(ccp(0,0));
            rank->setPosition(ccp(150, 10));
            cell->addChild(rank, 1);
            
            icon = CCSprite::create("hecheng-xx-02.png");
            icon->setScale(0.6f);
            icon->setPosition(ccp(230, 30));
            cell->addChild(icon, 2);
            
            sprintf(temp1, "%d", info.m_xing);
            rank = CCLabelTTF::create(temp1, "STXingkai.ttf", 29);
            rank->setColor(ccc3(255, 255, 255));
            rank->setAnchorPoint(ccp(0,0));
            rank->setPosition(ccp(250, 10));
            cell->addChild(rank, 1);
        }
        else
        {
            CCLabelTTF* rank1 = CCLabelTTF::create(info.m_zjrs.c_str(), "STXingkai.ttf", 29);
            rank1->setColor(ccc3(255, 255, 255));
            rank1->setAnchorPoint(ccp(0,0));
            rank1->setPosition(ccp(120, 10));
            cell->addChild(rank1, 1);
            
            CCLabelTTF* rank2 = CCLabelTTF::create(info.m_zcbs.c_str(), "STXingkai.ttf", 29);
            rank2->setColor(ccc3(255, 255, 255));
            rank2->setAnchorPoint(ccp(0,0));
            rank2->setPosition(ccp(260, 10));
            cell->addChild(rank2, 1);
        }
        
//        CCLabelTTF* duration = CCLabelTTF::create(info.m_state.c_str(), "华文行楷", 29);
//        duration->setColor(ccc3(255, 255, 255));
//        //duration->setAnchorPoint(ccp(0,0));
//        duration->setPosition(ccp(800 - size.width * 0.5f, 0));
//        cell->addChild(duration, 1);
//        
//        if(m_tag == RelationShipBase::TAG_ATTENTION || m_tag == RelationShipBase::TAG_FRIEND)
//        {
//            CCLabelTTF* rank = CCLabelTTF::create(info.m_dest.c_str(), "华文行楷", 29);
//            rank->setColor(ccc3(255, 255, 255));
//            rank->setAnchorPoint(ccp(0,0));
//            rank->setPosition(ccp(400 - size.width * 0.5f, -20));
//            cell->addChild(rank, 1);
//        }
//        else if(m_tag == RelationShipBase::TAG_ENEMY)
//        {
//            CCLabelTTF* rank = CCLabelTTF::create(info.m_times.c_str(), "华文行楷", 29);
//            rank->setColor(ccc3(255, 255, 255));
//            rank->setAnchorPoint(ccp(0,0));
//            rank->setPosition(ccp(480 - size.width * 0.5f, -20));
//            cell->addChild(rank, 1);
//        }
        
    
    }
}

CCSize RankingLayerChild::cellSizeForTable(cocos2d::extension::CCTableView *table)
{
    CCSize tableSize = getTableSize();
    return CCSizeMake(tableSize.width, tableSize.height / 6);
}

unsigned int RankingLayerChild::numberOfCellsInTableView(cocos2d::extension::CCTableView *table)
{
    return (int)m_atts.size();
}

void RankingLayerChild::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
    
}

void RankingLayerChild::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
    
}


