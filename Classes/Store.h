#pragma once

#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include<string>

using namespace cocos2d;

class Store
{
public:
	std::vector<int>allCards;//record every cards

	int level;

    void init();

	void purchaseCardCallBack(Ref* pSender);

	void randFourCards();

	void displayCards();

	void autoRefreshCards();//refresh both sprite and equipment

	void refreshSpriteCards();

	void refreshWeaponCards();
	

};