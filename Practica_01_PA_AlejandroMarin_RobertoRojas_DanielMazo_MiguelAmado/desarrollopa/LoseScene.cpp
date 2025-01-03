#include "LoseScene.h"

void LoseScene::Init() {

	textoPerder = new Text("VAYA, HAS PERDIDO", Text::TimesNewRoman24, Color());
	reinicio = new Text("¿Volver a empezar?", Text::Helvetica18, Color(1, 0.5, 0, 1));
	salir = new Text("Salir del juego", Text::Helvetica12, Color(0, 0, 0, 1));

	textoPerder->SetPosition(Vector3D(-3, 6, 0));
	reinicio->SetPosition(Vector3D(-1.5, 0, 0));
	salir->SetPosition(Vector3D(-1, -3, 0));

	AddGameObject(textoPerder);
	AddGameObject(reinicio);
	AddGameObject(salir);
	
	//AddGameObject(donkyLose);

	// a decorar la escena de perdida cerdos :)
}

void LoseScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	switch (key) {

	case 'w':
		selected = 0;
		reinicio->setType(Text::Helvetica18);
		salir->setType(Text::Helvetica12);

		reinicio->SetColor(Color(1, 0.5, 0, 1));
		salir->SetColor(Color(0, 0, 0, 1));
		break;

	case 's':
		selected = 1;
		reinicio->setType(Text::Helvetica12);
		salir->setType(Text::Helvetica18);

		reinicio->SetColor(Color(0, 0, 0, 1));
		salir->SetColor(Color(1, 0.5, 0, 1));
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



void LoseScene::ProcessSpecialKeyPressed(int key, int px, int py) {

	switch (key) {

	case GLUT_KEY_UP:
		selected = 0;
		reinicio->setType(Text::Helvetica18);
		salir->setType(Text::Helvetica12);

		reinicio->SetColor(Color(1, 0.5, 0, 1));
		salir->SetColor(Color(0, 0, 0, 1));
		break;

	case GLUT_KEY_DOWN:
		selected = 1;
		reinicio->setType(Text::Helvetica12);
		salir->setType(Text::Helvetica18);

		reinicio->SetColor(Color(0, 0, 0, 1));
		salir->SetColor(Color(1, 0.5, 0, 1));
		break;

	default:
		break;
	}
}