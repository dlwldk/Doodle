#include "TriangleMode.h"
#include <QMouseEvent>
#include "Command/AddFigureCommand.h"


TriangleMode::TriangleMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

void TriangleMode::mousePressEvent(QMouseEvent  *event) {
	if (event->button() == Qt::LeftButton) {
		this->firstPointX = event->x();
		this->firstPointY = event->y();
	}
}

void TriangleMode::mouseReleaseEvent(QMouseEvent  *event) {

	
	if (event->button() == Qt::LeftButton) {
		this->secondPointX = event->x();
		this->secondPointY = event->y();
	}

	if (this->firstPointX != this->secondPointX && this->firstPointY != this->secondPointY) {
		triangle = new Triangle(this->firstPointX, this->firstPointY, this->secondPointX, this->secondPointY, this->drawingWidget->currentColor);
		this->drawingWidget->figures.append(triangle);
		this->drawingWidget->removeRedostack(new AddFigureCommand(this->drawingWidget, triangle));
		this->drawingWidget->update();
	}

	

}

TriangleMode::~TriangleMode() {

}




