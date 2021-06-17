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
	void setTargetPosition(Vec2 data);//初始化目标位置
	void setMark();
	void PointInit(Chess* atktarget);
	void GetAttack(double atk);
	static Attack* Attack::create(const std::string& filename);
	virtual	void update(float dt);
private:
	Vec2 target_position;//目标位置
	int mark;//标记//0代表未飞行 1代表飞行中
	Chess* target;//攻击目标
	double attack;//发起攻击的chess的攻击力
};

#endif