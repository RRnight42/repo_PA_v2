#pragma once
#include "Barrel.h"
class NormalBarrel : public Barrel
{

public:
	NormalBarrel() : Barrel()
	{
		this->SetSpeed(Vector3D(0, 0, 0.3));
		this->setTypeBarrel(Barrel::Normal);
		this->PaintColor(Color(1, 0.5, 0, 1));
	}
};

