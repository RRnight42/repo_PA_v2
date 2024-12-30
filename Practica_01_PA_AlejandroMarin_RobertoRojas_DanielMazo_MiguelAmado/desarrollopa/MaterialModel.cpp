#include "MaterialModel.h"
#include <iostream>

void MaterialModel::AddMaterialTriangle(MaterialTriangle triangle)
{
	this->triangles.push_back(triangle);
}

void MaterialModel::Clear() {


	this->triangles.clear();


}


void MaterialModel::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glColor4f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue() , GetColor().GetAlpha());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	for (MaterialTriangle triangle : this->triangles)
	{
		triangle.Render();
	}
	glPopMatrix();
}

Solid* MaterialModel::Clone() {

	return new MaterialModel(*this);

}