#include"gameScene.h"
#include"mainMenuScene.h"
#include"pauseScene.h"
#include"informationLayer.h"
#include"cocos2d.h"

Scene* gameScene::createScene()
{
	return gameScene::create();
}

bool gameScene::init()
{
	if (!Scene::init())
		return false;

	this->createMapLayer();
	this->createInformationLayer();
	this->createButtons();
	
	return true;
}

void gameScene::createMapLayer()
{
	auto map = TMXTiledMap::create("map.tmx");
	
	this->addChild(map, 0, 99); // with a tag of '99'

	return;
}

void gameScene::createInformationLayer()
{
	auto informationLayer = informationLayer::create();
	this->addChild(informationLayer, 3);
	return;
}

void gameScene::createButtons()
{

	buttonLayer* ButtonLayer = buttonLayer::create();
	ButtonLayer->removeStartButton();
	this->addChild(ButtonLayer, 4);

	return;
}

void gameScene::gamePauseCallback(Ref* pSender)
{
	//auto pauseScene = pauseScene::createScene();
	Director::getInstance()->pushScene(pauseScene::create());
    
	return;
}