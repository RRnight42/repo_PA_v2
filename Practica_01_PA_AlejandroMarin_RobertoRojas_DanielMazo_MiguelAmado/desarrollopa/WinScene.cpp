#include "WinScene.h"

void WinScene::Init() {

	message = new Text("¡FELICIDADES, HAS GANADO", Text::TimesNewRoman24, Color());
	restart = new Text("Volver a jugar", Text::Helvetica18, Color(1, 0.5, 0, 1));
	salir = new Text("Salir", Text::Helvetica12, Color(0, 0, 0, 1));

	message->SetPosition(Vector3D(-5, 6, 0));
	restart->SetPosition(Vector3D(-1.5, 0, 0));
	salir->SetPosition(Vector3D(-1, -3, 0));

	AddGameObject(message);
	AddGameObject(restart);
	AddGameObject(salir);
}

void WinScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	switch (key) {

	case 'w':
		selected = 0;
		restart->setType(Text::Helvetica18);
		salir->setType(Text::Helvetica12);

		restart->SetColor(Color(1, 0.5, 0, 1));
		salir->SetColor(Color(0, 0, 0, 1));
		break;

	case 's':
		selected = 1;
		restart->setType(Text::Helvetica12);
		salir->setType(Text::Helvetica18);

		restart->SetColor(Color(0, 0, 0, 1));
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



void WinScene::ProcessSpecialKeyPressed(int key, int px, int py) {

	switch (key) {

	case GLUT_KEY_UP:
		selected = 0;
		restart->setType(Text::Helvetica18);
		salir->setType(Text::Helvetica12);

		restart->SetColor(Color(1, 0.5, 0, 1));
		salir->SetColor(Color(0, 0, 0, 1));
		break;

	case GLUT_KEY_DOWN:
		selected = 1;
		restart->setType(Text::Helvetica12);
		salir->setType(Text::Helvetica18);

		restart->SetColor(Color(0, 0, 0, 1));
		salir->SetColor(Color(1, 0.5, 0, 1));
		break;

	default:
		break;
	}
}