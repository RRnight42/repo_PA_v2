#include "Triangle.h"


void Triangle :: Render() {


	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_TRIANGLES);

    glColor4f(this->GetC0().GetRed() , this->GetC0().GetGreen() , this->GetC0().GetBlue(), this->GetC0().GetAlpha());
	glNormal3f(this->GetN0().GetX() , this->GetN0().GetY() ,this->GetN0().GetZ());
	glVertex3f(this->GetV0().GetX(), this->GetV0().GetY(), this->GetV0().GetZ());

	glColor4f(this->GetC1().GetRed(), this->GetC1().GetGreen(), this->GetC1().GetBlue(), this->GetC1().GetAlpha());
	glNormal3f(this->GetN1().GetX(), this->GetN1().GetY(), this->GetN1().GetZ());
	glVertex3f(this->GetV1().GetX(), this->GetV1().GetY(), this->GetV1().GetZ());

	glColor4f(this->GetC2().GetRed(), this->GetC2().GetGreen(), this->GetC2().GetBlue(), this->GetC2().GetAlpha());
	glNormal3f(this->GetN2().GetX(), this->GetN2().GetY(), this->GetN2().GetZ());
	glVertex3f(this->GetV2().GetX(), this->GetV2().GetY(), this->GetV2().GetZ());

	glEnd();
}


Solid* Triangle::Clone() {

	return new Triangle(*this);

}