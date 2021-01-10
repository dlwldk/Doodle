/********************************************************************************
** Form generated from reading UI file 'ToolBarColorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARCOLORWIDGET_H
#define UI_TOOLBARCOLORWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBarColorWidget
{
public:
    QPushButton *redButton;
    QPushButton *blueButton;
    QPushButton *yellowButton;
    QPushButton *dialogButton;

    void setupUi(QWidget *ToolBarColorWidget)
    {
        if (ToolBarColorWidget->objectName().isEmpty())
            ToolBarColorWidget->setObjectName(QString::fromUtf8("ToolBarColorWidget"));
        ToolBarColorWidget->resize(567, 434);
        ToolBarColorWidget->setMinimumSize(QSize(125, 40));
        redButton = new QPushButton(ToolBarColorWidget);
        redButton->setObjectName(QString::fromUtf8("redButton"));
        redButton->setGeometry(QRect(10, 20, 21, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\353\271\250\352\260\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        redButton->setIcon(icon);
        redButton->setIconSize(QSize(30, 30));
        blueButton = new QPushButton(ToolBarColorWidget);
        blueButton->setObjectName(QString::fromUtf8("blueButton"));
        blueButton->setGeometry(QRect(70, 20, 21, 21));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../\355\214\214\353\236\221.png"), QSize(), QIcon::Normal, QIcon::Off);
        blueButton->setIcon(icon1);
        blueButton->setIconSize(QSize(30, 30));
        yellowButton = new QPushButton(ToolBarColorWidget);
        yellowButton->setObjectName(QString::fromUtf8("yellowButton"));
        yellowButton->setGeometry(QRect(40, 20, 21, 21));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../\353\205\270\353\236\221.png"), QSize(), QIcon::Normal, QIcon::Off);
        yellowButton->setIcon(icon2);
        yellowButton->setIconSize(QSize(30, 30));
        dialogButton = new QPushButton(ToolBarColorWidget);
        dialogButton->setObjectName(QString::fromUtf8("dialogButton"));
        dialogButton->setGeometry(QRect(100, 20, 21, 21));

        retranslateUi(ToolBarColorWidget);

        QMetaObject::connectSlotsByName(ToolBarColorWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolBarColorWidget)
    {
        ToolBarColorWidget->setWindowTitle(QApplication::translate("ToolBarColorWidget", "Form", nullptr));
        redButton->setText(QString());
        blueButton->setText(QString());
        yellowButton->setText(QString());
        dialogButton->setText(QApplication::translate("ToolBarColorWidget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolBarColorWidget: public Ui_ToolBarColorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARCOLORWIDGET_H
