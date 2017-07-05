//
//  DropDownListLayer.h
//  qiuFight
//
//  Created by 张跃东 on 16/4/12.
//
//

#ifndef DropDownListLayer_h
#define DropDownListLayer_h

#include "cocos2d.h"
#include "Global.h"

USING_NS_CC;

class DropDownListLayer : public CPZLayer
{
public:
    DropDownListLayer(CCLabelTTF* label, CCSize size);
    ~DropDownListLayer();
    
    static DropDownListLayer* create(CCLabelTTF* label, CCSize size);
    std::string getString();
    int getSelectedIndex();
    void setSelectedIndex(int index);
    virtual void onEnter();
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    void addLabel(CCLabelTTF* label);
    void onSelected(CCObject* sender);
    void onClose();
    bool isShowDropDown();
    
private:
    CCMenu* mainMenu; // 下拉列表选项的集合
    CCLabelTTF* showLabel; // 显示选中的结果
    std::vector<CCLabelTTF*> selectLabels; //下拉列表label
    std::vector<CCLayerColor*> bgLayers; //设置背景
    bool isShowMenu; //是否显示了下拉列表
    int lastSelectedIndex;  //选中下拉列表的index
};


#endif /* DropDownListLayer_h */
