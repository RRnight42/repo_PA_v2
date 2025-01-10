#include "Game.h"
#include <iostream>
#include "DebugScene.h"

void Game::Init()
{
	cout << "[GAME] Init..." << endl;

    menu = new	MenuScene();
    lvl1 = new GameScene(GameScene::Level1);
	win = new WinScene();
	lose = new LoseScene();

	DebugScene* debug = new DebugScene();
	

	// solo para debug
	this->activeScene = win;
    


	scenes.push_back(menu);
	scenes.push_back(lvl1);
	scenes.push_back(win);
	scenes.push_back(lose);
	scenes.push_back(debug);

	this->menu->Init();
	this->lvl1->Init();
	this->win->Init();
	this->lose->Init();

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

	if (this->activeScene->hasEndedScene()) {
		if (this->activeScene == this->menu) {
			this->lvl1->endScene(false);
			this->lvl1->Reset();
			this->activeScene = lvl1;
		}
		else if (this->activeScene == this->win) {
			
			if (win->getMenuTransicion() == true) {
				this->menu->endScene(false);
				this->activeScene = menu;
			}
			else {
				this->lvl1->endScene(false);
				this->lvl1->Reset();
				this->activeScene = lvl1;
			}
			
			//this->lvl2->endScene(false);
			//this->lvl3->endScene(false);

		}
		else if (this->activeScene == this->lose) {

			if (lose->getMenuTransicion() == true) {
				this->menu->endScene(false);
				this->activeScene = menu;
			}
			else {
				this->lvl1->endScene(false);
				this->lvl1->Reset();
				this->activeScene = lvl1;
			}

			//this->lvl2->endScene(false);
			//this->lvl3->endScene(false);

		}
		else if (this->activeScene == this->lvl1) {
			if (this->lvl1->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
			}
			else if (this->lvl1->getCondVictoria() == false) {
				this->lose->endScene(false);
				this->activeScene = lose;
			}
		}
	}
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	this->activeScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessSpecialKeyPressed(int key, int px, int py) 
{
	this->activeScene->ProcessSpecialKeyPressed(key, px, py);
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
