#include "tst.h"

USING_NS_CC;
bool MoveSprite::init()
{
    //////////////////////////////
    // 1. super init first

    if (!Sprite::init())
    {
        return false;
    }
    auto btn = Sprite::create("MarioNSMBUDeluxe.png");
    this->addChild(btn);
    auto _mouseListener = EventListenerMouse::create();
   // _mouseListener->onMouseMove = CC_CALLBACK_1(MoveSprite::onMouseMove, this);
    _mouseListener->onMouseDown = CC_CALLBACK_1(MoveSprite::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

    return true;
}
void MoveSprite::onMouseMove(cocos2d::Event* event, cocos2d::EventListenerMouse* listener)
{
    // to illustrate the event....
    //auto _mouseListener = EventListenerMouse::create();

    //_mouseListener->onMouseDown = CC_CALLBACK_1(MoveSprite::onMouseDown, this);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    EventMouse* e = (EventMouse*)event;
   //listener->onMouseUp = CC_CALLBACK_1(MoveSprite::onMouseUp, this, listener);
    this->setPosition(Vec2(e->getCursorX(), e->getCursorY()));

}
void MoveSprite::onMouseDown(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    if (e->getCursorX() - this->getPositionX() < 70.0f && e->getCursorY() - this->getPositionY() < 130.0f) {
        auto _mouseListener = EventListenerMouse::create();
        _mouseListener->onMouseMove = CC_CALLBACK_1(MoveSprite::onMouseMove, this, _mouseListener);
        _mouseListener->onMouseUp = CC_CALLBACK_1(MoveSprite::onMouseUp, this, _mouseListener);
        //_mouseListener->onMouseDown = CC_CALLBACK_1(MoveSprite::onMouseDown, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    }
}
void MoveSprite::onMouseUp(cocos2d::Event* event, cocos2d::EventListenerMouse* listener)
{
    _eventDispatcher->removeEventListener(listener);
    
}