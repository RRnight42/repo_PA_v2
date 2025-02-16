#include "Emitter.h"
#include<random>
#include <cstdlib> 
#include <ctime> 

void Emitter::Render()
{
	for (int idx = 0; idx < this->particlesVector.size(); idx++)
	{
		// Verificar si la part�cula es v�lida antes de renderizar
		if (this->particlesVector[idx] != nullptr)
		{
			this->particlesVector[idx]->Render();
		}
	}
}

// funcion de probabilidades///
/*
Item* Emitter::generateSolidByProbability(const vector<pair<Item*, float>>& solidsWithProbabilities) {
	// Calcular la suma de las probabilidades (por si no suman exactamente 1.0)
	float totalProbability = 0.0f;
	for (const auto& entry : solidsWithProbabilities) {
		totalProbability += entry.second;
	}

	// Generar un n�mero aleatorio entre 0.0 y el total de probabilidades
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(0.0f, totalProbability);

	float randomValue = dis(gen);
	float cumulative = 0.0f;

	// Evaluar qu� probabilidad corresponde al valor generado
	for (const auto& entry : solidsWithProbabilities) {
		cumulative += entry.second;
		if (randomValue <= cumulative) {
			return entry.first->Clone();
		}
	}

	return nullptr; // No deber�a llegar aqu�
}*/

Item* Emitter::generateSolidByProbability(const vector<pair<Item*, float>>& solidsWithProbabilities) {
	// Calcular la suma de las probabilidades
	float totalProbability = 0.0f;
	for (const auto& entry : solidsWithProbabilities) {
		totalProbability += entry.second;
	}

	// Validar que las probabilidades sean v�lidas (ninguna debe ser negativa)
	if (totalProbability < 0.0f) {
		throw invalid_argument("La suma de las probabilidades no puede ser negativa.");
	}

	// Generar un n�mero aleatorio entre 0.0 y 1.0
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(0.0f, 1.0f);

	float randomValue = dis(gen); // Valor aleatorio entre 0 y 1
	float cumulative = 0.0f;

	// Evaluar qu� probabilidad corresponde al valor generado
	for (const auto& entry : solidsWithProbabilities) {
		cumulative += entry.second / totalProbability; // Normalizar las probabilidades a un rango [0, 1]
		if (randomValue <= cumulative) {
			return entry.first->Clone(); // Generar el clon del objeto seleccionado
		}
	}

	// Si el valor generado est� fuera del rango de probabilidades, no generar nada
	return nullptr;
}



void Emitter::Update(const float& timeUpdate)
{

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	long deltaTime = (currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime;

	long currentMs = currentTime.count() - this->initialMilliseconds.count();

	// Revisar part�culas existentes
	for (int i = 0; i < particlesVector.size(); i++)
	{
		// Validar si la part�cula a�n es v�lida (no es nullptr)
		if (particlesVector[i] != nullptr)
		{
			long particleAge = currentMs - particleCreationTimes[i];

			// Si la part�cula excede su vida �til
			if (particleAge > conf.getLifetimeParticle())
			{
				// Liberar memoria y marcar como nullptr
				delete particlesVector[i];
				particlesVector[i] = nullptr;

				// Si el loop est� habilitado, eliminar del vector
				if (conf.GetIsLooped())
				{
					particlesVector.erase(particlesVector.begin() + i);
					particleCreationTimes.erase(particleCreationTimes.begin() + i);
					// Ajustar �ndice
					i--;
				}
			}
			else
			{
				// Actualizar la part�cula solo si sigue siendo v�lida
				particlesVector[i]->Update(timeUpdate);
			}
		}
	}

	// No generar nuevas part�culas si no estamos en modo loop y hemos alcanzado el m�ximo
	if (!conf.GetIsLooped() && particlesVector.size() >= conf.GetMaxParticles())
		return;

	// Generar nuevas part�culas si el intervalo lo permite
	if (deltaTime > this->nextInterval)
	{
		int burstSize = generateRandom(conf.GetMinBurstSize(), conf.GetMaxBurstSize());

		for (int i = 0; i < burstSize && particlesVector.size() < conf.GetMaxParticles(); i++)
		{
			int particleID = particlesVector.size();

		
			Item* newParticle = generateSolidByProbability(conf.getVectorAndProbabilites());

			if (newParticle != nullptr) {
				newParticle->SetPosition(Vector3D<float>(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ()));

				// Generar un desplazamiento solo en el eje Z
				Vector3D<float> basePosition = this->GetPosition();
				Vector3D<float> offset = this->randomPositionOffsetZ(particleID);
				newParticle->SetPosition(basePosition + offset);

				particlesVector.push_back(newParticle);
				particleCreationTimes.push_back(currentMs);

			}
		}

		this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
		this->nextInterval = generateRandom(conf.GetMinInterval(), conf.GetMaxInterval());
	}
}





Vector3D<float> Emitter::randomPositionOffsetZ(int particleId) {
	mt19937 generator(static_cast<unsigned int>(time(nullptr)) + particleId);
	uniform_real_distribution<float> distribution(-10.0f, 10.0f); 

	float offsetZ = distribution(generator); 

	return Vector3D<float>(0, 0, offsetZ);
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

	// Generador de n�meros aleatorios con una semilla basada en particleId
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

/*Vector3D Emitter::randomSpeed(int particleId) {


	Vector3D spdReturn;

	
	mt19937 generator(static_cast<unsigned int>(time(nullptr)) + particleId);
	uniform_real_distribution<float> distribution(-1.0f, 1.0f);

	
	spdReturn.SetX(distribution(generator));
	spdReturn.SetY(distribution(generator));
	spdReturn.SetZ(distribution(generator));

	return spdReturn * 0.05f;
}*/

void Emitter::removeParticle(Item* particle) {
	for (int i = 0; i < particlesVector.size(); i++) {
		
		if (particlesVector[i] == particle) {

			
			delete particlesVector[i];
			
			particlesVector.erase(particlesVector.begin() + i);
			
		}
	}
}

void Emitter::clearParticles() {
	for (Item* particle : particlesVector) {
		delete particle; 
	}
	particlesVector.clear(); 
	particleCreationTimes.clear(); 
}


Solid* Emitter::Clone() {

	return new Emitter(*this);

}