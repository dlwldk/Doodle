#ifndef CHANGEFIGURECOMMANDREQUEST_H
#define CHANGEFIGURECOMMANDREQUEST_H

#include <Chain_Of_Responsibility/Request.h>

class ChangeFigureCommandRequest : public Request {


public:
	enum ChangeFigureCommand {
		ChangeUndoMode,
		ChangeRedoMode,
		ChangeAllEraseMode
	};
	ChangeFigureCommandRequest(ChangeFigureCommand changeFigureCommand);
	~ChangeFigureCommandRequest();
	ChangeFigureCommand getChangeFigureCommand() { return this->changeFigureCommand; }

private:
	ChangeFigureCommand changeFigureCommand;
};

#endif // CHANGEFIGURECOMMANDREQUEST_H