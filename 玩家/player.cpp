#include<player.h>

bool player::init()
{
	this->m_hp = 100;
	this->m_lv = 1;
	this->m_money = 1000;
	

	return true;
}


//用钱买等级，
bool player::reduceMoneyForLv(int Money) {
	//判断手中的钱够不够，如果手中的钱够等级加加，如果手中的钱不够返回假
	if (this->m_money >= Money) {
		this->m_money = this->m_money - Money;
		this->m_lv = this->m_lv + E;
		return true;
	}
	else
		return false;
}
//判断经验是不是足够升级
bool player::judgeEXP() {
	if (this->m_lv < 6) {
		if (EXP >= 100)
		{
			EXP = EXP - 100;
			this->m_lv++;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

//金币加
void player::addMoney(int Money) {
	this->m_money = this->m_money + Money;
}




//买角色
bool player::reduceMoneyForCard(int Money, int cardNumber,  cards* myCard) {
	//判断钱是否足够
	if (this->m_money >= Money&&myCard->offSize<7)
	{
		this->m_money = this->m_money - Money;
		myCard->offCard[myCard->offSize].cardlv = 1;
		myCard->offCard[myCard->offSize].whichCard = cardNumber;
		myCard->offSize++;
		return true;
	}
	else
		return false;
}




//买装备
bool  player::reduceMoneyForEquipment(int Money, int equipmentNumber) {
	//判断钱是否足够
	if (this->m_money >= Money)
	{
		this->m_money = this->m_money - Money;
		myEquipment[equipmentNumber]++;
		return true;
	}
	else
		return false;

}


//寻找要下场的角色的编号
int player::onforNumber(cards* myCard, int cardNumber,int cardlv) {
	for (int i = 0;i < myCard->onSize;i++)
	{
		if (myCard->onCard[i].whichCard == cardNumber && myCard->onCard[i].cardlv == cardlv)
		{
			return i;
		}
		
	}
	return -1;
}

//寻找要上场的角色的编号
int player::offforNumber(cards* myCard, int cardNumber,int cardlv) {
	for (int i = 0;i < myCard->offSize;i++)
	{
		if (myCard->offCard[i] .whichCard == cardNumber && myCard->offCard[i].cardlv ==cardlv)
		{
			return i;
		}

	}
	return -1;
}

//增加上场的角色，并对场下数组中相应角色进行删除操作-----------------------
bool player::addShowCard(int cardNumber, cards* myCard, int cardlv) {
	if (myCard->onSize < this->m_lv) {
		int ret = player::offforNumber(myCard, cardNumber, cardlv);
		myCard->onCard[myCard->onSize].cardlv = myCard->offCard[ret].cardlv;
		myCard->onCard[myCard->onSize].whichCard = myCard->offCard[ret].whichCard;
		for (int i = ret;i < myCard->offSize;i++)//对场下数组中相应角色进行删除操作
		{
			myCard->offCard[i] = myCard->offCard[i + 1];
		}
		myCard->offSize--;
		return true;
	}
	else
		return false;
}

//减少上场的角色,并对场上数组中相应角色进行删除操作，并卸掉其携带的装备------------------（有点问题，没办法精准下场，因为对装备没有判断)
void player::reduceShowCard(int cardNumber, cards* myCard, int cardlv) {
	int ret= player::onforNumber(myCard, cardNumber,cardlv);
	myCard->offCard[myCard->offSize].cardlv = myCard->onCard[ret].cardlv;
	myCard->offCard[myCard->offSize].whichCard = myCard->onCard[ret].whichCard;
	myEquipment[1] = myEquipment[1] + myCard->onCard->equipment[0];
	myEquipment[2] = myEquipment[2] + myCard->onCard->equipment[1];
	myEquipment[3] = myEquipment[3] + myCard->onCard->equipment[2];
	for (int i = ret;i < myCard->onSize;i++)//对场上数组中相应角色进行删除操作
	{
		myCard->onCard[i] = myCard->onCard[i + 1];
	}
	myCard->onSize--;
	                    
}


//升级卡牌
bool player::addlv(int cardNumber, int cardlv, cards* myCard) {
	if (cardlv < 3) {
		int ret1= player::offforNumber(myCard, cardNumber, cardlv);
		myCard->offCard[ret1].cardlv++;
		int ret2 = player::offforNumber(myCard, cardNumber, cardlv);
		for (int i = ret2;i < myCard->offSize;i++)//对场下数组中相应角色进行删除操作
		{
			myCard->offCard[i] = myCard->offCard[i + 1];
		}
		myCard->offSize--;
		return true;
	}
	else
		return false;
}


//装备武器                 问题：无法对确定位置的角色添加装备
bool player::addEquipment(int equipmentNumber, int cardNumber, int cardlv, cards* myCard)
{
	int ret = player::onforNumber(myCard, cardNumber, cardlv);
	if (myCard->onCard->equipment[equipmentNumber] == 0 && this->myEquipment[equipmentNumber - 1] != 0) {
		myCard->onCard->equipment[equipmentNumber] = 1;
		this->myEquipment[equipmentNumber - 1]--;
		return true;
	}
	else
		return false;
}