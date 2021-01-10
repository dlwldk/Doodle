#ifndef FINDER_H
#define FINDER_H

#include "Visitor.h"
#include "doodle.h"
#include "./Ui/DrawingWidget.h"

class DrawingWidget;

class Finder : public Visitor {


private:
	QPoint clickedPoint;
	bool &isExist;
	Doodle *doodle;

public:
	Finder(const QPoint &clickedPoint, bool &isExist);
	virtual ~Finder();
	virtual void Visit(Line *line);
	virtual void Visit(Circle *circle);
	virtual void Visit(Polygon *polygon);
	virtual void Visit(Rectangle *rectangle);
	virtual void Visit(Triangle *triangle);
	virtual void Visit(Rhombus *rhombus);
	virtual void Visit(Parallelogram *parallelogram);
	DrawingWidget *drawingWidget;
	
	

};

#endif // FINDER_H

