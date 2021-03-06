﻿#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#pragma once

#include "Singleton.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "spine/Json.h"

USING_NS_CC;
USING_NS_CC_EXT;
#define PormBoxTag  1000

#include "Button.h"
//#include "RichLabel.h"
#include "msgStru.h"
#include "struct.pb.h"

#include "Common.h"
//客户端测试算法控制宏
//#define EditEXE

#define PRI _pri(this)

#define winSize CCDirector::sharedDirector()->getWinSize()

//int monthArray[22] = {0,1,2,3,4,5,6,8,10,12,15,18,21,24,30,36,42,48,54,60,66,72};

inline int _pri(CCNode* _this)
{
    int pri = -128 - _this->getZOrder();
    CCNode* node = _this;
    while(node)
    {
        node=node->getParent();
        if (dynamic_cast<CCLayer*>(node)) {
            pri -= node->getZOrder();
        }
    }
    return pri;
}



class Global : public Singleton<Global>
{
public:
	Global(void);
	~Global(void);	
	const char * getString(const char* en);
    
    
    // 2016-03-05
    void SetGridSize(CCSize size)
    {
        gridSize = size;
    }
    
    CCSize GetGridSize()
    {
        return gridSize;
    }

    void SetGridPos(CCPoint pos)
    {
        gridPos = pos;
    }
    
    CCPoint GetGridPos()
    {
        return gridPos;
    }
    
    void SetMainNodeID(uint32_t nodeid)
    {
        mainID = nodeid;
    }
    
    uint32_t GetMainNodeID()
    {
        return mainID;
    }
    
    void SetMainPos(CCPoint pos)
    {
        mainPos = pos;
    }
    
    CCPoint GetMainPos()
    {
        return mainPos;
    }
    
    void SetCenterPos(CCPoint pos)
    {
        centerPos = pos;
    }
    
    CCPoint GetCenterPos()
    {
        return centerPos;
    }
    
    void SetMainPicIndex(int idx)
    {
        mainPicIndex = idx;
    }
    
    int GetMainPicIndex()
    {
        return mainPicIndex;
    }
    
    void setMainNodeInfo(nodeInfo info)
    {
        mainNodeInfo = info;
    }
    
    nodeInfo getMainNodeInfo()
    {
        return  mainNodeInfo;
    }

    static std::string getDataPath(std::string fileName)
    {
        std::string path = CCFileUtils::sharedFileUtils()->getWritablePath();
        path.append(fileName);
        return path;
    }
    
    void addMianNode(uint32_t nodeid);
    void deleteMainNode(uint32_t nodeid);
    void clearMainNodes();
    bool IsMainNode(uint32_t nodeid);
    int getMainNodeNum();
    std::vector<uint32_t> getMainNodes();
    
    void setJsonImageHead(int ft);
    int getJsonImageHead();
    void setJsonUpCameraSize(int upCamera);
    int getJsonUpCameraSize();
    void setJsonUpCameraScale(float ft);
    float getJsonUpCameraScale();
    
    void setConnectState(bool flag);
    bool getConnectState();
    int  getRand(int maxCount);
    
    std::vector<netInfo> getNetInfos();
    void addNetInfos(netInfo info);
    
    void PlayBackMusci(const char* music);
    void StopBackMusci();
    void PlayEffect(const char* music);
    
    void SetUserInfo(user_info info){m_UserInfo=info;}
    user_info GetUserInfo(){return m_UserInfo;}
    void EquipUpdate(int type,int iteID);
    void HeroLeveUp(int heroID,int heroLeve);
    
    void SetplayerInfo(user_info info){m_PlayerInfo=info;}
    user_info GetPlayerInfo(){return m_PlayerInfo;}
    
    std::string ComPlayerName(std::string mName);
    
    void SetShopItems(std::vector<shop_item> items);
    std::vector<shop_item> GetShopItems();
    void AddItemForBag(int mId,user_bag info);
    user_bag GetBagItem(int mID);
    std::map<int,user_bag> GetBagMap(){return mUserBag;}
    
    void ShowPromBox(const char* msg);
    void ShowPromMoveBox(std::vector<item> vec);
    
    NameColor GetNameColor(std::string& name);
    int GetFightType(){return mCurFightType;}
    void SetFightType(int fight){mCurFightType = fight;}
    std::vector<QianDaoUse> GetQiandao(){return mQianDaoInfo;}
    void SetQiandao(std::vector<QianDaoUse> info){mQianDaoInfo = info;}
private:
    void addInfoInDoc(rapidjson::Document& writedoc,Json* root,rapidjson::Document::AllocatorType& allocator);
    void pareObject(rapidjson::Value& object,Json* root,rapidjson::Document::AllocatorType& allocator);
    void pareArray(rapidjson::Value& array,Json* root,rapidjson::Document::AllocatorType& allocator);
    
    
	CCDictionary *mStringDict;
    
    CCSize gridSize;
    CCPoint gridPos;
    uint32_t  mainID;
    CCPoint mainPos;
    CCPoint centerPos;
    nodeInfo  mainNodeInfo;
    int  mainPicIndex;
    std::vector<uint32_t> m_mainIDs;
    
    int  m_imageHeadSize;
    int  m_perUpCamera;
    float  m_perUpCameraScale;
    
    bool m_isConnecting;
    
    std::vector<netInfo> m_nets;
    user_info m_UserInfo;
    
    user_info m_PlayerInfo;
    std::vector<nameMap> mComName;
    std::vector<shop_item>  shopItems;
    std::map<int,user_bag>  mUserBag;
    std::vector<NameColor> mNameColor;
    std::vector<QianDaoUse> mQianDaoInfo;
    int mCurFightType;
};

class CPZLayer : public CCLayer{
public:
    CPZLayer(void){}
    ~CPZLayer(void){}
    CREATE_FUNC(CPZLayer);
    virtual bool init();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
};

cocos2d::extension::Json* ReadJson(const char* path);

class CCPromBox : public CPZLayer
{
public:
    enum tag
    {
        tag_menu,
    };
    CCPromBox();
    ~CCPromBox();
    virtual bool init();
    CREATE_FUNC(CCPromBox);
    void SetTypeAndValue(const char* msg);
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
private:
    bool isTouchIn;
};

class CCPromMoveBox : public CPZLayer
{
public:
    enum tag
    {
        tag_menu,
    };
    CCPromMoveBox();
    ~CCPromMoveBox();
    virtual bool init();
    CREATE_FUNC(CCPromMoveBox);
    void SetTypeAndValue(std::vector<item> vec);
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
private:
    bool isTouchIn;
};
#endif
