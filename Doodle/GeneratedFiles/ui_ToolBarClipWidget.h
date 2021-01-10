/********************************************************************************
** Form generated from reading UI file 'ToolBarClipWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARCLIPWIDGET_H
#define UI_TOOLBARCLIPWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBarClipWidget
{
public:
    QPushButton *cutButton;
    QPushButton *copyButton;
    QPushButton *pasteButton;

    void setupUi(QWidget *ToolBarClipWidget)
    {
        if (ToolBarClipWidget->objectName().isEmpty())
            ToolBarClipWidget->setObjectName(QString::fromUtf8("ToolBarClipWidget"));
        ToolBarClipWidget->resize(170, 300);
        ToolBarClipWidget->setMinimumSize(QSize(170, 0));
        cutButton = new QPushButton(ToolBarClipWidget);
        cutButton->setObjectName(QString::fromUtf8("cutButton"));
        cutButton->setGeometry(QRect(20, 20, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\354\236\230\353\235\274\353\202\264\352\270\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutButton->setIcon(icon);
        copyButton = new QPushButton(ToolBarClipWidget);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        copyButton->setGeometry(QRect(70, 20, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../\353\263\265\354\202\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyButton->setIcon(icon1);
        pasteButton = new QPushButton(ToolBarClipWidget);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        pasteButton->setGeometry(QRect(120, 20, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../\353\266\231\354\227\254\353\204\243\352\270\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteButton->setIcon(icon2);

        retranslateUi(ToolBarClipWidget);

        QMetaObject::connectSlotsByName(ToolBarClipWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolBarClipWidget)
    {
        ToolBarClipWidget->setWindowTitle(QApplication::translate("ToolBarClipWidget", "Form", nullptr));
        cutButton->setText(QString());
        copyButton->setText(QString());
        pasteButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ToolBarClipWidget: public Ui_ToolBarClipWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARCLIPWIDGET_H
