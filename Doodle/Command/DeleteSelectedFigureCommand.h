#ifndef DELETESELECTEDFIGURECOMMAND_H
#define DELETESELECTEDFIGURECOMMAND_H

#include "Command.h"
#include "./Ui/DrawingWidget.h"

class Figure;

class DeleteSelectedFigureCommand : public Command {

public:
	DeleteSelectedFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> &deletedFigures);
	virtual void redo();
	virtual void undo();
	~DeleteSelectedFigureCommand();


private:
	DrawingWidget* drawingWidget;
	QList<Figure*> deletedFigures;
	QList<int> cutIndex;

};
#endif // DELETESELECTEDFIGURECOMMAND_H