#pragma once
#ifndef __Battle_Layer_H__
#define __Battle_Layer_H__
#include"cocos2d.h"
#include"Chess.h"
#define MaxSquares 6
USING_NS_CC;

class BattleLayer :public Layer
{
public:
	CREATE_FUNC(BattleLayer);
	virtual bool init();
	static BattleLayer* createLayer();
	void test();     //������
	void reset();    //������״̬����
	void imageinit();//����ͼƬ��Դ��ʼ��
	void onbattle(); //�����Ӽ���ս��
private:
	Chess* self[MaxSquares];
	Chess* enemy[MaxSquares];
};
#endif
