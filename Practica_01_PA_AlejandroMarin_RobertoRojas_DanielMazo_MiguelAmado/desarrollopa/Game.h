#pragma once
#include "Scene.h"
#include "LoseScene.h"
#include "WinScene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include <chrono>

using namespace chrono;

using namespace std;

class Game
{
private:

	milliseconds initialMilliseconds;
	long lasUpdatedTime;

	const float TIME_INCREMENT = 0.4;
	const long UPDATE_PERIOD = 10;


	//Scene mainScene;
	vector<Scene*> scenes;
	Scene* activeScene;

	// scenes

	MenuScene* menu;
	GameScene* lvl1;
	GameScene* lvl2;
	GameScene* lvl3;
	GameScene* lvl4;
	GameScene* lvl5;
	WinScene* win;
	LoseScene* lose;

	int nivelActual = 1;
public:

	Game() {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

