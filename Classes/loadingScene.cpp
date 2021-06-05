#include"loadingScene.h"

loadingScene::~loadingScene()
{
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("");
}

Scene* loadingScene::createLoadingScene()
{
	return loadingScene::create();
}

bool loadingScene::init()
{
	if (!Scene::init())
		return false;

#if MYRELEASE
#   if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	checkEdition();          /* 检查版本 */
#   endif
#endif
	setRunFirstTime();       /* 获取第一次运行时间 */
	calculateFileNumbers();  /* 计算文件总数 */
	setSystem();             /* 设置系统参数 */
	loadUserData();          /* 加载用户信息 */
	showLoadingBackGround(); /* 展示加载界面 */

	return true;
}