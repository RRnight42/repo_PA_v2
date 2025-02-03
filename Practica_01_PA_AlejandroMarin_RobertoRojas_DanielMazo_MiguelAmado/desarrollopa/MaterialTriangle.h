#pragma once
#include "Triangle.h"
#include "Material.h"
#include <GL/glut.h>
class MaterialTriangle : public Triangle
{
private:
	Material material;
	void useMaterial();
public:
	MaterialTriangle(
		Vector3D<float> vertex0Argument = Vector3D<float>(),
		Vector3D<float> vertex1Argument = Vector3D<float>(),
		Vector3D<float> vertex2Argument = Vector3D<float>(),
		Vector3D<float> normal0Argument = Vector3D<float>(),
		Vector3D<float> normal1Argument = Vector3D<float>(),
		Vector3D<float> normal2Argument = Vector3D<float>(),
		Color color0Argument = Color(1, 0, 0),
		Color color1Argument = Color(0, 1, 0),
		Color color2Argument = Color(0, 0, 1)) : Triangle(vertex0Argument,
			vertex1Argument, vertex2Argument,
			normal0Argument, normal1Argument, normal2Argument, color0Argument,
			color1Argument, color2Argument)
	{}
	MaterialTriangle(Triangle triangle)
		: MaterialTriangle(
			triangle.GetV0(),
			triangle.GetV1(),
			triangle.GetV2(),
			triangle.GetN0(),
			triangle.GetN1(),
			triangle.GetN2())
	{}
	inline Material GetMaterial() const { return this->material; }
	inline void SetMaterial(const Material& materialToSet) { this->material = materialToSet; }
	void Render();
};