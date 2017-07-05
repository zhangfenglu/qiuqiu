//
//  PersonCenterLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/4/1.
//
//

#ifndef PersonCenterLayer_h
#define PersonCenterLayer_h

#include "Global.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

// 公用底层
class PersonCenterBase : public CCLayer
{
public:
    enum PC_TAG
    {
        TAG_NONE,
        TAG_ZILIAO,
        TAG_XINXI,
        TAG_RONGYU,
        TAG_BISAI
    };
    
    PersonCenterBase();
    ~PersonCenterBase();
    
    virtual bool init();
    CREATE_FUNC(PersonCenterBase);
    
    void initUI();
    void resetBtnState();
    
    void ZiliaoClick(CCObject* pSender);
    void RongyuClick(CCObject* pSender);
    void BisaiClick(CCObject* pSender);
    void XinxiClick(CCObject* pSender);
    
    void SetClick(CCObject* pSender);
    void BackClick(CCObject* pSender);
    
private:
    PC_TAG m_currentTag;
    Button* ziliao;
    Button* xinxi;
    Button* rongyu;
    Button* bisai;
};

// 个人资料
class PersonInfo : public CCLayer
{
public:
    PersonInfo();
    ~PersonInfo();
    
    virtual bool init();
    CREATE_FUNC(PersonInfo);
    
    void ChangeHead(CCObject* pSender);
};

// 个人信息
class PersonXinxi : public CCLayer
{
public:
    PersonXinxi();
    ~PersonXinxi();
    
    virtual bool init();
    CREATE_FUNC(PersonXinxi);
    
    void ChangePlayer(CCObject* pSender);
    void RegisterClick(CCObject* pSender);
};

// 个人荣誉
class PersonRongyu : public CCLayer
{
public:
    PersonRongyu();
    ~PersonRongyu();
    
    virtual bool init();
    CREATE_FUNC(PersonRongyu);
};

// 比赛
class PersonCenterLayer : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    PersonCenterLayer();
    ~PersonCenterLayer();
    
    virtual bool init();
    CREATE_FUNC(PersonCenterLayer);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
private:
    //CCTableView* tableView;
    std::vector<bisaiInfo>  infos;
};



#endif /* PersonCenterLayer_h */
