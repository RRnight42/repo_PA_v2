#pragma once
#include "Solid.h"
#include "Model.h"
#include "Vector3D.h"
#include "Color.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"
#include "Teapot.h"
#include "Torus.h"

#include <string>
#include <stdexcept>

using namespace std;

class EmitterConfiguration
{
private:
    int DifferentParticleType;
    int maxParticles;
    int minBurstSize;
    int maxBurstSize;
    int minInterval;
    int maxInterval;
    long lifetimePerParticle;

    bool loopEmitter;
    bool randomSpeedColor;
    Vector3D speedParticle;
    Vector3D orientationParticle;
    Vector3D orientationSpeedParticle;
    Color colorParticle;

    Solid* particle1;
    Solid* particle2;
    Solid* particle3;
    Solid* particle4;
    Solid* particle5;
    Solid* particle6;

    bool useModels;

public:


    // Constructor por defecto
    EmitterConfiguration()
        : DifferentParticleType(1),
        maxParticles(100),
        minBurstSize(1),
        maxBurstSize(5),
        minInterval(500),
        maxInterval(1500),
        lifetimePerParticle(5000),
        loopEmitter(false),
        randomSpeedColor(false),
        speedParticle(Vector3D(0, 1, 0)),
        orientationParticle(Vector3D()),
        orientationSpeedParticle(Vector3D(0, 1, 0)),
        colorParticle(Color(1, 1, 1, 1)),
        particle1(new Sphere()),
        particle2(nullptr),
        particle3(nullptr),
        particle4(nullptr),
        particle5(nullptr),
        particle6(nullptr),
        useModels(false)
    {}




    // Constructor para usar modelos (.obj)
    EmitterConfiguration(
        const vector<Solid*>& models ,
        int dpt = 1,
        int maxParticles = 10,
        int minBurst = 1,
        int maxBurst = 5,
        int minInt = 500,
        int maxInt = 1500,
        long particleLT = 5000
    )
        : DifferentParticleType(dpt),
        maxParticles(maxParticles),
        minBurstSize(minBurst),
        maxBurstSize(maxBurst),
        minInterval(minInt),
        maxInterval(maxInt),
        lifetimePerParticle(particleLT),
        particle1(nullptr), particle2(nullptr),
        particle3(nullptr), particle4(nullptr),
        particle5(nullptr), particle6(nullptr),
        useModels(true)
    {
        if (dpt < 1 || dpt > 6) {
            throw invalid_argument("DifferentParticleType debe estar entre 1 y 6.");
        }

        // Asignar modelos
        if (models.size() < dpt) {
            throw invalid_argument("Se requieren suficientes primitivas para el número de tipos de partículas especificado.");
        }

        particle1 = models.size() > 0 ? models[0] : nullptr;
        particle2 = models.size() > 1 ? models[1] : nullptr;
        particle3 = models.size() > 2 ? models[2] : nullptr;
        particle4 = models.size() > 3 ? models[3] : nullptr;
        particle5 = models.size() > 4 ? models[4] : nullptr;
        particle6 = models.size() > 5 ? models[5] : nullptr;

    }

    // Constructor para usar primitivas geométricas
    EmitterConfiguration(
        const vector<Solid*>& primitives,
        int dpt = 1,
        int maxParticles = 10,
        int minBurst = 1,
        int maxBurst = 5,
        int minInt = 500,
        int maxInt = 1500,
        long particleLT = 5000,
        bool loop = false,
        bool random = false,
        Vector3D speed = Vector3D(0, 1, 0),
        Vector3D orientation = Vector3D(),
        Vector3D orientationSpeed = Vector3D(0, 1, 0),
        Color color = Color(1, 1, 1, 1)
    )
        : DifferentParticleType(dpt),
        maxParticles(maxParticles),
        minBurstSize(minBurst),
        maxBurstSize(maxBurst),
        minInterval(minInt),
        maxInterval(maxInt),
        lifetimePerParticle(particleLT),
        loopEmitter(loop),
        randomSpeedColor(random),
        speedParticle(speed),
        orientationParticle(orientation),
        orientationSpeedParticle(orientationSpeed),
        colorParticle(color),
        particle1(nullptr), particle2(nullptr),
        particle3(nullptr), particle4(nullptr),
        particle5(nullptr), particle6(nullptr),
        useModels(false)
    {
        if (dpt < 1 || dpt > 6) {
            throw invalid_argument("DifferentParticleType debe estar entre 1 y 6.");
        }

        // Asignar primitivas
        if (primitives.size() < dpt) {
            throw invalid_argument("Se requieren suficientes primitivas para el número de tipos de partículas especificado.");
        }

        particle1 = primitives.size() > 0 ? primitives[0] : nullptr;
        particle2 = primitives.size() > 1 ? primitives[1] : nullptr;
        particle3 = primitives.size() > 2 ? primitives[2] : nullptr;
        particle4 = primitives.size() > 3 ? primitives[3] : nullptr;
        particle5 = primitives.size() > 4 ? primitives[4] : nullptr;
        particle6 = primitives.size() > 5 ? primitives[5] : nullptr;
    }

    // Métodos de acceso
    inline int getDPT() const { return this->DifferentParticleType; }
    inline bool IsUsingModels() const { return this->useModels; }

    inline int GetMaxParticles() const { return this->maxParticles; }
    inline int GetMinBurstSize() const { return this->minBurstSize; }
    inline int GetMaxBurstSize() const { return this->maxBurstSize; }
    inline int GetMinInterval() const { return this->minInterval; }
    inline int GetMaxInterval() const { return this->maxInterval; }

    inline bool GetIsRandom() const { return this->randomSpeedColor; }
    inline bool GetIsLooped() const { return this->loopEmitter; }

    inline Vector3D getSpeedConf() const { return this->speedParticle; }
    inline Vector3D getOrientationConf() const { return this->orientationParticle; }
    inline Vector3D getOrientationSpeedConf() const { return this->orientationSpeedParticle; }
    inline Color getColorConf() const { return this->colorParticle; }

    inline int getLifetimeParticle() const { return this->lifetimePerParticle; }

    inline Solid* GetParticle(int index) const {
        switch (index) {
        case 1: return particle1;
        case 2: return particle2;
        case 3: return particle3;
        case 4: return particle4;
        case 5: return particle5;
        case 6: return particle6;
        default: throw out_of_range("Índice fuera de rango.");
        }
    }
};
