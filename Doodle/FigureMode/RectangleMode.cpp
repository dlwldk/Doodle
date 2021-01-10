
#include "RectangleMode.h"
#include <QMouseEvent>
#include "Command/AddFigureCommand.h"

RectangleMode::RectangleMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

void RectangleMode::mousePressEvent(QMouseEvent  *event) {
	if (event->button() == Qt::LeftButton) {
		this->firstPointX = event->x();
		this->firstPointY = event->y();
	}
}

void RectangleMode::mouseReleaseEvent(QMouseEvent  *event) {

	
	if (event->button() == Qt::LeftButton) {
		this->secondPointX = event->x(); 
		this->secondPointY = event->y();
	} 

	if (this->firstPointX != this->secondPointX && this->firstPointY != this->secondPointY) {
		rectangle = new Rectangle(this->firstPointX, this->firstPointY, this->secondPointX, this->secondPointY, this->drawingWidget->currentColor);
		this->drawingWidget->figures.append(rectangle);
		this->drawingWidget->removeRedostack(new AddFigureCommand(this->drawingWidget, rectangle));
		this->drawingWidget->update();
	}
	
}

RectangleMode::~RectangleMode() {

}




