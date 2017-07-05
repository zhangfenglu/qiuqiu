#include "Button.h"
#include "Global.h"

Button::~Button()
{
	if (isEffecttype)
	{
		
	}
}


Button* Button::createBtn(CCNode* baseNode,CCNode* upNode)
{	
	Button* btn = new Button;
	if (btn && btn->init(baseNode,upNode))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}

Button* Button::createBtn(std::string iconStr)
{
	
	Button *btn = new Button;
	if (btn && btn->init(iconStr))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}

Button* Button::createBtnWithSpriteFrameName(std::string iconStr,bool bPlist)
{
	
	Button *btn = new Button ;
	if (btn && btn->initWithFrameName(iconStr,bPlist))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}


Button* Button::createBtnWith2SpriteFrameName(std::string baseStr,std::string upStr,bool bPlist)
{
	
	Button* btn = new Button;
	if (btn && btn->initWith2FrameName(baseStr,upStr, bPlist))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}

Button* Button::createBtn(std::string baseStr,std::string upStr)
{
	
	Button* btn = new Button;
	if (btn && btn->init(baseStr,upStr))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}

Button* Button::createOtherBtn(std::string baseName, std::string name1, std::string name2, std::string name3)
{

	return NULL;
}


Button* Button::createEffectBtn(const char* baseEffectXmls,const char* baseFirstFrameName,const char* baseAnimateName,const char* upEffectXmls,const char* upFirstFrameName,const char* upAnimateName,const char* upWords)
{
	
	Button* btn = new Button;
	if (btn && btn->init(baseEffectXmls,baseFirstFrameName,baseAnimateName,upEffectXmls,upFirstFrameName,upAnimateName,upWords))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}

bool Button::init(CCNode* baseNode,CCNode* upNode)
{
	bool bRet = false;
	do 
	{
		m_HandlerPriority = kCCMenuHandlerPriority-42;
		bg = (CCSprite*)baseNode;
		this->setContentSize(bg->getContentSize());
		bg->addChild(upNode,eUpNodeTag,eUpNodeTag);
		upNode->setPosition(ccp(bg->getContentSize().width*0.5-upNode->getContentSize().width*0.5,bg->getContentSize().height*0.5 - upNode->getContentSize().height*0.5));
		//upNode->setPosition(ccp(upNode->getContentSize().width*0.5,upNode->getContentSize().height*0.5));
		this->addChild(bg,eBaseNodeTag,eBaseNodeTag);



		bRet = true;
	} while (0);
	return bRet;
}


bool Button::init(const char* baseEffectXmls,const char* baseFirstFrameName,const char* baseAnimateName,const char* upEffectXmls,const char* upFirstFrameName,const char* upAnimateName,const char* upWords)
{
	bool bRet = false;
	do 
	{
		 mbaseEffectXmls = baseEffectXmls;
		 mupEffectXmls = upEffectXmls;
		 isEffecttype = true;
		m_HandlerPriority = kCCMenuHandlerPriority-42;
		mScale = 2.0f;
		bg = CCSprite::createWithSpriteFrameName(baseFirstFrameName);
	
		bg->setScale(mScale);
		//this->setContentSize(CCSizeMake(bg->getContentSize().width*mScale,bg->getContentSize().height*mScale));
		this->setContentSize(bg->getContentSize());
		this->addChild(bg,1,1);
	
		CCSprite* upSp = CCSprite::createWithSpriteFrameName(upFirstFrameName);
	
		upSp->setScale(mScale);
		this->addChild(upSp,2,2);
	
		
		CCSprite* upSprite = CCSprite::create(upWords);
		//upSprite->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));

		this->addChild(upSprite,3,3);
		upSprite->setPosition(ccp(0,10.0f));

		bRet = true;
	} while (0);
	return bRet;
}

bool Button::init(std::string baseStr,std::string upStr)
{
	
	bool bRet = false;
	do 
	{	
		CCSprite* upSprite;
	
		m_HandlerPriority = kCCMenuHandlerPriority-42;
		bg = CCSprite::create(baseStr.c_str());


		this->setContentSize(bg->getContentSize());
		
		upSprite = CCSprite::create(upStr.c_str());
		
		bg->addChild(upSprite);
		upSprite->setPosition(ccp(bg->getContentSize().width/2,bg->getContentSize().height/2));
		this->addChild(bg);
		bRet = true;
	} while (0);
	return bRet;
}

bool Button::initOther(std::string baseName, std::string name1, std::string name2, std::string name3)
{

	return false;
}


bool Button::initWith2FrameName(std::string baseStr,std::string upStr,bool bPlist)
{
	m_HandlerPriority = kCCMenuHandlerPriority-42;
	bool bRet = false;
	do 
	{	
		CCSprite* upSprite;
		if (bPlist)
		{
			bg = CCSprite::createWithSpriteFrameName(baseStr.c_str());
		}
		else
		{
			bg = CCSprite::create(baseStr.c_str());
		}

		this->setContentSize(bg->getContentSize());
		if (bPlist)
		{
			upSprite = CCSprite::createWithSpriteFrameName(upStr.c_str());
		}
		else
		{
			upSprite = CCSprite::create(upStr.c_str());
		}
		bg->addChild(upSprite);
		upSprite->setPosition(ccp(bg->getContentSize().width/2,bg->getContentSize().height/2));
		this->addChild(bg);
		bRet = true;
	} while (0);
	return bRet;
}

bool Button::initWithFrameName(std::string iconStr,bool bPlist)
{
	bool bRet = false;
	do 
	{
		if(bPlist)
		{
			bg = CCSprite::createWithSpriteFrameName(iconStr.c_str());
		}
		else
		{
			bg = CCSprite::create(iconStr.c_str());
		}
		this->setContentSize(bg->getContentSize());
		this->addChild(bg,1,1);
		bRet = true;
	} while (0);
	return bRet;
}


bool Button::init(std::string iconStr)
{
	m_HandlerPriority = kCCMenuHandlerPriority-42;
	bool bRet = false;
	do 
	{
		if (strcmp(iconStr.c_str(),"") == 0)
		{
			bg = CCSprite::create();
			bg->setContentSize(CCSizeMake(200,120));			
		}
		else
		{
			bg = CCSprite::create(iconStr.c_str());
		}		
		this->setContentSize(bg->getContentSize());
		this->addChild(bg,1,1);
		bRet = true;
	} while (0);
	return bRet;
}

Button *Button::createBtn(std::string baseStr,std::string upStr,std::string moneyIcon,const char* numStr)
{
	Button* btn = new Button();
	if (btn && btn->init(baseStr,upStr,moneyIcon,numStr))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}

bool Button::init(std::string baseStr,std::string upStr,std::string moneyIcon,const char* numStr)
{
	bool bRet = false;
	do 
	{	
		CCSprite* upSprite;
		m_HandlerPriority = kCCMenuHandlerPriority-42;
		bg = CCSprite::create(baseStr.c_str());
		this->setContentSize(bg->getContentSize());

		upSprite = CCSprite::create(upStr.c_str());
		upSprite->setPosition(ccp(bg->getContentSize().width/2.0f,bg->getContentSize().height*11/16.0f));
		bg->addChild(upSprite);

		CCSprite *moneySprite = CCSprite::create(moneyIcon.c_str());
		moneySprite->setPosition(ccp(bg->getContentSize().width/5.0f,bg->getContentSize().height/4.0f));
		moneySprite->setScale(0.8f);
		bg->addChild(moneySprite);

		std::ostringstream oss;
		oss<<numStr;
		CCLabelBMFont *numLabel = CCLabelBMFont::create(oss.str().c_str(),
			"Graphics/Fonts/UI_yongbinghuashengchuancheng_num.fnt");
			numLabel->setPosition(ccp(bg->getContentSize().width*2/5.0f,bg->getContentSize().height/4.0f));
		numLabel->setAnchorPoint(ccp(0,0.5f));	
		bg->addChild(numLabel);
		this->addChild(bg);
		bRet = true;
	} while (0);
	return bRet;
}

//昆仑秘境专用按钮
Button *Button::createHomeBtn(std::string baseStr,std::string upStr,std::string wordIcon)
{
	Button* btn = new Button();
	if (btn && btn->init(baseStr,upStr,wordIcon))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return NULL;
}

bool Button::init(std::string baseStr,std::string upStr,std::string wordIcon)
{
	bool bRet = false;
	do 
	{	
		CCSprite* upSprite;
		m_HandlerPriority = kCCMenuHandlerPriority-1;
		bg = CCSprite::create(baseStr.c_str());
		this->setContentSize(bg->getContentSize());

		upSprite = CCSprite::create(upStr.c_str());
		upSprite->setPosition(ccp(bg->getContentSize().width/2.0f,bg->getContentSize().height/2.0));
		bg->addChild(upSprite);

		CCSprite *wordSprite = CCSprite::create(wordIcon.c_str());
		wordSprite->setAnchorPoint(ccp(0.5,0));
		wordSprite->setPosition(ccp(bg->getContentSize().width/2,wordSprite->getContentSize().height));
		//moneySprite->setScale(0.8f);
		bg->addChild(wordSprite);

		this->addChild(bg);
		bRet = true;
	} while (0);
	return bRet;
}

void Button::setIsShow(bool isShow)
{
	this->setVisible(isShow);
	isCanTouch = isShow;
}


//void Button::setOnClickCallback(SEL_CallFuncO cb, CCObject * obj)


void Button::onEnter()
{
	CCNode::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,/*m_HandlerPriority*/PRI,true);
	
}
void Button::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCNode::onExit();
}

CCRect Button::rect()
{
	CCSize sizeBg = bg->getContentSize();
	return CCRectMake(-sizeBg.width/2,-sizeBg.height/2,sizeBg.width,sizeBg.height);
}

bool Button::containsTouchLocation(CCTouch* pTouch)
{
	return rect().containsPoint(convertTouchToNodeSpaceAR(pTouch));
}
void Button::setIsCanTouch(bool bl)
{
	isCanTouch = bl;
	if(!isCanTouch && pressbg)
	{
		bg->setVisible(false);
		pressbg->setVisible(true);
	}else if (pressbg)
	{
		bg->setVisible(true);
		pressbg->setVisible(false);
	}
}
void Button::TouchMoreTime(float ft)
{
    click(this);
}
bool  Button::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	if (containsTouchLocation(pTouch))
	{
		if (!isCanTouch)
		{
			return false;
		}

		if(mIsSelect)
			return false;

		if(m_bIsSpecialEffect = false)
		{
		}
		if (mLockMode && mIsLock)
		{
			return false;
		}
		if (m_bPressChange)
		{
			bg->setVisible(false);
			pressbg->setVisible(true);
		}
		else
		{
			bg->setScale(1.1f*mScale);
		}
		
        if (mIsCanTouchMoreTime) {
            schedule(schedule_selector(Button::TouchMoreTime), 0.1f);
        }
        
		return true;
	}
	return false;
}

void Button::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	
	if (containsTouchLocation(pTouch))
	{
		if (!isCanTouch)
		{
			return;
		}
		if (mLockMode)
		{
			lockState();
		}
		
		click(this);
        Global::getInstance()->PlayEffect("touch.mp3");
	}
	if (m_bPressChange)
	{
		bg->setVisible(true);
		pressbg->setVisible(false);
	}
	else
	{
		if(mIsBig)
		{
			bg->setScale(1.1f*mScale);
		}
		else
		{
			bg->setScale(1.0f*mScale);
		}
	}
    if (mIsCanTouchMoreTime) {
        unschedule(schedule_selector(Button::TouchMoreTime));
    }
}

void Button::SetSelect(bool flag)
{
	mIsSelect = flag;
	if(flag)
	{
		bg->setScale(1.1f*mScale);
		bg->setColor(ccc3(255, 255, 255));
	}
	else
	{
		bg->setScale(0.9f*mScale);
		bg->setColor(ccc3(25, 25, 25));
	}

}

void Button::click(CCNode *node)
{
	if (mClickCallback != NULL)
	{
		CCLOG("=========== CLICK  ==============");
		(clickObj->*mClickCallback)(this);
	}
}



void Button::loadLock(float dt)
{
	unLockState();
}

void Button::lockState()
{
	schedule(schedule_selector(Button::loadLock),mLockDt);
	CCLog("------------------------------------------");
	mIsLock = true;
	loadSp = CCSprite::create("New_Graphics/UI_New_liantianfasong_003.png");
	bg->addChild(loadSp,12,1002);
	loadSp->setOpacity(100.0f);
	loadSp->setScale(1.8f);
	loadSp->setPosition(ccp(this->getContentSize().width*0.5,this->getContentSize().height*0.5));
	CCActionInterval*  action1 = CCRotateBy::create(0.1f,  -360.0f);
	loadSp->runAction(CCRepeatForever::create(action1));
	
}

void Button::unLockState()
{
	mIsLock = false;
	unschedule(schedule_selector(Button::loadLock));
	bg->removeChildByTag(1002,true);
}

void Button::setPressIcon(std::string iconStr,bool bPlist)
{
	if(bPlist)
	{
		pressbg = CCSprite::createWithSpriteFrameName(iconStr.c_str());
	}
	else
	{
		pressbg = CCSprite::create(iconStr.c_str());
	}
	addChild(pressbg,1,1);
	pressbg->setVisible(false);
	m_bPressChange =  true;
}

void Button::setPressEnable(bool b)
{
	isCanTouch = b;
	if(b)
	{
		bg->setVisible(true);
		pressbg->setVisible(false);
	}
	else
	{
		bg->setVisible(false);
		pressbg->setVisible(true);
	}
}

void Button::setPressIconShow(bool b)
{
	if(b)
	{
		m_bPressChange = false;
		bg->setVisible(false);
		pressbg->setVisible(true);
	}
	else
	{
		m_bPressChange = true;
		bg->setVisible(true);
		pressbg->setVisible(false);		
	}
}