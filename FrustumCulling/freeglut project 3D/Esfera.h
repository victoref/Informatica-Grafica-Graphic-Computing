#pragma once
#include "ObjetoCuadrico.h"
class Esfera : public ObjetoCuadrico
{
public:
	Esfera(GLdouble radio, GLint slices, GLint stack, color c);
	~Esfera();
	void dibuja();
private:
	GLdouble _radio, _top, _altura;
	GLint _slices, _stacks;
	color _color;
};