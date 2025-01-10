#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Item.h"

class PowerUp : public Item {

private:

    Model itemModel;

public:

    PowerUp() {}

    inline void SetModel(const Model& mdl) { this->itemModel = mdl; }

    inline void PaintPowerUp(const Color& c) { this->itemModel.PaintColor(c); }


    void Render() {

        this->itemModel.SetPosition(this->GetPosition());
        this->itemModel.SetOrientation(this->GetOrientation());
        this->itemModel.SetSpeed(this->GetSpeed());
        this->itemModel.SetOrientationSpeed(this->GetOrientationSpeed());
        this->itemModel.Render();

    }

    virtual CollisionEffect getCollisionEffect() = 0;

    virtual  Item* Clone() = 0;
};


