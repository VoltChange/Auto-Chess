#include"GameScene.h"
#include"MainMenuScene.h"
#include"PauseScene.h"
#include"InformationLayer.h"
#include"Store.h"
#include"StoreLayer.h"
#include"Card.h"
#include"cocos2d.h"

Scene* GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	if (!Scene::init())
		return false;

	this->createMapLayer();
	this->createInformationLayer();
	this->createButtons();
	this->createStoreLayer();
	
	/*auto test = MovableSprite::create();
	test->changecover("firedragon");
	//test->changecover("firedragon.png");
	test->setScale(0.2f);
	test->setPosition(Vec2(500, 500));*/

	/*auto test = Card::create();
	test->changecover("firedragon");
	test->setScale(0.26f);
	test->setAnchorPoint(Vec2(0, 1.0));
	test->setPosition(Vec2(1725, 180));
	//auto listener=EventListenerMouse::
	this->addChild(test);*/
	return true;
}

void GameScene::createMapLayer()
{
	auto map = TMXTiledMap::create("map.tmx");
	
	this->addChild(map, 0, 99); // with a tag of '99'

	return;
}

void GameScene::createInformationLayer()
{
	auto informationLayer = InformationLayer::create();
	this->addChild(informationLayer, 3);
	return;
}

void GameScene::createButtons()
{
	ButtonLayer* ButtonLayer = ButtonLayer::create();
	ButtonLayer->removeStartButton();//remove start button as it is no longer needed
	this->addChild(ButtonLayer, 4);

	return;
}

void GameScene::createStoreLayer()
{
	StoreLayer* storeLayer = StoreLayer::create();
	this->addChild(storeLayer, 4);
	return;
}

void GameScene::gamePauseCallback(Ref* pSender)
{
	Director::getInstance()->pushScene(PauseScene::create());
    
	return;
}