#ifndef CURRENTCOLORCHANGEDEVENT_H
#define CURRENTCOLORCHANGEDEVENT_H

#include <Observer\NotifyEvent.h>
#include <qcolor.h>

class CurrentColorChangedEvent : public NotifyEvent {


private:
	QColor color;


public:
	CurrentColorChangedEvent(const QColor &color);
	~CurrentColorChangedEvent();


	const QColor& getColor() { return this->color; }


};

#endif // CURRENTCOLORCHANGEDEVENT_H
