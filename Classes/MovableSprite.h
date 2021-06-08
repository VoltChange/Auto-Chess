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
    //����������
    void onMouseMove(cocos2d::Event* event, cocos2d::EventListenerMouse* listener);
    void onMouseDown(cocos2d::Event* event);
    void onMouseUp(cocos2d::Event* event,cocos2d::EventListenerMouse*);
    //create���
    CREATE_FUNC(MovableSprite);
    static MovableSprite* create(const std::string& filename);
    //���ÿ���
    void setname(const string& cardname);
    //ת����ͼ
    void changecover(const string& cardname);
private:
    string name;
};
#endif