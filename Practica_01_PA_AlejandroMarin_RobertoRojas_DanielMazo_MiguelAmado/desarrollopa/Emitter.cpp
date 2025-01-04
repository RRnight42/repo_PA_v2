#include "Emitter.h"
#include<random>
#include <cstdlib> 
#include <ctime> 

void Emitter::Render()
{
	for (int idx = 0; idx < this->particlesVector.size(); idx++)
	{
		// Verificar si la partícula es válida antes de renderizar
		if (this->particlesVector[idx] != nullptr)
		{
			this->particlesVector[idx]->Render();
		}
	}
}



void Emitter::Update(const float& timeUpdate)
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	long deltaTime = (currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime;

	long currentMs = currentTime.count() - this->initialMilliseconds.count();

	// Revisar partículas existentes
	for (int i = 0; i < particlesVector.size(); i++)
	{
		// Validar si la partícula aún es válida (no es nullptr)
		if (particlesVector[i] != nullptr)
		{
			long particleAge = currentMs - particleCreationTimes[i];

			// Si la partícula excede su vida útil
			if (particleAge > conf.getLifetimeParticle())
			{
				// Liberar memoria y marcar como nullptr
				delete particlesVector[i];
				particlesVector[i] = nullptr;

				// Si el loop está habilitado, eliminar del vector
				if (conf.GetIsLooped())
				{
					particlesVector.erase(particlesVector.begin() + i);
					particleCreationTimes.erase(particleCreationTimes.begin() + i);
					// Ajustar índice
					i--;
				}
			}
			else
			{
				// Actualizar la partícula solo si sigue siendo válida
				particlesVector[i]->Update(timeUpdate);
			}
		}
	}

	// No generar nuevas partículas si no estamos en modo loop y hemos alcanzado el máximo
	if (!conf.GetIsLooped() && particlesVector.size() >= conf.GetMaxParticles())
		return;

	// Generar nuevas partículas si el intervalo lo permite
	if (deltaTime > this->nextInterval)
	{
		int burstSize = generateRandom(conf.GetMinBurstSize(), conf.GetMaxBurstSize());

		for (int i = 0; i < burstSize && particlesVector.size() < conf.GetMaxParticles(); i++)
		{
			int particleID = particlesVector.size();

		
				Solid* newParticle;

			srand((time(0)));
			int generatedparticle = (rand() % conf.getDPT() + 1);

			
				
		    newParticle = conf.GetParticle(generatedparticle)->Clone();
			
		    

			// Generar un desplazamiento solo en el eje Z
			Vector3D basePosition = this->GetPosition();
			Vector3D offset = this->randomPositionOffsetZ(particleID);
			newParticle->SetPosition(basePosition + offset);

			if(!conf.IsUsingModels()){


			if (conf.GetIsRandom())
			{
				newParticle->SetColor(this->randomColor(particleID));
				newParticle->SetSpeed(this->randomSpeed(particleID));
			}
			else
			{
				newParticle->SetColor(conf.getColorConf());
				newParticle->SetSpeed(conf.getSpeedConf());
				newParticle->SetOrientation(conf.getOrientationConf());
				newParticle->SetOrientationSpeed(conf.getOrientationSpeedConf());
			}


			}
			



			particlesVector.push_back(newParticle);
			particleCreationTimes.push_back(currentMs);
		}

		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
		this->nextInterval = generateRandom(conf.GetMinInterval(), conf.GetMaxInterval());
	}
}





Vector3D Emitter::randomPositionOffsetZ(int particleId) {
	mt19937 generator(static_cast<unsigned int>(time(nullptr)) + particleId);
	uniform_real_distribution<float> distribution(-10.0f, 10.0f); 

	float offsetZ = distribution(generator); 

	return Vector3D(0, 0, offsetZ);
}


int Emitter::generateRandom(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}


Color Emitter::randomColor(int particleId) {

	Color colorReturn;

	// Generador de números aleatorios con una semilla basada en particleId
	mt19937 generator(static_cast<unsigned int>(time(nullptr)) + particleId);
	uniform_real_distribution<float> distribution(0.0f, 1.0f);

	float randomValueR = distribution(generator);
	float randomValueG = distribution(generator);
	float randomValueB = distribution(generator);
	float randomValueA = 1.0f;

	colorReturn.SetRed(randomValueR);
	colorReturn.SetGreen(randomValueG);
	colorReturn.SetBlue(randomValueB);
	colorReturn.SetAlpha(randomValueA);

	return colorReturn;

}

Vector3D Emitter::randomSpeed(int particleId) {


	Vector3D spdReturn;

	
	mt19937 generator(static_cast<unsigned int>(time(nullptr)) + particleId);
	uniform_real_distribution<float> distribution(-1.0f, 1.0f);

	
	spdReturn.SetX(distribution(generator));
	spdReturn.SetY(distribution(generator));
	spdReturn.SetZ(distribution(generator));

	return spdReturn * 0.05f;
}

void Emitter::removeParticle(Solid* particle) {
	for (int i = 0; i < particlesVector.size(); i++) {
		
		if (particlesVector[i] == particle) {
			
			delete particlesVector[i];
			
			particlesVector.erase(particlesVector.begin() + i);
			
			return;
		}
	}
}

void Emitter::clearParticles() {
	for (Solid* particle : particlesVector) {
		delete particle; 
	}
	particlesVector.clear(); 
	particleCreationTimes.clear(); 
}


Solid* Emitter::Clone() {

	return new Emitter(*this);

}