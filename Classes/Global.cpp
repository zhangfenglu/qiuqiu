#include "Global.h"
#include "CocoStudio/Json/rapidjson/stringbuffer.h"
#include "CocoStudio/Json/rapidjson/writer.h"

#include "spine/extension.h"
#include <ctime>

#include "SimpleAudioEngine.h"
#include "Resources.h"
#include "RichLabel.h"


using namespace rapidjson;



Global::Global(void)
{
	mStringDict  = CCDictionary::createWithContentsOfFile("strings_ch.xml");
	mStringDict->retain();
    
    mainID = 0;
    m_mainIDs.clear();
    m_nets.clear();
    mComName.clear();
    mUserBag.clear();
    m_isConnecting = false;
    mNameColor.clear();
    mCurFightType = 0;
    mQianDaoInfo.clear();
//    netInfo info1;
//    info1.m_netID = 1;
//    info1.m_netUrl = "60.174.233.70";
//    info1.m_netName = "测试一区";
//    info1.m_netPort = "1448";
//    m_nets.push_back(info1);
//    
//    netInfo info2;
//    info2.m_netID = 2;
//    info2.m_netUrl = "60.174.233.70";
//    info2.m_netName = "测试二区";
//    info2.m_netPort = "1449";
//    m_nets.push_back(info2);
    
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey("Syinyue", 0) == 0)
        CCUserDefault::sharedUserDefault()->setIntegerForKey("Syinyue", 1);
    
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey("Syinxiao", 0) == 0)
        CCUserDefault::sharedUserDefault()->setIntegerForKey("Syinxiao", 1);
    
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey("Stuanzhanyaoqing", 0) == 0)
        CCUserDefault::sharedUserDefault()->setIntegerForKey("Stuanzhanyaoqing", 2);
    
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey("Stuqiu", 0) == 0)
        CCUserDefault::sharedUserDefault()->setIntegerForKey("Stuqiu", 2);
    
    centerPos = ccp(0,0);
    PlayBackMusci("yinyue.mp3");
    Resource::sharedResource()->writeDb();
    Resource::sharedResource()->open();
    Resource::sharedResource()->GetComName(mComName);
    Resource::sharedResource()->GetNameColorList(mNameColor);
}

Global::~Global(void)
{
    m_mainIDs.clear();
    m_nets.clear();
    mComName.clear();
    mStringDict->release();
}


const char * Global::getString(const char* en)
{
	if (!mStringDict)
		return en;
	if(!mStringDict->objectForKey(en))
	{ 
		return en;
	}
	else
	{
		return ((CCString*)mStringDict->objectForKey(en))->m_sString.c_str();
	}
}
std::string Global::ComPlayerName(std::string mName)
{
    std::vector<nameMap>::iterator it = mComName.begin();
    for(; it != mComName.end(); ++it)
    {
        nameMap info = *it;
        std::string::size_type pos = mName.find(info.name);
        if (pos == std::string::npos) {
            continue;
        }else{
            return info.icon;
        }
    }
    return "";
}
NameColor Global::GetNameColor(std::string& name)
{
    std::string temName = name;
    int idex = 0;
    if (temName[0] == '[') {
        std::string::size_type pos = temName.find(']');
        std::string tem = temName.substr(1,pos-1);
        idex = atoi(tem.c_str());
        name = temName.substr(pos+1,temName.length()-pos-1);
    }
    
    NameColor color;
    color.mID = 1;
    color.colorR = 0;
    color.colorG = 0;
    color.colorB = 0;
    
    std::vector<NameColor>::iterator it = mNameColor.begin();
    for(; it != mNameColor.end(); ++it)
    {
        NameColor info = *it;
        
        if (info.mID == idex) {
            return info;
        }
    }
    
    return color;
}
void Global::PlayBackMusci(const char* music)
{
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey("Syinyue", 0) == 1)
    {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
            music, true);
    }
}

void Global::StopBackMusci()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
void Global::PlayEffect(const char* music)
{
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey("Syinxiao", 0) == 1)
    {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(music);
    }
}

int  Global::getRand(int maxCount)
{
    srand(time(0)) ;
    int index = rand()%maxCount;
    return index;
}
void Global::addInfoInDoc(rapidjson::Document& writedoc,Json* root,rapidjson::Document::AllocatorType& allocator)
{
    if (root->type == Json_Number) {
        writedoc.AddMember(root->name,root->valuefloat,allocator);
    }else if (root->type == Json_String) {
        writedoc.AddMember(root->name,root->valuestring,allocator);
    }else if(root->type == Json_Array)
    {
        rapidjson::Value arrayAdd(rapidjson::kArrayType);
        pareArray(arrayAdd,root->child,allocator);
        writedoc.AddMember(root->name,arrayAdd,allocator);
    }else if(root->type == Json_Object)
    {
        rapidjson::Value object(rapidjson::kObjectType);
        pareObject(object,root->child,allocator);
        writedoc.AddMember(root->name,object,allocator);
    }
    if (root->next) {
        addInfoInDoc(writedoc,root->next, allocator);
    }
}
void Global::pareObject(rapidjson::Value& object,Json* root,rapidjson::Document::AllocatorType& allocator)
{
    if (root->type == Json_Number) {
        object.AddMember(root->name,root->valuefloat,allocator);
    }else if (root->type == Json_String) {
        object.AddMember(root->name,root->valuestring,allocator);
    }else if(root->type == Json_Array)
    {
        rapidjson::Value arrayAdd(rapidjson::kArrayType);
        pareArray(arrayAdd,root->child,allocator);
        object.AddMember(root->name,arrayAdd,allocator);
    }else if(root->type == Json_Object)
    {
        rapidjson::Value objectAdd(rapidjson::kObjectType);
        pareObject(objectAdd,root->child,allocator);
        object.AddMember(root->name,objectAdd,allocator);
    }
    if (root->next) {
        pareObject(object,root->next, allocator);
    }
}
void Global::pareArray(rapidjson::Value& array,Json* root,rapidjson::Document::AllocatorType& allocator)
{
    if(root->type == Json_Object)
    {
        rapidjson::Value objectAdd(rapidjson::kObjectType);
        pareObject(objectAdd,root->child,allocator);
        array.PushBack(objectAdd, allocator);
    }
    if (root->next) {
        pareArray(array,root->next, allocator);
    }
}

void Global::addMianNode(uint32_t nodeid)
{
    bool isHad = false;
    std::vector<uint32_t>::iterator it = m_mainIDs.begin();
    for(; it != m_mainIDs.end(); ++it)
    {
        uint32_t idx = *it;
        if( idx == nodeid)
        {
            isHad = true;
            break;
        }
    }
    
    if(!isHad)
    {
        m_mainIDs.push_back(nodeid);
    }
}

void Global::deleteMainNode(uint32_t nodeid)
{
    std::vector<uint32_t>::iterator it = m_mainIDs.begin();
    for(; it != m_mainIDs.end();)
    {
        uint32_t idx = *it;
        if(idx == nodeid)
        {
            m_mainIDs.erase(it);
            it++;
            break;
        }
        else
            it++;
    }
}

void Global::clearMainNodes()
{
    m_mainIDs.clear();
}

bool Global::IsMainNode(uint32_t nodeid)
{
    bool isHad = false;
    std::vector<uint32_t>::iterator it = m_mainIDs.begin();
    for(; it != m_mainIDs.end(); ++it)
    {
        uint32_t idx = *it;
        if(idx == nodeid)
        {
            isHad = true;
            break;
        }
    }
    
    return isHad;
}

int Global::getMainNodeNum()
{
    return m_mainIDs.size();
}

std::vector<uint32_t> Global::getMainNodes()
{
    return m_mainIDs;
}

void Global::setJsonImageHead(int ft)
{
    m_imageHeadSize = ft;
}

int Global::getJsonImageHead()
{
    return m_imageHeadSize;
}

void Global::setJsonUpCameraSize(int upCamera)
{
    m_perUpCamera = upCamera;
}

int Global::getJsonUpCameraSize()
{
    return m_perUpCamera;
}

void Global::setJsonUpCameraScale(float ft)
{
    m_perUpCameraScale = ft;
}

float Global::getJsonUpCameraScale()
{
    return m_perUpCameraScale;
}

void Global::setConnectState(bool flag)
{
    m_isConnecting = flag;
}

bool Global::getConnectState()
{
    return m_isConnecting;
}

std::vector<netInfo> Global::getNetInfos()
{
    return m_nets;
}

void Global::addNetInfos(netInfo info)
{
    m_nets.push_back(info);
}

void Global::SetShopItems(std::vector<shop_item> items)
{
    shopItems = items;
}

std::vector<shop_item> Global::GetShopItems()
{
    return shopItems;
}
void Global::AddItemForBag(int mId,user_bag info)
{
    if(info.count)
    {
        mUserBag[mId] = info;
    }
    else {
        for (std::map<int,user_bag>::iterator i = mUserBag.begin(); i!=mUserBag.end(); ) {
            if (i->first == mId) {
                mUserBag.erase(i++);
            }else{
                i++;
            }
        }
    }
}
user_bag Global::GetBagItem(int mID)
{
    std::map<int,user_bag>::iterator iter = mUserBag.begin();
    for (; iter!=mUserBag.end(); iter++) {
        if (iter->first == mID) {
            return iter->second;
        }
    }
    if (iter == mUserBag.end()) {
        user_bag bagIte;
        bagIte.mId = 0;
        bagIte.count = 0;
        return bagIte;
    }
}
void Global::EquipUpdate(int type,int iteID)
{
    if (iteID) {
        m_UserInfo.mEquip[type] = iteID;
    }else {
        for (std::map<int, int>::iterator i = m_UserInfo.mEquip.begin(); i!=m_UserInfo.mEquip.end(); ) {
            if (i->first == type) {
                m_UserInfo.mEquip.erase(i++);
            }else{
                i++;
            }
        }
    }
}
void Global::HeroLeveUp(int heroID,int heroLeve)
{
    m_UserInfo.heroid = heroID;
    m_UserInfo.herolevel = heroLeve;
}
void Global::ShowPromBox(const char* msg)
{
    CCPromBox* box = CCPromBox::create();
    CCScene* sec = CCDirector::sharedDirector()->getRunningScene();
    sec->addChild(box,PormBoxTag,PormBoxTag);
    box->SetTypeAndValue(msg);
}
void Global::ShowPromMoveBox(std::vector<item> vec)
{
    CCPromMoveBox* box = CCPromMoveBox::create();
    CCScene* sec = CCDirector::sharedDirector()->getRunningScene();
    sec->addChild(box,PormBoxTag);
    box->SetTypeAndValue(vec);
}
///////////////////////////////////////CPZLayer
bool CPZLayer::init()
{
    if(!CCLayer::init())
        return false;
    setTouchEnabled(true);
    return true;
}

void CPZLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,PRI,true);
}

bool CPZLayer::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
    return true;
}



Json* ReadJson(const char* path)
{
    int lenght;
    const char* json = _Util_readFile(path, &lenght);
    Json* root = Json_create(json);
    if(!root)
        CCLog("can't open jsonfile %s", path);
    
    FREE(json);
    return root;
}


CCPromBox::CCPromBox()
{
    isTouchIn = false;
}
CCPromBox::~CCPromBox()
{
    
}
bool CCPromBox::init()
{
    if (!CPZLayer::init()) {
        return false;
    }
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(0,0,0,80));
    addChild(layer);
    
    
    /*
     CCLabelTTF* tile = CCLabelTTF::create(Global::getInstance()->getString("cz_tile"),"w7.ttf",35.0f);
     tile->setPosition(ccp(winSize.width/2,winSize.height/2+160));
     tile->setColor(ccc3(0,0,0));
     addChild(tile);
     */
    return true;
}
void CCPromBox::SetTypeAndValue(const char* msg)
{
    /*
    std::ostringstream osDropUpStr;
    osDropUpStr<<"<color><value>0</>"<<msg<<"</></>";
    RichLabel* smalllab = RichLabel::create(osDropUpStr.str().c_str(), "STXingkai.ttf", 30.0f, CCSizeMake(500, 0),false,false);
    smalllab->setPosition(winSize.width/2, winSize.height/2);
    addChild(smalllab,10);
    */
    
    CCLabelTTF* tile = CCLabelTTF::create(msg,"STXingkai.ttf",30.0f);
    tile->setPosition(ccp(winSize.width/2,winSize.height/2));
    tile->setColor(ccc3(0,0,0));
    addChild(tile,10);
    
    CCSprite* back = CCSprite::create("tanmudikuang-01.png");
    back->cocos2d::CCNode::setPosition(ccp(winSize.width/2,winSize.height/2));
    addChild(back,0,tag_menu);
}
bool CCPromBox::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(tag_menu);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, node->getContentSize().width, node->getContentSize().height);
    
    isTouchIn = rt.containsPoint(pt);
    //if(isTouchIn)
    //return false;
    //else
    //return true;
    return true;
}
void CCPromBox::ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent)
{
    if(isTouchIn)
        return;
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(tag_menu);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, node->getContentSize().width*0.9f, node->getContentSize().height*0.9f);
    if(rt.containsPoint(pt) == false)
    {
        getParent()->removeChild(this,true);
    }
}

CCPromMoveBox::CCPromMoveBox()
{
    
}
CCPromMoveBox::~CCPromMoveBox()
{
    
}
bool CCPromMoveBox::init()
{
    if (!CPZLayer::init()) {
        return false;
    }
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(0,0,0,80));
    addChild(layer);
    
    
    /*
     CCLabelTTF* tile = CCLabelTTF::create(Global::getInstance()->getString("cz_tile"),"w7.ttf",35.0f);
     tile->setPosition(ccp(winSize.width/2,winSize.height/2+160));
     tile->setColor(ccc3(0,0,0));
     addChild(tile);
     */
    return true;
}
void CCPromMoveBox::SetTypeAndValue(std::vector<item> vec)
{
    /*
     std::ostringstream osDropUpStr;
     osDropUpStr<<"<color><value>0</>"<<msg<<"</></>";
     RichLabel* smalllab = RichLabel::create(osDropUpStr.str().c_str(), "STXingkai.ttf", 30.0f, CCSizeMake(500, 0),false,false);
     smalllab->setPosition(winSize.width/2, winSize.height/2);
     addChild(smalllab,10);
     */
    
    CCLabelTTF* tile = CCLabelTTF::create("获得物品","STXingkai.ttf",40.0f);
    tile->setPosition(ccp(winSize.width/2,winSize.height/2+220));
    tile->setColor(ccc3(255,255,255));
    addChild(tile,10);
    
    char lab[128] = {0};
    int num = (int)vec.size();
    for (int i = 0; i<num; i++) {
        item ite = vec[i];
        
        sprintf(lab, "%s:%d",ite.itemName.c_str(),ite.maxCount);
        
        tile = CCLabelTTF::create(lab,"STXingkai.ttf",30.0f);
        tile->setPosition(ccp(winSize.width/2-150,winSize.height/2+160-i*35));
        tile->setAnchorPoint(ccp(0.0f,0.5f));
        tile->setColor(ccc3(255,255,255));
        addChild(tile,10);
    }
    
    CCSprite* back = CCSprite::create("touhuandikuang-01.png");
    back->cocos2d::CCNode::setPosition(ccp(winSize.width/2,winSize.height/2));
    //back->setScale(0.6f);
    addChild(back,0,tag_menu);
    
}


bool CCPromMoveBox::ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent)
{
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(tag_menu);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, node->getContentSize().width*0.6f, node->getContentSize().height*0.6f);
    
    isTouchIn = rt.containsPoint(pt);
    //if(isTouchIn)
    //return false;
    //else
    //return true;
    return true;
}
void CCPromMoveBox::ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent)
{
    if(isTouchIn)
        return;
    //CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCNode* node = getChildByTag(tag_menu);
    CCPoint pt = node->convertToNodeSpace(CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView()));
    CCRect rt = CCRectMake(0, 0, node->getContentSize().width*0.6f, node->getContentSize().height*0.6f);
    if(rt.containsPoint(pt) == false)
    {
        getParent()->removeChild(this,true);
    }
}