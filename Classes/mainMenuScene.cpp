#include"mainMenuScene.h"
#include"HelloWorldScene.h"
#include"gameScene.h"
#include"pauseScene.h"
//#include"cocos2d.h"
#include<iostream>

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	std::cout << "Error while loading: " << *filename << std::endl;
	std::cout << "Depending on how you compiled you might have to add 'Resources/' in front of filenames in mainMenuScene.cpp" << std::endl;
	return;
}



Scene* mainMenu::createScene()
{
	return mainMenu::create();
}

bool mainMenu::init()
{
	if (!Scene::init())
		return false;

    this->createBackgroundLayer();

	this->createButtonLayer();
	
	return true;
}

void mainMenu::createButtonLayer()
{
	
	buttonLayer* ButtonLayer = buttonLayer::create();
	
	this->addChild(ButtonLayer, 4);
	
	return;
}

void mainMenu::createBackgroundLayer()
{
	sprite[0] = Sprite::create("temp.jpg");

	sprite[0]->setPosition(960, 540);

	this->addChild(sprite[0], 1);

	return;
}
