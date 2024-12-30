#pragma once
#include "PowerUp.h"


class Shield : public PowerUp
{



public : 


	Shield() : PowerUp() {

		this->SetType(PowerUp::Shield);
		this->PaintColor(Color(0.5, 0.5, 0.7, 1));


	}


};

