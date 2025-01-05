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

    PowerUp() {}

    inline PowerUpType GetType() const { return this->type; }
    inline void setTypePowerUp(const PowerUpType& pwt) { this->type = pwt; }

    inline void SetModel(const Model& mdl) { this->itemModel = mdl; }

    inline void PaintPowerUp(const Color& c) { this->itemModel.PaintColor(c); }


    void Render() {

        this->itemModel.SetPosition(this->GetPosition());
        this->itemModel.SetOrientation(this->GetOrientation());
        this->itemModel.SetSpeed(this->GetSpeed());
        this->itemModel.SetOrientationSpeed(this->GetOrientationSpeed());
        this->itemModel.Render();

    }

    virtual  Solid* Clone() = 0;
};


