#pragma once
#include "Solid.h"
#include <GL/glut.h>
#include <vector>
#include "Triangle.h"
using namespace std;


class Model : public Solid
{

private:

	vector<Triangle> TriangleCollection;



public:

	Model() {}


	void SetModel(const Model& other) {

		this->TriangleCollection = other.TriangleCollection;
	}

	void AddTriangle(Triangle triangle);

	void Clear();

	void PaintColor(Color color);

	void Render();

	Solid* Clone();  
	

};
