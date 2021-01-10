#pragma once

#ifndef POLYGONMODE_H
#define POLYGONMODE_H

#include "FigureMode.h"
#include "Polygon.h"
#include <QList>

class PolygonMode : public FigureMode {

public:
	PolygonMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual ~PolygonMode();

private:
	QList<QPoint> pointList;
	QPoint p;
	Polygon* polygon;

};

#endif // POLYGONMODE_H

