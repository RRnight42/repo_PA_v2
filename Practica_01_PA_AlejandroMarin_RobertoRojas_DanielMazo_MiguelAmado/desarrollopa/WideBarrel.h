#pragma once
#include "Barrel.h"
#include "ModelLoader.h"
class WideBarrel : public Barrel
{
private:
	ModelLoader loader;

public: 
	WideBarrel () : Barrel()
	{
		
		this->loader.LoadModel("Barril2.obj");
		this->SetModel(this->loader.GetModel());
		this->SetSpeed(Vector3D(0, 0, 0.3));
		this->setTypeBarrel(Barrel::WideBarrel);
		this->PaintColor(Color(0.4, 0.2, 0, 1));
	}
};

