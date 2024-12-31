#pragma once
#include "PowerUp.h"
class Ray : public PowerUp
{



public:



    Ray(Model model) : PowerUp(model) {


        this->SetType(PowerUp::Ray);
        model.PaintColor(Color(1, 1, 0, 1));

    }


};