
#include "CircleMode.h"
#include <QMouseEvent>
#include "Command/AddFigureCommand.h"

CircleMode::CircleMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

void CircleMode::mousePressEvent(QMouseEvent  *event) {
	if (event->button() == Qt::LeftButton) {
		this->firstPointX = event->x();
		this->firstPointY = event->y();
	}
}

void CircleMode::mouseReleaseEvent(QMouseEvent  *event) {

	
	if (event->button() == Qt::LeftButton) {
		this->secondPointX = event->x();
		this->secondPointY = event->y();
	}

	if (this->firstPointX != this->secondPointX && this->firstPointY != this->secondPointY) {
		int rad = sqrt(((this->secondPointX - this->firstPointX)*(this->secondPointX - this->firstPointX)) + ((this->secondPointY - this->firstPointY)*(this->secondPointY - this->firstPointY)));
		circle = new Circle(this->firstPointX, this->firstPointY, rad, this->drawingWidget->currentColor);
		this->drawingWidget->figures.append(circle);
		this->drawingWidget->removeRedostack(new AddFigureCommand(this->drawingWidget, circle));
		this->drawingWidget->update();
	}
	
}

CircleMode::~CircleMode() {

}




