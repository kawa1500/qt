#include "dialogedit.h"
#include <QtWidgets>

DialogEdit::DialogEdit(QWidget *parent) :
    QDialog(parent)
{
    createView(false);
    setLayout(mainLayout);
}

DialogEdit::DialogEdit(QWidget *parent, Element element):
    QDialog(parent),element(element)
{
    createView(true);
    setLayout(mainLayout);
    nameLineEdit->setText(element.getName());
    createDaySpinBox->setValue(element.getCreateDay());
    dayToPaySpinBox->setValue(element.getDaysToPay());
    nameRecipientLineEdit->setText(element.getNameRecipient());
    addresRecipientLineEdit->setText(element.getAddresRecipient());
    numberAccountLineEdit->setText(element.getNumberAccount());
    valueSpinBox->setValue(element.getValue());
    titleLineEdit->setText(element.getTitle());
    templateTitleLineEdit->setText(element.getTemplateTitle());
    changableCheckBox->setChecked(element.isChangableTitle());
    parityCheckBox->setChecked(element.isParityMonth());
    nonParityCheckBox->setChecked(element.isNonParityMonth());
    isChangable();
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
    createElement();
    emit generate(element);
    close();
    this->setResult(QDialog::Accepted);
}

void DialogEdit::clickUpdateButton()
{
    createElement();
    emit update(element);
    close();
    this->setResult(QDialog::Accepted);
}

void DialogEdit::isChangable()
{
    if(changableCheckBox->isChecked()){
        templateTitleLineEdit->setEnabled(true);
    }
    else
    {
        templateTitleLineEdit->setText("");
        templateTitleLineEdit->setEnabled(false);
    }
}

void DialogEdit::createElement()
{
    element = Element(nameLineEdit->text());
    element.setCreateDay(createDaySpinBox->value());
    element.setDaysToPay(dayToPaySpinBox->value());
    element.setNameRecipient(nameRecipientLineEdit->text());
    element.setAddresRecipient(addresRecipientLineEdit->text());
    element.setNumberAccount(numberAccountLineEdit->text());
    element.setValue(valueSpinBox->value());
    element.setTitle(titleLineEdit->text());
    element.setTemplateTitle(templateTitleLineEdit->text());
    element.setChangable(changableCheckBox->isChecked());
    element.setParityMonth(parityCheckBox->isChecked());
    element.setNonParityMonth(nonParityCheckBox->isChecked());
}

void DialogEdit::createView(bool update)
{
    mainLayout = new QGridLayout;
    buttonsLayout = new QGridLayout;
    mainGroup = new QGroupBox;
    elementLayout = new QGridLayout;

    nameLineEdit = new QLineEdit;
    createDaySpinBox = new QSpinBox;
    createDaySpinBox->setMinimum(0);
    createDaySpinBox->setMaximum(31);
    dayToPaySpinBox = new QSpinBox;
    dayToPaySpinBox->setMinimum(0);
    dayToPaySpinBox->setMaximum(28);
    dayToPaySpinBox->setValue(14);
    nameRecipientLineEdit = new QLineEdit;
    addresRecipientLineEdit = new QLineEdit;
    numberAccountLineEdit = new QLineEdit;
    valueSpinBox = new QDoubleSpinBox;
    valueSpinBox->setMinimum(0.0);
    valueSpinBox->setMaximum(1000.0);
    titleLineEdit = new QLineEdit;
    templateTitleLineEdit = new QLineEdit;
    changableCheckBox = new QCheckBox;
    changableCheckBox->setChecked(true);
    connect(changableCheckBox,SIGNAL(clicked(bool)),this,SLOT(isChangable()));
    parityCheckBox = new QCheckBox;
    parityCheckBox->setChecked(true);
    nonParityCheckBox = new QCheckBox;
    nonParityCheckBox->setChecked(true);

    elementLayout->addWidget(new QLabel("Name:"),0,0);
    elementLayout->addWidget(nameLineEdit,0,1);
    elementLayout->addWidget(new QLabel("Day create Bill:"),1,0);
    elementLayout->addWidget(createDaySpinBox,1,1);
    elementLayout->addWidget(new QLabel("Day wait for Pay:"),2,0);
    elementLayout->addWidget(dayToPaySpinBox,2,1);
    elementLayout->addWidget(new QLabel("Name of Recipient:"),3,0);
    elementLayout->addWidget(nameRecipientLineEdit,3,1);
    elementLayout->addWidget(new QLabel("Addrees of Recipient:"),4,0);
    elementLayout->addWidget(addresRecipientLineEdit,4,1);
    elementLayout->addWidget(new QLabel("Number of account:"),5,0);
    elementLayout->addWidget(numberAccountLineEdit,5,1);
    elementLayout->addWidget(new QLabel("Value:"),6,0);
    elementLayout->addWidget(valueSpinBox,6,1);
    elementLayout->addWidget(new QLabel("Title transaction:"),7,0);
    elementLayout->addWidget(titleLineEdit,7,1);
    elementLayout->addWidget(new QLabel("Changable Title:"),8,0);
    elementLayout->addWidget(changableCheckBox,8,1);
    elementLayout->addWidget(new QLabel("Template of title Transaction:"),9,0);
    elementLayout->addWidget(templateTitleLineEdit,9,1);
    elementLayout->addWidget(new QLabel("Parity Month:"),10,0);
    elementLayout->addWidget(parityCheckBox,10,1);
    elementLayout->addWidget(new QLabel("NonParity Month:"),11,0);
    elementLayout->addWidget(nonParityCheckBox,11,1);

    mainGroup->setLayout(elementLayout);

    cancelButton = new QPushButton("Cancel");
    connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(clickCancelButton()));
    if(update)
    {
        createButton = new QPushButton("Update");
        connect(createButton,SIGNAL(clicked(bool)),this,SLOT(clickUpdateButton()));
    }
    else
    {
        createButton = new QPushButton("Create");
        connect(createButton,SIGNAL(clicked(bool)),this,SLOT(clickCreateButton()));
    }
    buttonsLayout->addWidget(cancelButton,0,0);
    buttonsLayout->addWidget(createButton,0,1);
    QWidget *w = new QWidget();
    w->setLayout(buttonsLayout);
    mainLayout->addWidget(mainGroup,0,0);
    mainLayout->addWidget(w,1,0);
    setFixedWidth(600);
    isChangable();
}
