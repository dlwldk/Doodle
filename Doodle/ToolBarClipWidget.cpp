
#include "ToolBarClipWidget.h"
#include <qmessagebox.h>
#include "Chain_Of_Responsibility/ChangeFigureClipRequest.h"
#include "Observer/ChangeManager.h"


ToolBarClipWidget::ToolBarClipWidget(QWidget *parent, Chain *chain)
	:QWidget(parent), Chain(chain) {

	ui.setupUi(this);

	connect(ui.cutButton, &QPushButton::clicked, this, &ToolBarClipWidget::cutButtonClicked);
	connect(ui.copyButton, &QPushButton::clicked, this, &ToolBarClipWidget::copyButtonClicked);
	connect(ui.pasteButton, &QPushButton::clicked, this, &ToolBarClipWidget::pasteButtonClicked);

	ChangeManager::getInstance()->registerObserve(this);
}


void ToolBarClipWidget::cutButtonClicked() {

	ChangeFigureClipRequest request(ChangeFigureClipRequest::ChangeCutMode);

	this->request(&request);

}

void ToolBarClipWidget::copyButtonClicked() {

	ChangeFigureClipRequest request(ChangeFigureClipRequest::ChangeCopyMode);

	this->request(&request);

}

void ToolBarClipWidget::pasteButtonClicked() {

	ChangeFigureClipRequest request(ChangeFigureClipRequest::ChangePasteMode);

	this->request(&request);

}

ToolBarClipWidget::~ToolBarClipWidget() {


}

#include "Observer/CopiedFigureCountChangedEvent.h"

void ToolBarClipWidget::update(NotifyEvent *notifyEvent) {


	if (dynamic_cast<CopiedFigureCountChangedEvent*>(notifyEvent)) {

		if (dynamic_cast<CopiedFigureCountChangedEvent*>(notifyEvent)->getSelectedFigureCount() == 0) {
			ui.cutButton->setEnabled(false);
			ui.copyButton->setEnabled(false);
		}
		else {
			ui.cutButton->setEnabled(true);
			ui.copyButton->setEnabled(true);
		}
		if (dynamic_cast<CopiedFigureCountChangedEvent*>(notifyEvent)->getCopiedFigureCount() == 0) {
			ui.pasteButton->setEnabled(false);
		}
		else {
			ui.pasteButton->setEnabled(true);
		}

	}
}

