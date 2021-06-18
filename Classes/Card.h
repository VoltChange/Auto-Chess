#pragma once

#include"cocos2d.h"
#include"MovableSprite.h"

using namespace cocos2d;

enum NameOfCard
{
	none = -1,
	fireDragon,//0
	fireSlime,//1
	goldSlime,//2
	metalSlime,//3
	shitSlime,//4
	heLin,//5
	bow,//6
	sword,//7
	shield//8
};

class Card :public MovableSprite
{
public:
    
	virtual bool init();

	CREATE_FUNC(Card);

	static Card* create(const std::string& filename);

	void bought();
	void sold();
	void SetName(string Name);

	int getIdentification();
	int getCardLv();

	virtual void onMouseDown(Event* event);
	virtual void onMouseMove(Event* event, EventListenerMouse* listener);
	virtual void onMouseUp(Event* event, EventListenerMouse* listener);

private:
	string name;
	int originalX, originalY;
	int identification;
	int cardLv;
};
