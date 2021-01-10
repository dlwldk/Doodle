#include <Observer\UndoRedoStackCountChangedEvent.h>

UndoRedoStackCountChangedEvent::UndoRedoStackCountChangedEvent(int undoStackCount, int redoStackCount)
	:undoStackCount(undoStackCount), redoStackCount(redoStackCount) {


}
UndoRedoStackCountChangedEvent::~UndoRedoStackCountChangedEvent() {


}