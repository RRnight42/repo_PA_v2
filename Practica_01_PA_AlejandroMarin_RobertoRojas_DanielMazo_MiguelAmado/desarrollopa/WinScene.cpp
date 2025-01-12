#include "WinScene.h"

void WinScene::Init() {

	message = new Text("¡FELICIDADES, HAS GANADO", Text::TimesNewRoman24, Color());
	restart = new Text("Volver a jugar", Text::Helvetica18, Color(1, 0.5, 0, 1));
	nextLvl = new Text("Siguiente nivel", Text::Helvetica12, Color(0, 0, 0, 1));
	menu = new Text("Menu", Text::Helvetica12, Color(0, 0, 0, 1));
	salir = new Text("Salir", Text::Helvetica12, Color(0, 0, 0, 1));


	message->SetPosition(Vector3D(-5, 8, 0));
	restart->SetPosition(Vector3D(-1.5, 3, 0));
	menu->SetPosition(Vector3D(-1, 0, 0));
	nextLvl->SetPosition(Vector3D(-1.5, -3, 0));
	salir->SetPosition(Vector3D(-1, -6, 0));

	AddGameObject(message);
	AddGameObject(restart);
	AddGameObject(nextLvl);
	AddGameObject(menu);
	AddGameObject(salir);
}

void WinScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	switch (key) {
		/*
	case 13:
		if (selected == 0) {
			this->endScene(true);
		}
		else if (selected == 1) {
			exit(0);
		}
		else if (selected == 2) {
			doSomething();
			salir->AddOption!!reremider

		}
*/

	case 'w':

		if (selected == 1) {
			selected = 0;

			restart->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 2) {
			selected = 1;

			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 3) {
			selected = 2;

			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 0) {
			selected = 3;

			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));
		}
		break;

	case 's':
		if (selected == 0) {
			selected = 1;
			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 1) {
			selected = 2;
			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 2) {
			selected = 3;
			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));
		}
		else if (selected == 3) {
			selected = 0;
			restart->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		break;

	case 13:

		if (selected == 0) {
			this->menuTransicion(false);
			this->NextLevel(false);
			this->endScene(true);

		}
		else if (selected == 1) {
			this->menuTransicion(true);
			this->NextLevel(false);
			this->endScene(true);
		}
		else if (selected == 2) {
			this->menuTransicion(false);
			this->NextLevel(true);
			this->endScene(true);
		}
		else {
			exit(0);
		}
		break;

	default:
		break;
	}
}



void WinScene::ProcessSpecialKeyPressed(int key, int px, int py) {

	switch (key) {

	case GLUT_KEY_UP:
		if (selected == 1) {
			selected = 0;

			restart->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 2) {
			selected = 1;

			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 3) {
			selected = 2;

			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 0) {
			selected = 3;

			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));
		}
		break;

	case GLUT_KEY_DOWN:
		if (selected == 0) {
			selected = 1;
			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 1) {
			selected = 2;
			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 2) {
			selected = 3;
			restart->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			restart->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));
		}
		else if (selected == 3) {
			selected = 0;
			restart->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			nextLvl->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			restart->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			nextLvl->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		break;

	default:
		break;
	}
}