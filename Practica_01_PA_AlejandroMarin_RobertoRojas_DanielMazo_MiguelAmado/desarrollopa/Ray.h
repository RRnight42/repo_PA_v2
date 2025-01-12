#pragma once
#include "PowerUp.h"
class Ray : public PowerUp
{
private:

    ModelLoader loader;

public:



    Ray() : PowerUp() {

        loader.SetScale(0.5);
        loader.LoadModel("Rayo.obj");
        this->SetModel(loader.GetModel());
        this->PaintPowerUp(Color(1, 1, 0, 1));
        this->SetSpeed(Vector3D(0, 0, 1));
        this->SetOrientationSpeed(Vector3D(0, 3, 0));

    }

    CollisionEffect getCollisionEffect() {

        return CollisionEffect(0, 0, 1);

    }

    Item* Clone() {

        return new Ray(*this);


    }

    bool isWideBarrel() { return false; }
};