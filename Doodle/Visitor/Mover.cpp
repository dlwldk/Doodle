
#include "Mover.h"
#include "Line.h"
#include "Circle.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Parallelogram.h"
#include <qmessagebox.h>
#include <qdebug.h>


Mover::Mover(int disX, int disY)
	: disX(disX), disY(disY) {


}

void Mover::Visit(Line *line) {
	
	line->setStartX(line->getStartX() + disX);
	line->setStartY(line->getStartY() + disY);
	line->setEndX(line->getEndX() + disX);
	line->setEndY(line->getEndY() + disY);
		
}

void Mover::Visit(Circle *circle) {
	circle->setCenterX(circle->getCenterX() + disX);
	circle->setCenterY(circle->getCenterY() + disY);

}


void Mover::Visit(Polygon *polygon) {
	
	
	for (int i = 0; i < polygon->squareNum(); i++) {
		
		polygon->setPoint(i, polygon->getPoint(i).x() + disX, polygon->getPoint(i).y() + disY);
		
	}
}

void Mover::Visit(Rectangle *rectangle) {
	
	rectangle->settopLeftX(rectangle->gettopLeftX() + disX);
	rectangle->settopLeftY(rectangle->gettopLeftY() + disY);
	rectangle->setbottomRightX(rectangle->getbottomRightX() + disX);
	rectangle->setbottomRightY(rectangle->getbottomRightY() + disY);
}

void Mover::Visit(Triangle *triangle) {

	triangle->settopLeftX(triangle->gettopLeftX() + disX);
	triangle->settopLeftY(triangle->gettopLeftY() + disY);
	triangle->setbottomRightX(triangle->getbottomRightX() + disX);
	triangle->setbottomRightY(triangle->getbottomRightY() + disY);
}

void Mover::Visit(Rhombus *rhombus) {
	rhombus->settopLeftX(rhombus->gettopLeftX() + disX);
	rhombus->settopLeftY(rhombus->gettopLeftY() + disY);
	rhombus->setbottomRightX(rhombus->getbottomRightX() + disX);
	rhombus->setbottomRightY(rhombus->getbottomRightY() + disY);
}
void Mover::Visit(Parallelogram *parallelogram) {
	
	parallelogram->settopLeftX(parallelogram->gettopLeftX() + disX);
	parallelogram->settopLeftY(parallelogram->gettopLeftY() + disY);
	parallelogram->setbottomRightX(parallelogram->getbottomRightX() + disX);
	parallelogram->setbottomRightY(parallelogram->getbottomRightY() + disY);
}



Mover::~Mover() {

}