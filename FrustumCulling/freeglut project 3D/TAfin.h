#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

#include "PuntoVector3D.h"


class TAfin
{
public:
	TAfin();
	~TAfin();

	void traslada(float x, float y, float z);//o puntovector o tres param x,y,z
	void escala(float x, float y, float z);
	void rota(GLfloat grados, float x, float y, float z);
	void postMultiplica(GLfloat* m1);
	GLfloat* getM(){ return m; };

protected:
	GLfloat* m;
};

