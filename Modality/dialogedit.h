#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>
#include "element.h"

class QGridLayout;
class QSpinBox;
class QLineEdit;
class QGroupBox;
class QPushButton;
class QDoubleSpinBox;
class QCheckBox;

class DialogEdit : public QDialog
{
    Q_OBJECT

public:
    DialogEdit(QWidget *parent = 0);
    DialogEdit(QWidget *parent, Element element);
    ~DialogEdit();
    Element element;

private:
    void createView(bool update);
    void createElement();
    QGridLayout *mainLayout;
    QGridLayout *buttonsLayout;
    QGridLayout *elementLayout;
    QGroupBox *mainGroup;

    QLineEdit *nameLineEdit;
    QSpinBox *createDaySpinBox;
    QSpinBox *dayToPaySpinBox;
    QLineEdit *nameRecipientLineEdit;
    QLineEdit *addresRecipientLineEdit;
    QLineEdit *numberAccountLineEdit;
    QDoubleSpinBox *valueSpinBox;
    QLineEdit *titleLineEdit;
    QLineEdit *templateTitleLineEdit;
    QCheckBox *changableCheckBox;
    QCheckBox *parityCheckBox;
    QCheckBox *nonParityCheckBox;

    QPushButton *cancelButton;
    QPushButton *createButton;

private slots:
    void clickCancelButton();
    void clickCreateButton();
    void clickUpdateButton();
    void isChangable();

signals:
    void generate(Element element);
    void update(Element element);
};

#endif // DIALOGEDIT_H
