#pragma once
#include "Model.h"
#include <string>

class ModelLoader
{


protected:

	float scale;
	Model model;
	vector<Vector3D> vertexCollection;
	vector<Vector3D> normalCollection;

	float minX, minY, minZ;
	float maxX, maxY, maxZ;


	inline float GetWidth() { return this->maxX - this->minX; }
	inline float GetHeight() { return this->maxY - this->minY; }
	inline float GetLength() { return this->maxZ - this->minZ; }

	void calcBoundaries(Vector3D vector);

	Triangle center(Triangle triangle);

	Vector3D parseObjLinetoVector3D(const string& line);

	Triangle parseObjTriangle(const string& line);

public:

	ModelLoader(float scale = 1) : scale(scale), maxX(0), maxY(0), maxZ(0), minX(0), minY(0), minZ(0) {}

	inline Model GetModel() { return this->model; }
	inline void SetModel(const Model& ModelToSet) { this->model = ModelToSet; }

	inline float GetScale() { return this->scale; }
	inline void SetScale(const float& ScaleToSet) { this->scale = ScaleToSet; }


	void LoadModel(const string& filePath);

	void Clear();

};
