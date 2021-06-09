#include<BattleLayer.h>
bool BattleLayer::init()
{
	if (!Layer::init())
		return false;
	for (int i = 0; i < MaxSquares; i++)
	{
		self[i] = Chess::create();
		enemy[i] = Chess::create();
	}
	return true;
}
BattleLayer* BattleLayer::createLayer()
{
	return BattleLayer::create();
}
void BattleLayer::test()
{
	self[0]->SetName("miaowa");
	self[1]->SetName("xiaohuo");
	self[2]->SetName("jieni");
	enemy[0]->SetName("pika");
	self[0]->SetOn(TRUE);
	self[1]->SetOn(TRUE);
	self[2]->SetOn(TRUE);
	enemy[0]->SetOn(TRUE);
}
void BattleLayer::reset()
{
	for (int i = 0; i < MaxSquares; i++)
	{
		self[i]->SetDead(false);
		self[i]->SetOn(false);
		enemy[i]->SetDead(false);
		enemy[i]->SetOn(false);
	}
}
void BattleLayer::imageinit()
{
	const int LvS = 3;
	const int LvE = 1;
	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn())
		{
			self[i]->Reverse(1);
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn())
		{
			enemy[i]->Reverse(0);
		}
	}
}
void BattleLayer::onbattle()
{
	const int LvS = 3;
	const int LvE = 1;
	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn())
		{
			this->addChild(self[i]);
			self[i]->setPosition(Vec2(300 * i + 300, 300));
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn())
		{
			this->addChild(enemy[i]);
			enemy[i]->setPosition(Vec2(300 * i + 300, 800));
		}
	}
}