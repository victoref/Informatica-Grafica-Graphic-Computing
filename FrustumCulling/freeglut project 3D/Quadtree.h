#pragma once
#include "QuadtreeNode.h"

class Quadtree
{
public:

	Quadtree();

	virtual ~Quadtree();

	void initialize(float x, float z, float s, Escena *esc);

	void drawArboles(float x1, float z1, float x2, float z2,
		float x3, float z3, float x4, float z4);

private:

	QuadtreeNode* header;

};