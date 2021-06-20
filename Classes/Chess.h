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
	double CountTheDistance(Vec2 position1, Vec2 position2);//������������֮��ľ���
	void SetDead(int);
	void SetOn(int);
	void PointInit();
	void AttackTo(Vec2 position);//���ɹ������ƶ���Ŀ��λ�ã���������дһ���������࣬���ձ���д������������Ӧ�й�����ķ����ٶ�
	void AttackTarget();//��������������һ��Ŀ�����ӵ�ָ�룬��ȡĿ�����ӵ�λ�ã���������ĺ�������һ���������ƶ���Ŀ������λ�ã������Ŀ�����ӿ�Ѫ
	void ReduceHp(double atk);
	void Reverse(int);
	void MoveTo(Vec2 position);//�����ƶ���Ŀ��λ��
	void MoveTarget(Chess* target);//����Ŀ������λ�þ���Ҫ�ƶ�����λ��
	void Test(cocos2d::Ref* pSender);//���ڵ��ԵĻص�����
	virtual	void update(float dt);
	Chess* ShowTarget();
	void destroy();//����update�İ�װ����
	void setdatafromcard(card);
	void setatkptrimage();
private:
	double healthpoint;       //HP
	double attack;            //������
	double atkspeed;          //�����ٶ�
	double movespeed;         //�ƶ��ٶ�
	double defence;           //������
	double atkrange;          //��������
	double flyspeed;          //������ķ����ٶ�
	std::string name;         //������
	Attack* p_attack;         //������ָ��
	double standard_atktimer;    //��������׼//atktimer=atkspeed*60;
	double standard_movetimer;   //������//
	double atktimer;             //����ʵ�ּ�ʱ������
	double movetimer;
	int atkmark;              //��¼�Ƿ��ڹ���//0����δ���� 1��������
	int movemark;             //��¼�Ƿ����ƶ�//0����δ�ƶ� 1�����ƶ���
	double move_time;        //�ƶ���Ҫ���ѵ�ʱ��//�ǵó�ʼ��
	Chess* atktarget;         //���Ŀ������
	/// /////////////////////////////////////////////////////////////////////
	int isdead;               //��¼�Ƿ�����
	int ison;                 //��¼�Ƿ��ϳ�
	int isupdate = 0;       //��¼�Ƿ���ִ��update
};

#endif