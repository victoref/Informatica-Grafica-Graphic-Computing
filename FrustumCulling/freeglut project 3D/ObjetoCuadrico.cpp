#include "ObjetoCuadrico.h"


ObjetoCuadrico::ObjetoCuadrico()
{
	o = gluNewQuadric();
}


ObjetoCuadrico::~ObjetoCuadrico()
{
	gluDeleteQuadric(o);

}

