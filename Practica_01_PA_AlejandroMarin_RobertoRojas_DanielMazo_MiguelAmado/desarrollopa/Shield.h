#pragma once
#include "PowerUp.h"


class Shield : public PowerUp
{



public:


    Shield(Model model) : PowerUp(model) {

        this->SetType(PowerUp::Shield);
        model.PaintColor(Color(0.5, 0.5, 0.7, 1));


    }


};
