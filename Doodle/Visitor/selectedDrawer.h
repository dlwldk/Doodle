
#ifndef SELECTEDDRAWER_H
#define SELECTEDDRAWER_H



#include "Visitor.h"

class QPainter;

class selectedDrawer : public Visitor {


private:
	QPainter *painter;

public:
	selectedDrawer(QPainter *painter);

	virtual void Visit(Line *line);
	virtual void Visit(Circle *circle);
	virtual void Visit(Polygon *polygon);
	virtual void Visit(Rectangle *rectangle);
	virtual void Visit(Triangle *triangle);
	virtual void Visit(Rhombus *rhombus);
	virtual void Visit(Parallelogram *parallogram);
	virtual ~selectedDrawer();

private:

};

#endif // SELECTEDDRAWER_H

