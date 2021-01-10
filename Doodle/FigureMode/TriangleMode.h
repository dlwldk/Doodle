#ifndef TRIANGLEMODE_H
#define TRIANGLEMODE_H

#include "FigureMode.h"
#include "Triangle.h"

class TriangleMode : public FigureMode {

public:
	TriangleMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual ~TriangleMode();

private:
	int firstPointX = -1;
	int firstPointY = -1;
	int secondPointX = -1;
	int secondPointY = -1;
	Triangle* triangle;

};

#endif // TRIANGLEMODE_H


