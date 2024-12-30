#pragma once
#include <iostream>

using namespace std;

class Vector3D
{
private:

	float x;
	float y;
	float z;

public:

	Vector3D() : x(0.0), y(0.0), z(0.0) {}

	Vector3D(float xArgument, float yArgument, float zArgument)
	{
		this->x = xArgument;
		this->y = yArgument;
		this->z = zArgument;
	}

	inline float GetX() const { return this->x; }
	inline float GetY() const { return this->y; }
	inline float GetZ() const { return this->z; }

	inline void SetX(const float& xToSet) { this->x = xToSet; }
	inline void SetY(const float& yToSet) { this->y = yToSet; }
	inline void SetZ(const float& zToSet) { this->z = zToSet; }

	Vector3D Add(Vector3D& other);
	Vector3D Product(const float& a);
	Vector3D Division(const float& value);
	float DotProduct(const Vector3D& other);
	Vector3D CrossProduct(const Vector3D& other);
	float Magnitude();
	float Distance(const Vector3D& other);
	void Normalize();

	Vector3D operator+(const Vector3D& vector);
	Vector3D operator-(const Vector3D& vector);
	Vector3D operator*(const float value);
	Vector3D operator/(const float value);
	float operator*(const Vector3D& vector);
	Vector3D operator^(const Vector3D& vector);
	float& operator[](const int& axis);


};

