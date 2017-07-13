#include "element.h"

Element::Element(const QString &name, const int &age):name(name),age(age)
{

}

Element::Element()
{

}

const QString& Element::getName()
{
    return name;
}

const int& Element::getAge()
{
    return age;
}

const QString Element::info()
{
    return "Element{ name="+name+", age="+QString::number(age)+"}";
}

bool Element::sortByName(const Element &s1, const Element &s2)
{
    if(QString::compare(s1.name,s2.name,Qt::CaseInsensitive)<0)return true;
    return false;
}

bool Element::sortByAge(const Element &s1, const Element &s2)
{
    if(s1.age<s2.age)return true;
    return false;
}
