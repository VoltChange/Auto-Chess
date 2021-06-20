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

	void createMenu();
	void createButtonLayer();
	void createSliderLayer();
	void createLabel();
	void createCheckBox();

	void sliderCallBack(Ref* pSender, cocos2d::ui::Slider::EventType type);

private:



	Vector<MenuItem*> menuItems;

	void menuReturnCallBack(Ref* pSender);
	
};