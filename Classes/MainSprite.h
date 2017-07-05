//
//  MainSprite.h
//  qiuFight
//
//  Created by 张跃东 on 16/2/29.
//
//

#ifndef MainSprite_h
#define MainSprite_h

#include "cocos2d.h"
USING_NS_CC;

class MainSprite : public CCNode //public CCSprite
{
public:
    MainSprite();
    ~MainSprite();
    CREATE_FUNC(MainSprite);
    virtual bool init();
    //static MainSprite* createWithIDX();
    
    void setOriginPos(CCPoint pos);
    void setSize(CCSize size);
    void updatePos(CCPoint pos);
    
    void updateMainPos();
    void setPlayerUpdate(uint32_t nodeId, CCPoint destPos);
    
    void addPlayerImage(int hero,int guanghuan,int baozi,int canying);
    void removePlayerImage();
    
    void setUpdateInfo(uint32_t nodeId, CCPoint oldPos, CCPoint destPos);
    virtual void update(float ft);
    void resetState();
    
    void setIamgeHead(bool flag);
    bool getIamgeHead();
    
    void setName(std::string name);
    
    void setSpSize(float size);
    float getSpSize();
    void setWaiguan(int hero,int guanghuan,int baozi,int canying)
    {
        heroID = hero;
        mGuanghuan = guanghuan;
        mBaozi = baozi;
        mCanying = canying;
    }
private:
    uint32_t m_sprID;
    CCPoint  m_destPos;
    CCPoint  m_diff;
    CCPoint  m_oldPos;
    int     m_times;
    
    bool   m_isImageHead;
    float   m_sp_scale;
    int heroID;
    int mGuanghuan;
    int mCanying;
    int mBaozi;
};

#endif /* MainSprite_h */
