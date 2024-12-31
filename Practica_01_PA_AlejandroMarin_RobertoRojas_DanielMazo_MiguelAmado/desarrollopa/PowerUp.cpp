#include "PowerUp.h"

void PowerUp::Render() {
	this->SetPosition(this->GetPosition() + Vector3D());
	this->itemModel.Render();
}

Solid* PowerUp::Clone() {
	return new PowerUp(*this);
}