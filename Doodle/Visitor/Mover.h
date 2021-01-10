#ifndef MOVER_H
#define MOVER_H



#include "Visitor.h"

class Mover : public Visitor {


private:
	
	int disX;
	int disY;

public:
	Mover(int disX, int disY);

	virtual void Visit(Line *line);
	virtual void Visit(Circle *circle);
	virtual void Visit(Polygon *polygon);
	virtual void Visit(Rectangle *rectangle);
	virtual void Visit(Triangle *triangle);
	virtual void Visit(Rhombus *rhombus);
	virtual void Visit(Parallelogram *parallogram);
	virtual ~Mover();


};

#endif // MOVER_H

