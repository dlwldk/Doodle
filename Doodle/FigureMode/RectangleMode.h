#pragma once

#ifndef RECTANGLEMODE_H
#define RECTANGLEMODE_H

#include "FigureMode.h"
#include "Rectangle.h"

class RectangleMode : public FigureMode {

public:
	RectangleMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual ~RectangleMode();

private:
	int firstPointX = -1;
	int firstPointY = -1;
	int secondPointX = -1;
	int secondPointY = -1;
	Rectangle* rectangle;

};

#endif // RECTANGLEMODE_H

