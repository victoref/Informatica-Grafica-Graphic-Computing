#include "Disco.h"


Disco::Disco(GLdouble radioIn, GLdouble radioOut, GLint slices, GLint loops, color c) :
_radioIn(radioIn), _radioOut(radioOut), _slices(slices), _loops(loops)
{
	_color.b = c.b;
	_color.g = c.g;
	_color.r = c.r;
}


Disco::~Disco()
{
}

void Disco::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(_color.r, _color.g, _color.b);
	glMultMatrixf(this->mT->getM());
	gluDisk(o, _radioIn, _radioOut, _slices, _loops);
	glPopMatrix();
}

