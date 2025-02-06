#include "Game.h"
#include <iostream>

void Game::Init()
{
	cout << "[GAME] Init..." << endl;

	menu = new	MenuScene();

	lvl1 = new GameScene(GameScene::Level1, 15);
	lvl2 = new GameScene(GameScene::Level2, 15);
	lvl3 = new GameScene(GameScene::Level3, 30);
	lvl4 = new GameScene(GameScene::Level4, 30);
	lvl5 = new GameScene(GameScene::Level5, 45);
	lvl6 = new GameScene(GameScene::Level6, 45);
	lvl7 = new GameScene(GameScene::Level7, 75);
	lvl8 = new GameScene(GameScene::Level8, 75);
	lvl9 = new GameScene(GameScene::Level9, 100);
	lvl10 = new GameScene(GameScene::FinalLevel, 100);

	win = new WinScene();
	lose = new LoseScene();
	ranking = new RankingScene();
	inputScene = new InputNameScene();

	nivelActual = 1;


	// solo para debug
	this->activeScene = menu;



	scenes.push_back(menu);
	scenes.push_back(lvl1);
	scenes.push_back(lvl2);
	scenes.push_back(lvl3);
	scenes.push_back(lvl4);
	scenes.push_back(lvl5);
	scenes.push_back(lvl6);
	scenes.push_back(lvl7);
	scenes.push_back(lvl8);
	scenes.push_back(lvl9);
	scenes.push_back(lvl10);
	scenes.push_back(win);
	scenes.push_back(lose);
	scenes.push_back(ranking);
	scenes.push_back(inputScene);

	this->menu->Init();
	this->lvl1->Init();
	this->win->Init();
	this->lose->Init();
	this->ranking->Init();
	this->inputScene->Init();

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
			if (this->menu->getEsRanking()) {

				this->ranking->endScene(false);
				this->ranking->Reset();
				this->ranking->Init();
				this->activeScene = ranking;

			}
			else {

			this->lvl1->endScene(false);
			this->lvl1->Reset();
			this->lvl1->Init();
			nivelActual = 1;
			this->activeScene = lvl1;
			}
		
		}
		else if (this->activeScene == this->ranking) {
			this->menu->endScene(false);
			this->activeScene = menu;
		}
		else if (this->activeScene == this->win) {

			if (win->getMenuTransicion() == true) {
				nivelActual = 1;
				this->menu->endScene(false);
				this->activeScene = menu;
			}
			else if (win->getNextLevel()) {
				if (nivelActual < 10) {
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

				case 6:
					this->lvl6->endScene(false);
					this->lvl6->Reset();
					this->lvl6->Init();
					this->activeScene = lvl6;
					break;

				case 7:
					this->lvl7->endScene(false);
					this->lvl7->Reset();
					this->lvl7->Init();
					this->activeScene = lvl7;
					break;

				case 8:
					this->lvl8->endScene(false);
					this->lvl8->Reset();
					this->lvl8->Init();
					this->activeScene = lvl8;
					break;

				case 9:
					this->lvl9->endScene(false);
					this->lvl9->Reset();
					this->lvl9->Init();
					this->activeScene = lvl9;
					break;

				case 10:
					this->lvl10->endScene(false);
					this->lvl10->Reset();
					this->lvl10->Init();
					this->activeScene = lvl10;
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

				case 6:
					this->lvl6->endScene(false);
					this->lvl6->Reset();
					this->lvl6->Init();
					this->activeScene = lvl6;
					break;

				case 7:
					this->lvl7->endScene(false);
					this->lvl7->Reset();
					this->lvl7->Init();
					this->activeScene = lvl7;
					break;

				case 8:
					this->lvl8->endScene(false);
					this->lvl8->Reset();
					this->lvl8->Init();
					this->activeScene = lvl8;
					break;

				case 9:
					this->lvl9->endScene(false);
					this->lvl9->Reset();
					this->lvl9->Init();
					this->activeScene = lvl9;
					break;

				case 10:
					this->lvl10->endScene(false);
					this->lvl10->Reset();
					this->lvl10->Init();
					this->activeScene = lvl10;
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
				this->lvl1->Reset();
			}

			//TRANSICIONES HACIA INPUT NAME
			else if (this->lvl1->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl1->getInformationCoins(), this->lvl1->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl1->Reset();
			}
		}
		else if (this->activeScene == this->lvl2) {
			if (this->lvl2->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl2->Reset();
			}
			else if (this->lvl2->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl2->getInformationCoins(), this->lvl2->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl2->Reset();
			}
		}
		else if (this->activeScene == this->lvl3) {
			if (this->lvl3->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl3->Reset();
			}
			else if (this->lvl3->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl3->getInformationCoins(), this->lvl3->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl3->Reset();
			}
		}
		else if (this->activeScene == this->lvl4) {
			if (this->lvl4->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl4->Reset();
			}
			else if (this->lvl4->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl4->getInformationCoins(), this->lvl4->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl4->Reset();
			}
		}
		else if (this->activeScene == this->lvl5) {
			if (this->lvl5->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl5->Reset();
			}
			else if (this->lvl5->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl5->getInformationCoins(), this->lvl5->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl5->Reset();
			}
		}
		else if (this->activeScene == this->lvl6) {
			if (this->lvl6->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl6->Reset();
			}
			else if (this->lvl6->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl6->getInformationCoins(), this->lvl6->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl6->Reset();
			}
		}
		else if (this->activeScene == this->lvl7) {
			if (this->lvl7->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl7->Reset();
			}
			else if (this->lvl7->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl7->getInformationCoins(), this->lvl7->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl7->Reset();
			}
		}
		else if (this->activeScene == this->lvl8) {
			if (this->lvl8->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl8->Reset();
			}
			else if (this->lvl8->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl8->getInformationCoins(), this->lvl8->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl8->Reset();
			}
		}
		else if (this->activeScene == this->lvl9) {
			if (this->lvl9->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl9->Reset();
			}
			else if (this->lvl9->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl9->getInformationCoins(), this->lvl9->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl9->Reset();
			}
		}
		else if (this->activeScene == this->lvl10) {
			if (this->lvl10->getCondVictoria() == true) {
				this->win->endScene(false);
				this->activeScene = win;
				this->lvl10->Reset();
			}
			else if (this->lvl10->getCondVictoria() == false) {
				this->inputScene->Init();
				inputScene->RecibirDatos(this->lvl10->getInformationCoins(), this->lvl10->getInformationLevel());
				this->inputScene->endScene(false);
				this->activeScene = inputScene;
				this->lvl10->Reset();
			}
		}
		else if(this->activeScene == this->inputScene){
				this->lose->endScene(false);
				this->lose->Reset();
				this->lose->Init();
				this->inputScene->Reset();
				this->activeScene = lose;
		}
		else if (this->activeScene == this->ranking) {
				this->ranking->endScene(false);
				this->menu->endScene(false);
				this->menu->Reset();
				this->menu->Init();
				this->activeScene == menu;
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
