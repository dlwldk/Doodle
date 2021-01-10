#pragma once

#ifndef FIGUREMODE_H
#define FIGUREMODE_H


class DrawingWidget;
class QMouseEvent;
class QKeyEvent;

class FigureMode {

protected:
	
	DrawingWidget *drawingWidget;
	

public:
	FigureMode(DrawingWidget *drawingWidget);
	virtual void mousePressEvent(QMouseEvent  *event) = 0;
	virtual void mouseReleaseEvent(QMouseEvent  *event) = 0;
	virtual void mouseMoveEvent(QMouseEvent *event) {}
	virtual void keyPressEvent(QKeyEvent *event) {}
	virtual ~FigureMode() = 0;
	

public:
	
};

#endif // FIGUREMODE_H

