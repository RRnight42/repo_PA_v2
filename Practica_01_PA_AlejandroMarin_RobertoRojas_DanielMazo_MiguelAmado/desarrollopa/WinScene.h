#pragma once
#include "Scene.h"
#include "Text.h"

class WinScene : public Scene
{
private:

	Text* message;
	Text* restart;
	Text* salir;

	unsigned int selected;

public:

	WinScene() : Scene() {}

	void Init();

	//void Reset();
	

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);

};

