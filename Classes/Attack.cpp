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
	mark = 0;//Ĭ�ϳ�ʼδ�ƶ�
}
void Attack::PointInit(Chess* atktarget)
{
	target = atktarget;
}
void Attack::GetAttack(double atk)
{
	attack = atk;
}

void Attack::update(float dt)
{
	Vec2 present_position = this->getPosition();
	double countdistance = sqrt(pow(target_position.x - present_position.x, 2) + pow(target_position.y - present_position.y, 2));
	//if (present_position == target_position)
	if(countdistance<=1)
	{
		mark = 0;
		double distance = sqrt(pow(target_position.x - target->getPositionX(), 2) + pow(target_position.y - target->getPositionY(), 2));//�������
		if (distance <= 50)//����
		{
			target->ReduceHp(attack);
		}
		this->unscheduleUpdate();
		this->setVisible(false);
	}
	else//���ڷ�����
	{
		mark = 1;
	}
}
void Attack::destroy()
{
	if (isupdate)
	{
		this->unscheduleUpdate();
		isupdate = 0;
	}
}