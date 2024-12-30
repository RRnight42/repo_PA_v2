#pragma once
#include "Scene.h"
#include "Text.h"
#include "Model.h"
#include "ModelLoader.h"




class LoseScene : public Scene
{
	

private : 

	Text* textoPerder = new Text("Vaya, has perdido" , Text::Helvetica18);
	Text* reinicio = new Text("¿Volver a empezar?", Text::Helvetica10);

	Model* donkyLose = new Model();

	Model* barrels[];
	

public:


	LoseScene() {
	
	
	
	
	}


	void Init();
};

