//
//  MainScene.h
//  qiuFight
//
//  Created by 张跃东 on 16/2/24.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "Global.h"

#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "WebSocketLayer.h"


class MainScene : public CCLayer
{
public:
    enum tagDif
    {
        TAG_NONE,
        TAG_LAYER_LOGIN,
        TAG_LAYER_PERSON,
        TAG_LAYER_RELATION,
        TAG_LAYER_RANKING,
        TAG_LAYER_SHOP,
        TAG_LAYER_SCENE,
        TAG_LAYER_TUANDUI,
        //TAG_LAYER_SOCKET,
        TAG_LAYER_GRID,
        TAG_LAYER_JOY,
        TAG_LAYER_USERINFO,
        TAG_GAME_END,
        TAG_GAME_COLOR_BG,
        TAG_MAX
    };
    MainScene();
    ~MainScene();
    virtual bool init();
    CREATE_FUNC(MainScene);
    void initJson();
    
    //static CCScene* scene();
    
    void initBackLayer();
    
    virtual void ccTouchesBegan(CCSet* pTouch, CCEvent* pEvent);
    virtual void ccTouchesMoved(CCSet* pTouch, CCEvent* pEvent);
    virtual void ccTouchesEnded(CCSet* pTouch, CCEvent* pEvent);
    
    virtual void update(float ft);
    //void updateFrame(float ft);
    
    void enterGame(const char* nick, int key);
    
    void setWinSize(const WebSocket::Data &data);
    void addSelfNode(const WebSocket::Data &data);
    void updateNodes(const WebSocket::Data &data);
    // 更新战斗内排名
    void updateRankeInFight(const WebSocket::Data &data);
    // 战斗结算
    void GameOverState(const WebSocket::Data &data);
    // 更新生命
    void UpdateFightLife(const WebSocket::Data& data);
    // 死亡
    void SetDeath(const WebSocket::Data& data);
    
    
    void updateMainState(CCPoint mainPos);
    
    void notifyEject();
    void notifySplite();
    
    void endSplit();
    
    void deleteMainNode(uint32_t nodeid);
    CCPoint calculateBorder(CCPoint pos, uint32_t size);
    
    void updateSceneSize(float siz);
    
    int getMainNodesSize();
    int getMainNodesMass();
    float getCameraScale();
    
    void CheckLayer(tagDif tag);
    void BackToLoginLayer(tagDif tag);
    
    bool OpenWebSocket(const char* ipAddress, const char* port);
    void UpdateScaleByMainNodes();
    void CloseFight();
    // 直接更新尺寸
    void UpdateScaleImmediately(float diff);
    bool IsNeedToUpdateScale();
    void CloseWebNet();
    
    // c->s
    void loginGame();
    void reqServerList();
    void reqServerKey(int netID, int modeID, int ticket_count); // mode 0,1
    void reqShopList();
    void reqBuyItem(int itemID);
    void reqUseItem(int itemID);
    void reqUnequipItem(int itemType);
    void reqUpHero();
    void reqSetFocus(int type, int set, int roleID);
    void reqRole(int roleID);
    void reqFans(int type, int rang1, int rang2, int roleid);
    void reqRanks(int type, int subtype);
    void reqGmInfo(const char* a, int id = 0, int count = 0);
    void reqHotMsg(int roleID);
    void reqGetMsg(int roleID, int rang1, int rang2);
    void reqSendMsg(int roleID, std::string content);
    void reqLikeMsg(int roleID, int msgID, int set); // set 1是like， 0是取消like
    void reqFriendList(int type);
    void reqAddFriend(int roleID, std::string name); // 二选一
    void reqResponseAdd(int flag, int roleID); // flag 1 ok, 0 cancel
    void reqSeasonRank(int roleID);
    void reqGameRecord(int roleID);
    void reqSendPhoto(int slot, std::string dataStr);
    void reqGetPhoto(int roleID);
    void reqSetName(std::string name, std::string passwd, int sex);
    void reqSetSex(int sex);
    void reqSetDesc(std::string desc);
    void reqSetGeo(int province);
    void reqSetIcon(int icon, std::string data);
    void reqGetTickets();
    void reqIcons(std::vector<int> iconList);
    void reqExitFight();
    void reqSign();
    void reqAward();
    
    // common
    void reqSendUIMsg(uint16_t type, std::string str);
    
    // s->c
    void setPlayerInfo(const WebSocket::Data &data);
    void respSyncRole(const WebSocket::Data &data);
    void respServerList(const WebSocket::Data& data);
    void respServerKey(const WebSocket::Data& data);
    void respErrors(const WebSocket::Data& data);
    void respShopList(const WebSocket::Data& data);
    void respHeroUp(const WebSocket::Data& data);
    void respEquipUpdate(const WebSocket::Data& data);
    void respItemUpdate(const WebSocket::Data& data);
    void respRoleInfo(const WebSocket::Data& data);
    void respFans(const WebSocket::Data& data);
    void respRanks(const WebSocket::Data& data);
    void respFightLikes(const WebSocket::Data& data);
    void respHotMsg(const WebSocket::Data& data);
    void respMsgList(const WebSocket::Data& data);
    void respFriendList(const WebSocket::Data& data);
    void respAddFriend(const WebSocket::Data& data);    // 添加好友
    void respAddInvite(const WebSocket::Data& data); // 添加邀请
    void respDelInvite(const WebSocket::Data& data); // 删除邀请
    void respSeasonRank(const WebSocket::Data& data);
    void respGameRecord(const WebSocket::Data& data);
    void respPhotos(const WebSocket::Data& data);
    void respIcons(const WebSocket::Data& data);
    void respAwardList(const WebSocket::Data& data);    //当月奖励列表
    
    void reqReLogin();
    
    // 战斗重连逻辑
    void reLogin(float ft);
    void reOpenSocket();
    void reConnectFightServer(float ft);
    void reSetNetKey(int netID, int netKey);
    void confirmReConnectFighting();
    void cancelReConnectFighting();
    // end
    
    void reRebirth();
    CCPoint getMoveDiff(){return m_diff;}
    
#ifdef EditEXE
    void UpdataWeight(int weight);
#endif
protected:
    void resetUpdateCamera(float ft);
    
private:    
    CCPoint m_diff;

    bool m_isFirstEnter;
    bool m_isSplit;
    
    float  m_initialSpeed;      // json主球的初始速度
    float  m_attenuationSpeed;  // json衰减速度
    float  m_sceneScale;        // json场景缩放比
    
    float  m_scale;
    
    float  m_tempScale;
    float  m_minScale;          // json最小缩放比
    
    CCPoint  m_grid_off_pos;
    
    bool m_isUpdateScale;
    tagDif  m_CurrTag;
    bool m_isFistGetItem;
    
    bool m_isFighting;          // 是否在战斗中
    std::string  m_ipAddress;   // 战斗服的IP地址
    std::string  m_ipPort;      // 战斗服的端口
    int m_netKey;               // 战斗key
    
};


//

class ZhanDouEnd : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    enum
    {
        TAG_NONE,
        TAG_LEFT_BTN,
        TAG_RIGHT_BTN,
        TAG_LOW_LAYER,
        TAG_LEFT_LAYER,
        TAG_RIGHT_LAYER
    };
    ZhanDouEnd();
    ~ZhanDouEnd();
    
    virtual bool init();
    CREATE_FUNC(ZhanDouEnd);
    
    void InitRank();
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
    void resetBtnState();
    void clickLeft(CCObject* pSender);
    void clickRight(CCObject* pSender);
    
    void ReturnBegan(CCObject* pSender);
    
    void setInfos(std::vector<EndGame1> infos, std::vector<Relation2Me1> relas);
    void setLikes(std::vector<EndGame2> infos);
    
    void clickGuanzhu(CCObject* pSender);
    void clickXihuan(CCObject* pSender);
    
    void ShowUserLowInfo();
    void ResSetFans();
    void ResAddFriend();
    std::string getIconString(int roleID, std::vector<icon_data> datas);
    void resIcon(std::vector<icon_data> arr);
private:
    EndGame1 getEndGame1ById(int roleID, std::vector<EndGame1> infos);
    Relation2Me1 getRela1ById(int roleID, std::vector<Relation2Me1> infos);
    EndGame2 getEndGame2ById(int roleID, std::vector<EndGame2> infos);
    
    std::vector<EndGame> mRankVec;
    std::vector<Relation2Me> mRelaVec;
    std::vector<EndGame2> mEndVec;
    bool  infoFlag;
    bool  likeFlag;
    int   mTouchDex;
    int   mCurTouch;
};

//邀请好友界面

class AddFriend : public CCLayer
{
public:
    AddFriend();
    ~AddFriend();
    
    virtual bool init();
    CREATE_FUNC(AddFriend);
    
    void InitFriend(friend_info info);
    void clickOK(CCObject* pSender);
    void clickCancel(CCObject* pSender);
private:
    friend_info m_friend;
};


class UserLow : public CPZLayer
{
public:
    enum
    {
        TAG_NONE,
        TAG_LEFT_BTN,
        TAG_RIGHT_BTN
    };
    UserLow();
    ~UserLow();
    
    virtual bool init();
    CREATE_FUNC(UserLow);

    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    
    void InitLike(EndGame info);
    
    void clickXihuan(CCObject* pSender);
    void clickGuanzhu(CCObject* pSender);
    
    void ResSetFans();
    void ResAddFrieng();
private:
    bool isTouchIn;
    EndGame mTouchInfo;
};

class ReqOpenFight : public CPZLayer
{
public:
    enum
    {
        TAG_NONE,
        TAG_LEFT_BTN,
        TAG_RIGHT_BTN
    };
    ReqOpenFight();
    ~ReqOpenFight();
    
    virtual bool init();
    CREATE_FUNC(ReqOpenFight);
    
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    
    void clickOK(CCObject* pSender);

private:
    bool isTouchIn;
};
#endif /* MainScene_h */
