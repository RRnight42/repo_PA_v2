#include "Barrel.h"

void Barrel::Render() {

	this->modelBarrel.SetPosition(this->GetPosition() + Vector3D());
	this->modelBarrel.Render();

}

Solid* Barrel::Clone() {
	return new Barrel(*this);
}
