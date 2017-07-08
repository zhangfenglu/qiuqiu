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


	bool isOpenPanel4;
	int Image_award_width;
	int Image_award_poiX;
	int Image_award_poiY;

	Award* awards[teams];

	ui::Layout *m_pWidget;
	ui::TouchGroup* _touchGroup;

	//每个竞技场 的奖励以及 进入所消耗的钻石 的ui
	ui::Layout *Panel4;
	ui::UIImageView* bg;
	ui::UIImageView* title;
	ui::UIImageView* xiaohao;
	ui::UIScrollView* scrollView;
	ui::UIImageView* Image_award;
	ui::UIButton* btn_close;
	ui::UIButton* btn_zudui;
	void initPanel4(int tag);
	std::vector<std::string> split(std::string str, std::string pattern);
	//竞技场按钮
	ui::Layout *Panel1;
	ui::Layout *Panel2;
	ui::Layout *Panel3;
	ui::UIButton* btn_chuji_ok;
	ui::UIButton* btn_zhongji_ok;
	ui::UIButton* btn_gaoji_ok;
	ui::UIButton* btn_shenyuan_ok;
	ui::UIButton* btn_emo_ok;
	ui::UIButton* btn_1_ok;
	ui::UIButton* btn_2_ok;
	ui::UIButton* btn_3_ok;
	ui::UIButton* btn_4_ok;
	ui::UIButton* btn_5_ok;
	ui::UIButton* btn_6_ok;
	ui::UIButton* btn_7_ok;
	ui::UIButton* btn_8_ok;
	ui::UIButton* btn_9_ok;
	ui::UIButton* btn_10_ok;

	void touchEvent(CCObject *pSender, ui::TouchEventType type);


};


#endif // TeamGameLayer_h__
