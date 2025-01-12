#pragma once
#include "Barrel.h"
#include "Sphere.h"

class WideBarrel :
    public Barrel
{
private:

    ModelLoader loader;
    Sphere* sphere = new Sphere(5);

public:

    WideBarrel() : Barrel() {

        this->loader.SetScale(1.5);
        this->loader.LoadModel("barrelwide_k2.obj");
        this->SetModel(loader.GetModel());
        this->PaintBarrel(Color(0.42, 0.23, 0.16, 1));
        this->SetSpeed(Vector3D(0, 0, 0.7));
        this->SetOrientation(Vector3D(0, 0, 90));
        this->SetOrientationSpeed(Vector3D(3, 0, 0));
        this->sphere->SetPosition(this->GetPosition());
        this->sphere->Render();

    }

     CollisionEffect getCollisionEffect() {

        return CollisionEffect(-1, 0, 0);

    }

    Item* Clone() {

        return new WideBarrel(*this);

    }
    bool isWideBarrel() { return true; }

};

