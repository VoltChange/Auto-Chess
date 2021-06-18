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
	virtual void addMoney(int Money)=0;	//金币加
	virtual bool reduceMoneyForLv(int Money)=0;//买经验
	virtual bool judgeEXP()=0;	 //判断经验是不是可以升级
	virtual bool reduceMoneyForEquipment(int Money, int equipmentNumber, int equipmentPosition)=0;//买装备
	virtual bool reduceMoneyForCard(int Money, int cardNumber, cards* myCard)=0;//买卡牌
	virtual int onforNumber(cards* myCard, int cardNumber, int cardlv)=0;//寻找场上的角色的编号
	virtual bool addlv(int cardNumber, int cardlv, cards* myCard)=0;//升级卡牌
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
	const int E = 20;//每回买到的经验值
	cards myCard;
	int myEquipment[MAX];
	int permitOnSize ;
};