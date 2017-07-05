//
//  SpikeSprite.h
//  qiuFight
//
//  Created by 张跃东 on 16/3/2.
//
//

#ifndef SpikeSprite_h
#define SpikeSprite_h

#include "cocos2d.h"
USING_NS_CC;

class SpikeSprite : public CCSprite
{
public:
    SpikeSprite(){}
    ~SpikeSprite(){}
    
    static SpikeSprite* createSpike();
};
#endif /* SpikeSprite_h */
