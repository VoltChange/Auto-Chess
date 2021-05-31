#include "Chess.h"

bool Chess::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}

Chess* Chess::create(const std::string& filename)
{
	Chess* sprite = new (std::nothrow) Chess();
	if (sprite && sprite->initWithFile(filename + ".png"))
	{
		sprite->autorelease();
		sprite->SetName(filename);
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
//
double Chess::ShowAtk()
{
	return attack;
}
double Chess::ShowDef()
{
	return defence;
}
double Chess::ShowAtkSpeed()
{
	return atkspeed;
}
double Chess::ShowMoveSpeed()
{
	return movespeed;
}
double Chess::ShowHp()
{
	return healthpoint;
}
double Chess::ShowAtkRange()
{
	return atkrange;
}
double Chess::ShowFlySpeed()
{
	return flyspeed;
}
std::string Chess::ShowName()
{
	return name;
}
void Chess::SetAtk(double data)
{
	attack = data;
}
void Chess::SetDef(double data)
{
	defence = data;
}
void Chess::SetAtkSpeed(double data)
{
	atkspeed = data;
}
void Chess::SetMoveSpeed(double data)
{
	movespeed = data;
}
void Chess::SetHp(double data)
{
	healthpoint = data;
}
void Chess::SetAtkRange(double data)
{
	atkrange = data;
}
void Chess::SetName(std::string data)
{
	name = data;
}
void Chess::SetFlySpeed (double data)
{
	flyspeed = data;
}
void Chess::PointInit(Attack* data)
{
	data = Attack::create();
}
//
void Chess::AttackTo(Vec2 position)
{
	this->getParent()->addChild(p_attack);
	Vec2 present_position = p_attack->getPosition();
	double distance=sqrt(pow(position.x - present_position.x, 2) + pow(position.y - present_position.y, 2));//计算距离
	float time = distance / flyspeed;//算出攻击物需要的时间
	auto attack_move = MoveTo::create(time,position);
	p_attack->runAction(attack_move);
}
void Chess::AttackTarget(Chess* target)
{
	Vec2 target_position = target->getPosition();
	AttackTo(target_position);
	Vec2 present_position = p_attack->getPosition();
	double distance = sqrt(pow(target_position.x - present_position.x, 2) + pow(target_position.y - present_position.y, 2));//计算距离
	if (distance <= 2.0)//攻击物完成攻击之后离目标物的距离
	{
		target->ReduceHp();
	}
	p_attack->removeFromParent();//解除关系
}
void Chess::ReduceHp()
{
	double Hp = ShowHp();
	Hp -= 2;//2是随便写的
	SetHp(Hp);
}

void Chess::MoveTo(Vec2 position)
{
	double distance = sqrt(pow(position.x - this->getPositionX(), 2) + pow(position.y - this->getPositionY(), 2));//计算距离
	const double angle = 30;
	auto move = MoveTo::create(distance / movespeed, position);//移动动作
	//创建晃动动作序列
	auto rotate1 = RotateBy::create(distance / movespeed / 4 / 2, angle);
	auto rotate2 = RotateBy::create(distance / movespeed / 4, -angle * 2);
	auto rotate3 = RotateBy::create(distance / movespeed / 4, angle * 2);
	auto rotate4 = RotateBy::create(distance / movespeed / 4, -angle * 2);
	auto rotate5 = RotateBy::create(distance / movespeed / 4 / 2, angle);
	auto seq1 = Sequence::createWithTwoActions(rotate1, rotate2);
	auto seq2 = Sequence::createWithTwoActions(rotate3, rotate4);
	auto seq3 = Sequence::createWithTwoActions(seq1, seq2);
	auto seq4 = Sequence::createWithTwoActions(seq3, rotate5);
	//移动和晃动同时序列
	auto spa = Spawn::createWithTwoActions(seq4, move);
	this->runAction(spa);
}
void Chess::MoveTarget(Chess* target)
{
	auto position = target->getPosition();//获取目标位置
	double distance = sqrt(pow(position.x - this->getPositionX(), 2) + pow(position.y - this->getPositionY(), 2));//计算距离
	auto unitvector = Vec2(position.x - this->getPositionX(), position.y - this->getPositionY()) / distance;//计算单位向量
	double movedistance;//根据攻击距离和目标棋子位置计算要移动的位置
	if (distance - atkrange > 0)
	{
		movedistance = distance - atkrange;
	}
	else
	{
		movedistance = 0;
	}
	auto targetposition = unitvector * movedistance + this->getPosition();
	this->MoveTo(targetposition);
}
void Chess::Reverse(int flag)
{
	this->setTexture(name + (flag ? "1" : "0") + ".png");
}
void Chess::Test(cocos2d::Ref* pSender)
{
	this->Reverse(0);
	this->SetMoveSpeed(200);
	this->MoveTo(Vec2(1000, 350));
}
