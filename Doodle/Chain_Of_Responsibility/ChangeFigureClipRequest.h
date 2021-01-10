#ifndef CHANGEFIGURECLIPREQUEST_H
#define CHANGEFIGURECLIPREQUEST_H

#include <Chain_Of_Responsibility/Request.h>

class ChangeFigureClipRequest : public Request {

public:
	enum ChangeFigureClip {
		ChangeCutMode,
		ChangeCopyMode,
		ChangePasteMode
	};

	ChangeFigureClipRequest(ChangeFigureClip changeFigureClip);
	~ChangeFigureClipRequest();
	ChangeFigureClip getChangeFigureClip() { return this->changeFigureClip; }


private:
	ChangeFigureClip changeFigureClip;
};

#endif // CHANGEFIGURECLIPREQUEST_H
