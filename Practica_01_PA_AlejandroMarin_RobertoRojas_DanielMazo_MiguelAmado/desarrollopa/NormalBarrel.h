#pragma once
#include "Barrel.h"
class NormalBarrel : public Barrel
{

private:

    ModelLoader loader;

public:

    NormalBarrel() : Barrel() {

        this->loader.SetScale(1);
        this->loader.LoadModel("barrel_k2.obj");
        this->SetModel(loader.GetModel());
        this->setTypeBarrel(BarrelType::Normal);
        this->PaintBarrel(Color(1, 0.5, 0, 1));
        this->SetSpeed(Vector3D(0, 0, 0.35));
        this->SetOrientation(Vector3D(0, 0, 90));
        this->SetOrientationSpeed(Vector3D(3, 0, 0));

    }


    Solid* Clone() {

        return new NormalBarrel(*this);

    }


};

