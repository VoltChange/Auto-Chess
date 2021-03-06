#pragma once

#include"cocos2d.h"
#include "ui/CocosGUI.h"
#include"AppDelegate.h"

using namespace cocos2d;

class ButtonLayer :public Layer
{
public:

	bool musicSign = true;

	CREATE_FUNC(ButtonLayer);

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
	void menuStartCallback(Ref* pSender);


};
