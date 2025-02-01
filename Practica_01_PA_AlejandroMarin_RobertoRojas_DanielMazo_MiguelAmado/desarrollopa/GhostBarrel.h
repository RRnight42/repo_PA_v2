#pragma once
#include "Barrel.h"
#include "Time.h"

class GhostBarrel :
    public Barrel
{

    Time timer;
    float seconds;


	bool iniciatedChange = false;
	const float tiempoInicializacion = 1;
	const float periodoActualizacion = 0.1f;
public: 

	GhostBarrel(string modelFileSet, float scale, CollisionEffect effectSet, Vector3D speedSet, Color colorSet, bool iWB = false) : Barrel(modelFileSet, scale, effectSet, speedSet, colorSet, iWB) {}

    void Fade() {
    
    
		float alpha = this->GetColor().GetAlpha();

		alpha = alpha - 0.1f;
    
		this->PaintBarrel(Color(1, 1, 1, alpha));
    
    }


	// en teoria si el alpha funcionara bien  , se espera un segundo cuando se genera y luego desaparece 


	void Update(const float& timeUpdate) {


		Barrel::Update(timeUpdate);

		timer.Run();
		seconds += timer.GetDeltaTime();

		if (!iniciatedChange) {

		while (seconds < tiempoInicializacion) {}
		iniciatedChange = true;
		seconds = 0;
        }else if (seconds >= periodoActualizacion && this->GetColor().GetAlpha() > 0) {
			Fade();
			seconds = 0;
		}

		


		cout << seconds << endl;
	}



};

