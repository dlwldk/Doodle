
#ifndef _DRAWINGWIDGET_H
#define _DRAWINGWIDGET_H

#include <qwidget.h>
#include <QObject>
#include <QList>
#include <QStack>
#include "FigureMode/FigureModeType.h"
#include "Figure.h"

class FigureMode;
class Figure;
class Command;

class DrawingWidget : public QWidget {

	Q_OBJECT


public:
	DrawingWidget(QWidget *parent = nullptr);
	~DrawingWidget();

	void changeFigureMode(FigureModeType figureModeType);
	void changeCurrentColor(const QColor &color);

	FigureMode *figureMode;
	QStack <Command*> undostack;
	QStack <Command*> redostack;
	QList<Figure*> figures;
	QList<Figure*> selectedFigures;
	QList<Figure*> copiedFigures;
	QColor currentColor;
	int undoStackSize;
	int redoStackSize;

	void removeRedostack(Command *command);
	void undo();
	void redo();
	void alldelete();
    void cut();
	void copy();
	void paste();
	void copiedSelectedFigureCount();


protected:
	void mousePressEvent(QMouseEvent  *event);
	void mouseReleaseEvent(QMouseEvent  *event);
	void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent  *event);
	virtual void paintEvent(QPaintEvent *event);

	public slots:
	void write();
	void otherwrite();
	void read();
	void callCopiedFiguresCountEvent();

};

#endif //_DRAWINGWIDGET_H