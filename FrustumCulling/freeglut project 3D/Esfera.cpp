#include "Esfera.h"


Esfera::Esfera(GLdouble radio, GLint slices, GLint stack, color c) :
_radio(radio), _slices(slices), _stacks(stack)
{
	_color.b = c.b;
	_color.g = c.g;
	_color.r = c.r;
}


Esfera::~Esfera()
{
}

void Esfera::dibuja(){
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->mT->getM());
	glColor3f(_color.r, _color.g, _color.b);
	gluSphere(o, _radio, _slices, _stacks);
	glPopMatrix();
}



