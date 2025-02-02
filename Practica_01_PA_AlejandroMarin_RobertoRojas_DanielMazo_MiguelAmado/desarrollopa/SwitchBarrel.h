#pragma once
#include "Barrel.h"
#include "Time.h"
#include <random>

class SwitchBarrel : public Barrel
{

	Time timer;
	float seconds;
	
	const float c1 = -3.45;
	const float c2 = 0;
	const float c3 = 3.45;

	int actualCarril;

	const float tiempoCambio = 1.5f;
	

public : 

	SwitchBarrel(string modelFileSet, float scale, CollisionEffect effectSet, Vector3D speedSet, Color colorSet, bool iWB = false) : Barrel(modelFileSet, scale , effectSet , speedSet , colorSet , iWB) {
	

		seconds = 0;
	
		if (this->GetPosition().GetX() == c1) {
		
			this->actualCarril = 1;
		
		
		}
	
		if (this->GetPosition().GetX() == c2) {

			this->actualCarril = 2;


		}

		if (this->GetPosition().GetX() == c3) {

			this->actualCarril = 3;


		}


	
	}


	void Switch() {
	
			int select;
			srand((time(0)));
			select = (rand() % 2);

			switch (actualCarril) {
			
			
			case 1:
					
					this->actualCarril = 2;
					this->SetPosition(Vector3D(c2, this->GetPosition().GetY(), this->GetPosition().GetZ()));				

			break;
			
			case 2:

				if (select == 0) {

					this->actualCarril = 1;
					this->SetPosition(Vector3D(c1, this->GetPosition().GetY(), this->GetPosition().GetZ()));
				}
				else {

					this->actualCarril = 3;
					this->SetPosition(Vector3D(c3, this->GetPosition().GetY(), this->GetPosition().GetZ()));


				}

			break;

			case 3:


					this->actualCarril = 2;
					this->SetPosition(Vector3D(c2, this->GetPosition().GetY(), this->GetPosition().GetZ()));

			break;
			
			
			}
	
	
	}

	void Update(const float& timeUpdate) {


		Barrel::Update(timeUpdate);

		timer.Run();
		seconds += timer.GetDeltaTime();

		if (seconds >= tiempoCambio) {
		
		Switch();
		seconds = 0;
		
		}

		
	
	}

	Item* Clone() {
	
		return new SwitchBarrel(*this);
	
	}

	
};

