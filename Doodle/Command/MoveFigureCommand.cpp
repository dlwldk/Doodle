
#include "MoveFigureCommand.h"
#include "./Visitor/Mover.h"
#include <qlist.h>
#include "./Figure.h"

MoveFigureCommand::MoveFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> &selectedFigures, int disX, int disY)
	:drawingWidget(drawingWidget), disX(disX), disY(disY) {

	/*for (int i = 0; i < selectedFigures.size(); i++) {
		Figure* tmp = selectedFigures.at(i);
		//const_cast<QPoint&>(point).setY(y);
		this->movedFigures.append(tmp);
	
	}*/
	this->movedFigures = selectedFigures;

}

void MoveFigureCommand::redo() {

	Mover mover(this->disX, this->disY);
	for (int i = 0; i < this->movedFigures.size(); i++) {

		this->movedFigures.at(i)->Accept(&mover);

	}
	
	this->drawingWidget->update();

}

void MoveFigureCommand::undo() {

	Mover mover(-this->disX, -this->disY);
	for (int i = 0; i < this->movedFigures.size(); i++) {
		
		this->movedFigures.at(i)->Accept(&mover);
		
	}
	
	this->drawingWidget->update();

}

MoveFigureCommand::~MoveFigureCommand() {

}





