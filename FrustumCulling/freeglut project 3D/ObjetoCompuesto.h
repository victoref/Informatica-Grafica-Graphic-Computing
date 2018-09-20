#pragma once
#include "Objeto3D.h"

class ObjetoCompuesto : public Objeto3D
{
public:
	ObjetoCompuesto();
	~ObjetoCompuesto();
	void dibuja();
	void introduceObjeto(Objeto3D* o);
	Objeto3D** getHijo(){ return hijo; };
	bool visible = true;
protected:
	Objeto3D** hijo;
	int numHijos;
	int i = 0;
};

