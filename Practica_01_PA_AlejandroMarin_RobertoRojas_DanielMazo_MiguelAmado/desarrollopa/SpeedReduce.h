#pragma once
#include "PowerUp.h"
class SpeedReduce : public PowerUp
{


public:

	SpeedReduce() : PowerUp() {
	
		this->SetType(PowerUp::SpeedReduce);
		this->PaintColor(Color(0, 0, 1, 1));
	
	}
	
};

