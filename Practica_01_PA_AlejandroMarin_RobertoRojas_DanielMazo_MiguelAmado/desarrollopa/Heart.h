#pragma once
#include "PowerUp.h"
#include <cstdlib> 
#include <ctime> 

class Heart : public PowerUp
{

public:

    enum TypeHeart { NormalHeart, SuperHeart, PoisonHeart };

private:

    TypeHeart typeheart;

public:


    Heart(Model model) : PowerUp(model) {


        this->SetType(PowerUp::Heart);
        srand(static_cast<unsigned>(time(0)));
        this->typeheart = static_cast<TypeHeart>(rand() % 3);


        switch (this->typeheart) {


        case NormalHeart:
            model.PaintColor(Color(1, 0, 0, 1));
            break;

        case SuperHeart:
            model.PaintColor(Color(1, 1, 0, 1));
            break;

        case PoisonHeart:
            model.PaintColor(Color(0.31, 0.11, 0.36, 1));
            break;


        }



    }

    inline TypeHeart getHeartType() const { return this->typeheart; }
};
