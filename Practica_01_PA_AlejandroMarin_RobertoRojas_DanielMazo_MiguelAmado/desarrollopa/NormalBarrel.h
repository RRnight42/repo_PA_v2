#pragma once
#include "Barrel.h"
class NormalBarrel : public Barrel
{
	NormalBarrel(Model model) : Barrel(model)
	{
		this->SetSpeed(Vector3D(0, 0, 0.3));
		this->SetType(Barrel::Normal);
		model.PaintColor(Color(1, 0.5, 0, 1));
	}
};

