#pragma once
#include "Solid.h"
#include "Model.h"
#include "Vector3D.h"
#include "Color.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Item.h"

#include <string>
#include <stdexcept>
#include<random>
#include <cstdlib> 
#include <ctime>
#include <numeric>



using namespace std;

class EmitterConfiguration
{
private:
    
    int maxParticles;
    int minBurstSize;
    int maxBurstSize;
    int minInterval;
    int maxInterval;
    long lifetimePerParticle;
    bool loopEmitter;


    vector<pair<Item*, float>> modelsProbability;


    bool useModels;

public:


    // Constructor por defecto
    EmitterConfiguration()
        :
        maxParticles(100),
        minBurstSize(1),
        maxBurstSize(5),
        minInterval(500),
        maxInterval(1500),
        lifetimePerParticle(5000),
        loopEmitter(false),
        useModels(false)
    {}

    /*EmitterConfiguration(
        const vector<pair<Item*, float>>& modelsWithProbabilities,
        int maxParticles = 10,
        int minBurst = 1,
        int maxBurst = 5,
        int minInt = 500,
        int maxInt = 1500,
        long particleLT = 5000,
        bool loop = true
    ) :
        modelsProbability(modelsWithProbabilities),
        maxParticles(maxParticles),
        minBurstSize(minBurst),
        maxBurstSize(maxBurst),
        minInterval(minInt),
        maxInterval(maxInt),
        loopEmitter(loop),
        lifetimePerParticle(particleLT),
        useModels(true)
    {
        // Validar que el vector no esté vacío y su tamaño sea válido
        if (modelsWithProbabilities.empty() || modelsWithProbabilities.size() > 6) {
            throw invalid_argument("El vector de modelos debe contener entre 1 y 6 elementos.");
        }

        // Validar que todas las probabilidades sean positivas
        for (const auto& pair : modelsWithProbabilities) {
            if (pair.second <= 0.0f) {
                throw invalid_argument("Todas las probabilidades deben ser mayores que 0.");
            }
        }

        // Verificar que la suma de las probabilidades sea igual a 1 (o cercana)
        float sumProbabilities = 0.0f;
        for (const auto& pair : modelsWithProbabilities) {
            sumProbabilities += pair.second;
        }

        if (abs(sumProbabilities - 1.0f) > 0.01f) { // Tolerancia de ±0.01
            throw invalid_argument("La suma de las probabilidades debe ser igual a 1.");
        }
    }*/

    EmitterConfiguration(
        vector<pair<Item*, float>>& modelsWithProbabilities,
        int maxParticles = 10,
        int minBurst = 1,
        int maxBurst = 5,
        int minInt = 500,
        int maxInt = 1500,
        long particleLT = 5000,
        bool loop = true
    ) :
        modelsProbability(modelsWithProbabilities),
        maxParticles(maxParticles),
        minBurstSize(minBurst),
        maxBurstSize(maxBurst),
        minInterval(minInt),
        maxInterval(maxInt),
        loopEmitter(loop),
        lifetimePerParticle(particleLT),
        useModels(true)
    {
        // Validar que el vector no esté vacío y su tamaño sea válido
        if (modelsWithProbabilities.empty() || modelsWithProbabilities.size() > 6) {
            throw invalid_argument("El vector de modelos debe contener entre 1 y 6 elementos.");
        }

        // Validar que todas las probabilidades sean positivas
        for (const auto& pair : modelsWithProbabilities) {
            if (pair.second < 0.0f) {
                throw invalid_argument("Las probabilidades deben ser mayores o iguales a 0.");
            }
        }

        // Calcular la suma total de probabilidades
        float sumProbabilities = 0.0f;
        for (const auto& pair : modelsWithProbabilities) {
            sumProbabilities += pair.second;
        }

        // Si la suma de probabilidades es menor a 1, normalizamos
        if (sumProbabilities < 1.0f) {
            for (auto& pair : modelsWithProbabilities) {
                pair.second /= sumProbabilities; // Normalizamos para que sumen 1
            }
        }

        // Si la suma es mayor que 1, recortamos las probabilidades para que sumen 1
        if (sumProbabilities > 1.0f) {
            float excess = sumProbabilities - 1.0f;
            for (auto& pair : modelsWithProbabilities) {
                pair.second -= pair.second * (excess / sumProbabilities); // Ajustamos
            }
        }

        // La suma de las probabilidades debería ser ahora 1
        float newSumProbabilities = 0.0f;
        for (const auto& pair : modelsWithProbabilities) {
            newSumProbabilities += pair.second;
        }

        // Si no suman exactamente 1 (considerando una tolerancia), lanzamos advertencia
        if (abs(newSumProbabilities - 1.0f) > 0.01f) {
            cerr << "Advertencia: Las probabilidades no suman exactamente 1, pero se han ajustado." << endl;
        }
    }


    inline bool IsUsingModels() const { return this->useModels; }

    inline int GetMaxParticles() const { return this->maxParticles; }
    inline int GetMinBurstSize() const { return this->minBurstSize; }
    inline int GetMaxBurstSize() const { return this->maxBurstSize; }
    inline int GetMinInterval() const { return this->minInterval; }
    inline int GetMaxInterval() const { return this->maxInterval; }

   
    inline bool GetIsLooped() const { return this->loopEmitter; }



    inline int getLifetimeParticle() const { return this->lifetimePerParticle; }

    inline vector<pair<Item*,float>> getVectorAndProbabilites() const { return this->modelsProbability; }
    inline int getVectorSize() const { return this->modelsProbability.size(); }


    inline Item* GetParticle(int index) const {
    
        if (index < 1 || index > modelsProbability.size()) {
            throw out_of_range("El índice está fuera del rango permitido.");
        }
        return modelsProbability.at(index - 1).first;

    }
};
