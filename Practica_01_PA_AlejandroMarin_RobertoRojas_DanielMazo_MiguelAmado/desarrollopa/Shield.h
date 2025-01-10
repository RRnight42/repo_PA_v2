#pragma once
#include "PowerUp.h"


class Shield : public PowerUp
{

private:

    ModelLoader loader;

public:


    Shield() : PowerUp() {

      
        loader.SetScale(0.07);
        loader.LoadModel("Escudo.obj");
        this->SetModel(loader.GetModel());
        this->PaintPowerUp(Color(0.5, 0.5, 0.7, 1));
        this->SetSpeed(Vector3D(0, 0, 1));
        this->SetOrientation(Vector3D(0, 0, -90));
        this->SetOrientationSpeed(Vector3D(0, 3, 0));

    }

    CollisionEffect getCollisionEffect() {

        return CollisionEffect(0,0,2);

    }



    Item* Clone() {

        return new Shield(*this);


    }
};
