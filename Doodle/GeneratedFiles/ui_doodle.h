/********************************************************************************
** Form generated from reading UI file 'doodle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOODLE_H
#define UI_DOODLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include "Ui\DrawingWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Doodle
{
public:
    QAction *newMenu;
    QAction *openMenu;
    QAction *saveMenu;
    QAction *othersaveMenu;
    DrawingWidget *drawingWidget;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *Doodle)
    {
        if (Doodle->objectName().isEmpty())
            Doodle->setObjectName(QString::fromUtf8("Doodle"));
        Doodle->resize(1149, 551);
        Doodle->setMinimumSize(QSize(700, 0));
        Doodle->setToolTipDuration(11);
        newMenu = new QAction(Doodle);
        newMenu->setObjectName(QString::fromUtf8("newMenu"));
        openMenu = new QAction(Doodle);
        openMenu->setObjectName(QString::fromUtf8("openMenu"));
        saveMenu = new QAction(Doodle);
        saveMenu->setObjectName(QString::fromUtf8("saveMenu"));
        othersaveMenu = new QAction(Doodle);
        othersaveMenu->setObjectName(QString::fromUtf8("othersaveMenu"));
        drawingWidget = new DrawingWidget(Doodle);
        drawingWidget->setObjectName(QString::fromUtf8("drawingWidget"));
        Doodle->setCentralWidget(drawingWidget);
        toolBar = new QToolBar(Doodle);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMinimumSize(QSize(0, 0));
        toolBar->setMaximumSize(QSize(16777215, 16777215));
        toolBar->setAcceptDrops(true);
        toolBar->setToolTipDuration(11);
        toolBar->setLayoutDirection(Qt::LeftToRight);
        toolBar->setAutoFillBackground(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Doodle->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(Doodle);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1149, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        Doodle->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(newMenu);
        menu->addAction(openMenu);
        menu->addAction(saveMenu);
        menu->addAction(othersaveMenu);

        retranslateUi(Doodle);

        QMetaObject::connectSlotsByName(Doodle);
    } // setupUi

    void retranslateUi(QMainWindow *Doodle)
    {
        Doodle->setWindowTitle(QApplication::translate("Doodle", "Doodle", nullptr));
        newMenu->setText(QApplication::translate("Doodle", "\354\203\210\353\241\234 \353\247\214\353\223\244\352\270\260", nullptr));
        openMenu->setText(QApplication::translate("Doodle", "\354\227\264\352\270\260", nullptr));
        saveMenu->setText(QApplication::translate("Doodle", "\354\240\200\354\236\245", nullptr));
        othersaveMenu->setText(QApplication::translate("Doodle", "\353\213\244\353\245\270 \354\235\264\353\246\204\354\234\274\353\241\234 \354\240\200\354\236\245", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Doodle", "toolBar", nullptr));
#ifndef QT_NO_STATUSTIP
        toolBar->setStatusTip(QApplication::translate("Doodle", "10", nullptr));
#endif // QT_NO_STATUSTIP
        menu->setTitle(QApplication::translate("Doodle", "\355\214\214\354\235\274", nullptr));
        menu_2->setTitle(QApplication::translate("Doodle", "\355\216\270\354\247\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Doodle: public Ui_Doodle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOODLE_H
