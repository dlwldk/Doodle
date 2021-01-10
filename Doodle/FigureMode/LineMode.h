#pragma once

#ifndef LINEMODE_H
#define LINEMODE_H

#include "FigureMode.h"
#include "Ui/DrawingWidget.h"
#include "Line.h"

class LineMode : public FigureMode {

public:
	LineMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual ~LineMode();

private:
	int firstPointX = -1;
	int firstPointY = -1;
	int secondPointX = -1;
	int secondPointY = -1;
	Line* line;

};

#endif // LINEMODE_H

