#include "TeamGameLayer.h"

TeamGameLayer::TeamGameLayer()
:_touchGroup(NULL)
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

	Panel4 = static_cast<ui::Layout*>(panel->getChildByName("Panel4"));
	bg = static_cast<ui::UIImageView*>(Panel4->getChildByName("bg"));
	//bg->setVisible(false);

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
