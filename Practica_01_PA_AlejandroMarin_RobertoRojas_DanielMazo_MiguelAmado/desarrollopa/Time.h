#pragma once
#include <chrono>
using namespace std;
using namespace chrono;

class Time
{
private:
	milliseconds interTime;

	float time;
	float timeScale;
	double deltaTime;
	double unscaledDeltaTime;

public:
	Time() : time(0), timeScale(1), deltaTime(0), unscaledDeltaTime(0)
	{
		interTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	}

	inline float GetTime() { return time; }
	inline float GetDeltaTime() { return deltaTime; }
	inline double GetUnscaledDeltaTime() { return unscaledDeltaTime; }
	void SetTimeScale(float& timeScale);//Establece la velocidad a la que pasa el tiempo

	void Run();//Actualiza el tiempo del juego
};
