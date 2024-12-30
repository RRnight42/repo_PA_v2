#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Teapot : public Solid
{
private:
	float size;

public:

	Teapot() : size(0.4), Solid() {}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }
	
	void Render();
	Solid* Clone();
};

