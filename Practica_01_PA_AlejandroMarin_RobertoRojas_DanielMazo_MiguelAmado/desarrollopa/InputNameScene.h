#pragma once
#include "Scene.h"
#include "Text.h"
#include <string>

class InputNameScene :
    public Scene
{


private:

	int monedas;
	int nivel;

	string inputBuffer;
	int inputLength;

	Text* titulo = new Text("Introduce tu nombre para guardar tu progreso:", Text::TimesNewRoman24, Color(0.5, 0, 0.5, 1));
	Text* inputText = new Text("[_____________]", Text::TimesNewRoman24, Color(0.5, 0, 0.5, 1));

public:
	InputNameScene() :Scene() {}

	void Init();
	void Reset();

	void RecibirDatos(int monedasDevolverNivel, int nivelDevolver) {

		this->monedas = monedasDevolverNivel;
		this->nivel = nivelDevolver;

	}

	string GetRawNamePlayer();

	void GuardarDatos(string nombrePlayer, string namefile);

	void ProcessKeyPressed(unsigned char key, int px, int py);

};

