#ifndef __LABELSTROKE_H__
#define __LABELSTROKE_H__

#include "cocos2d.h"



USING_NS_CC;

class LabelStroke : public CCLabelTTF //public CCNodeRGBA/*, public CCRGBAProtocol*/
{
public:
	LabelStroke() {}
	~LabelStroke() {}

	static LabelStroke * create(const char* string, const char* fontName, const int fontSize, int strokeSize = 1, ccColor3B color = ccc3(0, 0, 0));
	static LabelStroke * create(const char* string, const char* fontName, const int fontSize, const CCSize& dimensions, 
									CCTextAlignment hAlignment = kCCTextAlignmentLeft, int strokeSize = 1, ccColor3B color = ccc3(0, 0, 0));
	bool init(const char* string, const char* fontName, const int fontSize, int strokeSize, ccColor3B color);
	bool init(const char* string, const char* fontName, const int fontSize, const CCSize& dimensions, CCTextAlignment hAlignment, int strokeSize, ccColor3B color);
	
	//const char * getString();
	//void setColor(ccColor3B color);	

	///** Opacity: conforms to CCRGBAProtocol protocol */
	//CC_PROPERTY(GLubyte, m_nOpacity, Opacity)
	///** Color: conforms with CCRGBAProtocol protocol */
	//CC_PROPERTY_PASS_BY_REF(ccColor3B, m_sColor, Color);
	//// RGBAProtocol
	///** opacity: conforms to CCRGBAProtocol protocol */
	//virtual void setOpacityModifyRGB(bool bValue);
	//virtual bool isOpacityModifyRGB(void);

	//virtual void setOpacity(GLubyte opacity);

private:
	//CCRenderTexture* createStroke(CCLabelTTF* label, float size ,ccColor3B cor);

	//CCLabelTTF * mLabel;
};

#endif // __LABELSTROKE_H__
