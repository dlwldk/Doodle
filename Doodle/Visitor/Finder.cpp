
#include "Finder.h"
#include "Line.h"
#include "Circle.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Parallelogram.h"
#include "TestMath.h"
#include "selectedDrawer.h"
#include "./FigureMode/LineMode.h"
#include <qmessagebox.h>
#include <QMouseEvent>
#include <QDebug>


Finder::Finder(const QPoint &clickedPoint, bool &isExist)
	:clickedPoint(clickedPoint), isExist(isExist) {
	
}

Finder::~Finder() {

}

void Finder::Visit(Line *line) {

	this->isExist = math::checkPointLiesOnLine(this->clickedPoint, QPoint(line->getStartX(), line->getStartY()), QPoint(line->getEndX(), line->getEndY()), 5);
}

void Finder::Visit(Circle *circle) {

	this->isExist = math::checkPointLiesOnCircleBoundary(this->clickedPoint, QPoint(circle->getCenterX(), circle->getCenterY()), circle->getRadius(), 5);
}

void Finder::Visit(Polygon *polygon) {

	QList <QPoint> points = polygon->getPoints();
	for (int i = 1; i <= points.size(); i++) {
		
		if (i == points.size()) {
			this->isExist = math::checkPointLiesOnLine(this->clickedPoint, QPoint(points.at(i-1).x(), points.at(i-1).y()), QPoint(points.at(0).x(), points.at(0).y()), 5);
		}
		else {
			this->isExist = math::checkPointLiesOnLine(this->clickedPoint, QPoint(points.at(i-1).x(), points.at(i-1).y()), QPoint(points.at(i).x(), points.at(i).y()), 5);
		}
		
		if (this->isExist == true)
			return;
	}
}

void Finder::Visit(Rectangle *rectangle) {

	if (math::checkPointLiesOnLine(this->clickedPoint, QPoint(rectangle->gettopLeftX(), rectangle->gettopLeftY()), QPoint(rectangle->gettopLeftX(), rectangle->getbottomRightY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(rectangle->gettopLeftX(), rectangle->getbottomRightY()), QPoint(rectangle->getbottomRightX(), rectangle->getbottomRightY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(rectangle->getbottomRightX(), rectangle->getbottomRightY()), QPoint(rectangle->getbottomRightX(), rectangle->gettopLeftY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(rectangle->getbottomRightX(), rectangle->gettopLeftY()), QPoint(rectangle->gettopLeftX(), rectangle->gettopLeftY()), 5)) {
		
		this->isExist = true;
	}

	
}

void Finder::Visit(Triangle *triangle) {
	
	if ( math::checkPointLiesOnLine(this->clickedPoint, QPoint(triangle->gettopLeftX(), triangle->getbottomRightY()), QPoint(triangle->getbottomRightX(), triangle->getbottomRightY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(triangle->getbottomRightX(), triangle->getbottomRightY()), QPoint(triangle->gettopLeftX() + triangle->getWidth() / 2, triangle->gettopLeftY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(triangle->gettopLeftX() + triangle->getWidth() / 2, triangle->gettopLeftY()), QPoint(triangle->gettopLeftX(), triangle->getbottomRightY()), 5)) {
		
		this->isExist = true;
	}

	
}

void Finder::Visit(Rhombus *rhombus) {

	if (math::checkPointLiesOnLine(this->clickedPoint, QPoint(rhombus->gettopLeftX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2)), QPoint(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->getbottomRightY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->getbottomRightY()), QPoint(rhombus->getbottomRightX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2)), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(rhombus->getbottomRightX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2)), QPoint(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->gettopLeftY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(rhombus->gettopLeftX() + (rhombus->getWidth() / 2), rhombus->gettopLeftY()), QPoint(rhombus->gettopLeftX(), rhombus->gettopLeftY() + (rhombus->getHeight() / 2)), 5)) {
		
		this->isExist = true;
	}

	
}

void Finder::Visit(Parallelogram *parallelogram) {

	if (math::checkPointLiesOnLine(this->clickedPoint, QPoint(parallelogram->gettopLeftX(), parallelogram->gettopLeftY()), QPoint(parallelogram->gettopLeftX() + parallelogram->getWidth() / 3, parallelogram->getbottomRightY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(parallelogram->gettopLeftX() + parallelogram->getWidth() / 3, parallelogram->getbottomRightY()), QPoint(parallelogram->getbottomRightX(), parallelogram->getbottomRightY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(parallelogram->getbottomRightX(), parallelogram->getbottomRightY()), QPoint(parallelogram->gettopLeftX() + (2 * parallelogram->getWidth() / 3), parallelogram->gettopLeftY()), 5)
		|| math::checkPointLiesOnLine(this->clickedPoint, QPoint(parallelogram->gettopLeftX() + (2 * parallelogram->getWidth() / 3), parallelogram->gettopLeftY()), QPoint(parallelogram->gettopLeftX(), parallelogram->gettopLeftY()), 5)) {
		
		this->isExist = true;
	}

	
}


