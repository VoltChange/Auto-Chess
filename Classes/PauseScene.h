#pragma once

#include"cocos2d.h"
#include"ButtonLayer.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;



class PauseScene :public Scene
{
public:
	CREATE_FUNC(PauseScene);

	static Scene* createScene();

	virtual bool init();

private:
	Vector<MenuItem*> menuItems;

	void createMenu();
	void createButtonLayer();
	void createSliderLayer();
	void createLabel();

	void menuReturnCallBack(Ref* pSender);
	
};