#include "Copa.h"
#include "Esfera.h"
#include "Cilindro.h"
Copa::Copa(int tipo, GLdouble altura, GLdouble tam)
{
	if (tipo == 0){
		introduceObjeto(new Esfera(tam, 32, 32, { 0.1F, 0.35F, 0.15F }));
		hijo[0]->getmT()->traslada(0, altura, 0);
	}
	else if (tipo == 1){
		introduceObjeto(new Esfera(tam, 32, 32, { 0.1F, 0.35F, 0.15F }));
		introduceObjeto(new Esfera(tam + 0.25, 32, 32, { 0.1F, 0.35F, 0.15F }));
		hijo[0]->getmT()->traslada(-0.5, altura, -0.5);
		hijo[1]->getmT()->traslada(0.75, altura - 0.1, 0.75);
	}
	else if (tipo == 2){
		introduceObjeto(new Cilindro(tam, 0, altura, 32, 32, { 0.03F, 0.35F, 0.06F }));
		hijo[0]->getmT()->traslada(0, altura, 0);
		hijo[0]->getmT()->rota(-90, 1, 0, 0);
	}
	else if (tipo == 3){
		introduceObjeto(new Cilindro(tam, 0, altura, 32, 32, { 0.03F, 0.35F, 0.06F }));
		introduceObjeto(new Cilindro(tam, 0, altura, 32, 32, { 0.03F, 0.35F, 0.06F }));
		hijo[0]->getmT()->traslada(0, altura, 0);
		hijo[0]->getmT()->rota(-90, 1, 0, 0);
		hijo[1]->getmT()->traslada(0, altura + 1.5, 0);
		hijo[1]->getmT()->rota(-90, 1, 0, 0);
	}
}


Copa::~Copa()
{
	for (int j = 0; j < i; j++){
		hijo[j] = nullptr;
		delete hijo[j];
	}
}
