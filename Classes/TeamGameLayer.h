#ifndef TeamGameLayer_h__
#define TeamGameLayer_h__

#include "cocos2d.h"
USING_NS_CC;
#include "cocos-ext.h"
USING_NS_CC_EXT;
#include "spine/Json.h"
#include "CocoStudio/Json/rapidjson/stringbuffer.h"
#include "CocoStudio/Json/rapidjson/writer.h"
#include "spine/extension.h"

class TeamGameLayer : public CCLayer
{
public:
	enum 
	{
		teams = 15
	};
	TeamGameLayer();
	~TeamGameLayer();
	CREATE_FUNC(TeamGameLayer);

	virtual bool init();
	cocos2d::extension::Json* ReadJson(const char* path);
private:

	struct Award
	{
		std::string title;
		std::string xiaohao;
		std::string allawards;
	};

	Award* awards[teams];

	ui::Layout *m_pWidget;
	ui::TouchGroup* _touchGroup;

	//每个竞技场 的奖励以及 进入所消耗的钻石 的ui
	ui::Layout *Panel4;
	ui::UIImageView* bg;



};


#endif // TeamGameLayer_h__
