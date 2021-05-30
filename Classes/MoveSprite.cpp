#include "MoveSprite.h"

USING_NS_CC;
bool MoveSprite::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Sprite::init())
    {
       return false;
    }
  //  auto msprite = Sprite::create();
 //   this->addChild(msprite);
  //  auto _mouseListener = EventListenerMouse::create();
  //  _mouseListener->onMouseDown = CC_CALLBACK_1(MoveSprite::onMouseDown, this);
  //  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

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
   // auto local = e->getLocation();
    auto eX = e->getCursorX();
    auto eY = e->getCursorY();
   // auto local = convertToWorldSpace(this->getPosition());
  auto X = this->getPositionX();
   auto Y = this->getPositionY();
    //auto X = local.x;
   // auto Y = local.y;
    auto S = this->getContentSize();
    //auto rect = this->getBoundingBox();
  if ((fabs(X-eX)<S.width/2)&& (fabs(Y - eY) < S.height/2)) 
   // if (eX<100 && eY< 100)
    {

      
        auto _mouseListener = EventListenerMouse::create();
        event->stopPropagation();
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
MoveSprite* MoveSprite::create(const std::string& filename)
{
    MoveSprite* sprite = new (std::nothrow) MoveSprite();
    auto _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseDown = CC_CALLBACK_1(MoveSprite::onMouseDown, sprite);
    sprite->_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, sprite);
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}
