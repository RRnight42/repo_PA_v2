#include "LoseScene.h"

void LoseScene::Init() {

	textoPerder = new Text("VAYA, HAS PERDIDO", Text::TimesNewRoman24, Color());
	reinicio = new Text("�Volver a empezar?", Text::Helvetica18, Color(1, 0.5, 0, 1));
	menu = new Text("Menu", Text::Helvetica12, Color(0, 0, 0, 1));
	salir = new Text("Salir del juego", Text::Helvetica12, Color(0, 0, 0, 1));

	textoPerder->SetPosition(Vector3D<float>(-3, 6, 0));
	reinicio->SetPosition(Vector3D<float>(-1.5, 0, 0));
	menu->SetPosition(Vector3D<float>(-1, -3, 0));
	salir->SetPosition(Vector3D<float>(-1, -6, 0));

	AddGameObject(textoPerder);
	AddGameObject(reinicio);
	AddGameObject(menu);
	AddGameObject(salir);

}

void LoseScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	switch (key) {

	case 'w':
		if (selected == 1) {
			selected = 0;
			reinicio->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 2) {
			selected = 1;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 0) {
			selected = 2;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));
		}
		break;

	case 's':
		if (selected == 0) {
			selected = 1;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 1) {
			selected = 2;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));

		}
		else if (selected == 2) {
			selected = 0;
			reinicio->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		break;

	case 13:

		if (selected == 0) {
			this->menuTransicion(false);
			this->endScene(true);

		}
		else if (selected == 1) {
			this->menuTransicion(true);
			this->endScene(true);
		}
		else {
			exit(0);
		}
		break;
	}
}

void LoseScene::Reset() {
	this->ClearGameObject();
	delete textoPerder;
	delete reinicio;
	delete menu;
	delete salir;

	textoPerder = nullptr;
	reinicio = nullptr;
	menu = nullptr;
	salir = nullptr;

	selected = 0;
}

void LoseScene::ProcessSpecialKeyPressed(int key, int px, int py) {

	switch (key) {

	case GLUT_KEY_UP:
		if (selected == 1) {
			selected = 0;
			reinicio->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 2) {
			selected = 1;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));

		}
		else if (selected == 0) {
			selected = 2;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));
		}
		break;

	case GLUT_KEY_DOWN:
		if (selected == 0) {
			selected = 1;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica18);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(1, 0.5, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		else if (selected == 1) {
			selected = 2;
			reinicio->setType(Text::Helvetica12);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica18);

			reinicio->SetColor(Color(0, 0, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(1, 0.5, 0, 1));

		}
		else if (selected == 2) {
			selected = 0;
			reinicio->setType(Text::Helvetica18);
			menu->setType(Text::Helvetica12);
			salir->setType(Text::Helvetica12);

			reinicio->SetColor(Color(1, 0.5, 0, 1));
			menu->SetColor(Color(0, 0, 0, 1));
			salir->SetColor(Color(0, 0, 0, 1));
		}
		break;

	default:
		break;
	}
}