#include "Cilindro.h"


Cilindro::Cilindro(GLdouble base, GLdouble top, GLdouble altura,GLint slices, GLint stack, color c): 
_base(base), _top(top), _altura(altura), _slices(slices), _stacks(stack)
{
	_color.b = c.b;
	_color.g = c.g;
	_color.r = c.r;

}


Cilindro::~Cilindro()
{
}

void Cilindro::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->mT->getM());
	glColor3f(_color.r, _color.g, _color.b);
	gluCylinder(o, _base, _top, _altura, _slices, _stacks);
	glPopMatrix();
}
