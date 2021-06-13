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
	void PointInit(Attack* point);//初始化p_attack
	void setTargetPosition(Vec2 data);//初始化目标位置
	void setMark();
	static Attack* Attack::create(const std::string& filename);
	virtual	void update(float dt);
private:
	Vec2 target_position;//目标位置
	Attack* p_attack;//通过指针获取每一帧攻击物的位置
	int mark;//标记//0代表未移动 1代表飞行中
};

#endif