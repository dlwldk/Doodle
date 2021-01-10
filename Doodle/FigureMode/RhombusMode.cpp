
#include "RhombusMode.h"
#include <QMouseEvent>
#include "Command/AddFigureCommand.h"

RhombusMode::RhombusMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

void RhombusMode::mousePressEvent(QMouseEvent  *event) {
	if (event->button() == Qt::LeftButton) {
		this->firstPointX = event->x();
		this->firstPointY = event->y();
	}
}

void RhombusMode::mouseReleaseEvent(QMouseEvent  *event) {

	
	if (event->button() == Qt::LeftButton) {
		this->secondPointX = event->x();
		this->secondPointY = event->y();
	}

	if (this->firstPointX != this->secondPointX && this->firstPointY != this->secondPointY) {
		rhombus = new Rhombus(this->firstPointX, this->firstPointY, this->secondPointX, this->secondPointY, this->drawingWidget->currentColor);
		this->drawingWidget->figures.append(rhombus);
		this->drawingWidget->removeRedostack(new AddFigureCommand(this->drawingWidget, rhombus));
		this->drawingWidget->update();
	}
	
}

RhombusMode::~RhombusMode() {

}




