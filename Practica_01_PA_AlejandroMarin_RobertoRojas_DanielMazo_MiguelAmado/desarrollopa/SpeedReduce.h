#pragma once
#include "PowerUp.h"
class SpeedReduce : public PowerUp
{
private:

	ModelLoader loader;

public:

	SpeedReduce() : PowerUp() {
	
		
		loader.SetScale(0.4);
		loader.LoadModel("Speedfactor.obj");
		this->setTypePowerUp(PowerUp::SpeedReduce);
		this->SetModel(loader.GetModel());
		this->PaintPowerUp(Color(0, 0, 1, 1));
		this->SetSpeed(Vector3D(0, 0, 0.6));
		this->SetOrientationSpeed(Vector3D(0, 3, 0));
	}
	
	Solid* Clone() {

		return new SpeedReduce(*this);


	}
};

