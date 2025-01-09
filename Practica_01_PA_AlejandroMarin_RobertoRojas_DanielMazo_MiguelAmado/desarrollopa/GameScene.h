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

using namespace std;

class GameScene : public Scene
{

public:
	
	enum Level {Level1 , Level2 , Level3 , Level4, Level5};


private:

	Player* player = new Player();

	Sphere* shield = new Sphere(0.18, 15, 10);
	

	Cuboid* carretera = new Cuboid(10, 2, 150);
	Cuboid* sep1 = new Cuboid(0.5, 2, 160);
	Cuboid* sep2 = new Cuboid(0.5, 2, 160);
	Cuboid* sep3 = new Cuboid(0.5, 2, 160);
	Cuboid* sep4 = new Cuboid(0.5, 2, 160);

	Emitter* emitterBarrelC1 = new Emitter();
	Emitter* emitterBarrelC2 = new Emitter();
	Emitter* emitterBarrelC3 = new Emitter();

	Emitter* emitterWideBarrelC1 = new Emitter();
	Emitter* emitterWideBarrelC2 = new Emitter();

	Emitter* emitterPowerUpC1 = new Emitter();
	Emitter* emitterPowerUpC2 = new Emitter();
	Emitter* emitterPowerUpC3 = new Emitter();

	Emitter* emitterCoinsC1 = new Emitter();
	Emitter* emitterCoinsC2 = new Emitter();
	Emitter* emitterCoinsC3 = new Emitter();

	UICanva* canva = new UICanva();

	// powerups 

	vector<Emitter*> barrelEmitters;
	
	bool shieldEffect = false;
	bool speedEffect = false;
	const float reduce = 0.5;
	chrono::steady_clock::time_point timePowerUp;

	

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

