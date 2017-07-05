//
//  JoystickLayer.cpp
//  qiuFight
//
//  Created by 张跃东 on 16/2/25.
//
//

#include "JoystickLayer.h"
#include "Common.h"


JoystickLayer::JoystickLayer()
{
    
}

JoystickLayer::~JoystickLayer()
{
    
}

bool JoystickLayer::init()
{
    if(!CCLayer::init())
        return false;
    
    out = CCSprite::create("Joystick_01.png");
    out->setScale(0.5f);
    out->setPosition(ccp(0,0));
    addChild(out, 0, 1);
    
    in = CCSprite::create("Joystick_02.png");
    in->setPosition(ccp(0,0));
    in->setScale(0.5f);
    addChild(in, 1, 2);
    
    return true;
}

void JoystickLayer::setOutPos(cocos2d::CCPoint pos)
{
    out->setPosition(pos);
    outSize = out->getContentSize() * 0.2f;
    
    in->setPosition(pos);
}

void JoystickLayer::updateJoystick(cocos2d::CCPoint dif)
{
    CCPoint outPos = out->getPosition();
    
    CCPoint currentPos = in->getPosition();
    CCPoint destPos = ccpAdd(currentPos, dif);
    
    float x = destPos.x - outPos.x;
    float y = destPos.y - outPos.y;
//    float r = outSize.width * 0.5f;
    float r = R_LENGTH;
    
    
    if((x * x + y * y ) < r * r)
    {
        
    }
    else
    {
        float a = atanf(y/x);
        float ran ;
        if(x > 0 && y > 0)
        {
            ran = a;
        }
        else if(x < 0 && y > 0)
        {
            ran = M_PI + a;
        }
        else if(x < 0 && y < 0)
        {
            ran = M_PI + a;
        }
        else if(x > 0 && y < 0)
        {
            ran = a;
        }
        
        destPos.x = outPos.x + r * cosf(ran);
        destPos.y = outPos.y + r * sinf(ran);
    }
    
    
    in->setPosition(destPos);
    
}

CCPoint JoystickLayer::GetJoyPos()
{
    return in->getPosition();
}

