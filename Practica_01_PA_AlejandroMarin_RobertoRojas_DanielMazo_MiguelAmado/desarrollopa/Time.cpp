#include "Time.h"
#include <iostream>

void Time::SetTimeScale(float& timescale)
{
	if (timescale < 0) { timescale = 0; }
	this->timeScale = timescale;
}

void Time::Run()
{
	milliseconds currentMs = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	float deltaMs = (currentMs - this->interTime).count() * 0.001;//Calcula los milisegundos entre el frame anterior y el nuevo
	this->interTime = currentMs;

	this->time += deltaMs;//Actualiza el tiempo del juego
	this->deltaTime = deltaMs * this->timeScale;//Actualiza el DeltaTime
	this->unscaledDeltaTime = deltaMs;//Actualiza el UnscaledDeltaTime
}
