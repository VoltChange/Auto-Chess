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
	int equipment[3] = {0,0,0};//0代表无，1代表有
};

class cards
{
public:
	class card onCard[MAX];
	class card offCard[MAX];
	int onSize = 0;
	int offSize = 0;
};

class player
{
private:
	int m_lv ;
	int m_hp ;
	int m_money ;
	int EXP;
	const int E = 20;//每回买到的经验值
	cards myCard;
	int myEquipment[4] = { 0,0,0,0 };  //其中1.2.3分别对应1.2.3号武器数量
public:
	 bool init();
	//减少血量      判断的
	 void changeLv() ;
	//显示血量
	 void displayLv();
	//改变血量
	 void changeHp() ;
	//显示血量
	 void displayHp() ;
	//金币加
	 void addMoney(int Money) ;
	 //金币减
	 bool reduceMoneyForLv(int Money);//买经验
	 bool reduceMoneyForEquipment(int Money,int equipmentNumber);//买装备
	 bool reduceMoneyForCard(int Money,int cardNumber,cards*myCard);//买卡牌
	 //判断经验是不是可以升级
	 bool judgeEXP();
	//显示金币
	 void display_money();
	 //改变角色或装备状态
	 //寻找要下场或者要上场的角色的编号
	 int onforNumber(cards* myCard,int cardNumber,int cardlv);//场上的
	 int offforNumber(cards* myCard, int cardNumber,int cardlv);//场下的
	 //增加上场的角色
	 bool addShowCard(int cardNumber, cards* myCard, int cardlv);
	 //减少上场的角色
	 void reduceShowCard(int cardNumber,cards* myCard, int cardlv);
	 //升级卡牌
	 bool addlv(int cardNumber, int cardlv, cards* myCard);
	 //装备武器
	 bool addEquipment(int equipmentNumber,int cardNumber, int cardlv, cards* myCard);
	 
};




