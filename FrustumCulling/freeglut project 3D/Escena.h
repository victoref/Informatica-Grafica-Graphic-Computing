#pragma once
#include "ObjetoCompuesto.h"
#include "Arbol.h"
#include "Cubo.h"
#include "ObjetoCuadrico.h"
#include "Coche.h"
#include "Quadtree.h"
#include <iostream>


class Escena : public ObjetoCompuesto
{

public:
	Escena(float x, float z);
	~Escena();

	int getTamCopa() { return _tamCopa = 1 + rand() % 2; };
	int getTipoCopa() { return _tipoCopa = rand() % 4; };
	int getAltura() { return _altura = 3 + rand() % 4; };
	bool canMove(){ return stopMov; };
	int getNumAr(){ return numArboles; };
	void dibuja(float x1, float z1, float x2, float z2,
		float x3, float z3, float x4, float z4);


	void creaArbol(int i, int j); 
	void rellenaMatriz(); 
	void colision();
	bool frustum;


private:
	Coche* coche;
	Arbol* aux;
	int _tamCopa, _tipoCopa, _altura;
	int numArboles = 0;
	int cont;
	bool stopMov = false;
	float c;
	float f;

	Quadtree* quadtree;
};

