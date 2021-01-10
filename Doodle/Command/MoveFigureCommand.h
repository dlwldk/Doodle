#ifndef MOVEFIGURECOMMAND_H
#define MOVEFIGURECOMMAND_H

#include "Command.h"
#include "./Ui/DrawingWidget.h"


class Figure;

class MoveFigureCommand : public Command {

public:
	MoveFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> &selectedFigure, int disX, int disY);
	virtual void redo();
	virtual void undo();
	~MoveFigureCommand();
	

private:
	DrawingWidget* drawingWidget;
	QList<Figure*> movedFigures;
	Figure* figure;
	int disX;
	int disY;
};

#endif // MOVEFIGURECOMMAND_H
