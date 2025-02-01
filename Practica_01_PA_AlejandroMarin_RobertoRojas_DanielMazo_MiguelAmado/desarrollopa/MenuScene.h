#pragma once
#include "Scene.h"
#include "Text.h"
class MenuScene : public Scene
{

private:

	Text* title;
	Text* inputText1;
	Text* inputText2;
	Text* inputText3;

	unsigned int selected;
	bool esRanking;

public:

	MenuScene() :Scene() {}

	void Init();
	//void Reset();

	inline bool getEsRanking() const { return this->esRanking; }
	inline bool setEsRanking(bool r) { esRanking = r; }

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);
    //void ProcessMouseMovement(int x, int y);
    //void ProcessMouseClicked(int button, int state, int x, int y);

};

