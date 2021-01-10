#pragma once

#ifndef PARALLELOGRAMMODE_H
#define PARALLELOGRAMMODE_H

#include "FigureMode.h"
#include "Parallelogram.h"

class ParallelogramMode : public FigureMode {

public:
	ParallelogramMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual ~ParallelogramMode();

private:
	int firstPointX = -1;
	int firstPointY = -1;
	int secondPointX = -1;
	int secondPointY = -1;
	Parallelogram* parallelogram;

};

#endif // PARALLELOGRAMMODE_H


