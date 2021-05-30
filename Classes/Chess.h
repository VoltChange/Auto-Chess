#pragma once
#ifndef __CHESS_SPRITE_H__
#define __CHESS_SPRITE_H__

#include "cocos2d.h"
#include <string>
#include <cmath>
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
    std::string ShowName();
    void SetHp(double data);
    void SetAtk(double data);
    void SetAtkSpeed(double data);
    void SetMoveSpeed(double data);
    void SetDef(double data);
    void SetAtkRange(double data);
    void SetName(std::string data);
    void AttackTo(Vec2 position);//���ɹ������ƶ���Ŀ��λ�ã���������дһ���������࣬���ձ���д������������Ӧ�й�����ķ����ٶ�
    void AttackTarget(Chess* target);//��������������һ��Ŀ�����ӵ�ָ�룬��ȡĿ�����ӵ�λ�ã���������ĺ�������һ���������ƶ���Ŀ������λ�ã������Ŀ�����ӿ�Ѫ
    void Reverse(int);
    void MoveTo(Vec2 position);//�����ƶ���Ŀ��λ��
    void MoveTarget(Chess* target);//����Ŀ������λ�þ���Ҫ�ƶ�����λ��
    void Test(cocos2d::Ref* pSender);//���ڵ��ԵĻص�����
private:
    double healthpoint; //HP
    double attack;      //������
    double atkspeed;    //�����ٶ�
    double movespeed;   //�ƶ��ٶ�
    double defence;     //������
    double atkrange;    //��������
    std::string name;   //������
};
#endif