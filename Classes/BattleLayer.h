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
	void test();     //测试用
	void reset();    //将棋子状态重置
	void imageinit();//棋子图片资源初始化
	void onbattle(); //将棋子加入战场
private:
	Chess* self[MaxSquares];
	Chess* enemy[MaxSquares];
};
#endif
