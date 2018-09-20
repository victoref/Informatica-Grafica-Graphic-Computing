#pragma once
#include "TAfin.h"
#include "PuntoVector3D.h"

struct color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};


class Objeto3D
{
public:

	Objeto3D()
	{
		mT = new TAfin();
	}
	
	virtual ~Objeto3D()
	{
	}

	virtual void dibuja() = 0;
	TAfin* getmT(){ return mT; };

protected:
	TAfin* mT;
};

