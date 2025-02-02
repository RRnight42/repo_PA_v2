#pragma once
#include "Solid.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "MaterialModel.h"
#include "Text.h"
#include "UICanva.h"
#include "Time.h"
#include "CollisionEffect.h"

#include <vector>

class Player : public Solid
{

public:

    enum PowerUp { None, Ray, Shield, SpeedReduce };


private:

    MaterialModel model;
    Sphere* shield = new Sphere(1.7, 15, 10);
    Cuboid* frozenCube = new Cuboid(3,3,3);

    int lives;
    int coinsValue;

    bool activeShield = false;
    bool frozen = false;

    int carril;


    const float distanceColission = 1;
    const float distanceColissionWideBarrel = 5;

    UICanva* uiCanva = nullptr;


    int powerUp;


public:



    Player() : Solid(), lives(3), coinsValue(0), powerUp(None) {}

    inline float getDistanceColission() const { return this->distanceColission; }
    inline float getDistanceColissionWide() const { return this->distanceColissionWideBarrel; }

    inline void setPowerUp(const Player::PowerUp& pow) { this->powerUp = pow; }

    inline int getLives() const { return this->lives; }
    

    int getCurrentPowerUp();

    inline int getCarril() const { return this->carril; }

    inline bool getFrozen() const { return this->frozen; }

    inline void setCarril(const int& carrilSet) { this->carril = carrilSet; }

    bool hasPowerUp() const;
    inline int getCoins() const { return coinsValue; }

    inline bool hasShieldActivated() const { return this->activeShield; }

    inline void setModelPlayer(const MaterialModel& mS) { this->model = mS; }

    inline void setShield(const bool& s) { this->activeShield = s;}

    inline void setFrozen(const bool& f) { this->frozen = f; }
     
    int usePowerUp();
    void setUICanva(UICanva* ui);
    void notifyUICanva();


    void ResetPowerUp() { this->powerUp = None; }

    void applyCollisionEffect(CollisionEffect col);
   

    void Update(const float& timeUpdate);
    void Render();

    Solid* Clone(){
    
        return new Player(*this);
    }
  
};
