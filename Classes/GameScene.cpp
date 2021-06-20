﻿#include"GameScene.h"


Scene* GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	if (!Scene::init())
		return false;
	this->playersinit();
	this->createMapLayer();
	this->createInformationLayer();
	this->createButtons();
	this->createStoreLayer();
	this->creatBattleLayer();
	this->scheduleUpdate();
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
	informationLayer->setplayerptr(playerme);
	informationLayer->displayNum();
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
	storeLayer->setplayerptr(playerme);//绑定玩家指针
	this->addChild(storeLayer, 4);
	return;
}

void GameScene::gamePauseCallback(Ref* pSender)
{
	Director::getInstance()->pushScene(PauseScene::create());

	return;
}
void GameScene::playersinit()
{
	playerme = Play::create();
	this->addChild(playerme);
	playeren = Play::create();
	this->addChild(playeren);
}
void GameScene::creatBattleLayer()
{
	auto battlelayer = BattleLayer::create();
	battlelayer->setplayersptr(playerme, playeren);
	battlelayer->setVisible(0);
	auto startItem = MenuItemImage::create("start.jpg",
		"start2.jpg",
		CC_CALLBACK_0(BattleLayer::startup, battlelayer));
	startItem->setScale(0.25);
	auto menu = Menu::create(startItem, NULL);
	menu->setPosition(Vec2(500, 170));
	this->addChild(menu, 5);
	this->addChild(battlelayer, 5);

}
////////////////////////////////////////
void GameScene::update(float dt)
{
	if (playerme->getm_hp() <= 0)
	{
		auto lose = Scene::create();
		auto label1 = Label::createWithTTF("LOSE", "fonts/Marker Felt.ttf", 140);
		label1->setPosition(Vec2(960, 540));
		lose->addChild(label1);
		Director::getInstance()->pushScene(lose);

		this->unscheduleUpdate();
	}
	else
		if (playeren->getm_hp() <= 0)
		{
			auto win = Scene::create();
			auto label1 = Label::createWithTTF("WIN", "fonts/Marker Felt.ttf", 140);
			label1->setPosition(Vec2(960, 540));
			win->addChild(label1);
			Director::getInstance()->pushScene(win);

			this->unscheduleUpdate();
		}
}