
#include "PolygonMode.h"
#include <QMouseEvent>
#include "Command/AddFigureCommand.h"


PolygonMode::PolygonMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

void PolygonMode::mousePressEvent(QMouseEvent  *event) {

	
	if (event->button() == Qt::LeftButton) {
		p.setX(event->x());
		p.setY(event->y());
		pointList.append(p);
	}

	else if (event->button() == Qt::RightButton) {
		polygon = new Polygon(pointList, this->drawingWidget->currentColor);
		this->drawingWidget->figures.append(polygon);
		this->drawingWidget->removeRedostack(new AddFigureCommand(this->drawingWidget, polygon));
		this->drawingWidget->update();
		pointList.clear();
	}
	
}

void PolygonMode::mouseReleaseEvent(QMouseEvent  *event) {

}

PolygonMode::~PolygonMode() {

}




