#ifndef CHANGEFIGUREMODEREQUEST_H
#define CHANGEFIGUREMODEREQUEST_H

#include <Chain_Of_Responsibility/Request.h>

class ChangeFigureModeRequest : public Request {

public:
	enum ChangeFigureMode {
		ChangeLineMode,
		ChangeCircleMode,
		ChangePolygonMode,
		ChangeRectangleMode,
		ChangeTriangleMode,
		ChangeRhombusMode,
		ChangeParallelogramMode,
		ChangeCursorMode
	};
	ChangeFigureModeRequest(ChangeFigureMode changeFigureMode);
	~ChangeFigureModeRequest();
	ChangeFigureMode getChangeFigureMode() { return this->changeFigureMode; }

private:
	ChangeFigureMode changeFigureMode;
};

#endif // CHANGEFIGUREMODEREQUEST_H