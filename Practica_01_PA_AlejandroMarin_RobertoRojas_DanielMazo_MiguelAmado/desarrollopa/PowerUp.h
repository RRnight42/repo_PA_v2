#pragma once
#include "Model.h"
#include "ModelLoader.h"

class PowerUp : public Solid {


public:

    enum PowerUpType { Heart, Ray, Shield, SpeedReduce };


private:


    PowerUpType type;
    Model itemModel;

public:

    PowerUp(Model model) {

        this->itemModel = model;

    }

    inline PowerUpType GetType() const { return this->type; }
    inline void SetType(const PowerUpType& puSet) { this->type = puSet; }

    inline Model GetItemModel() const { return this->itemModel; }
    inline void SetItemModel(const Model& model) { this->itemModel = model; }

    void Render();
    Solid* Clone();
};


