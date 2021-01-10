#pragma once

#ifndef REMOVEALLFIGUREMODECOMMAND_H
#define REMOVEALLFIGUREMODECOMMAND_H

#include "Command.h"
#include <qlist.h>
#include "Ui/DrawingWidget.h"

//class DrawingWidget;
class Figure;

class RemoveAllFigureCommand : public Command {

public:
	RemoveAllFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> removefigures);
	virtual void redo();
	virtual void undo();
	
	~RemoveAllFigureCommand();

private:
	DrawingWidget* drawingWidget;
	QList <Figure*> removefigures;
	

};

#endif // REMOVEALLFIGUREMODECOMMAND_H
