﻿#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "cocos2d.h"
//#include "BaseStruct.h"
USING_NS_CC;

// typedef  void (*OnClickFunc)();
// void onClick();

class Button : public CCNode, public CCTargetedTouchDelegate
{
public:
	Button() : mClickCallback(NULL) , clickObj(NULL)
		,isCanTouch(true)
		,isEffecttype(false)
		, mScale(1)
		,mIsLock(false)
		,mLockMode(false)
		,mIsBig(false)
		,mIsSelect(false)
		,m_bIsSpecialEffect(false)
		,mLockDt(0.65f)
		,m_bPressChange(false)
		,m_bPressEnable(false)
        ,mIsCanTouchMoreTime(false)
		,pressbg(NULL)
		,bg(NULL){}
	virtual ~Button();

	enum eBtnTag{
		eBaseNodeTag = 101,
		eUpNodeTag = 102,
	};

	static Button* createBtn(std::string iconStr);
	static Button* createBtnWithSpriteFrameName(std::string iconStr,bool bPlist = true);
	static Button* createBtn(std::string baseStr,std::string upStr);
	//创建两个叠加精灵按钮
	static Button* createBtnWith2SpriteFrameName(std::string baseStr,std::string upStr, bool bPlist = true);
	// add by sanmor 创建可以显示数字的按钮
	static Button *createBtn(std::string baseStr,std::string upStr,std::string moneyIcon,const char* numStr);
	//创建两个特效的按钮
	static Button* createEffectBtn(const char* baseEffectXmls,const char* baseFirstFrameName,const char* baseAnimateName,const char* upEffectXmls,const char* upFirstFrameName,const char* upAnimateName,const char* upWords);
	//创建昆仑秘境专用按钮kk
	static Button* createHomeBtn(std::string baseStr,std::string upStr,std::string wordIcon);
	static Button* createOtherBtn(std::string baseName, std::string name1, std::string name2, std::string name3);


	static Button* createBtn(CCNode* baseNode,CCNode* upNode);

	

	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	void onEnter();
	void onExit();
	virtual CCRect rect();

	bool containsTouchLocation(CCTouch* pTouch);
	void click(CCNode *node);
	void setOnClickCallback(SEL_CallFuncO cb, CCObject * obj){ mClickCallback = cb; clickObj = obj;/*clickObj->retain();*/}
	//设置是否显示
	void setIsShow(bool  isShow);
	void setPressIcon(std::string iconStr,bool bPlist);
	void setPressEnable(bool b);
	void setPressIconShow(bool b);
	bool getPressIconShow(){return m_bPressChange;}

	void SetSelect(bool bl);
	void setHandlerPriority(int nHandler) {m_HandlerPriority = nHandler;}
	int getHandlerPriority(){return m_HandlerPriority;};

	CC_SYNTHESIZE(int,m_nCurClickedIndex,CurClickedIndex);

	
	bool init(std::string iconStr);
	bool init(std::string baseStr,std::string upStr);
	bool init(std::string baseStr,std::string upStr,std::string moneyIcon,const char* numStr);
	bool initOther(std::string baseName, std::string name1, std::string name2, std::string name3);
	bool initWithFrameName(std::string iconStr,bool bPlist = true);
	bool initWith2FrameName(std::string baseStr,std::string upStr,bool bPlist = true);
	bool init(std::string baseStr,std::string upStr,std::string wordIcon);
	//创建两个特效的按钮
	bool init(const char* baseEffectXmls,const char* baseFirstFrameName,const char* baseAnimateName,const char* upEffectXmls,const char* upFirstFrameName,const char* upAnimateName,const char* upWords);
	
	void setBgScale(float scale) { mScale = scale; bg->setScale(mScale);}
	void setClickEndBig(bool isBig){mIsBig = isBig;}

	
	bool init(CCNode* baseNode,CCNode* upNode);
	//设置锁住模式
	CC_SYNTHESIZE(bool,mLockMode,LockMode);
	//设置锁住时间
	CC_SYNTHESIZE(float,mLockDt,LockDt);
	//设置是否可点击
	//CC_SYNTHESIZE(bool,isCanTouch,IsCanTouch);
    
    CC_SYNTHESIZE(bool,mIsCanTouchMoreTime,IsCanTouchMoreTime);
	//设置索引值
	CC_SYNTHESIZE(int,nIndex,IndexNum);

	bool isCanTouch;
	bool getIsCanTouch(){return isCanTouch;}
	void setIsCanTouch(bool bl);

	//是否为特殊音效
	CC_SYNTHESIZE(bool ,m_bIsSpecialEffect,IsSpecialEffect);

	void setBtnUnclick();
    
    void TouchMoreTime(float ft);
protected:
	CCSprite *bg;
	CCSprite *pressbg;
	float mScale;
	int m_HandlerPriority;
	bool mIsLock;
	bool m_bPressChange;
	bool m_bPressEnable;

private:
	SEL_CallFuncO mClickCallback;
	CCObject *clickObj;

	const char* mbaseEffectXmls;
	const char* mupEffectXmls;
	bool isEffecttype;


	void loadLock(float dt);
	void lockState();
	void unLockState();
	CCSprite* loadSp;//锁住图标

	bool mIsBig;
	bool mIsSelect;
	/*bool isCanTouch;*/
	
	
};


#endif