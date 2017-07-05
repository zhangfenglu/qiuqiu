#ifndef _CEDIT_BOX_H_
#define _CEDIT_BOX_H_
#pragma once

#include "Global.h"

class CInputText : public CCLayer, public CCIMEDelegate
{
public:
	enum EidtType
	{
		EIDT_NORMEL,
		EIDT_PASSWORD,
		EIDI_NUM
	};
	CInputText();
	~CInputText();
	virtual void onClickTrackNode(bool bClicked) = 0;

	virtual void registerWithTouchDispatcher();
	virtual void keyboardWillShow(CCIMEKeyboardNotificationInfo& info);
	virtual void keyboardDidHide(CCIMEKeyboardNotificationInfo& info);
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	std::string getEditString();
	std::string getSpaceName(){return mSpaceName;}
	void setEditString(const char* str){mResult = str;}
	void SetMaxNum(int num){mMaxNum = num;}
    void SetMaxFontNum(int num){mMaxFontNum = num;}
	void SetBoxSize(CCSize  zi);
	void SetEidtType(EidtType tp){mType = tp;}
	bool GetSelect(){return m_IsSelect;}
    void setOnClickCallback(SEL_CallFuncO cb, CCObject * obj){ mClickCallback = cb; clickObj = obj;}
protected:
	CCNode * m_pTrackNode;
	CCPoint  m_beginPos;
	CCPoint  m_endPos;
	EidtType  mType;
	std::string  mSpaceName;
	std::string  mFontName;
	float   mFontSize;
	std::string  mResult;
	int  mMaxNum;
	int  mMaxFontNum;               //最大显示的字符数
	bool  m_IsSelect;
	CCSprite *mCursor;
	float  m_MoveFloat;
    SEL_CallFuncO mClickCallback;
    CCObject *clickObj;
};

class CEditBox : public CInputText, public CCTextFieldDelegate
{
public:
	CEditBox();
	~CEditBox();
	virtual void onClickTrackNode(bool bClicked);
	static  CEditBox*  CreateBox(CCPoint pos, CCRect rt=CCRectMake(40,0,10,84),const char* str="function/func_input_1.png",EidtType type = EIDT_NORMEL,bool isChinese = false,const char* fontName ="w7.ttf",float fontSize = 30.0f);
	bool InitBox(CCPoint pos,CCRect rt,const char* str,bool isChinese,const char* fontName,float fontSize,EidtType type);

	virtual bool onTextFieldAttachWithIME(CCTextFieldTTF * pSender);
	virtual bool onTextFieldDetachWithIME(CCTextFieldTTF * pSender);
	virtual bool onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen);
	virtual bool onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen);
	virtual bool onDraw(CCTextFieldTTF * pSender);
	//virtual void setPosition(const CCPoint &position){setPosition(position);}
	void  setFontColor(const cocos2d::ccColor3B &color3b){ ((CCTextFieldTTF*)m_pTrackNode)->setColor(color3b);}
	void  setFontSize(float size){((CCTextFieldTTF*)m_pTrackNode)->setFontSize(size);}
	void  changeText(float fd);
	void  reRunActiorn();
private:
	std::string oldstr;
	int  mTimeCount;
	bool  isPutInChinese;
	float  stringLen;

};

class CEditBoxTool : public CCEditBox
{
public:
    static CEditBoxTool* Create(const CCSize& size, CCScale9Sprite* pNormal9SpriteBg, CCScale9Sprite* pPressed9SpriteBg = NULL, CCScale9Sprite* pDisabled9SpriteBg = NULL)
    {
        CEditBoxTool* pRet = new CEditBoxTool();
        
        if (pRet != NULL && pRet->initWithSizeAndBackgroundSprite(size, pNormal9SpriteBg))
        {
            if (pPressed9SpriteBg != NULL)
            {
                pRet->setBackgroundSpriteForState(pPressed9SpriteBg, CCControlStateHighlighted);
            }
            
            if (pDisabled9SpriteBg != NULL)
            {
                pRet->setBackgroundSpriteForState(pDisabled9SpriteBg, CCControlStateDisabled);
            }
            pRet->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(pRet);
        }
        
        return pRet;
    }
    virtual void registerWithTouchDispatcher()
    {
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, PRI, true);
    }
};
#endif