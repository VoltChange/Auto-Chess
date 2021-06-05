#pragma once

#include"cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class buttonLayer :public Layer
{
public:
	CREATE_FUNC(buttonLayer);

	virtual bool init();

	static Layer* createLayer();

	void removeStartButton();
	void removePauseButton();
private:
	Menu* menu;
	Vector<MenuItem*> menuItems;

	MenuItemImage* startItem;

	MenuItemImage* closeItem;
	MenuItemImage* pauseItem;

	cocos2d::ui::Button* musicItem;

	void createButtons();
	void setButtonScale();
	void setButtonPosition();
	void addButtons();

	void menuCloseCallback(Ref* pSender);
	void menuPauseCallback(Ref* pSender);
	void menuMusicCallback(Ref* pSender);
	void menuStartCallback(Ref* pSender);


};
