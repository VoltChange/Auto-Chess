#include"MainMenuScene.h"
//#include"HelloWorldScene.h"
#include"GameScene.h"
#include"PauseScene.h"
//#include"cocos2d.h"
#include<iostream>

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	std::cout << "Error while loading: " << *filename << std::endl;
	std::cout << "Depending on how you compiled you might have to add 'Resources/' in front of filenames in mainMenuScene.cpp" << std::endl;
	return;
}



Scene* MainMenu::createScene()
{
	return MainMenu::create();
}

bool MainMenu::init()
{
	if (!Scene::init())
		return false;

    this->createBackgroundLayer();

	this->createButtonLayer();
	
	return true;
}

void MainMenu::createButtonLayer()
{
	
	ButtonLayer* ButtonLayer = ButtonLayer::create();
	
	this->addChild(ButtonLayer, 4);
	
	return;
}

void MainMenu::createBackgroundLayer()
{
	sprite[0] = Sprite::create("temp.jpg");

	sprite[0]->setPosition(960, 540);

	this->addChild(sprite[0], 1);

	return;
}
