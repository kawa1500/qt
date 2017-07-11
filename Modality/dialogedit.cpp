#include "dialogedit.h"
#include <QtWidgets>

DialogEdit::DialogEdit(QWidget *parent) :
    QDialog(parent)
{
    mainLayout = new QGridLayout;
    buttonsLayout = new QGridLayout;
    mainGroup = new QGroupBox;
    elementLayout = new QGridLayout;

    ageSpinBox = new QSpinBox;
    ageSpinBox->setMinimum(0);
    ageSpinBox->setMaximum(110);
    nameLineEdit = new QLineEdit;
    elementLayout->addWidget(ageSpinBox,0,0);
    elementLayout->addWidget(nameLineEdit,1,0);
    mainGroup->setLayout(elementLayout);
    
    cancelButton = new QPushButton("Cancel");
    createButton = new QPushButton("Create");
    connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(clickCancelButton()));
    connect(createButton,SIGNAL(clicked(bool)),this,SLOT(clickCreateButton()));
    buttonsLayout->addWidget(cancelButton,0,0);
    buttonsLayout->addWidget(createButton,0,1);
    QWidget *w = new QWidget();
    w->setLayout(buttonsLayout);
    mainLayout->addWidget(mainGroup,0,0);
    mainLayout->addWidget(w,1,0);

    setLayout(mainLayout);
}

DialogEdit::~DialogEdit()
{

}

void DialogEdit::clickCancelButton()
{
    close();
    this->setResult(QDialog::Rejected);
}

void DialogEdit::clickCreateButton()
{
    element = Element(nameLineEdit->text(),ageSpinBox->value());
    emit generate(element);
    close();
    this->setResult(QDialog::Accepted);
}
