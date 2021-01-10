
#include "ParallelogramMode.h"
#include <QMouseEvent>
#include "Command/AddFigureCommand.h"

ParallelogramMode::ParallelogramMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

void ParallelogramMode::mousePressEvent(QMouseEvent  *event) {
	if (event->button() == Qt::LeftButton) {
		this->firstPointX = event->x();
		this->firstPointY = event->y();
	}
}

void ParallelogramMode::mouseReleaseEvent(QMouseEvent  *event) {

	
	if (event->button() == Qt::LeftButton) {
		this->secondPointX = event->x();
		this->secondPointY = event->y();
	}

	if (this->firstPointX != this->secondPointX && this->firstPointY != this->secondPointY) {
		parallelogram = new Parallelogram(this->firstPointX, this->firstPointY, this->secondPointX, this->secondPointY, this->drawingWidget->currentColor);
		this->drawingWidget->figures.append(parallelogram);
		this->drawingWidget->removeRedostack(new AddFigureCommand(this->drawingWidget, parallelogram));
		this->drawingWidget->update();
	}
	
}

ParallelogramMode::~ParallelogramMode() {

}




