#pragma once
#include<iostream>
#include<vector>
#define MAX 100

using namespace std;

class card
{
public:
	int whichCard;
	int cardlv;
	int equipment[3] = {0,0,0};//0�����ޣ�1������
};

class cards
{
public:
	class card onCard[MAX];
	class card offCard[MAX];
	int onSize = 0;
	int offSize = 0;
};

class player
{
private:
	int m_lv ;
	int m_hp ;
	int m_money ;
	int EXP;
	const int E = 20;//ÿ���򵽵ľ���ֵ
	cards myCard;
	int myEquipment[4] = { 0,0,0,0 };  //����1.2.3�ֱ��Ӧ1.2.3����������
public:
	 bool init();
	//����Ѫ��      �жϵ�
	 void changeLv() ;
	//��ʾѪ��
	 void displayLv();
	//�ı�Ѫ��
	 void changeHp() ;
	//��ʾѪ��
	 void displayHp() ;
	//��Ҽ�
	 void addMoney(int Money) ;
	 //��Ҽ�
	 bool reduceMoneyForLv(int Money);//����
	 bool reduceMoneyForEquipment(int Money,int equipmentNumber);//��װ��
	 bool reduceMoneyForCard(int Money,int cardNumber,cards*myCard);//����
	 //�жϾ����ǲ��ǿ�������
	 bool judgeEXP();
	//��ʾ���
	 void display_money();
	 //�ı��ɫ��װ��״̬
	 //Ѱ��Ҫ�³�����Ҫ�ϳ��Ľ�ɫ�ı��
	 int onforNumber(cards* myCard,int cardNumber,int cardlv);//���ϵ�
	 int offforNumber(cards* myCard, int cardNumber,int cardlv);//���µ�
	 //�����ϳ��Ľ�ɫ
	 bool addShowCard(int cardNumber, cards* myCard, int cardlv);
	 //�����ϳ��Ľ�ɫ
	 void reduceShowCard(int cardNumber,cards* myCard, int cardlv);
	 //��������
	 bool addlv(int cardNumber, int cardlv, cards* myCard);
	 //װ������
	 bool addEquipment(int equipmentNumber,int cardNumber, int cardlv, cards* myCard);
	 
};




