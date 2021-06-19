#include"PauseScene.h"
#include"cocos2d.h"

Scene* PauseScene::createScene()
{
	return PauseScene::create();
}



bool PauseScene::init()
{
	if (!Scene::init())
		return false;

	createMenu();
	createButtonLayer();
	createSliderLayer();
	createLabel();
	//auto item = MenuItemLabel::create("bitmapRed.fnt", "Your Text");

	return true;
}

void PauseScene::createMenu()
{
	//auto myLabel = Label::createWithBMFont("bitmapRed.fnt", "Your Text");

    auto myLabel = Label::createWithSystemFont("return", "Arial", 100);

	auto returnItem = MenuItemLabel::create(myLabel,CC_CALLBACK_1(PauseScene::menuReturnCallBack,this));

	returnItem->setPosition(Vec2(960, 500));

	menuItems.pushBack(returnItem);

	auto menu = Menu::createWithArray(menuItems);

	menu->setPosition(Vec2::ZERO);

	this->addChild(menu);

	return;
}

void PauseScene::createButtonLayer()
{
	ButtonLayer* ButtonLayer = ButtonLayer::create();
	ButtonLayer->removeStartButton();
	ButtonLayer->removePauseButton();
	this->addChild(ButtonLayer,4);
	return;
}

void PauseScene::createSliderLayer()
{
	auto slider = cocos2d::ui::Slider::create();
	slider->loadBarTexture("Slider_Back.png"); 
	slider->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
	slider->loadProgressBarTexture("Slider_PressBar.png");

	slider->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				//std::cout << "slider moved" << std::endl;
				break;
			default:
				break;
		}
		});

	slider->setPosition(Vec2(960, 800));

	this->addChild(slider);

	return;
}

void PauseScene::createLabel()
{
	auto musicLabel = Label::createWithTTF("volume", "fonts/Marker Felt.ttf", 30);

	musicLabel->setPosition(Vec2(800, 800));

	this->addChild(musicLabel);
	return;
}

void PauseScene::menuReturnCallBack(Ref* pSender)
{
	Director::getInstance()->popScene();

	return;
}
