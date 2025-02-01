#pragma once
#include "Solid.h"
#include "CollisionEffect.h"
class Item : public Solid
{

public : 

    Item() {}

    virtual CollisionEffect getCollisionEffect() = 0;
    virtual Item* Clone() = 0;
    virtual bool isWideBarrel() { return false; };
};

