#pragma once
#ifndef __Battle_Layer_H__
#define __Battle_Layer_H__
#include"cocos2d.h"
#include"Chess.h"
#include "Play.h"
#define MaxSquares 6
USING_NS_CC;

class BattleLayer :public Layer
{
public:
	CREATE_FUNC(BattleLayer);
	virtual bool init();
	static BattleLayer* createLayer();
	void test();     //������
	void test2();
	void reset();    //������״̬����
	void imageinit();//����ͼƬ��Դ��ʼ��
	void onbattle(); //�����Ӽ���ս��
	void start();    //��ʼ
	void searchtarget();//��Ŀ��
	int isend();     //���ر��غ�ʤ����0����δ������1�����ҷ�Ӯ��2����з�Ӯ
	void end();     //�������غϣ��Ƴ�layer������Ѫ
	void destroy();  //���ٸ���update
	void startup();//���°�ť��ʼ
	virtual	void update(float dt);
	void step(float dt);//�ı�ʱ��
	void setchessdata();//������������
private:
	Chess* self[MaxSquares];
	Chess* enemy[MaxSquares];
	int isbattle;
	double time; //��ʱ��
	Play* player_me;
	Play* player_en;
};
#endif
