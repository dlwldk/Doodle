#ifndef FIGUREMODECHANGEDEVENT_H
#define FIGUREMODECHANGEDEVENT_H

#include <Observer\NotifyEvent.h>
#include <FigureMode\FigureModeType.h>

class FigureModeChangedEvent : public NotifyEvent {

public:
	FigureModeChangedEvent(FigureModeType figureModeType);
	~FigureModeChangedEvent();
	FigureModeType getFigureModeType() { return this->figureModeType; }

private:
	FigureModeType figureModeType;
};

#endif // FIGUREMODECHANGEDEVENT_H
