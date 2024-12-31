#pragma once
#include "Barrel.h"
class DDBarrel : public Barrel
{
	DDBarrel(Model model) : Barrel(model)
	{
		this->SetSpeed(Vector3D(0, 0, 0.3));
		this->SetType(Barrel::DoubleDamage);
		model.PaintColor(Color(0.3, 0.3, 0.3, 1));
	}

};

