#pragma once
#include "Barrel.h"
class SpeedBarrel :
    public Barrel
{

private:

    ModelLoader loader;

public:

        SpeedBarrel() : Barrel() {

        this->loader.SetScale(1);
        this->loader.LoadModel("barrel_k2.obj");
        this->SetModel(loader.GetModel());
        this->setTypeBarrel(BarrelType::SpeedBarrel);
        this->PaintBarrel(Color(0, 0.7, 0, 1));
        this->SetSpeed(Vector3D(0, 0, 0.6));
        this->SetOrientation(Vector3D(0, 0, 90));
        this->SetOrientationSpeed(Vector3D(3, 0, 0));

    }


    Solid* Clone() {

        return new SpeedBarrel(*this);

    }

};

