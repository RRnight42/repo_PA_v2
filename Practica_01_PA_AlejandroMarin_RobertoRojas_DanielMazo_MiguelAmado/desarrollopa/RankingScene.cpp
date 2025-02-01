#include "RankingScene.h"

void RankingScene::Init() {

	titulo = new Text("Barrel Escape X", Text::TimesNewRoman24, Color());
	rank = new Text("Comenzar", Text::Helvetica18, Color(1, 0.5, 0, 1));   //De momento
	inputText = new Text("Pulse enter paea volver a menú", Text::Helvetica12, Color(0, 0, 0, 0.7));

	// igual metemos un modelo de fondo para decorar

	titulo->SetPosition(Vector3D(-2, 6, 0));
	rank->SetPosition(Vector3D(-1.5, 0, 0));
	inputText->SetPosition(Vector3D(-1, -3, 0));

	AddGameObject(titulo);
	AddGameObject(rank);
	AddGameObject(inputText);

}

void RankingScene::Reset() {
	this->ClearGameObject();

	delete titulo;
	delete rank;
	delete inputText;
}

void RankingScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	switch (key) {
	case 13:
		this->endScene(true);
		break;
	}
}

