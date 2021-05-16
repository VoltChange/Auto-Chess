#pragma once
#ifndef __MOVE_SPRITE_H__
#define __MOVE_SPRITE_H__

#include "cocos2d.h"
#include <string>
class MoveSprite : public cocos2d::Sprite
{
public:
    virtual bool init();
    void onMouseMove(cocos2d::Event* event, cocos2d::EventListenerMouse* listener);
    void onMouseDown(cocos2d::Event* event);
    void onMouseUp(cocos2d::Event* event,cocos2d::EventListenerMouse*);
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
   // void marioVes(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(MoveSprite);
};
#endif