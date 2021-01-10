#include <Observer\CopiedFigureCountChangedEvent.h>

CopiedFigureCountChangedEvent::CopiedFigureCountChangedEvent(int selectedFigureCount, int copiedFigureCount)
	:selectedFigureCount(selectedFigureCount), copiedFigureCount(copiedFigureCount) {


}

CopiedFigureCountChangedEvent::~CopiedFigureCountChangedEvent() {


}