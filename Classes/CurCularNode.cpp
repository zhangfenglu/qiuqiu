//
//  FoodSprite.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/3/2.
//
//

#include "CurCularNode.h"
#include "Common.h"



CirCularNode::CirCularNode()
{
    m_clipNode = NULL;
}
CirCularNode::~CirCularNode()
{
    CC_SAFE_RELEASE_NULL(m_clipNode);
}
CirCularNode* CirCularNode::create(float radius)
{
    auto pClipNode = new CirCularNode();
    if (pClipNode && pClipNode->init(radius)) {
        pClipNode->autorelease();
    }
    else
    {
        delete pClipNode;
        pClipNode = NULL;
    }
    return pClipNode;
}
CirCularNode* CirCularNode::create(float radius,CCNode* pNode)
{
    auto clipNode = CirCularNode::create(radius);
    if (clipNode) {
        clipNode->setClipNode(pNode);
    }
    
    return clipNode;
}
bool CirCularNode::init(float radius)
{
    if (!CCClippingNode::init()) {
        return false;
    }
    
    auto circleNode = CCDrawNode::create();
    
    const int maxTrangle = 360;
    
    CCPoint circleVec2[maxTrangle];
    
    for (int i = 0; i < maxTrangle; i++) {
        float x = cosf(i*(M_PI/180.0f))*radius;
        float y = sinf(i*(M_PI/180.0f))*radius;
        circleVec2[i] = ccp(x, y);
    }
    
    auto circleColor = ccc4f(0, 1, 0, 1);
    
    circleNode->drawPolygon(circleVec2, maxTrangle, circleColor, 1, circleColor);
    setStencil(circleNode);
    
    return true;
}
void CirCularNode::setClipNode(CCNode* pNode)
{
    CC_SAFE_RELEASE_NULL(m_clipNode);
    m_clipNode = pNode;
    CC_SAFE_RETAIN(m_clipNode);
    addChild(pNode);
}

CCNode* CirCularNode::getClipNode()
{
    return m_clipNode;
}
