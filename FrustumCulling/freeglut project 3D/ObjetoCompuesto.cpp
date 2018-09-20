#include "ObjetoCompuesto.h"
#include "Arbol.h"


ObjetoCompuesto::ObjetoCompuesto()
{
	numHijos = 10000;
	hijo = new Objeto3D* [numHijos]; ///declaracion de arrays dinamicos
}


ObjetoCompuesto::~ObjetoCompuesto()
{
}

void ObjetoCompuesto::dibuja(){
	if (visible){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glMultMatrixf(this->mT->getM());
		for (int j = 0; j < i; j++){
			hijo[j]->dibuja();
		}
		glPopMatrix();
	}

}

void ObjetoCompuesto::introduceObjeto(Objeto3D* o){
	hijo[i] = o;
	i++;
}
