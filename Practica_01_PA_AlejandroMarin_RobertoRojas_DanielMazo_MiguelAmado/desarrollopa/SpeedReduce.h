#pragma once
#include "PowerUp.h"
class SpeedReduce : public PowerUp
{


public:

	SpeedReduce(Model model) : PowerUp(model) {
	
		this->SetType(PowerUp::SpeedReduce);
		model.PaintColor(Color(0, 0, 1, 1));
	
	}
	
};

