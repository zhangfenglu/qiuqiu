#ifndef LoginingLayer_h__
#define LoginingLayer_h__
#include "cocos2d.h"
USING_NS_CC;
#include "cocos-ext.h"
USING_NS_CC_EXT;
#include "MainScene.h"

class LoginingLayer : public CCLayer
{
public:
	LoginingLayer();
	~LoginingLayer();
	CREATE_FUNC(LoginingLayer);
	virtual bool init();

	void update(float delta);

private:
	int m_nCount;
	ui::Layout *m_pWidget;
	ui::TouchGroup* _touchGroup;
	ui::UILoadingBar* loadingBar;
	ui::Label* title;
	std::string str;
};



#endif // LoginingLayer_h__
