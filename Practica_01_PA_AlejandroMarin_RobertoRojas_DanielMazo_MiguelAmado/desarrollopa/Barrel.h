#pragma once
#include <cstdlib> 
#include <ctime> 
#include "Solid.h"
#include "Model.h"
class Barrel : public Solid
{
public:

    enum BarrelType { Normal, WideBarrel, DoubleDamage, SpeedBarrel, SwitchBarrel };


private:

    
    BarrelType type;
    Model model;


public:

    Barrel() {}

    inline BarrelType GetType() const { return this->type; }
    inline void setTypeBarrel(const BarrelType& bt) { this->type = bt; }

    inline void SetModel(const Model& mdl) { this->model = mdl; }
    inline void PaintColor(const Color& c) { this->model.PaintColor(c); }

    void Render() {

       
    
        this->model.Render();
    
    
    }
   
    Solid* Clone() {
    
        return new Barrel(*this);
    
    }
};

