#include "LoginingLayer.h"


bool LoginingLayer::init()
{
	if (!CCLayer::init())
		return false;

	_touchGroup = ui::TouchGroup::create();
	addChild(_touchGroup);
	m_pWidget = static_cast<ui::Layout*>(GUIReader::shareReader()->widgetFromJsonFile("LoginningLayer/LoginningLayer.json"));
	_touchGroup->addWidget(m_pWidget);
	scheduleUpdate();

	
	ui::Layout* panel = static_cast<ui::Layout*>(_touchGroup->getWidgetByName("Panel"));
	loadingBar = dynamic_cast<ui::UILoadingBar*>(panel->getChildByName("ProgressBar"));
	loadingBar->setPercent(0);
	loadingBar->setZOrder(1000);

	title = static_cast<ui::Label*>(ui::UIHelper::seekWidgetByName(panel, "tishi"));
	str = title->getStringValue();
	return true;
}

void LoginingLayer::update(float delta)
{
	if (m_nCount <= 98)
	{
		if ((int)(delta  * 1000000)  % 2 == 0)
			m_nCount++;
	}
	else
	{
		if ((int)(delta * 1000000 )  % 20 == 0)
			m_nCount++;
	}
	//m_nCount++;

	if (m_nCount >= 100)
	{
		unscheduleUpdate();
		//进入登录 游戏界面
		this->setVisible(false);
		MainScene* layer = MainScene::create();
		this->getParent()->addChild(layer, 2, 0);
		//m_nCount = 0;
	}
	loadingBar->setPercent(m_nCount);

	std::ostringstream ss("");

	ss << str << m_nCount << "%";
	
	title->setText(ss.str().c_str());
	
}

LoginingLayer::LoginingLayer()
: m_nCount(0)
{

}

LoginingLayer::~LoginingLayer()
{
	unscheduleUpdate();
}
