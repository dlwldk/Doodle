#include <Observer\ChangeManager.h>
#include "Observer/Observer.h"

ChangeManager ChangeManager::instance;

ChangeManager::ChangeManager() {


}

void ChangeManager::registerObserve(Observer *observer) {

	this->observers.append(observer);

}

void ChangeManager::update(NotifyEvent *notifyEvent) {


	for (int i = 0; i < this->observers.size(); i++) {
	
		this->observers.at(i)->update(notifyEvent);
	}
}


ChangeManager::~ChangeManager() {

}