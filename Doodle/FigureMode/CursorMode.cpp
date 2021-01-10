#include "CursorMode.h"
#include "./Visitor/Finder.h"
#include "./Visitor/Mover.h"
#include "Command/MoveFigureCommand.h"
#include "Command/CopyFigureCommand.h"
#include "Command/DeleteSelectedFigureCommand.h"
#include "Observer/CopiedFigureCountChangedEvent.h"
#include "Observer/ChangeManager.h"
#include <QMouseEvent>
#include "doodle.h"
#include "Figure.h"
#include <qwidget.h>
#include <qdebug.h>
#include <qmessagebox.h>


CursorMode::CursorMode(DrawingWidget *drawingWidget)
	:FigureMode(drawingWidget) {

}

#include <qmessagebox.h>
void CursorMode::mousePressEvent(QMouseEvent  *event) {
	
	QPoint p;
	if (event->button() == Qt::LeftButton) {
		p.setX(event->x());
		p.setY(event->y());
	}

	bool isExist = false;
	bool isSelected;
	readyToMove = false;
	Finder finder(p, isExist);
	Figure *figure;
	
	if (event->button() == Qt::LeftButton && event->modifiers() == Qt::ShiftModifier) {
		for (int i = 0; i < drawingWidget->figures.size(); i++) {
			isExist = false;
			isSelected = false;
			drawingWidget->figures.at(i)->Accept(&finder);

			if (isExist == true) { //객체가 존재할 때
				figure = drawingWidget->figures.at(i);
				break;
			}
		}
		if (isExist == true) {
			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
				if (figure == drawingWidget->selectedFigures.at(i)) {
					isSelected = true;
					break;
				}

			}
			if (isSelected == true) { //객체가 이미 선택된 상태일 때
				int index = drawingWidget->selectedFigures.indexOf(figure);
				drawingWidget->selectedFigures.takeAt(index);
				drawingWidget->update();
			}
		}
	}
	else if (event->button() == Qt::LeftButton && event->modifiers() == Qt::ControlModifier) {
		for (int i = 0; i < drawingWidget->figures.size(); i++) {
			isExist = false;
			isSelected = false;
			readyToMove = false;
			drawingWidget->figures.at(i)->Accept(&finder);

			if (isExist == true) { //객체가 존재할 때
				figure = drawingWidget->figures.at(i);
				break;
			}
		}
		if (isExist == true) {
			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
				if (figure == drawingWidget->selectedFigures.at(i)) { //객체가 이미 선택된 상태일 때
					isSelected = true;
					break;
				}

			}
			if (isSelected == true) {
				this->startX = event->x();
				this->startY = event->y();
				this->previousX = event->x();
				this->previousY = event->y();
				readyToMove = true;
			}
		}
	}
	else if (event->button() == Qt::LeftButton) {
		for (int i = 0; i < drawingWidget->figures.size(); i++) {
			isExist = false;
			isSelected = false;
			readyToMove = false;
			drawingWidget->figures.at(i)->Accept(&finder);

			if (isExist == true) { //객체가 존재할 때
				figure = drawingWidget->figures.at(i);
				break;
			}
		}
		if (isExist == true) {
			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
				if (figure == drawingWidget->selectedFigures.at(i)) { //객체가 이미 선택된 상태일 때
					isSelected = true;
					break;
				}
			}
			if (isSelected == false) {
				drawingWidget->selectedFigures.append(figure);
				drawingWidget->update();
			}
		}
	}

	drawingWidget->copiedSelectedFigureCount();
	
}

void CursorMode::mouseMoveEvent(QMouseEvent *event) {
	
	
	if (this->readyToMove == true) {
		
		int disX = event->x() - this->previousX;
		int disY = event->y() - this->previousY;

		Mover mover(disX, disY);
		for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
		
			drawingWidget->selectedFigures.at(i)->Accept(&mover); 

		}
		
		drawingWidget->update();
		this->previousX = event->x();
		this->previousY = event->y();
		
	}
}

void CursorMode::mouseReleaseEvent(QMouseEvent *event) {
	
	if (this->readyToMove == true) {

		drawingWidget->removeRedostack(new MoveFigureCommand(this->drawingWidget, drawingWidget->selectedFigures, event->x() - this->startX, event->y() - this->startY));
		
	}
	this->readyToMove = false;
}

void CursorMode::keyPressEvent(QKeyEvent *event) {
	
	/*복사*/
	if (event->matches(QKeySequence::Copy)) { 
		if (drawingWidget->selectedFigures.size() > 0) { //선택된 객체가 존재할 때
			while (!drawingWidget->copiedFigures.isEmpty())
				delete drawingWidget->copiedFigures.takeFirst();
		
			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
			
				Figure *figure = drawingWidget->selectedFigures.at(i)->Clone();
				drawingWidget->copiedFigures.append(figure);
			
			}
			drawingWidget->copiedSelectedFigureCount();
		}
		
	}

	/*잘라내기*/
	else if (event->matches(QKeySequence::Cut)) {
		
		if (drawingWidget->selectedFigures.size() > 0) { //선택된 객체가 존재할 때
		
			while (!drawingWidget->copiedFigures.isEmpty())
				delete drawingWidget->copiedFigures.takeFirst();
			

			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {

				Figure *figure = drawingWidget->selectedFigures.at(i)->Clone();
				drawingWidget->copiedFigures.append(figure);
				
			}

			QList<Figure*> tmpFigures;
			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
				tmpFigures.append(drawingWidget->selectedFigures.at(i));
			}
		
			drawingWidget->removeRedostack(new DeleteSelectedFigureCommand(drawingWidget, tmpFigures));

			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
				for (int j = 0; j < drawingWidget->figures.size(); j++) {
					if (drawingWidget->selectedFigures.at(i) == drawingWidget->figures.at(j)) {
						drawingWidget->figures.removeAt(j);
					}
				}
			}
			drawingWidget->selectedFigures.clear();
			drawingWidget->copiedSelectedFigureCount();
			drawingWidget->update();
			
		}
	}

	/*지우기*/
	else if (event->matches(QKeySequence::Delete)) {

		if (drawingWidget->selectedFigures.size() > 0) {
		
			QList<Figure*> tmpFigures;
			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
			
				tmpFigures.append(drawingWidget->selectedFigures.at(i));
				
			}

			drawingWidget->removeRedostack(new DeleteSelectedFigureCommand(this->drawingWidget, tmpFigures));
			
			for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
				for (int j = 0; j < drawingWidget->figures.size(); j++) {
					if (drawingWidget->selectedFigures.at(i) == drawingWidget->figures.at(j)) {
						drawingWidget->figures.removeAt(j);
					}
				}
			}
			
			drawingWidget->selectedFigures.clear();
			drawingWidget->copiedSelectedFigureCount();
			drawingWidget->update();
		}
	}

	/*붙여넣기*/
	else if (event->matches(QKeySequence::Paste)) {
		if (drawingWidget->copiedFigures.size() > 0) {
			Mover mover(drawingWidget->mapFromGlobal(QCursor::pos()).x(), drawingWidget->mapFromGlobal(QCursor::pos()).y());
			QList<Figure*> tmp;
			for (int i = 0; i < drawingWidget->copiedFigures.size(); i++) {
		
				Figure *figure = drawingWidget->copiedFigures.at(i)->Clone();
				figure->Accept(&mover);
				drawingWidget->figures.append(figure);
				tmp.append(figure);
			}
			
			drawingWidget->removeRedostack(new CopyFigureCommand(this->drawingWidget, tmp));
			drawingWidget->copiedSelectedFigureCount();
			drawingWidget->update();
		}
	}
}

void CursorMode::cut() {

	if (drawingWidget->selectedFigures.size() > 0) { //선택된 객체가 존재할 때

		while (!drawingWidget->copiedFigures.isEmpty())
			delete drawingWidget->copiedFigures.takeFirst();


		for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {

			Figure *figure = drawingWidget->selectedFigures.at(i)->Clone();
			drawingWidget->copiedFigures.append(figure);

		}

		QList<Figure*> tmpFigures;
		for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
			tmpFigures.append(drawingWidget->selectedFigures.at(i));
		}

		drawingWidget->removeRedostack(new DeleteSelectedFigureCommand(drawingWidget, tmpFigures));

		for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {
			for (int j = 0; j < drawingWidget->figures.size(); j++) {
				if (drawingWidget->selectedFigures.at(i) == drawingWidget->figures.at(j)) {
					drawingWidget->figures.removeAt(j);
				}
			}
		}
		drawingWidget->selectedFigures.clear();
		drawingWidget->copiedSelectedFigureCount();
		drawingWidget->update();

	}

}

void CursorMode::copy() {

	if (drawingWidget->selectedFigures.size() > 0) { //선택된 객체가 존재할 때
		while (!drawingWidget->copiedFigures.isEmpty())
			delete drawingWidget->copiedFigures.takeFirst();

		for (int i = 0; i < drawingWidget->selectedFigures.size(); i++) {

			Figure *figure = drawingWidget->selectedFigures.at(i)->Clone();
			drawingWidget->copiedFigures.append(figure);

		}
		drawingWidget->copiedSelectedFigureCount();
	}

}

void CursorMode::paste() {

	if (drawingWidget->copiedFigures.size() > 0) {
		Mover mover(drawingWidget->mapFromGlobal(QCursor::pos()).x(), drawingWidget->mapFromGlobal(QCursor::pos()).y());
		QList<Figure*> tmp;
		for (int i = 0; i < drawingWidget->copiedFigures.size(); i++) {

			Figure *figure = drawingWidget->copiedFigures.at(i)->Clone();
			figure->Accept(&mover);
			drawingWidget->figures.append(figure);
			tmp.append(figure);
		}

		drawingWidget->removeRedostack(new CopyFigureCommand(this->drawingWidget, tmp));
		drawingWidget->copiedSelectedFigureCount();
		drawingWidget->update();
	}

}

CursorMode::~CursorMode() {

}




