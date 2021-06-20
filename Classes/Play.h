#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#define MAX 6
#include "cocos2d.h"
using namespace std;
USING_NS_CC;
class card
{
private:
	int identification;
	int lv;

	double healthpoint;       //HP
	double attack;            //攻击力
	double atkspeed;          //攻击速度
	double movespeed;         //移动速度
	double defence;           //防御力
	double atkrange;          //攻击距离
	double flyspeed;          //攻击物的飞行速度
	std::string name;         //卡牌名

	int ison = 0;             //判断是否存在这张卡
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

	int IsOn();
	void SetOn(int);


	double getHealthpoint() { return healthpoint; }
	double getAttack() { return attack; }
	double getAtkSpeed() { return atkspeed; }
	double getMoveSpeed() { return movespeed; }
	double getDefense() { return defence; }
	double getAtkRange() { return atkrange; }
	double getFlySpeed() { return flyspeed; }
	string showName() { return name; }
};

class cards
{
public:
	class card onCard[MAX];
	int onSize = 0;
};
class Play :public cocos2d::Sprite
{
public:
	CREATE_FUNC(Play);
	virtual bool init();
private:
	int m_lv;
	int m_hp;
	int m_money;
	int EXP;
	const int E = 20;//每回买到的经验值
	cards myCard;
	cards myEquipment;
	int permitOnSize;
public:
	void addMoney(int Money);	//金币加
	bool reduceMoneyForLv(int Money);//买经验
	bool judgeEXP();	 //判断经验是不是可以升级
	bool reduceMoneyForEquipment(int Money, int equipmentNumber, int equipmentPosition);//买装备
	bool reduceMoneyForCard(int Money, int cardNumber);//买卡牌
	int onforNumber(cards* myCard, int cardNumber, int cardlv);//寻找场上的角色的编号
	bool addlv(int cardNumber, int cardlv, cards* myCard);//升级卡牌
	int getm_lv();//访问血量
	int getm_hp();
	int getm_money();
	int getEXP();
	cards getMyCard();
	cards getMyEquipment();
};