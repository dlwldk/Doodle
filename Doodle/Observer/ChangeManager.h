#ifndef CHANGEMANAGER_H
#define CHANGEMANAGER_H

#include <QList>
#include <Observer\Observer.h>

class Observer;

class ChangeManager {

private:
	ChangeManager();
	~ChangeManager();
	
	static ChangeManager instance;


public:
	void registerObserve(Observer *observer);

	static ChangeManager* getInstance() {
	
		return &ChangeManager::instance;
	}
	
	void update(NotifyEvent *notifyEvent);

private:
	QList <Observer*> observers;

};

#endif // CHANGEMANAGER_H
