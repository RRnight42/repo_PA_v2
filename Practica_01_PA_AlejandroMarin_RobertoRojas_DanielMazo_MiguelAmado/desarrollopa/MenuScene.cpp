#include "MenuScene.h"

void MenuScene::Init() {

	title = new Text("Barrel Escape X", Text::TimesNewRoman24 ,Color());
	inputText1 = new Text("Comenzar" , Text::Helvetica18 ,Color(1, 0.5, 0, 1));
	inputText2 = new Text("Salir", Text::Helvetica12, Color(0, 0, 0, 1));

	// igual metemos un modelo de fondo para decorar

	title->SetPosition(Vector3D(-2, 6, 0));
	inputText1->SetPosition(Vector3D(-1.5, 0, 0));
	inputText2->SetPosition(Vector3D(-1, -3, 0));

	AddGameObject(title);
	AddGameObject(inputText1);
	AddGameObject(inputText2);

}

void MenuScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	switch (key) {
	
	case 'w':
		selected = 0;
		this->inputText1->setType(Text::Helvetica18);
		this->inputText2->setType(Text::Helvetica12);
		
		this->inputText1->SetColor(Color(1, 0.5, 0, 1));
		this->inputText2->SetColor(Color(0, 0, 0, 1));
		break;
	
	case 's':
		selected = 1;
		this->inputText1->setType(Text::Helvetica12);
		this->inputText2->setType(Text::Helvetica18);
		this->inputText2->SetColor(Color(1, 0.5, 0, 1));
		this->inputText1->SetColor(Color(0, 0, 0, 1));
		break;

	case 13:

		if (selected == 0) {
			this->endScene(true);
		}
		else {
			exit(0);
		}
		break;
	}
}

void MenuScene::ProcessSpecialKeyPressed(int key, int px, int py) {

	switch (key) {

	case GLUT_KEY_UP:
		selected = 0;
		inputText1->setType(Text::Helvetica18);
		inputText2->setType(Text::Helvetica12);

		inputText1->SetColor(Color(1, 0.5, 0, 1));
		inputText2->SetColor(Color(0, 0, 0, 1));
		break;

	case GLUT_KEY_DOWN: 
		selected = 1;
		inputText1->setType(Text::Helvetica12);
		inputText2->setType(Text::Helvetica18);

		inputText1->SetColor(Color(0, 0, 0, 1));
		inputText2->SetColor(Color(1, 0.5, 0, 1));
		break;

	default:
		break;
	}
}

