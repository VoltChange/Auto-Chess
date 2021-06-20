#include "MovableSprite.h"

USING_NS_CC;
bool MovableSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    //将鼠标按下事件加入监听
    auto _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseDown = CC_CALLBACK_1(MovableSprite::onMouseDown, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    //初始化name
    name = "";
    return true;
}
void MovableSprite::onMouseMove(cocos2d::Event* event, cocos2d::EventListenerMouse* listener)
{
    //实时获取鼠标位置并移动
    EventMouse* e = (EventMouse*)event;
    this->setPosition(Vec2(e->getCursorX(), e->getCursorY()));

}
void MovableSprite::onMouseDown(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    //获取鼠标位置
    auto eX = e->getCursorX();
    auto eY = e->getCursorY();
    //获取精灵位置与范围
    auto X = this->getPositionX();
    auto Y = this->getPositionY();
    auto S = this->getContentSize();
    //判断点击时鼠标是否在精灵范围内
    if ((fabs(X - eX) < S.width / 2) && (fabs(Y - eY) < S.height / 2))
    {
        auto _mouseListener = EventListenerMouse::create();
        event->stopPropagation();//吞没事件，不让下层监听
        //建立对鼠标移动和松开按键的事件监听
        _mouseListener->onMouseMove = CC_CALLBACK_1(MovableSprite::onMouseMove, this, _mouseListener);
        _mouseListener->onMouseUp = CC_CALLBACK_1(MovableSprite::onMouseUp, this, _mouseListener);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    }
}
void MovableSprite::onMouseUp(cocos2d::Event* event, cocos2d::EventListenerMouse* listener)
{
    //移除对鼠标移动和松开按键的事件监听
    _eventDispatcher->removeEventListener(listener);

}
MovableSprite* MovableSprite::create(const std::string& filename)
{
    MovableSprite* sprite = new (std::nothrow) MovableSprite();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}
void MovableSprite::setname(const string& cardname)
{
    name = cardname;
}
void MovableSprite::changecover(const string& cardname)
{
    this->setname(cardname);//设置卡名
    setTexture(name + ".png");//根据卡名改卡图
}