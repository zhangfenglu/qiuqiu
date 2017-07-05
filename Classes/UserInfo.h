//
//  PersonCenterLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/4/1.
//
//

#ifndef UserInfo_h
#define UserInfo_h

#include "Global.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "WebSocketLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;

// 公用底层
class UserInfo : public CCLayer
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_SHOUYE,
        TAG_ZHAOPIAN,
        TAG_YOUXI,
        TAG_ZHANDUI,
        TAG_LIUYAN,
        TAG_XIHUAN,
        TAG_GERENRONGYU,
        TAG_BISAIJILU,
        
        TAG_SHOUYE_BTN,
        TAG_ZHAOPIAN_BTN,
        TAG_YOUXI_BTN,
        TAG_ZHANDUI_BTN,
        TAG_LIUYAN_BTN
    };
    
    UserInfo();
    ~UserInfo();
    
    virtual bool init();
    CREATE_FUNC(UserInfo);
    
    void initUI();
    void resetBtnState();
    
    void ShouyeClick(CCObject* pSender);
    void ZhaopianClick(CCObject* pSender);
    void YouxiClick(CCObject* pSender);
    void ZhanduiClick(CCObject* pSender);
    
    void LiuyanClick(CCObject* pSender);
    void BackClick(CCObject* pSender);
    void ShowXihuan(bool isShow);
    void ShowGame(int idex);
    void respFans(const WebSocket::Data& data);
    
    void respHotLiuyan(const WebSocket::Data& data);
    void respLiuyan(const WebSocket::Data& data);
    
    void resSeasonRank(const WebSocket::Data& data);
    void resGameRecode(const WebSocket::Data& data);
    void resHeadImg(int count);
    void resPhoto(std::vector<std::string> arr);
    void setHeadIcon();
private:
    PC_TAG m_currentTag;
    std::vector<TestAtt> fanses;
};

// 个人资料
class FirstPage : public CCLayer
{
public:
    enum
    {
        TAG_NONE,
        TAG_XIHUANBTN,
        TAG_LUYINBTN,
        TAG_DIQUBTN,
        TAG_TOUXIANGBTN,
        TAG_HEADCHOSE,
        TAG_HEADICON
    };
    FirstPage();
    ~FirstPage();
    
    virtual bool init();
    CREATE_FUNC(FirstPage);
    
    void ChangeHead(CCObject* pSender);
    
    void HeadClick(cocos2d::CCObject *pSender);   //头像
    void LuyinClick(cocos2d::CCObject *pSender);   //录音
    
    void XihuanClick(cocos2d::CCObject *pSender);   //喜欢
    
    void DiquClick(cocos2d::CCObject *pSender);   //选择地区
    
    void SetBtnToTouch();
    void InitFensi(std::vector<TestAtt> info);
    void SenMSG(float ft);
    void resHeadImg(int count);
    void setHeadIcon();
};

// 设置
class HeadIconChose : public CPZLayer
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_FindFriend,
        TAG_Fujinderen,
        TAG_SHEZHI,
        TAG_ZHUCE,
        TAG_XUANZENAN,
        TAG_XUANZENV,
    };
    HeadIconChose();
    ~HeadIconChose();
    
    virtual bool init();
    CREATE_FUNC(HeadIconChose);
    
    void resetBtnState();
    void InitShezhiUI();
    void InitZhuceUI();
    
    void YouxiShezhi(CCObject* pSender);
    void Yonghuxinxi(CCObject* pSender);
    void Back(CCObject* pSender);
    void SenMSG(float ft);
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    void SetParentTag(int tag){mParent = tag;}
    void resHeadImg(int count);
    void reshHead();
private:
    PC_TAG m_currentTag;
    int mParent;
};

// 普通头像
class NormalHeadIcon : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:

    NormalHeadIcon();
    ~NormalHeadIcon();
    
    virtual bool init();
    CREATE_FUNC(NormalHeadIcon);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    void rushHead();
    
private:
    
};

// 照片头像
class PhotoHeadIcon : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    
    PhotoHeadIcon();
    ~PhotoHeadIcon();
    
    virtual bool init();
    CREATE_FUNC(PhotoHeadIcon);
    void InitTabelView(int count);
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
    void rushHead();
private:
    int mPhotoNum;
};

// 荣誉头环
class HeadRing : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    
    HeadRing();
    ~HeadRing();
    
    virtual bool init();
    CREATE_FUNC(HeadRing);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
    
private:
    
};

// 选择地区
class HeadRingInfo : public CPZLayer
{
public:
    HeadRingInfo();
    ~HeadRingInfo();
    
    virtual bool init();
    CREATE_FUNC(HeadRingInfo);
    
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    void InitItemInfo(item itemInfo);
    
    void UseClick(CCObject* pSender);
    void XiexiaClick(CCObject* pSender);
private:
    item mCurItem;
    bool isTouchIn;
};
// 选择地区
class XuanzeDiqu : public CPZLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    XuanzeDiqu();
    ~XuanzeDiqu();
    
    virtual bool init();
    CREATE_FUNC(XuanzeDiqu);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
private:
    std::map<int,std::string> hInfo;
    bool isTouchIn;
};
// 喜欢
class XiHuan : public CCLayer
{
public:
    XiHuan();
    ~XiHuan();
    
    virtual bool init();
    CREATE_FUNC(XiHuan);
    
    void XihuanClick(cocos2d::CCObject *pSender);   //喜欢
    
    void InitInfo(std::vector<TestAtt> info);
    
    //void SetXihuan(std::vector<xihuanInfo> info){m_xihuaninfo = info;}
    //std::vector<xihuanInfo> m_xihuaninfo;
};

// 照片
class ZhaoPian : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    ZhaoPian();
    ~ZhaoPian();
    
    virtual bool init();
    CREATE_FUNC(ZhaoPian);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    void InitTabelView(std::vector<std::string> arr);
    void SenMSG(float ft);
private:
    int m_spHeadNum;
    bool m_isShowAdd;
    std::vector<std::string> mPotoArr;
};

// 照片
class ZhaoPianView : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    ZhaoPianView();
    ~ZhaoPianView();
    
    virtual bool init();
    CREATE_FUNC(ZhaoPianView);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    void InitTabelView(std::string arr,int mCount);
    
private:
    std::string mIcon;
};

// 游戏数据
class GameInfo : public CCLayer
{
public:
    enum
    {
        TAG_NONE,
        TAG_GERENRONGYUBTN,
        TAG_BISAIJILUBTN,
        TAG_HEADCHOSE,
        TAG_HEADBTN,
        TAG_HEADICON
    };
    GameInfo();
    ~GameInfo();
    
    virtual bool init();
    CREATE_FUNC(GameInfo);
    
    void GerenClick(cocos2d::CCObject *pSender);
    void BisaiClick(cocos2d::CCObject *pSender);
    void HeadClick(cocos2d::CCObject *pSender);   //头像
    void SetBtnToTouch();
    void resHeadImg(int count);
    void setHeadIcon();
private:
    int m_spHeadNum;
};

// 个人荣誉
class GerenRongYu : public CCLayer
{
public:
    GerenRongYu();
    ~GerenRongYu();
    
    virtual bool init();
    CREATE_FUNC(GerenRongYu);
    void InitRongyu(std::vector<season_rank> arr);
    void ShowUI(float fx,season_rank info);
    void GameClick(cocos2d::CCObject *pSender);
    void BisaiClick(cocos2d::CCObject *pSender);
    void SenMSG(float ft);
private:
    int m_spHeadNum;
};

// 比赛
class BisaiJilu : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    BisaiJilu();
    ~BisaiJilu();
    
    virtual bool init();
    CREATE_FUNC(BisaiJilu);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    void GameClick(cocos2d::CCObject *pSender);
    void GerenClick(cocos2d::CCObject *pSender);
    void SenMSG(float ft);
    void InitBisai(std::vector<bisaiInfo> arr);
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
private:
    //CCTableView* tableView;
    std::vector<bisaiInfo>  infos;
};


// 个人荣誉
class ZhanDui : public CCLayer
{
public:
    ZhanDui();
    ~ZhanDui();
    
    virtual bool init();
    CREATE_FUNC(ZhanDui);
private:
    int m_spHeadNum;
};


// 留言
class LiuYan : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate, public CCEditBoxDelegate
{
public:
    LiuYan();
    ~LiuYan();
    
    virtual bool init();
    CREATE_FUNC(LiuYan);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    //virtual CCSize cellSizeForTable(CCTableView* table);
    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    void FasongClick(cocos2d::CCObject *pSender);
    void ShuaxinClick(cocos2d::CCObject *pSender);
    virtual void editBoxReturn(cocos2d::extension::CCEditBox* editBox);
    
    void InitHotLiuyan(std::vector<LiuyanInfo> hotArr);
    void InitLiuyan(std::vector<LiuyanInfo> hotArr);
    
    void SenMSG(float ft);
    
    void HotZanClick(cocos2d::CCObject *pSender);
    void HotJubaoClick(cocos2d::CCObject *pSender);
    void ZanClick(cocos2d::CCObject *pSender);
    void JubaoClick(cocos2d::CCObject *pSender);
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
private:
    //CCTableView* tableView;
    std::vector<LiuyanInfo>  infos;
    std::vector<LiuyanInfo>  hotInfo;
    int m_curpage;
};

#endif /* PersonCenterLayer_h */
