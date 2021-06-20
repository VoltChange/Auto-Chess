#pragma once

#include"cocos2d.h"
#include "ui/CocosGUI.h"
#include"Play.h"

using namespace cocos2d;

class InformationLayer :public Layer
{
public:
	CREATE_FUNC(InformationLayer);

	virtual bool init();

	static Layer* createLayer();

	void setplayerptr(Play*);


	void displayNum();

	void dataUpdate(float dt);

private:
	Play* player;

	cocos2d::ui::LoadingBar* hpBar;

	Label* lv;
	Label* money;

	void displayLv();

	void displayHp();

	void displayCoin();

	void displayStore();

};