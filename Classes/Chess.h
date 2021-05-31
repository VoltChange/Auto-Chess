#pragma once
#ifndef __CHESS_SPRITE_H__
#define __CHESS_SPRITE_H__

#include "cocos2d.h"
#include <string>
#include <cmath>
#include "Attack.h"
USING_NS_CC;
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
	std::string ShowName();
	void SetHp(double data);
	void SetAtk(double data);
	void SetAtkSpeed(double data);
	void SetMoveSpeed(double data);
	void SetDef(double data);
	void SetAtkRange(double data);
	void SetName(std::string data);
	void SetFlySpeed(double data);
	void PointInit();
	void AttackTo(Vec2 position);//生成攻击物移动至目标位置，可能需求写一个攻击物类，参照本类写法，攻击物类应有攻击物的飞行速度
	void AttackTarget(Chess* target);//攻击函数，传入一个目标棋子的指针，获取目标棋子的位置，调用上面的函数生成一个攻击物移动至目标棋子位置，到达后目标旗子扣血
	void ReduceHp();
	void Reverse(int);
	void MoveTo(Vec2 position);//棋子移动至目标位置
	void MoveTarget(Chess* target);//根据目标棋子位置决定要移动到的位置
	void Test(cocos2d::Ref* pSender);//用于调试的回调函数
private:
	double healthpoint; //HP
	double attack;      //攻击力
	double atkspeed;    //攻击速度
	double movespeed;   //移动速度
	double defence;     //防御力
	double atkrange;    //攻击距离
	double flyspeed;    //攻击物的飞行速度
	std::string name;   //卡牌名
	Attack* p_attack;
};

#endif
