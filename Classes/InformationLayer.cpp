#include"InformationLayer.h"
#include "ui/CocosGUI.h"

Layer* InformationLayer::createLayer()
{
	return InformationLayer::create();
}

bool InformationLayer::init()
{
	if (!Layer::create())
		return false;

	this->displayLv();
	this->displayHp();
	this->displayCoin();
	this->displayStore();

	return true;
}

void InformationLayer::displayLv()
{
	auto Lv = Sprite::create("lv.png");
	Lv->setPosition(Vec2(300, 80));
	Lv->setScale(0.9f);
	this->addChild(Lv);
	return;
}

void InformationLayer::displayHp()
{
	auto hpBar = cocos2d::ui::LoadingBar::create("hpBar.png");
	hpBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	hpBar->setPosition(Vec2(210, 170));
	hpBar->setScale(3.0f);
	hpBar->setPercent(100);

	this->addChild(hpBar);

	//this->schedule(CC_SCHEDULE_SELECTOR(hpUpdate),2);

	return;
}

void InformationLayer::displayCoin()
{

	auto Coin = Sprite::create("coin.jpg");
	Coin->setPosition(Vec2(100, 80));
	Coin->setScale(0.5f);
	this->addChild(Coin);

	return;
}

void InformationLayer::displayStore()
{
	

	return;
}



