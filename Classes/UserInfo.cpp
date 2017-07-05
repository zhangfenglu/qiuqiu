//
//  PersonCenterLayer.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/4/1.
//
//

#include "UserInfo.h"
//#include "InputLabel.h"
#include "MainScene.h"
#include "RichLabel.h"
#include "CEditBox.h"
#include "ExchangeInfo.h"

#include "msg_client.pb.h"
#include "struct.pb.h"
#include "msg_error.pb.h"
#include "Resources.h"
#include "GraySprite.h"
#include "CurCularNode.h"

//////////////////////////////////////////////////////
// base
//////////////////////////////////////////////////////
UserInfo::UserInfo()
{
    fanses.clear();
}

UserInfo::~UserInfo()
{
    
}

bool UserInfo::init()
{
    if(!CCLayer::init())
        return false;
    setTouchEnabled(true);
    initUI();
    
    return true;
}

void UserInfo::initUI()
{
    CCSprite* back = CCSprite::create("center_back.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.6f);
    addChild(back);
    
    Button* backBtn = Button::createBtnWithSpriteFrameName("back_btn.png", false);
    backBtn->setPosition(ccp(winSize.width - 50, 30));
    backBtn->setScale(0.3f);
    backBtn->setOnClickCallback(callfuncO_selector(UserInfo::BackClick), this);
    addChild(backBtn, 1);
    
    Button* shouye = Button::createBtnWithSpriteFrameName("shouye-01.png", false);
    shouye->setPosition(ccp(50, winSize.height - 70));
    shouye->setScale(0.6f);
    shouye->setOnClickCallback(callfuncO_selector(UserInfo::ShouyeClick), this);
    shouye->setPressIcon("shouye-02.png", false);
    shouye->setPressIconShow(true);
    addChild(shouye, 1,TAG_SHOUYE_BTN);
    
    Button* zhaopian = Button::createBtnWithSpriteFrameName("zhaopian-01.png", false);
    zhaopian->setPosition(ccp(50, winSize.height - 190));
    zhaopian->setScale(0.6f);
    zhaopian->setOnClickCallback(callfuncO_selector(UserInfo::ZhaopianClick), this);
    zhaopian->setPressIcon("zhaopian-02.png", false);
    zhaopian->setPressIconShow(false);
    addChild(zhaopian, 1,TAG_ZHAOPIAN_BTN);
    
    Button* youxi = Button::createBtnWithSpriteFrameName("youxi-01.png", false);
    youxi->setPosition(ccp(50, winSize.height - 310));
    youxi->setScale(0.6f);
    youxi->setOnClickCallback(callfuncO_selector(UserInfo::YouxiClick), this);
    youxi->setPressIcon("youxi-02.png", false);
    youxi->setPressIconShow(false);
    addChild(youxi, 1,TAG_YOUXI_BTN);
    
    Button* zhandui = Button::createBtnWithSpriteFrameName("zhandui-01.png", false);
    zhandui->setPosition(ccp(50, winSize.height - 430));
    zhandui->setScale(0.6f);
    zhandui->setOnClickCallback(callfuncO_selector(UserInfo::ZhanduiClick), this);
    zhandui->setPressIcon("zhandui-02.png", false);
    zhandui->setPressIconShow(false);
    addChild(zhandui, 1,TAG_ZHANDUI_BTN);
    
    Button* liuyan = Button::createBtnWithSpriteFrameName("liuyan-01.png", false);
    liuyan->setPosition(ccp(50, winSize.height - 550));
    liuyan->setScale(0.6f);
    liuyan->setOnClickCallback(callfuncO_selector(UserInfo::LiuyanClick), this);
    liuyan->setPressIcon("liuyan-02.png", false);
    liuyan->setPressIconShow(false);
    addChild(liuyan, 1,TAG_LIUYAN_BTN);

    
    m_currentTag = TAG_NONE;
    
    ShouyeClick(shouye);
}

void UserInfo::resetBtnState()
{
    ((Button*)getChildByTag(TAG_SHOUYE_BTN))->setPressIconShow(false);
    ((Button*)getChildByTag(TAG_ZHAOPIAN_BTN))->setPressIconShow(false);
    ((Button*)getChildByTag(TAG_YOUXI_BTN))->setPressIconShow(false);
    ((Button*)getChildByTag(TAG_ZHANDUI_BTN))->setPressIconShow(false);
    ((Button*)getChildByTag(TAG_LIUYAN_BTN))->setPressIconShow(false);
    
    removeChildByTag(m_currentTag);
}

void UserInfo::ShouyeClick(cocos2d::CCObject *pSender)
{
    if(TAG_SHOUYE == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_SHOUYE;
    Button* shouye = (Button*)pSender;
    shouye->setPressIconShow(true);
    
    FirstPage* xinxi = FirstPage::create();
    //xinxi->setPosition(ccp(50, 0));
    addChild(xinxi, 10, TAG_SHOUYE);
   
}

void UserInfo::ZhaopianClick(cocos2d::CCObject *pSender)
{
    if(TAG_ZHAOPIAN == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_ZHAOPIAN;
    Button* zhaopian = (Button*)pSender;
    zhaopian->setPressIconShow(true);
    
    ZhaoPian* xinxi = ZhaoPian::create();
    //xinxi->setPosition(ccp(50, 0));
    addChild(xinxi, 10, TAG_ZHAOPIAN);
}

void UserInfo::YouxiClick(cocos2d::CCObject *pSender)
{
    if(TAG_YOUXI == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_YOUXI;
    Button* youxi = (Button*)pSender;
    youxi->setPressIconShow(true);
    
    GameInfo* xinxi = GameInfo::create();
    //xinxi->setPosition(ccp(50, 0));
    addChild(xinxi, 10, TAG_YOUXI);
}

void UserInfo::ZhanduiClick(cocos2d::CCObject *pSender)
{
    if(TAG_ZHANDUI == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_ZHANDUI;
    Button* zhandui = (Button*)pSender;
    zhandui->setPressIconShow(true);
    
    ZhanDui* xinxi = ZhanDui::create();
    //xinxi->setPosition(ccp(50, 0));
    addChild(xinxi, 10, TAG_ZHANDUI);
}

void UserInfo::LiuyanClick(cocos2d::CCObject *pSender)
{
    if(TAG_LIUYAN == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_LIUYAN;
    Button* liuyan = (Button*)pSender;
    liuyan->setPressIconShow(true);
    
    LiuYan* xinxi = LiuYan::create();
    //xinxi->setPosition(ccp(50, 0));
    addChild(xinxi, 10, TAG_LIUYAN);
}

void UserInfo::BackClick(cocos2d::CCObject *pSender)
{
    MainScene* main = dynamic_cast<MainScene*>(getParent());
    main->BackToLoginLayer(MainScene::TAG_LAYER_USERINFO);
}

void UserInfo::setHeadIcon()
{
    FirstPage* layer = (FirstPage*)getChildByTag(TAG_SHOUYE);
    if (layer) {
        layer->setHeadIcon();
    }
    
    GameInfo* game = (GameInfo*)getChildByTag(TAG_YOUXI);
    if (game) {
        game->setHeadIcon();
    }
}
void UserInfo::ShowXihuan(bool isShow)
{
    removeChildByTag(m_currentTag);
    if(isShow)
    {
        m_currentTag = TAG_XIHUAN;
    
        XiHuan* xinxi = XiHuan::create();
        //xinxi->setPosition(ccp(50, 0));
        addChild(xinxi, 10, TAG_XIHUAN);
        
        xinxi->InitInfo(fanses);
    }else{
        m_currentTag = TAG_SHOUYE;
        
        FirstPage* xinxi = FirstPage::create();
        //xinxi->setPosition(ccp(50, 0));
        addChild(xinxi, 10, TAG_SHOUYE);
    }
}

void UserInfo::ShowGame(int idex)
{
    removeChildByTag(m_currentTag);
    
    switch (idex) {
        case 1:
            {
                m_currentTag = TAG_YOUXI;
                
                GameInfo* xinxi = GameInfo::create();
                //xinxi->setPosition(ccp(50, 0));
                addChild(xinxi, 10, TAG_YOUXI);
            }
            break;
        case 2:
            {
                m_currentTag = TAG_GERENRONGYU;
                
                GerenRongYu* xinxi = GerenRongYu::create();
                //xinxi->setPosition(ccp(50, 0));
                addChild(xinxi, 10, TAG_GERENRONGYU);
            }
            break;
        case 3:
            {
                m_currentTag = TAG_BISAIJILU;
                
                BisaiJilu* xinxi = BisaiJilu::create();
                //xinxi->setPosition(ccp(50, 0));
                addChild(xinxi, 10, TAG_BISAIJILU);
            }
            break;
    }
}
void UserInfo::respFans(const WebSocket::Data& data)
{
    fanses.clear();
    if(data.len <= 2)
    {
        FirstPage* layer = (FirstPage*)getChildByTag(TAG_SHOUYE);
        if (layer) {
            layer->InitFensi(fanses);
        }
    }
    else
    {
        UM_Fans resp;
        bool re = resp.ParseFromArray(data.bytes + 2, data.len - 2);
        if(re)
        {
            //std::vector<rank_info> items;
            //std::vector<TestAtt> fanses;
            int num = resp.list_size();
            //CCLog("list number is:%d", num);
            for( int i = 0; i < num; i++)
            {
                TestAtt  rank;
                fans_info item = resp.list(i);
                //CCLog("shop item id is:%d", item.roleid());
                //items.push_back(item);
                rank.m_id = item.roleid();
                rank.m_sex = item.sex();
                rank.m_name = item.name();
                rank.m_icon = item.icon();
                
                rank.m_dest = Global::getInstance()->getString("2");
                rank.m_state = Global::getInstance()->getString("3");
                rank.m_times = Global::getInstance()->getString("4");
                fanses.push_back(rank);
            }
            
            FirstPage* layer = (FirstPage*)getChildByTag(TAG_SHOUYE);
            if (layer) {
                layer->InitFensi(fanses);
            }
        }
    }
}
void UserInfo::respHotLiuyan(const WebSocket::Data& data)
{
    for(int i = 0; i < data.len; ++i)
    {
//        printf("%d,", data.bytes[i]);
    }
    UM_TopMsg resp;
    bool re = resp.ParseFromArray(data.bytes + 2, data.len - 2);
    if(re)
    {
        std::vector<LiuyanInfo> HotLiuyan;
        int num = resp.list_size();
        //CCLog("hot msg list number is:%d", num);
        for( int i = 0; i < num; i++)
        {
            LiuyanInfo  rank;
            msg_info item = resp.list(i);
            
            rank.m_icon = item.icon();
            rank.likeCount = item.likecnt();
            rank.m_name = item.name();
            rank.m_neirong = item.content();
            rank.liuyanID = item.id();
            rank.roleid = item.roleid();
            rank.isLike = 0;
            HotLiuyan.push_back(rank);
        }
        
        LiuYan* layer = (LiuYan*)getChildByTag(TAG_LIUYAN);
        if (layer) {
            layer->InitHotLiuyan(HotLiuyan);
        }
    }
}
void UserInfo::respLiuyan(const WebSocket::Data& data)
{
    for (int i = 0; i < data.len; i++) {
//        printf("%d,", data.bytes[i]);
    }
    UM_MsgList resp;
    bool re = resp.ParseFromArray(data.bytes + 2, data.len - 2);
    if(re)
    {
        std::vector<LiuyanInfo> HotLiuyan;
        int num = resp.list_size();
        //CCLog("msg list number is:%d", num);
        for( int i = 0; i < num; i++)
        {
            LiuyanInfo  rank;
            msg_info item = resp.list(i);
            
            rank.m_icon = item.icon();
            rank.likeCount = item.likecnt();
            rank.m_name = item.name();
            rank.m_neirong = item.content();
            rank.liuyanID = item.id();
            rank.roleid = item.roleid();
            rank.isLike = 0;
            HotLiuyan.push_back(rank);
        }
        
        LiuYan* layer = (LiuYan*)getChildByTag(TAG_LIUYAN);
        if (layer) {
            layer->InitLiuyan(HotLiuyan);
        }
    }
}

void UserInfo::resSeasonRank(const WebSocket::Data& data)
{
    UM_SeasonRank resp;
    bool re = resp.ParseFromArray(data.bytes + 2, data.len - 2);
    if(re)
    {
        std::vector<season_rank> HotLiuyan;
        int num = resp.list_size();
        //CCLog("msg list number is:%d", num);
        for( int i = 0; i < num; i++)
        {
            season_rank info = resp.list(i);
            if (i<3) {
                HotLiuyan.push_back(info);
            }
        }
        
        GerenRongYu* layer = (GerenRongYu*)getChildByTag(TAG_GERENRONGYU);
        if (layer) {
            layer->InitRongyu(HotLiuyan);
        }
    }
}
void UserInfo::resGameRecode(const WebSocket::Data& data)
{
    UM_GameRecord resp;
    bool re = resp.ParseFromArray(data.bytes + 2, data.len - 2);
    if(re)
    {
        std::vector<bisaiInfo> HotLiuyan;
        int num = resp.list_size();
        //CCLog("msg list number is:%d", num);
        for( int i = 0; i < num; i++)
        {
            char tem[64] = {0};
            game_record info = resp.list(i);
            bisaiInfo bisi;
            
            bisi.m_id = info.roleid();
            bisi.m_Icon = info.icon();
            bisi.m_nickName = info.nickname();
            if (bisi.m_nickName == "") {
                sprintf(tem, "S%d",info.roleid());
                bisi.m_nickName = tem;
            }
            
            struct timeval tv;
            gettimeofday(&tv, NULL);
            
            int gameTime = info.time();
            //CCLOG("name:%s",bisi.m_nickName.c_str());
            //CCLOG("now: game:%d",gameTime);
            long mSec = gameTime/1000;
            long mut = mSec/60;
            long hour = mut/60;
            long day = hour/24;
            long mon = day/30;
            if (mon) {
                sprintf(tem, Global::getInstance()->getString("5"),mon);
            }else if(day){
                sprintf(tem, Global::getInstance()->getString("6"),day);
            }else if(hour){
                sprintf(tem, Global::getInstance()->getString("7"),hour);
            }else if(mut){
                sprintf(tem, Global::getInstance()->getString("8"),mut);
            }else if(mSec){
                sprintf(tem, Global::getInstance()->getString("9"),mSec);
            }
            
            //sprintf(tem, "%d天前",info.time());
            bisi.m_lastTime = tem;
            sprintf(tem, "%d",info.rank());
            bisi.m_rank = tem;
            
            //char temp[64];
            
            unsigned long long eMass = 0.000173415299158326*(pow(info.mass(), 5))-7.34152991583261;
            
            if (eMass < 10000) {
                sprintf(tem, Global::getInstance()->getString("10"), eMass);
            }else if(eMass < 1000000)
            {
                unsigned long long tMa = eMass/100;
                sprintf(tem, Global::getInstance()->getString("11"), tMa);
            }else if(eMass < 1000000000)
            {
                unsigned long long tMa = eMass/100000;
                sprintf(tem, Global::getInstance()->getString("12"), tMa);
            }else if(eMass < 1000000000000)
            {
                unsigned long long tMa = eMass/100000000;
                sprintf(tem, Global::getInstance()->getString("13"), tMa);
            }else if(eMass < 1000000000000000)
            {
                unsigned long long tMa = eMass/100000000000;
                sprintf(tem, Global::getInstance()->getString("14"), tMa);
            }else if(eMass < 1000000000000000000)
            {
                unsigned long long tMa = eMass/100000000000000;
                sprintf(tem, Global::getInstance()->getString("15"), tMa);
            }else{
                unsigned long long tMa = eMass/100000000000000000;
                sprintf(tem, Global::getInstance()->getString("16"), tMa);
            }
            //sprintf(tem, "%d克",info.mass());
            bisi.m_weight = tem;
            sprintf(tem, "%d",info.eat());
            bisi.m_number = tem;
            
            int mit = info.live()/60;
            int sec = info.live()%60;
            if (mit) {
                sprintf(tem, Global::getInstance()->getString("17"),mit,sec);
            }else{
                sprintf(tem, Global::getInstance()->getString("18"),sec);
            }
            //sprintf(tem, "%d秒",info.live());
            bisi.m_duration = tem;
            sprintf(tem, "%d",info.copper());
            bisi.m_copper = tem;
            
            HotLiuyan.push_back(bisi);
        }
        
        BisaiJilu* layer = (BisaiJilu*)getChildByTag(TAG_BISAIJILU);
        if (layer) {
            layer->InitBisai(HotLiuyan);
        }
    }
}

void UserInfo::resHeadImg(int count)
{
    FirstPage* layer = (FirstPage*)getChildByTag(TAG_SHOUYE);
    if(layer)
        layer->resHeadImg(count);
    
    GameInfo* game = (GameInfo*)getChildByTag(TAG_YOUXI);
    if (game) {
        game->resHeadImg(count);
    }
}

void UserInfo::resPhoto(std::vector<std::string> arr)
{
    ZhaoPian* layer = (ZhaoPian*)getChildByTag(TAG_ZHAOPIAN);
    if(layer)
    {
        layer->InitTabelView(arr);
    }
}

////////////////////////////////////////////////////////////////////
// 首页
////////////////////////////////////////////////////////////////////
FirstPage::FirstPage()
{
    
}

FirstPage::~FirstPage()
{
    
}

bool FirstPage::init()
{
    if(!CCLayer::init())
        return false;
    
    user_info info = Global::getInstance()->GetPlayerInfo();
    
    CCSprite* back = CCSprite::create("beijingdikuang-01.png");
    back->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+100));
    back->setScale(0.57f);
    addChild(back);
    
    Button* headbg = NULL;
    user_info user = Global::getInstance()->GetUserInfo();
    std::map<int, int> equip = user.mEquip;
    std::map<int,int>::iterator iter;
    iter = equip.find(6);
    if (iter!=equip.begin()) {
        if(iter->second)
        {
            item ite = Resource::sharedResource()->getItemForID(iter->second);
            headbg = Button::createBtnWithSpriteFrameName(ite.itemIcon.c_str(), false);
            headbg->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+180));
            headbg->setScale(0.7f);
            headbg->setOnClickCallback(callfuncO_selector(FirstPage::HeadClick), this);
            headbg->setPressIcon(ite.itemIcon.c_str(), false);
            addChild(headbg, 2,TAG_TOUXIANGBTN);
        }else{
            headbg = Button::createBtnWithSpriteFrameName("touxiang002.png", false);
            headbg->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+180));
            headbg->setScale(0.7f);
            headbg->setOnClickCallback(callfuncO_selector(FirstPage::HeadClick), this);
            headbg->setPressIcon("touxiang002.png", false);
            addChild(headbg, 2,TAG_TOUXIANGBTN);
        }
    }else{
        headbg = Button::createBtnWithSpriteFrameName("touxiang002.png", false);
        headbg->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+180));
        headbg->setScale(0.7f);
        headbg->setOnClickCallback(callfuncO_selector(FirstPage::HeadClick), this);
        headbg->setPressIcon("touxiang002.png", false);
        addChild(headbg, 2,TAG_TOUXIANGBTN);
    }
    
    
    user_info myInfo = Global::getInstance()->GetUserInfo();
    user_info pInfo = Global::getInstance()->GetPlayerInfo();
    if (myInfo.roleID != pInfo.roleID)
    {
        headbg->setIsCanTouch(false);
    }
    
    std::string path;
    if (info.icon>100) {
        char temp[32];
        sprintf(temp, "hero_%d.png", info.icon);
        path = temp;
    }else{
        char spName[64] = {0};
        sprintf(spName, "headImage%d.jpg",info.icon);
        
        path = Global::getInstance()->getDataPath(spName);
    }
    
    CCSprite* head = CCSprite::create(path.c_str());
    CirCularNode* headCir = CirCularNode::create(90, head);
    head->setScale(0.7f);
    headCir->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+180));
    addChild(headCir, 2,TAG_HEADICON);
    
    CCLabelTTF* useName = CCLabelTTF::create(info.roleName.c_str(), "STXingkai.ttf", 45);
    useName->setColor(ccc3(0, 0, 0));
    useName->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+30));
    addChild(useName, 2);
    
    std::map<int, std::string> hInfo = ExchangeInfo::getProvinces();
    
    Button* diqubtn = Button::createBtnWithSpriteFrameName("input.png", false);
    diqubtn->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-20));
    diqubtn->setScaleX(0.5f);
    diqubtn->setOnClickCallback(callfuncO_selector(FirstPage::DiquClick), this);
    addChild(diqubtn, 2,TAG_DIQUBTN);
    
    useName = CCLabelTTF::create(hInfo[info.province].c_str(), "STXingkai.ttf", 35);
    //useName = CCLabelTTF::create("中国", "STXingkai.ttf", 30);
    useName->setColor(ccc3(0, 0, 0));
    useName->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-20));
    addChild(useName, 2);
    
    CCLabelTTF* neirong = CCLabelTTF::create(Global::getInstance()->getString("19"), "STXingkai.ttf", 30);
    neirong->setColor(ccc3(0, 0, 0));
    neirong->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-70));
    addChild(neirong, 2);
    
    Button* luyin = Button::createBtnWithSpriteFrameName("shouye-luyin001.png", false);
    luyin->setPosition(ccp(winSize.width * 0.5f-400, winSize.height * 0.5f+250));
    luyin->setScale(0.5f);
    luyin->setOnClickCallback(callfuncO_selector(FirstPage::LuyinClick), this);
    addChild(luyin, 2,TAG_LUYINBTN);
    
    CCSprite* luyints = CCSprite::create("shouye-luyin002.png");
    luyints->setScale(0.5f);
    luyints->setPosition(ccp(winSize.width * 0.5f-380, winSize.height * 0.5f+275));
    addChild(luyints, 2);
    
    scheduleOnce(schedule_selector(FirstPage::SenMSG), 0.01f);

    return true;
}

void FirstPage::SenMSG(float ft)
{
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqFans(2, 0, 20,usef.roleID);
}
void FirstPage::setHeadIcon()
{
    removeChildByTag(TAG_HEADICON, true);
    user_info info = Global::getInstance()->GetPlayerInfo();
    std::string path;
    if (info.icon>100) {
        char temp[32];
        sprintf(temp, "hero_%d.png", info.icon);
        path = temp;
    }else{
        char spName[64] = {0};
        sprintf(spName, "headImage%d.jpg",info.icon);
        
        path = Global::getInstance()->getDataPath(spName);
    }
    
    CCSprite* head = CCSprite::create(path.c_str());
    CirCularNode* headCir = CirCularNode::create(90, head);
    head->setScale(0.7f);
    headCir->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+180));
    addChild(headCir, 2,TAG_HEADICON);
    
    ((HeadIconChose*)getChildByTag(TAG_HEADCHOSE))->reshHead();
}
void FirstPage::InitFensi(std::vector<TestAtt> info)
{
    std::string glab[2] = {Global::getInstance()->getString("20"),Global::getInstance()->getString("21")};
    
    char tem[32] = {0};
    sprintf(tem, "%d",(int)info.size());
    
    for(int i=0;i<2;i++)
    {
        CCSprite* guanzhbg = CCSprite::create("hengtiaodikuang-01.png");
        guanzhbg->setScale(0.59f);
        guanzhbg->setPosition(ccp(winSize.width * 0.5f-215+i*510, winSize.height * 0.5f-140));
        addChild(guanzhbg, 2);
        
        CCLabelTTF* mcount = CCLabelTTF::create(tem, "STXingkai.ttf", 45);
        mcount->setColor(ccc3(0, 0, 0));
        mcount->setPosition(ccp(guanzhbg->getContentSize().width/2,guanzhbg->getContentSize().height-40));
        guanzhbg->addChild(mcount, 2);
        
        CCLabelTTF* lab = CCLabelTTF::create(glab[i].c_str(), "STXingkai.ttf", 45);
        lab->setColor(ccc3(0, 0, 0));
        lab->setPosition(ccp(guanzhbg->getContentSize().width/2,40));
        guanzhbg->addChild(lab, 2);
    }
    
    
    Button* xihuanbg = Button::createBtnWithSpriteFrameName("hengtiaozhuangtiai-02.png", false);
    xihuanbg->setPosition(ccp(winSize.width * 0.5f+40, winSize.height * 0.5f-220));
    xihuanbg->setScale(0.59f);
    xihuanbg->setOnClickCallback(callfuncO_selector(FirstPage::XihuanClick), this);
    addChild(xihuanbg, 2,TAG_XIHUANBTN);
    
    CCSprite* shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-760, 0));
    xihuanbg->addChild(shangfen, 2);
    
    CCLabelTTF* xihuanlab = CCLabelTTF::create(Global::getInstance()->getString("21"), "STXingkai.ttf",50);
    xihuanlab->setColor(ccc3(0, 0, 0));
    xihuanlab->setPosition(ccp(-660,0));
    xihuanbg->addChild(xihuanlab, 2);
    
    CCSprite* hongxin = CCSprite::create("hongxin-01.png");
    //shangfen->setScale(0.5f);
    hongxin->setPosition(ccp(780, 10));
    xihuanbg->addChild(hongxin, 2);
    
    CCLabelTTF* hongxinnum = CCLabelTTF::create(tem, "STXingkai.ttf",50);
    hongxinnum->setColor(ccc3(0, 0, 0));
    hongxinnum->setPosition(ccp(780,-40));
    xihuanbg->addChild(hongxinnum, 2);
    
    int maxCount = info.size()>8?8:(int)info.size();
    for (int i = 0; i<maxCount; i++) {
        
        hongxin = CCSprite::create("touxiang002.png");
        hongxin->setScale(0.4f);
        hongxin->setPosition(ccp(650 - i*150, 0));
        xihuanbg->addChild(hongxin, 2);
        /*
        char temp[32];
        sprintf(temp, "hero_%d.png", info[i].m_icon);

        hongxin = CCSprite::create(temp);
        hongxin->setScale(0.5f);
        hongxin->setPosition(ccp(650 - i*150, 0));
        xihuanbg->addChild(hongxin, 2);
        */
        char temp1[32];
        CCSprite* icon;
        CirCularNode* iconCir;
        if(info[i].m_icon < 101)
        {
            CCTexture2D* tex = ExchangeInfo::GetTextureForData(info[i].m_iconStr.c_str());
            icon = CCSprite::createWithTexture(tex);
            icon->setScale(0.4f);
            iconCir = CirCularNode::create(50, icon);
        }
        else
        {
            sprintf(temp1, "hero_%d.png", info[i].m_icon);
            icon = CCSprite::create(temp1);
            icon->setScale(0.4f);
            iconCir = CirCularNode::create(50, icon);
        }
        
        iconCir->setPosition(ccp(650 - i*150, 0));
        xihuanbg->addChild(iconCir, 1);
    }
}
void FirstPage::SetBtnToTouch()
{
    Button* butn1 = (Button*)getChildByTag(TAG_DIQUBTN);
    butn1->setIsCanTouch(true);
    Button* butn2 = (Button*)getChildByTag(TAG_TOUXIANGBTN);
    butn2->setIsCanTouch(true);
    Button* butn3 = (Button*)getChildByTag(TAG_LUYINBTN);
    butn3->setIsCanTouch(true);
    Button* butn4 = (Button*)getChildByTag(TAG_XIHUANBTN);
    butn4->setIsCanTouch(true);
}
void FirstPage::DiquClick(cocos2d::CCObject *pSender)
{
    Button* butn1 = (Button*)getChildByTag(TAG_DIQUBTN);
    butn1->setIsCanTouch(false);
    Button* butn2 = (Button*)getChildByTag(TAG_TOUXIANGBTN);
    butn2->setIsCanTouch(false);
    Button* butn3 = (Button*)getChildByTag(TAG_LUYINBTN);
    butn3->setIsCanTouch(false);
    Button* butn4 = (Button*)getChildByTag(TAG_XIHUANBTN);
    butn4->setIsCanTouch(false);
    XuanzeDiqu* diqulayer = XuanzeDiqu::create();
    addChild(diqulayer,100);
}
void FirstPage::ChangeHead(cocos2d::CCObject *pSender)
{
    HeadIconChose* head = (HeadIconChose*)getChildByTag(TAG_HEADCHOSE);
    if(head)
        head->reshHead();
}

void FirstPage::HeadClick(cocos2d::CCObject *pSender)   //头像
{
    user_info myInfo = Global::getInstance()->GetUserInfo();
    user_info pInfo = Global::getInstance()->GetPlayerInfo();
    if (myInfo.roleID == pInfo.roleID) {
        Button* butn1 = (Button*)getChildByTag(TAG_DIQUBTN);
        butn1->setIsCanTouch(false);
        Button* butn2 = (Button*)getChildByTag(TAG_TOUXIANGBTN);
        butn2->setIsCanTouch(false);
        Button* butn3 = (Button*)getChildByTag(TAG_LUYINBTN);
        butn3->setIsCanTouch(false);
        Button* butn4 = (Button*)getChildByTag(TAG_XIHUANBTN);
        butn4->setIsCanTouch(false);
        
        HeadIconChose* layer = HeadIconChose::create();
        addChild(layer,20,TAG_HEADCHOSE);
        layer->SetParentTag(1);
    }
}
void FirstPage::resHeadImg(int count)
{
    HeadIconChose* layer = (HeadIconChose*)getChildByTag(TAG_HEADCHOSE);
    if(layer)
        layer->resHeadImg(count);
}
void FirstPage::LuyinClick(cocos2d::CCObject *pSender)   //录音
{
    
}
void FirstPage::XihuanClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowXihuan(true);
}


////////////////////////////////////////////////////////////////
/// 修改头环
////////////////////////////////////////////////////////////////
HeadIconChose::HeadIconChose()
{
    mParent = 0;
}
HeadIconChose::~HeadIconChose()
{
    
}

bool HeadIconChose::init()
{
    if(!CPZLayer::init())
        return false;
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 80));
    addChild(layer);
    
    CCSprite* back = CCSprite::create("dimianbeijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.6f);
    addChild(back);
    
    back = CCSprite::create("dikuangbeijing-02.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.9f);
    addChild(back,0,101);
    
    
    Button* backBtn = Button::createBtnWithSpriteFrameName("fangjianshezhi-guanbi-01.png", false);
    backBtn->setPosition(ccp(winSize.width - 90, winSize.height - 70));
    backBtn->setScale(0.6f);
    backBtn->setOnClickCallback(callfuncO_selector(HeadIconChose::Back), this);
    addChild(backBtn, 1);
    
    Button* zhaopy = Button::createBtnWithSpriteFrameName("wodetouxiang-01.png", false);
    zhaopy->setPosition(ccp(180, winSize.height - 70));
    zhaopy->setScale(0.6f);
    zhaopy->setOnClickCallback(callfuncO_selector(HeadIconChose::YouxiShezhi), this);
    zhaopy->setPressIcon("wodetouxiagn-02.png", false);
    zhaopy->setPressIconShow(true);
    addChild(zhaopy, 1,TAG_FindFriend);
    
    Button* yonghu = Button::createBtnWithSpriteFrameName("rongyutouhuan-01.png", false);
    yonghu->setPosition(ccp(360, winSize.height - 70));
    yonghu->setScale(0.6f);
    yonghu->setOnClickCallback(callfuncO_selector(HeadIconChose::Yonghuxinxi), this);
    yonghu->setPressIcon("rongyutouhuan-02.png", false);
    //zhaopy->setPressIconShow(true);
    addChild(yonghu, 1,TAG_Fujinderen);

    m_currentTag = TAG_NONE;
    
    YouxiShezhi(zhaopy);
    return true;
}
void HeadIconChose::InitShezhiUI()
{
    CCLayer* pyLayer = CCLayer::create();
    addChild(pyLayer,5,TAG_SHEZHI);
    
    NormalHeadIcon* icon = NormalHeadIcon::create();
    pyLayer->addChild(icon,0,2);
    
    PhotoHeadIcon* photo = PhotoHeadIcon::create();
    pyLayer->addChild(photo,0,1);
    
    scheduleOnce(schedule_selector(HeadIconChose::SenMSG), 0.01f);
}
void HeadIconChose::reshHead()
{
    NormalHeadIcon* layer = (NormalHeadIcon*)getChildByTag(TAG_SHEZHI)->getChildByTag(2);
    if(layer)
        layer->rushHead();
    PhotoHeadIcon* layerP = (PhotoHeadIcon*)getChildByTag(TAG_SHEZHI)->getChildByTag(1);
    if(layerP)
        layerP->rushHead();
}
void HeadIconChose::resHeadImg(int count)
{
    PhotoHeadIcon* layer = (PhotoHeadIcon*)getChildByTag(TAG_SHEZHI)->getChildByTag(1);
    layer->InitTabelView(count);
}
void HeadIconChose::SenMSG(float ft)
{
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent()->getParent())->reqGetPhoto(usef.roleID);
}
void HeadIconChose::InitZhuceUI()
{
    CCLayer* pyLayer = CCLayer::create();
    addChild(pyLayer,5,TAG_ZHUCE);
    
    HeadRing* ring = HeadRing::create();
    pyLayer->addChild(ring);
}
void HeadIconChose::Back(CCObject* pSender)
{
    if (mParent == 1) {
        ((FirstPage*)getParent())->SetBtnToTouch();
    }
    
    if (mParent == 2) {
        ((GameInfo*)getParent())->SetBtnToTouch();
    }
    
    getParent()->removeChild(this,true);
}
void HeadIconChose::resetBtnState()
{
    ((Button*)getChildByTag(TAG_Fujinderen))->setPressIconShow(false);
    ((Button*)getChildByTag(TAG_FindFriend))->setPressIconShow(false);
    
    removeChildByTag(m_currentTag);
}
void HeadIconChose::YouxiShezhi(CCObject* pSender)
{
    if(TAG_SHEZHI == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_SHEZHI;
    Button* shouye = (Button*)pSender;
    shouye->setPressIconShow(true);
    
    InitShezhiUI();
}
void HeadIconChose::Yonghuxinxi(CCObject* pSender)
{
    if(TAG_ZHUCE == m_currentTag)
        return;
    
    resetBtnState();
    m_currentTag = TAG_ZHUCE;
    Button* shouye = (Button*)pSender;
    shouye->setPressIconShow(true);
    
    //removeChildByTag(TAG_PYLayer, true);
    InitZhuceUI();
}
bool HeadIconChose::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    CCNode* node = getChildByTag(101);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, 900, 600);
    
    bool isTouchIn = rt.containsPoint(pt);
    if(isTouchIn)
        return false;
    else
        return true;
}
////////////////////////////////
//  普通头像
////////////////////////////////
NormalHeadIcon::NormalHeadIcon()
{
    
}
NormalHeadIcon::~NormalHeadIcon()
{
    
}

bool NormalHeadIcon::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSprite* back = CCSprite::create("jingdianzhaopian-01.png");
    back->setPosition(ccp(winSize.width * 0.5f-390, winSize.height * 0.5f+170));
    back->setScale(0.6f);
    addChild(back);
    
    back = CCSprite::create("zhaopiantouxiang-01.png");
    back->setPosition(ccp(winSize.width * 0.5f-390, winSize.height * 0.5f-20));
    back->setScale(0.6f);
    addChild(back);
    
    CCTableView* tableView = CCTableView::create(this, CCSizeMake(920, 160));
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionHorizontal);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(110,winSize.height * 0.5f));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 50, 101);
    //tableView->reloadData();
    
    return true;
}
void NormalHeadIcon::rushHead()
{
    ((CCTableView*)getChildByTag(101))->reloadData();
}
void NormalHeadIcon::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    MainScene* scene = (MainScene*)getParent()->getParent()->getParent()->getParent()->getParent();
    int idex = cell->getIdx();
    scene->reqSetIcon(101+idex, "");
}
CCTableViewCell* NormalHeadIcon::tableCellAtIndex(CCTableView* table, unsigned int idex)
{
    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    createTableViewCell(cell, table, idex);
    return cell;
}
CCSize NormalHeadIcon::cellSizeForTable(CCTableView* table)
{
    return CCSizeMake(160, 160);
}
unsigned int NormalHeadIcon::numberOfCellsInTableView(CCTableView* table)
{
    return  9;
}
void NormalHeadIcon::createTableViewCell(CCNode* cell, CCTableView* table, int idex)
{
    char spName[64] = {0};
    int index = idex + 101;
    sprintf(spName, "hero_%d.png",index);
    
    CCSprite* spIcon = CCSprite::create(spName);
    spIcon->setPosition(ccp(80,80));
    spIcon->setScale(0.45f);
    cell->addChild(spIcon);
    
    user_info info = Global::getInstance()->GetUserInfo();
    int iconIdex = info.icon%101;
    if (iconIdex == idex && info.icon > 100) {
        spIcon = CCSprite::create("head_bg_02.png");
        spIcon->setPosition(ccp(80,80));
        spIcon->setScale(0.48f);
        cell->addChild(spIcon);
    }else{
        spIcon = CCSprite::create("head_bg_01.png");
        spIcon->setPosition(ccp(80,80));
        spIcon->setScale(0.48f);
        cell->addChild(spIcon);
    }
}


////////////////////////////////
//  照片头像
////////////////////////////////
PhotoHeadIcon::PhotoHeadIcon()
{
    mPhotoNum = 0;
}
PhotoHeadIcon::~PhotoHeadIcon()
{
    
}

bool PhotoHeadIcon::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    

    
    //tableView->reloadData();
    
    return true;
}
void PhotoHeadIcon::InitTabelView(int count)
{
    mPhotoNum = count+1;
    if (getChildByTag(101)) {
        CCTableView* tabel = (CCTableView*)getChildByTag(101);
        tabel->reloadData();
    }else{
        CCTableView* tableView = CCTableView::create(this, CCSizeMake(920, 160));
        //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
        tableView->setDirection(kCCScrollViewDirectionHorizontal);
        //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
        tableView->setPosition(ccp(110,winSize.height * 0.5f-190));
        tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
        tableView->setDelegate(this);
        addChild(tableView, 50, 101);
    }
}
void PhotoHeadIcon::rushHead()
{
    ((CCTableView*)getChildByTag(101))->reloadData();
}
void PhotoHeadIcon::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    int idex = cell->getIdx();
    if (idex == mPhotoNum-1) {
        ExchangeInfo::AddPhoto(idex + 1);
    }else{
        ExchangeInfo::UpLoadIcon(idex + 1);
    }
}
CCTableViewCell* PhotoHeadIcon::tableCellAtIndex(CCTableView* table, unsigned int idex)
{
    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    createTableViewCell(cell, table, idex);
    return cell;
}
CCSize PhotoHeadIcon::cellSizeForTable(CCTableView* table)
{
    return CCSizeMake(160, 160);
}
unsigned int PhotoHeadIcon::numberOfCellsInTableView(CCTableView* table)
{
    return  mPhotoNum;
}
void PhotoHeadIcon::createTableViewCell(CCNode* cell, CCTableView* table, int idex)
{
    if(idex == mPhotoNum - 1)
    {
        CCSprite* hongxin = CCSprite::create("tianjiazhaopian-01.png");
        hongxin->setScale(0.5f);
        hongxin->setPosition(ccp(80, 80));
        cell->addChild(hongxin, 2);
    }else{
        char spName[64] = {0};
        sprintf(spName, "headImage%d.jpg",idex+1);
        
        std::string path = Global::getInstance()->getDataPath(spName);
        
        //CCLOG("photo:%s",path.c_str());
        CCSprite* spIcon = CCSprite::create(path.c_str());
        spIcon->setPosition(ccp(80,80));
        spIcon->setScale(0.43f);
        cell->addChild(spIcon);
        
        user_info info = Global::getInstance()->GetUserInfo();
        if (info.icon == idex+1) {
            spIcon = CCSprite::create("head_bg_02.png");
            spIcon->setPosition(ccp(80,80));
            spIcon->setScale(0.48f);
            cell->addChild(spIcon);
        }else{
            spIcon = CCSprite::create("head_bg_01.png");
            spIcon->setPosition(ccp(80,80));
            spIcon->setScale(0.48f);
            cell->addChild(spIcon);
        }
    }
}

////////////////////////////////
//  荣誉头环
////////////////////////////////
HeadRing::HeadRing()
{
    
}
HeadRing::~HeadRing()
{
    
}

bool HeadRing::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    
    CCTableView* tableView = CCTableView::create(this, CCSizeMake(920, 350));
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionHorizontal);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(110,winSize.height * 0.5f-180));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 50, 101);
    //tableView->reloadData();
    
    return true;
}

void HeadRing::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    int idex = cell->getIdx();
    item ite = Resource::sharedResource()->getItemForID(idex + 601);
    HeadRingInfo* layer = HeadRingInfo::create();
    addChild(layer, 100);
    layer->InitItemInfo(ite);
}
CCTableViewCell* HeadRing::tableCellAtIndex(CCTableView* table, unsigned int idex)
{
    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    createTableViewCell(cell, table, idex);
    return cell;
}
CCSize HeadRing::cellSizeForTable(CCTableView* table)
{
    return CCSizeMake(300, 350);
}
unsigned int HeadRing::numberOfCellsInTableView(CCTableView* table)
{
    return  12;
}
void HeadRing::createTableViewCell(CCNode* cell, CCTableView* table, int idex)
{
    CCSprite* cellBG = CCSprite::create("touhuandikuang-01.png");
    cellBG->setPosition(ccp(150,175));
    cellBG->setScale(0.6f);
    cell->addChild(cellBG);
    
    char spName[64] = {0};
    sprintf(spName, "%d.png",601+idex);
    
    user_bag bag = Global::getInstance()->GetBagItem(idex + 601);
    if (bag.count) {
        CCSprite* sptxture = CCSprite::create(spName);
        sptxture->setPosition(ccp(150,200));
        sptxture->setScale(0.6f);
        cell->addChild(sptxture);
    }else{
        GraySprite* sptxture = GraySprite::create(spName);
        sptxture->setPosition(ccp(150,200));
        sptxture->setScale(0.6f);
        cell->addChild(sptxture);
    }
    
    item ite = Resource::sharedResource()->getItemForID(idex + 601);
    
    CCLabelTTF* useName = CCLabelTTF::create(ite.itemName.c_str(), "STXingkai.ttf", 30);
    useName->setColor(ccc3(0, 0, 0));
    useName->setPosition(ccp(150, 70));
    cell->addChild(useName, 2);
}
/////////////////
HeadRingInfo::HeadRingInfo()
{
    
}
HeadRingInfo::~HeadRingInfo()
{
    
}

bool HeadRingInfo::init()
{
    if(!CPZLayer::init())
        return false;
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 80));
    addChild(layer);
    
    CCSprite* back = CCSprite::create("dimianbeijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.45f);
    addChild(back,0,101);
    
    
    
    return true;
}
void HeadRingInfo::InitItemInfo(item itemInfo)
{
    mCurItem = itemInfo;
    char spName[64] = {0};
    sprintf(spName, "%d.png",mCurItem.itemID);
    
    CCSprite* sptxture = CCSprite::create(spName);
    sptxture->setPosition(ccp(winSize.width/2-200,winSize.height/2+50));
    sptxture->setScale(0.6f);
    addChild(sptxture);
    
    user_bag bagIte = Global::getInstance()->GetBagItem(mCurItem.itemID);
    //CCLog("iteCount:%d",bagIte.count);
    if (bagIte.count) {
        user_info user = Global::getInstance()->GetUserInfo();
        std::map<int, int> equip = user.mEquip;
        std::map<int,int>::iterator iter = equip.begin();
        for (; iter!=equip.end(); iter++) {
            if (iter->first == itemInfo.itemType) {
                break;
            }
        }
        if (iter!=equip.end()) {
            if(iter->second)
            {
                Button* guanhuan = Button::createBtnWithSpriteFrameName("xiexia-01.png", false);
                guanhuan->setPosition(ccp(winSize.width/2-200,winSize.height/2-80));
                guanhuan->setScale(0.6f);
                guanhuan->setOnClickCallback(callfuncO_selector(HeadRingInfo::XiexiaClick), this);
                guanhuan->setPressIcon("xiexia-02.png", false);
                addChild(guanhuan, 1);
            }else{
                Button* guanhuan = Button::createBtnWithSpriteFrameName("zhuangbei_01.png", false);
                guanhuan->setPosition(ccp(winSize.width/2-200,winSize.height/2-80));
                guanhuan->setScale(0.6f);
                guanhuan->setOnClickCallback(callfuncO_selector(HeadRingInfo::UseClick), this);
                guanhuan->setPressIcon("zhuangbei_02.png", false);
                addChild(guanhuan, 1);
            }
        }else{
            Button* guanhuan = Button::createBtnWithSpriteFrameName("zhuangbei_01.png", false);
            guanhuan->setPosition(ccp(winSize.width/2-200,winSize.height/2-80));
            guanhuan->setScale(0.6f);
            guanhuan->setOnClickCallback(callfuncO_selector(HeadRingInfo::UseClick), this);
            guanhuan->setPressIcon("zhuangbei_02.png", false);
            addChild(guanhuan, 1);
        }
    }else{
        CCLabelTTF* useName = CCLabelTTF::create(Global::getInstance()->getString("22"), "STXingkai.ttf", 30);
        useName->setColor(ccc3(0, 0, 0));
        useName->setPosition(ccp(winSize.width/2-200,winSize.height/2-80));
        addChild(useName, 2);
    }

    CCLabelTTF* useName = CCLabelTTF::create(mCurItem.itemName.c_str(), "STXingkai.ttf", 45);
    useName->setColor(ccc3(0, 0, 0));
    useName->setAnchorPoint(ccp(0.0f,0.5f));
    useName->setPosition(ccp(winSize.width/2-30,winSize.height/2+110));
    addChild(useName, 2);
    
    useName = CCLabelTTF::create(Global::getInstance()->getString("23"), "STXingkai.ttf", 30);
    useName->setColor(ccc3(0, 0, 0));
    useName->setAnchorPoint(ccp(0.0f,0.5f));
    useName->setPosition(ccp(winSize.width/2-30,winSize.height/2+60));
    addChild(useName, 2);
    
    std::ostringstream ossAttr;
    //std::string content1 = "头环";
    
    ossAttr<<"<t/><font><fontname>STXingkai</><fontsize>25</><color><value>00000000</>" << mCurItem.itemTips.c_str()<<"</></>";
    //ossAttr<<"<t/><font><fontname>STXingkai</><fontsize>25</><color><value>00000000</>" << content1.c_str()<<"</></>";
    
    
    RichLabel* helpCon = RichLabel::create(ossAttr.str().c_str(), "STXingkai.ttf", 25.0f, CCSizeMake(300, 31),false,false);
    helpCon->setAnchorPoint(CCPointZero);
    //helpCon->setColor(ccBLACK);
    helpCon->setPosition(ccp(winSize.width/2-30,winSize.height/2+20));
    addChild(helpCon, 2);
}

void HeadRingInfo::UseClick(CCObject* pSender)
{
    MainScene* scene = (MainScene*)getParent()->getParent()->getParent()->getParent()->getParent();
    scene->reqUseItem(mCurItem.itemID);
}
void HeadRingInfo::XiexiaClick(CCObject* pSender)
{
    MainScene* scene = (MainScene*)getParent()->getParent()->getParent()->getParent()->getParent();
    scene->reqUnequipItem(mCurItem.itemType);
}
bool HeadRingInfo::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(101);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, node->getContentSize().width*0.45f, node->getContentSize().height*0.45f);
    
    isTouchIn = rt.containsPoint(pt);
    //if(isTouchIn)
        //return false;
    //else
        //return true;
    return true;
}
void HeadRingInfo::ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent)
{
    if(isTouchIn)
        return;
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(101);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, node->getContentSize().width*0.45f, node->getContentSize().height*0.45f);
    if(rt.containsPoint(pt) == false)
    {
        getParent()->removeChild(this);
    }
}
////////////////////////////////////////////////////////////////
/// 选择地区
////////////////////////////////////////////////////////////////
XuanzeDiqu::XuanzeDiqu()
{
    hInfo = ExchangeInfo::getProvinces();
    isTouchIn = false;
}
XuanzeDiqu::~XuanzeDiqu()
{
    
}

bool XuanzeDiqu::init()
{
    if(!CPZLayer::init())
        return false;
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(0, 0, 0, 80));
    addChild(layer);
    
    CCSprite* back = CCSprite::create("chengshibg-2.png");
    back->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
    back->setScale(0.6f);
    addChild(back);
    
    CCLabelTTF* statelb = CCLabelTTF::create(Global::getInstance()->getString("24"), "STXingkai.ttf", 40);
    statelb->setColor(ccc3(0, 0, 0));
    statelb->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f+270));
    addChild(statelb, 2);
    
    //455*667
    
    
    CCTableView* tableView = CCTableView::create(this, getTableSize());
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(winSize.width * 0.5f-275,winSize.height * 0.5f-240));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 50, 101);
    tableView->reloadData();
    
    return true;
}


void XuanzeDiqu::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    int idex = cell->getIdx();
    MainScene* scene = (MainScene*)(getParent()->getParent()->getParent());
    scene->reqSetGeo(1001+idex);
    getParent()->removeChild(this,true);
}
CCTableViewCell* XuanzeDiqu::tableCellAtIndex(CCTableView* table, unsigned int idex)
{
    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    createTableViewCell(cell, table, idex);
    return cell;
}
CCSize XuanzeDiqu::cellSizeForTable(CCTableView* table)
{
    return CCSizeMake(550, 70);
    
}
unsigned int XuanzeDiqu::numberOfCellsInTableView(CCTableView* table)
{
    return (int)hInfo.size();
}

CCSize XuanzeDiqu::getTableSize()
{
    return CCSizeMake(550, 480);
}
void XuanzeDiqu::createTableViewCell(CCNode* cell, CCTableView* table, int idex)
{
    
        CCSprite* table_bg = CCSprite::create("chengshibg-1.png");
        //table_bg->setScaleX(0.33f);
        table_bg->setScale(0.6f);
        table_bg->setPosition(ccp(275,35));
        cell->addChild(table_bg,1);
        
        std::string info = hInfo[idex+1001];
        
        CCLabelTTF* statelb = CCLabelTTF::create(info.c_str(), "STXingkai.ttf", 35);
        //statelb->setColor(ccc3(0, 0, 0));
        statelb->setAnchorPoint(ccp(0,0.5f));
        statelb->setPosition(ccp(20,35));
        cell->addChild(statelb, 2);

}

bool XuanzeDiqu::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(101);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, 550, 480);
    
    isTouchIn = rt.containsPoint(pt);
    if(isTouchIn)
        return false;
    else
        return true;
    //return true;
}
void XuanzeDiqu::ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent)
{
    if(isTouchIn)
        return;
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(101);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, 550, 480);
    if(rt.containsPoint(pt) == false)
    {
        ((FirstPage*)getParent())->SetBtnToTouch();
        getParent()->removeChild(this);
    }
}

////////////////////////////////////////////////////////////////////
// 喜欢
////////////////////////////////////////////////////////////////////
XiHuan::XiHuan()
{
    
}

XiHuan::~XiHuan()
{
    
}

bool XiHuan::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* back = CCSprite::create("beijingdikuang-01.png");
    back->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-50));
    back->setScaleX(0.57f);
    back->setScaleY(0.65f);
    addChild(back);
    
    
    Button* xihuanbg = Button::createBtnWithSpriteFrameName("hengtiaozhuangtiai-02.png", false);
    xihuanbg->setPosition(ccp(winSize.width * 0.5f+40, winSize.height * 0.5f+240));
    xihuanbg->setScale(0.59f);
    xihuanbg->setOnClickCallback(callfuncO_selector(XiHuan::XihuanClick), this);
    addChild(xihuanbg, 2,10);
    
    CCSprite* shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-760, 0));
    shangfen->setFlipY(true);
    xihuanbg->addChild(shangfen, 2);
    
    CCLabelTTF* xihuanlab = CCLabelTTF::create(Global::getInstance()->getString("21"), "STXingkai.ttf",50);
    xihuanlab->setColor(ccc3(0, 0, 0));
    xihuanlab->setPosition(ccp(-660,0));
    xihuanbg->addChild(xihuanlab, 2);
    
    CCSprite* hongxin = CCSprite::create("hongxin-01.png");
    //shangfen->setScale(0.5f);
    hongxin->setPosition(ccp(780, 10));
    xihuanbg->addChild(hongxin, 2);
    
    
    return true;
}
void XiHuan::InitInfo(std::vector<TestAtt> info)
{
    int size = (int)info.size();
    
    char tem[64] = {0};
    sprintf(tem, "%d",size);
    CCLabelTTF* hongxinnum = CCLabelTTF::create(tem, "STXingkai.ttf",50);
    hongxinnum->setColor(ccc3(0, 0, 0));
    hongxinnum->setPosition(ccp(780,-40));
    getChildByTag(10)->addChild(hongxinnum, 2);
    
    if(size == 0)
    {
        CCLabelTTF* xihuanLAB = CCLabelTTF::create(Global::getInstance()->getString("25"), "STXingkai.ttf",40);
        xihuanLAB->setColor(ccc3(0, 0, 0));
        xihuanLAB->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
        addChild(xihuanLAB, 2);
    }else{
        int maxCount = 10<info.size()?10:(int)info.size();
        for (int i=0; i<maxCount; i++) {
            CCSprite* hongxin = CCSprite::create("touxiang002.png");
            hongxin->setScale(0.4f);
            hongxin->setPosition(ccp(250 + (i%5)*170, 420-(i/5)*220));
            addChild(hongxin, 2);
            
            char temp[32];
            sprintf(temp, "hero_%d.png", info[i].m_icon);
            hongxin = CCSprite::create(temp);
            hongxin->setScale(0.5f);
            hongxin->setPosition(ccp(250 + (i%5)*170, 420-(i/5)*220));
            addChild(hongxin, 2);
            
            CCLabelTTF* xihuanlab = CCLabelTTF::create(Global::getInstance()->getString("21"), "STXingkai.ttf",50);
            xihuanlab->setColor(ccc3(0, 0, 0));
            xihuanlab->setPosition(ccp(250 + (i%5)*170, 320-(i/5)*220));
            addChild(xihuanlab, 2);
        }
    }
}

void XiHuan::XihuanClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowXihuan(false);
}

////////////////////////////////////////////////////////////////////
// 照片
////////////////////////////////////////////////////////////////////
ZhaoPian::ZhaoPian()
{
    mPotoArr.clear();
}

ZhaoPian::~ZhaoPian()
{
    mPotoArr.clear();
}

bool ZhaoPian::init()
{
    if(!CCLayer::init())
        return false;
    setTouchEnabled(true);
    
    CCSprite* rightbg = CCSprite::create("zhaopianbg-01.png");
    rightbg->setPosition(ccp(winSize.width * 0.5f+480, winSize.height * 0.5f+20));
    rightbg->setScale(0.6f);
    addChild(rightbg);
    
    /*
    CCSprite* buttombg = CCSprite::create("zhaopian-03.png");
    buttombg->setPosition(ccp(winSize.width * 0.5f-40, winSize.height * 0.5f-240));
    buttombg->setScale(0.6f);
    addChild(buttombg);
    
    CCLabelTTF* neirong = CCLabelTTF::create("空荡荡的照片板，好像少了点什么呢", "STXingkai.ttf",40);
    //neirong->setColor(ccc3(0, 0, 0));
    neirong->setPosition(ccp(neirong->getContentSize().width/2+400,neirong->getContentSize().height/2+30));
    buttombg->addChild(neirong, 2);
    
    CCLabelTTF* lab = CCLabelTTF::create("未上传照片", "STXingkai.ttf",45);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(winSize.width * 0.5f-40, winSize.height * 0.5f+100));
    addChild(lab, 2);
    
    CCTableView* tableView = CCTableView::create(this, CCSizeMake(130, 530));
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setPosition(ccp(winSize.width * 0.5f+420, 80));
    //tableView->setPosition(ccp(-20,0));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 100, 101);
    //tableView->reloadData();
    */
    
    scheduleOnce(schedule_selector(ZhaoPian::SenMSG), 0.01f);
    return true;
}
void ZhaoPian::SenMSG(float ft)
{
    user_info user = Global::getInstance()->GetPlayerInfo();
    MainScene* scene = (MainScene*)getParent()->getParent();
    scene->reqGetPhoto(user.roleID);
}
void ZhaoPian::InitTabelView(std::vector<std::string> arr)
{
    mPotoArr = arr;
    user_info myInfo = Global::getInstance()->GetUserInfo();
    user_info pInfo = Global::getInstance()->GetPlayerInfo();
    if (myInfo.roleID == pInfo.roleID) {
        m_isShowAdd = true;
        m_spHeadNum = (int)arr.size()+1;
    }else{
        m_isShowAdd = false;
        m_spHeadNum = (int)arr.size();
    }
    if (getChildByTag(101)) {
        ((CCTableView*)getChildByTag(101))->reloadData();
        if (arr.size() != 0) {
            removeChildByTag(201,true);
            
            ZhaoPianView* zView = ZhaoPianView::create();
            addChild(zView,20,201);
            if (arr.size() == 0) {
                zView->InitTabelView("", 0);
            }else{
                zView->InitTabelView(arr[0], 1);
            }
        }
    }else{
        removeChildByTag(201,true);
        
        ZhaoPianView* zView = ZhaoPianView::create();
        addChild(zView,20,201);
        if (arr.size() == 0) {
            zView->InitTabelView("", 0);
        }else{
            zView->InitTabelView(arr[0], 1);
        }
        
        CCTableView* tableView = CCTableView::create(this, CCSizeMake(130, 530));
        //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
        tableView->setDirection(kCCScrollViewDirectionVertical);
        tableView->setPosition(ccp(winSize.width * 0.5f+420, 80));
        //tableView->setPosition(ccp(-20,0));
        tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
        tableView->setDelegate(this);
        addChild(tableView, 100, 101);
    }
}
void ZhaoPian::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    int idex = cell->getIdx();
    if(idex == m_spHeadNum-1)
    {
        ExchangeInfo::AddPhoto(idex+1);
    }else{
        removeChildByTag(201,true);
        
        ZhaoPianView* zView = ZhaoPianView::create();
        addChild(zView,20,201);
        if (mPotoArr.size() == 0) {
            zView->InitTabelView("", 0);
        }else{
            zView->InitTabelView(mPotoArr[idex], 1);
        }
    }
}
CCTableViewCell* ZhaoPian::tableCellAtIndex(CCTableView* table, unsigned int idex)
{
    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    if(idex == m_spHeadNum - 1 && m_isShowAdd)
    {
        CCSprite* hongxin = CCSprite::create("tianjiazhaopian-01.png");
        hongxin->setScale(0.5f);
        hongxin->setPosition(ccp(60, 60));
        cell->addChild(hongxin, 2);
    }else{
        CCTexture2D* tex = ExchangeInfo::GetTextureForData(mPotoArr[idex].c_str());
        CCLog("imag:%s",mPotoArr[idex].c_str());
        CCSprite* hongxin = CCSprite::createWithTexture(tex);
        hongxin->setScale(0.3f);
        hongxin->setPosition(ccp(60, 60));
        cell->addChild(hongxin, 2);
    }
    
    
    return cell;
}
CCSize ZhaoPian::cellSizeForTable(CCTableView* table)
{
    return CCSizeMake(120, 120);
}
unsigned int ZhaoPian::numberOfCellsInTableView(CCTableView* table)
{
    return m_spHeadNum;
}

///////////////////
ZhaoPianView::ZhaoPianView()
{
    
}
ZhaoPianView::~ZhaoPianView()
{
    
}

bool ZhaoPianView::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    
    return true;
}


void ZhaoPianView::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    
}
CCTableViewCell* ZhaoPianView::tableCellAtIndex(CCTableView* table, unsigned int idex)
{
    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    
    CCTexture2D* tex = ExchangeInfo::GetTextureForData(mIcon.c_str());
    
    CCSprite* hongxin = CCSprite::createWithTexture(tex);
    hongxin->setScale(2.834f);
    hongxin->setPosition(ccp(425, 300));
    cell->addChild(hongxin, 2,50);
    return cell;
}
CCSize ZhaoPianView::cellSizeForTable(CCTableView* table)
{
    return CCSizeMake(850, 600);
}
unsigned int ZhaoPianView::numberOfCellsInTableView(CCTableView* table)
{
    return 1;
}
void ZhaoPianView::InitTabelView(std::string arr,int mCount)
{
    mIcon = arr;
    if (mCount == 0) {
        CCSprite* back = CCSprite::create("zhaopianbj.png");
        back->setPosition(ccp(winSize.width * 0.5f-40, winSize.height * 0.5f+50));
        back->setScale(0.6f);
        addChild(back);
        
        CCSprite* buttombg = CCSprite::create("zhaopian-03.png");
        buttombg->setPosition(ccp(winSize.width * 0.5f-40, winSize.height * 0.5f-240));
        buttombg->setScale(0.6f);
        addChild(buttombg);
        
        CCLabelTTF* neirong = CCLabelTTF::create(Global::getInstance()->getString("26"), "STXingkai.ttf",40);
        //neirong->setColor(ccc3(0, 0, 0));
        neirong->setPosition(ccp(neirong->getContentSize().width/2+400,neirong->getContentSize().height/2+30));
        buttombg->addChild(neirong, 2);
        
        CCLabelTTF* lab = CCLabelTTF::create(Global::getInstance()->getString("27"), "STXingkai.ttf",45);
        lab->setColor(ccc3(0, 0, 0));
        lab->setPosition(ccp(winSize.width * 0.5f-40, winSize.height * 0.5f+100));
        addChild(lab, 2);
    }else{
        
        CCTableView* tableView = CCTableView::create(this, CCSizeMake(850, 600));
        //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
        tableView->setDirection(kCCScrollViewDirectionVertical);
        //tableView->setDirection(kCCScrollViewDirectionBoth);
        tableView->setPosition(ccp(winSize.width * 0.5f-460, winSize.height/2-300));
        //tableView->setPosition(ccp(-20,0));
        tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
        tableView->setDelegate(this);
        addChild(tableView, 100, 101);
    }
}
////////////////////////////////////////////////////////////////////
// 游戏数据
////////////////////////////////////////////////////////////////////
GameInfo::GameInfo()
{
  
}

GameInfo::~GameInfo()
{
    
}

bool GameInfo::init()
{
    if(!CCLayer::init())
        return false;
    
    user_info info = Global::getInstance()->GetPlayerInfo();
    duanweiInfo duan = Resource::sharedResource()->GetDuanweiInfo(info.duanwei);
    
    CCSprite* back = CCSprite::create("beijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+45));
    back->setScale(0.57f);
    addChild(back);
    
    CCSprite* youxi = CCSprite::create("xuanxiangkuang.png");
    youxi->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+280));
    youxi->setScale(0.57f);
    addChild(youxi);
    
    CCSprite* shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(80 ,youxi->getContentSize().height/2));
    shangfen->setFlipY(true);
    youxi->addChild(shangfen, 2);
    
    CCLabelTTF* lab = CCLabelTTF::create(Global::getInstance()->getString("28"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(230 ,youxi->getContentSize().height/2));
    youxi->addChild(lab, 2);
    
    youxi = CCSprite::create("splite.png");
    youxi->setPosition(ccp(winSize.width * 0.5f-80, winSize.height * 0.5f+45));
    youxi->setScale(0.5f);
    addChild(youxi);
    
    Button* headbg = NULL;
    user_info user = Global::getInstance()->GetUserInfo();
    std::map<int, int> equip = user.mEquip;
    std::map<int,int>::iterator iter;
    iter = equip.find(6);
    if (iter!=equip.begin()) {
        if(iter->second)
        {
            item ite = Resource::sharedResource()->getItemForID(iter->second);
            headbg = Button::createBtnWithSpriteFrameName(ite.itemIcon.c_str(), false);
            headbg->setPosition(ccp(winSize.width * 0.5f-245, winSize.height * 0.5f+80));
            headbg->setScale(0.55f);
            headbg->setOnClickCallback(callfuncO_selector(GameInfo::HeadClick), this);
            headbg->setPressIcon(ite.itemIcon.c_str(), false);
            addChild(headbg, 2,TAG_HEADBTN);
        }else{
            headbg = Button::createBtnWithSpriteFrameName("touxiang002.png", false);
            headbg->setPosition(ccp(winSize.width * 0.5f-245, winSize.height * 0.5f+80));
            headbg->setScale(0.55f);
            headbg->setOnClickCallback(callfuncO_selector(GameInfo::HeadClick), this);
            headbg->setPressIcon("touxiang002.png", false);
            addChild(headbg, 2,TAG_HEADBTN);
        }
    }else{
        headbg = Button::createBtnWithSpriteFrameName("touxiang002.png", false);
        headbg->setPosition(ccp(winSize.width * 0.5f-245, winSize.height * 0.5f+80));
        headbg->setScale(0.55f);
        headbg->setOnClickCallback(callfuncO_selector(GameInfo::HeadClick), this);
        headbg->setPressIcon("touxiang002.png", false);
        addChild(headbg, 2,TAG_HEADBTN);
    }
    
    user_info myInfo = Global::getInstance()->GetUserInfo();
    user_info pInfo = Global::getInstance()->GetPlayerInfo();
    if (myInfo.roleID != pInfo.roleID)
    {
        headbg->setIsCanTouch(false);
    }
    char temp[64];
    std::string path;
    if (info.icon>100) {
        sprintf(temp, "hero_%d.png", info.icon);
        path = temp;
    }else{
        char spName[64] = {0};
        sprintf(spName, "headImage%d.jpg",info.icon);
        
        path = Global::getInstance()->getDataPath(spName);
    }
    
    CCSprite* head = CCSprite::create(path.c_str());
    CirCularNode* headCir = CirCularNode::create(70, head);
    head->setScale(0.5f);
    headCir->setPosition(ccp(winSize.width * 0.5f-245, winSize.height * 0.5f+80));
    addChild(headCir, 2,TAG_HEADICON);
    
    sprintf(temp, Global::getInstance()->getString("29"), info.level);
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f+190));
    addChild(lab, 2);
    
    sprintf(temp, Global::getInstance()->getString("30"), info.gold);
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f+150));
    addChild(lab, 2);
    
    youxi = CCSprite::create("copper.png");
    youxi->setPosition(ccp(winSize.width * 0.5f+50+lab->getContentSize().width+20, winSize.height * 0.5f+150));
    youxi->setScale(0.5f);
    addChild(youxi);
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("31"), "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f+110));
    addChild(lab, 2);
    

    youxi = CCSprite::create(duan.icon.c_str());
    youxi->setPosition(ccp(winSize.width * 0.5f+150, winSize.height * 0.5f+110));
    youxi->setScale(0.25f);
    addChild(youxi);
    
    lab = CCLabelTTF::create(duan.name.c_str(), "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+170, winSize.height * 0.5f+110));
    addChild(lab, 2);
    
    if (info.stars > 3) {
        char starLab[32] = {0};
        sprintf(starLab, "%d",info.stars);
        lab = CCLabelTTF::create(starLab, "STXingkai.ttf", 30);
        lab->setColor(ccc3(0, 0, 0));
        lab->setAnchorPoint(ccp(0.0f,0.5f));
        lab->setPosition(ccp(winSize.width * 0.5f+270, winSize.height * 0.5f+110));
        addChild(lab, 2);
        
        CCSprite* xing = CCSprite::create("hecheng-xx-02.png");
        xing->setScale(0.6f);
        xing->setPosition(ccp(winSize.width * 0.5f+310, winSize.height * 0.5f+110));
        addChild(xing, 2);
    }else{
        for(int i = 0;i<3;i++)
        {
            if (info.stars > i) {
                CCSprite* xing = CCSprite::create("hecheng-xx-02.png");
                xing->setScale(0.6f);
                xing->setPosition(ccp(winSize.width * 0.5f+270 + i*30, winSize.height * 0.5f+110));
                addChild(xing, 2);
            }else{
                CCSprite* xing = CCSprite::create("hecheng-xx-01.png");
                xing->setScale(0.6f);
                xing->setPosition(ccp(winSize.width * 0.5f+270 + i*30, winSize.height * 0.5f+110));
                addChild(xing, 2);
            }
        }
    }
    
    sprintf(temp, Global::getInstance()->getString("32"), info.mvpCount);
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f+70));
    addChild(lab, 2);
    
    sprintf(temp, Global::getInstance()->getString("33"), info.chapionCount);
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f+30));
    addChild(lab, 2);
    
    sprintf(temp, Global::getInstance()->getString("34"), info.eatPlayerCount);
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f-10));
    addChild(lab, 2);
    
    sprintf(temp, Global::getInstance()->getString("35"), info.eatCount);
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f-50));
    addChild(lab, 2);
    
    //char temp[64];
    
    unsigned long long eMass = 0.000173415299158326*(pow(info.maxMass, 5))-7.34152991583261;
    
    if (eMass < 10000) {
        sprintf(temp, Global::getInstance()->getString("36"),eMass);
    }else if(eMass < 1000000)
    {
        unsigned long long tMa = eMass/100;
        sprintf(temp, Global::getInstance()->getString("37"), tMa);
    }else if(eMass < 1000000000)
    {
        unsigned long long tMa = eMass/100000;
        sprintf(temp, Global::getInstance()->getString("38"), tMa);
    }else if(eMass < 1000000000000)
    {
        unsigned long long tMa = eMass/100000000;
        sprintf(temp, Global::getInstance()->getString("39"), tMa);
    }else if(eMass < 1000000000000000)
    {
        unsigned long long tMa = eMass/100000000000;
        sprintf(temp, Global::getInstance()->getString("40"), tMa);
    }else if(eMass < 1000000000000000000)
    {
        unsigned long long tMa = eMass/100000000000000;
        sprintf(temp, Global::getInstance()->getString("41"), tMa);
    }else{
        unsigned long long tMa = eMass/100000000000000000;
        sprintf(temp, Global::getInstance()->getString("42"), tMa);
    }
    //sprintf(temp, "最大体重:%d千克", info.maxMass);
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+50, winSize.height * 0.5f-90));
    addChild(lab, 2);
    
    Button* gerenbt = Button::createBtnWithSpriteFrameName("xuanxiangkuang.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-190));
    gerenbt->setScale(0.57f);
    gerenbt->setOnClickCallback(callfuncO_selector(GameInfo::GerenClick), this);
    addChild(gerenbt, 2,TAG_GERENRONGYUBTN);
    
    shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-780 ,0));
    gerenbt->addChild(shangfen, 2);
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("43"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(-630 ,0));
    gerenbt->addChild(lab, 2);
    
    gerenbt = Button::createBtnWithSpriteFrameName("xuanxiangkuang.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-250));
    gerenbt->setScale(0.57f);
    gerenbt->setOnClickCallback(callfuncO_selector(GameInfo::BisaiClick), this);
    addChild(gerenbt, 2,TAG_BISAIJILUBTN);
    
    shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-780 ,0));
    gerenbt->addChild(shangfen, 2);
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("44"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(-630 ,0));
    gerenbt->addChild(lab, 2);
    return true;
}
void GameInfo::setHeadIcon()
{
    removeChildByTag(TAG_HEADICON, true);
    user_info info = Global::getInstance()->GetPlayerInfo();
    char temp[32];
    std::string path;
    if (info.icon>100) {
        sprintf(temp, "hero_%d.png", info.icon);
        path = temp;
    }else{
        char spName[64] = {0};
        sprintf(spName, "headImage%d.jpg",info.icon);
        
        path = Global::getInstance()->getDataPath(spName);
    }
    
    CCSprite* head = CCSprite::create(path.c_str());
    CirCularNode* headCir = CirCularNode::create(70, head);
    head->setScale(0.5f);
    headCir->setPosition(ccp(winSize.width * 0.5f-245, winSize.height * 0.5f+80));
    addChild(headCir, 2,TAG_HEADICON);
    
    ((HeadIconChose*)getChildByTag(TAG_HEADCHOSE))->reshHead();
}
void GameInfo::GerenClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowGame(2);
}
void GameInfo::BisaiClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowGame(3);
}
void GameInfo::HeadClick(cocos2d::CCObject *pSender)   //头像
{
    Button* gern = (Button*)getChildByTag(TAG_GERENRONGYUBTN);
    gern->setIsCanTouch(false);
    Button* bisai = (Button*)getChildByTag(TAG_BISAIJILUBTN);
    bisai->setIsCanTouch(false);
    Button* head = (Button*)getChildByTag(TAG_HEADBTN);
    head->setIsCanTouch(false);
    
    HeadIconChose* layer = HeadIconChose::create();
    addChild(layer,20,TAG_HEADCHOSE);
    layer->SetParentTag(2);
}
void GameInfo::SetBtnToTouch()
{
    Button* gern = (Button*)getChildByTag(TAG_GERENRONGYUBTN);
    gern->setIsCanTouch(true);
    Button* bisai = (Button*)getChildByTag(TAG_BISAIJILUBTN);
    bisai->setIsCanTouch(true);
    
    Button* head = (Button*)getChildByTag(TAG_HEADBTN);
    head->setIsCanTouch(true);

}
void GameInfo::resHeadImg(int count)
{
    HeadIconChose* layer = (HeadIconChose*)getChildByTag(TAG_HEADCHOSE);
    if(layer)
        layer->resHeadImg(count);
}
////////////////////////////////////////////////////////////////////
// 个人荣誉
////////////////////////////////////////////////////////////////////
GerenRongYu::GerenRongYu()
{
    
}

GerenRongYu::~GerenRongYu()
{
    
}

bool GerenRongYu::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* back = CCSprite::create("beijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-15));
    back->setScale(0.57f);
    addChild(back);
    
    CCSprite* youxi = CCSprite::create("xuanxiangkuang.png");
    youxi->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+220));
    youxi->setScale(0.57f);
    addChild(youxi);
    
    CCSprite* shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(80 ,youxi->getContentSize().height/2));
    shangfen->setFlipY(true);
    youxi->addChild(shangfen, 2);
    
    CCLabelTTF* lab = CCLabelTTF::create(Global::getInstance()->getString("43"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(230 ,youxi->getContentSize().height/2));
    youxi->addChild(lab, 2);
    
    
    Button* gerenbt = Button::createBtnWithSpriteFrameName("xuanxiangkuang.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+280));
    gerenbt->setScale(0.57f);
    gerenbt->setOnClickCallback(callfuncO_selector(GerenRongYu::GameClick), this);
    addChild(gerenbt, 2);
    
    shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-780 ,0));
    gerenbt->addChild(shangfen, 2);
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("28"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(-630 ,0));
    gerenbt->addChild(lab, 2);
    
    
    gerenbt = Button::createBtnWithSpriteFrameName("xuanxiangkuang.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-250));
    gerenbt->setScale(0.57f);
    gerenbt->setOnClickCallback(callfuncO_selector(GerenRongYu::BisaiClick), this);
    addChild(gerenbt, 2);
    
    shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-780 ,0));
    gerenbt->addChild(shangfen, 2);
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("44"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(-630 ,0));
    gerenbt->addChild(lab, 2);
    
    scheduleOnce(schedule_selector(GerenRongYu::SenMSG), 0.01f);
    return true;
}
void GerenRongYu::SenMSG(float ft)
{
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqSeasonRank(usef.roleID);
}
void GerenRongYu::ShowUI(float fx,season_rank info)
{
    //CCSprite* youxi = CCSprite::create("rongyu_base.png");
    //youxi->setPosition(ccp(fx, winSize.height * 0.5f));
    //youxi->setScale(0.57f);
    //addChild(youxi);
    
    //CCLOG("info,  duanwei:%d   xingji:%d   rank:%d",info.duanwei(),info.star(),info.rank());
    
    if (!info.duanwei()) {
        return;
    }
    
    duanweiInfo duan = Resource::sharedResource()->GetDuanweiInfo(info.duanwei());
    //duanweiInfo duan = Resource::sharedResource()->GetDuanweiInfo(1);
    char temp[64] = {0};
    sprintf(temp, Global::getInstance()->getString("45"),info.season());
    CCLabelTTF* lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    //lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(fx, winSize.height * 0.5f+110));
    addChild(lab, 2);
    
    if (info.star() < 4 ) {
        int xxIdx = 0;
        if (xxIdx < info.star()) {
            CCSprite* xing = CCSprite::create("hecheng-xx-02.png");
            xing->setScale(0.9f);
            xing->setPosition(ccp(fx-45, winSize.height * 0.5f+58));
            xing->setRotation(-30.0f);
            addChild(xing, 2);
        }else{
            CCSprite* xing = CCSprite::create("hecheng-xx-01.png");
            xing->setScale(0.9f);
            xing->setPosition(ccp(fx-45, winSize.height * 0.5f+58));
            xing->setRotation(-30.0f);
            addChild(xing, 2);
        }
        xxIdx++;
        if (xxIdx < info.star())
        {
            CCSprite* xing = CCSprite::create("hecheng-xx-02.png");
            xing->setScale(0.9f);
            xing->setPosition(ccp(fx, winSize.height * 0.5f+70));
            //xing->setRotation(30.0f);
            addChild(xing, 2);
        }else{
            CCSprite* xing = CCSprite::create("hecheng-xx-01.png");
            xing->setScale(0.9f);
            xing->setPosition(ccp(fx, winSize.height * 0.5f+70));
            //xing->setRotation(30.0f);
            addChild(xing, 2);
        }
        xxIdx++;
        
        if (xxIdx < info.star())
        {
            CCSprite* xing = CCSprite::create("hecheng-xx-02.png");
            xing->setScale(0.9f);
            xing->setPosition(ccp(fx+45, winSize.height * 0.5f+58));
            xing->setRotation(30.0f);
            addChild(xing, 2);
        }else{
            CCSprite* xing = CCSprite::create("hecheng-xx-01.png");
            xing->setScale(0.9f);
            xing->setPosition(ccp(fx+45, winSize.height * 0.5f+58));
            xing->setRotation(30.0f);
            addChild(xing, 2);
        }
    }else{
        CCSprite* xing = CCSprite::create("hecheng-xx-02.png");
        xing->setScale(0.9f);
        xing->setPosition(ccp(fx-15, winSize.height * 0.5f+70));
        //xing->setRotation(30.0f);
        addChild(xing, 2);
        
        sprintf(temp, "%d",info.star());
        lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
        lab->setColor(ccc3(0, 0, 0));
        lab->setAnchorPoint(ccp(0.0f, 0.5f));
        lab->setPosition(ccp(fx+15, winSize.height * 0.5f+67));
        addChild(lab, 2);
    }
    
    
    CCSprite* xing = CCSprite::create(duan.icon.c_str());
    xing->setScale(0.7f);
    xing->setPosition(ccp(fx, winSize.height * 0.5f-20));
    addChild(xing, 2);
    
    lab = CCLabelTTF::create(duan.name.c_str(), "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    //lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(fx, winSize.height * 0.5f-100));
    addChild(lab, 2);
    
    if (info.rank() !=0 ) {
        sprintf(temp, Global::getInstance()->getString("46"),info.rank());
    }else{
        sprintf(temp, Global::getInstance()->getString("47"));
    }
    lab = CCLabelTTF::create(temp, "STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    //lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(fx, winSize.height * 0.5f-145));
    addChild(lab, 2);

}
void GerenRongYu::InitRongyu(std::vector<season_rank> arr)
{
    int sNum = (int)arr.size();
    float fx = 0;
    if (sNum == 1) {
        fx = winSize.width*0.5f+45;
    }
    
    if (sNum == 2) {
        fx = winSize.width*0.5f+45-150;
    }
    
    if (sNum == 3) {
        fx = winSize.width*0.5f+45-300;
    }
    for (int i = 0; i<sNum; i++) {
        ShowUI(fx + i*300, arr[i]);
    }
}
void GerenRongYu::GameClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowGame(1);
}
void GerenRongYu::BisaiClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowGame(3);
}



////////////////////////////////////////////////////////////////////
// 比赛记录
////////////////////////////////////////////////////////////////////
BisaiJilu::BisaiJilu()
{
    infos.clear();
    /*
    bisaiInfo info1;
    info1.m_id = 1;
    info1.m_Icon = 1;
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
    info2.m_Icon = 1;
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
    info3.m_Icon = 1;
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
    info4.m_Icon = 1;
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
    info5.m_Icon = 1;
    info5.m_nickName = "批发初吻";
    info5.m_lastTime = "11天前";
    info5.m_rank = "30";
    info5.m_weight = "10毫克";
    info5.m_number = "10";
    info5.m_duration = "2分钟";
    info5.m_copper = "1";
    infos.push_back(info5);
     */
}

BisaiJilu::~BisaiJilu()
{
    
}

bool BisaiJilu::init()
{
    if(!CCLayer::init())
        return false;
    
    //CCLayerColor* color = CCLayerColor::create(ccc4(255, 0, 0, 100), 1036, 460);
    //    CCLayerColor* color = CCLayerColor::create(ccc4(0, 0, 0, 255), 1036, 460);
    //    color->setPosition(ccp(0,0));
    //    addChild(color,0);
    
    //CCSprite* title_base = CCSprite::create("title_back.png");
    //title_base->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height - 200 ));
   // title_base->setScale(0.6f);
   // addChild(title_base, 1);
    
    CCSprite* youxi = CCSprite::create("xuanxiangkuang.png");
    youxi->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+160));
    youxi->setScale(0.57f);
    addChild(youxi);
    
    CCSprite* shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(80 ,youxi->getContentSize().height/2));
    shangfen->setFlipY(true);
    youxi->addChild(shangfen, 2);
    
    CCLabelTTF* lab = CCLabelTTF::create(Global::getInstance()->getString("44"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(230 ,youxi->getContentSize().height/2));
    youxi->addChild(lab, 2);
    
    Button* gerenbt = Button::createBtnWithSpriteFrameName("xuanxiangkuang.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+280));
    gerenbt->setScale(0.57f);
    gerenbt->setOnClickCallback(callfuncO_selector(BisaiJilu::GameClick), this);
    addChild(gerenbt, 2);
    
    shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-780 ,0));
    gerenbt->addChild(shangfen, 2);
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("28"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(-630 ,0));
    gerenbt->addChild(lab, 2);
    
    
    gerenbt = Button::createBtnWithSpriteFrameName("xuanxiangkuang.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+220));
    gerenbt->setScale(0.57f);
    gerenbt->setOnClickCallback(callfuncO_selector(BisaiJilu::GerenClick), this);
    addChild(gerenbt, 2);
    
    shangfen = CCSprite::create("shangfenye-01.png");
    //shangfen->setScale(0.5f);
    shangfen->setPosition(ccp(-780 ,0));
    gerenbt->addChild(shangfen, 2);
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("43"), "STXingkai.ttf",55);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(-630 ,0));
    gerenbt->addChild(lab, 2);
    
    
    CCSprite* title_nick = CCSprite::create("title_nick.png");
    title_nick->setPosition(ccp(340, winSize.height - 200));
    title_nick->setScale(0.6f);
    addChild(title_nick, 1);
    
    CCSprite* title_rank = CCSprite::create("rank_title.png");
    title_rank->setPosition(ccp(520, winSize.height - 200));
    title_rank->setScale(0.6f);
    addChild(title_rank, 1);
    
    CCSprite* title_weight = CCSprite::create("title_weight.png");
    title_weight->setPosition(ccp(650, winSize.height - 200));
    title_weight->setScale(0.6f);
    addChild(title_weight, 1);
    
    CCSprite* title_num = CCSprite::create("tunshirenshu-002.png");
    title_num->setPosition(ccp(790, winSize.height - 200));
    title_num->setScale(0.6f);
    addChild(title_num, 1);
    
    CCSprite* title_duration = CCSprite::create("cunhuoshijian-002.png");
    title_duration->setPosition(ccp(920, winSize.height - 200));
    title_duration->setScale(0.6f);
    addChild(title_duration, 1);
    
    CCSprite* title_copper = CCSprite::create("tongqian-002.png");
    title_copper->setPosition(ccp(1030, winSize.height - 200));
    title_copper->setScale(0.6f);
    addChild(title_copper, 1);
    
    CCTableView* tableView = CCTableView::create(this, getTableSize());
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(120,60));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 2, 101);
    tableView->reloadData();
    
    scheduleOnce(schedule_selector(BisaiJilu::SenMSG), 0.01f);
    return true;
}
void BisaiJilu::SenMSG(float ft)
{
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqGameRecord(usef.roleID);
}
void BisaiJilu::InitBisai(std::vector<bisaiInfo> arr)
{
    infos.clear();
    infos = arr;
    CCTableView* tabel = (CCTableView*)getChildByTag(101);
    tabel->reloadData();
}
void BisaiJilu::GameClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowGame(1);
}
void BisaiJilu::GerenClick(cocos2d::CCObject *pSender)
{
    ((UserInfo*)getParent())->ShowGame(2);
}
CCSize BisaiJilu::getTableSize()
{
    return CCSizeMake(980, 360);
}

void BisaiJilu::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell)
{
    
}

CCTableViewCell* BisaiJilu::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idex)
{

    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    createTableViewCell(cell, table, idex);
    return cell;
}

void BisaiJilu::createTableViewCell(cocos2d::CCNode *cell, cocos2d::extension::CCTableView *table, int idex)
{
    int left = idex % 2;
    CCSprite* table_bg = NULL;
    if(left == 0)
        table_bg = CCSprite::create("bisai_cell_back1.png");
    else
        table_bg = CCSprite::create("bisai_cell_back2.png");
    if(table)
    {
        table_bg->setScale(0.54f);
        table_bg->setPosition(ccp(490,40));
        cell->addChild(table_bg,1);
        
        CCSize size = table_bg->getContentSize() * 0.6;
        
        bisaiInfo info = infos[idex];
        /*
        char temp[32];
        sprintf(temp, "hero_%d.png", info.m_Icon);
        CCSprite* icon = CCSprite::create(temp);
        icon->setPosition(ccp(590 - size.width * 0.5f+20, 40));
        icon->setScale(0.25f);
        cell->addChild(icon, 1);
        */
        char temp1[32];
        CCSprite* icon;
        CirCularNode* iconCir;
        if(info.m_Icon < 101)
        {
            /*
            CCTexture2D* tex = ExchangeInfo::GetTextureForData(info.m_iconStr.c_str());
            icon = CCSprite::createWithTexture(tex);
            icon->setScale(0.4f);
            iconCir = CirCularNode::create(50, icon);
          */
        }
        else
        {
            sprintf(temp1, "hero_%d.png", info.m_Icon);
            icon = CCSprite::create(temp1);
            icon->setScale(0.4f);
            iconCir = CirCularNode::create(50, icon);
        }
        
        iconCir->setPosition(ccp(590 - size.width * 0.5f+20, 40));
        cell->addChild(iconCir, 1);
        
        NameColor color = Global::getInstance()->GetNameColor(info.m_nickName);

        CCLabelTTF* nick_name = CCLabelTTF::create(info.m_nickName.c_str(), "STXingkai.ttf", 29);
        nick_name->setColor(ccc3(color.colorR, color.colorG, color.colorB));
        nick_name->setAnchorPoint(ccp(0,0));
        nick_name->setPosition(ccp(650 - size.width * 0.5f+20, 50));
        cell->addChild(nick_name, 1);
        
        CCLabelTTF* last_Time = CCLabelTTF::create(info.m_lastTime.c_str(), "STXingkai.ttf", 24);
        last_Time->setColor(ccc3(255, 255, 255));
        last_Time->setAnchorPoint(ccp(0,0));
        last_Time->setPosition(ccp(650 - size.width * 0.5f+20, 10));
        cell->addChild(last_Time, 1);
        
        CCLabelTTF* rank = CCLabelTTF::create(info.m_rank.c_str(), "STXingkai.ttf", 29);
        rank->setColor(ccc3(255, 255, 255));
        rank->setAnchorPoint(ccp(0,0));
        rank->setPosition(ccp(900 - size.width * 0.5f+20, 30));
        cell->addChild(rank, 1);
        
        CCLabelTTF* weight = CCLabelTTF::create(info.m_weight.c_str(), "STXingkai.ttf", 29);
        weight->setColor(ccc3(255, 255, 255));
        weight->setAnchorPoint(ccp(0,0));
        weight->setPosition(ccp(1000 - size.width * 0.5f+20, 30));
        cell->addChild(weight, 1);
        
        CCLabelTTF* num = CCLabelTTF::create(info.m_number.c_str(), "STXingkai.ttf", 29);
        num->setColor(ccc3(255, 255, 255));
        num->setAnchorPoint(ccp(0,0));
        num->setPosition(ccp(660, 30));
        cell->addChild(num, 1);
        
        CCLabelTTF* duration = CCLabelTTF::create(info.m_duration.c_str(), "STXingkai.ttf", 29);
        duration->setColor(ccc3(255, 255, 255));
        duration->setAnchorPoint(ccp(0,0));
        duration->setPosition(ccp(770, 30));
        cell->addChild(duration, 1);
        
        CCLabelTTF* coppor = CCLabelTTF::create(info.m_copper.c_str(), "STXingkai.ttf", 29);
        coppor->setColor(ccc3(255, 255, 255));
        coppor->setAnchorPoint(ccp(0,0));
        coppor->setPosition(ccp(900, 30));
        cell->addChild(coppor, 1);
    }
}

CCSize BisaiJilu::cellSizeForTable(cocos2d::extension::CCTableView *table)
{
    CCSize tableSize = getTableSize();
    return CCSizeMake(tableSize.width, tableSize.height / 4.5);
}

unsigned int BisaiJilu::numberOfCellsInTableView(cocos2d::extension::CCTableView *table)
{
    return (int)infos.size();
}


////////////////////////////////////////////////////////////////////
// 战队系统
////////////////////////////////////////////////////////////////////
ZhanDui::ZhanDui()
{
    
}

ZhanDui::~ZhanDui()
{
    
}

bool ZhanDui::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* back = CCSprite::create("zhanduibeijingtu-01.png");
    back->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f));
    back->setScale(0.57f);
    addChild(back);
    
    
    CCLabelTTF* lab = CCLabelTTF::create("战队系统即将推出", "STXingkai.ttf",45);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+200));
    addChild(lab, 2);
    
    
    lab = CCLabelTTF::create("《球球大战》招募战队系统先锋测试员！","STXingkai.ttf",35);
    lab->setColor(ccc3(0, 0, 0));
    //lab->setAnchorPoint(ccp(0.0f, 0.5f));
    lab->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+130));
    addChild(lab, 2);
    
    
    std::ostringstream ossAttr;
    std::string content1 = "      为了保证游戏稳定性，运营团队决定在战队系统正式推出前，向广大玩家招募一批战队系统先锋测试员，率先体验战队系统和战队战！我们随后将在官方微信公众号具体公布招募信息和要求，敬请留意官方微信公众号。\n     请大家关注《球球大战》官方微信公众号：了不起的团队";
   
    ossAttr<<"<t/><font><fontname>STXingkai</><fontsize>25</><color><value>00000000</>" << content1.c_str()<<"</></>";
    
    
    RichLabel* helpCon = RichLabel::create(ossAttr.str().c_str(), "STXingkai.ttf", 25.0f, CCSizeMake(690, 30),false,false);
    helpCon->setAnchorPoint(CCPointZero);
    //helpCon->setColor(ccBLACK);
    helpCon->setPosition(ccp(280, winSize.height * 0.5f+50));
    addChild(helpCon, 2);
    
    lab = CCLabelTTF::create("了不起的公司","STXingkai.ttf",25);
    lab->setColor(ccc3(0, 0, 0));
    //lab->setAnchorPoint(CCPointZero);
    lab->setPosition(ccp(900, winSize.height * 0.5f-165));
    addChild(lab, 2);
    
    lab = CCLabelTTF::create("2016年7月","STXingkai.ttf",25);
    lab->setColor(ccc3(0, 0, 0));
    //lab->setAnchorPoint(CCPointZero);
    lab->setPosition(ccp(900, winSize.height * 0.5f-195));
    addChild(lab, 2);
    
    return true;
}


////////////////////////////////////////////////////////////////////
// 留言
////////////////////////////////////////////////////////////////////
LiuYan::LiuYan()
{
    infos.clear();
    hotInfo.clear();
    /*
    for (int i = 0; i < 15; i++) {
        LiuyanInfo info;
        info.m_name = "了不起的家伙";
        info.m_neirong = "ddfadfsaaeffafds";
        info.m_icon = 1;
        info.likeCount = 10;
        info.isLike = 0;
        infos.push_back(info);
    }
    
    for (int i = 0; i < 3; i++) {
        LiuyanInfo info;
        info.m_name = "了不起的家伙";
        info.m_neirong = "ddfadfsaaeffafds";
        info.m_icon = 1;
        info.likeCount = 10;
        info.isLike = 0;
        hotInfo.push_back(info);
    }
    */
    m_curpage = 0;
}

LiuYan::~LiuYan()
{
    infos.clear();
    hotInfo.clear();
}

bool LiuYan::init()
{
    if(!CCLayer::init())
        return false;
    
    CCSprite* back = CCSprite::create("beijing-01.png");
    back->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f-45));
    back->setScale(0.57f);
    addChild(back);
    
    CCSprite* youxi = CCSprite::create("xuanxiangkuang.png");
    youxi->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+260));
    youxi->setScale(0.57f);
    addChild(youxi);
    
    
    char liuyan[256] = {0};
    sprintf(liuyan, Global::getInstance()->getString("48"),(int)infos.size());
    
    CCLabelTTF* lab = CCLabelTTF::create(liuyan, "STXingkai.ttf",40);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(winSize.width * 0.5f-330, winSize.height * 0.5f+260));
    addChild(lab, 2,1);
    
    
    youxi = CCSprite::create("xuanxiangkuang.png");
    youxi->setPosition(ccp(winSize.width * 0.5f+45, winSize.height * 0.5f+200));
    youxi->setScale(0.57f);
    addChild(youxi);
    
    Button* gerenbt = Button::createBtnWithSpriteFrameName("fasong-01.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+380, winSize.height * 0.5f+200));
    gerenbt->setScale(0.57f);
    gerenbt->setPressIcon("fasong-02.png", false);
    gerenbt->setOnClickCallback(callfuncO_selector(LiuYan::FasongClick), this);
    addChild(gerenbt, 2);
    
    gerenbt = Button::createBtnWithSpriteFrameName("liuyanfanye-01.png", false);
    gerenbt->setPosition(ccp(winSize.width * 0.5f+480, winSize.height * 0.5f+200));
    gerenbt->setScale(0.57f);
    gerenbt->setOnClickCallback(callfuncO_selector(LiuYan::ShuaxinClick), this);
    addChild(gerenbt, 2);
    
    
    lab = CCLabelTTF::create(Global::getInstance()->getString("49"), "STXingkai.ttf",40);
    lab->setColor(ccc3(0, 0, 0));
    lab->setPosition(ccp(winSize.width * 0.5f-335, winSize.height * 0.5f+200));
    addChild(lab, 2);
    
    
    CCSprite* inputbg = CCSprite::create("liuyanshurubj.png");
    inputbg->setScaleY(0.6f);
    inputbg->setScaleX(0.5f);
    inputbg->setPosition(ccp(winSize.width * 0.5f + 30, winSize.height * 0.5+200));
    addChild(inputbg, 2);
    
    CEditBoxTool* edbox = CEditBoxTool::Create(CCSizeMake(520, 80), CCScale9Sprite::create("input.png"));
    edbox->setPosition(ccp(winSize.width * 0.5f+30 , winSize.height * 0.5 +200));
    edbox->setFont("STXingkai.ttf", 29.0f);
    edbox->setFontColor(ccc3(0, 0, 0));
    edbox->setMaxLength(114);
    edbox->setInputMode(kEditBoxInputModeAny);
    edbox->setDelegate(this);
    addChild(edbox, 3, 101);
    
    
    
    CCTableView* tableView = CCTableView::create(this, getTableSize());
    //tableView->setTouchPriority(MAIN_TABLEVIEW_ACTIVE);
    tableView->setDirection(kCCScrollViewDirectionVertical);
    //tableView->setPosition(ccp(winSize.width * 0.5f - CHILD_OFFSET_X, winSize.height * 0.5f - CHILD_OFFSET_Y));
    tableView->setPosition(ccp(120,60));
    tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    tableView->setDelegate(this);
    addChild(tableView, 2, 102);
    //tableView->reloadData();
    
    InitHotLiuyan(hotInfo);
    scheduleOnce(schedule_selector(LiuYan::SenMSG), 0.01f);
    return true;
}

void LiuYan::SenMSG(float ft)
{
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqHotMsg(usef.roleID);
    ((MainScene*)getParent()->getParent())->reqGetMsg(usef.roleID, 0, 10);
}
void LiuYan::editBoxReturn(cocos2d::extension::CCEditBox* editBox)
{
    CEditBoxTool* input = dynamic_cast<CEditBoxTool*>(getChildByTag(101));
    std::string nick = input->getText();
    if(nick == "" || nick.size() == 0)
        return;

}
void LiuYan::FasongClick(cocos2d::CCObject *pSender)
{
    CEditBoxTool* input = dynamic_cast<CEditBoxTool*>(getChildByTag(101));
    std::string nick = input->getText();
    if(nick == "" || nick.size() == 0)
        return;
    
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqSendMsg(usef.roleID, nick);
    
    input->setText("");
}
void LiuYan::ShuaxinClick(cocos2d::CCObject *pSender)
{
    int num = (int)infos.size();
    if (num < 10) {
        return;
    }
    m_curpage++;
    
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqGetMsg(usef.roleID, m_curpage*10, m_curpage*10+10);
}
CCSize LiuYan::getTableSize()
{
    return CCSizeMake(980, 410-240);
}

void LiuYan::tableCellTouched(cocos2d::extension::CCTableView *table, cocos2d::extension::CCTableViewCell *cell)
{
    
}

CCTableViewCell* LiuYan::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idex)
{
    
    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
    }else{
        cell->removeAllChildrenWithCleanup(true);
    }
    createTableViewCell(cell, table, idex);
    return cell;
}

void LiuYan::createTableViewCell(cocos2d::CCNode *cell, cocos2d::extension::CCTableView *table, int idex)
{
    int left = idex % 2;
    CCSprite* table_bg = NULL;
    if(left == 0)
        table_bg = CCSprite::create("bisai_cell_back2.png");
    else
        table_bg = CCSprite::create("bisai_cell_back1.png");
    if(table)
    {
        table_bg->setScale(0.54f);
        table_bg->setPosition(ccp(490,40));
        cell->addChild(table_bg,1);
        
        CCSize size = table_bg->getContentSize() * 0.6;
        
        LiuyanInfo info = infos[idex+10*m_curpage];
        
        char temp[32];
        sprintf(temp, "hero_%d.png", info.m_icon);
        CCSprite* icon = CCSprite::create(temp);
        icon->setPosition(ccp(590 - size.width * 0.5f+20, 40));
        icon->setScale(0.25f);
        cell->addChild(icon, 1);
        
        CCLabelTTF* nick_name = CCLabelTTF::create(info.m_name.c_str(), "STXingkai.ttf", 29);
        nick_name->setColor(ccc3(255, 255, 255));
        nick_name->setAnchorPoint(ccp(0,0));
        nick_name->setPosition(ccp(650 - size.width * 0.5f+20, 45));
        cell->addChild(nick_name, 1);
        
        CCLabelTTF* last_Time = CCLabelTTF::create(info.m_neirong.c_str(), "STXingkai.ttf", 24);
        last_Time->setColor(ccc3(255, 255, 255));
        last_Time->setAnchorPoint(ccp(0,0));
        last_Time->setPosition(ccp(650 - size.width * 0.5f+20, 15));
        cell->addChild(last_Time, 1);
        
        char labStr[8] = {0};
        sprintf(labStr, "%d",info.likeCount);
        CCLabelTTF* count = CCLabelTTF::create(labStr, "STXingkai.ttf", 29);
        count->setColor(ccc3(255, 255, 255));
        count->setAnchorPoint(ccp(1,0));
        count->setPosition(ccp(800 , 45));
        cell->addChild(count, 1);
        
        Button* gerenbt = Button::createBtnWithSpriteFrameName("zan_01.png", false);
        gerenbt->setPosition(ccp(830 , 60));
        gerenbt->setScale(0.57f);
        gerenbt->setPressIcon("zan_02.png", false);
        gerenbt->setOnClickCallback(callfuncO_selector(LiuYan::ZanClick), this);
        cell->addChild(gerenbt, 2);
        
        if (info.isLike) {
            gerenbt->setPressIconShow(true);
        }
    
        
        Button* jubao = Button::createBtnWithSpriteFrameName("jubao_01.png", false);
        jubao->setPosition(ccp(900 , 60));
        jubao->setScale(0.6f);
        jubao->setOnClickCallback(callfuncO_selector(LiuYan::JubaoClick), this);
        cell->addChild(jubao, 2);
    }
}
void LiuYan::HotZanClick(cocos2d::CCObject *pSender)
{
    Button* btn = (Button*)pSender;
    CCLayer* cell = (CCLayer*)(btn->getParent());
    int idx = cell->getTag();
    int set = 1;
    if(hotInfo[idx].isLike)
        set = 0;
    
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqLikeMsg(usef.roleID, hotInfo[idx].liuyanID, set);
    
    hotInfo[idx].isLike = set;
    if (set == 0) {
        hotInfo[idx].likeCount--;
    }else{
        hotInfo[idx].likeCount++;
    }
    //hotInfo[idx].likeCount++;
    //btn->setPressIconShow(hotInfo[idx].isLike);
    
    CCTableView* tabel = dynamic_cast<CCTableView*>(getChildByTag(102));
    tabel->reloadData();
}
void LiuYan::HotJubaoClick(cocos2d::CCObject *pSender)
{
    
}
void LiuYan::ZanClick(cocos2d::CCObject *pSender)
{
    Button* btn = (Button*)pSender;
    CCTableViewCell* cell = (CCTableViewCell*)(btn->getParent());
    int idx = cell->getIdx();
    int set = 1;
    if(infos[idx].isLike)
        set = 0;
    
    user_info usef = Global::getInstance()->GetPlayerInfo();
    ((MainScene*)getParent()->getParent())->reqLikeMsg(usef.roleID, infos[idx].liuyanID, set);
    
    infos[idx].isLike = set;
    if (set == 0) {
        infos[idx].likeCount--;
    }else{
        infos[idx].likeCount++;
    }
    //btn->setPressIconShow(infos[idx].isLike);
    
    CCTableView* tabel = dynamic_cast<CCTableView*>(getChildByTag(102));
    tabel->reloadData();

}
void LiuYan::JubaoClick(cocos2d::CCObject *pSender)
{
    
}
CCSize LiuYan::tableCellSizeForIndex(cocos2d::extension::CCTableView *table,unsigned int idx)
{
    return CCSizeMake(980, 80);
}

unsigned int LiuYan::numberOfCellsInTableView(cocos2d::extension::CCTableView *table)
{
    int num = (int)infos.size();
    
    return num;
}
void LiuYan::InitHotLiuyan(std::vector<LiuyanInfo> hotArr)
{
    //hotInfo = hotArr;
    for (int i = 0; i < hotInfo.size(); i++) {
        CCLayer* layer = CCLayer::create();
        layer->setPosition(ccp(120,400-i*80));
        addChild(layer,0,i);
        
        int left = i % 2;
        CCSprite* table_bg = NULL;
        if(left == 0)
            table_bg = CCSprite::create("bisai_cell_back1.png");
        else
            table_bg = CCSprite::create("bisai_cell_back2.png");
        
        table_bg->setScale(0.54f);
        table_bg->setPosition(ccp(490,40));
        layer->addChild(table_bg,1);
            
        CCSize size = table_bg->getContentSize() * 0.6;
            
        LiuyanInfo info = hotInfo[i];
            
        char temp[32];
        sprintf(temp, "hero_%d.png", info.m_icon);
        CCSprite* icon = CCSprite::create(temp);
        icon->setPosition(ccp(590 - size.width * 0.5f+20, 40));
        icon->setScale(0.25f);
        layer->addChild(icon, 1);
            
        CCLabelTTF* nick_name = CCLabelTTF::create(info.m_name.c_str(), "STXingkai.ttf", 29);
        nick_name->setColor(ccc3(255, 255, 255));
        nick_name->setAnchorPoint(ccp(0,0));
        nick_name->setPosition(ccp(650 - size.width * 0.5f+20, 45));
        layer->addChild(nick_name, 1);
            
        CCLabelTTF* last_Time = CCLabelTTF::create(info.m_neirong.c_str(), "STXingkai.ttf", 24);
        last_Time->setColor(ccc3(255, 255, 255));
        last_Time->setAnchorPoint(ccp(0,0));
        last_Time->setPosition(ccp(650 - size.width * 0.5f+20, 15));
        layer->addChild(last_Time, 1);
            
        char labStr[8] = {0};
        sprintf(labStr, "%d",info.likeCount);
        CCLabelTTF* count = CCLabelTTF::create(labStr, "STXingkai.ttf", 29);
        count->setColor(ccc3(255, 255, 255));
        count->setAnchorPoint(ccp(1,0));
        count->setPosition(ccp(800 , 45));
        layer->addChild(count, 1);
        
        Button* gerenbt = Button::createBtnWithSpriteFrameName("zan_01.png", false);
        gerenbt->setPosition(ccp(830 , 60));
        gerenbt->setScale(0.57f);
        gerenbt->setPressIcon("zan_02.png", false);
        gerenbt->setOnClickCallback(callfuncO_selector(LiuYan::HotZanClick), this);
        layer->addChild(gerenbt, 2);
        
        if (info.isLike) {
            gerenbt->setPressIconShow(true);
        }
        
        
        Button* jubao = Button::createBtnWithSpriteFrameName("jubao_01.png", false);
        jubao->setPosition(ccp(900 , 60));
        jubao->setScale(0.6f);
        jubao->setOnClickCallback(callfuncO_selector(LiuYan::HotJubaoClick), this);
        layer->addChild(jubao, 2);
        
        icon = CCSprite::create("huo_01.png");
        icon->setPosition(ccp(900, 25));
        icon->setScale(0.6f);
        layer->addChild(icon, 1);
        
    }
}
void LiuYan::InitLiuyan(std::vector<LiuyanInfo> hotArr)
{
    infos.clear();
    infos = hotArr;
    
    CCTableView* tabel = dynamic_cast<CCTableView*>(getChildByTag(102));
    tabel->reloadData();
}