#pragma once
#include "ObjetoCuadrico.h"
class Disco : public ObjetoCuadrico
{
public:
	Disco(GLdouble radioIn, GLdouble radioOut, GLint slices, GLint loops, color c);
	~Disco();
	void dibuja();

private:
	GLdouble _radioIn, _radioOut;
	GLint _slices, _loops;
	color _color;
};