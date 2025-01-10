#pragma once
#include <chrono>
#include "Scene.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Text.h"
#include "Emitter.h"
#include "EmitterConfiguration.h"
#include "MaterialModelLoader.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Player.h"
#include  "PowerUp.h"
#include "UICanva.h"
#include "Ray.h"
#include "Shield.h"
#include "Heart.h"
#include "SpeedReduce.h"
#include"Barrel.h"
#include "DDBarrel.h"
#include "WideBarrel.h"
#include "SpeedBarrel.h"
#include "NormalBarrel.h"

using namespace std;

class GameScene : public Scene
{

public:
	
	enum Level {Level1 , Level2 , Level3 , Level4, Level5};


private:

	Player* player;

	Sphere* shield;
	
	Cuboid* carretera;
	Cuboid* sep1;
	Cuboid* sep2;
	Cuboid* sep3;
	Cuboid* sep4;

	Emitter* emitterBarrelC1;
	Emitter* emitterBarrelC2;
	Emitter* emitterBarrelC3;

	Emitter* emitterWideBarrelC1;
	Emitter* emitterWideBarrelC2;

	Emitter* emitterPowerUpC1;
	Emitter* emitterPowerUpC2;
	Emitter* emitterPowerUpC3;

	Emitter* emitterCoinsC1;
	Emitter* emitterCoinsC2;
	Emitter* emitterCoinsC3;

	UICanva* canva;

	// powerups 

	vector<Emitter*> barrelEmitters;
	
	bool shieldEffect = false;
	bool speedEffect = false;
	const float reduce = 0.5;
	chrono::steady_clock::time_point timePowerUp;

	ModelLoader loader;
	MaterialModelLoader* loaderMaterial;

	Level level;


public : 
	
	inline Level getLevel() const { return this->level;}


	GameScene(Level levelToSet) : level(levelToSet){}

	void usePowerUpPlayer();
	void Init();
	void Reset();
	
	//powerups

	void activateRay();
	void activateShield();
	void activateSpeedReduce(const float& speedFactor);
	
	void resetTimeEffects();

	//inputs

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);

	void Render();
	void Update(const float& timeUpdate);
	
};

