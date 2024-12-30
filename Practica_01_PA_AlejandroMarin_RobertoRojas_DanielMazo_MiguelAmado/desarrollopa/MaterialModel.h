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
	void AddMaterialTriangle(MaterialTriangle triangle);
	void Clear();
	void Render();

	Solid* Clone();
};
