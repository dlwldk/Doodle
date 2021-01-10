/********************************************************************************
** Form generated from reading UI file 'ToolBarCommandWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARCOMMANDWIDGET_H
#define UI_TOOLBARCOMMANDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBarCommandWidget
{
public:
    QPushButton *redoButton;
    QPushButton *undoButton;
    QPushButton *alleraseButton;

    void setupUi(QWidget *ToolBarCommandWidget)
    {
        if (ToolBarCommandWidget->objectName().isEmpty())
            ToolBarCommandWidget->setObjectName(QString::fromUtf8("ToolBarCommandWidget"));
        ToolBarCommandWidget->resize(240, 305);
        ToolBarCommandWidget->setMinimumSize(QSize(240, 50));
        redoButton = new QPushButton(ToolBarCommandWidget);
        redoButton->setObjectName(QString::fromUtf8("redoButton"));
        redoButton->setGeometry(QRect(50, 20, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\354\225\236\354\234\274\353\241\234\352\260\200\352\270\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        redoButton->setIcon(icon);
        undoButton = new QPushButton(ToolBarCommandWidget);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));
        undoButton->setGeometry(QRect(10, 20, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../\353\222\244\353\241\234\352\260\200\352\270\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        undoButton->setIcon(icon1);
        alleraseButton = new QPushButton(ToolBarCommandWidget);
        alleraseButton->setObjectName(QString::fromUtf8("alleraseButton"));
        alleraseButton->setGeometry(QRect(120, 20, 111, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../\353\252\250\353\221\220\354\247\200\354\232\260\352\270\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        alleraseButton->setIcon(icon2);

        retranslateUi(ToolBarCommandWidget);

        QMetaObject::connectSlotsByName(ToolBarCommandWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolBarCommandWidget)
    {
        ToolBarCommandWidget->setWindowTitle(QApplication::translate("ToolBarCommandWidget", "Form", nullptr));
        redoButton->setText(QString());
        undoButton->setText(QString());
        alleraseButton->setText(QApplication::translate("ToolBarCommandWidget", "\353\252\250\353\221\220 \354\247\200\354\232\260\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolBarCommandWidget: public Ui_ToolBarCommandWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARCOMMANDWIDGET_H
