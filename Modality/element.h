#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

class Element
{
public:
    Element(const QString& name, const int& age);
    Element();
    const QString& getName();
    const int& getAge();
    const QString info();

private:
    QString name;
    int age;

public:
    static bool sortByName(const Element &s1, const Element &s2);
    static bool sortByAge(const Element &s1, const Element &s2);

};

#endif // ELEMENT_H
