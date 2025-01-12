#include "Game.h"
#include <iostream>

void Game::Init()
{
	cout << "[GAME] Init..." << endl;
	
    menu = new	MenuScene();

    lvl1 = new GameScene(GameScene::Level1 , 15);
	lvl2 = new GameScene(GameScene::Level2, 30);
	lvl3 = new GameScene(GameScene::Level3, 45);
	lvl4 = new GameScene(GameScene::Level4, 75);
	lvl5 = new GameScene(GameScene::Level5, 100);

	win = new WinScene();
	lose = new LoseScene();

	nivelActual = 1;
	

	// solo para debug
	this->activeScene = menu;
    


	scenes.push_back(menu);
	scenes.push_back(lvl1);
	scenes.push_back(lvl2);
	scenes.push_back(lvl3);
	scenes.push_back(lvl4);
	scenes.push_back(lvl5);
	scenes.push_back(win);
	scenes.push_back(lose);

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
			this->lvl1->Init();
			nivelActual = 1;
			this->activeScene = lvl1;
		}
		else if (this->activeScene == this->win) {
			
			if (win->getMenuTransicion() == true) {
				nivelActual = 1;
				this->menu->endScene(false);
				this->activeScene = menu;
			}
			else if (win->getNextLevel()){
				if (nivelActual < 5) {
					nivelActual++;
				}
				switch (nivelActual) {
				case 2:
					this->lvl2->endScene(false);
					this->lvl2->Reset();
					this->lvl2->Init();
					this->activeScene = lvl2;
					break;

				case 3:
					this->lvl3->endScene(false);
					this->lvl3->Reset();
					this->lvl3->Init();
					this->activeScene = lvl3;
					break;

				case 4:
					this->lvl4->endScene(false);
					this->lvl4->Reset();
					this->lvl4->Init();
					this->activeScene = lvl4;
					break;

				case 5:
					this->lvl5->endScene(false);
					this->lvl5->Reset();
					this->lvl5->Init();
					this->activeScene = lvl5;
					break;
				}
			}
			else {
				switch (nivelActual) {
				case 1:
					this->lvl1->endScene(false);
					this->lvl1->Reset();
					this->lvl1->Init();
					this->activeScene = lvl1;
					break;

				case 2:
					this->lvl2->endScene(false);
					this->lvl2->Reset();
					this->lvl2->Init();
					this->activeScene = lvl2;
					break;

				case 3:
					this->lvl3->endScene(false);
					this->lvl3->Reset();
					this->lvl3->Init();
					this->activeScene = lvl3;
					break;

				case 4:
					this->lvl4->endScene(false);
					this->lvl4->Reset();
					this->lvl4->Init();
					this->activeScene = lvl4;
					break;

				case 5:
					this->lvl5->endScene(false);
					this->lvl5->Reset();
					this->lvl5->Init();
					this->activeScene = lvl5;
					break;
				}
			}
		}
		else if (this->activeScene == this->lose) {

			if (lose->getMenuTransicion() == true) {
				this->menu->endScene(false);
				nivelActual = 1;
				this->activeScene = menu;
			}
			else {
				this->lvl1->endScene(false);
				nivelActual = 1;
				this->lvl1->Reset();
				this->lvl1->Init();
				this->activeScene = lvl1;
			}

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
		else if (this->activeScene == this->lvl2) {
			if (this->lvl2->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
			}
			else if (this->lvl2->getCondVictoria() == false) {
				this->lose->endScene(false);
				this->activeScene = lose;
			}
		}
		else if (this->activeScene == this->lvl3) {
			if (this->lvl3->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
			}
			else if (this->lvl3->getCondVictoria() == false) {
				this->lose->endScene(false);
				this->activeScene = lose;
			}
		}
		else if (this->activeScene == this->lvl4) {
			if (this->lvl4->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
			}
			else if (this->lvl4->getCondVictoria() == false) {
				this->lose->endScene(false);
				this->activeScene = lose;
			}
		}
		else if (this->activeScene == this->lvl5) {
			if (this->lvl5->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
			}
			else if (this->lvl5->getCondVictoria() == false) {
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
