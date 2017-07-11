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
