#include "LoginLayer1.h"

bool LoginLayer1::init()
{
	if (!CCLayer::init())
		return false;
	//m_pUiLayer = ui::UILayer::create();
	_touchGroup = ui::TouchGroup::create();
	//_touchGroup->addChild(m_pUiLayer);
	addChild(_touchGroup);
	//addChild(m_pUiLayer);

	m_pWidget = static_cast<ui::Layout*>(GUIReader::shareReader()->widgetFromJsonFile("LoginLayer/LoginLayer.json"));
	//m_pUiLayer->addWidget(m_pWidget);
	_touchGroup->addWidget(m_pWidget);

	CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
	CCSize rootSize = m_pWidget->getSize();
	/*m_pUiLayer->setPosition(CCPoint((screenSize.width - rootSize.width) / 2,
		(screenSize.height - rootSize.height) / 2));
*/

	ui::Layout* panel = static_cast<ui::Layout*>(_touchGroup->getWidgetByName("Panel"));
	ui::Layout* back = static_cast<ui::Layout*>(panel->getChildByName("back"));

	//本地寻找登陆账号与密码
	//找不到 就显示 账号登陆控件 否则隐藏
	using namespace ui;
	//登陆控件
    login_bg = static_cast<ui::ImageView*>(back->getChildByName("login_bg"));
	login_bg->setZOrder(10000);
	login_zhanghao = static_cast<ui::TextField*>(ui::UIHelper::seekWidgetByName(login_bg, "TextField_zhanghao"));
	login_mima = static_cast<ui::TextField*>(ui::UIHelper::seekWidgetByName(login_bg, "TextField_mima"));
	btn_login = static_cast<ui::UIButton*>(ui::UIHelper::seekWidgetByName(login_bg, "login"));
	btn_guest = static_cast<ui::UIButton*>(ui::UIHelper::seekWidgetByName(login_bg, "guest"));
	btn_reg = static_cast<ui::UIButton*>(ui::UIHelper::seekWidgetByName(login_bg, "reg"));
	login_zhanghao->addEventListenerTextField(this, textfieldeventselector(LoginLayer1::textFieldEvent));
	btn_login->addTouchEventListener(this, toucheventselector(LoginLayer1::loginServer));
	btn_guest->addTouchEventListener(this, toucheventselector(LoginLayer1::toGuestUI));
	btn_reg->addTouchEventListener(this, toucheventselector(LoginLayer1::toRegUI));

	//游客登陆控件
	guest_bg = static_cast<ui::ImageView*>(back->getChildByName("guest_bg"));

	guest_zhanghao = static_cast<ui::TextField*>(ui::UIHelper::seekWidgetByName(guest_bg, "TextField_zhanghao"));
	guest_zhanghao->addEventListenerTextField(this, textfieldeventselector(LoginLayer1::textFieldEvent));
	//不能输入数据 默认读取机型编码udid
	guest_zhanghao->setTouchEnabled(false);

	btn_guestLogin = static_cast<ui::UIButton*>(ui::UIHelper::seekWidgetByName(guest_bg, "login_guest"));
	btn_guestLogin->addTouchEventListener(this, toucheventselector(LoginLayer1::guestLoginServer));
	btn_back1 = static_cast<ui::UIButton*>(ui::UIHelper::seekWidgetByName(guest_bg, "btn_back"));
	btn_back1->addTouchEventListener(this, toucheventselector(LoginLayer1::backToLoginUI));


	//注册控件
	reg_bg = static_cast<ui::ImageView*>(back->getChildByName("reg_bg"));
	//默认 游客与注册控件是隐藏的
	guest_bg->setVisible(false);
	reg_bg->setVisible(false);
	guest_bg->setTouchEnabled(false);
	reg_bg->setTouchEnabled(false);
	//ui::Label* title = static_cast<ui::Label*>(ui::UIHelper::seekWidgetByName(reg_bg, "title"));
    TextField_zhanghao = static_cast<ui::TextField*>(ui::UIHelper::seekWidgetByName(reg_bg, "TextField_zhanghao"));
	TextField_mima = static_cast<ui::TextField*>(ui::UIHelper::seekWidgetByName(reg_bg, "TextField_mima"));
	TextField_mima_ok = static_cast<ui::TextField*>(ui::UIHelper::seekWidgetByName(reg_bg, "TextField_mima_ok"));
	
	TextField_zhanghao->addEventListenerTextField(this, textfieldeventselector(LoginLayer1::textFieldEvent));
	ok = static_cast<ui::UIButton*>(ui::UIHelper::seekWidgetByName(reg_bg, "ok"));
	ok->addTouchEventListener(this, toucheventselector(LoginLayer1::regServer));
	btn_back = static_cast<ui::UIButton*>(ui::UIHelper::seekWidgetByName(reg_bg, "btn_back"));
	btn_back->addTouchEventListener(this, toucheventselector(LoginLayer1::backToLoginUI));




	return true;
}

LoginLayer1::LoginLayer1()
:_touchGroup(NULL)
{

}

void LoginLayer1::textFieldEvent(CCObject* pSender,ui::TextFiledEventType type)
{
	ui::TextField* zhanghao = static_cast<ui::TextField*>(pSender);
	switch (type)
	{
	case ui::TEXTFIELD_EVENT_ATTACH_WITH_IME:
	{
										
		CCLog("111111111111111111");
	}
		break;

	case ui::TEXTFIELD_EVENT_DETACH_WITH_IME:
	{
		CCLog("111111111111111112");
	}
		break;

	case ui::TEXTFIELD_EVENT_INSERT_TEXT:
	{
	   CCLog("111111111111111113");
	  const char* inValue = zhanghao->getStringValue();
	  if (judgeInputBox(inValue))
	  {
		  CCLog("shuzi huo zhe zimu");
	  }
	  else
	  {
		  CCLog("hanzi");
		  zhanghao->setText("");
	
	  }
	}
		break;

	case ui::TEXTFIELD_EVENT_DELETE_BACKWARD:
		CCLog("111111111111111114");
		break;

	default:
		break;
	}
}

void LoginLayer1::regServer(CCObject *pSender, ui::TouchEventType type)
{
	switch (type)
	{
	case ui::TOUCH_EVENT_BEGAN:
		CCLog("TOUCH_EVENT_BEGAN");
		break;

	case ui::TOUCH_EVENT_MOVED:
		
		break;

	case ui::TOUCH_EVENT_ENDED:
	{
								  CCLog("TOUCH_EVENT_ENDED");
								  //判断账号与密码是否为空
								  const char* zhanghao = TextField_zhanghao->getStringValue();
								  const char* mima = TextField_mima->getStringValue();
								  const char* ok = TextField_mima_ok->getStringValue();
								  if (mima != ok)
								  {
									  CCLog("ERROR");
									  TextField_mima->setText("");
									  TextField_mima_ok->setText("");
								  }
								  else if (zhanghao && strlen(zhanghao) != 0 && mima && strlen(mima) != 0 && ok && strlen(ok) != 0)
								  {
									  //发送注册数据 向服务器
									  CCLog("SEND");
								  }
								  else
								  {
									  CCLog("NOT CAN NULL");
									  return;
								  }
	}
	
		break;

	case ui::TOUCH_EVENT_CANCELED:
	
		break;

	default:
		break;
	}
}

bool LoginLayer1::judgeInputBox(const char* inValue)
{
	bool result = false;
	while (*inValue)
	{
		if ((*inValue) & 0x80)
		{
			result = false;
			CCLog("hanzi");
			//TextField_zhanghao->setText("");
			break;
		}
		else if ((*inValue >= 'a' && *inValue <= 'z' || *inValue >= 'A' && *inValue <= 'Z') || *inValue >= '0' && *inValue <= '9')
		{
			CCLog("shuzi huo zhe zimu");
			result = true;
		}
		else
		{
			result = false;
			break;
		}
		inValue++;
	}



	return result;
}

void LoginLayer1::loginServer(CCObject *pSender, ui::TouchEventType type)
{
	switch (type)
	{
	case ui::TOUCH_EVENT_BEGAN:
		CCLog("TOUCH_EVENT_BEGAN");
		break;

	case ui::TOUCH_EVENT_MOVED:

		break;

	case ui::TOUCH_EVENT_ENDED:
	{
								  CCLog("TOUCH_EVENT_ENDED");
								  //判断账号与密码是否为空
								  const char* zhanghao = login_zhanghao->getStringValue();
								  const char* mima = login_mima->getStringValue();
								  if (zhanghao && strlen(zhanghao) != 0 && mima && strlen(mima) != 0)
								  {
									  //发送登陆数据 向服务器
									  CCLog("SEND");
                                      m_pWidget->setVisible(false);
                                      LoginLayer* layer = static_cast<LoginLayer*>(this->getParent());
                                      layer->initUI();
								  }
								  else
								  {
									  CCLog("NOT CAN NULL");
									  return;
								  }
	}

		break;

	case ui::TOUCH_EVENT_CANCELED:

		break;

	default:
		break;
	}
}

void LoginLayer1::toGuestUI(CCObject *pSender, ui::TouchEventType type)
{
	switch (type)
	{
	case ui::TOUCH_EVENT_BEGAN:
		CCLog("TOUCH_EVENT_BEGAN");
		break;

	case ui::TOUCH_EVENT_MOVED:

		break;

	case ui::TOUCH_EVENT_ENDED:
	{
		 CCLog("TOUCH_EVENT_ENDED");
		 login_bg->setVisible(false);
		 login_bg->setZOrder(1);
		 reg_bg->setVisible(false);
		 reg_bg->setZOrder(1);
		 guest_bg->setZOrder(1000);
		 guest_bg->setVisible(true);
								 
	}

		break;

	case ui::TOUCH_EVENT_CANCELED:

		break;

	default:
		break;
	}
}

void LoginLayer1::toRegUI(CCObject *pSender, ui::TouchEventType type)
{
	switch (type)
	{
	case ui::TOUCH_EVENT_BEGAN:
		CCLog("TOUCH_EVENT_BEGAN");
		break;

	case ui::TOUCH_EVENT_MOVED:

		break;

	case ui::TOUCH_EVENT_ENDED:
	{
								  CCLog("TOUCH_EVENT_ENDED");
								  login_bg->setVisible(false);
								  login_bg->setZOrder(1);
								  guest_bg->setVisible(false);
								  reg_bg->setZOrder(1000);
								  guest_bg->setZOrder(1);
								  reg_bg->setVisible(true);

	}

		break;

	case ui::TOUCH_EVENT_CANCELED:

		break;

	default:
		break;
	}
}

void LoginLayer1::backToLoginUI(CCObject *pSender, ui::TouchEventType type)
{
	switch (type)
	{
	case ui::TOUCH_EVENT_BEGAN:
		CCLog("TOUCH_EVENT_BEGAN");
		break;

	case ui::TOUCH_EVENT_MOVED:

		break;

	case ui::TOUCH_EVENT_ENDED:
	{
								  CCLog("TOUCH_EVENT_ENDED");
								  login_bg->setVisible(true);
								  login_bg->setZOrder(1000);
								  guest_bg->setVisible(false);
								  reg_bg->setZOrder(1);
								  guest_bg->setZOrder(1);
								  reg_bg->setVisible(true);

	}

		break;

	case ui::TOUCH_EVENT_CANCELED:

		break;

	default:
		break;
	}
}

void LoginLayer1::guestLoginServer(CCObject *pSender, ui::TouchEventType type)
{
	switch (type)
	{
	case ui::TOUCH_EVENT_BEGAN:
		CCLog("TOUCH_EVENT_BEGAN");
		break;

	case ui::TOUCH_EVENT_MOVED:

		break;

	case ui::TOUCH_EVENT_ENDED:
	{
								  CCLog("TOUCH_EVENT_ENDED");
								  //判断账号与密码是否为空
								  const char* zhanghao = guest_zhanghao->getStringValue();
								  if (zhanghao && strlen(zhanghao) != 0)
								  {
									  //发送登陆数据 向服务器
									  CCLog("SEND");
                                      m_pWidget->setVisible(false);
                                      LoginLayer* layer = static_cast<LoginLayer*>(this->getParent());
                                      layer->initUI();
								  }
								  else
								  {
									  CCLog("NOT CAN NULL");
									  return;
								  }
	}

		break;

	case ui::TOUCH_EVENT_CANCELED:

		break;

	default:
		break;
	}
}
