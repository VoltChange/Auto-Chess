#include"PauseScene.h"
#include"cocos2d.h"
#include "AudioEngine.h"
#include"AppDelegate.h"

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
	createCheckBox();
	//auto item = MenuItemLabel::create("bitmapRed.fnt", "Your Text");

	return true;
}

void PauseScene::createMenu()
{
	//auto myLabel = Label::createWithBMFont("bitmapRed.fnt", "Your Text");

    auto myLabel = Label::createWithSystemFont("return", "Arial", 50);

	auto returnItem = MenuItemLabel::create(myLabel,CC_CALLBACK_1(PauseScene::menuReturnCallBack,this));

	returnItem->setPosition(Vec2(960, 400));

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

	slider->setMaxPercent(100);

	slider->setPercent(AudioEngine::getVolume(musicID1)*100);	

	slider->addEventListener(CC_CALLBACK_2(PauseScene::sliderCallBack, this));

	slider->setPosition(Vec2(1000, 800));

	this->addChild(slider);

	return;
}

void PauseScene::createLabel()
{
	auto musicLabel = Label::createWithTTF("volume", "fonts/Marker Felt.ttf", 50);
	auto musicLabel1 = Label::createWithTTF("sound effect", "fonts/Marker Felt.ttf", 50);

	musicLabel->setPosition(Vec2(800, 800));
	musicLabel1->setPosition(Vec2(800, 600));

	this->addChild(musicLabel);
	this->addChild(musicLabel1);
	return;
}

void PauseScene::createCheckBox()
{
	if (soundEffectSign)
	{
		auto checkbox = ui::CheckBox::create("CheckBoxNode_Normal.png",
			"CheckBox_Press.png",
			"CheckBox_Disable.png",
			"CheckBox_Disable.png",
			"CheckBoxNode_Disable.png");

		checkbox->setPosition(Vec2(1000, 600));

		checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
				case ui::Widget::TouchEventType::BEGAN:
				{
					break;
				}
				case ui::Widget::TouchEventType::ENDED:
				{
					soundEffectSign = false;
					break;
				}
				default:
					break;
			}
			});
		this->addChild(checkbox);
	}
	else
	{
		auto checkbox = ui::CheckBox::create("CheckBoxNode_Disable.png",
			"CheckBox_Press.png",
			"CheckBox_Disable.png",
			"CheckBox_Disable.png",
			"CheckBoxNode_Normal.png");

		checkbox->setPosition(Vec2(1000, 600));

		checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
				case ui::Widget::TouchEventType::BEGAN:
				{
					break;
				}
				case ui::Widget::TouchEventType::ENDED:
				{
					soundEffectSign = true;
					break;
				}
				default:
					break;
			}
			});
		this->addChild(checkbox);
	}

	return;
}

void PauseScene::menuReturnCallBack(Ref* pSender)
{
	if (soundEffectSign)
		AudioEngine::play2d("buttonDown.mp3", false);
	Director::getInstance()->popScene();

	return;
}

void PauseScene::sliderCallBack(Ref* pSender, cocos2d::ui::Slider::EventType type)
{
	auto item = (cocos2d::ui::Slider*)(pSender);
	
	if (item->getPercent() == 100) {
		item->setEnabled(false);
	}
	else {
		AudioEngine::setVolume(musicID1,item->getPercent() / 100.0f);
	}

	return;
}