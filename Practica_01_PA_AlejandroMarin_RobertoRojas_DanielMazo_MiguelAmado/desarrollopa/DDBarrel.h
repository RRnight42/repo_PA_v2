#pragma once
#include "Barrel.h"
#include "CollisionEffect.h"

class DDBarrel :
    public Barrel
{
private:

    ModelLoader loader;

public : 

    DDBarrel() : Barrel() {

        this->loader.SetScale(1);
        this->loader.LoadModel("barrel_k2.obj");
        this->SetModel(loader.GetModel());
        this->setTypeBarrel(BarrelType::DoubleDamage);
        this->PaintBarrel(Color(0.2, 0.2, 0.2, 1));
        this->SetSpeed(Vector3D(0, 0, 0.35));
        this->SetOrientation(Vector3D(0, 0, 90));
        this->SetOrientationSpeed(Vector3D(3, 0, 0));
    
    }

     CollisionEffect getCollisionEffect() {
    
        return CollisionEffect(-2,0,0);
    
    }

    Item* Clone() {
    
        return new DDBarrel(*this);
    
    }
};

