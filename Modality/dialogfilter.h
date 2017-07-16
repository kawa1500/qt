#ifndef DIALOGFILTER_H
#define DIALOGFILTER_H

#include <QDialog>
#include "element.h"

class QComboBox;
class QLineEdit;
class QGridLayout;
class QPushButton;

class DialogFilter : public QDialog
{
    Q_OBJECT

public:
    DialogFilter(QList<Element> elements,QWidget *parent = 0);
    ~DialogFilter();

private:
    QComboBox *typeComboBox;
    QLineEdit *regexpLineEdit;
    QGridLayout *mainLayout;
    QPushButton *cancelButton;
    QPushButton *confitmButton;
    QGridLayout *buttonLayout;
    QList<Element> elements;

private slots:
    void clickCancel();
    void clickConfirm();

signals:
    void filter(QList<Element> elements);

};

#endif // DIALOGFILTER_H
