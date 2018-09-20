#pragma once
#include "ObjetoCompuesto.h"
class Copa: public ObjetoCompuesto
{
public:
	Copa(int tipo, GLdouble altura, GLdouble tam);
	~Copa();
};

