#include "TeamGameLayer.h"

TeamGameLayer::TeamGameLayer()
:_touchGroup(NULL),
isOpenPanel4(false),
Image_award_width(0),
Image_award_poiX(0),
Image_award_poiY(0)
{

}

TeamGameLayer::~TeamGameLayer()
{

}

bool TeamGameLayer::init()
{
	if (!CCLayer::init())
		return false;
	_touchGroup = ui::TouchGroup::create();
	addChild(_touchGroup);

	m_pWidget = static_cast<ui::Layout*>(GUIReader::shareReader()->widgetFromJsonFile("jingjiPlayer/jingjiPlayer.json"));
	_touchGroup->addWidget(m_pWidget);

	ui::Layout* panel = static_cast<ui::Layout*>(_touchGroup->getWidgetByName("Panel"));
	using namespace ui;
	Panel4 = static_cast<ui::Layout*>(panel->getChildByName("Panel4"));
	Panel4->setZOrder(-1);
	Panel4->setVisible(false);
	bg = static_cast<ui::UIImageView*>(Panel4->getChildByName("bg"));
	title = static_cast<ui::UIImageView*>(bg->getChildByName("title"));
	xiaohao = static_cast<ui::UIImageView*>(bg->getChildByName("zuanshi"));
	scrollView = static_cast<ui::UIScrollView*>(bg->getChildByName("ScrollView"));
	Image_award = static_cast<ui::UIImageView*>(scrollView->getChildByName("Image_award"));
	btn_close = static_cast<ui::UIButton*>(bg->getChildByName("btn_close"));
	btn_close->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_close->setTag(10000);
	btn_zudui = static_cast<ui::UIButton*>(bg->getChildByName("btn_zudui"));
	btn_zudui->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_zudui->setTag(20000);
	Image_award_width = Image_award->getSize().width + 300;
	Image_award_poiX = Image_award->getPositionX();
	Image_award_poiY = scrollView->getSize().height + Image_award->getSize().height * 2;
	Json* root = ReadJson("jingjichang.json");

	Json* jsonChild = root->child;
	int i = -1;
	while (jsonChild)
	{
		i++;
		switch (jsonChild->type)
		{
		case Json_NULL:
			break;
		case Json_Number:
			break;
		case Json_Object:
		{
							
					        
							Json* title = Json_getItem(jsonChild, "title");
							
							//CCLog("<<<<<<%s", title->valuestring);
							Json * xiaohao = Json_getItem(jsonChild, "xiaohao");
							Json* allawards = Json_getItem(jsonChild, "allawards");
							Award* award = new Award();
							award->title = title->valuestring;
							award->xiaohao = xiaohao->valuestring;
							award->allawards = allawards->valuestring;
							awards[i] = award;
		}
			break;
		case Json_String:
			CCLog("<<<<<<%s", jsonChild->valuestring);

			break;
		case Json_True:
			break;
		case Json_Array:
			break;
		default:
			break;
		}

		jsonChild = jsonChild->next;
	}

	for (int i = 0; i < sizeof(awards) / sizeof(awards[0]); i++)
	{
		std::string title = awards[i]->title;
		CCLog("<<<<<<%s", title.c_str());
	}
	
	//Pannel1
	Panel1 = static_cast<ui::Layout*>(panel->getChildByName("Panel1"));
	btn_chuji_ok = static_cast<ui::UIButton*>(Panel1->getChildByName("btn_chuji_ok"));
	btn_chuji_ok->setTag(1000);
	btn_chuji_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_zhongji_ok = static_cast<ui::UIButton*>(Panel1->getChildByName("btn_zhongji_ok"));
	btn_zhongji_ok->setTag(1001);
	btn_zhongji_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_gaoji_ok = static_cast<ui::UIButton*>(Panel1->getChildByName("btn_gaoji_ok"));
	btn_gaoji_ok->setTag(1002);
	btn_gaoji_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_shenyuan_ok = static_cast<ui::UIButton*>(Panel1->getChildByName("btn_shenyuan_ok"));
	btn_shenyuan_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_shenyuan_ok->setTag(1003);
	btn_emo_ok = static_cast<ui::UIButton*>(Panel1->getChildByName("btn_emo_ok"));
	btn_emo_ok->setTag(1004);
	btn_emo_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));

	//Pannel2
	Panel2 = static_cast<ui::Layout*>(panel->getChildByName("Panel2"));
	btn_1_ok = static_cast<ui::UIButton*>(Panel2->getChildByName("btn_1_ok"));
	btn_1_ok->setTag(1005);
	btn_1_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_2_ok = static_cast<ui::UIButton*>(Panel2->getChildByName("btn_2_ok"));
	btn_2_ok->setTag(1006);
	btn_2_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_3_ok = static_cast<ui::UIButton*>(Panel2->getChildByName("btn_3_ok"));
	btn_3_ok->setTag(1007);
	btn_3_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_4_ok = static_cast<ui::UIButton*>(Panel2->getChildByName("btn_4_ok"));
	btn_4_ok->setTag(1008);
	btn_4_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_5_ok = static_cast<ui::UIButton*>(Panel2->getChildByName("btn_5_ok"));
	btn_5_ok->setTag(1009);
	btn_5_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	//Pannel3
	Panel3 = static_cast<ui::Layout*>(panel->getChildByName("Panel3"));
	btn_6_ok = static_cast<ui::UIButton*>(Panel3->getChildByName("btn_6_ok"));
	btn_6_ok->setTag(1010);
	btn_6_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_7_ok = static_cast<ui::UIButton*>(Panel3->getChildByName("btn_7_ok"));
	btn_7_ok->setTag(1011);
	btn_7_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_8_ok = static_cast<ui::UIButton*>(Panel3->getChildByName("btn_8_ok"));
	btn_8_ok->setTag(1012);
	btn_8_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_9_ok = static_cast<ui::UIButton*>(Panel3->getChildByName("btn_9_ok"));
	btn_9_ok->setTag(1013);
	btn_9_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));
	btn_10_ok = static_cast<ui::UIButton*>(Panel3->getChildByName("btn_10_ok"));
	btn_10_ok->setTag(1014);
	btn_10_ok->addTouchEventListener(this, toucheventselector(TeamGameLayer::touchEvent));

	
	return true;
}

cocos2d::extension::Json* TeamGameLayer::ReadJson(const char* path)
{
	int lenght;
	const char* json = _Util_readFile(path, &lenght);
	Json* root = Json_create(json);
	if (!root)
		CCLog("can't open jsonfile %s", path);

	FREE(json);
	return root;
}

void TeamGameLayer::initPanel4(int tag)
{
	if (tag >= 1000)
	{
		std::string titleStr = awards[tag - 1000]->title;
		titleStr = "jingjiPlayer\\box\\title\\" + titleStr + ".png";
		title->loadTexture(titleStr.c_str());
		std::string xiaohaoStr = awards[tag - 1000]->xiaohao;
		xiaohaoStr = "jingjiPlayer\\box\\killzuanshi\\" + xiaohaoStr + ".png";
		xiaohao->loadTexture(xiaohaoStr.c_str());
		std::string awardsStr = awards[tag - 1000]->allawards;
		std::vector<std::string> awardsArrays = split(awardsStr, "|");

		scrollView->removeAllChildren();
		for (int i = 0; i < awardsArrays.size(); i++)
		{
			ui::UIImageView* cloneImage = ui::UIImageView::create();
			scrollView->addChild(cloneImage);
			std::string clonePath = "jingjiPlayer\\box\\reward\\" + awardsArrays.at(i) + ".png";
			cloneImage->loadTexture(clonePath.c_str());
			cloneImage->setPosition(ccp(Image_award_poiX + Image_award_width * i, Image_award_poiY));

		}
	}
}

std::vector<std::string> TeamGameLayer::split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//À©Õ¹×Ö·û´®ÒÔ·½±ã²Ù×÷
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;

}

void TeamGameLayer::touchEvent(CCObject *pSender, ui::TouchEventType type)
{
	ui::UIButton* button = static_cast<ui::UIButton*>(pSender);
	int tag = button->getTag();
	switch (type)
	{
	case ui::TOUCH_EVENT_BEGAN:
		
		break;

	case ui::TOUCH_EVENT_MOVED:
		
		break;

	case ui::TOUCH_EVENT_ENDED:
	{
		
		 if (tag == 10000)//¹Ø±Õµ¯´°
		 {
			 Panel4->setVisible(false);
			 Panel4->setZOrder(-1);
		 }
		 else if (tag == 20000)
		 {
			 CCLog("zudui");
		 }
		 else
		 {
			 Panel4->setZOrder(1000);
			 Panel4->setVisible(true);
			 initPanel4(tag);
		 }
		 
	}
		break;

	case ui::TOUCH_EVENT_CANCELED:
		
		break;

	default:
		break;
	}
}


