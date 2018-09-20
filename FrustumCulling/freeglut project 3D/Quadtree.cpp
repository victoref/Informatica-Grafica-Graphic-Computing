#include "Quadtree.h"


Quadtree::Quadtree()
{
}


Quadtree::~Quadtree()
{
}

void Quadtree::initialize(float x, float z, float s, Escena *esc) {

	header = new QuadtreeNode(x, z, s, esc);
	header->build();

}

void Quadtree::drawArboles(float x1, float z1, float x2, float z2,
	float x3, float z3, float x4, float z4) {

	header->drawTrees(x1, z1, x2, z2, x3, z3, x4, z4);
}