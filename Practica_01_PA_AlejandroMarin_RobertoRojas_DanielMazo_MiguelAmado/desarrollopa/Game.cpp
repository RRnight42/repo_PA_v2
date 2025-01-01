#include "Game.h"
#include <iostream>
#include "DebugScene.h"

void Game::Init()
{
	cout << "[GAME] Init..." << endl;

    menu = new	MenuScene();
    lvl1 = new GameScene(GameScene::Level1);
	DebugScene* debug = new DebugScene();
	

	// solo para debug
	//this->activeScene = lvl1;
     this->activeScene = debug;


	scenes.push_back(menu);
	scenes.push_back(lvl1);
	scenes.push_back(debug);

	for (int i = 0; i < scenes.size(); i++)
		scenes[i]->Init();

	/*
	EmitterConfiguration config(20, new Sphere(), 150 );

	Model* skull = new Model();
	ModelLoader loader;

	
	//loader.LoadModel("skull.obj");
	
	//loader.SetScale(0.03);
	//*skull = loader.GetModel();

	//skull->SetPosition(Vector3D(0.0 , 0.0 , -150.0));
	//skull->SetOrientation(Vector3D(180, 0, 180));

	Emitter* emisorParticulas = new Emitter(config);
	
	emisorParticulas->SetPosition(Vector3D(0, 8, 0));
	emisorParticulas->SetGravity(false);

	
	this->activeScene->AddGameObject(emisorParticulas);
	
*/


}

void Game::Render()
{
	this->activeScene->Render();
	
}

void Game::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count() - this->lasUpdatedTime > UPDATE_PERIOD)) {
	this->activeScene->Update(TIME_INCREMENT);
	this->lasUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	
	}

	if (this->activeScene == this->menu) {
	
		if (this->menu->hasEndedScene()) {
		
			this->activeScene = lvl1;		
		}
	
	}

	
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	this->activeScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;
	this->activeScene->ProcessMouseClicked(button, state, x, y);
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
	this->activeScene->ProcessMouseMovement(x, y);
}
