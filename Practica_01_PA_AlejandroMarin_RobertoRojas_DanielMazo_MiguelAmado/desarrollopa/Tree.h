#pragma once
#include "Item.h"
#include "MaterialModelLoader.h"
#include "MaterialModel.h"

class Tree :
    public Item
{

private:

	MaterialModelLoader loader;
	MaterialModel TreeModel;

public:

	Tree() {


		this->loader.SetScale(0.3);
		this->loader.LoadModel("arbol_low.obj");
		TreeModel.SetModel(loader.GetModel());
		this->SetSpeed(Vector3D<float>(0, 0, 0.9));

	}

	void Render() {

		this->TreeModel.SetPosition(this->GetPosition());
		this->TreeModel.SetOrientation(this->GetOrientation());
		this->TreeModel.SetSpeed(this->GetSpeed());
		this->TreeModel.Render();

	}


	CollisionEffect getCollisionEffect() {

		return CollisionEffect(0, 0, 0);

	}


	Item* Clone() {

		return new Tree(*this);

	}

	bool isWideBarrel() { return false; }


};

