#pragma once
#include "Scene.h"
#include "Text.h"
class RankingScene : public Scene
{
private:
	Text* titulo;
	string texto;
	Text* rank;
	Text* inputText;

public:
	RankingScene() :Scene() {}

	void Init();
	void Reset();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	//void ProcessMouseMovement(int x, int y);
	//void ProcessMouseClicked(int button, int state, int x, int y);
};

