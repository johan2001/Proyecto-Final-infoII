/********************************************************************************
** Form generated from reading UI file 'multijugador.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIJUGADOR_H
#define UI_MULTIJUGADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multijugador
{
public:

    void setupUi(QWidget *Multijugador)
    {
        if (Multijugador->objectName().isEmpty())
            Multijugador->setObjectName(QString::fromUtf8("Multijugador"));
        Multijugador->resize(400, 300);

        retranslateUi(Multijugador);

        QMetaObject::connectSlotsByName(Multijugador);
    } // setupUi

    void retranslateUi(QWidget *Multijugador)
    {
        Multijugador->setWindowTitle(QCoreApplication::translate("Multijugador", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multijugador: public Ui_Multijugador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIJUGADOR_H
