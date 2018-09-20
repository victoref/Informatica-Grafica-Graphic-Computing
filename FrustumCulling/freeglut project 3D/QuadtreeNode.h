#pragma once
#include <list>
class Objeto3D;
class Escena;

class QuadtreeNode
{
public:
	QuadtreeNode(float x, float z, float s, Escena* esc);
	virtual ~QuadtreeNode();

	int numberTreeIntersect();
	void addIntersectingTreeToList();
	void build();
	void drawTrees(float x1, float z1, float x2, float z2, float x3, float z3, float x4, float z4);
	bool checkCollision(float x1, float z1, float s1, float x2, float z2, float s2);

private:
	int SWCornerX;
	int SWCornerZ;
	double size;
	int numA;
	std::list<Objeto3D*> TreeList;
	Objeto3D** arboles;
	QuadtreeNode* SWChild;
	QuadtreeNode* NWChild;
	QuadtreeNode* NEChild;
	QuadtreeNode* SEChild;
	Escena* escena;
};

