#pragma once
#include "Barrel.h"
class DDBarrel : public Barrel
{

public:
	DDBarrel() : Barrel()
	{
		this->SetSpeed(Vector3D(0, 0, 0.3));
		this->setTypeBarrel(Barrel::DoubleDamage);
		this->PaintColor(Color(0.3, 0.3, 0.3, 1));
	}

};

