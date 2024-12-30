#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cuboid : public Solid
{
private:

	float length;
	float height;
	float width;

public:

	Cuboid(float l =1, float h = 1, float w = 1) : Solid(), length(l), height(h), width(w)
	{}

	inline float GetLength() { return this->length; }
	inline float GetHeight() { return this->height; }
	inline float GetWidth() { return this->width; }

	void SetLength(float lengthToSet) { this->length = lengthToSet; }
	void SetHeight(float heightToSet) { this->height = heightToSet; }
	void SetWidth(float widthToSet) { this->width = widthToSet; }

	void Render();
	Solid* Clone();
};

