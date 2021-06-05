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
	void update(float Time) override;                 /* ��ʱ�� */
	void setSystem();                                 /* ����ϵͳ���� */
	void calculateFileNumbers();                      /* �����ļ����� */
	void setRunFirstTime();                           /* ��ȡ��һ������ʱ�� */

	void loadUserData();                              /* �����û����� */
	void loadingText();                               /* �������� */
	void loadingImage();                              /* ����ͼƬ */
	void loadingMusic();                              /* �������� */
	void loadingAnimation();                          /* ���ض��� */

	void showLoadingBackGround();                     /* չʾ���� */
	void showTileAndLoadingBar();                     /* չʾ������ */
	void showLoadingBarFlower(const int& ID);         /* չʾ�������ϵĻ� */
	void beginLoadingImageAndMusic();                 /* ��ʼ����ͼƬ������ */

	void runLoGoCallBack(Node* node, const int& ID);   /* չʾlogo�ص� */
	void loadingTextCallBack();                       /* �������ֻص� */
	void loadingAnimationCallBack();                  /* ���ض����ص� */
	void beginGameCallBack(Ref* pSender);             /* ��ʼ��Ϸ�ص� */

	//int openResourcesPath(map<string, string>& Path, const std::string& xml, bool IsEncryption = false);  /* ����Դ·�� */

	void throwException();
	void checkEdition();
	void changeFiles();

private:
	int _textNumbers;                                 // �ı���
	int _loadFileNumbers;                             // �ļ�������
	int _allFileNumbers;                              // �ļ�����(ͼƬ�����֣��������ı�)
	bool _flowerVisible[5] = { false };               // ���ػ����Ƿ�ɼ� 
	float _loadingPrecent;                            // ���ؽ��� 
	Sprite* _sprite[8];                               // ����ͼƬ 
	MenuItemLabel* _label;                            // ���ֱ�ǩ 
	//LoadingBar* _loadingBar;                          // ������ 
	EventListenerTouchOneByOne* _listener;            // ���ؼ��� 
	//Global* _global;                                  // ȫ�ֱ�������
	Director* _director;                              // ���ݵ��� 
	FileUtils* _files;                                // �ļ����� 
	//UserData* _userData;
	//std::unique_ptr<network::Downloader> _downloader;
};