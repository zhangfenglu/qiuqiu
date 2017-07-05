//
//  FoodSprite.h
//  qiuFight
//
//  Created by 刘权威 on 16/3/2.
//
//

#ifndef _CirCularNode_
#define _CirCularNode_

#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
USING_NS_CC;

class CirCularNode : public CCClippingNode
{
public:
    CirCularNode();
    virtual ~CirCularNode();
    static CirCularNode* create(float radius);
    static CirCularNode* create(float radius,CCNode* pNode);
    virtual bool init(float radius);
    
    CC_PROPERTY(CCNode*,m_clipNode,ClipNode);
};

#endif /* PlayerSprite_h */
