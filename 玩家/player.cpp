#include<player.h>

bool player::init()
{
	this->m_hp = 100;
	this->m_lv = 1;
	this->m_money = 1000;
	

	return true;
}


//��Ǯ��ȼ���
bool player::reduceMoneyForLv(int Money) {
	//�ж����е�Ǯ��������������е�Ǯ���ȼ��Ӽӣ�������е�Ǯ�������ؼ�
	if (this->m_money >= Money) {
		this->m_money = this->m_money - Money;
		this->m_lv = this->m_lv + E;
		return true;
	}
	else
		return false;
}
//�жϾ����ǲ����㹻����
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

//��Ҽ�
void player::addMoney(int Money) {
	this->m_money = this->m_money + Money;
}




//���ɫ
bool player::reduceMoneyForCard(int Money, int cardNumber,  cards* myCard) {
	//�ж�Ǯ�Ƿ��㹻
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




//��װ��
bool  player::reduceMoneyForEquipment(int Money, int equipmentNumber) {
	//�ж�Ǯ�Ƿ��㹻
	if (this->m_money >= Money)
	{
		this->m_money = this->m_money - Money;
		myEquipment[equipmentNumber]++;
		return true;
	}
	else
		return false;

}


//Ѱ��Ҫ�³��Ľ�ɫ�ı��
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

//Ѱ��Ҫ�ϳ��Ľ�ɫ�ı��
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

//�����ϳ��Ľ�ɫ�����Գ�����������Ӧ��ɫ����ɾ������-----------------------
bool player::addShowCard(int cardNumber, cards* myCard, int cardlv) {
	if (myCard->onSize < this->m_lv) {
		int ret = player::offforNumber(myCard, cardNumber, cardlv);
		myCard->onCard[myCard->onSize].cardlv = myCard->offCard[ret].cardlv;
		myCard->onCard[myCard->onSize].whichCard = myCard->offCard[ret].whichCard;
		for (int i = ret;i < myCard->offSize;i++)//�Գ�����������Ӧ��ɫ����ɾ������
		{
			myCard->offCard[i] = myCard->offCard[i + 1];
		}
		myCard->offSize--;
		return true;
	}
	else
		return false;
}

//�����ϳ��Ľ�ɫ,���Գ�����������Ӧ��ɫ����ɾ����������ж����Я����װ��------------------���е����⣬û�취��׼�³�����Ϊ��װ��û���ж�)
void player::reduceShowCard(int cardNumber, cards* myCard, int cardlv) {
	int ret= player::onforNumber(myCard, cardNumber,cardlv);
	myCard->offCard[myCard->offSize].cardlv = myCard->onCard[ret].cardlv;
	myCard->offCard[myCard->offSize].whichCard = myCard->onCard[ret].whichCard;
	myEquipment[1] = myEquipment[1] + myCard->onCard->equipment[0];
	myEquipment[2] = myEquipment[2] + myCard->onCard->equipment[1];
	myEquipment[3] = myEquipment[3] + myCard->onCard->equipment[2];
	for (int i = ret;i < myCard->onSize;i++)//�Գ�����������Ӧ��ɫ����ɾ������
	{
		myCard->onCard[i] = myCard->onCard[i + 1];
	}
	myCard->onSize--;
	                    
}


//��������
bool player::addlv(int cardNumber, int cardlv, cards* myCard) {
	if (cardlv < 3) {
		int ret1= player::offforNumber(myCard, cardNumber, cardlv);
		myCard->offCard[ret1].cardlv++;
		int ret2 = player::offforNumber(myCard, cardNumber, cardlv);
		for (int i = ret2;i < myCard->offSize;i++)//�Գ�����������Ӧ��ɫ����ɾ������
		{
			myCard->offCard[i] = myCard->offCard[i + 1];
		}
		myCard->offSize--;
		return true;
	}
	else
		return false;
}


//װ������                 ���⣺�޷���ȷ��λ�õĽ�ɫ���װ��
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