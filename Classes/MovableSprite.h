#pragma once
#ifndef __MOVABLE_SPRITE_H__
#define __MOVABLE_SPRITE_H__

#include "cocos2d.h"
#include <string>
using namespace std;
class MovableSprite : public cocos2d::Sprite
{
public:
    virtual bool init();
    //鼠标监听函数
    void onMouseMove(cocos2d::Event* event, cocos2d::EventListenerMouse* listener);
    void onMouseDown(cocos2d::Event* event);
    void onMouseUp(cocos2d::Event* event,cocos2d::EventListenerMouse*);
    //create相关
    CREATE_FUNC(MovableSprite);
    static MovableSprite* create(const std::string& filename);
    //设置卡名
    void setname(const string& cardname);
    //转换卡图
    void changecover(const string& cardname);
private:
    string name;
};
#endif