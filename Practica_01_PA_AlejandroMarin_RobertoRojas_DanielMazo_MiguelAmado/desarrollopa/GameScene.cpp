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

	shield = new Sphere(0.18, 15, 10);


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

	
	loaderMaterial = new MaterialModelLoader(0.12);

	loaderMaterial->LoadModel("Player.obj");
	
	player->SetPosition(Vector3D(0 , -0.3 , 18.7));
	player->setModelPlayer(loaderMaterial->GetMaterialModel());

	player->setCarril(2);

	player->setUICanva(canva);

	
	shield->SetOrientationSpeed(Vector3D(0, 5, 0));
	shield->SetPosition(player->GetPosition());
	shield->SetColor(Color(0, 1, 1, 0));
	
	player->SetOrientationSpeed(Vector3D(0, 3, 0));

	canva->InitUI();
	canva->SetPosition(Vector3D(0, 0, 19));
	carretera->SetPosition(Vector3D(0, -4, -60));
	sep1->SetPosition(Vector3D(-1.7, -3.95, -60));
	sep2->SetPosition(Vector3D(-5, -3.95, -60));
	sep3->SetPosition(Vector3D(1.7, -3.95, -60));
	sep4->SetPosition(Vector3D(5, -3.95, -60));
	
	
	carretera->SetColor(Color(0, 0, 0, 1));

	sep1->SetColor(Color(1, 1, 1, 1));
	sep2->SetColor(Color(1, 1, 1, 1));
	sep3->SetColor(Color(1, 1, 1, 1));
	sep4->SetColor(Color(1, 1, 1, 1));
	

	emitterBarrelC1->SetPosition(Vector3D(-3.45, -2, -40));
	emitterBarrelC2->SetPosition(Vector3D(0, -2, -40));
	emitterBarrelC3->SetPosition(Vector3D(3.45, -2, -40));

	emitterPowerUpC1->SetPosition(Vector3D(-3.45, -2, -40));
	emitterPowerUpC2->SetPosition(Vector3D(0, -2, -40));
	emitterPowerUpC3->SetPosition(Vector3D(3.45, -2, -40));
	
	emitterCoinsC1->SetPosition(Vector3D(-3.45, -2, -40));
	emitterCoinsC2->SetPosition(Vector3D(0, -2, -40));
	emitterCoinsC3->SetPosition(Vector3D(3.45, -2, -40));

	emitterWideBarrelC1->SetPosition(Vector3D(-1.7, -2, -40));
	emitterWideBarrelC2->SetPosition(Vector3D(1.7, -2, -40));

	barrelEmitters.push_back(emitterBarrelC1);
	barrelEmitters.push_back(emitterBarrelC2);
	barrelEmitters.push_back(emitterBarrelC3);
	barrelEmitters.push_back(emitterWideBarrelC1);
	barrelEmitters.push_back(emitterWideBarrelC2);

	vector <pair<Item*, float>> barrelsDistribution = { {new NormalBarrel() , 0.5f } , {new SpeedBarrel() , 0.3f } , {new DDBarrel() , 0.2f}};
	vector <pair<Item*, float>> barrelsWideDistribution = { {new WideBarrel() , 1.0f } };

	if (this->getLevel() == this->Level1) {

		EmitterConfiguration confBarrelLvl1(barrelsDistribution, 20, 1, 2, 5000, 12000, 8000, true);
		EmitterConfiguration confWideBarrelLvl1(barrelsWideDistribution, 10, 1, 1, 12000, 20000, 8000, true);
		

		emitterBarrelC1->setConfiguration(confBarrelLvl1);
		emitterBarrelC2->setConfiguration(confBarrelLvl1);
		emitterBarrelC3->setConfiguration(confBarrelLvl1);

		emitterWideBarrelC1->setConfiguration(confWideBarrelLvl1);
		emitterWideBarrelC2->setConfiguration(confWideBarrelLvl1);

	
	}else if (this->getLevel() == this->Level2) {

	}else if (this->getLevel() == this->Level3) {

	}else if (this->getLevel() == this->Level4) {

	}else if (this->getLevel() == this->Level5) {

	}	
	AddGameObject(player);
	//AddGameObject(shield);

	AddGameObject(canva);
	AddGameObject(carretera);
	AddGameObject(sep1);
	AddGameObject(sep2);
	AddGameObject(sep3);
	AddGameObject(sep4);

AddGameObject(emitterBarrelC1);
AddGameObject(emitterBarrelC2);
AddGameObject(emitterBarrelC3);

	// de momento lo comentamos

	//AddGameObject(emitterPowerUp1);
	//AddGameObject(emitterPowerUp2);
	//AddGameObject(emitterPowerUp3);
	//
	AddGameObject(emitterWideBarrelC1);
	AddGameObject(emitterWideBarrelC2);
}

void GameScene::Reset() {

	this->ClearGameObject();
	delete player;
	player = nullptr;
	delete shield;
	shield = nullptr;

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


	this->Init();
}

void GameScene::Render() {

	Scene::Render();

	if (shieldEffect = true) {


		shield->Render();

	}

}

void GameScene::Update(const float& timeUpdate) {

	Scene::Update(timeUpdate);

	this->emitterBarrelC1->checkCollisionsPlayer(*player);
	this->emitterBarrelC2->checkCollisionsPlayer(*player);
	this->emitterBarrelC3->checkCollisionsPlayer(*player);

	this->emitterWideBarrelC1->checkCollisionsPlayer(*player);
	this->emitterWideBarrelC2->checkCollisionsPlayer(*player);

	this->emitterPowerUpC1->checkCollisionsPlayer(*player);
	this->emitterPowerUpC2->checkCollisionsPlayer(*player);
	this->emitterPowerUpC3->checkCollisionsPlayer(*player);

	if (shieldEffect || speedEffect) {
		auto elapsed = chrono::steady_clock::now() - timePowerUp;
		int duration = 10; 

		if (chrono::duration_cast<chrono::seconds>(elapsed).count() >= duration) {

			shieldEffect = false;
			speedEffect = false;

			resetTimeEffects();
			
		}
	}

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
	shield->SetColor(Color(0, 1, 1, 0.35));


}


void GameScene::activateSpeedReduce(const float& speedFactor) {


	for (Emitter* em : barrelEmitters) {
		for (Solid* barrel : em->getParticles()) {
			barrel->SetSpeed(Vector3D(0, 0, barrel->GetSpeed().GetZ() * speedFactor)); // Restauramos la velocidad original
		}

	}


}

void GameScene::resetTimeEffects() {



	if (player->getCurrentPowerUp() == 2) {
		player->ResetPowerUp(); // Quitamos el escudo
		shield->SetColor(Color(0, 1, 1, 0));
		cout << "update: Escudo desactivado." << endl;
	}

	if (player->getCurrentPowerUp() == 3) {
		player->ResetPowerUp(); // Quitamos la velocidad
		cout << "update: velocidad desactivada." << endl;
	}

	// Restaurar velocidad de los barriles si es necesario
	for (Emitter* em : barrelEmitters) {
		for (Solid* barrel : em->getParticles()) {
			barrel->SetSpeed(Vector3D(0, 0, barrel->GetSpeed().GetZ() * 2)); // Restauramos la velocidad original
		}

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
			player->SetPosition(player->GetPosition() - Vector3D(0.45,0,0));
			shield->SetPosition(player->GetPosition());
		}
		break;
	
	case 'D':
	case 'd':
		if (player->getCarril() == 3) {}
		else {
			player->setCarril(player->getCarril() + 1);
			player->SetPosition(player->GetPosition() + Vector3D(0.45, 0, 0));
			shield->SetPosition(player->GetPosition());
		}
		break;
	
	//Para debugear las condiciones de derrota y victoria y el cambio de escena, añadimos dos teclas especificas
	case 'o':
		//this->SetVictoryCondition(false);
		this->endScene(true);
		break;

	case'p':
		//this->SetVictoryCondition(true);
		this->endScene(true);
		break;

     }

}

void GameScene::ProcessSpecialKeyPressed(int key, int px, int py) {

	switch (key) {

	case GLUT_KEY_LEFT:
		if (player->getCarril() == 1) {}
		else {
			player->setCarril(player->getCarril() - 1);
			player->SetPosition(player->GetPosition() - Vector3D(0.45, 0, 0));
			shield->SetPosition(player->GetPosition());
		}
		break;

	case GLUT_KEY_RIGHT:
		if (player->getCarril() == 3) {}
		else {
			player->setCarril(player->getCarril() + 1);
			player->SetPosition(player->GetPosition() + Vector3D(0.45, 0, 0));
			shield->SetPosition(player->GetPosition());
		}
		break;

	default:
		break;
	}
}