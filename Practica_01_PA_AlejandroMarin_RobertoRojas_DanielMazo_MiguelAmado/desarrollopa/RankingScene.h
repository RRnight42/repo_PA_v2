#pragma once
#include "Scene.h"
#include "Text.h"
#include <string>


using namespace std;

class RankingScene : public Scene
{
private:

	Text* rankingTitle;
	Text* ranking1;
	Text* ranking2;
	Text* ranking3;
	Text* ranking4;
	Text* ranking5;
	Text* ranking6;
	Text* ranking7;
	Text* ranking8;
	Text* ranking9;
	Text* ranking10;


public:
	RankingScene() :Scene() {}

	void Init();
	void Reset();

	string MostrarResultados(string filePath ,  int  indice);

	void ProcessKeyPressed(unsigned char key, int px, int py);

};

