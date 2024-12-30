#include "Vector3D.h"
#include <iostream>;
#include <cstdlib>;
#include <ctime>;




Vector3D Vector3D::Add(Vector3D& other)
{
	return Vector3D(
		this->GetX() + other.GetX(),
		this->GetY() + other.GetY(),
		this->GetZ() + other.GetZ());
}



Vector3D Vector3D::Product(const float& a)
{
	return Vector3D(
		x * a,
		y * a,
		z * a);
}

Vector3D Vector3D::Division(const float& value) {


	Vector3D newVector(this->GetX() / value, this->GetY() / value, this->GetZ() / value);
	return newVector;
}

float Vector3D::DotProduct(const Vector3D& other) {
	return (x * other.x) + (y * other.y) + (z * other.z);
}

Vector3D Vector3D::CrossProduct(const Vector3D& other) {
	float crossX = (y * other.z) - (z * other.y);
	float crossY = (z * other.x) - (x * other.z);
	float crossZ = (x * other.y) - (y * other.x);

	return Vector3D(crossX, crossY, crossZ);
}


float Vector3D::Magnitude() {
	return sqrt((x) * (x) + (y) * (y) + (z) * (z));
}

void Vector3D::Normalize() {
		float mag = this->Magnitude(); 
		if (mag > 0.0f) {
			this->x /= mag;
			this->y /= mag;
			this->z /= mag;
		}
		else {
			throw std::runtime_error("No se puede normalizar un vector de magnitud cero.");
		}
	
}


float Vector3D::Distance(const Vector3D& other) {
	
	float dx = other.GetX() - this->GetX();
	float dy = other.GetY() - this->GetY();
	float dz = other.GetZ() - this->GetZ();
	return sqrt(dx * dx + dy * dy + dz * dz);
}


Vector3D Vector3D :: operator+(const Vector3D& vector)  {

	float x = this->GetX() + vector.GetX();
	float y = this->GetY() + vector.GetY();
	float z = this->GetZ() + vector.GetZ();

	return Vector3D(x, y, z);

}
Vector3D Vector3D :: operator-(const Vector3D& vector) {

	float x = this->GetX() - vector.GetX();
	float y = this->GetY() - vector.GetY();
	float z = this->GetZ() - vector.GetZ();

	return Vector3D(x, y, z);
}
Vector3D Vector3D :: operator*(const float value) {

	float x = this->GetX() * value;
	float y = this->GetY() * value;
	float z = this->GetZ() * value;

	return Vector3D(x, y, z);
}

Vector3D Vector3D::operator/(const float value)
{
	return Vector3D(this->GetX() / value, this->GetY() / value, this->GetZ() / value);
}

float Vector3D::operator*(const Vector3D& vector)
{
	float x = this->GetX() * vector.GetX();
	float y = this->GetY() * vector.GetY();
	float z = this->GetZ() * vector.GetZ();

	return (x + y + z);
}

Vector3D Vector3D::operator^(const Vector3D& vector) {
	float X = (y * vector.z) - (z * vector.y);
	float Y = (z * vector.x) - (x * vector.z);
	float Z = (x * vector.y) - (y * vector.x);

	return Vector3D(X, Y, Z);

}

float& Vector3D :: operator[](const int& axis) {

	if (axis > 2 || axis < 0) {
		throw out_of_range("Axis no encontrado");
	}

	if (axis == 0) return x;
	if (axis == 1) return y;
	if (axis == 2) return z;


};


