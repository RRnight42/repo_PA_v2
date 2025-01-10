#pragma once
#include "Model.h"
#include "Solid.h"
#include "ModelLoader.h"
#include "Text.h"
#include "Ray.h"
#include "Shield.h"
#include "Heart.h"
#include "SpeedReduce.h"

class UICanva : public Solid
{
   

private:

    ModelLoader loader;
    

    Text* coinsText;

    Model* heart1 = new Model();
    Model* heart2 = new Model();
    Model* heart3 = new Model();

    Model* rayPowerUpUI = new Model();
    Model* shieldPowerUpUI = new Model();
    Model* speedPowerUpUI = new Model();

    Model* activePowerUp = nullptr;

    Model* activeHeart1 = heart1;
    Model* activeHeart2 = heart2;
    Model* activeHeart3 = heart3;

    Model* coinUI = new Model();

    int coins;
    int lives;
    int powerUi;

public:
   

    UICanva() : coinsText(new Text( int(0) , Text::TimesNewRoman24)) , activePowerUp(nullptr) , powerUi(0){}


    void InitUI();
    void UpdateCoinsText(const int& coinsValue) { this->coinsText->setText(coinsValue); }    
    void UpdateHeartsUI(const int& currentLive);
    void SetActivePowerUpUI(const int& power);
    

    void Update(const float& timeUpdate);
    void Render();
    Solid* Clone();

};

