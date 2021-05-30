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
    if (sprite && sprite->initWithFile(filename+".png"))
    {
        sprite->autorelease();
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
//
void Chess::AttackTo(Vec2 position)
{

}
void Chess::AttackTarget(Chess* target)
{

}

void Chess::MoveTo(Vec2 position)
{

}
void Chess::MoveTarget(Chess* target)
{

}
void Chess::Reverse(int flag)
{

}