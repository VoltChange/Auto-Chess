#pragma once

#include"cocos2d.h"
#include"buttonLayer.h"

using namespace cocos2d;



class pauseScene :public Scene
{
public:
	CREATE_FUNC(pauseScene);

	static Scene* createScene();

	virtual bool init();

private:
	Vector<MenuItem*> menuItems;

	void createMenu();
	void createButtonLayer();

	void menuReturnCallBack(Ref* pSender);
	
};