#pragma once
#include "PowerUp.h"
class Ray : public PowerUp
{



public : 



	Ray() : PowerUp() {
	
	
		this->SetType(PowerUp::Ray);
		this->PaintColor(Color(1, 1, 0, 1));
	
	
	
	}


};

