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
	void test();     //测试用
	void test2();
	void reset();    //将棋子状态重置
	void imageinit();//棋子图片资源初始化
	void onbattle(); //将棋子加入战场
	void start();    //开始
	void searchtarget();//换目标
	int isend();     //返回本回合胜负，0代表未结束，1代表我方赢，2代表敌方赢
	void end();     //结束本回合，移除layer，并扣血
	void destroy();  //销毁各种update
	void startup();//按下按钮开始
	virtual	void update(float dt);
	void step(float dt);//改变时间
	void setchessdata();//设置棋子数据
private:
	Chess* self[MaxSquares];
	Chess* enemy[MaxSquares];
	int isbattle;
	double time; //计时器
	Play* player_me;
	Play* player_en;
};
#endif
