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
	const int E = 20;//每回买到的经验值
	cards myCard;
	int myEquipment[MAX];
	int permitOnSize ;
public:
	bool init();
	void addMoney(int Money);	//金币加
	bool reduceMoneyForLv(int Money);//买经验
	bool judgeEXP();	 //判断经验是不是可以升级
	bool reduceMoneyForEquipment(int Money, int equipmentNumber, int equipmentPosition);//买装备
	bool reduceMoneyForCard(int Money, int cardNumber, cards* myCard);//买卡牌
	int onforNumber(cards* myCard, int cardNumber, int cardlv);//寻找场上的角色的编号
	bool addlv(int cardNumber, int cardlv, cards* myCard);//升级卡牌
};