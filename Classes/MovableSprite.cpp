#include "MovableSprite.h"

USING_NS_CC;
bool MovableSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    //����갴���¼��������
    auto _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseDown = CC_CALLBACK_1(MovableSprite::onMouseDown, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    //��ʼ��name
    name = "";
    return true;
}
void MovableSprite::onMouseMove(cocos2d::Event* event, cocos2d::EventListenerMouse* listener)
{
    //ʵʱ��ȡ���λ�ò��ƶ�
    EventMouse* e = (EventMouse*)event;
    this->setPosition(Vec2(e->getCursorX(), e->getCursorY()));

}
void MovableSprite::onMouseDown(Event* event)
{
    EventMouse* e = (EventMouse*)event;
    //��ȡ���λ��
    auto eX = e->getCursorX();
    auto eY = e->getCursorY();
    //��ȡ����λ���뷶Χ
    auto X = this->getPositionX();
    auto Y = this->getPositionY();
    auto S = this->getContentSize();
    //�жϵ��ʱ����Ƿ��ھ��鷶Χ��
    if ((fabs(X - eX) < S.width / 2) && (fabs(Y - eY) < S.height / 2))
    {
        auto _mouseListener = EventListenerMouse::create();
        event->stopPropagation();//��û�¼��������²����
        //����������ƶ����ɿ��������¼�����
        _mouseListener->onMouseMove = CC_CALLBACK_1(MovableSprite::onMouseMove, this, _mouseListener);
        _mouseListener->onMouseUp = CC_CALLBACK_1(MovableSprite::onMouseUp, this, _mouseListener);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    }
}
void MovableSprite::onMouseUp(cocos2d::Event* event, cocos2d::EventListenerMouse* listener)
{
    //�Ƴ�������ƶ����ɿ��������¼�����
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
    this->setname(cardname);//���ÿ���
    setTexture(name + ".png");//���ݿ����Ŀ�ͼ
}