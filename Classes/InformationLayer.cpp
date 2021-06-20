#include"InformationLayer.h"
#include "ui/CocosGUI.h"
#define schedule_selector(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)

Layer* InformationLayer::createLayer()
{
	return InformationLayer::create();
}

bool InformationLayer::init()
{
	if (!Layer::create())
		return false;
	/*lv = Label::create();
	money = Label::create();*/
	this->displayLv();
	this->displayHp();
	this->displayCoin();
	this->displayStore();
	this->schedule(schedule_selector(InformationLayer::dataUpdate));
	return true;
}

void InformationLayer::displayLv()
{
	auto Lv = Sprite::create("lv.png");
	Lv->setPosition(Vec2(300, 80));
	Lv->setScale(0.9f);
	this->addChild(Lv,5);
	return;
}

void InformationLayer::displayHp()
{
	hpBar = cocos2d::ui::LoadingBar::create("hpBar.png");
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
	this->addChild(Coin,5);

	return;
}

void InformationLayer::displayStore()
{
	

	return;
}

void InformationLayer::setplayerptr(Play* ptr)
{
	player = ptr;

	return;
}

void InformationLayer::displayNum()
{
	char lvNum[3];
	char moneyNum[4];
	itoa(this->player->getm_lv(), lvNum, 10);
	itoa(this->player->getm_money(), moneyNum, 10);
	lv = Label::createWithTTF(lvNum, "fonts/Marker Felt.ttf", 40);
    money = Label::createWithTTF(moneyNum, "fonts/Marker Felt.ttf", 40);

	lv->setPosition(Vec2(300, 80));
	money->setPosition(Vec2(100, 80));

	this->addChild(lv,7);
	this->addChild(money,7);

	return;
}

void InformationLayer::dataUpdate(float dt)
{
	this->removeChild(lv);
	this->removeChild(money);
	displayNum();

	hpBar->setPercent(player->getm_hp());

	return;
}


