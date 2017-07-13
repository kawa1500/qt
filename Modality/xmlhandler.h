#ifndef XMLHANDLER_H
#define XMLHANDLER_H

#include<QString>
#include "element.h"

class QDomElement;
class QDomNode;

class XmlHandler
{
public:
    XmlHandler(const QString& location);
    void save(const QList<Element>& elements);
    QList<Element> getList();

private:
    QString filelocation;
    QString filename;

private:
    QDomElement convertElement(Element element);
    Element convertQDomNode(QDomNode element);
    void add_Param(QDomElement &elem, const QString name, const QString value);
};

#endif // XMLHANDLER_H
