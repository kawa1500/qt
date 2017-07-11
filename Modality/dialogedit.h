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
    DialogEdit(QWidget *parent, Element element);
    ~DialogEdit();
    Element element;

private:
    void createView(bool update);
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
    void clickUpdateButton();

signals:
    void generate(Element element);
    void update(Element element);
};

#endif // DIALOGEDIT_H
