#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Sphere : public Solid
{
private:

	float radius;
	int slices;
	int slacks;

public:


	Sphere(float radius = 1.0 , int slices = 10 , int slacks = 8): Solid(), radius(radius), slices(slices), slacks(slacks) {}

	

	inline float GetRadius() { return this->radius; }
	inline int GetSlices() { return this->slices; }
	inline int GetSlacks() { return this->slacks; }

	void SetRadius(float radiusToSet) { this->radius = radiusToSet; }
	void SetSlices(int slicesToSet) { this->slices = slicesToSet; }
	void SetSlacks(int slacksToSet) { this->slacks = slacksToSet; }

	void Render();
	Solid* Clone();

};

