#pragma once
#include "Scene.h"
#include "Text.h"
#include <string>


using namespace std;

class RankingScene : public Scene
{
private:

	Text* ranking;

public:
	RankingScene() :Scene() {}

	void Init();
	void Reset();

	string MostrarResultados(string filePath);

	void ProcessKeyPressed(unsigned char key, int px, int py);

};

