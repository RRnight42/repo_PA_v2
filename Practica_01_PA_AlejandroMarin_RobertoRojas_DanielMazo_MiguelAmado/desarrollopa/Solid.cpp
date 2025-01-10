#include "Solid.h"

void Solid::Update(const float& timeUpdate)
{
	this->orientation = this->orientation + this->orientationSpeed * timeUpdate;

    if (this->GetGravity()) {
    
        this->speed = this->speed + Vector3D(0, -0.0098f, 0) * timeUpdate;
    
    }
    // Actualizar la posición con la velocidad
    this->position = this->position + this->speed * timeUpdate;
}


float Solid::Distance(const Vector3D& other) {

    float x = other.GetX() - this->GetPosition().GetX();
    float xx = x * x;
    float y = other.GetY() - this->GetPosition().GetY();
    float yy = y * y;
    float z = other.GetZ() - this->GetPosition().GetZ();
    float zz = z * z;

    return sqrt(xx + yy + zz);

}
/*
void Solid::SetSpeedMCU(Vector3D orbitPoint, float radius, Vector3D speedMCU) {

    Vector3D radialVector = this->position - orbitPoint;

    radialVector.Normalize();


    //if (radialVector.Magnitude() != radius) {
    //    throw std::invalid_argument("La posición del sólido no corresponde al radio proporcionado.");
    //}

    Vector3D up (0, 0, 1); // Vector auxiliar (puedes elegir cualquier otro si es necesario)
    if (fabs(radialVector.GetZ()) > 0.99f) {
        up = Vector3D(0, 1, 0); // Cambia el vector auxiliar si radialVector es casi paralelo a (0,0,1)
    }
    Vector3D tangentialVector = radialVector.CrossProduct(up); // Producto cruzado para obtener el tangente

    //Vector3D tangentialVector(-radialVector.GetY(), radialVector.GetX(), radialVector.GetZ());

    tangentialVector.Normalize();

    tangentialVector = tangentialVector * speedMCU.Magnitude();


    this->speed = tangentialVector;
}
*/