#include "MaterialTriangle.h"


void MaterialTriangle::Render() {
	glDisable(GL_COLOR_MATERIAL);
	this->useMaterial();
	glBegin(GL_TRIANGLES);

	glNormal3f(this->GetN0().GetX(), this->GetN0().GetY(), this->GetN0().GetZ());
	glVertex3f(this->GetV0().GetX(), this->GetV0().GetY(), this->GetV0().GetZ());
	glNormal3f(this->GetN1().GetX(), this->GetN1().GetY(), this->GetN1().GetZ());
	glVertex3f(this->GetV1().GetX(), this->GetV1().GetY(), this->GetV1().GetZ());
	glNormal3f(this->GetN2().GetX(), this->GetN2().GetY(), this->GetN2().GetZ());
	glVertex3f(this->GetV2().GetX(), this->GetV2().GetY(), this->GetV2().GetZ());
	glEnd();
}
void MaterialTriangle::useMaterial()
{
	float MatAmbient[] = { this->material.GetAmbientColor().GetRed(), this->material.GetAmbientColor().GetGreen(), this->material.GetAmbientColor().GetBlue(), this->material.GetAmbientColor().GetAlpha(), 1.0f };
	float MatDiffuse[] = { this->material.GetDiffuseColor().GetRed(), this->material.GetDiffuseColor().GetGreen(), this->material.GetDiffuseColor().GetBlue(), this->material.GetDiffuseColor().GetAlpha(),1.0f };
	float MatSpecular[] = { this->material.GetSpecularColor().GetRed(), this->material.GetSpecularColor().GetGreen(), this->material.GetSpecularColor().GetBlue(),this->material.GetSpecularColor().GetAlpha() , 0.1f };
	float MatShininess = 60;
	float black[] = { 0.0f,0.0f,0.0f,1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}