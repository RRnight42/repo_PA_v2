#pragma once
#include "Barrel.h"
class SwitchBarrel : public Barrel
{
private:
	float elapsedTime;            //Tiempo acumulado
	float switchInterval;         //Intervalo de cambio de carril
	vector<Vector3D> lanes;  //Posiciones posibles de los carriles
	float initialPosition;

public:
	SwitchBarrel(Model model, float interval = 3.0f) : Barrel(model), elapsedTime(0), switchInterval(interval)
	{
		lanes = {
			Vector3D(-0.45f, -0.3f, 0.0f), //Carril izquierdo
			Vector3D(0.0f, -0.3f, 0.0f),   //Carril central
			Vector3D(0.45f, -0.3f, 0.0f)   //Carril derecho
		};

		this->SetSpeed(Vector3D(0, 0, 0.3));
		this->SetType(Barrel::SwitchBarrel);
		model.PaintColor(Color(1, 1, 1, 1));
	}

    void Update(float deltaTime) {

        elapsedTime += deltaTime;

       
        if (elapsedTime >= switchInterval) {
           
            Vector3D newPosition = lanes[rand() % lanes.size()];
			newPosition.SetZ(this->GetPosition().GetZ());

            // Establece la nueva posición
            this->SetPosition(newPosition);

            // Reinicia el temporizador
            elapsedTime = 0;

        }
    }
};

