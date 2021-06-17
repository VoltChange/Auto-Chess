#pragma once
#ifndef __ATTACK_H__
#define __ATTACK_H__

#include "Chess.h"
#include "cocos2d.h"
USING_NS_CC;
class Attack : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Attack);
	virtual bool init();
	void setTargetPosition(Vec2 data);//��ʼ��Ŀ��λ��
	void setMark();
	void PointInit(Chess* atktarget);
	void GetAttack(double atk);
	static Attack* Attack::create(const std::string& filename);
	virtual	void update(float dt);
private:
	Vec2 target_position;//Ŀ��λ��
	int mark;//���//0����δ���� 1���������
	Chess* target;//����Ŀ��
	double attack;//���𹥻���chess�Ĺ�����
};

#endif