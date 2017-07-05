//
//  JoystickLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/2/25.
//
//

#ifndef JoystickLayer_h
#define JoystickLayer_h

#include "cocos2d.h"
USING_NS_CC;

class JoystickLayer : public CCLayer
{
public:
    JoystickLayer();
    ~JoystickLayer();
    
    virtual bool init();
    CREATE_FUNC(JoystickLayer);
    
    void setOutPos(CCPoint pos);
    void updateJoystick(CCPoint dif);
    
    CCPoint GetJoyPos();
    
private:
    CCSprite* in;
    CCSprite* out;
    
    CCSize outSize;
};

#endif /* JoystickLayer_h */
