#pragma once
#include "Solid.h"
#include "MaterialModel.h"
#include "Text.h"
#include "UICanva.h"

#include <vector>

class Player : public Solid
{

public : 

    enum PowerUp { None, Ray, Shield, SpeedReduce };


private:

    MaterialModel model;

    int lives;
    int coinsValue; 

    int carril; 


    const float distanceColission = 0.1;
    const float distanceColissionWideBarrel = 1;
    

public:

    UICanva* uiCanva = nullptr;
  

    PowerUp powerUp;
    
    Player() : Solid(), lives(3), coinsValue(0), powerUp(None) {}

    inline float getDistanceColission() const { return this->distanceColission; }
    inline float getDistanceColissionWide() const { return this->distanceColissionWideBarrel; }

     int getCurrentPowerUp();
     void setPowerUp(const int& pu);

    inline int getCarril() const { return this->carril; }
    inline void setCarril(const int& carrilSet) { this->carril = carrilSet; }

    bool hasPowerUp() const;
    inline int getCoins() const { return coinsValue; }

    inline void setModelPlayer(const MaterialModel& mS) { this->model = mS; }

    int usePowerUp();
    void AddLive(const int& amount);
    void LoseLive(const int& amount);
    void addCoin();
    void setUICanva(UICanva* ui);
    void notifyUICanva();

    void Render();

    Solid* Clone(){
    
        return new Player(*this);
    }
  
};
