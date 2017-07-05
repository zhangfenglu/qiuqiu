//
//  LoginScene.h
//  qiuFight
//
//  Created by 张跃东 on 16/3/4.
//
//

#ifndef LoginScene_h
#define LoginScene_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "WebSocket.h"

#include "DropDownListLayer.h"
#include "LoginLayer1.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LoginLayer : public CCLayer, public CCEditBoxDelegate
{
public:
    enum
    {
        TAG_SHENGCUN,
        TAG_QIANDAO,
        TAG_FUWUQILAB
    };
    LoginLayer(){}
    ~LoginLayer(){}
    
    virtual bool init();
    CREATE_FUNC(LoginLayer);
    
    void initUI();
    void initLoginLayer();
    
    void NextScene(CCObject* pSender);
    void ResetName(CCObject* pSender);
    void ShowGM(CCObject* pSender);
    void ShowQiandao(CCObject* pSender);
    void PersonCenter(CCObject* pSender);   // 个人中心
    void RelationClick(CCObject* pSender);  // 关系
    void RankClick(CCObject* pSender);      // 排行
    void MagicClick(CCObject* pSender);     // 魔法屋
    void HelpClick(CCObject* pSender);      // 帮助
    void FriendClick(CCObject* pSender);    // 找朋友
    void TeamClick(CCObject* pSender);      // 团队模式
    void LiveClick(CCObject* pSender);      // 生产模式
    void ShezhiClick(CCObject* pSender);    // 设置
    void HeadClick(cocos2d::CCObject *pSender);   //头像
    
    virtual void editBoxReturn(cocos2d::extension::CCEditBox* editBox);
    
    void RespMagicClick();
    
    void delayEnter(float ft);
    void InitHeadInfo();
    void initLogin(float ft);
    
    void updateNetInfos();
    void setNetKey(int key);
    void SetNameOK();
    
    void relogin();
    void rushmenpiao();
    void rushqiandao();
    
    netInfo getNetInfo();
private:
    //DropDownListLayer* dropLayer ;
    bool m_isLogin;
    int net_key;
};

//////
class GMScene : public CCLayer , public CCEditBoxDelegate
{
public:
    
    GMScene(){}
    ~GMScene(){}
    
    virtual bool init();
    CREATE_FUNC(GMScene);
    
    
    virtual void editBoxReturn(cocos2d::extension::CCEditBox* editBox);
    void Back(CCObject* pSender);
    void ok(CCObject* pSender);
private:
    
};
// 生存模式
class ShengCun : public CPZLayer
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_Life,
        TAG_MenpiaoXiaohao,
        TAG_BtnJian,
        TAG_BtnJia,
        TAG_Xin1,
        TAG_Xin2,
        TAG_Xin3,
        TAG_MENPIAOLAB,
    };
    ShengCun();
    ~ShengCun();
    
    virtual bool init();
    CREATE_FUNC(ShengCun);
    
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    
    void AddLife(CCObject* pSender);      // 加生命
    void SubLife(CCObject* pSender);      // 减生命
    void AddMenPiao(CCObject* pSender);
    void StartGame(CCObject* pSender);
    void rushmenpiao();
    
    
    void delayEnter(float ft);
private:
    bool isTouchIn;
    
    int  menpiaoNum;
    int  menpiaoxiaohao;
    int  lifeNum;
};

// 生存模式
class LingRuchangQuan : public CPZLayer
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_Ruchangquan,
        TAG_Jinbi,
        TAG_MENPIAOLAB,
        TAG_MONEYLAB,
        TAG_LINQUCISHU
    };
    LingRuchangQuan();
    ~LingRuchangQuan();
    
    virtual bool init();
    CREATE_FUNC(LingRuchangQuan);
    
    void BackClick(CCObject* pSender);
    void FreeLing(CCObject* pSender);
    void GouMai(CCObject* pSender);
    void rushmenpiao();
private:
    bool isTouchIn;
    
    int  menpiaoNum;
    int  money;
};

// 找朋友
class FindFriend : public CPZLayer, public CCEditBoxDelegate
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_FindFriend,
        TAG_Fujinderen,
        TAG_PYLayer,
        TAG_FuJinLayer
    };
    FindFriend();
    ~FindFriend();
    
    virtual bool init();
    CREATE_FUNC(FindFriend);
    
    void Saoyisao(CCObject* pSender);
    void Leida(CCObject* pSender);
    void Yaoyiyao(CCObject* pSender);
    
    void Back(CCObject* pSender);
    
    void Zhaopengyou(CCObject* pSender);
    void Fujinderen(CCObject* pSender);
    
    void InitZhaoPYUI();
    void resetBtnState();
    
    virtual void editBoxReturn(cocos2d::extension::CCEditBox* editBox);
private:
    PC_TAG m_currentTag;
};

// 设置
class SheZhi : public CPZLayer, public CCEditBoxDelegate
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_FindFriend,
        TAG_Fujinderen,
        TAG_SHEZHI,
        TAG_ZHUCE,
        TAG_USERSHEZHI,
        TAG_XUANZENAN,
        TAG_XUANZENV
    };
    SheZhi();
    ~SheZhi();
    
    virtual bool init();
    CREATE_FUNC(SheZhi);
    
    void resetBtnState();
    void InitShezhiUI();
    void InitZhuceUI();
    void InitUserShezhi();
    void YouxiShezhi(CCObject* pSender);
    void Yonghuxinxi(CCObject* pSender);
    void Yinyue(CCObject* pSender);
    void Yinxiao(CCObject* pSender);
    void tuanzhanyaoqing(CCObject* pSender);
    void tuqiushezhi(CCObject* pSender);
    
    virtual void editBoxReturn(cocos2d::extension::CCEditBox* editBox);
    
    void xuanzenan(CCObject* pSender);
    void xuanzenv(CCObject* pSender);
    void Back(CCObject* pSender);
    void baocunBtn(CCObject* pSender);
    
    void SetNameOK();
private:
    PC_TAG m_currentTag;
    int  mUserSex;
};

// 签到
class Qiandao : public CPZLayer
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_QIANDAOBTN,
        TAG_INFOLAYER
    };
    Qiandao();
    ~Qiandao();
    
    virtual bool init();
    CREATE_FUNC(Qiandao);
    void InitInfo();
    void QiandaoClick(CCObject* pSender);
    void Back(CCObject* pSender);
    void UpdateSignInfos();
    void RushInfo();
private:
    std::vector<QianDao> mInfo;
};
#endif /* LoginScene_h */
