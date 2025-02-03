#include "Vector3D.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath> // Para funciones matemáticas como sqrt

template <class S>
Vector3D<S> Vector3D<S>::Add(Vector3D<S>& other)
{
    return Vector3D<S>(
        this->GetX() + other.GetX(),
        this->GetY() + other.GetY(),
        this->GetZ() + other.GetZ());
}

template <class S>
Vector3D<S> Vector3D<S>::Product(const S& a)
{
    return Vector3D<S>(
        x * a,
        y * a,
        z * a);
}

template <class S>
Vector3D<S> Vector3D<S>::Division(const S& value)
{
    if (value == 0) {
        throw std::runtime_error("División por cero no permitida.");
    }
    return Vector3D<S>(x / value, y / value, z / value);
}

template <class S>
float Vector3D<S>::DotProduct(const Vector3D<S>& other)
{
    return static_cast<float>((x * other.x) + (y * other.y) + (z * other.z));
}

template <class S>
Vector3D<S> Vector3D<S>::CrossProduct(const Vector3D<S>& other)
{
    S crossX = (y * other.z) - (z * other.y);
    S crossY = (z * other.x) - (x * other.z);
    S crossZ = (x * other.y) - (y * other.x);

    return Vector3D<S>(crossX, crossY, crossZ);
}

template <class S>
float Vector3D<S>::Magnitude()
{
    return std::sqrt(static_cast<float>((x * x) + (y * y) + (z * z)));
}

template <class S>
void Vector3D<S>::Normalize()
{
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

template <class S>
float Vector3D<S>::Distance(const Vector3D<S>& other)
{
    S dx = other.GetX() - this->GetX();
    S dy = other.GetY() - this->GetY();
    S dz = other.GetZ() - this->GetZ();
    return std::sqrt(static_cast<float>(dx * dx + dy * dy + dz * dz));
}

template <class S>
Vector3D<S> Vector3D<S>::operator+(const Vector3D<S>& vector)
{
    return Vector3D<S>(this->GetX() + vector.GetX(), this->GetY() + vector.GetY(), this->GetZ() + vector.GetZ());
}

template <class S>
Vector3D<S> Vector3D<S>::operator-(const Vector3D<S>& vector)
{
    return Vector3D<S>(this->GetX() - vector.GetX(), this->GetY() - vector.GetY(), this->GetZ() - vector.GetZ());
}

template <class S>
Vector3D<S> Vector3D<S>::operator*(const S value)
{
    return Vector3D<S>(this->GetX() * value, this->GetY() * value, this->GetZ() * value);
}

template <class S>
Vector3D<S> Vector3D<S>::operator/(const S value)
{
    if (value == 0) {
        throw std::runtime_error("División por cero no permitida.");
    }
    return Vector3D<S>(this->GetX() / value, this->GetY() / value, this->GetZ() / value);
}

template <class S>
S Vector3D<S>::operator*(const Vector3D<S>& vector)
{
    return (this->GetX() * vector.GetX()) + (this->GetY() * vector.GetY()) + (this->GetZ() * vector.GetZ());
}

template <class S>
Vector3D<S> Vector3D<S>::operator^(const Vector3D<S>& vector)
{
    S X = (y * vector.z) - (z * vector.y);
    S Y = (z * vector.x) - (x * vector.z);
    S Z = (x * vector.y) - (y * vector.x);
    return Vector3D<S>(X, Y, Z);
}

template <class S>
S& Vector3D<S>::operator[](const int& axis)
{
    if (axis > 2 || axis < 0) {
        throw std::out_of_range("Axis no encontrado");
    }
    if (axis == 0) return x;
    if (axis == 1) return y;
    return z;
}

// Evita errores de referencia cruzada
template class Vector3D<float>;
template class Vector3D<double>;
template class Vector3D<int>;



