#include"BattleLayer.h"
Vec2 myfield[6]={ Vec2(930,710),Vec2(810,600),Vec2(1050,600),Vec2(690,475),Vec2(930,475),Vec2(1170,475) };
Vec2 enfield[6] = { Vec2(930,780),Vec2(810,900),Vec2(1050,900),Vec2(690,1000),Vec2(930,1000),Vec2(1170,1000) };
bool BattleLayer::init()
{
	if (!Layer::init())
		return false;
	for (int i = 0; i < MaxSquares; i++)
	{
		self[i] = Chess::create();
		this->addChild(self[i]);
		self[i]->PointInit();
		self[i]->setVisible(0);
		enemy[i] = Chess::create();
		this->addChild(enemy[i]);
		enemy[i]->PointInit();
		enemy[i]->setVisible(0);
	}
	//计时器部分
	time = 0.0f;
	char string[12] = "ceshi";
	//sprintf(string, "%d S", player_me->getm_money());
	auto label1 = Label::createWithTTF(string, "fonts/Marker Felt.ttf", 40);
    this->addChild(label1, 0, 0);
	label1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	label1->setPosition(Vec2(170, 1000));
	label1->setOpacity(200);
	//
	//label1->setString("xixixi");
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
	enemy[0]->SetName("pika");
	self[0]->SetOn(TRUE);
	self[1]->SetOn(TRUE);
	enemy[0]->SetOn(TRUE);
	self[0]->SetHp(70);
	self[1]->SetHp(40);
	enemy[0]->SetHp(7000);
	self[0]->SetAtk(70);
	self[1]->SetAtk(70);
	enemy[0]->SetAtk(70);
	self[0]->SetDef(10);
	self[1]->SetDef(10);
	enemy[0]->SetDef(10);
	self[0]->SetAtkSpeed(4);
	self[1]->SetAtkSpeed(3.5);
	enemy[0]->SetAtkSpeed(4);
	self[0]->SetMoveSpeed(100);
	self[1]->SetMoveSpeed(100);
	enemy[0]->SetMoveSpeed(100);
	self[0]->SetAtkRange(1100);
	self[1]->SetAtkRange(300);
	enemy[0]->SetAtkRange(600);
	self[0]->SetFlySpeed(100);
	self[1]->SetFlySpeed(130);
	enemy[0]->SetFlySpeed(400);
	self[0]->PointInit();
	self[1]->PointInit();
	enemy[0]->PointInit();
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
	const int LvS = player_me->getm_lv();
	const int LvE = player_en->getm_lv();
	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn())
		{
			self[i]->Reverse(1);
			//self[i]->setatkptrimage();
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn())
		{
			enemy[i]->Reverse(0);
			//enemy[i]->setatkptrimage();
		}
	}
}
void BattleLayer::onbattle()
{
	isbattle = 1;
	const int LvS = player_me->getm_lv();
	const int LvE = player_en->getm_lv();
	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn())
		{
			self[i]->setVisible(1);
			self[i]->setPosition(myfield[i]);
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn())
		{
			enemy[i]->setVisible(1);
			enemy[i]->setPosition(enfield[i]);
		}
	}
}
void BattleLayer::start()
{
	const int LvS = player_me->getm_lv();
	const int LvE = player_en->getm_lv();
	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn() && (!self[i]->IsDead()))
		{
			for (int j = 0; j < LvE; j++)
			{
				if (enemy[j]->IsOn() && (!enemy[i]->IsDead()))
				{
					self[i]->AtkTargetInit(enemy[j]);
					self[i]->AttackTarget();
					break;
				}
			}
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn() && (!enemy[i]->IsDead()))
		{
			for (int j = 0; j < LvS; j++)
			{
				if (self[j]->IsOn() && (!self[i]->IsDead()))
				{
					enemy[i]->AtkTargetInit(self[j]);
					enemy[i]->AttackTarget();
					break;
				}
			}
		}
	}
	this->scheduleUpdate();
}
void BattleLayer::update(float dt)
{
	end();
	searchtarget();
}
void BattleLayer::test2()
{
	enemy[0]->AtkTargetInit(self[0]);
	enemy[0]->AttackTarget();
	self[0]->AtkTargetInit(enemy[0]);
	self[0]->AttackTarget();
	self[1]->AtkTargetInit(enemy[0]);
	self[1]->AttackTarget();
}
int BattleLayer::isend()
{
	const int LvS = player_me->getm_lv();
	const int LvE = player_en->getm_lv();
	int myon = 0;//????????????????????????????????
	int mydead = 0;
	int enon = 0;
	int endead = 0;
	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn())
			myon++;
		if (self[i]->IsDead())
			mydead++;
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn())
			enon++;
		if (enemy[i]->IsDead())
			endead++;
	}
	if (myon == mydead)
		return 2;
	if (enon == endead)
		return 1;

	return 0;
}
void BattleLayer::end()
{
	if (isbattle)
	{
		if (isend())
		{
			this->unscheduleUpdate();
			this->unschedule("step_key");
			//扣血
			//
			this->destroy();//销毁所有update
			//this->setVisible(0);
			isbattle = 0;
		}
	}
}
void BattleLayer::searchtarget()
{
	const int LvS = player_me->getm_lv();
	const int LvE = player_en->getm_lv();

	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn() && (!self[i]->IsDead()))
		{
			if (self[i]->ShowTarget()->IsDead())
			{
				for (int j = 0; j < LvE; j++)
				{
					if (enemy[j]->IsOn() && (!enemy[j]->IsDead()))
					{
						self[i]->AtkTargetInit(enemy[j]);
						//self[i]->AttackTarget();
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn() && (!enemy[i]->IsDead()))
		{
			if (enemy[i]->ShowTarget()->IsDead())
			{
				for (int j = 0; j < LvS; j++)
				{
					if (self[j]->IsOn() && (!self[j]->IsDead()))
					{
						enemy[i]->AtkTargetInit(self[j]);
						//enemy[i]->AttackTarget();
						break;
					}
				}
			}
		}
	}
}
void BattleLayer::destroy()
{
	const int LvS = player_me->getm_lv();
	const int LvE = player_en->getm_lv();
	
	for (int i = 0; i < LvS; i++)
	{
		if (self[i]->IsOn())
		{
			self[i]->destroy();
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		if (enemy[i]->IsOn())
		{
			enemy[i]->destroy();
		}
	}
}
void BattleLayer::startup()
{
	time = 0.0f;//计时重置
	this->setVisible(1);//设置可见
	this->reset();//重置棋子状态
	//this->test();
	this->enemygenerate();
	this->setchessdata();
	this->imageinit();//加载场上棋子图片资源
	this->onbattle(); //棋子上场
	this->start();
	this->scheduleUpdate();
	this->schedule(CC_CALLBACK_1(BattleLayer::step, this), "step_key");

}
void BattleLayer::step(float dt)
{
	time += dt;
	char string[12] = { 0 };
	sprintf(string, "%2.1f S", time);   //加载时间的字符串，精确到0.1秒的
	//sprintf(string, "%d", (int)time); //精确到1秒的
	auto label1 = (Label*)getChildByTag(0);//通过标识找到label
	label1->setString(string);             //设置字符串
}
void BattleLayer::setchessdata()
{
	const int LvS = player_me->getm_lv();
	const int LvE = player_en->getm_lv();
	cards hero_me = player_me->getMyCard();
	cards equip_me = player_me->getMyEquipment();
	cards hero_en = player_en->getMyCard();
	cards equip_en = player_en->getMyEquipment();
	for (int i = 0; i < LvS; i++)
	{
		card cardhero = hero_me.onCard[i];
		card cardequip = equip_me.onCard[i];
		if (cardhero.IsOn())
		{
			//开始获取数据
			self[i]->setdatafromcard(cardhero);
			self[i]->SetOn(1);
			if (cardequip.IsOn())//如果该位置有装备卡
			{
				self[i]->SetAtk(self[i]->ShowAtk() + cardequip.getAttack());
				self[i]->SetDef(self[i]->ShowDef() + cardequip.getDefense());
				self[i]->SetAtkRange(self[i]->ShowAtkRange() + cardequip.getAtkRange());
			}
		}
	}
	for (int i = 0; i < LvE; i++)
	{
		card cardhero = hero_en.onCard[i];
		card cardequip = equip_en.onCard[i];
		if (cardhero.IsOn())
		{
			//开始获取数据
			enemy[i]->setdatafromcard(cardhero);
			enemy[i]->SetOn(1);
			if (cardequip.IsOn())//如果该位置有装备卡
			{
				enemy[i]->SetAtk(enemy[i]->ShowAtk() + cardequip.getAttack());
				enemy[i]->SetDef(enemy[i]->ShowDef() + cardequip.getDefense());
				enemy[i]->SetAtkRange(enemy[i]->ShowAtkRange() + cardequip.getAtkRange());
			}
		}
	}
}
void BattleLayer::setplayersptr(Play* ptr1, Play* ptr2)
{
	player_me = ptr1;
	player_en = ptr2;
}
void BattleLayer::enemygenerate()
{
	player_en->reduceMoneyForCard(0, 0);

}