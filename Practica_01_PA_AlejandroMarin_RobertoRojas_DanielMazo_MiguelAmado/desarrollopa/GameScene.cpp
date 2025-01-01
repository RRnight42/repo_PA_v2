#include "GameScene.h"
#include "Player.h"
#include<random>

void GameScene::Init() {

	// configuraciones comunes de todos los niveles
	// dibujar escena y demas tralla

	ModelLoader loader;
	MaterialModelLoader* loaderMaterial = new MaterialModelLoader(0.12);

	loaderMaterial->LoadModel("Player.obj");
	
	player->SetPosition(Vector3D(0 , -0.3 , 18.7));
	player->setModelPlayer(loaderMaterial->GetMaterialModel());

	player->setCarril(2);

	player->setUICanva(canva);

	
	shield->SetOrientationSpeed(Vector3D(0, 5, 0));
	shield->SetPosition(player->GetPosition());
	
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
	shield->SetColor(Color(0, 1, 1, 0.35));

	emitterBarrelC1->SetPosition(Vector3D(-3.45, -2, -40));
	emitterBarrelC2->SetPosition(Vector3D(0, -2, -40));
	emitterBarrelC3->SetPosition(Vector3D(3.45, -2, -40));

	emitterPowerUp1->SetPosition(Vector3D(-3.45, -2, -40));
	emitterPowerUp2->SetPosition(Vector3D(0, -2, -40));
	emitterPowerUp3->SetPosition(Vector3D(3.45, -2, -40));


	barrelEmitters.push_back(emitterBarrelC1);
	barrelEmitters.push_back(emitterBarrelC2);
	barrelEmitters.push_back(emitterBarrelC3);

	powerUpEmitters.push_back(emitterPowerUp1); 
	powerUpEmitters.push_back(emitterPowerUp2);
	powerUpEmitters.push_back(emitterPowerUp3);

	if (this->getLevel() == this->Level1) {

		//EmitterConfiguration confBarrelLevel1(1, 4, 1, 2, 3000, 7000, 7000, true, false, Vector3D(0, 0, 0.5), Vector3D(0, 90, 0), Vector3D(0, 0, 1), Color(1, 0, 0, 1), new Ray());		
		//EmitterConfiguration confPowerUpLevel1(new PowerUp(this->loader), 3, 1, 1, 8000, 15000, 7000,true , false, Vector3D(0, 0, 0.5), Vector3D(0, 0, 0) , Vector3D(0,1,0));
		
	//	emitterBarrelC1->setConfiguration(confBarrelLevel1);
	//	emitterBarrelC2->setConfiguration(confBarrelLevel1);
	//	emitterBarrelC3->setConfiguration(confBarrelLevel1);
		
	}else if (this->getLevel() == this->Level2) {

	}else if (this->getLevel() == this->Level3) {

	}else if (this->getLevel() == this->Level4) {

	}else if (this->getLevel() == this->Level5) {

	}
	
	AddGameObject(player);
	AddGameObject(shield);

	AddGameObject(canva);
	AddGameObject(carretera);
	AddGameObject(sep1);
	AddGameObject(sep2);
	AddGameObject(sep3);
	AddGameObject(sep4);

//	AddGameObject(emitterBarrelC1);
//	AddGameObject(emitterBarrelC2);
//	AddGameObject(emitterBarrelC3);

	// de momento lo comentamos

	//AddGameObject(emitterPowerUp1);
	//AddGameObject(emitterPowerUp2);
	//AddGameObject(emitterPowerUp3);
	//
	//AddGameObject(emitterWideBarrel1);
	//AddGameObject(emitterWideBarrel2);
}

void GameScene::Update(const float& timeUpdate) {

	Scene::Update(timeUpdate);

	powerUpCollisions();
	barrelCollisions();
	

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
void GameScene::recogerPowerUp(const int& nuevoPowerUp) {
		
		if (player->getCurrentPowerUp() != 0) {
			cout << "Usa tu powerup antes de coger otro" << endl;
		}else {
		// Actualizar UICanva con el nuevo power-up
		player->setPowerUp(nuevoPowerUp);
		player->notifyUICanva();
	}
}

void GameScene::powerUpCollisions() {
	// Iterar sobre los emisores de power-ups
	for (Emitter* emisor : powerUpEmitters) {
		for (Solid* particle : emisor->getParticles()) {

			PowerUp* powerUp = static_cast<PowerUp*>(particle);

			if (player->GetPosition().Distance(powerUp->GetPosition()) < player->getDistanceColission()) {
				// Colisión detectada: recoger el power-up
				recogerPowerUp(static_cast<Player::PowerUp>(powerUp->GetType()));

				emisor->removeParticle(powerUp);
				break; 
			}
		}
	}
}

void GameScene::barrelCollisions() {


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
		player->setPowerUp(0); // Quitamos el escudo
		shield->SetColor(Color(0, 1, 1, 0));
		cout << "update: Escudo desactivado." << endl;
	}

	if (player->getCurrentPowerUp() == 3) {
		player->setPowerUp(0); // Quitamos la velocidad
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
	}





}