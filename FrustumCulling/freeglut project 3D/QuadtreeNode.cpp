#include "QuadtreeNode.h"
#include "Escena.h"

QuadtreeNode::QuadtreeNode(float x, float z, float s, Escena* esc)
{
	SWCornerX = x;
	SWCornerZ = z;
	size = s;
	escena = esc;
	

	SWChild = nullptr;
	NWChild = nullptr;
	NEChild = nullptr;
	SEChild = nullptr;
}


QuadtreeNode::~QuadtreeNode()
{
}

int QuadtreeNode::numberTreeIntersect(){
	GLfloat x, z;
	int numVal = 0;
	numA = escena->getNumAr();
	arboles = escena->getHijo();
	for (int i = 1; i <= numA; i++){
		x = arboles[i]->getmT()->getM()[12];
		z = arboles[i]->getmT()->getM()[14];
		if (x >= SWCornerX && x <= SWCornerX + size
			&& z <= SWCornerZ && z >= SWCornerZ - size)
			numVal++;

	}
	return numVal;
}

void QuadtreeNode::addIntersectingTreeToList(){
	GLfloat x, z;
	numA = escena->getNumAr();
	arboles = escena->getHijo();
	for (int i = 1; i <= numA; i++){
		x = arboles[i]->getmT()->getM()[12];
		z = arboles[i]->getmT()->getM()[14];
		if (x >= SWCornerX && x <= SWCornerX + size
			&& z <= SWCornerZ && z >= SWCornerZ - size)
			TreeList.push_back(arboles[i]);

	}
}

void QuadtreeNode::build()
{
	if (this->numberTreeIntersect() <= 15)
		this->addIntersectingTreeToList();
	else {
		SWChild = new QuadtreeNode(SWCornerX, SWCornerZ, size / 2.0, escena);
		NWChild = new QuadtreeNode(SWCornerX, SWCornerZ - size / 2.0,
			size / 2.0, escena);
		NEChild = new QuadtreeNode(SWCornerX + size / 2.0, SWCornerZ - size / 2.0
			, size / 2.0, escena);
		SEChild = new QuadtreeNode(SWCornerX + size / 2.0, SWCornerZ,
			size / 2.0, escena);
		SWChild->build();
		NWChild->build();
		NEChild->build();
		SEChild->build();
	}
}

void QuadtreeNode::drawTrees(float x1, float z1, float x2, float z2, float x3,
	float z3, float x4, float z4){
	if (checkCollision(SWCornerX, SWCornerZ, size, x4, z4, std::abs(x1 - x2))) {
		if (SWChild == nullptr) { // El nodo es hoja
			std::list<Objeto3D*>::iterator TreeListIterator;
			TreeListIterator = TreeList.begin();
			// Dibujar los asteroides de asteroidList.
			while (TreeListIterator != TreeList.end()) {
				(*TreeListIterator)->dibuja();
				TreeListIterator++;
			}
		}
		else {
			SWChild->drawTrees(x1, z1, x2, z2, x3, z3, x4, z4);
			NWChild->drawTrees(x1, z1, x2, z2, x3, z3, x4, z4);
			NEChild->drawTrees(x1, z1, x2, z2, x3, z3, x4, z4);
			SEChild->drawTrees(x1, z1, x2, z2, x3, z3, x4, z4);
		}
	}
}

bool QuadtreeNode::checkCollision(float x1, float z1, float s1, float x2, float z2, float s2){
	return !(x1 + s1 < x2 || x1 > x2 + s2 || z1 - s1 > z2 || z1 < z2 - s2);
}