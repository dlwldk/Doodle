
#include "CopyFigureCommand.h"

CopyFigureCommand::CopyFigureCommand(DrawingWidget *drawingWidget, QList<Figure*> &copiedFigures)
	:drawingWidget(drawingWidget), copiedFigures(copiedFigures) {

}

void CopyFigureCommand::redo() {
	if (this->copiedFigures.size() > 0) {
		for (int i = 0; i < this->copiedFigures.size(); i++) {
			drawingWidget->figures.append(this->copiedFigures.at(i));
		}

		drawingWidget->update();
	}
}

void CopyFigureCommand::undo() {

	if (this->copiedFigures.size() > 0) {
		
		for (int i = 0; i < this->copiedFigures.size(); i++) {
		
			for (int j = 0; j < drawingWidget->figures.size(); j++) {
				if (this->copiedFigures.at(i) == drawingWidget->figures.at(j)) {
					drawingWidget->figures.takeAt(j);
					break;
				}
			}
		}
		drawingWidget->update();
	}
}

CopyFigureCommand::~CopyFigureCommand() {



}




