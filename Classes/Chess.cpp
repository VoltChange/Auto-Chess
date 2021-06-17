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
int Chess::IsDead()
{
	return isdead;
}
int Chess::IsOn()
{
	return ison;
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
void Chess::SetFlySpeed(double data)
{
	flyspeed = data;
}
void Chess::SetDead(int flag)
{
	isdead = flag;
}
void Chess::SetOn(int flag)
{
	ison = flag;
}
void Chess::SetMoveTime()
{
	move_time = 0;
}
void Chess::PointInit()
{
	p_attack = Attack::create(name);
}
double Chess::SetAtkTimer(double data)
{
	return data * 60;//60帧数
}
double Chess::SetMoveTimer()
{
	return move_time * 60;//60是帧数
}
void Chess::SetAtkMark()
{
	atkmark = 0;//初始化为0，不攻击
}
void Chess::SetMovemark()
{
	movemark = 0;
}
void Chess::AtkTargetInit(Chess* data)
{
	atktarget = data;
}
//
void Chess::AttackTo(Vec2 position)
{
	p_attack->setPosition(this->getPosition());
	p_attack->setVisible(true);
	double time = CountTheDistance(position, p_attack->getPosition()) / flyspeed;//算出攻击物需要的时间

	//攻击物的单个计时器
	p_attack->setTargetPosition(position);//告诉攻击物目标位置
	p_attack->scheduleUpdate();//attack内部注册计时器,会自动注销

	//开始攻击
	auto attack_move = MoveTo::create(time, position);
	p_attack->runAction(attack_move);

}
double Chess::CountTheDistance(Vec2 position1, Vec2 position2)
{
	return sqrt(pow(position1.x - position2.x, 2)
		+ pow(position1.y - position2.y, 2));
}
void Chess::AttackTarget()
{
	//初始化
	standard_atktimer = SetAtkTimer(atkspeed);
	atktimer = standard_atktimer;
	SetMovemark();
	p_attack->PointInit(atktarget);
	p_attack->GetAttack(attack);

	this->getParent()->addChild(p_attack);
	//注册定时器
	this->scheduleUpdate();
}
void Chess::ReduceHp(double atk)
{
	SetHp(ShowHp() -(atk - defence));//atk是攻击方的攻击力
}
void Chess::update(float dt)
{
	//棋子不在移动
	if (0 == movemark)
	{
		//在范围内＆目标不再移动//目标的movemark变更?
		//发动攻击
		if (CountTheDistance(this->getPosition(), atktarget->getPosition()) <= atkrange)
		{
			if (standard_atktimer == atktimer)
			{
				atkmark = 1;
				AttackTo(atktarget->getPosition());//攻击
			}

			atktimer--;
			if (atktimer <= 0)//计时器到零了之后又回复原数，重复攻击
			{
				atktimer = standard_atktimer;
			}

			if ((this->healthpoint)<=0)
			{
				this->isdead = 1;//死亡
			}

			if (this->IsDead()||atktarget->IsDead())//如果死了就停止攻击
			{
				atkmark = 0;
				p_attack->removeFromParent();
				this->unscheduleUpdate();
			}
		}

		//目标不在攻击范围内＆棋子不移动
		else
		{
			movemark = 1;//标记正在移动
			MoveTarget(atktarget);
			standard_movetimer = SetMoveTimer();
			movetimer = standard_movetimer;
		}
	}
	//棋子在移动
	else if (1 == movemark)
	{
		movetimer--;
		if (movetimer <= 0)
		{
			movemark = 0;
			movetimer = standard_movetimer;
			standard_atktimer = SetAtkTimer(atkspeed);
			atktimer = standard_atktimer;
		}
	}
}

void Chess::MoveTo(Vec2 position)
{
	double distance = sqrt(pow(position.x - this->getPositionX(), 2) + pow(position.y - this->getPositionY(), 2));//计算距离
	const double angle = 30;
	auto move = MoveTo::create(distance / movespeed, position);//移动动作
	move_time = distance / movespeed;
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