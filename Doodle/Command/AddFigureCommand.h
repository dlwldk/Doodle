#pragma once

#ifndef ADDFIGUREMODECOMMAND_H
#define ADDFIGUREMODECOMMAND_H

#include "Command.h"
#include "./Ui/DrawingWidget.h"

class Figure;

class AddFigureCommand : public Command {

public:
	AddFigureCommand(DrawingWidget *drawingWidget, Figure *figure);
	virtual void redo(); 
	virtual void undo();
	~AddFigureCommand();

private:
	DrawingWidget* drawingWidget;
	Figure* figure;

};

#endif // ADDFIGUREMODECOMMAND_H
