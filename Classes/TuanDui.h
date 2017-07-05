//
//  RelationShipLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/4/8.
//
//

#ifndef TuanDui_h
#define TuanDui_h

#include "Global.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

#include "WebSocketLayer.h"

// 公用底层
class TuanDui : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    enum RS_TAG
    {
        TAG_NONE,
        TAG_ATTENTION,
        TAG_FRIEND,
        TAG_ENEMY,
        TAG_BLACK
    };
    
    TuanDui();
    ~TuanDui();
    
    virtual bool init();
    CREATE_FUNC(TuanDui);
    
    void initUI();

    void BackClick(CCObject* pSender);
  
    void SenMSG(float ft);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view){}
    virtual void scrollViewDidZoom(CCScrollView* view){}
    
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
    void StartGame(CCObject* pSender);
    void Yaoqing(CCObject* pSender);
    
    void ReSetTabelView();
private:
    std::vector<TestAtt> m_atts;
};


// 公用底层
class YaoqingList : public CCLayer
{
public:
    enum RS_TAG
    {
        TAG_NONE,
        TAG_ATTENTION,
        TAG_FRIEND,
        TAG_ENEMY,
        TAG_BLACK
    };
    
    YaoqingList();
    ~YaoqingList();
    
    virtual bool init();
    CREATE_FUNC(YaoqingList);
    
    void initUI();
    void resetBtnState();
    
    void AttentionClick(CCObject* pSender);
    void FriendClick(CCObject* pSender);
    void EnemyClick(CCObject* pSender);
    void BlackClick(CCObject* pSender);
    
    void PrePageClick(CCObject* pSender);
    void NextPageClick(CCObject* pSender);
    void BackClick(CCObject* pSender);
    
    RS_TAG GetCurrentTag()
    {
        return m_currentTag;
    }
    void respFans(const WebSocket::Data& data);
    void resIcon(std::vector<icon_data> icons);
    void respFriends(const WebSocket::Data& data);
    
    void SenMSG(float ft);
public:
    RS_TAG      m_currentTag;
    Button*     m_attention;
    Button*     m_friend;
    Button*     m_enemy;
    Button*     m_black;
};
// 关注
class TeamList : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    TeamList();
    ~TeamList();
    
    virtual bool init();
    CREATE_FUNC(TeamList);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    
    void setLists(std::vector<TestAtt> ranks)
    {
        m_atts.clear();
        m_atts = ranks;
    }
    void initTableView(std::vector<TestAtt> fanses);
    void updateLists(std::vector<icon_data> datas);
    std::string getIconString(int roleID, std::vector<icon_data>datas);
    
    void SendYaoqing(CCObject* pSender);
    void Xuanze(CCObject* pSender);
    void XuanzeAll(CCObject* pSender);
    
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
private:
    //CCTableView* tableView;
    std::vector<TestAtt> m_atts;
};

// 粉丝


#endif /* RelationShipLayer_h */
