//
//  ShopLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/4/10.
//
//

#ifndef ShopLayer_h
#define ShopLayer_h

#include "Global.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class ShopLayerBase : public CCLayer
{
public:
    enum S_TAG
    {
        TAG_NONE,
        TAG_WAIGUAN,
        TAG_HERO,
        TAG_JINHE,
        TAG_HDBS,
        TAG_HECHENG,
        TAG_CAILIAO,
        TAG_TONGQIAN_LAB,
        TAG_YUANBAO_LAB
    };
    
    ShopLayerBase();
    ~ShopLayerBase();
    
    virtual bool init();
    CREATE_FUNC(ShopLayerBase);
    
    void initUI();
    void resetBtnState();
    
    void WaiGuanClick(CCObject* pSender);
    void HeroClick(CCObject* pSender);
    void JinheClick(CCObject* pSender);
    void HdbsClick(CCObject* pSender);
    
    void BackClick(CCObject* pSender);
    void RushLab();
    S_TAG   GetCurrentTag()
    {
        return m_shopTag;
    }
    
private:
    Button* waiguanBtn;
    Button* heroBtn;
    Button* jinheBtn;
    Button* hdbbBtn;
    
    S_TAG   m_shopTag;
};



// 外观
class ShopLayerWaiguan : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    enum weiguan_tag
    {
        guanghuan_tag,
        baozi_tag,
        canyin_tag
    };
    
    ShopLayerWaiguan();
    ~ShopLayerWaiguan();
    
    virtual bool init();
    CREATE_FUNC(ShopLayerWaiguan);
    
    void GuangHuanClick(CCObject* pSender);
    void BaoziClick(CCObject* pSender);
    void CanyinClick(CCObject* pSender);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    
    void initTableView(float ft);
    
    void resetBtnState();
    void rushTabel();
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
private:
    Button* guanhuan;
    Button* baozi;
    Button* canyin;
    
    CCSize  childSize;
    
    weiguan_tag m_tag;
    
    CCTableView* tableView;
    
    std::vector<ChildItem> guanghuans;
    std::vector<ChildItem> baozis;
    std::vector<ChildItem> canyins;
};
// 购买界面
class BuyItemLayer : public CPZLayer
{
public:
    BuyItemLayer();
    ~BuyItemLayer();
    
    virtual bool init();
    CREATE_FUNC(BuyItemLayer);
    void BuyClick(CCObject* pSender);
    void UseClick(CCObject* pSender);
    void XiexiaClick(CCObject* pSender);
    
    void InitItem(ChildItem ite,int itemType);
    
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    
private:
    ChildItem mItem;
    bool isTouchIn;
};
// 英雄
class ShopLayerHero : public CCLayer
{
public:
    ShopLayerHero();
    ~ShopLayerHero();
    
    virtual bool init();
    CREATE_FUNC(ShopLayerHero);
    
    void HechengClick(CCObject* pSender);
    void BagClick(CCObject* pSender);
    
    void InitShenshou();
    
    void helpClick(CCObject* pSender);
    void LookClick(CCObject* pSender);
    
private:
    CCSize childSize;
};

// 材料包裹
class CaiLiaoBag : public CPZLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    CaiLiaoBag();
    ~CaiLiaoBag();
    
    virtual bool init();
    CREATE_FUNC(CaiLiaoBag);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    
    
    //virtual void registerWithTouchDispatcher(){
        //CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,PRI,true);
    //}
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    
    //virtual void ccTouchesBegan(CCSet* pTouches,CCEvent* pEvent);
    //virtual void ccTouchesMoved(CCSet* pTouches,CCEvent* pEvent);
    //virtual void ccTouchesEnded(CCSet* pTouches,CCEvent* pEvent);
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
private:
    std::vector<itemInfo> hInfo;
    bool isTouchIn;
};

// 合成
class HeCheng : public CPZLayer
{
public:
    HeCheng();
    ~HeCheng();
    
    virtual bool init();
    CREATE_FUNC(HeCheng);
    void BackClick(CCObject* pSender);
    void HechengClick(CCObject* pSender);
    
    void InitItem();
    
private:
    std::vector<itemInfo> hInfo;
    int itemMax;
    int starNum;
};
// 锦盒
class ShopLayerJinhe : public CCLayer
{
public:
    ShopLayerJinhe();
    ~ShopLayerJinhe();
    
    virtual bool init();
    CREATE_FUNC(ShopLayerJinhe);
    
    void OpenMuClick(CCObject* pSender);
    void OpenHaoClick(CCObject* pSender);
    
    void rushLab();
private:
    CCSize childSize;
};

// 获取元宝
class ShopLayerHuoqu : public CCLayer
{
public:
    ShopLayerHuoqu();
    ~ShopLayerHuoqu();
    
    virtual bool init();
    CREATE_FUNC(ShopLayerHuoqu);
    
    void LingquClick(CCObject* pSender);
    void copyClick(CCObject* pSender);
    void saveClick(CCObject* pSender);
    
private:
    CCSize childSize;
};



#endif /* ShopLayer_h */
