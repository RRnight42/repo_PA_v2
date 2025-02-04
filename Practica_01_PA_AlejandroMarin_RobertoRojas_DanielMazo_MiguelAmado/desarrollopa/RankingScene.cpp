#include "RankingScene.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
void RankingScene::Init() {


	rankingTitle = new Text("RANKING DE PUNTUACIONES :", Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking1 = new Text(MostrarResultados("data.txt", 1), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking2 = new Text(MostrarResultados("data.txt", 2), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking3 = new Text(MostrarResultados("data.txt", 3), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking4 = new Text(MostrarResultados("data.txt", 4), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking5 = new Text(MostrarResultados("data.txt", 5), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking6 = new Text(MostrarResultados("data.txt", 6), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking7 = new Text(MostrarResultados("data.txt", 7), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking8 = new Text(MostrarResultados("data.txt", 8), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking9 = new Text(MostrarResultados("data.txt", 9), Text::TimesNewRoman24, Color(0, 0, 0, 1));
	ranking10 = new Text(MostrarResultados("data.txt", 10), Text::TimesNewRoman24, Color(0, 0, 0, 1));


	rankingTitle->SetPosition(Vector3D<float>(-9, 11, 0));
	ranking1->SetPosition(Vector3D<float>(-9, 9, 0));
	ranking2->SetPosition(Vector3D<float>(-9, 7, 0));
	ranking3->SetPosition(Vector3D<float>(-9, 5, 0));
	ranking4->SetPosition(Vector3D<float>(-9, 3, 0));
	ranking5->SetPosition(Vector3D<float>(-9, 1, 0));
	ranking6->SetPosition(Vector3D<float>(-9, -1, 0));
	ranking7->SetPosition(Vector3D<float>(-9, -3, 0));
	ranking8->SetPosition(Vector3D<float>(-9, -5, 0));
	ranking9->SetPosition(Vector3D<float>(-9, -7, 0));
	ranking10->SetPosition(Vector3D<float>(-9, -9, 0));

	AddGameObject(rankingTitle);
	AddGameObject(ranking1);
	AddGameObject(ranking2);
	AddGameObject(ranking3);
	AddGameObject(ranking4);
	AddGameObject(ranking5);
	AddGameObject(ranking6);
	AddGameObject(ranking7);
	AddGameObject(ranking8);
	AddGameObject(ranking9);
	AddGameObject(ranking10);

}

string RankingScene::MostrarResultados(string filePath, int indice) {
	try {
		ifstream lector(filePath);
		string linea;
		int contador = 0;

		// Recorremos el archivo línea por línea
		while (getline(lector, linea)) {
			contador++;
			if (contador == indice) {

				return linea;
			}
		}
		return "";
	}
	catch (const exception& e) {
		cout << "Error al leer el archivo: " << e.what() << endl;
		return "";
	}
}


void RankingScene::Reset() {
	this->ClearGameObject();

	delete ranking1;
	delete ranking2;
	delete ranking3;
	delete ranking4;
	delete ranking5;
	delete ranking6;
	delete ranking7;
	delete ranking8;
	delete ranking9;
	delete ranking10;

	ranking1 = nullptr;
	ranking2 = nullptr;
	ranking3 = nullptr;
	ranking4 = nullptr;
	ranking5 = nullptr;
	ranking6 = nullptr;
	ranking7 = nullptr;
	ranking8 = nullptr;
	ranking9 = nullptr;
	ranking10 = nullptr;
}

void RankingScene::ProcessKeyPressed(unsigned char key, int px, int py) {

	switch (key) {

	case 8:
		this->endScene(true);
		break;

	case 13:
		this->endScene(true);
		break;
	}
}



