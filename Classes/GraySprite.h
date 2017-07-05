#ifndef __GRAY_SPRITE_H__
#define __GRAY_SPRITE_H__

#include "cocos2d.h"
USING_NS_CC;


class GraySprite : public CCSprite
{
public:
	GraySprite(){}
	virtual ~GraySprite(){}
	static GraySprite* create(const char* pszFileName);
	static GraySprite* createWithSpriteFrameName(const char *pszSpriteFrameName);
	bool initWithTexture(CCTexture2D* pTexture, const CCRect& tRect);
	bool initWithTexture(CCTexture2D *pTexture);
	static GraySprite* createWithTexture(CCTexture2D *pTexture);
	virtual void draw();

};


#endif

