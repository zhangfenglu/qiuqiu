//
//  WebSocketLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/2/29.
//
//

#ifndef WebSocketLayer_h
#define WebSocketLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "WebSocket.h"

USING_NS_CC;
USING_NS_CC_EXT;

class WebSocketLayer : public CCLayer, public WebSocket::Delegate
{
public:
    WebSocketLayer();
    virtual ~WebSocketLayer();
    
    virtual bool init();
    CREATE_FUNC(WebSocketLayer);
    
    virtual void onOpen(WebSocket* ws);
    virtual void onMessage(WebSocket* ws, const WebSocket::Data& data);
    virtual void onClose(WebSocket* ws);
    virtual void onError(WebSocket* ws, const WebSocket::ErrorCode&error);
    
    //Menu Callbacks
    void onSendMsg(const char* buf, int nLen);
    void onSendUIMsg(const char* buf, int nLen);
    
    bool openWebSocket(const char* ipAddress, const char* port);
    
    void closeNet();
    
private:
    WebSocket* _wsiSendBinary;
    
    WebSocket* _wsiUIBinary;
    
    int _sendBinaryTimes;
    std::string  uiUrl;
    
};



#endif /* WebSocketLayer_h */
