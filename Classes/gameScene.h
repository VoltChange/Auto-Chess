#pragma once

#include"cocos2d.h"

using namespace cocos2d;

class gameScene :public Scene {
public:
	CREATE_FUNC(gameScene);
	static Scene* createScene();

CC_CONSTRUCTOR_ACCESS:
	//gameScene;
	//~gameScene;
	virtual bool init();

private:

	void createMapLayer();
	void createButtons();
	void createInformationLayer();

	void gamePauseCallback(Ref* pSender);

private:
	Menu* menu;
	Vector<MenuItem*> menuItems;
};