#pragma once
#include "PowerUp.h"
#include <cstdlib> 
#include <ctime> 

class Heart : public PowerUp
{

public:

    enum TypeHeart { NormalHeart, SuperHeart, PoisonHeart };

private:

    TypeHeart typeheart;
    ModelLoader loader;

public:


    Heart() : PowerUp() {


       
        srand(static_cast<unsigned>(time(0)));
        this->typeheart = static_cast<TypeHeart>(rand() % 3);

        loader.SetScale(0.5);
        loader.LoadModel("Corazon.obj");
        this->setTypePowerUp(PowerUp::Heart);
        this->SetModel(loader.GetModel());
        this->SetSpeed(Vector3D(0, 0, 0.6));
        this->SetOrientationSpeed(Vector3D(0, 3, 0));

        switch (this->typeheart) {


        case NormalHeart:
            this->PaintPowerUp((Color(1, 0, 0, 1)));
            break;

        case SuperHeart:
            this->PaintPowerUp((Color(1, 1, 0, 1)));
            break;

        case PoisonHeart:
            this->PaintPowerUp((Color(0.31, 0.11, 0.36, 1)));
            break;


        }

        

    }

    inline TypeHeart getHeartType() const { return this->typeheart; }

    CollisionEffect getCollisionEffect() {
    
        switch (this->getHeartType()){
        
        
        case NormalHeart:
            return CollisionEffect(1,0,0);
            break;
        
        case SuperHeart:
            return CollisionEffect(2, 0, 0);
            break;
        
        case PoisonHeart:
            return CollisionEffect(-1, 0, 0);
            break;
        
        }
    
    }



    Item* Clone() {
    
        return new Heart(*this);
    
    
    }
};
