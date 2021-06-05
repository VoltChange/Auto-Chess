#include"pauseScene.h"
#include"cocos2d.h"

Scene* pauseScene::createScene()
{
	return pauseScene::create();
}



bool pauseScene::init()
{
	if (!Scene::init())
		return false;

	createMenu();
	createButtonLayer();

	//auto item = MenuItemLabel::create("bitmapRed.fnt", "Your Text");

	return true;
}

void pauseScene::createMenu()
{
	//auto myLabel = Label::createWithBMFont("bitmapRed.fnt", "Your Text");

    auto myLabel = Label::createWithSystemFont("click here to return", "Arial", 100);

	auto returnItem = MenuItemLabel::create(myLabel,CC_CALLBACK_1(pauseScene::menuReturnCallBack,this));

	
	//returnItem->setCallback(menuReturnCallBack);

	returnItem->setPosition(Vec2(500, 500));

	menuItems.pushBack(returnItem);

	auto menu = Menu::createWithArray(menuItems);

	menu->setPosition(Vec2::ZERO);

	this->addChild(menu);

	return;
}

void pauseScene::createButtonLayer()
{
	buttonLayer* ButtonLayer = buttonLayer::create();
	ButtonLayer->removeStartButton();
	ButtonLayer->removePauseButton();
	this->addChild(ButtonLayer,4);
	return;
}

void pauseScene::menuReturnCallBack(Ref* pSender)
{
	Director::getInstance()->popScene();

	return;
}
