#pragma once
#include "Solid.h"
#include "MaterialTriangle.h"
#include <vector>

class MaterialModel : public Solid
{

private:

	vector<MaterialTriangle> triangles;



public:
	MaterialModel() {}

	void SetModel(const MaterialModel& other) {

		this->triangles = other.triangles;
	}

	void AddMaterialTriangle(MaterialTriangle triangle);
	void Clear();
	void Render();

	Solid* Clone();
};
