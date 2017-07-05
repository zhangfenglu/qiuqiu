#ifndef __RICHLABEL_H__
#define __RICHLABEL_H__

#include "Global.h"

enum LinkType
{
	LinkItem = 0,
	LinkBeing = 1,
};

class RichLabel;
class RichLabelDelegate
{
public:
	virtual ~RichLabelDelegate() {}
	virtual void linkClick(RichLabel* label, const LinkType linkType, const int targetId) = 0;
};

class RichLabel : public CCLayerRGBA /*public CCTouchDelegate, public CCRGBAProtocol*/
{
public:
    RichLabel() : mLinkDelegate(NULL), mParsed(false), mAllowAppendString(false) {}
	~RichLabel() {}

	static RichLabel * create(const char* string, const char* fontName, const int fontSize, CCSize labelSize, bool appendString = false, bool enableShadow = true);
	bool init(const char* string, const char* fontName, const int fontSize, CCSize labelSize, bool appendString = false, bool enableShadow = true);

	const char * getRichString() { return mString.c_str();}
	CCSize getTextSize() { return mContentSize;};
	void setLinkDelegate(RichLabelDelegate * delegate) { mLinkDelegate = delegate; }

	//void setColor(ccColor3B color);
	void appendString(const char* string);

	//virtual void setOpacity(GLubyte opacity);
	//virtual GLubyte getOpacity(void);

	/** Opacity: conforms to CCRGBAProtocol protocol */
	CC_PROPERTY(GLubyte, m_nOpacity, Opacity)
	/** Color: conforms with CCRGBAProtocol protocol */
	CC_PROPERTY_PASS_BY_REF(ccColor3B, m_sColor, Color);
	// RGBAProtocol
	/** opacity: conforms to CCRGBAProtocol protocol */
	virtual void setOpacityModifyRGB(bool bValue);
	virtual bool isOpacityModifyRGB(void);

	virtual void registerWithTouchDispatcher();

	virtual void onEnter();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {}
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	enum TagType {
		None,
		FontTag,
		LinkTag,
		ColorTag,
		EmojTag,
		LineTag,
		SectionTag,
		TabTag,
		EndTag,
	};



private:
	const char *  parse(const char* string, bool recurse = false);
	const char * parseFont(const char* string);
	const char * parseLink(const char* string);
	const char * parseColor(const char* string);
	const char * parseEmoj(const char* string);
	const char * parseLine(const char* string);
	const char * parseSection(const char* string);
	const char * parseTab(const char* string);
	
	TagType searchTag(const char* string, int & pos);
	void createLabel(const char * string, int length = -1, bool defaultFont = true);
	int searchTruncatePos(const char *string, int pixelWidth);
	
	void measureString(const char* string, float &width, float &height);
    int SearchStrPos(const char *string, int pixelWidth);
	CCSize mSize;
	bool mParsed;

	std::string mString;
	RichLabelDelegate * mLinkDelegate;

	struct Link {
		LinkType linkType;
		int linkTarget;
		CCRect rect;

		Link() {}
		Link(CCRect _rect, LinkType _type, int target) 
		{
			rect = _rect;
			linkType = _type;
			linkTarget = target;
		}
		Link(const Link & link) 
		{
			rect = link.rect;
			linkType = link.linkType;
			linkTarget = link.linkTarget;
		}
	};

	std::vector<Link> mLinkMap;

	std::string mDefaultFontName;
	int mDefaultFontSize;
	int mDefaultColor;

	std::string mFontName;
	int mFontSize;
	int mColor;

	bool mNoneTagFound;
	bool mColorTagFound;
	bool mFontTagFound;
	bool mLinkTagFound;
	bool mEmojTagFound;

	float mLabelOffsetX;
	float mLabelOffsetY;

	Link mLink;

	CCSize mContentSize;

	bool mAllowAppendString;
	bool mEnableShadow;
};

#endif // __RICHLABEL_H__
