
#include "selectedDrawer.h"
#include "Line.h"
#include "Circle.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Parallelogram.h"

#include <qpainter.h>

selectedDrawer::selectedDrawer(QPainter *painter)
	:painter(painter) {


}

void selectedDrawer::Visit(Line *line) {

	painter->setPen(QPen(Qt::black, 2, Qt::DotLine));
	painter->drawLine(line->getStartX(), line->getStartY(), line->getEndX(), line->getEndY());
}

void selectedDrawer::Visit(Circle *circle) {

	painter->setPen(QPen(Qt::black, 2, Qt::DotLine));
	painter->drawEllipse(circle->getCenterX() - circle->getRadius(), circle->getCenterY() - circle->getRadius(), circle->getRadius() * 2, circle->getRadius() * 2);
}

void selectedDrawer::Visit(Polygon *polygon) {
	painter->setPen(QPen(Qt::black, 2, Qt::DotLine));
	QPainterPath path;
	QList<QPoint> points = polygon->getPoints();
	path.moveTo(points.at(0));
	for (int j = 1; j < points.size(); j++) {
		path.lineTo(points.at(j));
	}
	path.lineTo(points.at(0));
	painter->drawPath(path);
}

void selectedDrawer::Visit(Rectangle *rectangle) {
	painter->setPen(QPen(Qt::black, 2, Qt::DotLine));
	painter->drawRect(rectangle->gettopLeftX(), rectangle->gettopLeftY(), rectangle->getWidth(), rectangle->getHeight());
}

void selectedDrawer::Visit(Triangle *triangle) {
	painter->setPen(QPen(Qt::black, 2, Qt::DotLine));
	QPainterPath path;
	path.moveTo(triangle->gettopLeftX(), triangle->gettopLeftY() + triangle->getHeight());
	path.lineTo(triangle->getbottomRightX(), triangle->getbottomRightY());
	path.lineTo(triangle->getbottomRightX() - (triangle->getWidth() / 2), triangle->gettopLeftY());
	path.lineTo(triangle->gettopLeftX(), triangle->gettopLeftY() + triangle->getHeight());
	painter->drawPath(path);
}

void selectedDrawer::Visit(Rhombus *rhombus) {
	painter->setPen(QPen(Qt::black, 2, Qt::DotLine));
	QPainterPath path;
	path.moveTo(rhombus->gettopLeftX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2));
	path.lineTo(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->getbottomRightY());
	path.lineTo(rhombus->getbottomRightX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2));
	path.lineTo(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->gettopLeftY());
	path.lineTo(rhombus->gettopLeftX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2));

	painter->drawPath(path);
}
void selectedDrawer::Visit(Parallelogram *parallelogram) {
	painter->setPen(QPen(Qt::black, 2, Qt::DotLine));
	QPainterPath path;
	path.moveTo(parallelogram->gettopLeftX(), parallelogram->gettopLeftY());
	path.lineTo(parallelogram->gettopLeftX() + parallelogram->getWidth() / 3, parallelogram->getbottomRightY());
	path.lineTo(parallelogram->getbottomRightX(), parallelogram->getbottomRightY());
	path.lineTo(parallelogram->gettopLeftX() + (2 * parallelogram->getWidth() / 3), parallelogram->gettopLeftY());
	path.lineTo(parallelogram->gettopLeftX(), parallelogram->gettopLeftY());

	painter->drawPath(path);
}



selectedDrawer::~selectedDrawer() {

}