#include<play2.h>


bool play::init()
{
	this->m_hp = 100;
	this->m_lv = 1;
	this->m_money = 1000;
	this->permitOnSize = 1;

	return true;
}



void play::addMoney(int Money) {            //��Ҽ�
	this->m_money = this->m_money + Money;
}


bool play::reduceMoneyForLv(int Money) {
	if (this->m_money >= Money) {                 //�ж����е�Ǯ��������������е�Ǯ���ȼ��Ӽӣ�������е�Ǯ�������ؼ�
		this->m_money = this->m_money - Money;
		this->m_lv = this->m_lv + E;
		return true;
	}
	else
		return false;
}

bool play::judgeEXP() {//�жϾ����ǲ����㹻����
	if (this->m_lv < 6) {
		if (EXP >= 100)
		{
			EXP = EXP - 100;
			this->m_lv++;
			this->permitOnSize++;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}



bool  play::reduceMoneyForEquipment(int Money, int equipmentNumber,int equipmentPosition) {    //��װ��
	if (this->m_money >= Money)         //�ж�Ǯ�Ƿ��㹻
	{
		this->m_money = this->m_money - Money;
		myEquipment[equipmentPosition]= equipmentNumber;
		return true;
	}
	else
		return false;
}



bool play::reduceMoneyForCard(int Money, int cardNumber, cards* myCard) {          //���ɫ
	if (this->m_money >= Money)     //�ж�Ǯ�Ƿ��㹻
	{
		this->m_money = this->m_money - Money;
		myCard->onCard[myCard->onSize].cardlv = 1;
		myCard->onCard[myCard->onSize].whichCard = cardNumber;
		myCard->onSize++;
		return true;
	}
	else
		return false;
}


int play::onforNumber(cards* myCard, int cardNumber, int cardlv) {
	for (int i = 0;i < myCard->onSize;i++)
	{
		if (myCard->onCard[i].whichCard == cardNumber && myCard->onCard[i].cardlv == cardlv)
		{
			return i;
		}

	}
	return -1;
}



bool play::addlv(int cardNumber, int cardlv, cards* myCard) {   //��������
	if (cardlv < 3) {
		int ret1 = play::onforNumber(myCard, cardNumber, cardlv);
		myCard->onCard[ret1].cardlv++;
		int ret2 = play::onforNumber(myCard, cardNumber, cardlv);
		for (int i = ret2;i < myCard->onSize;i++)//�Գ�����������Ӧ��ɫ����ɾ������
		{
			myCard->onCard[i] = myCard->onCard[i + 1];
		}
		myCard->onSize--;
		return true;
	}
	else
		return false;
}
