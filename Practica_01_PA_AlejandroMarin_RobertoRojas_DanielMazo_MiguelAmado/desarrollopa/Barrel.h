#pragma once
#include <cstdlib> 
#include <ctime> 
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Item.h"
#include "Sphere.h"

class Barrel : public Item
{

private:
    //Sphere* esfera = new Sphere(0.7);    //Esta esfera es para renderizar las posiciones reales de los barriles en debug
    Model model;

public:

    Barrel() {}


    inline void SetModel(const Model& mdl) { this->model = mdl; }

    inline void PaintBarrel(const Color& c) { this->model.PaintColor(c); }


    void Render() {

        this->model.SetPosition(this->GetPosition());
        this->model.SetOrientation(this->GetOrientation());
        this->model.SetSpeed(this->GetSpeed());
        this->model.SetOrientationSpeed(this->GetOrientationSpeed());
        this->model.Render();
        //this->esfera->SetPosition(this->GetPosition());
        //this->esfera->Render();
    }
   
    virtual CollisionEffect getCollisionEffect() = 0;

    virtual  Item* Clone() = 0; 
    virtual bool isWideBarrel() = 0;
};

