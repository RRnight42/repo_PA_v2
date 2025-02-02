#pragma once
#include "Barrel.h"
#include "Time.h"

class BrakeBarrel : public Barrel
{
	Time timer;
	float seconds;


	bool freno ;
    float delay ;
	float tiempoFreno ;

	float velZ;


public:

	BrakeBarrel(string modelFileSet, float scale, CollisionEffect effectSet, Vector3D speedSet, Color colorSet, float tf = 1.5f , float del = 5 , bool iWB = false) : Barrel(modelFileSet, scale, effectSet, speedSet, colorSet, iWB) {


		this->tiempoFreno = tf;
		this->delay = del;
		this->freno = false;
		this->seconds = 0;
		this->velZ = 0;

	}


	void Brake() {

		velZ = this->GetSpeed().GetZ();

		this->SetSpeed(Vector3D(0,0,0));

	}


	void ReturnVelocity(float vel) {
	
		this->SetSpeed(Vector3D(0, 0, vel));
	
	}

	void Update(const float& timeUpdate) {


		Barrel::Update(timeUpdate);

		timer.Run();
		seconds += timer.GetDeltaTime();


		if (seconds >= delay && freno == false) {
		
			Brake();
			freno = true;
			seconds = 0;
		}

		if (freno == true && seconds >= tiempoFreno) {
		
			ReturnVelocity(this->velZ);
			freno = false;
			seconds = 0;
		}


	}

	Item* Clone() {

		return new BrakeBarrel(*this);

	}






};

