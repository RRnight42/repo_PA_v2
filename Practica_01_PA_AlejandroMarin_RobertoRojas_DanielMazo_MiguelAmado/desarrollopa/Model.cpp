#include "Model.h"

void Model::PaintColor(Color color)
{
	for (Triangle& triangle : this->TriangleCollection)
	{
		triangle.SetC0(color);
		triangle.SetC1(color);
		triangle.SetC2(color);
	}
}

void Model::Render()
{
	glPushMatrix();
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue() , this->GetColor().GetAlpha());
	glRotatef(this->GetOrientation().GetX(), 1, 0, 0);
	glRotatef(this->GetOrientation().GetY(), 0, 1, 0);
	glRotatef(this->GetOrientation().GetZ(), 0, 0, 1);

	for (Triangle& triangle : this->TriangleCollection)
	{
		triangle.Render();
	}

	glPopMatrix();
}

void Model::AddTriangle(Triangle triangle) {

	this->TriangleCollection.push_back(triangle);
}

void Model::Clear() {
	this->TriangleCollection.clear();
}


Solid* Model :: Clone() {

	return new Model(*this);

}