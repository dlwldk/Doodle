#pragma once

#ifndef RHOMBUSMODE_H
#define RHOMBUSMODE_H

#include "FigureMode.h"
#include "Rhombus.h"

class RhombusMode : public FigureMode {

public:
	RhombusMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual ~RhombusMode();

private:
	int firstPointX = -1;
	int firstPointY = -1;
	int secondPointX = -1;
	int secondPointY = -1;
	Rhombus* rhombus;

};

#endif // RHOMBUSMODE_H


