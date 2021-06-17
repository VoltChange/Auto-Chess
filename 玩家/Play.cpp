#include"Play.h"


bool Play::init()
{
	this->m_hp = 100;
	this->m_lv = 1;
	this->m_money = 10;
	this->permitOnSize = 1;

	return true;
}

void Play::addMoney(int Money) {            //��Ҽ�
	this->m_money = this->m_money + Money;
}

bool Play::reduceMoneyForLv(int Money) {
	if (this->m_money >= Money) {                 //�ж����е�Ǯ��������������е�Ǯ���ȼ��Ӽӣ�������е�Ǯ�������ؼ�
		this->m_money = this->m_money - Money;
		this->m_lv = this->m_lv + E;
		return true;
	}
	else
		return false;
}

bool Play::judgeEXP() {//�жϾ����ǲ����㹻����
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

bool Play::reduceMoneyForEquipment(int Money, int equipmentNumber,int equipmentPosition) {    //��װ��
	if (this->m_money >= Money)         //�ж�Ǯ�Ƿ��㹻
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

bool Play::reduceMoneyForCard(int Money, int cardNumber) {          //���ɫ
	if (this->m_money >= Money)     //�ж�Ǯ�Ƿ��㹻
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

bool Play::addlv(int cardNumber, int cardlv, cards* myCard) {   //��������
	if (cardlv < 3) {
		int ret1 = Play::onforNumber(myCard, cardNumber, cardlv);
		myCard->onCard[ret1].setLv(myCard->onCard[ret1].getLv() + 1);
		int ret2 = Play::onforNumber(myCard, cardNumber, cardlv);
		for (int i = ret2; i < myCard->onSize; i++)//�Գ�����������Ӧ��ɫ����ɾ������
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
	attack=10;            //������
	atkspeed=1;          //�����ٶ�
	movespeed=5;         //�ƶ��ٶ�
	defence=50;           //������
	atkrange=100;          //��������
    flyspeed=20;          //������ķ����ٶ�
	
	return;
}
void card::setFireSlimeData()
{
	name = "fireSlimen";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

	return;
}
void card::setGoldSlimeData()
{
	name = "goldSlime";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

	return;
}
void card::setMetalSlimeData()
{
	name = "metalSlime";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

	return;
}
void card::setShitSlimeData()
{
	name = "shitSlime";
	lv = 1;
	
	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

	return;
}
void card::setHeLinData()
{
	name = "helin";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

	return;
}
void card::setBowData()
{
	name = "bow";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

	return;
}
void card::setSwordData()
{
	name = "sword";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

	return;
}
void card::setShieldData()
{
	name = "shield";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 10;            //������
	atkspeed = 1;          //�����ٶ�
	movespeed = 5;         //�ƶ��ٶ�
	defence = 50;           //������
	atkrange = 100;          //��������
	flyspeed = 20;          //������ķ����ٶ�

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