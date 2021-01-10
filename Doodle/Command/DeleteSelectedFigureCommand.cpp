
#include "DeleteSelectedFigureCommand.h"

DeleteSelectedFigureCommand::DeleteSelectedFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> &deletedFigures)
	:drawingWidget(drawingWidget), deletedFigures(deletedFigures) {
	
}
#include <qdebug.h>
void DeleteSelectedFigureCommand::redo() {
	
	if (this->deletedFigures.size() > 0) {
		
		for (int i = 0; i < this->deletedFigures.size(); i++) {
		
			for (int j = 0; j < drawingWidget->figures.size(); j++) {
				if (this->deletedFigures.at(i) == drawingWidget->figures.at(j)) {                
					drawingWidget->figures.takeAt(j);
					break;
					
				}
			}
		}
		drawingWidget->update();
	}
}

void DeleteSelectedFigureCommand::undo() {

	if (this->deletedFigures.size() > 0) {
		for (int i = 0; i < this->deletedFigures.size(); i++) {
			drawingWidget->figures.append(this->deletedFigures.at(i));
		}
		drawingWidget->update();
	}
}

DeleteSelectedFigureCommand::~DeleteSelectedFigureCommand() {



}




