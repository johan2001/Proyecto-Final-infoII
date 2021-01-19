/********************************************************************************
** Form generated from reading UI file 'jefefinal.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JEFEFINAL_H
#define UI_JEFEFINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jefefinal
{
public:

    void setupUi(QWidget *Jefefinal)
    {
        if (Jefefinal->objectName().isEmpty())
            Jefefinal->setObjectName(QString::fromUtf8("Jefefinal"));
        Jefefinal->resize(400, 300);

        retranslateUi(Jefefinal);

        QMetaObject::connectSlotsByName(Jefefinal);
    } // setupUi

    void retranslateUi(QWidget *Jefefinal)
    {
        Jefefinal->setWindowTitle(QCoreApplication::translate("Jefefinal", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Jefefinal: public Ui_Jefefinal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JEFEFINAL_H
