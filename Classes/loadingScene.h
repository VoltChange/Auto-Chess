#pragma once

#include"cocos2d.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class loadingScene :public Scene {
public:
	CREATE_FUNC(loadingScene);
	static Scene* createLoadingScene();
	static void loadUserFileData();
	static void caveUserFileData();
CC_CONSTRUCTOR_ACCESS:
	loadingScene();
	~loadingScene();
	virtual bool init() override;

private:
	void update(float Time) override;                 /* 定时器 */
	void setSystem();                                 /* 设置系统参数 */
	void calculateFileNumbers();                      /* 计算文件总数 */
	void setRunFirstTime();                           /* 获取第一次运行时间 */

	void loadUserData();                              /* 加载用户数据 */
	void loadingText();                               /* 加载文字 */
	void loadingImage();                              /* 加载图片 */
	void loadingMusic();                              /* 加载音乐 */
	void loadingAnimation();                          /* 加载动画 */

	void showLoadingBackGround();                     /* 展示背景 */
	void showTileAndLoadingBar();                     /* 展示进度条 */
	void showLoadingBarFlower(const int& ID);         /* 展示进度条上的花 */
	void beginLoadingImageAndMusic();                 /* 开始加载图片与音乐 */

	void runLoGoCallBack(Node* node, const int& ID);   /* 展示logo回调 */
	void loadingTextCallBack();                       /* 加载文字回调 */
	void loadingAnimationCallBack();                  /* 加载动画回调 */
	void beginGameCallBack(Ref* pSender);             /* 开始游戏回调 */

	//int openResourcesPath(map<string, string>& Path, const std::string& xml, bool IsEncryption = false);  /* 打开资源路径 */

	void throwException();
	void checkEdition();
	void changeFiles();

private:
	int _textNumbers;                                 // 文本数
	int _loadFileNumbers;                             // 文件加载数
	int _allFileNumbers;                              // 文件总数(图片，音乐，动画，文本)
	bool _flowerVisible[5] = { false };               // 加载花朵是否可见 
	float _loadingPrecent;                            // 加载进度 
	Sprite* _sprite[8];                               // 精灵图片 
	MenuItemLabel* _label;                            // 文字标签 
	//LoadingBar* _loadingBar;                          // 进度条 
	EventListenerTouchOneByOne* _listener;            // 加载监听 
	//Global* _global;                                  // 全局变量单例
	Director* _director;                              // 导演单例 
	FileUtils* _files;                                // 文件单例 
	//UserData* _userData;
	//std::unique_ptr<network::Downloader> _downloader;
};