/********************************************************************************
** Form generated from reading UI file 'detected.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTED_H
#define UI_DETECTED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_detected
{
public:
    QLabel *label;

    void setupUi(QDialog *detected)
    {
        if (detected->objectName().isEmpty())
            detected->setObjectName(QString::fromUtf8("detected"));
        detected->resize(400, 300);
        label = new QLabel(detected);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 40, 151, 16));

        retranslateUi(detected);

        QMetaObject::connectSlotsByName(detected);
    } // setupUi

    void retranslateUi(QDialog *detected)
    {
        detected->setWindowTitle(QApplication::translate("detected", "Dialog", nullptr));
        label->setText(QApplication::translate("detected", "MOVEMENT DETECTED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class detected: public Ui_detected {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTED_H
