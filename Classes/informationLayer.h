#pragma once

#include"cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class informationLayer :public Layer
{
public:
	CREATE_FUNC(informationLayer);

	virtual bool init();

	static Layer* createLayer();

private:
	void displayLv();

	void displayHp();

	void displayCoin();

	void displayStore();

	
};