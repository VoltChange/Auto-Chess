#pragma once
#include"Play.h"
#include"cocos2d.h"
#include"MainMenuScene.h"
#include"PauseScene.h"
#include"InformationLayer.h"
#include"Store.h"
#include"StoreLayer.h"
#include"Card.h"
#include"BattleLayer.h"
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
	void playersinit();
	void createMapLayer();
	void createButtons();
	void createInformationLayer();
	void createStoreLayer();
	void creatBattleLayer();
	void gamePauseCallback(Ref* pSender);

private:
	Menu* menu;
	Vector<MenuItem*> menuItems;
	Play* playerme;
	Play* playeren;
};