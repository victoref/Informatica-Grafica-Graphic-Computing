#include "Coche.h"


Coche::Coche()
{
	cRuedas.r = 0.5f;
	cRuedas.g = 0.5F;
	cRuedas.b = 0.5F;

	cChasis.r = 0.88F;
	cChasis.g = 0.6F;
	cChasis.b = 0.2F;

	cFaros.r = 0.38F;
	cFaros.g = 0.6F;
	cFaros.r = 0.28F;

	chasis = new Cubo(2, cChasis);

	neumaticoTI = new Cilindro(1, 1, 1, 32, 32, cRuedas);
	llantaTI = new Disco(0.5, 1, 6, 1, cRuedas);
	neumaticoTD = new Cilindro(1, 1, 1, 32, 32, cRuedas);
	llantaTD = new Disco(0.5, 1, 6, 1, cRuedas);
	neumaticoDI = new Cilindro(1, 1, 1, 32, 32, cRuedas);
	llantaDI = new Disco(0.5, 1, 6, 1, cRuedas);
	neumaticoDD = new Cilindro(1, 1, 1, 32, 32, cRuedas);
	llantaDD = new Disco(0.5, 1, 6, 1, cRuedas);

	ruedaTI = new ObjetoCompuesto();
	ruedaTD = new ObjetoCompuesto();
	ruedaDD = new ObjetoCompuesto();
	ruedaDI = new ObjetoCompuesto();

	faroDR = new Cilindro(0.3, 0.3, 0.3, 32, 32, cFaros);
	faroIZ = new Cilindro(0.3, 0.3, 0.3, 32, 32, cFaros);


	ruedaTI->introduceObjeto(llantaTI);
	ruedaTI->introduceObjeto(neumaticoTI);
	ruedaTI->getmT()->traslada(-1, 0, -2.8);

	ruedaTD->introduceObjeto(llantaTD);
	ruedaTD->introduceObjeto(neumaticoTD);
	ruedaTD->getmT()->traslada(-1, 0, 1.8);
	ruedaTD->getHijo()[0]->getmT()->traslada(0, 0, 1);

	ruedaDD->introduceObjeto(llantaDD);
	ruedaDD->introduceObjeto(neumaticoDD);
	ruedaDD->getmT()->traslada(3, 0, 0.8);
	ruedaDD->getHijo()[0]->getmT()->traslada(0, 0, 1);


	ruedaDI->introduceObjeto(llantaDI);
	ruedaDI->introduceObjeto(neumaticoDI);
	ruedaDI->getmT()->traslada(3, 0, -1.8);

	introduceObjeto(ruedaTI);
	introduceObjeto(ruedaTD);
	introduceObjeto(ruedaDI);
	introduceObjeto(ruedaDD);
	introduceObjeto(faroDR);
	introduceObjeto(faroIZ);
	introduceObjeto(chasis);
	chasis->getmT()->rota(-10, 0, 0, 1);
	chasis->getmT()->traslada(-2, 0, -2);
	faroIZ->getmT()->traslada(4.2, 1, -0.8);
	faroIZ->getmT()->rota(90, 0, 1, 0);
	faroDR->getmT()->traslada(4.2, 1, 0.8);
	faroDR->getmT()->rota(90, 0, 1, 0);
	
}


Coche::~Coche()
{
	for (int j = 0; j < i; j++) {
		hijo[j] = nullptr;
		delete hijo[j];
	}
}
