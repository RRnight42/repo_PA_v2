#include "MenuScene.h"


void MenuScene::Init() {

	title = new Text("TITULO", Text::TimesNewRoman24 ,Color());
	inputText1 = new Text("Comenzar" , Text::Helvetica12 ,Color(1, 0.5, 0, 1));
	inputText2 = new Text("Salir", Text::Helvetica12, Color(0, 0, 0, 1));

	// igual metemos un modelo de fondo para decorar

	
	this->title->SetGravity(false);
	this->inputText1->SetGravity(false);
	this->inputText2->SetGravity(false);

	title->SetPosition(Vector3D(-2, 6, 0));
	inputText1->SetPosition(Vector3D(-1.5, 0, 0));
	inputText2->SetPosition(Vector3D(-1, -3, 0));

	AddGameObject(title);
	AddGameObject(inputText1);
	AddGameObject(inputText2);



}

void MenuScene::ProcessKeyPressed(unsigned char key, int px, int py) {


	switch (key) {
	
	case 'a':
		
		selected = 0;
		this->inputText1->setType(Text::Helvetica18);
		this->inputText2->setType(Text::Helvetica12);
		
		this->inputText1->SetColor(Color(1, 0.5, 0, 1));
		this->inputText2->SetColor(Color(0, 0, 0, 1));
		
		break;
	
	case 'z':
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

