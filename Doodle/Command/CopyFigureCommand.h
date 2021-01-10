#ifndef COPYFIGURECOMMAND_H
#define COPYFIGURECOMMAND_H

#include "Command.h"
#include "./Ui/DrawingWidget.h"

class Figure;

class CopyFigureCommand : public Command {

public:
	CopyFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> &copiedFigures);
	virtual void redo();
	virtual void undo();
	~CopyFigureCommand();


private:
	DrawingWidget* drawingWidget;
	QList<Figure*> copiedFigures;

};
#endif // COPYFIGURECOMMAND_H