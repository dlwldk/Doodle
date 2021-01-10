#ifndef CHANGEFIGURECOLORREQUEST_H
#define CHANGEFIGURECOLORREQUEST_H

#include <Chain_Of_Responsibility/Request.h>
#include <QColor>

class ChangeFigureColorRequest : public Request {

public:
	ChangeFigureColorRequest(const QColor &color);
	~ChangeFigureColorRequest();
	const QColor& getColor() { return this->color; }

private:
	QColor color;

public:
	

};

#endif // CHANGEFIGURECOLORREQUEST_H