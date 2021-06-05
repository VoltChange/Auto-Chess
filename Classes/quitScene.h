#pragma once

#include"cocos2d.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class quitMenu :public Scene
{
public:
	CREATE_FUNC(quitMenu);
	static int getSumRunTime();

CC_CONSTRUCTOR_ACCESS:
	quitMenu() : _quitDialog(nullptr) {}
	virtual bool init();

private:
	void createDiglog();	/* �����Ի��� */
	void createButtons(const std::string& Label, Vec2& vec2, const int& ID);/* ������ť */
	void caveTime(const int time);
	//virtual void deleteDialog() override;

private:
	Sprite* _quitDialog;    /* �Ի��� */
};