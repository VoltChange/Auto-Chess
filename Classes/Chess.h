#pragma once
#ifndef __CHESS_SPRITE_H__
#define __CHESS_SPRITE_H__

#include "cocos2d.h"
#include <string>
#include <cmath>
#include"Play.h"

USING_NS_CC;
class Attack;
class Chess : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Chess);
	virtual bool init();
	static Chess* create(const std::string& filename);
	double ShowHp();
	double ShowAtk();
	double ShowAtkSpeed();
	double ShowMoveSpeed();
	double ShowDef();
	double ShowAtkRange();
	double ShowFlySpeed();
	int IsDead();
	int IsOn();
	std::string ShowName();
	void SetHp(double data);
	void SetAtk(double data);
	void SetAtkSpeed(double data);
	void SetMoveSpeed(double data);
	void SetDef(double data);
	void SetAtkRange(double data);
	void SetName(std::string data);
	void SetFlySpeed(double data);
	double SetAtkTimer(double data);
	double SetMoveTimer();
	void SetAtkMark();
	void SetMovemark();
	void SetMoveTime();
	void AtkTargetInit(Chess* data);
	double CountTheDistance(Vec2 position1, Vec2 position2);//计算两个坐标之间的距离
	void SetDead(int);
	void SetOn(int);
	void PointInit();
	void AttackTo(Vec2 position);//生成攻击物移动至目标位置，可能需求写一个攻击物类，参照本类写法，攻击物类应有攻击物的飞行速度
	void AttackTarget();//攻击函数，传入一个目标棋子的指针，获取目标棋子的位置，调用上面的函数生成一个攻击物移动至目标棋子位置，到达后目标旗子扣血
	void ReduceHp(double atk);
	void Reverse(int);
	void MoveTo(Vec2 position);//棋子移动至目标位置
	void MoveTarget(Chess* target);//根据目标棋子位置决定要移动到的位置
	void Test(cocos2d::Ref* pSender);//用于调试的回调函数
	virtual	void update(float dt);
	Chess* ShowTarget();
	void destroy();//销毁update的包装方法
	void setdatafromcard(card);
	void setatkptrimage();
private:
	double healthpoint;       //HP
	double attack;            //攻击力
	double atkspeed;          //攻击速度
	double movespeed;         //移动速度
	double defence;           //防御力
	double atkrange;          //攻击距离
	double flyspeed;          //攻击物的飞行速度
	std::string name;         //卡牌名
	Attack* p_attack;         //攻击物指针
	double standard_atktimer;    //计数器标准//atktimer=atkspeed*60;
	double standard_movetimer;   //计数器//
	double atktimer;             //真正实现计时器功能
	double movetimer;
	int atkmark;              //记录是否在攻击//0代表未攻击 1代表攻击中
	int movemark;             //记录是否在移动//0代表未移动 1代表移动中
	double move_time;        //移动需要花费的时间//记得初始化
	Chess* atktarget;         //存放目标棋子
	/// /////////////////////////////////////////////////////////////////////
	int isdead;               //记录是否死亡
	int ison;                 //记录是否上场
	int isupdate = 0;       //记录是否在执行update
};

#endif