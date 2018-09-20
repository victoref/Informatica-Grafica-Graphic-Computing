#include "Arbol.h"


Arbol::Arbol(int tipoCopa, GLdouble altura, GLdouble tamCopa)
{

	//esf = new Esfera(tamCopa, 32, 32, { 0.1F, 0.35F, 0.15F });
	//esf2 = new Esfera(tamCopa + 0.25, 32, 32, { 0.1F, 0.35F, 0.15F });
	//cono = new Cilindro(tamCopa, 0, altura, 32, 32, { 0.03F, 0.35F, 0.06F });
	//cono2 = new Cilindro(tamCopa, 0, altura, 32, 32, { 0.03F, 0.35F, 0.06F });
	copaEsf = new Copa(0, altura, tamCopa);
	copaEsf2 = new Copa(1, altura, tamCopa + 0.25);
	copaCon = new Copa(2, altura, tamCopa);
	copaCon2 = new Copa(3, altura, tamCopa);
	cilindro = new Cilindro(1, 0.5, altura, 32, 32, { 0.32F, 0.21F, 0.05F }); //tallo

	if (tipoCopa == 0){
		introduceObjeto(copaEsf);
		introduceObjeto(cilindro);
		hijo[1]->getmT()->rota(-90, 1, 0, 0);
	}
	else if (tipoCopa == 1){
		introduceObjeto(copaEsf2);
		introduceObjeto(cilindro);
		hijo[1]->getmT()->rota(-90, 1, 0, 0);
	}
	else if (tipoCopa == 2){
		introduceObjeto(copaCon);
		introduceObjeto(cilindro);
		
		hijo[1]->getmT()->rota(-90, 1, 0, 0);
	}
	else if (tipoCopa == 3){
		introduceObjeto(copaCon2);
		introduceObjeto(cilindro);
		hijo[1]->getmT()->rota(-90, 1, 0, 0);
	}
}


Arbol::~Arbol()
{
	for (int j = 0; j < i; j++){
		hijo[j] = nullptr;
		delete hijo[j];
	}
}
