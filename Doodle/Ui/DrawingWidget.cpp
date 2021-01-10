

#include "DrawingWidget.h"
#include <qpainter.h>
#include <QKeyEvent>
#include "FigureMode/LineMode.h"
#include "FigureMode/CircleMode.h"
#include "FigureMode/PolygonMode.h"
#include "FigureMode/RectangleMode.h"
#include "FigureMode/TriangleMode.h"
#include "FigureMode/RhombusMode.h"
#include "FigureMode/ParallelogramMode.h"
#include "FigureMode/CursorMode.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <qmessagebox.h>


//#include "FigureMode/FigureModeType.h"

#include "Command\RemoveAllFigureCommand.h"
#include "Command\DeleteSelectedFigureCommand.h"
#include "Command\CopyFigureCommand.h"
#include "./Visitor/Mover.h"
#include "Observer/ChangeManager.h"
#include "Observer/CurrentColorChangedEvent.h"
#include "Observer/FigureModeChangedEvent.h"
#include "Observer/UndoRedoStackCountChangedEvent.h"
#include "Observer/CopiedFigureCountChangedEvent.h"

DrawingWidget::DrawingWidget(QWidget *parent)
	:QWidget(parent), figureMode(nullptr) {

	this->changeFigureMode(FigureModeType::CursorModeType);
	this->changeCurrentColor(QColor(255, 0, 0));

	this->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
	this->setMouseTracking(true);

	

	UndoRedoStackCountChangedEvent event(this->undostack.count(), this->redostack.count());
	CopiedFigureCountChangedEvent event2(this->selectedFigures.size(), this->copiedFigures.size());
	
	ChangeManager::getInstance()->update(&event);
	ChangeManager::getInstance()->update(&event2);

}

void DrawingWidget::changeFigureMode(FigureModeType figureModeType) {

	if (this->figureMode != nullptr) {
		delete this->figureMode;
		this->selectedFigures.clear(); 
		this->update();
	}
	
	if (figureModeType == LineModeType) {
		this->figureMode = new LineMode(this);
	}
	else if (figureModeType == CircleModeType) {
		this->figureMode = new CircleMode(this);
	}
	else if (figureModeType == PolygonModeType) {
		this->figureMode = new PolygonMode(this);
	}
	else if (figureModeType == RectangleModeType) {
		this->figureMode = new RectangleMode(this);
	}
	else if (figureModeType == TriangleModeType) {
		this->figureMode = new TriangleMode(this);
	}
	else if (figureModeType == RhombusModeType) {
		this->figureMode = new RhombusMode(this);
	}
	else if (figureModeType == ParallelogramModeType) {
		this->figureMode = new ParallelogramMode(this);
	}
	else if (figureModeType == CursorModeType) {
		this->figureMode = new CursorMode(this);
	}

	FigureModeChangedEvent event(figureModeType);
	ChangeManager::getInstance()->update(&event);
	this->copiedSelectedFigureCount();
	
}


void DrawingWidget::changeCurrentColor(const QColor &color) {

	this->currentColor = color;

	CurrentColorChangedEvent event(color);
	ChangeManager::getInstance()->update(&event);

}

void DrawingWidget::alldelete() {

	if (this->figures.size() == 0)
		return;

	this->selectedFigures.clear();

	Command* command = new RemoveAllFigureCommand(this, figures);
	this->removeRedostack(command);

	this->figures.clear();

	this->update();
	this->undoStackSize = this->undostack.size();
	this->redoStackSize = this->redostack.size();

	UndoRedoStackCountChangedEvent event(this->undoStackSize, this->redoStackSize);
	ChangeManager::getInstance()->update(&event);
	this->copiedSelectedFigureCount();

}

void DrawingWidget::undo() {
	
	if (this->undostack.size() > 0) {

		this->selectedFigures.clear();
		Command* command = undostack.pop();
		command->undo();
		redostack.push(command);

	}

	this->undoStackSize = this->undostack.size();
	this->redoStackSize = this->redostack.size();
	
	UndoRedoStackCountChangedEvent event(this->undoStackSize, this->redoStackSize);
	ChangeManager::getInstance()->update(&event);
	this->copiedSelectedFigureCount();

}

void DrawingWidget::redo() {
	
	if (this->redostack.size() > 0) {
		
		this->selectedFigures.clear();
		Command* command = redostack.pop();
		command->redo();
		undostack.push(command);
		
	}
	
	this->undoStackSize = this->undostack.size();
	this->redoStackSize = this->redostack.size();

	UndoRedoStackCountChangedEvent event(this->undoStackSize, this->redoStackSize);
	ChangeManager::getInstance()->update(&event);
	this->copiedSelectedFigureCount();
}

void DrawingWidget::cut() {

	if (dynamic_cast<CursorMode*>(this->figureMode)) {
		dynamic_cast<CursorMode*>(this->figureMode)->cut();
	}

}

void DrawingWidget::copy() {
	
	if (dynamic_cast<CursorMode*>(this->figureMode)) {
		dynamic_cast<CursorMode*>(this->figureMode)->copy();
	}
		
}

void DrawingWidget::paste() {
	
	if (dynamic_cast<CursorMode*>(this->figureMode)) {
		dynamic_cast<CursorMode*>(this->figureMode)->paste();
	}
}

void DrawingWidget::copiedSelectedFigureCount() {

	CopiedFigureCountChangedEvent event(this->selectedFigures.size(), this->copiedFigures.size());
	ChangeManager::getInstance()->update(&event);

}

void DrawingWidget::removeRedostack(Command *command) {
	
	this->undostack.append(command);
	if (this->redostack.size() != 0) {
		while (!this->redostack.isEmpty()) {
			delete this->redostack.pop();
		}
	}

	this->undoStackSize = this->undostack.size();
	this->redoStackSize = this->redostack.size();
	UndoRedoStackCountChangedEvent event(this->undoStackSize, this->redoStackSize);

	ChangeManager::getInstance()->update(&event);
}

DrawingWidget::~DrawingWidget() {

	if (this->figureMode != nullptr)
		delete this->figureMode;

	while (!figures.isEmpty()) //리스트 초기화
		delete figures.takeFirst();
}


void DrawingWidget::callCopiedFiguresCountEvent() {

	CopiedFigureCountChangedEvent changeEvent(this->selectedFigures.size(), this->copiedFigures.size());
	ChangeManager::getInstance()->update(&changeEvent);

}

void DrawingWidget::write() {

	QString filename;

	if (this->windowTitle() == QString::fromLocal8Bit("제목 없음")) {

	filename = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("파일 저장하기"), QString::fromLocal8Bit("%1.txt").arg(this->windowTitle()), tr("*.txt"));

	if (filename.isEmpty())
		return;
	}
	else {
		filename = this->windowTitle();
	}
	QFile file(filename);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		qDebug() << "Not Open file";
		return;
	}
	QTextStream data(&file);

	for (int i = 0; i < this->figures.size(); i++) {
		data << this->figures.at(i)->getString();
	}

	file.close();
	this->undoStackSize = this->undostack.size();
	this->redoStackSize = this->redostack.size();

	this->setWindowTitle(filename);

}

void DrawingWidget::otherwrite() {

	
	QString filename = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("파일 저장하기"), QString::fromLocal8Bit("%1.txt").arg(this->windowTitle()), tr("*.txt"));

	if (filename.isEmpty())
		return;
	QFile file(filename);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
		qDebug() << "Not Open file";
		return;
	}
	QTextStream data(&file);

	for (int i = 0; i < figures.size(); i++) {
		data << figures.at(i)->getString();
	}

	file.close();
	this->undoStackSize = this->undostack.size();
	this->redoStackSize = this->redostack.size();

	this->setWindowTitle(filename);

}
#include <qabstractbutton.h>
void DrawingWidget::read() {

	
	QString dir = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("열기"), QDir::currentPath(), tr("*.txt"));

	QFile file(dir);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Not Open File";
		return;
	}

	if (this->undoStackSize != this->undostack.size()  || this->redoStackSize != this->redostack.size() ) {
		QMessageBox *box = new QMessageBox("DrawingWidget", QString::fromLocal8Bit("변경 내용을 %1에 저장하시겠습니까?").arg(this->windowTitle()), QMessageBox::NoIcon, QMessageBox::Save, QMessageBox::Discard, QMessageBox::Cancel);
		box->button(QMessageBox::Save)->setText(QString::fromLocal8Bit("저장(S)"));
		box->button(QMessageBox::Discard)->setText(QString::fromLocal8Bit("저장 안 함(N)"));
		box->button(QMessageBox::Cancel)->setText(QString::fromLocal8Bit("취소"));

		int ret = box->exec();

		if (ret == QMessageBox::Save) {
			this->write();
		}

		while (!figures.isEmpty())
			delete figures.takeFirst();
		while (!this->redostack.isEmpty())
			delete this->redostack.pop();

		while (!this->undostack.isEmpty())
			delete this->undostack.pop();

		//this->updateUndoRedoButton();
		//toolBarCommandWidget->updateUndoRedoButton();

		this->update();
	}

	QTextStream in(&file);
	QStringList fields, data;
	QString str, first;

	while (!in.atEnd()) {

		str = in.readLine();
		fields = str.split(' ');
		first = fields.value(0).toInt();

		if (first == 1) {
			Line* line = new Line(fields.value(1).toInt(), fields.value(2).toInt(), fields.value(3).toInt(), fields.value(4).toInt(), QColor(fields.value(5).toInt(), fields.value(6).toInt(), fields.value(7).toInt()));
			this->figures.append(line);

		}
		else if (first == 2) {
			Circle* circle = new Circle(fields.value(1).toInt(), fields.value(2).toInt(), fields.value(3).toInt(), QColor(fields.value(4).toInt(), fields.value(5).toInt(), fields.value(6).toInt()));
			this->figures.append(circle);

		}
		else if (first == 3) {
			QList<QPoint> points;
			int add = 0;
			for (int j = 0; j < fields.value(4).toInt(); j++) {
				QPoint p;
				p.setX(fields.value(5 + add).toInt());
				p.setY(fields.value(6 + add).toInt());
				points.append(p);
				add += 2;
			}
			Polygon* polygon = new Polygon(points, QColor(fields.value(1).toInt(), fields.value(2).toInt(), fields.value(3).toInt()));
			this->figures.append(polygon);
		}
		else if (first == 4) {
			Rectangle* rectangle= new Rectangle(fields.value(1).toInt(), fields.value(2).toInt(), fields.value(3).toInt(), fields.value(4).toInt(), QColor(fields.value(5).toInt(), fields.value(6).toInt(), fields.value(7).toInt()));
			this->figures.append(rectangle);

		}
		else if (first == 5) {
			Triangle* triangle = new Triangle(fields.value(1).toInt(), fields.value(2).toInt(), fields.value(3).toInt(), fields.value(4).toInt(), QColor(fields.value(5).toInt(), fields.value(6).toInt(), fields.value(7).toInt()));
			this->figures.append(triangle);

		}
		else if (first == 6) {
			Rhombus* rhombus = new Rhombus(fields.value(1).toInt(), fields.value(2).toInt(), fields.value(3).toInt(), fields.value(4).toInt(), QColor(fields.value(5).toInt(), fields.value(6).toInt(), fields.value(7).toInt()));
			this->figures.append(rhombus);
		}
		else if (first == 7) {
			Parallelogram* parallelogram = new Parallelogram(fields.value(1).toInt(), fields.value(2).toInt(), fields.value(3).toInt(), fields.value(4).toInt(), QColor(fields.value(5).toInt(), fields.value(6).toInt(), fields.value(7).toInt()));
			this->figures.append(parallelogram);
		}
	}

	this->undoStackSize = 0;
	this->redoStackSize = 0;


	this->setWindowTitle(dir);
	this->update();

}
void DrawingWidget::mousePressEvent(QMouseEvent  *event) {

	if (this->figureMode == nullptr)
		return;

	this->figureMode->mousePressEvent(event);
	
}

void DrawingWidget::mouseReleaseEvent(QMouseEvent  *event) {

	
	if (this->figureMode == nullptr)
		return;

	this->figureMode->mouseReleaseEvent(event);

}

void DrawingWidget::mouseMoveEvent(QMouseEvent *event) {


	if (this->figureMode != nullptr) {
		if (hasFocus() == false)
			setFocus();
		this->figureMode->mouseMoveEvent(event);
	}

}

void DrawingWidget::keyPressEvent(QKeyEvent *event) {

	
	if (event->matches(QKeySequence::Undo)) {
		undo();
	}
	else if (event->matches(QKeySequence::Redo)) {
		redo();
	}
	
	else if (event->key() == (Qt::Key_Escape)) {
		/*while (!selectedFigures.isEmpty())
			selectedFigures.takeFirst();*/

		this->selectedFigures.clear();
		this->update();
	}
	else if (event->matches(QKeySequence::Copy)) {
		if (this->figureMode != nullptr)
			this->figureMode->keyPressEvent(event);
	}
	else if (event->matches(QKeySequence::Paste)) {
		if (this->figureMode != nullptr)
			this->figureMode->keyPressEvent(event);
	}
	else if (event->matches(QKeySequence::Delete)) {
		if (this->figureMode != nullptr)
			this->figureMode->keyPressEvent(event);
	}
	else if (event->matches(QKeySequence::Cut)) {
		if (this->figureMode != nullptr)
			this->figureMode->keyPressEvent(event);
	}
	
	
}
#include "Visitor\Drawer.h"
#include "Visitor\selectedDrawer.h"

void DrawingWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	
	Drawer drawer(&painter);
	selectedDrawer selectedDrawer(&painter);

	
	for (int i = 0; i < this->figures.size(); i++) {
		this->figures.at(i)->Accept(&drawer);
		
	}

	for (int i = 0; i < this->selectedFigures.size(); i++) {

		this->selectedFigures.at(i)->Accept(&selectedDrawer);

	}
	
	
}