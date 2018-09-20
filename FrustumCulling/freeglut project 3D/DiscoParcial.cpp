#include "DiscoParcial.h"


DiscoParcial::DiscoParcial(GLdouble radioIn, GLdouble radioOut, GLint slices, GLint loops, GLint anguloIni, GLint anguloFin, color c) :
_radioIn(radioIn), _radioOut(radioOut), _slices(slices), _loops(loops), _angIni(anguloIni), _angFin(anguloFin)
{
	_color.b = c.b;
	_color.g = c.g;
	_color.r = c.r;
}


DiscoParcial::~DiscoParcial()
{
}

void DiscoParcial::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(_color.r, _color.g, _color.b);
	glMultMatrixf(this->mT->getM());
	gluPartialDisk(o, _radioIn, _radioOut, _slices, _loops, _angIni, _angFin);
	glPopMatrix();
}