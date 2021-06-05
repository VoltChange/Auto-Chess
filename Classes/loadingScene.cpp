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
	checkEdition();          /* ���汾 */
#   endif
#endif
	setRunFirstTime();       /* ��ȡ��һ������ʱ�� */
	calculateFileNumbers();  /* �����ļ����� */
	setSystem();             /* ����ϵͳ���� */
	loadUserData();          /* �����û���Ϣ */
	showLoadingBackGround(); /* չʾ���ؽ��� */

	return true;
}