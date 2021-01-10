

#ifndef DRAWER_H
#define DRAWER_H



#include "Visitor.h"

class QPainter;

class Drawer : public Visitor {


private:
	QPainter *painter;

public:
	Drawer(QPainter *painter);

	virtual void Visit(Line *line);
	virtual void Visit(Circle *circle);
	virtual void Visit(Polygon *polygon);
	virtual void Visit(Rectangle *rectangle);
	virtual void Visit(Triangle *triangle);
	virtual void Visit(Rhombus *rhombus);
	virtual void Visit(Parallelogram *parallogram);
	virtual ~Drawer();

private:

};

#endif // DRAWER_H

