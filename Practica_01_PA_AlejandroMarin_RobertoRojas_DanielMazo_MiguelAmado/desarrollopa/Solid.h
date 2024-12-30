#pragma once
#include "Vector3D.h"
#include "Color.h"
#include "util.h"

class Solid
{
private:
	Vector3D position;
	Vector3D orientation;
	Vector3D speed;
	Vector3D orientationSpeed;
	Color color;
	bool useGravity;


public:
	Solid(Vector3D pos = Vector3D() , Vector3D rot = Vector3D() , Vector3D spd = Vector3D(), Vector3D rotSpeed = Vector3D(), Color col = Color() , bool gravity = false) :
		position(pos),
		orientation(rot),
		speed(spd),
		orientationSpeed(rotSpeed),
		color(col),
	    useGravity(gravity){}

	inline Vector3D GetPosition() const { return this->position; }
	inline Vector3D GetOrientation() const { return this->orientation; }
	inline Vector3D GetOrientationSpeed() const { return this->orientationSpeed; }
	inline Vector3D GetSpeed() const { return this->speed; }
	inline Color GetColor() const { return this->color; }
	inline bool GetGravity() const { return this->useGravity; }

	void SetPosition(const Vector3D& coordsToSet) { this->position = coordsToSet; }
	void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }
	void SetOrientationSpeed(const  Vector3D& orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	void SetSpeed(const  Vector3D& speedToSet) { this->speed = speedToSet; }
	void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	void SetGravity(const bool& grav) { this->useGravity = grav; }

	
	float Distance(const Vector3D& other);
	

	virtual void Render() = 0;
	virtual void Update(const float& timeUpdate);



	virtual Solid* Clone() = 0;
};

