#include "Text.h"

void Text::Render() {

	glPushMatrix();
	glColor4f(this->GetColor().GetRed(), this->GetColor().GetGreen(), this->GetColor().GetBlue() ,  this->GetColor().GetAlpha());
	glTranslatef(this->GetPosition().GetX(), this->GetPosition().GetY(), this->GetPosition().GetZ());
	glRasterPos3d(0, 0, 0);
	for (char& c : texto) {

		switch (this->getType()) {
		
		case TimesNewRoman10:
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, c);
			break;

		case TimesNewRoman24:
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			break;

		case Helvetica10:
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, c);
			break;

		case Helvetica12:
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
			break;

		case Helvetica18:
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			break;
		
		default:
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, c);
			break;
		
		}

		


	}

	glPopMatrix();


	

}

Solid* Text::Clone(){
	
		return new Text(*this);
	
	}