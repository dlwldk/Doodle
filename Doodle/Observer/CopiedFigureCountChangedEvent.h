#ifndef COPIEDFIGURECOUNTCHANGEDEVENT_H
#define COPIEDFIGURECOUNTCHANGEDEVENT_H

#include <Observer\NotifyEvent.h>


class CopiedFigureCountChangedEvent : public NotifyEvent {

public:
	CopiedFigureCountChangedEvent(int selectedFigureCount, int copiedFigureCount);
	~CopiedFigureCountChangedEvent();


private:

	int selectedFigureCount = 0;
	int copiedFigureCount = 0;


public:
	int getSelectedFigureCount() { return this->selectedFigureCount; }
	int getCopiedFigureCount() { return this->copiedFigureCount; }
};

#endif // COPIEDFIGURECOUNTCHANGEDEVENT_H
