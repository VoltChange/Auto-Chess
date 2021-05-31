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
	static Attack* Attack::create(const std::string& filename);
};

#endif
