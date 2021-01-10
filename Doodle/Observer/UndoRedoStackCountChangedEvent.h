#ifndef UNDOREDOSTACKCOUNTCHANGEDEVENT_H
#define UNDOREDOSTACKCOUNTCHANGEDEVENT_H

#include <Observer\NotifyEvent.h>


class UndoRedoStackCountChangedEvent : public NotifyEvent {

public:
	UndoRedoStackCountChangedEvent(int undoStackCount, int redoStackCount);
	~UndoRedoStackCountChangedEvent();
	

private:
	
	int undoStackCount = 0;
	int redoStackCount = 0;


public:
	int getUndoStackCount() { return this->undoStackCount; }
	int getRedoStackCount() { return this->redoStackCount; }
};

#endif // UNDOREDOSTACKCOUNTCHANGEDEVENT_H
