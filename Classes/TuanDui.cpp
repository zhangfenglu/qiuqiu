//
//  RelationShipLayer.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/4/8.
//
//

#include "TuanDui.h"
#include "MainScene.h"

#define CHILD_OFFSET_X      100
#define CHILD_OFFSET_Y      50
#define MAIN_TABLLEVIEW_ACTIVE      -120


#include "msg_client.pb.h"
#include "struct.pb.h"
#include "ExchangeInfo.h"
#include "msg_error.pb.h"
#include "CurCularNode.h"
/////////////////////////////////////////////////////
///base
/////////////////////////////////////////////////////
TuanDui::TuanDui()
{
    m_atts.clear();
    
    
     for (int i = 0; i<5; i++) {
         TestAtt tes;
         tes.m_id = 5252525;
         tes.m_icon = 102;
         tes.m_name = "nininii";
         tes.m_sex = 1;
         tes.m_state = "dadadadada";
         tes.m_dest = "";
         tes.m_iconStr = "";
         tes.m_times = "";
     
         m_atts.push_back(tes);
     }
}

TuanDui::~TuanDui()
{
    m_atts.clear();
    
}

bool TuanDui::init()
{
    if(!CCLayer::init())
        return false;
    
    initUI();
    
    CCTableView* tableView = CCTableView::create(this, getTableSize());
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    //tableView->setDirection(kCCScrollViewDirectionBoth);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(winSize.width/2-465,160));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 2, 101);
    tableView->reloadData();
    
    char temp[128] = {0};
    sprintf(temp, "sdfasdfe的队伍(%d/5)",(int)m_atts.size());
    CCLabelTTF* nick_name = CCLabelTTF::create(temp, "STXingkai.ttf", 29);
    nick_name->setColor(ccc3(0, 0, 0));
    //nick_name->setAnchorPoint(ccp(0,0));
    nick_name->setPosition(ccp(winSize.width/2,winSize.height-80));
    addChild(nick_name, 5);
    return true;
}

void TuanDui::initUI()
{
    CCSprite* back = CCSprite::create("center_back.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.6f);
    addChild(back);
    
    back = CCSprite::create("beijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScaleX(0.6f);
    back->setScaleY(0.8f);
    addChild(back);
    
    
    Button* backBtn = Button::createBtnWithSpriteFrameName("fanhui-01.png", false);
    backBtn->setPosition(ccp(winSize.width - 80, 50));
    backBtn->setScale(0.6f);
    backBtn->setOnClickCallback(callfuncO_selector(TuanDui::BackClick), this);
    addChild(backBtn, 1,1);
    
    backBtn = Button::createBtnWithSpriteFrameName("kaishibisai-01.png", false);
    backBtn->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f-215));
    backBtn->setScale(0.6f);
    backBtn->setPressIcon("kaishibisai-02.png", false);
    backBtn->setOnClickCallback(callfuncO_selector(TuanDui::StartGame), this);
    addChild(backBtn, 2,2);
    
    backBtn = Button::createBtnWithSpriteFrameName("yaoqing.png", false);
    backBtn->setPosition(ccp(winSize.width * 0.5f+260, winSize.height * 0.5f-215));
    backBtn->setScale(0.6f);
    //backBtn->setPressIcon("kaishibisai-02.png", false);
    backBtn->setOnClickCallback(callfuncO_selector(TuanDui::Yaoqing), this);
    addChild(backBtn, 2,3);
    
}

void TuanDui::Yaoqing(CCObject* pSender)
{
    ((CCTableView*)getChildByTag(101))->setTouchEnabled(false);
    ((Button*)getChildByTag(1))->setIsCanTouch(false);
    ((Button*)getChildByTag(2))->setIsCanTouch(false);
    ((Button*)getChildByTag(3))->setIsCanTouch(false);
    
    YaoqingList* relation = YaoqingList::create();
    addChild(relation, 10);
}
void TuanDui::SenMSG(float ft)
{
    //AttentionClick(m_attention);
}

void TuanDui::BackClick(cocos2d::CCObject *pSender)
{
    MainScene* main = dynamic_cast<MainScene*>(getParent());
    main->BackToLoginLayer(MainScene::TAG_LAYER_TUANDUI);
}
void TuanDui::StartGame(CCObject* pSender)
{
    
}

CCSize TuanDui::getTableSize()
{
    return CCSizeMake(930,375);
}

void TuanDui::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell)
{
    //int idx = cell->getIdx();
    //TestAtt info = m_atts[idx];
    
    //((MainScene*)getParent()->getParent())->reqRole(info.m_id);
}

CCTableViewCell* TuanDui::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idex)
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

void TuanDui::createTableViewCell(cocos2d::CCNode *cell, cocos2d::extension::CCTableView *table, int idex)
{
    int left = idex % 2;
    CCSprite* table_bg = NULL;
    if(left == 0)
        table_bg = CCSprite::create("dikuang-01.png");
    else
        table_bg = CCSprite::create("dikuang-02.png");
    if(table)
    {
        table_bg->setScale(0.6f);
        table_bg->setPosition(ccp(0,40));
        cell->addChild(table_bg,1);
        
        CCSize size = table_bg->getContentSize() * 0.6;
        
        TestAtt info = m_atts[idex];
        if (info.m_icon > 101) {
            char temp[32];
            sprintf(temp, "hero_%d.png", info.m_icon);
            CCSprite* icon = CCSprite::create(temp);
            CirCularNode* iconCir = CirCularNode::create(25, icon);
            iconCir->setPosition(ccp(50 - size.width * 0.5f, 40));
            icon->setScale(0.2f);
            cell->addChild(iconCir, 1);
        }else{
            
            CCTexture2D* tex = ExchangeInfo::GetTextureForData(info.m_iconStr.c_str());
            
            CCSprite* icon = CCSprite::createWithTexture(tex);
            CirCularNode* iconCir = CirCularNode::create(25, icon);
            iconCir->setPosition(ccp(50 - size.width * 0.5f, 40));
            icon->setScale(0.2f);
            cell->addChild(iconCir, 1);
        }
        
        
        CCSprite* sex = CCSprite::create("male.png");
        sex->setPosition(ccp(100 - size.width * 0.5f, 40));
        sex->setScale(0.8f);
        cell->addChild(sex, 1);
        
        if (info.m_name == "") {
            char namlab[64] = {0};
            sprintf(namlab, "S%d",info.m_id);
            info.m_name = namlab;
        }
        CCLabelTTF* nick_name = CCLabelTTF::create(info.m_name.c_str(), "STXingkai.ttf", 29);
        nick_name->setColor(ccc3(255, 255, 255));
        nick_name->setAnchorPoint(ccp(0,0));
        nick_name->setPosition(ccp(120 - size.width * 0.5f, 20));
        cell->addChild(nick_name, 1);
        
        CCLabelTTF* duration = CCLabelTTF::create(info.m_state.c_str(), "STXingkai.ttf", 29);
        duration->setColor(ccc3(255, 255, 255));
        //duration->setAnchorPoint(ccp(0,0));
        duration->setPosition(ccp(800 - size.width * 0.5f, 40));
        cell->addChild(duration, 1);
        
    }
}

CCSize TuanDui::cellSizeForTable(cocos2d::extension::CCTableView *table)
{
    CCSize tableSize = getTableSize();
    return CCSizeMake(tableSize.width, 75);
}

unsigned int TuanDui::numberOfCellsInTableView(cocos2d::extension::CCTableView *table)
{
    return 5;
}
void TuanDui::ReSetTabelView()
{
    ((CCTableView*)getChildByTag(101))->setTouchEnabled(true);
    ((Button*)getChildByTag(1))->setIsCanTouch(true);
    ((Button*)getChildByTag(2))->setIsCanTouch(true);
    ((Button*)getChildByTag(3))->setIsCanTouch(true);
}
////////////////////////////////////////////////////////////////////
//// 好友列表
////////////////////////////////////////////////////////////////////
YaoqingList::YaoqingList()
{
    m_currentTag    = TAG_NONE;
    m_attention     = NULL;
    m_friend        = NULL;
    m_enemy         = NULL;
    m_black         = NULL;
}

YaoqingList::~YaoqingList()
{
    m_currentTag    = TAG_NONE;
    m_attention     = NULL;
    m_friend        = NULL;
    m_enemy         = NULL;
    m_black         = NULL;
}

bool YaoqingList::init()
{
    if(!CCLayer::init())
        return false;
    
    initUI();
    
    return true;
}

void YaoqingList::initUI()
{
    //CCSprite* back = CCSprite::create("center_back.png");
    //back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    //back->setScale(0.6f);
    //addChild(back);
    
    CCSprite* back = CCSprite::create("beijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScaleX(0.6f);
    back->setScaleY(0.8f);
    addChild(back);
    
    m_attention = Button::createBtnWithSpriteFrameName("zuduiyaoqing-01.png", false);
    m_attention->setPosition(ccp(270, winSize.height - 80));
    m_attention->setScale(0.6f);
    m_attention->setOnClickCallback(callfuncO_selector(YaoqingList::AttentionClick), this);
    m_attention->setPressIcon("zuduiyaoqing-02.png", false);
    m_attention->setPressIconShow(true);
    addChild(m_attention, 1);
    
    m_friend = Button::createBtnWithSpriteFrameName("jinqiduiyou-01.png", false);
    m_friend->setPosition(ccp(560, winSize.height - 80));
    m_friend->setScale(0.6f);
    m_friend->setOnClickCallback(callfuncO_selector(YaoqingList::FriendClick), this);
    m_friend->setPressIcon("jinqiduiyou-02.png", false);
    addChild(m_friend, 1);
    
    m_enemy = Button::createBtnWithSpriteFrameName("fujinyaoqing-01.png", false);
    m_enemy->setPosition(ccp(850, winSize.height - 80));
    m_enemy->setScale(0.6f);
    m_enemy->setOnClickCallback(callfuncO_selector(YaoqingList::EnemyClick), this);
    m_enemy->setPressIcon("fujinyaoqing-02.png", false);
    addChild(m_enemy, 1);
    
    /*
    m_black = Button::createBtnWithSpriteFrameName("heimigndan-02.png", false);
    m_black->setPosition(ccp(940, winSize.height - 80));
    m_black->setScale(0.6f);
    m_black->setOnClickCallback(callfuncO_selector(YaoqingList::BlackClick), this);
    m_black->setPressIcon("heimingdan-01.png", false);
    addChild(m_black, 1);
     */
    
    Button* backBtn = Button::createBtnWithSpriteFrameName("fanhui-01.png", false);
    backBtn->setPosition(ccp(winSize.width - 80, 50));
    backBtn->setScale(0.6f);
    backBtn->setOnClickCallback(callfuncO_selector(YaoqingList::BackClick), this);
    addChild(backBtn, 1);
    
    m_currentTag = TAG_NONE;
    scheduleOnce(schedule_selector(YaoqingList::SenMSG), 0.01f);
}
void YaoqingList::SenMSG(float ft)
{
    AttentionClick(m_attention);
}
void YaoqingList::resetBtnState()
{
    m_attention->setPressIconShow(false);
    m_friend->setPressIconShow(false);
    m_enemy->setPressIconShow(false);
    //m_black->setPressIconShow(false);
    
    if(getChildByTag(TAG_ATTENTION))
    {
        removeChildByTag(TAG_ATTENTION);
    }
    else if(getChildByTag(TAG_FRIEND))
    {
        removeChildByTag(TAG_FRIEND);
    }
    else if(getChildByTag(TAG_ENEMY))
    {
        removeChildByTag(TAG_ENEMY);
    }
    //else if(getChildByTag(TAG_BLACK))
    //{
        //removeChildByTag(TAG_BLACK);
    //}
}

void YaoqingList::AttentionClick(cocos2d::CCObject *pSender)
{
    if(TAG_ATTENTION == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_ATTENTION;
    m_attention->setPressIconShow(true);
    
    TeamList* attention = TeamList::create();
    //attention->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(attention, 10, TAG_ATTENTION);
    
    //user_info usef = Global::getInstance()->GetUserInfo();
    //((MainScene*)getParent())->reqFriendList(1);
}

void YaoqingList::FriendClick(cocos2d::CCObject *pSender)
{
    if(TAG_FRIEND == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_FRIEND;
    m_friend->setPressIconShow(true);
    
    TeamList* attention = TeamList::create();
    //attention->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(attention, 10, TAG_FRIEND);
    
    //user_info usef = Global::getInstance()->GetUserInfo();
    //((MainScene*)getParent())->reqFans(2, 0, 20,usef.roleID);
}

void YaoqingList::EnemyClick(cocos2d::CCObject *pSender)
{
    if(TAG_ENEMY == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_ENEMY;
    m_enemy->setPressIconShow(true);
    
    TeamList* attention = TeamList::create();
    //attention->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(attention, 10, TAG_ENEMY);
    
    //((MainScene*)getParent())->reqFriendList(4);
}

void YaoqingList::BlackClick(cocos2d::CCObject *pSender)
{
    if(TAG_BLACK == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_BLACK;
    m_black->setPressIconShow(true);
    
    TeamList* attention = TeamList::create();
    attention->setPosition(ccp(CHILD_OFFSET_X, CHILD_OFFSET_Y));
    addChild(attention, 10, TAG_BLACK);
    
    //((MainScene*)getParent())->reqFriendList(3);
}

void YaoqingList::PrePageClick(cocos2d::CCObject *pSender)
{
    
}

void YaoqingList::NextPageClick(cocos2d::CCObject *pSender)
{
    
}

void YaoqingList::BackClick(cocos2d::CCObject *pSender)
{
    TuanDui* tuandui = (TuanDui*)getParent();
    tuandui->ReSetTabelView();
    getParent()->removeChild(this, true);
}


////////////////////////////////////////////////////////////////////
//// 好友列表
////////////////////////////////////////////////////////////////////
TeamList::TeamList()
{
    m_atts.clear();
    
}

TeamList::~TeamList()
{
    m_atts.clear();
    
}

bool TeamList::init()
{
    if(!CCLayer::init())
        return false;
    
//    CCLayerColor* color = CCLayerColor::create(ccc4(0, 0, 0, 255), 936, 460);
//    color->setPosition(ccp(0,0));
//    addChild(color,0);
    CCSprite* back = CCSprite::create("tuandui_labbg.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f+180));
    back->setScale(0.6f);
    addChild(back);
    
    
    CCLabelTTF* nick_name = CCLabelTTF::create(Global::getInstance()->getString("93"), "STXingkai.ttf", 29);
    nick_name->setColor(ccc3(0, 0, 0));
    nick_name->setPosition(ccp(winSize.width/2-200, winSize.height * 0.5f+180));
    addChild(nick_name, 1);
    
    nick_name = CCLabelTTF::create(Global::getInstance()->getString("142"), "STXingkai.ttf", 29);
    nick_name->setColor(ccc3(0, 0, 0));
    nick_name->setPosition(ccp(winSize.width/2+100, winSize.height * 0.5f+180));
    addChild(nick_name, 1);
    
    nick_name = CCLabelTTF::create(Global::getInstance()->getString("143"), "STXingkai.ttf", 29);
    nick_name->setColor(ccc3(0, 0, 0));
    nick_name->setPosition(ccp(winSize.width/2+300, winSize.height * 0.5f+180));
    addChild(nick_name, 1);
    //scheduleOnce(schedule_selector(RelationShipAttention::initTableView), 0.1);
    
    Button* m_enemy = Button::createBtnWithSpriteFrameName("fasongyaoqing-01.png", false);
    m_enemy->setPosition(ccp(winSize.width/2, 100));
    m_enemy->setScale(0.6f);
    m_enemy->setOnClickCallback(callfuncO_selector(TeamList::SendYaoqing), this);
    m_enemy->setPressIcon("fasongyaoqing-02.png", false);
    addChild(m_enemy, 1);
    
    Button* zhaopy = Button::createBtnWithSpriteFrameName("xuanze_btn_1.png", false);
    zhaopy->setPosition(ccp(winSize.width/2-360, 100));
    zhaopy->setScale(0.6f);
    zhaopy->setOnClickCallback(callfuncO_selector(TeamList::XuanzeAll), this);
    zhaopy->setPressIcon("xuanze_btn_2.png", false);
    addChild(zhaopy,2);
    
    nick_name = CCLabelTTF::create(Global::getInstance()->getString("144"), "STXingkai.ttf", 29);
    nick_name->setColor(ccc3(0, 0, 0));
    nick_name->setPosition(ccp(winSize.width/2-290, 100));
    addChild(nick_name, 1);
    
    std::vector<TestAtt>  fanses;
    for (int i = 0; i<10; i++) {
        TestAtt tes;
        tes.m_id = 5252525;
        tes.m_icon = 102;
        tes.m_name = "nininii";
        tes.m_sex = 1;
        tes.m_state = "dadadadada";
        tes.m_dest = "";
        tes.m_iconStr = "";
        tes.m_times = "";
        
        fanses.push_back(tes);
    }
    
    initTableView(fanses);
    return true;
}
void TeamList::XuanzeAll(CCObject* pSender)
{
    Button* btn = (Button*)pSender;
    CCTableView* view = (CCTableView*)getChildByTag(101);
    if(btn->getPressIconShow())
    {
        btn->setPressIconShow(true);
        
        for (int i=0; i<m_atts.size(); i++) {
            CCTableViewCell* cell = view->cellAtIndex(i);
            if(cell)
            {
                Button* btn1 = (Button*)cell->getChildByTag(100)->getChildByTag(1);
                if(btn1)
                    btn1->setPressIconShow(true);
            }
        }
    }
    else
    {
        btn->setPressIconShow(false);
        
        for (int i=0; i<m_atts.size(); i++) {
            CCTableViewCell* cell = view->cellAtIndex(i);
            if(cell)
            {
                Button* btn1 = (Button*)cell->getChildByTag(100)->getChildByTag(1);
                if(btn1)
                    btn1->setPressIconShow(false);
            }
        }
    }
}
void TeamList::SendYaoqing(CCObject* pSender)
{
    
}
void TeamList::initTableView(std::vector<TestAtt> fanses)
{
    m_atts = fanses;
    if (getChildByTag(101)) {
        ((CCTableView*)getChildByTag(101))->reloadData();
        return;
    }
    
    CCTableView* tableView = CCTableView::create(this, getTableSize());
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(winSize.width/2-465,150));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 2, 101);
    tableView->reloadData();
}
void TeamList::updateLists(std::vector<icon_data> datas)
{
    std::vector<TestAtt>::iterator it = m_atts.begin();
    for(; it != m_atts.end(); ++it)
    {
        if((*it).m_icon < 101)
        {
            (*it).m_iconStr = getIconString((*it).m_id, datas);
        }
    }
    
    initTableView(m_atts);
}
std::string TeamList::getIconString(int roleID, std::vector<icon_data>datas)
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
CCSize TeamList::getTableSize()
{
    return CCSizeMake(930, 320);
}

void TeamList::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell)
{
    int idx = cell->getIdx();
    TestAtt info = m_atts[idx];
    
    ((MainScene*)getParent()->getParent())->reqRole(info.m_id);
}

CCTableViewCell* TeamList::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idex)
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

void TeamList::createTableViewCell(cocos2d::CCNode *cell, cocos2d::extension::CCTableView *table, int idex)
{
    int left = idex % 2;
    CCSprite* table_bg = NULL;
    if(left == 0)
        table_bg = CCSprite::create("yaoqing-bg1.png");
    else
        table_bg = CCSprite::create("yaoqing-bg2.png");
    if(table)
    {
        table_bg->setScaleY(0.7f);
        table_bg->setScaleX(0.52f);
        table_bg->setPosition(ccp(0,40));
        cell->addChild(table_bg,1);
        
        CCSize size = table_bg->getContentSize() * 0.6;
        
        Button* zhaopy = Button::createBtnWithSpriteFrameName("xuanze_btn_1.png", false);
        zhaopy->setPosition(ccp(130 - size.width * 0.5f, 40));
        zhaopy->setScale(0.6f);
        zhaopy->setOnClickCallback(callfuncO_selector(TeamList::Xuanze), this);
        zhaopy->setPressIcon("xuanze_btn_2.png", false);
        cell->addChild(zhaopy,2,1);
        
        TestAtt info = m_atts[idex];
        if (info.m_icon > 101) {
            char temp[32];
            sprintf(temp, "hero_%d.png", info.m_icon);
            CCSprite* icon = CCSprite::create(temp);
            CirCularNode* iconCir = CirCularNode::create(25, icon);
            iconCir->setPosition(ccp(200 - size.width * 0.5f, 40));
            icon->setScale(0.2f);
            cell->addChild(iconCir, 1);
        }else{
            
            CCTexture2D* tex = ExchangeInfo::GetTextureForData(info.m_iconStr.c_str());
            
            CCSprite* icon = CCSprite::createWithTexture(tex);
            CirCularNode* iconCir = CirCularNode::create(25, icon);
            iconCir->setPosition(ccp(200 - size.width * 0.5f, 40));
            icon->setScale(0.2f);
            cell->addChild(iconCir, 1);
        }
        
        
        CCSprite* sex = CCSprite::create("male.png");
        sex->setPosition(ccp(250 - size.width * 0.5f, 40));
        sex->setScale(0.8f);
        cell->addChild(sex, 1);
        
        if (info.m_name == "") {
            char namlab[64] = {0};
            sprintf(namlab, "S%d",info.m_id);
            info.m_name = namlab;
        }
        CCLabelTTF* nick_name = CCLabelTTF::create(info.m_name.c_str(), "STXingkai.ttf", 29);
        nick_name->setColor(ccc3(255, 255, 255));
        nick_name->setAnchorPoint(ccp(0,0));
        nick_name->setPosition(ccp(270 - size.width * 0.5f, 20));
        cell->addChild(nick_name, 1);
        
        CCLabelTTF* duration = CCLabelTTF::create(info.m_state.c_str(), "STXingkai.ttf", 29);
        duration->setColor(ccc3(255, 255, 255));
        //duration->setAnchorPoint(ccp(0,0));
        duration->setPosition(ccp(800 - size.width * 0.5f, 40));
        cell->addChild(duration, 1);
        
    }
}
bool TeamList::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(101);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, 930, 320);
    
    bool isTouchIn = rt.containsPoint(pt);
    if(isTouchIn)
        return false;
    else
        return true;
    //return true;
}
void TeamList::Xuanze(CCObject* pSender)
{
    Button* btn = (Button*)pSender;
    if(btn->getPressIconShow())
    {
        btn->setPressIconShow(true);
    }
    else
    {
        btn->setPressIconShow(false);
    }
}
CCSize TeamList::cellSizeForTable(cocos2d::extension::CCTableView *table)
{
    CCSize tableSize = getTableSize();
    return CCSizeMake(tableSize.width, 75);
}

unsigned int TeamList::numberOfCellsInTableView(cocos2d::extension::CCTableView *table)
{
    return (int)m_atts.size();
}

void TeamList::scrollViewDidScroll(cocos2d::extension::CCScrollView *view)
{
    
}

void TeamList::scrollViewDidZoom(cocos2d::extension::CCScrollView *view)
{
    
}


