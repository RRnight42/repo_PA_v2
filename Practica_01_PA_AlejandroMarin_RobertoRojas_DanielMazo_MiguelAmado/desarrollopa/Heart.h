#pragma once
#include "PowerUp.h"
#include <cstdlib> 
#include <ctime> 

class Heart : public PowerUp
{


private:

    int typeheart;
    ModelLoader loader;

public:


    Heart() : PowerUp() {


       
        srand((time(0)));
        typeheart = (rand() % 3);

  

        loader.SetScale(0.5);
        loader.LoadModel("Corazon.obj");
        this->SetModel(loader.GetModel());
        this->SetSpeed(Vector3D(0, 0, 1));
        this->SetOrientationSpeed(Vector3D(0, 3, 0));

        switch (typeheart) {

        case 0:
            this->PaintPowerUp((Color(1, 0, 0, 1)));
            break;

        case 1:
            this->PaintPowerUp((Color(1, 1, 0, 1)));
            break;

        case 2:
            this->PaintPowerUp((Color(0.31, 0.11, 0.36, 1)));
            break;

        }
    }

    inline int getHeartType() const { return this->typeheart; }

    CollisionEffect getCollisionEffect() {
    
        switch (this->getHeartType()){
        
        
        case 0:
            return CollisionEffect(1,0,0);
            break;
        
        case 1:
            return CollisionEffect(2, 0, 0);
            break;
        
        case 2:
            return CollisionEffect(-1, 0, 0);
            break;
        
        }
    
    }



    Item* Clone() {

        return new Heart(*this);

    }

    bool isWideBarrel() { return false; }
};
