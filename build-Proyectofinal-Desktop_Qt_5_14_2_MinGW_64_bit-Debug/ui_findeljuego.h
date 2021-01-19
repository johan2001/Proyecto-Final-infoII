/********************************************************************************
** Form generated from reading UI file 'findeljuego.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDELJUEGO_H
#define UI_FINDELJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Findeljuego
{
public:

    void setupUi(QWidget *Findeljuego)
    {
        if (Findeljuego->objectName().isEmpty())
            Findeljuego->setObjectName(QString::fromUtf8("Findeljuego"));
        Findeljuego->resize(400, 300);

        retranslateUi(Findeljuego);

        QMetaObject::connectSlotsByName(Findeljuego);
    } // setupUi

    void retranslateUi(QWidget *Findeljuego)
    {
        Findeljuego->setWindowTitle(QCoreApplication::translate("Findeljuego", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Findeljuego: public Ui_Findeljuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDELJUEGO_H
