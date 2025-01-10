#pragma once
#include "Solid.h"
#include "Item.h"
#include "Model.h"
#include "ModelLoader.h"

class Coin : public Item
{

private:

	ModelLoader loader;
	Model coinModel;

public:

	Coin() {


		this->loader.SetScale(1);
		this->loader.LoadModel("Coin.obj");
		coinModel.SetModel(loader.GetModel());
		this->coinModel.PaintColor(Color(1, 1, 0, 1));
		this->SetSpeed(Vector3D(0, 0, 0.45));
		this->SetOrientationSpeed(Vector3D(0, 3, 0));

	}

	void Render() {

		this->coinModel.SetPosition(this->GetPosition());
		this->coinModel.SetOrientation(this->GetOrientation());
		this->coinModel.SetSpeed(this->GetSpeed());
		this->coinModel.SetOrientationSpeed(this->GetOrientationSpeed());
		this->coinModel.Render();

	}


	CollisionEffect getCollisionEffect() {
	
		return CollisionEffect(0, 1, 0);
	
	}

	
	Item* Clone() {
	
		return new Coin(*this);
	
	}
};

