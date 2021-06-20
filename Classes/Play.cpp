#include"Play.h"


bool Play::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	this->m_hp = 100;
	this->m_lv = 1;
	this->m_money = 100;
	this->permitOnSize = 1;

	return true;
}

void Play::addMoney(int Money) {            //��Ҽ�
	this->m_money = this->m_money + Money;
}

bool Play::reduceMoneyForLv(int Money) {
	if (this->m_money >= Money) {                 //�ж����е�Ǯ��������������е�Ǯ���ȼ��Ӽӣ�������е�Ǯ�������ؼ�
		if (this->getm_lv() < 6)
		{
			this->m_money = this->m_money - Money;
			this->m_lv = this->m_lv + 1;//ԭΪthis->m_lv = this->m_lv + E����̫��
			return true;
		}
		else
			return false;
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

bool Play::reduceMoneyForEquipment(int Money, int equipmentNumber, int equipmentPosition) {    //��װ��
	if (this->m_money >= Money&&this->myEquipment.onSize<6)         //�ж�Ǯ�Ƿ��㹻
	{
		int i = 0;
		for (i = 0; i < 6; i++)
		{
			if (!myCard.onCard[i].IsOn())
				break;
		}
		if (i >= 6)
			return false;
		this->m_money = this->m_money - Money;
		myEquipment.onCard[i].initialize(equipmentNumber);
		myEquipment.onCard[i].SetOn(1);//��Ϊ�ϳ�
		myEquipment.onSize++;
		return true;
	}
	else
	{
		return false;
	}
}

bool Play::reduceMoneyForCard(int Money, int cardNumber) {          //���ɫ
	if (this->m_money >= Money&&this->myCard.onSize<6)     //�ж�Ǯ�Ƿ��㹻
	{
		int i = 0;
		for (i = 0; i < 6; i++)
		{
			if (!myCard.onCard[i].IsOn())
				break;
		}
		if (i >= 6)
			return false;
		this->m_money = this->m_money - Money;
		this->myCard.onCard[i].initialize(cardNumber);
		this->myCard.onCard[i].SetOn(1);//��Ϊ�ϳ�
		this->myCard.onSize++;
		return true;
	}
	else
		return false;
}

int Play::onforNumber( int cardNumber, int cardlv) {
	for (int i = 0; i < myCard.onSize; i++)
	{
		if (myCard.onCard[i].getIdentification() == cardNumber && myCard.onCard[i].getLv() == cardlv&& myCard.onCard[i].IsOn())
		{
			return i;
		}

	}
	return -1;
}

bool Play::addlv(int cardNumber, int cardlv) {   //��������
	if (cardlv < 3) {
		int ret1 = Play::onforNumber(cardNumber, cardlv);
		myCard.onCard[ret1].setLv(myCard.onCard[ret1].getLv() + 1);
		int ret2 = Play::onforNumber(cardNumber, cardlv);
		myCard.onCard[ret2].SetOn(0);
		int ret3 = Play::onforNumber(cardNumber, cardlv);
		//�Գ�����������Ӧ��ɫ����ɾ������
		myCard.onCard[ret3].SetOn(0);
		myCard.onSize--;
		myCard.onSize--;
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
	name = "firedragon";
	lv = 1;

	healthpoint = 120;       //HP
	attack = 50;            //������
	atkspeed = 2;          //�����ٶ�
	movespeed = 80;         //�ƶ��ٶ�
	defence = 10;           //������
	atkrange = 320;          //��������
	flyspeed = 320;          //������ķ����ٶ�

	return;
}
void card::setFireSlimeData()
{
	name = "fireslime";
	lv = 1;

	healthpoint = 110;       //HP
	attack = 40;            //������
	atkspeed = 2.2;          //�����ٶ�
	movespeed = 80;         //�ƶ��ٶ�
	defence = 15;           //������
	atkrange = 370;          //��������
	flyspeed = 330;          //������ķ����ٶ�

	return;
}
void card::setGoldSlimeData()
{
	name = "goldslime";
	lv = 1;

	healthpoint = 80;       //HP
	attack = 35;            //������
	atkspeed = 1.8;          //�����ٶ�
	movespeed = 40;         //�ƶ��ٶ�
	defence = 10;           //������
	atkrange = 340;          //��������
	flyspeed = 280;          //������ķ����ٶ�

	return;
}
void card::setMetalSlimeData()
{
	name = "metalslime";
	lv = 1;

	healthpoint = 180;       //HP
	attack = 35;            //������
	atkspeed = 2.2;          //�����ٶ�
	movespeed = 30;         //�ƶ��ٶ�
	defence = 15;           //������
	atkrange = 300;          //��������
	flyspeed = 250;          //������ķ����ٶ�

	return;
}
void card::setShitSlimeData()
{
	name = "shitslime";
	lv = 1;

	healthpoint = 100;       //HP
	attack = 30;            //������
	atkspeed = 2;          //�����ٶ�
	movespeed = 60;         //�ƶ��ٶ�
	defence = 15;           //������
	atkrange = 650;          //��������
	flyspeed = 500;          //������ķ����ٶ�

	return;
}
void card::setHeLinData()
{
	name = "helin";
	lv = 1;

	healthpoint = 60;       //HP
	attack = 30;            //������
	atkspeed = 1.0;          //�����ٶ�
	movespeed = 30;         //�ƶ��ٶ�
	defence = 5;           //������
	atkrange = 350;          //��������
	flyspeed = 750;          //������ķ����ٶ�

	return;
}
void card::setBowData()
{
	name = "bow";
	lv = 1;

	healthpoint = 0;       //HP
	attack = 0;            //������
	atkspeed = 0;          //�����ٶ�
	movespeed = 0;         //�ƶ��ٶ�
	defence = 0;           //������
	atkrange = 500;          //��������
	flyspeed = 300;          //������ķ����ٶ�

	return;
}
void card::setSwordData()
{
	name = "sword";
	lv = 1;

	healthpoint = 0;       //HP
	attack = 20;            //������
	atkspeed = 0;          //�����ٶ�
	movespeed = 0;         //�ƶ��ٶ�
	defence = 0;           //������
	atkrange = 0;          //��������
	flyspeed = 0;          //������ķ����ٶ�

	return;
}
void card::setShieldData()
{
	name = "shield";
	lv = 1;

	healthpoint = 0;       //HP
	attack = 0;            //������
	atkspeed = 0;          //�����ٶ�
	movespeed = 0;         //�ƶ��ٶ�
	defence = 10;           //������
	atkrange = 0;          //��������
	flyspeed = 0;          //������ķ����ٶ�

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

int card::IsOn()
{
	return ison;
}
void card::SetOn(int data)
{
	ison = data;
}



int Play::getm_lv()
{
	return this->m_lv;
}
int Play::getm_hp()
{
	return this->m_hp;
}
int Play::getm_money()
{
	return this->m_money;
}
int Play::getEXP()
{
	return this->EXP;
}
cards Play::getMyCard()
{
	return myCard;
}
cards Play::getMyEquipment()
{
	return myEquipment;
}
void Play::reducehp()
{
	this->m_hp -= 40;
}

bool Play::refreshStore()
{
	if (this->m_money >= 3)
	{
		this->m_money -= 3;
		return true;
	}
	return false;
}
void Play::sellhero(int num)
{
	this->myCard.onCard[num].SetOn(0);
	this->myCard.onSize--;
}
void Play::sellequip(int num)
{
	this->myEquipment.onCard[num].SetOn(0);
	this->myEquipment.onSize--;
}