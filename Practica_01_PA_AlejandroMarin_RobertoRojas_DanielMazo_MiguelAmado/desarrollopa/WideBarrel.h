#pragma once
#include "Barrel.h"
class WideBarrel : public Barrel
{
	WideBarrel (Model model) : Barrel(model)
	{
		this->SetSpeed(Vector3D(0, 0, 0.3));
		this->SetType(Barrel::WideBarrel);
		model.PaintColor(Color(0.4, 0.2, 0, 1));
	}
};

