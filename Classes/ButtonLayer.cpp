#include"ButtonLayer.h"
#include"PauseScene.h"
#include"GameScene.h"

Layer* ButtonLayer::createLayer()
{
	return ButtonLayer::create();
}

bool ButtonLayer::init()
{
	if (!Layer::create())
		return false;

	this->createButtons();
	this->setButtonScale();
	this->setButtonPosition();
	this->addButtons();

	return true;
}

void ButtonLayer::menuStartCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene::create());
	return;
}

void ButtonLayer::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	return;
}

void ButtonLayer::menuPauseCallback(Ref* pSender)
{
	Director::getInstance()->pushScene(PauseScene::create());
	return;
}

void ButtonLayer::menuMusicCallback(Ref* pSender)
{
	if (true)//musicOn
		;
	else//musicOff
		;
	return;
}

void ButtonLayer::createButtons()
{
	startItem = MenuItemImage::create("start.jpg",
		"start2.jpg",
		CC_CALLBACK_1(ButtonLayer::menuStartCallback, this));

	closeItem = MenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(ButtonLayer::menuCloseCallback, this));

	pauseItem = MenuItemImage::create("pauseButton1.png",
		"pauseButton2.png",
		CC_CALLBACK_1(ButtonLayer::menuPauseCallback, this));

	musicItem = cocos2d::ui::Button::create("musicOn.jpg", "musicOff.jpg", "musicOff.jpg");
	musicItem->addClickEventListener([this](Ref* pSender) {
		cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(pSender);
		if (true)//musicOn
		{
			button->loadTextures("musicOff.jpg", "musicOff.jpg", "musicOff.jpg");
			;//turn off music
		}
		else//musicOff
		{
			button->loadTextures("musicOn.jpg", "musicOn.jpg", "musicOn.jpg");
			;//turn on music
		}
		});

	return;

}

void ButtonLayer::setButtonScale()
{
	startItem->setScale(0.3f);

	closeItem->setScale(2.0f);
	pauseItem->setScale(0.6f);
	musicItem->setScale(0.1f);
	return;
}

void ButtonLayer::setButtonPosition()
{
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2 - 20;
	float y = origin.y + closeItem->getContentSize().height / 2 + 20;

	closeItem->setPosition(Vec2(x, y));
	pauseItem->setPosition(Vec2(1710,48));
	musicItem->setPosition(Vec2(1800, y));

	startItem->setPosition(Vec2(600, 540));

	return;
}

void ButtonLayer::addButtons()
{
    menuItems.pushBack(pauseItem);
	menuItems.pushBack(closeItem);

	menu = Menu::createWithArray(menuItems);
	menu->setPosition(Vec2::ZERO);

	pauseItem->setTag(1);//tag pauseItem 1
	menu->addChild(startItem, 4, 0);//tag startItem 0

	this->addChild(menu, 4);
	this->addChild(musicItem, 4);

	//pauseItem->setPosition(Vec2(1710, 50));
	
	return;
}

void ButtonLayer::removeStartButton()
{
	menu->removeChildByTag(0);
	return;
}

void ButtonLayer::removePauseButton()
{
	menu->removeChildByTag(1);
	return;
}

