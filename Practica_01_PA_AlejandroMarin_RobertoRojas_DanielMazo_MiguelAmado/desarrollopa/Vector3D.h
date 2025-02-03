#pragma once
#include <iostream>

using namespace std;

template<class S> class Vector3D
{
private:

	S x;
	S y;
	S z;

public:

	Vector3D() : x(0.0), y(0.0), z(0.0) {}

	Vector3D(S xArgument, S yArgument, S zArgument)
	{
		this->x = xArgument;
		this->y = yArgument;
		this->z = zArgument;
	}

	inline S GetX() const { return this->x; }
	inline S GetY() const { return this->y; }
	inline S GetZ() const { return this->z; }

	inline void SetX(const S& xToSet) { this->x = xToSet; }
	inline void SetY(const S& yToSet) { this->y = yToSet; }
	inline void SetZ(const S& zToSet) { this->z = zToSet; }

	Vector3D Add(Vector3D& other);
	Vector3D Product(const S& a);
	Vector3D Division(const S& value);
	float DotProduct(const Vector3D& other);
	Vector3D CrossProduct(const Vector3D& other);
	float Magnitude();
	float Distance(const Vector3D& other);
	void Normalize();

	Vector3D operator+(const Vector3D& vector);
	Vector3D operator-(const Vector3D& vector);
	Vector3D operator*(const S value);
	Vector3D operator/(const S value);
	S operator*(const Vector3D& vector);
	Vector3D operator^(const Vector3D& vector);
	S& operator[](const int& axis);


};

