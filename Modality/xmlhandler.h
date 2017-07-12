#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include<QString>
#include "element.h"

class QDomElement;

class XmlHandler
{
public:
    XmlHandler(const QString& location);
    void save(const QList<Element>& elements);

private:
    QString filelocation;
    QString filename;

private:
    const QDomElement& convertElement(const Element& element);
};

#endif // XMLHANDLER_H
