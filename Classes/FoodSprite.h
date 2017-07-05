//
//  FoodSprite.h
//  qiuFight
//
//  Created by 张跃东 on 16/3/2.
//
//

#ifndef FoodSprite_h
#define FoodSprite_h

#include "cocos2d.h"
USING_NS_CC;

class FoodSprite : public CCNode
{
public:
    FoodSprite();
    ~FoodSprite();
    CREATE_FUNC(FoodSprite);
    virtual bool init();
    void createWithRGB(uint16_t index, bool isFood,int baozi,std::string icon,std::string name);
    
    void setUpdateInfo(uint32_t nodeId, CCPoint oldPos, CCPoint destPos);
    virtual void update(float ft);
    
    void setImageHead(bool flag);
    bool getImageHead();
    
    int getImageIndex();
    void setImageIndex(int index, bool isFood);
    
    void addPlayerImage(int hero,int guanghuan,int baozi,int canying,std::string icon);
    void removePlayerImage();
    
    void setName(const char* name);
    void setWaiguan(int hero,int guanghuan,int baozi,int canying)
    {
        heroID = hero;
        mGuanghuan = guanghuan;
        mBaozi = baozi;
        mCanying = canying;
    }
private:
    uint32_t m_spriteID;
    CCPoint m_destPos;
    CCPoint m_oldPos;
    CCPoint m_diff;
    int     m_times;
    
    bool    m_isImageHead;
    int     m_imageIndex;
    
    bool    m_isFood;
    
    int heroID;
    int mGuanghuan;
    int mCanying;
    int mBaozi;
};

#endif /* FoodSprite_h */
