#pragma once
#include "Objeto3D.h"
#include "ObjetoCompuesto.h"
#include "ObjetoCuadrico.h"
#include "Cilindro.h"
#include "Disco.h"
#include "DiscoParcial.h"
#include "Esfera.h"
#include "Cubo.h"

class Coche : public ObjetoCompuesto
{
public:
	Coche();
	~Coche();
private:
	Cubo* chasis;
	ObjetoCompuesto* ruedaTI;
	ObjetoCompuesto* ruedaTD;
	ObjetoCompuesto* ruedaDI;
	ObjetoCompuesto* ruedaDD;
	Cilindro* neumaticoTI;
	Disco* llantaTI;
	Cilindro* neumaticoTD;
	Disco* llantaTD;
	Cilindro* neumaticoDI;
	Disco* llantaDI;
	Cilindro* neumaticoDD;
	Disco* llantaDD;
	Cilindro* faroIZ;
	Cilindro* faroDR;
	color cRuedas;
	color cChasis;
	color cFaros;
};

