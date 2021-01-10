
#ifndef _OBSERVER_H
#define _OBSERVER_H

#include <Observer\NotifyEvent.h>


class NotifyEvent;

class Observer {

public:
	Observer();
	~Observer();

	virtual void update(NotifyEvent *notifyEvent);




};

#endif //_OBSERVER_H