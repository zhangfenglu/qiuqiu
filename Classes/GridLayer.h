//
//  GridLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/2/24.
//
//

#ifndef GridLayer_h
#define GridLayer_h

#include "Global.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "WebSocket.h"
#include "NodeInfo.h"
USING_NS_CC;
USING_NS_CC_EXT;

class GridLayer : public CCLayer
{
public:
    GridLayer();
    ~GridLayer();
    
    virtual bool init();
    CREATE_FUNC(GridLayer);
    
    void createMap();
    
    void upCenter(CCPoint pt)
    {
        getChildByTag(0)->setPosition(pt);
    }
    //virtual void draw();
    
    void updateNodes(const WebSocket::Data &data);
    
    void ChangeNodes(uint32_t nodeId, CNodeInfo* node);
    void DeleteNode(uint32_t nodeID);
    void AddNode(CNodeInfo* node);
    void updateNodeState(CNodeInfo* node);
    
    CCPoint GetMainPos(uint32_t nodeId);
    
    void updateOtherPlayer(nodeInfo info);
    void updateOtherPos(uint32_t nodeID, CCPoint destPos);
    
    void updateMainNodes(nodeInfo info);
    void addMainNode(nodeInfo info);
    
    void setMainNodePos(CCPoint pos);
    void deleteMainNode(uint32_t nodeID);
    
    void updateMainPos(uint32_t sprID, CCPoint pos);
    
    void resetMainState();
    
    int getMainNodeSize(uint32_t nodeID);
    int getMainMass(uint32_t nodeID);
    CCPoint getMainNodesCenterPos();
    
    void delayUpdateCameraSize(float ft);
    
    void removeOtherChild();
    
    float getMainNodeDiff();
#ifdef EditEXE
    void updateMain(float ft);
    int getMass();
#endif
    
private:
#ifdef EditEXE
    int   mass;
#endif
    int m_topNum;
    int m_leftNum;
    
    float width;
    float height;
    
    CCPoint m_node_win_diff;
    
    std::vector<eatInfo> eats;
    std::vector<uint32_t> unVisibles;
    std::map<uint32_t, CNodeInfo*> nodes;
    
    float m_cameraScale;
    
    // test
//    long  currentTime;
//    long  tempTime;
//    int index;
    
    std::vector<CCSpriteBatchNode*> mBatch;
    
};

#endif /* GridLayer_h */
