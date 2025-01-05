#pragma once
#include "Scene.h"
#include "Text.h"
#include "Model.h"
#include "ModelLoader.h"

class LoseScene : public Scene
{
private: 

	Text* textoPerder;
	Text* reinicio;
	Text* salir;
	//Model* donkyLose = new Model();

	//Model* barrels[];

	unsigned int selected;
	
public:

	LoseScene() : Scene() {}

	
	void Init();
	//void Reset();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);
};

