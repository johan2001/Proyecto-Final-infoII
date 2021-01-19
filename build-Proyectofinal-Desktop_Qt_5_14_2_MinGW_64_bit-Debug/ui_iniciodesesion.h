/********************************************************************************
** Form generated from reading UI file 'iniciodesesion.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIODESESION_H
#define UI_INICIODESESION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Iniciodesesion
{
public:

    void setupUi(QWidget *Iniciodesesion)
    {
        if (Iniciodesesion->objectName().isEmpty())
            Iniciodesesion->setObjectName(QString::fromUtf8("Iniciodesesion"));
        Iniciodesesion->resize(400, 300);

        retranslateUi(Iniciodesesion);

        QMetaObject::connectSlotsByName(Iniciodesesion);
    } // setupUi

    void retranslateUi(QWidget *Iniciodesesion)
    {
        Iniciodesesion->setWindowTitle(QCoreApplication::translate("Iniciodesesion", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Iniciodesesion: public Ui_Iniciodesesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIODESESION_H
