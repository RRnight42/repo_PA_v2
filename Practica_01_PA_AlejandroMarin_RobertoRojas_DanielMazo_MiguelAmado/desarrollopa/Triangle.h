#pragma once
#include "Solid.h"
#include <GL/glut.h>


class Triangle : public Solid
{

private: 

	Vector3D v0, v1, v2;
	Color    c0, c1, c2;
	Vector3D n0, n1, n2;

public :


	Triangle(Vector3D v0a  = Vector3D() , 
		     Vector3D v1a  = Vector3D() ,
		     Vector3D v2a  = Vector3D() ,
		     
		     Vector3D n0a = Vector3D(),
		     Vector3D n1a = Vector3D(),
		     Vector3D n2a = Vector3D(),
		     
		     Color c0a = Color(),
		     Color c1a = Color(),
		     Color c2a = Color()) : v0(v0a) , v1(v1a), v2(v2a) , c0(c0a) , c1(c1a) , c2(c2a) , n0(n0a), n1(n1a), n2(n2a) {}


	inline Vector3D GetV0() { return this->v0; }
	inline Vector3D GetV1() { return this->v1; }
	inline Vector3D GetV2() { return this->v2; }

	inline Vector3D GetN0() { return this->n0; }
	inline Vector3D GetN1() { return this->n1; }
	inline Vector3D GetN2() { return this->n2; }

	inline Color GetC0() { return this->c0; }
	inline Color GetC1() { return this->c1; }
	inline Color GetC2() { return this->c2; }

	inline void SetV0(const Vector3D& arg) { this->v0 = arg; }
	inline void SetV1(const Vector3D& arg) { this->v1 = arg; }
	inline void SetV2(const Vector3D& arg) { this->v2 = arg; }

	inline void SetN0(const Vector3D& arg) { this->n0 = arg; }
	inline void SetN1(const Vector3D& arg) { this->n1 = arg; }
	inline void SetN2(const Vector3D& arg) { this->n2 = arg; }

	inline void SetC0(const Color& arg) { this->c0 = arg; }
	inline void SetC1(const Color& arg) { this->c1 = arg; }
	inline void SetC2(const Color& arg) { this->c2 = arg; }


	void Render();
	Solid* Clone();


};

