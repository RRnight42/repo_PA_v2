#include "GameScene.h"
#include "Player.h"
#include "Barrel.h"
#include "PowerUp.h"
#include<random>

void GameScene::Init() {

	// configuraciones comunes de todos los niveles
	// dibujar escena y demas tralla


	shieldEffect = false;
	speedEffect = false;

	player = new Player();

	carretera = new Cuboid(10, 2, 150);
	sep1 = new Cuboid(0.5, 2, 160);
	sep2 = new Cuboid(0.5, 2, 160);
	sep3 = new Cuboid(0.5, 2, 160);
	sep4 = new Cuboid(0.5, 2, 160);

	emitterBarrelC1 = new Emitter();
	emitterBarrelC2 = new Emitter();
	emitterBarrelC3 = new Emitter();

	emitterWideBarrelC1 = new Emitter();
	emitterWideBarrelC2 = new Emitter();

	emitterPowerUpC1 = new Emitter();
	emitterPowerUpC2 = new Emitter();
	emitterPowerUpC3 = new Emitter();

	emitterCoinsC1 = new Emitter();
	emitterCoinsC2 = new Emitter();
	emitterCoinsC3 = new Emitter();

	canva = new UICanva();

	emitterBarrelC1->SetPosition(Vector3D(-3.45, -1, -40));
	emitterBarrelC2->SetPosition(Vector3D(0, -1, -40));
	emitterBarrelC3->SetPosition(Vector3D(3.45, -1, -40));

	emitterPowerUpC1->SetPosition(Vector3D(-3.45, -1, -40));
	emitterPowerUpC2->SetPosition(Vector3D(0, -1, -40));
	emitterPowerUpC3->SetPosition(Vector3D(3.45, -1, -40));

	emitterCoinsC1->SetPosition(Vector3D(-3.45, -1, -40));
	emitterCoinsC2->SetPosition(Vector3D(0, -1, -40));
	emitterCoinsC3->SetPosition(Vector3D(3.45, -1, -40));

	emitterWideBarrelC1->SetPosition(Vector3D(-1.7, -1, -40));
	emitterWideBarrelC2->SetPosition(Vector3D(1.7, -1, -40));


	loaderMaterial = new MaterialModelLoader(0.6);

	loaderMaterial->LoadModel("Player.obj");

	player->SetPosition(Vector3D(0, -1, 10));
	player->setModelPlayer(loaderMaterial->GetMaterialModel());

	player->setCarril(2);
	player->setUICanva(canva);

	canva->InitUI();
	canva->SetPosition(Vector3D(0, 0, 19));
	carretera->SetPosition(Vector3D(0, -3.05, -60));
	sep1->SetPosition(Vector3D(-1.7, -3, -60));
	sep2->SetPosition(Vector3D(-5, -3, -60));
	sep3->SetPosition(Vector3D(1.7, -3, -60));
	sep4->SetPosition(Vector3D(5, -3, -60));


	carretera->SetColor(Color(0, 0, 0, 1));

	sep1->SetColor(Color(1, 1, 1, 1));
	sep2->SetColor(Color(1, 1, 1, 1));
	sep3->SetColor(Color(1, 1, 1, 1));
	sep4->SetColor(Color(1, 1, 1, 1));



	barrelEmitters.push_back(emitterBarrelC1);
	barrelEmitters.push_back(emitterBarrelC2);
	barrelEmitters.push_back(emitterBarrelC3);
	barrelEmitters.push_back(emitterWideBarrelC1);
	barrelEmitters.push_back(emitterWideBarrelC2);


	if (this->getLevel() == this->Level1) {

		vector <pair<Item*, float>> barrelsDistribution = { {new NormalBarrel() , 0.3f } , {new SpeedBarrel() , 0.2f } , {new DDBarrel() , 0.1f} };
		vector <pair<Item*, float>> barrelsWideDistribution = { {new WideBarrel() , 0.2f } };
		vector <pair<Item*, float>> powersDistribution = { {new Heart() , 0.25f } ,{new Ray() , 0.25f } , {new Shield() , 0.25f } , {new SpeedReduce() , 0.25f} };
		vector <pair<Item*, float>> CoinsDistribution = { {new Coin() , 1.0f } };

		EmitterConfiguration confBarrelLvl1(barrelsDistribution, 20, 1, 2, 1000, 12000, 30000, true);
		EmitterConfiguration confWideBarrelLvl1(barrelsWideDistribution, 10, 1, 1, 12000, 30000, 30000, true);
		EmitterConfiguration confPULvl1(powersDistribution, 20, 1, 1, 15000, 20000, 30000, true);
		EmitterConfiguration confCoinLvl(CoinsDistribution, 50, 1, 5, 8000, 20000, 30000, true);

		emitterBarrelC1->setConfiguration(confBarrelLvl1);
		emitterBarrelC2->setConfiguration(confBarrelLvl1);
		emitterBarrelC3->setConfiguration(confBarrelLvl1);

		emitterWideBarrelC1->setConfiguration(confWideBarrelLvl1);
		emitterWideBarrelC2->setConfiguration(confWideBarrelLvl1);

		emitterPowerUpC1->setConfiguration(confPULvl1);
		emitterPowerUpC2->setConfiguration(confPULvl1);
		emitterPowerUpC3->setConfiguration(confPULvl1);

		emitterCoinsC1->setConfiguration(confCoinLvl);
		emitterCoinsC2->setConfiguration(confCoinLvl);
		emitterCoinsC3->setConfiguration(confCoinLvl);


	}
	else if (this->getLevel() == this->Level2) {
		vector <pair<Item*, float>> barrelsDistribution = { {new NormalBarrel() , 0.4f } , {new SpeedBarrel() , 0.4f } , {new DDBarrel() , 0.2f} };
		vector <pair<Item*, float>> barrelsWideDistribution = { {new WideBarrel() , 0.3f } };
		vector <pair<Item*, float>> powersDistribution = { {new Heart() , 0.25f } ,{new Ray() , 0.25f } , {new Shield() , 0.25f } , {new SpeedReduce() , 0.25f} };
		vector <pair<Item*, float>> CoinsDistribution = { {new Coin() , 1.0f } };

		EmitterConfiguration confBarrelLvl2(barrelsDistribution, 20, 1, 2, 5000, 12000, 30000, true);
		EmitterConfiguration confWideBarrelLvl2(barrelsWideDistribution, 10, 1, 1, 12000, 20000, 30000, true);
		EmitterConfiguration confPULvl2(powersDistribution, 20, 1, 1, 15000, 20000, 30000, true);
		EmitterConfiguration confCoinLvl(CoinsDistribution, 50, 1, 5, 8000, 20000, 30000, true);

		emitterBarrelC1->setConfiguration(confBarrelLvl2);
		emitterBarrelC2->setConfiguration(confBarrelLvl2);
		emitterBarrelC3->setConfiguration(confBarrelLvl2);

		emitterWideBarrelC1->setConfiguration(confWideBarrelLvl2);
		emitterWideBarrelC2->setConfiguration(confWideBarrelLvl2);

		emitterPowerUpC1->setConfiguration(confPULvl2);
		emitterPowerUpC2->setConfiguration(confPULvl2);
		emitterPowerUpC3->setConfiguration(confPULvl2);

		emitterCoinsC1->setConfiguration(confCoinLvl);
		emitterCoinsC2->setConfiguration(confCoinLvl);
		emitterCoinsC3->setConfiguration(confCoinLvl);

	}
	else if (this->getLevel() == this->Level3) {
		vector <pair<Item*, float>> barrelsDistribution = { {new NormalBarrel() , 0.3f } , {new SpeedBarrel() , 0.3f } , {new DDBarrel() , 0.3f} };
		vector <pair<Item*, float>> barrelsWideDistribution = { {new WideBarrel() , 0.3f } };
		vector <pair<Item*, float>> powersDistribution = { {new Heart() , 0.25f } ,{new Ray() , 0.25f } , {new Shield() , 0.25f } , {new SpeedReduce() , 0.25f} };
		vector <pair<Item*, float>> CoinsDistribution = { {new Coin() , 1.0f } };

		EmitterConfiguration confBarrelLvl3(barrelsDistribution, 20, 1, 2, 3000, 7000, 30000, true);
		EmitterConfiguration confWideBarrelLvl3(barrelsWideDistribution, 10, 1, 1, 12000, 20000, 30000, true);
		EmitterConfiguration confPULvl3(powersDistribution, 20, 1, 1, 15000, 20000, 30000, true);
		EmitterConfiguration confCoinLvl(CoinsDistribution, 50, 1, 5, 8000, 20000, 30000, true);

		emitterBarrelC1->setConfiguration(confBarrelLvl3);
		emitterBarrelC2->setConfiguration(confBarrelLvl3);
		emitterBarrelC3->setConfiguration(confBarrelLvl3);

		emitterWideBarrelC1->setConfiguration(confWideBarrelLvl3);
		emitterWideBarrelC2->setConfiguration(confWideBarrelLvl3);

		emitterPowerUpC1->setConfiguration(confPULvl3);
		emitterPowerUpC2->setConfiguration(confPULvl3);
		emitterPowerUpC3->setConfiguration(confPULvl3);

		emitterCoinsC1->setConfiguration(confCoinLvl);
		emitterCoinsC2->setConfiguration(confCoinLvl);
		emitterCoinsC3->setConfiguration(confCoinLvl);

	}
	else if (this->getLevel() == this->Level4) {
		vector <pair<Item*, float>> barrelsDistribution = { {new NormalBarrel() , 0.1f } , {new SpeedBarrel() , 0.4f } , {new DDBarrel() , 0.4f} };
		vector <pair<Item*, float>> barrelsWideDistribution = { {new WideBarrel() , 0.15f } };
		vector <pair<Item*, float>> powersDistribution = { {new Heart() , 0.25f } ,{new Ray() , 0.25f } , {new Shield() , 0.25f } , {new SpeedReduce() , 0.25f} };
		vector <pair<Item*, float>> CoinsDistribution = { {new Coin() , 1.0f } };

		EmitterConfiguration confBarrelLvl4(barrelsDistribution, 20, 1, 2, 5000, 12000, 30000, true);
		EmitterConfiguration confWideBarrelLvl4(barrelsWideDistribution, 10, 1, 1, 12000, 20000, 30000, true);
		EmitterConfiguration confPULvl4(powersDistribution, 20, 1, 1, 15000, 20000, 30000, true);
		EmitterConfiguration confCoinLvl(CoinsDistribution, 50, 1, 5, 8000, 20000, 30000, true);

		emitterBarrelC1->setConfiguration(confBarrelLvl4);
		emitterBarrelC2->setConfiguration(confBarrelLvl4);
		emitterBarrelC3->setConfiguration(confBarrelLvl4);

		emitterWideBarrelC1->setConfiguration(confWideBarrelLvl4);
		emitterWideBarrelC2->setConfiguration(confWideBarrelLvl4);

		emitterPowerUpC1->setConfiguration(confPULvl4);
		emitterPowerUpC2->setConfiguration(confPULvl4);
		emitterPowerUpC3->setConfiguration(confPULvl4);

		emitterCoinsC1->setConfiguration(confCoinLvl);
		emitterCoinsC2->setConfiguration(confCoinLvl);
		emitterCoinsC3->setConfiguration(confCoinLvl);

	}
	else if (this->getLevel() == this->Level5) {
		vector <pair<Item*, float>> barrelsDistribution = { {new NormalBarrel() , 0.01f } , {new SpeedBarrel() , 0.01f } , {new DDBarrel() , 0.98f} };
		vector <pair<Item*, float>> barrelsWideDistribution = { {new WideBarrel() , 0.01f } };
		vector <pair<Item*, float>> powersDistribution = { {new Heart() , 0.25f } ,{new Ray() , 0.25f } , {new Shield() , 0.25f } , {new SpeedReduce() , 0.25f} };
		vector <pair<Item*, float>> CoinsDistribution = { {new Coin() , 1.0f } };

		EmitterConfiguration confBarrelLvl5(barrelsDistribution, 20, 1, 2, 5000, 12000, 30000, true);
		EmitterConfiguration confWideBarrelLvl5(barrelsWideDistribution, 10, 1, 1, 12000, 20000, 30000, true);
		EmitterConfiguration confPULvl5(powersDistribution, 20, 1, 1, 15000, 20000, 30000, true);
		EmitterConfiguration confCoinLvl(CoinsDistribution, 50, 1, 5, 8000, 20000, 30000, true);

		emitterBarrelC1->setConfiguration(confBarrelLvl5);
		emitterBarrelC2->setConfiguration(confBarrelLvl5);
		emitterBarrelC3->setConfiguration(confBarrelLvl5);

		emitterWideBarrelC1->setConfiguration(confWideBarrelLvl5);
		emitterWideBarrelC2->setConfiguration(confWideBarrelLvl5);

		emitterPowerUpC1->setConfiguration(confPULvl5);
		emitterPowerUpC2->setConfiguration(confPULvl5);
		emitterPowerUpC3->setConfiguration(confPULvl5);

		emitterCoinsC1->setConfiguration(confCoinLvl);
		emitterCoinsC2->setConfiguration(confCoinLvl);
		emitterCoinsC3->setConfiguration(confCoinLvl);

	}
	AddGameObject(player);
	AddGameObject(canva);
	AddGameObject(carretera);
	AddGameObject(sep1);
	AddGameObject(sep2);
	AddGameObject(sep3);
	AddGameObject(sep4);
	AddGameObject(emitterBarrelC1);
	AddGameObject(emitterBarrelC2);
	AddGameObject(emitterBarrelC3);
	AddGameObject(emitterWideBarrelC1);
	AddGameObject(emitterWideBarrelC2);
	AddGameObject(emitterCoinsC1);
	AddGameObject(emitterCoinsC2);
	AddGameObject(emitterCoinsC3);
	AddGameObject(emitterPowerUpC1);
	AddGameObject(emitterPowerUpC2);
	AddGameObject(emitterPowerUpC3);
}

void GameScene::Reset() {

	this->ClearGameObject();
	delete player;
	player = nullptr;
	delete carretera;
	carretera = nullptr;
	delete sep1;
	sep1 = nullptr;
	delete sep2;
	sep2 = nullptr;
	delete sep3;
	sep3 = nullptr;
	delete sep4;
	sep4 = nullptr;

	delete emitterBarrelC1;
	emitterBarrelC1 = nullptr;
	delete emitterBarrelC2;
	emitterBarrelC2 = nullptr;
	delete emitterBarrelC3;
	emitterBarrelC3 = nullptr;

	delete emitterWideBarrelC1;
	emitterWideBarrelC1 = nullptr;
	delete emitterWideBarrelC2;
	emitterWideBarrelC2 = nullptr;

	delete emitterPowerUpC1;
	emitterPowerUpC1 = nullptr;
	delete emitterPowerUpC2;
	emitterPowerUpC2 = nullptr;
	delete emitterPowerUpC3;
	emitterPowerUpC3 = nullptr;

	delete emitterCoinsC1;
	emitterCoinsC1 = nullptr;
	delete emitterCoinsC2;
	emitterCoinsC2 = nullptr;
	delete emitterCoinsC3;
	emitterCoinsC3 = nullptr;

	barrelEmitters.clear();

	delete loaderMaterial;
	loaderMaterial = nullptr;


	delete canva;
	canva = nullptr;

	shieldEffect = false;
	speedEffect = false;
}

void GameScene::Update(const float& timeUpdate) {

	Scene::Update(timeUpdate);

	time.Run();


	this->emitterBarrelC1->checkCollisionsPlayer(player);
	this->emitterBarrelC2->checkCollisionsPlayer(player);
	this->emitterBarrelC3->checkCollisionsPlayer(player);

	this->emitterWideBarrelC1->checkCollisionsPlayer(player);
	this->emitterWideBarrelC2->checkCollisionsPlayer(player);

	this->emitterPowerUpC1->checkCollisionsPlayer(player);
	this->emitterPowerUpC2->checkCollisionsPlayer(player);
	this->emitterPowerUpC3->checkCollisionsPlayer(player);

	this->emitterCoinsC1->checkCollisionsPlayer(player);
	this->emitterCoinsC2->checkCollisionsPlayer(player);
	this->emitterCoinsC3->checkCollisionsPlayer(player);

	if (shieldEffect || speedEffect) {

		int duration = 10;
		timePowerUps += time.GetDeltaTime();

		if (timePowerUps >= duration) {


			player->ResetPowerUp();


			if (speedEffect) {
				for (Emitter* em : barrelEmitters) {
					for (Item* barrel : em->getParticles()) {
						barrel->SetSpeed(Vector3D(0, 0, barrel->GetSpeed().GetZ() * 2)); // Restauramos la velocidad original
					}

				}

				timePowerUps = 0;
				speedEffect = false;
			}

			if (shieldEffect) {
				this->player->setShield(false);
				timePowerUps = 0;
				shieldEffect = false;
			}




		}
	}
	cambioEscena();
	//cout << player->getLives() << ", " << player->getCoins() << "," << player->getCurrentPowerUp() << endl;
	

}


void GameScene::usePowerUpPlayer() {
	if (player->hasPowerUp()) {

		int powerUp = this->player->usePowerUp();

		switch (powerUp) {
		case Player::Ray:
			activateRay();
			break;

		case Player::SpeedReduce:
			activateSpeedReduce(0.5f); // Reducir velocidad un 50%
			timePowerUp = chrono::steady_clock::now();
			speedEffect = true;
			break;


		case Player::Shield:
			activateShield();
			break;

		default:
			break;
		}

		// Notificar a la interfaz
		player->notifyUICanva();
	}
}




void GameScene::activateRay() {

	for (Emitter* em : barrelEmitters) {

		em->clearParticles();

	}

}

void GameScene::activateShield() {


	shieldEffect = true;
	player->setShield(true);


}


void GameScene::activateSpeedReduce(const float& speedFactor) {


	for (Emitter* em : barrelEmitters) {
		for (Solid* barrel : em->getParticles()) {
			barrel->SetSpeed(Vector3D(0, 0, barrel->GetSpeed().GetZ() * speedFactor)); // reducir un 50%
		}

	}


}

void GameScene::cambioEscena() {

	if (player->getCoins() >= coinsToWin) {
		this->condVictoria = true;
		this->endScene(true);
	}
	else if (this->player->getLives() <= 0) {
		this->endScene(true);
	}
}

void GameScene::ProcessKeyPressed(unsigned char key, int px, int py) {



	switch (key) {

	case 'L':
	case 'l':
		usePowerUpPlayer();
		break;

	case 'A':
	case 'a':
		if (player->getCarril() == 1) {}
		else {
			player->setCarril(player->getCarril() - 1);
			player->SetPosition(player->GetPosition() - Vector3D(3.45, 0, 0));
		}
		break;

	case 'D':
	case 'd':
		if (player->getCarril() == 3) {}
		else {
			player->setCarril(player->getCarril() + 1);
			player->SetPosition(player->GetPosition() + Vector3D(3.45, 0, 0));

		}
		break;

		//Para debugear las condiciones de derrota y victoria y el cambio de escena, añadimos dos teclas especificas
	case 'o':

		this->endScene(true);
		this->setCondVictoria(false);
		break;

	case'p':

		this->endScene(true);
		this->setCondVictoria(true);
		break;

	}

}

void GameScene::ProcessSpecialKeyPressed(int key, int px, int py) {

	switch (key) {

	case GLUT_KEY_LEFT:
		if (player->getCarril() == 1) {}
		else {
			player->setCarril(player->getCarril() - 1);
			player->SetPosition(player->GetPosition() - Vector3D(3.45, 0, 0));
		}
		break;

	case GLUT_KEY_RIGHT:
		if (player->getCarril() == 3) {}
		else {
			player->setCarril(player->getCarril() + 1);
			player->SetPosition(player->GetPosition() + Vector3D(3.45, 0, 0));
		}
		break;

	default:
		break;
	}
}