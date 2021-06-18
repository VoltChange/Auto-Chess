#pragma once
#include"cocos2d.h"
#include"Store.h"
#include "ui/CocosGUI.h"
#include"Play.h"
#include"Card.h"
#include"Gamescene.h"

using namespace cocos2d;

//for cardItem[]
static bool callbackSign[4] = { true,true,true,true };

class StoreLayer :public Layer
{
public:
	CREATE_FUNC(StoreLayer);

	virtual bool init(Play*player);

	static Layer* createLayer();

	Store store;
	//Play player;

	MenuItemImage* cardItem[4];
	MenuItemLabel* refreshCard;
	MenuItemLabel* buyEXP;

	const int cardY = 300;
	const int cardHeadX1 = 98;
	const int cardHeadX2 = 1075;
	const Point preparingPositionOfEquipment[6] = { Vec2(1075,300),Vec2(1075 + 150 * 1,300),Vec2(1075 + 150 * 2,300),
												   Vec2(1075 + 150 * 3,300),Vec2(1075 + 150 * 4,300),Vec2(1075 + 150 * 5,300) };
	const Point preparingPositionOfSprite[6] = { Vec2(98,300),Vec2(98 + 150 * 1,300),Vec2(98 + 150 * 2,300),
												   Vec2(98 + 150 * 3,300),Vec2(98 + 150 * 4,300),Vec2(98 + 150 * 5,300) };
	bool preparingAreaOfSprite[6];
	bool preparingAreaOfEquipment[6];

	Menu* storeItems;

	Card* onDisplayCards[6];
	Card* onDisplayEquipments[6];

	const std::string photoName[9] = { "firedragon",
									   "fireslime" ,
									   "goldslime" ,
									   "metalslime",
									   "shitslime" ,
									   "helin",
									   "bow"  ,
									   "sword",
									   "shield" };

	void createMenuItemOfCards(std::vector<int>& allCards);

	void purchaseCardCallBack0(Ref* pSender, Play* player);
	void purchaseCardCallBack1(Ref* pSender, Play* player);
	void purchaseCardCallBack2(Ref* pSender, Play* player);
	void purchaseCardCallBack3(Ref* pSender, Play* player);

	void refreshCardWithCoins(Ref* pSender);
	void buyEXPEithCoins(Ref* pSender, Play* player);



	void sendCardsToPreparingArea(int position);

	void sellCard();
};
