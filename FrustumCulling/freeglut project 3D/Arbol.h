#pragma once
#include "Objeto3D.h"
#include "ObjetoCompuesto.h"
#include "Esfera.h"
#include "Cilindro.h"
#include "Copa.h"
class Arbol: public ObjetoCompuesto
{
public:
	Arbol(int tipoCopa, GLdouble altura, GLdouble tamCopa);
	~Arbol();

private:

	Copa* copaEsf;
	Copa* copaEsf2;
	Copa* copaCon;
	Copa* copaCon2;
	Cilindro* cilindro;	
};

