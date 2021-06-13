#pragma once
#ifndef __ATTACK_H__
#define __ATTACK_H__

#include "cocos2d.h"
USING_NS_CC;
class Attack : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Attack);
	virtual bool init();
	void PointInit(Attack* point);//��ʼ��p_attack
	void setTargetPosition(Vec2 data);//��ʼ��Ŀ��λ��
	void setMark();
	static Attack* Attack::create(const std::string& filename);
	virtual	void update(float dt);
private:
	Vec2 target_position;//Ŀ��λ��
	Attack* p_attack;//ͨ��ָ���ȡÿһ֡�������λ��
	int mark;//���//0����δ�ƶ� 1���������
};

#endif