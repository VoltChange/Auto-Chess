#pragma once

#include"cocos2d.h"

using namespace cocos2d;

class GameScene :public Scene {
public:
	CREATE_FUNC(GameScene);
	static Scene* createScene();

CC_CONSTRUCTOR_ACCESS:
	//GameScene;
	//~GameScene;
	virtual bool init();

private:

	void createMapLayer();
	void createButtons();
	void createInformationLayer();
	void createStoreLayer();

	void gamePauseCallback(Ref* pSender);

private:
	Menu* menu;
	Vector<MenuItem*> menuItems;
};