#pragma once

#ifndef CURSORMODE_H
#define CURSORMODE_H

#include "FigureMode.h"
#include "doodle.h"

class CursorMode : public FigureMode {

public:
	CursorMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event);
	virtual void mouseReleaseEvent(QMouseEvent  *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);
	virtual ~CursorMode();
	void copy();
	void cut();
	void paste();


private:
	int startX = -1;
	int startY = -1;
	int previousX = -1;
	int previousY= -1;
	int currentX = -1;
	int currentY = -1;
	
	QMouseEvent *e;
	bool readyToMove;
	
};

#endif // CURSORMODE_H

