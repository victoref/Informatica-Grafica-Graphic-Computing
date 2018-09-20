#pragma once
#include "ObjetoCuadrico.h"
class DiscoParcial : public ObjetoCuadrico
{
public:
	DiscoParcial(GLdouble radioIn, GLdouble radioOut, GLint slices, GLint loops, GLint anguloIni, GLint anguloFin, color c);
	~DiscoParcial();
	void dibuja();

private:
	GLdouble _radioIn, _radioOut;
	GLint _slices, _loops, _angIni, _angFin;
	color _color;
};
