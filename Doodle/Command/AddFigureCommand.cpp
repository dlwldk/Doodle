
#include "AddFigureCommand.h"

AddFigureCommand::AddFigureCommand(DrawingWidget *drawingWidget, Figure *figure)
	:drawingWidget(drawingWidget), figure(figure) {

}

void AddFigureCommand::redo() {

	this->drawingWidget->figures.append(this->figure); 
	this->drawingWidget->update();
}

void AddFigureCommand::undo() {

	int index = this->drawingWidget->figures.indexOf(this->figure);
	this->drawingWidget->figures.takeAt(index);
	this->drawingWidget->update();
}

AddFigureCommand::~AddFigureCommand() {


	
}




