#include"Card.h"
#include"MovableSprite.h"
#include"pauseScene.h"

Card* Card::create(const std::string& filename)
{
	return Card::create();
}

bool Card::init()
{
	if (!MovableSprite::create())
		return false;
	cardLv = 1;
	showStar();
	//将鼠标按下事件加入监听
	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseDown = CC_CALLBACK_1(MovableSprite::onMouseDown, this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	//初始化name
	name = "";


	return true;
}

void Card::bought()
{

	return;
}

void Card::sold()
{

	return;
}

void Card::SetName(string Name)
{
	name = Name;
	return;
}

void Card::onMouseDown(Event* event)
{
	EventMouse* mouse = (EventMouse*)event;
	//获取鼠标位置
	auto mouseX = mouse->getCursorX();
	auto mouseY = mouse->getCursorY();
	//获取精灵位置与范围
	auto spriteX = this->getPositionX();
	auto spriteY = this->getPositionY();
	auto spriteS = this->getContentSize();

	//判断点击时鼠标是否在精灵范围内
	if ((fabs(spriteX - mouseX)< (spriteS.width) / 2) && (fabs(spriteY - mouseY) < (spriteS.height) / 2))
	{
		auto _mouseListener = EventListenerMouse::create();
		event->stopPropagation();//吞没事件，不让下层监听
		//建立对鼠标移动和松开按键的事件监听
		_mouseListener->onMouseMove = CC_CALLBACK_1(MovableSprite::onMouseMove, this, _mouseListener);
		_mouseListener->onMouseUp = CC_CALLBACK_1(MovableSprite::onMouseUp, this, _mouseListener);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	}

	return;
}

void Card::onMouseMove(Event* event, EventListenerMouse* listener)
{
	EventMouse* mouse = (EventMouse*)event;
	this->setPosition(Vec2(mouse->getCursorX(), mouse->getCursorY()));
	
	return;
}

void Card::onMouseUp(Event* event, EventListenerMouse* listener)
{
	_eventDispatcher->removeEventListener(listener);
	return;
}

int Card::getIdentification()
{
	return identification;
}

int Card::getCardLv()
{
	return cardLv;
}

void Card::setCardLv(int CardLv)
{
	cardLv = CardLv;

	return;
}

void Card::setIdentification(int Identification)
{
	identification = Identification;

	return;
}

void Card::showStar()
{
	for (int i = 0; i < cardLv ; i++)
	{
		auto star = Sprite::create("star.jpg");

		star->setPosition(Vec2(20 + i * 40, 20));
		star->setScale(0.15f);
		
		this->addChild(star);
	}

	return;
}