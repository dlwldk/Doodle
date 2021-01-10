
#ifndef LINE_H
#define LINE_H
#include "Figure.h"
#include "Visitor/Visitor.h"


class Line : public Figure {
	
private:
	int startX; //������ X��ǥ
	int startY; //������ Y��ǥ
	int endX; //���� X��ǥ
	int endY; //���� Y��ǥ

public:
	Line();
	Line(int startX, int startY, int endX, int endY, QColor color);
	Line(const Line& line) {

		this->startX = line.startX;
		this->startY = line.startY;
		this->endX = line.endX;
		this->endY = line.endY;
		this->color = line.color;

	}
	Line* Clone() {
		return new Line(*this);
	}
	~Line(); 
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	void setStartX(int startX);
	void setStartY(int startY);
	void setEndX(int endX);
	void setEndY(int endY);
	virtual QString getString();
	virtual void Accept(Visitor *visitor);
};

#endif // LINE_H
