#pragma once
#include <cstdlib> 
#include <ctime> 
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"
class Barrel : public Solid
{
public:

    enum BarrelType { Normal, WideBarrel, DoubleDamage, SpeedBarrel };


private:

    
    BarrelType type;
    Model model;


public:

    Barrel() {}

    inline BarrelType GetType() const { return this->type; }
    inline void setTypeBarrel(const BarrelType& bt) { this->type = bt; }

    inline void SetModel(const Model& mdl) { this->model = mdl; }

    inline void PaintBarrel(const Color& c) { this->model.PaintColor(c); }


    void Render() {

        this->model.SetPosition(this->GetPosition());
        this->model.SetOrientation(this->GetOrientation());
        this->model.SetSpeed(this->GetSpeed());
        this->model.SetOrientationSpeed(this->GetOrientationSpeed());
        this->model.Render();
    
    }
   
    virtual  Solid* Clone() = 0; 
};

