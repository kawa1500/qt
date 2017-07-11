/********************************************************************************
** Form generated from reading UI file 'dialogedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDIT_H
#define UI_DIALOGEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogEdit
{
public:

    void setupUi(QDialog *DialogEdit)
    {
        if (DialogEdit->objectName().isEmpty())
            DialogEdit->setObjectName(QStringLiteral("DialogEdit"));
        DialogEdit->resize(400, 300);

        retranslateUi(DialogEdit);

        QMetaObject::connectSlotsByName(DialogEdit);
    } // setupUi

    void retranslateUi(QDialog *DialogEdit)
    {
        DialogEdit->setWindowTitle(QApplication::translate("DialogEdit", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEdit: public Ui_DialogEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDIT_H
