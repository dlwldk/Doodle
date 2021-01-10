#pragma once

#ifndef CIRCLEMODE_H
#define CIRCLEMODE_H

#include "FigureMode.h"
#include "doodle.h"
#include "Circle.h"

class CircleMode : public FigureMode {

public:
	CircleMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual ~CircleMode();

private:
	int firstPointX = -1;
	int firstPointY = -1;
	int secondPointX = -1;
	int secondPointY = -1;
	Circle* circle;
	QMouseEvent *event;

};

#endif // CIRCLEMODE_H
