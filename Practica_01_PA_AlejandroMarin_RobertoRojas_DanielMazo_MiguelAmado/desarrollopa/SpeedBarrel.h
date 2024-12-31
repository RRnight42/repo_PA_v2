#pragma once
#include "Barrel.h"
class SpeedBarrel : public Barrel
{
	SpeedBarrel(Model model) : Barrel(model)
	{
		this->SetSpeed(Vector3D(0, 0, 0.7));
		this->SetType(Barrel::SpeedBarrel);
		model.PaintColor(Color(0, 1, 0, 1));
	}

};

