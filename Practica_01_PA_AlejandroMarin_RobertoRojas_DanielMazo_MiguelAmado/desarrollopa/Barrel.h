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
    Model modelBarrel;


public:

    Barrel(Model model) { 
        this->modelBarrel = model;
    }

    inline BarrelType GetType() const { return this->type; }
    inline void SetType(const BarrelType& BarrelSet) { this->type = BarrelSet; }

    inline Model GetModelBarrel() const { return this->modelBarrel; }
    inline void SetModelBarrel(const Model& model) { this->modelBarrel = model; }

    void Render();
    Solid* Clone();

};

