#pragma once

#ifndef VISITOR_H
#define VISITOR_H

class Line;
class Circle;
class Polygon;
class Rectangle;
class Triangle;
class Rhombus;
class Parallelogram;

class Visitor {

public:
	Visitor();
	virtual void Visit(Line *line) = 0;
	virtual void Visit(Circle *circle) = 0;
	virtual void Visit(Polygon *polygon) = 0;
	virtual void Visit(Rectangle *rectangle) = 0;
	virtual void Visit(Triangle *triangle) = 0;
	virtual void Visit(Rhombus *rhombus) = 0;
	virtual void Visit(Parallelogram *parallelogram) = 0;
	virtual ~Visitor() = 0;

protected:


public:

};

#endif // VISITOR_H

