
#include "Drawer.h"
#include "Line.h"
#include "Circle.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Parallelogram.h"

#include <qpainter.h>

Drawer::Drawer(QPainter *painter)
	:painter(painter) {


}

void Drawer::Visit(Line *line) {

	painter->setPen(line->getcolor());
	painter->drawLine(line->getStartX(), line->getStartY(), line->getEndX(), line->getEndY());
}

void Drawer::Visit(Circle *circle) {
	painter->setPen(circle->getcolor());
	painter->drawEllipse(circle->getCenterX() - circle->getRadius(), circle->getCenterY() - circle->getRadius(), circle->getRadius() * 2, circle->getRadius() * 2);
}

void Drawer::Visit(Polygon *polygon) {
	painter->setPen(polygon->getcolor());
	QPainterPath path;
	QList<QPoint> points = polygon->getPoints();
	path.moveTo(points.at(0));
	for (int j = 1; j < points.size(); j++) {
		path.lineTo(points.at(j));
	}
	path.lineTo(points.at(0));
	painter->drawPath(path);
}

void Drawer::Visit(Rectangle *rectangle) {
	painter->setPen(rectangle->getcolor());
	painter->drawRect(rectangle->gettopLeftX(), rectangle->gettopLeftY(), rectangle->getWidth(), rectangle->getHeight());
}

void Drawer::Visit(Triangle *triangle) {
	painter->setPen(triangle->getcolor());
	QPainterPath path;
	path.moveTo(triangle->gettopLeftX(), triangle->gettopLeftY() + triangle->getHeight());
	path.lineTo(triangle->getbottomRightX(), triangle->getbottomRightY());
	path.lineTo(triangle->getbottomRightX() - (triangle->getWidth() / 2), triangle->gettopLeftY());
	path.lineTo(triangle->gettopLeftX(), triangle->gettopLeftY() + triangle->getHeight());
	painter->drawPath(path);
}

void Drawer::Visit(Rhombus *rhombus) {
	painter->setPen(rhombus->getcolor());
	QPainterPath path;
	path.moveTo(rhombus->gettopLeftX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2));
	path.lineTo(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->getbottomRightY());
	path.lineTo(rhombus->getbottomRightX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2));
	path.lineTo(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->gettopLeftY());
	path.lineTo(rhombus->gettopLeftX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2));

	painter->drawPath(path);
}
void Drawer::Visit(Parallelogram *parallelogram) {
	painter->setPen(parallelogram->getcolor());
	QPainterPath path;
	path.moveTo(parallelogram->gettopLeftX(), parallelogram->gettopLeftY());
	path.lineTo(parallelogram->gettopLeftX() + parallelogram->getWidth() / 3, parallelogram->getbottomRightY());
	path.lineTo(parallelogram->getbottomRightX(), parallelogram->getbottomRightY());
	path.lineTo(parallelogram->gettopLeftX() + (2 * parallelogram->getWidth() / 3), parallelogram->gettopLeftY());
	path.lineTo(parallelogram->gettopLeftX(), parallelogram->gettopLeftY());

	painter->drawPath(path);
}



Drawer::~Drawer() {

}