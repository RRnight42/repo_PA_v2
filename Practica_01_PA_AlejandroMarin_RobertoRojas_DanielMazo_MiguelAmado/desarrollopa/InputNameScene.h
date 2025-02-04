#pragma once
#include "Scene.h"
#include "Text.h"
#include <string>

using namespace std;

class InputNameScene :
    public Scene
{


private:

	int monedasTexto;
	int nivelTexto;

	string inputBuffer;
	int inputLength;

	Text* titulo;
	Text* inputText;

public:
	InputNameScene() :Scene() {}

	void Init();
	void Reset();

	void RecibirDatos(int monedasDevolverNivel, int nivelDevolver) {

		this->monedasTexto = monedasDevolverNivel;
		this->nivelTexto = nivelDevolver;

	}

	string GetRawNamePlayer();

	void GuardarDatos(string nombrePlayer, string namefile);

	void ProcessKeyPressed(unsigned char key, int px, int py);

};

