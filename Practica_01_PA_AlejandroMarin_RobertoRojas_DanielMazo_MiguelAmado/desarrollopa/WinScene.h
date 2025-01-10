#pragma once
#include "Scene.h"
#include "Text.h"

class WinScene : public Scene
{
private:

	Text* message;
	Text* restart;
	Text* menu;
	Text* salir;
	

	unsigned int selected;
	bool gomenu;

public:

	WinScene() : Scene() {}

	void Init();

	//void Reset();
	

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);

	inline bool getMenuTransicion() const { return this->gomenu; }
	inline void menuTransicion(const bool& men) { this->gomenu = men; }

};

