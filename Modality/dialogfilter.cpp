#include "dialogfilter.h"
#include <QtWidgets>

DialogFilter::DialogFilter(QList<Element> elements, QWidget *parent) :
    QDialog(parent),elements(elements)
{
    mainLayout = new QGridLayout;
    typeComboBox = new QComboBox;
    typeComboBox->addItem("Name");
    typeComboBox->addItem("Age");
    regexpLineEdit = new QLineEdit;
    cancelButton = new QPushButton("Cancel");
    confitmButton = new QPushButton("Confirm");
    buttonLayout = new QGridLayout;
    QGroupBox *b = new QGroupBox;
    buttonLayout->addWidget(cancelButton,0,0);
    buttonLayout->addWidget(confitmButton,0,1);
    b->setLayout(buttonLayout);
    mainLayout->addWidget(typeComboBox,0,0);
    mainLayout->addWidget(regexpLineEdit,1,0);
    mainLayout->addWidget(b,2,0);
    setLayout(mainLayout);

    connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(clickCancel()));
    connect(confitmButton,SIGNAL(clicked(bool)),this,SLOT(clickConfirm()));
}

DialogFilter::~DialogFilter()
{

}

void DialogFilter::clickCancel()
{
    close();
    this->setResult(QDialog::Rejected);
}

void DialogFilter::clickConfirm()
{
   /* QRegularExpression re(regexpLineEdit->text());
    QList<Element> nElem;
    for(Element e: elements)
    {
        QRegularExpressionMatch match = re.match(e.getName());
        if (match.hasMatch()) {
            nElem.append(e);
        }
    }
*/
    emit filter(elements);
    close();
    this->setResult(QDialog::Accepted);
}
