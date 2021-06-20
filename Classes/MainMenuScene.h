#pragma once

#include "ui/CocosGUI.h"
#include"cocos2d.h"

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif 

using namespace cocos2d;


class MainMenu :public Scene
{
public:
	CREATE_FUNC(MainMenu);
	static Scene* createScene();

CC_CONSTRUCTOR_ACCESS:
	//mainMenu();
	//~mainMenu();
	virtual bool init();

private:


	void createButtonLayer();
	void createBackgroundLayer();

	void menuCloseCallback(Ref* pSender);
	void menuPauseCallback(Ref* pSender);
	void menuStartCallback(Ref* pSender);
	void menuMusicCallback(Ref* pSender);
	
private:
	Sprite* sprite[20];
	
};
