#pragma once
#include "ObjetoCuadrico.h"

class Cilindro : public ObjetoCuadrico
{
public:
	Cilindro(GLdouble base, GLdouble top, GLdouble altura, GLint slices, GLint stack, color c);
	~Cilindro();
	void dibuja();

private:
	GLdouble _radio, _base, _top, _altura;
	GLint _slices, _stacks;
	color _color;

};

