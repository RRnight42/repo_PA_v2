#pragma once
#include "Scene.h"
#include "Text.h"

class LoseScene : public Scene
{
private: 

	Text* textoPerder;
	Text* reinicio;
	Text* menu;
	Text* salir;

	unsigned int selected;
	bool gomenu;
	
public:

	LoseScene() : Scene() {}

	
	void Init();
	void Reset();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);

	inline bool getMenuTransicion() const { return this->gomenu; }
	inline void menuTransicion(const bool& men) { this->gomenu = men; }
};

