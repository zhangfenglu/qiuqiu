//
//  RankingLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/4/9.
//
//

#ifndef RankingLayer_h
#define RankingLayer_h

#include "Global.h"
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

#include "WebSocketLayer.h"

// test
struct TestRank
{
    int         m_id;
    int         m_sex;
    int         m_iconDex;
    int         m_rank;
    int         m_duanwei;
    int         m_xing;
    std::string m_name;
    std::string m_zjrs;      //最近获得人数
    std::string m_zcbs;      //总崇拜数
    std::string m_zjymz;     //最近仰慕者数
    std::string m_zymz;      //总仰慕数
    std::string m_zjhds;     //最近获得珍珠数
    std::string m_hdzs;      //总获得数
    std::string m_zjjss;     //最近击杀数
    std::string m_zjss;      //总击杀数
    std::string m_iconStr;   //icon照片
};

class RankingLayerBase : public CPZLayer
{
public:
    enum R_TAG
    {
        TAG_NONE,
        TAG_JHDW,
        TAG_CBZ,
        TAG_YMZ,
        TAG_XZZ,
        TAG_JSS
    };
    
    RankingLayerBase();
    ~RankingLayerBase();
    
    virtual bool init();
    CREATE_FUNC(RankingLayerBase);
    
    void initUI();
    void resetBtnState();
    
    void JhdwClick(CCObject* pSender);
    void CbzClick(CCObject* pSender);
    void YmzClick(CCObject* pSender);
    void XzzClick(CCObject* pSender);
    void JssClick(CCObject* pSender);
    
    void BackClick(CCObject* pSender);
    
    R_TAG   GetCurrentTag()
    {
        return m_rankTag;
    }
    
    void respRanks(const WebSocket::Data &data);
    void SenMSG(float ft);
    
    void respRankIcons(std::vector<icon_data> icons);
private:
    Button* jhdwBtn;
    Button* cbzBtn;
    Button* ymzBtn;
    Button* xzzBtn;
    Button* jssBtn;
    
    R_TAG   m_rankTag;
};


class RankingLayerChild : public CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
public:
    RankingLayerChild();
    ~RankingLayerChild();
    
    
    virtual bool init();
    CREATE_FUNC(RankingLayerChild);
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idex);
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    
    void setRanks(std::vector<TestRank> ranks);
    void updateRanks(std::vector<icon_data> datas);
    std::string getIconString(int roleID, std::vector<icon_data> datas);
    void initTableView();
protected:
    CCSize getTableSize();
    void createTableViewCell(CCNode* cell, CCTableView* table, int idex);
    
    void clickBtn1(CCObject* pSender);
    void clickBtn2(CCObject* pSender);
    void clickBtn3(CCObject* pSender);
    
    void resetBtnState();
    
private:
    //CCTableView* tableView;
    std::vector<TestRank> m_atts;
    RankingLayerBase::R_TAG m_tag;
    
    Button* btn1;
    Button* btn2;
    Button* btn3;
    
    int current_click_index;
};


#endif /* RankingLayer_h */
