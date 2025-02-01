#pragma once
#include <chrono>
#include "Scene.h"
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
#include"Barrel.h"
#include "Coin.h"
#include "Item.h"
#include "Time.h"

using namespace std;

class GameScene : public Scene
{

public:
	
	enum Level {Level1 , Level2 , Level3 , Level4, Level5 , Level6 , Level7 , Level8 , Level9 , FinalLevel};


private:

	Player* player;

	
	
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


	// tiempo 

	float timePowerUps;
	Time time;

	bool condVictoria;

	int coinsToWin;

public : 
	
	inline Level getLevel() const { return this->level;}


	GameScene(Level levelToSet ,  int coinsObjective) : level(levelToSet) , coinsToWin(coinsObjective){}

	void usePowerUpPlayer();
	void Init();
	void Reset();
	
	//powerups

	void activateRay();
	void activateShield();
	void activateSpeedReduce(const float& speedFactor);

	inline bool getCondVictoria() const { return this->condVictoria; }
	inline void setCondVictoria(const bool& co) { this->condVictoria = co; }
	
	//inputs


	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyPressed(int key, int px, int py);

	void cambioEscena();

	
	void Update(const float& timeUpdate);
	
};

