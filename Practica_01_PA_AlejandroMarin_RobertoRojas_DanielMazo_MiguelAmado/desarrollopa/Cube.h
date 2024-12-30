#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cube : public Solid
{
private:

	float size;

public:

	Cube(float size = 0.5) : Solid() ,  size(size) {}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void Render();
	Solid* Clone();
	
};

