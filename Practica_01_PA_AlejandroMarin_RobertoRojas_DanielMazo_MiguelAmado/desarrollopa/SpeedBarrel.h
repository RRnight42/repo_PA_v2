#pragma once
#include "Barrel.h"
class SpeedBarrel : public Barrel
{

public:
	SpeedBarrel() : Barrel()
	{
		this->SetSpeed(Vector3D(0, 0, 0.7));
		this->setTypeBarrel(Barrel::SpeedBarrel);
		this->PaintColor(Color(0, 1, 0, 1));
	}

};

