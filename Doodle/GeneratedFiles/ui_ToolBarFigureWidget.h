/********************************************************************************
** Form generated from reading UI file 'ToolBarFigureWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARFIGUREWIDGET_H
#define UI_TOOLBARFIGUREWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBarFigureWidget
{
public:
    QPushButton *polygonButton;
    QPushButton *lineButton;
    QPushButton *circleButton;
    QPushButton *rectangleButton;
    QPushButton *triangleButton;
    QPushButton *rhombusButton;
    QPushButton *parallelogramButton;
    QPushButton *cursorButton;

    void setupUi(QWidget *ToolBarFigureWidget)
    {
        if (ToolBarFigureWidget->objectName().isEmpty())
            ToolBarFigureWidget->setObjectName(QString::fromUtf8("ToolBarFigureWidget"));
        ToolBarFigureWidget->resize(420, 369);
        ToolBarFigureWidget->setMinimumSize(QSize(420, 90));
        polygonButton = new QPushButton(ToolBarFigureWidget);
        polygonButton->setObjectName(QString::fromUtf8("polygonButton"));
        polygonButton->setGeometry(QRect(130, 20, 41, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\353\271\210\355\217\264\353\246\254\352\263\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        polygonButton->setIcon(icon);
        lineButton = new QPushButton(ToolBarFigureWidget);
        lineButton->setObjectName(QString::fromUtf8("lineButton"));
        lineButton->setGeometry(QRect(10, 20, 41, 31));
        lineButton->setToolTipDuration(4);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../\354\204\240.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineButton->setIcon(icon1);
        circleButton = new QPushButton(ToolBarFigureWidget);
        circleButton->setObjectName(QString::fromUtf8("circleButton"));
        circleButton->setGeometry(QRect(70, 20, 41, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../\353\271\210\354\233\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        circleButton->setIcon(icon2);
        rectangleButton = new QPushButton(ToolBarFigureWidget);
        rectangleButton->setObjectName(QString::fromUtf8("rectangleButton"));
        rectangleButton->setGeometry(QRect(190, 20, 41, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../\353\271\210\354\202\254\352\260\201\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleButton->setIcon(icon3);
        triangleButton = new QPushButton(ToolBarFigureWidget);
        triangleButton->setObjectName(QString::fromUtf8("triangleButton"));
        triangleButton->setGeometry(QRect(250, 20, 41, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../\353\271\210\354\202\274\352\260\201\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        triangleButton->setIcon(icon4);
        rhombusButton = new QPushButton(ToolBarFigureWidget);
        rhombusButton->setObjectName(QString::fromUtf8("rhombusButton"));
        rhombusButton->setGeometry(QRect(310, 20, 41, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../\353\271\210\353\247\210\353\246\204\353\252\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        rhombusButton->setIcon(icon5);
        parallelogramButton = new QPushButton(ToolBarFigureWidget);
        parallelogramButton->setObjectName(QString::fromUtf8("parallelogramButton"));
        parallelogramButton->setGeometry(QRect(370, 20, 41, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../\353\271\210\355\217\211\355\226\211\354\202\254\353\263\200\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        parallelogramButton->setIcon(icon6);
        cursorButton = new QPushButton(ToolBarFigureWidget);
        cursorButton->setObjectName(QString::fromUtf8("cursorButton"));
        cursorButton->setGeometry(QRect(10, 60, 41, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../\354\273\244\354\204\234\353\252\250\353\223\234.png"), QSize(), QIcon::Normal, QIcon::Off);
        cursorButton->setIcon(icon7);

        retranslateUi(ToolBarFigureWidget);

        QMetaObject::connectSlotsByName(ToolBarFigureWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolBarFigureWidget)
    {
        ToolBarFigureWidget->setWindowTitle(QApplication::translate("ToolBarFigureWidget", "Form", nullptr));
        polygonButton->setText(QString());
        lineButton->setText(QString());
        circleButton->setText(QString());
        rectangleButton->setText(QString());
        triangleButton->setText(QString());
        rhombusButton->setText(QString());
        parallelogramButton->setText(QString());
        cursorButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ToolBarFigureWidget: public Ui_ToolBarFigureWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARFIGUREWIDGET_H
