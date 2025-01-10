#pragma once
#include <cstdlib> 
#include <ctime> 
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Item.h"

class Barrel : public Item
{

private:

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
    
    }
   
    virtual CollisionEffect getCollisionEffect() = 0;

    virtual  Item* Clone() = 0; 
};

