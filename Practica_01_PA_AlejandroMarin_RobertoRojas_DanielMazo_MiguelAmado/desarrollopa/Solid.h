#pragma once
#include "Vector3D.h"
#include "Color.h"
#include "util.h"

class Solid
{




private:
	Vector3D<float> position;
	Vector3D<float> orientation;
	Vector3D<float> speed;
	Vector3D<float> orientationSpeed;
	Color color;
	bool useGravity;


public:
	Solid(Vector3D<float> pos = Vector3D<float>() , Vector3D<float> rot = Vector3D<float>() , Vector3D<float> spd = Vector3D<float>(), Vector3D<float> rotSpeed = Vector3D<float>(), Color col = Color() , bool gravity = false) :
		position(pos),
		orientation(rot),
		speed(spd),
		orientationSpeed(rotSpeed),
		color(col),
	    useGravity(gravity){}

	inline Vector3D<float> GetPosition() const { return this->position; }
	inline Vector3D<float> GetOrientation() const { return this->orientation; }
	inline Vector3D<float> GetOrientationSpeed() const { return this->orientationSpeed; }
	inline Vector3D<float> GetSpeed() const { return this->speed; }
	inline Color GetColor() const { return this->color; }
	inline bool GetGravity() const { return this->useGravity; }

	void SetPosition(const Vector3D<float>& coordsToSet) { this->position = coordsToSet; }
	void SetOrientation(const Vector3D<float>& orientationToSet) { this->orientation = orientationToSet; }
	void SetOrientationSpeed(const  Vector3D<float>& orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	void SetSpeed(const  Vector3D<float>& speedToSet) { this->speed = speedToSet; }
	void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	void SetGravity(const bool& grav) { this->useGravity = grav; }

	
	float Distance(const Vector3D<float>& other);
	

	virtual void Render() = 0;
	virtual void Update(const float& timeUpdate);


	virtual Solid* Clone() = 0;
};

