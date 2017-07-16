#ifndef DIALOGGENERATE_H
#define DIALOGGENERATE_H

#include <QDialog>
#include "element.h"
#include <QList>

class QPushButton;
class QComboBox;

class DialogGenerate : public QDialog
{
    Q_OBJECT

public:
    DialogGenerate(QWidget *parent,QList<Element> elements);
    ~DialogGenerate();

private:
    QStringList months;
    QStringList years;
    QString actualMonth;
    QString actualYear;
    QList<Element> elements;
    QPushButton *generatePushButton;
    QComboBox *monthCombo;
    QComboBox *yearCombo;
    QString generateRow(Element element);

private slots:
    void clickGenerate();
};

#endif // DIALOGGENERATE_H
