
#include "LineMode.h"
#include <QMouseEvent>
#include "Command/AddFigureCommand.h"


LineMode::LineMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

void LineMode::mousePressEvent(QMouseEvent  *event) {
	if (event->button() == Qt::LeftButton) {
		this->firstPointX = event->x();
		this->firstPointY = event->y();
	}
}

void LineMode::mouseReleaseEvent(QMouseEvent  *event) {

	
	if (event->button() == Qt::LeftButton) {
		this->secondPointX = event->x();
		this->secondPointY = event->y();
	}
		
	if (this->firstPointX != this->secondPointX && this->firstPointY != this->secondPointY) {
		line = new Line(this->firstPointX, this->firstPointY, this->secondPointX, this->secondPointY, this->drawingWidget->currentColor);
		this->drawingWidget->figures.append(line);
		this->drawingWidget->removeRedostack(new AddFigureCommand(this->drawingWidget, line));
		this->drawingWidget->update();
	}

	
	
}

LineMode::~LineMode() {

}




