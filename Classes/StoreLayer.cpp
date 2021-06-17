#include"StoreLayer.h"
#include"PauseScene.h"//for test,need delete
#include"Card.h"
#include"Play.h"



bool StoreLayer::init()
{
	if (!Layer::init())
		return false;
	memset(this->preparingAreaOfEquipment, 0, sizeof(this->preparingAreaOfEquipment));
	memset(this->preparingAreaOfSprite, 0, sizeof(this->preparingAreaOfSprite));
	
	player.init();
	store.randFourCards();
	this->createMenuItemOfCards(store.allCards);
	
	return true;
}

Layer* StoreLayer::createLayer()
{
	return StoreLayer::create();
}

void StoreLayer::createMenuItemOfCards(std::vector<int>&allCards)
{
	
	
	auto myLabel = Label::createWithSystemFont("Refresh Store", "Arial", 35);
	auto myLabel1= Label::createWithSystemFont("Buy EXP", "Arial", 35);
	refreshCard = MenuItemLabel::create(myLabel, CC_CALLBACK_1(StoreLayer::refreshCardWithCoins, this));
	buyEXP = MenuItemLabel::create(myLabel1, CC_CALLBACK_1(StoreLayer::buyEXPEithCoins, this));

	cocos2d::Vector<int>::const_iterator it = allCards.end() - 4;
	//create spriteCard
	cardItem[0] = MenuItemImage::create(photoName[*it] + ".png",
		photoName[*it] + "light.png",//need replace
		photoName[*it] + ".png",
		CC_CALLBACK_1(StoreLayer::purchaseCardCallBack0, this));
	cardItem[0]->setName(photoName[*it]);
	it++;
	cardItem[1] = MenuItemImage::create(photoName[*it] + ".png",
		photoName[*it] + "light.png",//need replace
		photoName[*it] + ".png",
		CC_CALLBACK_1(StoreLayer::purchaseCardCallBack1, this));
	cardItem[1]->setName(photoName[*it]);
	it++;
	cardItem[2] = MenuItemImage::create(photoName[*it] + ".png",
		photoName[*it] + "light.png",//need replace
		photoName[*it ] + ".png",
		CC_CALLBACK_1(StoreLayer::purchaseCardCallBack2, this));
	cardItem[2]->setName(photoName[*it]);
	//create equipmentCard
	cardItem[3] = MenuItemImage::create(photoName[allCards.back()] + ".png",
		photoName[allCards.back()] + "light.png",
		photoName[allCards.back() ] + ".png",//need replace
		CC_CALLBACK_1(StoreLayer::purchaseCardCallBack3, this));
	cardItem[3]->setName(photoName[allCards.back()]);
	
	refreshCard->setPosition(Vec2(500, 80));
	buyEXP->setPosition(Vec2(500, 120));

	cardItem[0]->setPosition(Vec2(695, 110));
	cardItem[1]->setPosition(Vec2(695 + 150 * 1, 110));
	cardItem[2]->setPosition(Vec2(695 + 150 * 2, 110));
	cardItem[3]->setPosition(Vec2(1295, 110));

	cardItem[0]->setScale(0.27f);
	cardItem[1]->setScale(0.27f);
	cardItem[2]->setScale(0.27f);
	cardItem[3]->setScale(0.27f);

	storeItems = Menu::create();

	storeItems->addChild(cardItem[0]);
	storeItems->addChild(cardItem[1]);
	storeItems->addChild(cardItem[2]);
	storeItems->addChild(cardItem[3]);
	storeItems->addChild(refreshCard);
	storeItems->addChild(buyEXP);
	//storeItems = Menu::createWithArray(onDisplayCards);
	storeItems->setPosition(Vec2::ZERO);

    this->addChild(storeItems);

	return;
}

void StoreLayer::purchaseCardCallBack0(Ref* pSender)
{
	if (callbackSign[0])
	{
		if (player.reduceMoneyForCard(3, store.allCards.at(store.allCards.size()-4)))
		{
			this->cardItem[0]->getDisabledImage();
			this->cardItem[0]->setEnabled(false);
			cardItem[0]->setColor(Color3B::GRAY);
			sendCardsToPreparingArea(1);
			callbackSign[0] = false;
		}
		else
		{
			//输出警告对话框
		
		}
	}

	return;
}

void StoreLayer::purchaseCardCallBack1(Ref* pSender)
{
	if (callbackSign[1])
	{
		if (player.reduceMoneyForCard(3, store.allCards.at(store.allCards.size() - 3)))
		{
			this->cardItem[1]->getDisabledImage();
			this->cardItem[1]->setEnabled(0);
			cardItem[1]->setColor(Color3B::GRAY);
			sendCardsToPreparingArea(2);
			callbackSign[1] = false;
		}
	}
	return;
}

void StoreLayer::purchaseCardCallBack2(Ref* pSender)
{
	if (callbackSign[2])
	{
		if (player.reduceMoneyForCard(3, store.allCards.at(store.allCards.size() - 2)))
		{
			this->cardItem[2]->getDisabledImage();
			this->cardItem[2]->setEnabled(false);
			cardItem[2]->setColor(Color3B::GRAY);
			sendCardsToPreparingArea(3);
			callbackSign[2] = false;
		}
	}
	return;
}


void StoreLayer::purchaseCardCallBack3(Ref* pSender)
{
	if (callbackSign[3])
	{
		if (player.reduceMoneyForEquipment(3, store.allCards.back(),1))
		{
			cardItem[3]->getDisabledImage();
			cardItem[3]->setEnabled(false);
			cardItem[3]->setColor(Color3B::GRAY);
			sendCardsToPreparingArea(4);
			callbackSign[3] = false;
		}
	}
	return;
}

void StoreLayer::refreshCardWithCoins(Ref* pSender)
{
	store.randFourCards();
	for (int i = 0; i < 4; i++)
	{
		callbackSign[i] = true;
	}
	this->createMenuItemOfCards(store.allCards);
	return;
}

void StoreLayer::buyEXPEithCoins(Ref* pSender)
{
	if (player.reduceMoneyForLv(2))
		;
	return;
}

void StoreLayer::sendCardsToPreparingArea(int tag )
{
	string fileName;
	switch (tag)
	{
		case 1:
		{
			fileName = cardItem[0]->getName();
			break;
		}
		case 2:
		{
			fileName = cardItem[1]->getName();
			break;
		}
		case 3:
		{
			fileName = cardItem[2]->getName();
			break;
		}
		case 4:
		{
			fileName = cardItem[3]->getName();
			break;
		}
		default:
			break;
	}
	if (4 == tag)
	{
		for (int i = 0; i < 6; i++)
		{
			if (preparingAreaOfEquipment[i])//true : ocupied
			{
				;//pass
			}
			else//false : available
			{
				onDisplayEquipments[i] = Card::create();
				onDisplayEquipments[i]->changecover(fileName);
				onDisplayEquipments[i]->setScale(0.26f);
				onDisplayEquipments[i]->setAnchorPoint(Vec2(0.5, 0.5));
				onDisplayEquipments[i]->setPosition(Vec2(cardHeadX2 + 150 * i, cardY));
				preparingAreaOfEquipment[i] = true;
				onDisplayEquipments[i]->SetName(fileName);
				//auto listener=EventListenerMouse::
				this->addChild(onDisplayEquipments[i]);
				i = 6;
			}
		}
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			if (preparingAreaOfSprite[i])//true : ocupied
			{
				;//pass
			}
			else//false : available
			{
				onDisplayCards[i] = Card::create();
				onDisplayCards[i]->changecover(fileName);
				onDisplayCards[i]->setScale(0.26f);
				onDisplayCards[i]->setAnchorPoint(Vec2(0.5, 0.5));
				onDisplayCards[i]->setPosition(Vec2(cardHeadX1 + 150 * i, cardY));
				preparingAreaOfSprite[i] = true;
				//auto listener=EventListenerMouse::
				this->addChild(onDisplayCards[i]);
				i = 6;
			}
		}
	}
	return;
}
