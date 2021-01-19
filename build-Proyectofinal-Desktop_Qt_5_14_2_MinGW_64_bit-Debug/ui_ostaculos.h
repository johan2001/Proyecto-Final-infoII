/********************************************************************************
** Form generated from reading UI file 'ostaculos.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSTACULOS_H
#define UI_OSTACULOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ostaculos
{
public:

    void setupUi(QWidget *Ostaculos)
    {
        if (Ostaculos->objectName().isEmpty())
            Ostaculos->setObjectName(QString::fromUtf8("Ostaculos"));
        Ostaculos->resize(400, 300);

        retranslateUi(Ostaculos);

        QMetaObject::connectSlotsByName(Ostaculos);
    } // setupUi

    void retranslateUi(QWidget *Ostaculos)
    {
        Ostaculos->setWindowTitle(QCoreApplication::translate("Ostaculos", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ostaculos: public Ui_Ostaculos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSTACULOS_H
