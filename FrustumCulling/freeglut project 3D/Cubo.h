#pragma once
#include  "Malla.h"

class Cubo : public Malla
{
public:
	Cubo(int radio, color c);
	~Cubo();

private:
	int nLados;
	int nPoligonos;

};

