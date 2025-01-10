#pragma once
#include <vector>
#include <chrono>
#include "Solid.h"
#include "Color.h"
#include <iostream>
#include <random>
#include "EmitterConfiguration.h"
#include "ModelLoader.h"
#include "Item.h"
#include "Player.h"

using namespace std;
using namespace chrono;

class Emitter : public Solid
{
private:
    EmitterConfiguration conf;
    vector<Item*> particlesVector;
    vector<long> particleCreationTimes; 

    milliseconds initialMilliseconds;
    long lastUpdateTime;
    long nextInterval;

    int currentBurstSize;

    int generateRandom(int min, int max);

public:
    Emitter(EmitterConfiguration confToSet = EmitterConfiguration()) 
        : conf(confToSet), currentBurstSize(0), nextInterval(0)
    {
        this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        this->lastUpdateTime = 0;
        this->nextInterval = generateRandom(conf.GetMinInterval(), conf.GetMaxInterval());
    }

    inline vector<Item*> getParticles() { return this->particlesVector; }

    Color randomColor(int particleId);
    //Vector3D randomSpeed(int particleId);

    void Render();
    void Update(const float& timeUpdate);

    inline void setConfiguration(const EmitterConfiguration& configuration) { this->conf = configuration; }

    void removeParticle(Item* particle);
    void clearParticles();
    
    Vector3D randomPositionOffsetZ(int particleId);

    Item* generateSolidByProbability(const vector<pair<Item*, float>>& solidsWithProbabilities);

    void checkCollisionsPlayer(Player player) {

        for (Item* particle : particlesVector) {

            if (particle->Distance(player.GetPosition()) < player.getDistanceColission()) {

                player.applyCollisionEffect(particle->getCollisionEffect());

                this->removeParticle(particle);
            }

            
         }
    }

    Solid* Clone();
};
