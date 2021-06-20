#include "Chess.h"
#include "Attack.h"
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
	p_attack = Attack::create();
	this->getParent()->addChild(p_attack);
}
double Chess::SetAtkTimer(double data)
{
	return data * 60;//60֡��
}
double Chess::SetMoveTimer()
{
	return move_time * 60;//60��֡��
}
void Chess::SetAtkMark()
{
	atkmark = 0;//��ʼ��Ϊ0��������
}
void Chess::SetMovemark()
{
	movemark = 0;
}
void Chess::AtkTargetInit(Chess* data)
{
	atktarget = data;
	this->p_attack->PointInit(data);
}
//
void Chess::AttackTo(Vec2 position)
{
	p_attack->setPosition(this->getPosition());
	p_attack->setVisible(true);
	double time = CountTheDistance(position, p_attack->getPosition()) / flyspeed;//�����������Ҫ��ʱ��

	//������ĵ�����ʱ��
	p_attack->setTargetPosition(position);//���߹�����Ŀ��λ��
	p_attack->scheduleUpdate();//attack�ڲ�ע���ʱ��,���Զ�ע��

	//��ʼ����
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
	//��ʼ��
	standard_atktimer = SetAtkTimer(atkspeed);
	atktimer = standard_atktimer;
	SetMovemark();
	this->setatkptrimage();
	p_attack->GetAttack(attack);

	//this->getParent()->addChild(p_attack);
	//ע�ᶨʱ��
	this->scheduleUpdate();
}
void Chess::ReduceHp(double atk)
{
	SetHp(ShowHp() - (atk - defence));//atk�ǹ������Ĺ�����
}
void Chess::update(float dt)
{
	if ((this->healthpoint) <= 0)
	{
		this->isdead = 1;//����
		this->setVisible(0);
	}

	if (this->IsDead())//������˾�ֹͣ����
	{
		atkmark = 0;
		p_attack->setVisible(0);
		this->unscheduleUpdate();
	}
	//���Ӳ����ƶ�
	if (0 == movemark)
	{
		//�ڷ�Χ�ڣ�Ŀ�겻���ƶ�//Ŀ���movemark���?
		//��������
		if (CountTheDistance(this->getPosition(), atktarget->getPosition()) <= atkrange + 20)
		{
			if (standard_atktimer <= atktimer)//(standard_atktimer == atktimer)
			{
				atkmark = 1;
				AttackTo(atktarget->getPosition());//����
			}

			atktimer--;
			if (atktimer <= 0)//��ʱ��������֮���ֻظ�ԭ�����ظ�����
			{
				atktimer = standard_atktimer;
			}

			//////////////////////////////
		}

		//Ŀ�겻�ڹ�����Χ�ڣ����Ӳ��ƶ�
		else
		{
			movemark = 1;//��������ƶ�
			p_attack->setVisible(0);
			MoveTarget(atktarget);
			standard_movetimer = SetMoveTimer();
			movetimer = standard_movetimer;
		}
	}
	//�������ƶ�
	else if (1 == movemark)
	{
		movetimer--;
		if (movetimer <= 0)
		{
			movemark = 0;
			//movetimer = standard_movetimer;
			standard_atktimer = SetAtkTimer(atkspeed);
			atktimer = standard_atktimer;
		}
	}
	isupdate = 1;
}

void Chess::MoveTo(Vec2 position)
{
	double distance = sqrt(pow(position.x - this->getPositionX(), 2) + pow(position.y - this->getPositionY(), 2));//�������
	const double angle = 30;
	auto move = MoveTo::create(distance / movespeed, position);//�ƶ�����
	move_time = distance / movespeed;
	//�����ζ���������
	auto rotate1 = RotateBy::create(distance / movespeed / 4 / 2, angle);
	auto rotate2 = RotateBy::create(distance / movespeed / 4, -angle * 2);
	auto rotate3 = RotateBy::create(distance / movespeed / 4, angle * 2);
	auto rotate4 = RotateBy::create(distance / movespeed / 4, -angle * 2);
	auto rotate5 = RotateBy::create(distance / movespeed / 4 / 2, angle);
	auto seq1 = Sequence::createWithTwoActions(rotate1, rotate2);
	auto seq2 = Sequence::createWithTwoActions(rotate3, rotate4);
	auto seq3 = Sequence::createWithTwoActions(seq1, seq2);
	auto seq4 = Sequence::createWithTwoActions(seq3, rotate5);
	//�ƶ��ͻζ�ͬʱ����
	auto spa = Spawn::createWithTwoActions(seq4, move);
	this->runAction(spa);
}
void Chess::MoveTarget(Chess* target)
{
	auto position = target->getPosition();//��ȡĿ��λ��
	double distance = sqrt(pow(position.x - this->getPositionX(), 2) + pow(position.y - this->getPositionY(), 2));//�������
	auto unitvector = Vec2(position.x - this->getPositionX(), position.y - this->getPositionY()) / distance;//���㵥λ����
	double movedistance;//���ݹ��������Ŀ������λ�ü���Ҫ�ƶ���λ��
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
///////////////////////////////////////////////////////////////////
Chess* Chess::ShowTarget()
{
	return atktarget;
}
void Chess::destroy()
{
	if (isupdate)
	{
		this->unscheduleUpdate();
		isupdate = 0;
		//p_attack->destroy();
	}
}
void Chess::setdatafromcard(card instance)
{
	this->SetName(instance.showName());
	this->SetHp(instance.getHealthpoint());
	this->SetAtk(instance.getAttack());
	this->SetAtkSpeed(instance.getAtkSpeed());
	this->SetMoveSpeed(instance.getMoveSpeed());
	this->SetDef(instance.getDefense());
	this->SetAtkRange(instance.getAtkRange());
	this->SetFlySpeed(instance.getFlySpeed());
}
void Chess::setatkptrimage()
{
	p_attack->setTexture(name + "attack.png");
}