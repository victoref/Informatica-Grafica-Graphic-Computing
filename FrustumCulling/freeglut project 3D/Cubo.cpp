#include "Cubo.h"


Cubo::Cubo(int longitud, color cc)
{
	nLados = 4;
	nPoligonos = 2;

	numeroVertices = nLados * nPoligonos;
	numeroNormales = numeroVertices;
	numeroCaras = 6;
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	c = cc;

	//cubo normal quitar cuatros, doses y unos
	vertice[0] = new PuntoVector3D( 0, 0, 0, 1 );
	vertice[1] = new PuntoVector3D(0, longitud + 2, 0, 1);
	vertice[2] = new PuntoVector3D(0, longitud + 2, longitud + 2, 1);
	vertice[3] = new PuntoVector3D(0, 0, longitud + 2, 1);
	vertice[4] = new PuntoVector3D(longitud + 4, 1, 1, 1);
	vertice[5] = new PuntoVector3D(longitud + 4, longitud + 1, 1, 1);
	vertice[6] = new PuntoVector3D(longitud + 4, longitud + 1, longitud + 1, 1);
	vertice[7] = new PuntoVector3D(longitud + 4, 1, longitud + 1, 1);

	VerticeNormal** vn = new VerticeNormal*[4];
	vn[0] = new VerticeNormal(0, 0); ///fondo iz
	vn[1] = new VerticeNormal(1, 0);
	vn[2] = new VerticeNormal(2, 0);
	vn[3] = new VerticeNormal(3, 0);
	cara[0] = new Cara(4, vn);

	VerticeNormal** vn1 = new VerticeNormal*[4];
	vn1[0] = new VerticeNormal(4, 1); //frente dr
	vn1[1] = new VerticeNormal(5, 1);
	vn1[2] = new VerticeNormal(6, 1);
	vn1[3] = new VerticeNormal(7, 1);
	cara[1] = new Cara(4, vn1);

	VerticeNormal** vn2 = new VerticeNormal*[4];
	vn2[0] = new VerticeNormal(6, 2); //tapa
	vn2[1] = new VerticeNormal(5, 2);
	vn2[2] = new VerticeNormal(1, 2);
	vn2[3] = new VerticeNormal(2, 2);
	cara[2] = new Cara(4, vn2);

	VerticeNormal** vn3 = new VerticeNormal*[4];
	vn3[0] = new VerticeNormal(6, 3); //frente iz
	vn3[1] = new VerticeNormal(2, 3);
	vn3[2] = new VerticeNormal(3, 3);
	vn3[3] = new VerticeNormal(7, 3);
	cara[3] = new Cara(4, vn3);

	VerticeNormal** vn4 = new VerticeNormal*[4];
	vn4[0] = new VerticeNormal(3, 4); //suelo
	vn4[1] = new VerticeNormal(0, 4);
	vn4[2] = new VerticeNormal(4, 4);
	vn4[3] = new VerticeNormal(7, 4);
	cara[4] = new Cara(4, vn4);

	VerticeNormal** vn5 = new VerticeNormal*[4];
	vn5[0] = new VerticeNormal(0, 5); //fondo dr
	vn5[1] = new VerticeNormal(1, 5);
	vn5[2] = new VerticeNormal(5, 5);
	vn5[3] = new VerticeNormal(4, 5);
	cara[5] = new Cara(4, vn5);

	normal[0] = new PuntoVector3D(-1, 0, 0, 0);
	normal[1] = new PuntoVector3D(1, 0, 0, 0);
	normal[2] = new PuntoVector3D(0, 1, 0, 0);
	normal[3] = new PuntoVector3D(0, 0, 1, 0);
	normal[4] = new PuntoVector3D(0, -1, 0, 0);
	normal[5] = new PuntoVector3D(0, 0, -1, 0);


}


Cubo::~Cubo()
{

}
