#pragma once
#include<iostream>
#include<vector>
#define MAX 100

using namespace std;

class card
{
public:
	int whichCard;
	int cardlv;
};

class cards
{
public:
	class card onCard[MAX];
	int onSize = 0;  
};
class play
{
private:
	int m_lv;
	int m_hp;
	int m_money;
	int EXP;
	const int E = 20;//ÿ���򵽵ľ���ֵ
	cards myCard;
	int myEquipment[MAX];
	int permitOnSize ;
public:
	bool init();
	void addMoney(int Money);	//��Ҽ�
	bool reduceMoneyForLv(int Money);//����
	bool judgeEXP();	 //�жϾ����ǲ��ǿ�������
	bool reduceMoneyForEquipment(int Money, int equipmentNumber, int equipmentPosition);//��װ��
	bool reduceMoneyForCard(int Money, int cardNumber, cards* myCard);//����
	int onforNumber(cards* myCard, int cardNumber, int cardlv);//Ѱ�ҳ��ϵĽ�ɫ�ı��
	bool addlv(int cardNumber, int cardlv, cards* myCard);//��������
};