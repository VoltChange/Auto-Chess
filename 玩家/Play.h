#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#define MAX 6

using namespace std;

class card
{
private:
	int identification;
	int lv;
    
	double healthpoint;       //HP
	double attack;            //������
	double atkspeed;          //�����ٶ�
	double movespeed;         //�ƶ��ٶ�
	double defence;           //������
	double atkrange;          //��������
	double flyspeed;          //������ķ����ٶ�
	std::string name;         //������
public:
	void initialize(int identification);

	void setFireDragonData();
	void setFireSlimeData();
	void setGoldSlimeData();
	void setMetalSlimeData();
	void setShitSlimeData();
	void setHeLinData();
	void setBowData();
	void setSwordData();
	void setShieldData();

	void setLv(int Lv);
	void setIdentification(int Identification);
	void setHealthpoint(double Healthpoint);
	void setAttack(double Attack);
	void setAtkSpeed(double AtkSpeed);
	void setMoveSpeed(double MoveSpeed);
	void setDefense(double Defense);
	void setAtkRange(double AtkRan);
	void setFlySpeed(double FlySpeed);

	int getLv();
	int getIdentification();
};

class cards
{
public:
	class card onCard[MAX];
	int onSize = 0;
};
class Play
{
private:
	int m_lv;
	int m_hp;
	int m_money;
	int EXP;
	const int E = 20;//ÿ���򵽵ľ���ֵ
	cards myCard;
	cards myEquipment;
	int permitOnSize;
public:
	bool init();
	void addMoney(int Money);	//��Ҽ�
	bool reduceMoneyForLv(int Money);//����
	bool judgeEXP();	 //�жϾ����ǲ��ǿ�������
	bool reduceMoneyForEquipment(int Money, int equipmentNumber,int equipmentPosition);//��װ��
	bool reduceMoneyForCard(int Money, int cardNumber);//����
	int onforNumber(cards* myCard, int cardNumber, int cardlv);//Ѱ�ҳ��ϵĽ�ɫ�ı��
	bool addlv(int cardNumber, int cardlv, cards* myCard);//��������

};