#pragma once
#include "Scene.h"
#include "Text.h"
class MenuScene : public Scene
{

private:

	Text* title;
	Text* inputText1;
	Text* inputText2;

	unsigned int selected;

public:

	MenuScene() :Scene() {}

	void Init();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);
    //void ProcessMouseMovement(int x, int y);
    //void ProcessMouseClicked(int button, int state, int x, int y);

};

