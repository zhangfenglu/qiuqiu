#ifndef LoginLayer1_h__
#define LoginLayer1_h__

#include "cocos2d.h"
USING_NS_CC;
#include "cocos-ext.h"
USING_NS_CC_EXT;
#include "LoginScene.h"
//using namespace ui;


//typedef enum
//{
//	TEXTFIELD_EVENT_ATTACH_WITH_IME,
//	TEXTFIELD_EVENT_DETACH_WITH_IME,
//	TEXTFIELD_EVENT_INSERT_TEXT,
//	TEXTFIELD_EVENT_DELETE_BACKWARD,
//}TextFiledEventType;

//typedef void (CCObject::*SEL_TextFieldEvent)(CCObject*, TextFiledEventType);
//#define textfieldeventselector(_SELECTOR) (SEL_TextFieldEvent)(&_SELECTOR)

class LoginLayer1 : public CCLayer
{
public:
	LoginLayer1();
	CREATE_FUNC(LoginLayer1);

	virtual bool init();
	virtual void textFieldEvent(CCObject* pSender, ui::TextFiledEventType type);

	void loginServer(CCObject *pSender, ui::TouchEventType type);
	void regServer(CCObject *pSender, ui::TouchEventType type);
	void guestLoginServer(CCObject *pSender, ui::TouchEventType type);
	void toGuestUI(CCObject *pSender, ui::TouchEventType type);
	void toRegUI(CCObject *pSender, ui::TouchEventType type);

	void backToLoginUI(CCObject *pSender, ui::TouchEventType type);

	
protected:
	ui::Layout *m_pWidget;
	ui::TouchGroup* _touchGroup;




	//×¢²á¿Ø¼þ
	ui::ImageView* reg_bg;
	ui::TextField* TextField_zhanghao;
	ui::TextField* TextField_mima;
	ui::TextField* TextField_mima_ok;
	ui::UIButton* ok;
	ui::UIButton* btn_back;

	//µÇÂ½¿Ø¼þ
	ui::ImageView* login_bg;
	ui::TextField* login_zhanghao;
	ui::TextField* login_mima;
	ui::UIButton* btn_login;
	ui::UIButton* btn_guest;
	ui::UIButton* btn_reg;
	//ÓÎ¿ÍµÇÂ½¿Ø¼þ
	ui::ImageView* guest_bg;
	ui::TextField* guest_zhanghao;
	ui::UIButton* btn_guestLogin;
	ui::UIButton* btn_back1;


	//ÅÐ¶Ï×Ö·û´®ÊÇ·ñÊÇ Êý×ÖºÍ×ÖÄ¸
	bool judgeInputBox(const char* inValue);
};

#endif // LoginLayer1_h__
