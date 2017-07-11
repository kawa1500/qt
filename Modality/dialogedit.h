#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>
#include "element.h"

class QGridLayout;
class QSpinBox;
class QLineEdit;
class QGroupBox;
class QPushButton;

class DialogEdit : public QDialog
{
    Q_OBJECT

public:
    DialogEdit(QWidget *parent = 0);
    ~DialogEdit();
    Element element;

private:
    QGridLayout *mainLayout;
    QGridLayout *buttonsLayout;
    QGridLayout *elementLayout;
    QGroupBox *mainGroup;
    QSpinBox *ageSpinBox;
    QLineEdit *nameLineEdit;
    QPushButton *cancelButton;
    QPushButton *createButton;

private slots:
    void clickCancelButton();
    void clickCreateButton();

signals:
    void generate(Element element);
};

#endif // DIALOGEDIT_H
