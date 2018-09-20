#include "Escena.h"
#include <math.h>
#include<time.h>
#include <iostream>

Escena::Escena(float x, float z)
{
	f = std::abs(x);
	c = std::abs(z);
	frustum = false;
	quadtree = new Quadtree();
	srand(time(NULL));
	coche = new Coche();
	introduceObjeto(coche);
	coche->getmT()->escala(0.5, 0.5, 0.5);
	
	rellenaMatriz();
	

	quadtree->initialize(x * 3, z * 3, std::abs(2*x)*3, this);
		
}


Escena::~Escena()
{
	for (int n = 0; n < i; n++) {
		hijo[n] = nullptr;
		delete hijo[n];
	}
}

void Escena::creaArbol(int i, int j){
	
	if (rand() % 2 == 1) {
		aux = new Arbol(getTipoCopa(), getAltura(), getTamCopa());
		introduceObjeto(aux);
		aux->getmT()->traslada(i * 3, 0, j * 3);
		numArboles++;
	}
}


void Escena::rellenaMatriz(){
	for (int i = -f; i < f; i++) {
		for (int j = -c; j < c; j++) {
	/*for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {*/
			if (i != 0 || j != 0){
				creaArbol(i, j);
			}
		}
	}
	cont = numArboles;

}

void Escena::colision(){
	float mod;
	for (int i = 1; i <= numArboles; i++){
		mod = std::sqrtf(std::powf((hijo[i]->getmT()->getM()[12] - coche->getmT()->getM()[12]), 2) +
			std::powf((hijo[i]->getmT()->getM()[14] - coche->getmT()->getM()[14]), 2));
		if (mod < 2 && static_cast<ObjetoCompuesto*>(hijo[i])->visible){
			 static_cast<ObjetoCompuesto*>(hijo[i])->visible = false;
			 cont--;
			 if (cont == 0){
				 stopMov = true;
			 }
		 }
	}
}

void Escena::dibuja(float x1, float z1, float x2, float z2,
	float x3, float z3, float x4, float z4){


	if (frustum){

		hijo[0]->dibuja();
		quadtree->drawArboles(x1, z1, x2, z2,
			x3, z3, x4, z4);

	}
	else
		ObjetoCompuesto::dibuja();

}
