#include"Play.h"


bool Play::init()
{
	this->m_hp = 100;
	this->m_lv = 1;
	this->m_money = 10;
	this->permitOnSize = 1;

	return true;
}

void Play::addMoney(int Money) {            //金币加
	this->m_money = this->m_money + Money;
}

bool Play::reduceMoneyForLv(int Money) {
	if (this->m_money >= Money) {                 //判断手中的钱够不够，如果手中的钱够等级加加，如果手中的钱不够返回假
		this->m_money = this->m_money - Money;
		this->m_lv = this->m_lv + E;
		return true;
	}
	else
		return false;
}

bool Play::judgeEXP() {//判断经验是不是足够升级
	if (this->m_lv < 6) {
		if (EXP >= 100)
		{
			EXP = EXP - 100;
			this->m_lv++;
			this->permitOnSize++;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Play::reduceMoneyForEquipment(int Money, int equipmentNumber,int equipmentPosition) {    //买装备
	if (this->m_money >= Money)         //判断钱是否足够
	{
		this->m_money = this->m_money - Money;
		myEquipment.onCard[myEquipment.onSize].initialize(equipmentNumber);
		myEquipment.onSize++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Play::reduceMoneyForCard(int Money, int cardNumber) {          //买角色
	if (this->m_money >= Money)     //判断钱是否足够
	{
		this->m_money = this->m_money - Money;
		this->myCard.onCard[this->myCard.onSize].initialize(cardNumber);
		this->myCard.onSize++;
		return true;
	}
	else
		return false;
}

int Play::onforNumber(cards* myCard, int cardNumber, int cardlv) {
	for (int i = 0; i < myCard->onSize; i++)
	{
		if (myCard->onCard[i].getIdentification() == cardNumber && myCard->onCard[i].getLv() == cardlv)
		{
			return i;
		}

	}
	return -1;
}

bool Play::addlv(int cardNumber, int cardlv, cards* myCard) {   //升级卡牌
	if (cardlv < 3) {
		int ret1 = Play::onforNumber(myCard, cardNumber, cardlv);
		myCard->onCard[ret1].setLv(myCard->onCard[ret1].getLv() + 1);
		int ret2 = Play::onforNumber(myCard, cardNumber, cardlv);
		for (int i = ret2; i < myCard->onSize; i++)//对场下数组中相应角色进行删除操作
		{
			myCard->onCard[i] = myCard->onCard[i + 1];
		}
		myCard->onSize--;
		return true;
	}
	else
		return false;
}

void card::initialize(int identification)
{
	switch (identification)
	{
		case 0:
		{
			setFireDragonData();
			break;
		}
		case 1:
		{
			setFireSlimeData();
			break;
		}
		case 2:
		{
			setGoldSlimeData();
			break;
		}
		case 3:
		{
			setMetalSlimeData();
			break;
		}
		case 4:
		{
			setShitSlimeData();
			break;
		}
		case 5:
		{
			setHeLinData();
			break;
		}
		case 6:
		{
			setBowData();
			break;
		}
		case 7:
		{
			setSwordData();
			break;
		}
		case 8:
		{
			setShieldData();
			break;
		}
		default:
			break;
	}
}

void card::setFireDragonData()
{
	name = "fireDragon";
	lv = 1;

	healthpoint=100;       //HP
	attack=10;            //攻击力
	atkspeed=1;          //攻击速度
	movespeed=5;         //移动速度
	defence=50;           //防御力
	atkrange=100;          //攻击距离
    flyspeed=20;          //攻击物的飞行速度
	
	return;
}
void card::setFireSlimeData()
{
	name = "fireSlimen";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}
void card::setGoldSlimeData()
{
	name = "goldSlime";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}
void card::setMetalSlimeData()
{
	name = "metalSlime";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}
void card::setShitSlimeData()
{
	name = "shitSlime";
	lv = 1;
	
	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}
void card::setHeLinData()
{
	name = "helin";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}
void card::setBowData()
{
	name = "bow";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}
void card::setSwordData()
{
	name = "sword";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}
void card::setShieldData()
{
	name = "shield";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //攻击力
	atkspeed = 1;          //攻击速度
	movespeed = 5;         //移动速度
	defence = 50;           //防御力
	atkrange = 100;          //攻击距离
	flyspeed = 20;          //攻击物的飞行速度

	return;
}

void card::setLv(int Lv)
{
	lv = Lv;

	return;
}
void card::setIdentification(int Identification)
{
	identification = Identification;

	return;
}

void card::setHealthpoint(double Healthpoint)
{
	healthpoint = Healthpoint;

	return;
}

void card::setAttack(double Attack)
{
	attack = Attack;

	return;
}

void card::setAtkSpeed(double AtkSpeed)
{
	atkrange = AtkSpeed;

	return;
}

void card::setMoveSpeed(double MoveSpeed)
{
	movespeed = MoveSpeed;

	return;
}

void card::setDefense(double Defense)
{
	defence = Defense;

	return;
}

void card::setAtkRange(double AtkRange)
{
	atkrange = AtkRange;

	return;
}

void card::setFlySpeed(double FlySpeed)
{
	flyspeed = FlySpeed;

	return;
}


int card::getLv()
{
	return lv;
}
int card::getIdentification()
{
	return identification;
}