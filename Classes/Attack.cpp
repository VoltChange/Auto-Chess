#include "Attack.h"

bool Attack::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}

Attack* Attack::create(const std::string& filename)
{
	Attack* sprite = new (std::nothrow) Attack();
	if (sprite && sprite->initWithFile(filename + "attack.png"))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Attack::setTargetPosition(Vec2 data)
{
	target_position = data;
}
void Attack::setMark()
{
	mark = 0;//默认初始未移动
}
void Attack::update(float dt)
{
	Vec2 present_position = this->getPosition();
	double distance = sqrt(pow(target_position.x - present_position.x, 2) + pow(target_position.y - present_position.y, 2));//计算距离
	if (distance <= 5)//击中
	{
		this->unscheduleUpdate();
		this->setVisible(false);
		mark = 0;
	}
	else//还在飞行中
	{
		mark = 1;
	}
}