#include "element.h"

Element::Element(const QString &name):name(name)
{

}

Element::Element()
{

}

const QString& Element::getName()
{
    return name;
}

const QString& Element::getNameRecipient()
{
    return nameRecipient;
}

const QString& Element::getAddresRecipient()
{
    return addresRecipient;
}

const QString& Element::getNumberAccount()
{
    return numberAccount;
}

const QString& Element::getTitle()
{
    return title;
}

const QString& Element::getTemplateTitle()
{
    return templateTitle;
}

const int& Element::getCreateDay()
{
    return createDay;
}

const int& Element::getDaysToPay()
{
    return daysToPay;
}

const double& Element::getValue()
{
    return value;
}

const bool& Element::isChangableTitle()
{
    return chanabletitle;
}

const bool& Element::isParityMonth()
{
    return parityMonth;
}

const bool& Element::isNonParityMonth()
{
    return nonParityMonth;
}

void Element::setName(const QString& name){
    this->name=name;
}

void Element::setValue(const double& value){
    this->value=value;
}

void Element::setAddresRecipient(const QString& address){
    this->addresRecipient=address;
}

void Element::setNameRecipient(const QString& name){
    this->nameRecipient=name;
}

void Element::setNumberAccount(const QString& number){
    this->numberAccount=number;
}

void Element::setCreateDay(const int& day){
    this->createDay=day;
}

void Element::setDaysToPay(const int& day){
    this->daysToPay=day;
}

void Element::setTitle(const QString& title){
    this->title=title;
}

void Element::setTemplateTitle(const QString& templateTitle){
    this->templateTitle=templateTitle;
}

void Element::setChangable(const bool& changable){
    this->chanabletitle=changable;
}

void Element::setParityMonth(const bool& parity){
    this->parityMonth=parity;
}

void Element::setNonParityMonth(const bool& nonParity){
    this->nonParityMonth=nonParity;
}

const QString Element::info()
{
    return "Element{ name="+name+", value="+QString::number(value)+
            ", createDay="+QString::number(createDay)+"}";
}

bool Element::sortByName(const Element &s1, const Element &s2)
{
    if(QString::compare(s1.name,s2.name,Qt::CaseInsensitive)<0)return true;
    return false;
}

bool Element::sortByValue(const Element &s1, const Element &s2)
{
    if(s1.value<s2.value)return true;
    return false;
}
