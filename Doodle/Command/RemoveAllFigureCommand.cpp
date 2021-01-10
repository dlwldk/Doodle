
#include "RemoveAllFigureCommand.h"
#include <qmessagebox.h>

RemoveAllFigureCommand::RemoveAllFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> removefigures)
	:drawingWidget(drawingWidget), removefigures(removefigures) {

}

void RemoveAllFigureCommand::redo() {

	
	while (!this->drawingWidget->figures.isEmpty()) {
		Figure* tmp = this->drawingWidget->figures.takeFirst();
		this->removefigures.append(tmp);
	}
	
	this->drawingWidget->update();
	
}

void RemoveAllFigureCommand::undo() {

	
	while (!removefigures.isEmpty()) {
		Figure* tmp = removefigures.takeFirst();
		this->drawingWidget->figures.append(tmp);
		//int index = this->removefigures;
	}
	
	
	this->drawingWidget->update();
	
}

RemoveAllFigureCommand::~RemoveAllFigureCommand() {



}




