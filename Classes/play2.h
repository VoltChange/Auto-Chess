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

class IPlay
{
public:
    virtual bool init()=0;
	virtual void addMoney(int Money)=0;	//��Ҽ�
	virtual bool reduceMoneyForLv(int Money)=0;//����
	virtual bool judgeEXP()=0;	 //�жϾ����ǲ��ǿ�������
	virtual bool reduceMoneyForEquipment(int Money, int equipmentNumber, int equipmentPosition)=0;//��װ��
	virtual bool reduceMoneyForCard(int Money, int cardNumber, cards* myCard)=0;//����
	virtual int onforNumber(cards* myCard, int cardNumber, int cardlv)=0;//Ѱ�ҳ��ϵĽ�ɫ�ı��
	virtual bool addlv(int cardNumber, int cardlv, cards* myCard)=0;//��������
	virtual ~IPlay();
};


class play:public IPlay
{
public:
	bool init();
	void addMoney(int Money);	
	bool reduceMoneyForLv(int Money);
	bool judgeEXP();	 
	bool reduceMoneyForEquipment(int Money, int equipmentNumber, int equipmentPosition);
	bool reduceMoneyForCard(int Money, int cardNumber, cards* myCard);
	int onforNumber(cards* myCard, int cardNumber, int cardlv);
	bool addlv(int cardNumber, int cardlv, cards* myCard);
private:
	int m_lv;
	int m_hp;
	int m_money;
	int EXP;
	const int E = 20;//ÿ���򵽵ľ���ֵ
	cards myCard;
	int myEquipment[MAX];
	int permitOnSize ;
};