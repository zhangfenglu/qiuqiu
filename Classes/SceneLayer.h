//
//  SceneLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/2/25.
//
//

#ifndef SceneLayer_h
#define SceneLayer_h

#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "WebSocket.h"
USING_NS_CC;
USING_NS_CC_EXT;

#include "Global.h"

class SceneLayer : public CCLayer
{
public:
    enum tagDef
    {
        TAG_NONE,
        TAG_MAIN,
        TAG_MAX,
        TAG_LIFELAYER,
        TAG_FUHUO
    };
    
    SceneLayer();
    ~SceneLayer();
    
    virtual bool init();
    CREATE_FUNC(SceneLayer);

//    virtual void ccTouchesBegan(CCSet* pTouch, CCEvent* pEvent);
//    virtual void ccTouchesMoved(CCSet* pTouch, CCEvent* pEvent);
//    virtual void ccTouchesEnded(CCSet* pTouch, CCEvent* pEvent);
 
    void setJoystickPos(CCPoint pos);
    void updateJoystickPos(CCPoint diff);
    void moveEndJoystick();
    
    
    void addSelfNode(nodeInfo info);
    void updateMainInfo(nodeInfo info);
    
    CCPoint GetJoyDiff();
    
    void clickPopBtn(CCObject* pSender);
    void clickSplitBtn(CCObject* pSender);
    
    void addEndUI(const char* lab,int sec);
    
    void deleteMainNode(uint32_t nodeID);
    void updateSceneScale(float scale);
    
    void updateWeightLabel(int mass);
    
    void updateFightRanking(std::vector<fight_rank> ranks);
    
    // 设置倒计时
    void setDuration(int duration);
    void updateDuration(float ft);
    void setDurationText(int duration);
    void ViewLife(int count);
private:
    CCPoint m_joystickPos;
    
    CCLabelTTF* m_weight;
    
    int m_duration;
};

class ZhanDouPaiMing : public CCLayer
{
public:
    ZhanDouPaiMing();
    ~ZhanDouPaiMing();
    
    virtual bool init();
    void initLabels();
    CREATE_FUNC(ZhanDouPaiMing);
    
    void updatpaiming(std::vector<fight_rank> ranks);
    void clearLabels();
private:
};

class ZhanDouFuhuo : public CPZLayer
{
public:
    ZhanDouFuhuo();
    ~ZhanDouFuhuo();
    
    virtual bool init();
    void initLabels();
    CREATE_FUNC(ZhanDouFuhuo);
    void clickEndBtn(CCObject* pSender);
    void clickFuhuo(CCObject* pSender);
    void setLab(const char* lab,int sec);
    void updatTime(float ft);
private:
    int mDaojishi;
};



#endif /* SceneLayer_h */
