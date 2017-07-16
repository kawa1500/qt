#include "xmlhandler.h"
#include <QDomDocument>
#include <QFile>
#include <QTextStream>

QTextStream output(stderr);

XmlHandler::XmlHandler(const QString &location):filelocation(location)
{
    filename="data";
}

void XmlHandler::save(const QList<Element> &elements)
{
    QDomDocument doc(filename);
    QFile file(filelocation);
    if (!file.open(QIODevice::ReadWrite)) {
        output<<"Cannot open the file"<<endl;
        return;
    }

    file.close();

    // Modify content
    QDomElement root = doc.createElement("elements");
    doc.appendChild(root);

    for(Element e : elements)
    {
        root.appendChild(convertElement(e));
    }

    if (!file.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
       output<<"Basically, now we lost content of a file"<<endl;
       return;
    }
    QByteArray xml = doc.toByteArray();
    file.write(xml);
    file.close();
}

QDomElement XmlHandler::convertElement(Element element)
{
    QDomDocument doc;
    QDomElement elem = doc.createElement("element");

    add_Param(elem,"name",element.getName());
    add_Param(elem,"createDay",QString::number(element.getCreateDay()));
    add_Param(elem,"daysToPay",QString::number(element.getDaysToPay()));
    add_Param(elem,"nameRecipient",element.getNameRecipient());
    add_Param(elem,"addresRecipient",element.getAddresRecipient());
    add_Param(elem,"numberAccount",element.getNumberAccount());
    add_Param(elem,"value",QString::number(element.getValue()));
    add_Param(elem,"title",element.getTitle());
    QString logic =element.isChangableTitle()?"true":"false";
    add_Param(elem,"chanabletitle",logic);
    add_Param(elem,"templateTitle",element.getTemplateTitle());
    logic =element.isParityMonth()?"true":"false";
    add_Param(elem,"parityMonth",logic);
    logic =element.isNonParityMonth()?"true":"false";
    add_Param(elem,"nonParityMonth",logic);

    return elem;
}

Element XmlHandler::convertQDomNode(QDomNode element)
{
    QDomNodeList l = element.childNodes();
    Element e;
    output<<l.size()<<endl;
    for(int i=0;i<l.size();i++)
    {
        if(l.item(i).nodeName()=="name")
        {
            e.setName(l.item(i).firstChild().nodeValue());
        }
        else if(l.item(i).nodeName()=="createDay")
        {
            e.setCreateDay(l.item(i).firstChild().nodeValue().toInt());
        }
        else if(l.item(i).nodeName()=="daysToPay")
        {
            e.setDaysToPay(l.item(i).firstChild().nodeValue().toInt());
        }
        else if(l.item(i).nodeName()=="nameRecipient")
        {
            e.setNameRecipient(l.item(i).firstChild().nodeValue());
        }
        else if(l.item(i).nodeName()=="addresRecipient")
        {
            e.setAddresRecipient(l.item(i).firstChild().nodeValue());
        }
        else if(l.item(i).nodeName()=="numberAccount")
        {
            e.setNumberAccount(l.item(i).firstChild().nodeValue());
        }
        else if(l.item(i).nodeName()=="value")
        {
            e.setValue(l.item(i).firstChild().nodeValue().toDouble());
        }
        else if(l.item(i).nodeName()=="title")
        {
            e.setTitle(l.item(i).firstChild().nodeValue());
        }
        else if(l.item(i).nodeName()=="chanabletitle")
        {
            e.setChangable(l.item(i).firstChild().nodeValue()=="true"?true:false);
        }
        else if(l.item(i).nodeName()=="templateTitle")
        {
            e.setTemplateTitle(l.item(i).firstChild().nodeValue());
        }
        else if(l.item(i).nodeName()=="parityMonth")
        {
            e.setParityMonth(l.item(i).firstChild().nodeValue()=="true"?true:false);
        }
        else if(l.item(i).nodeName()=="nonParityMonth")
        {
            e.setNonParityMonth(l.item(i).firstChild().nodeValue()=="true"?true:false);
        }
    }
    output<<e.info()<<endl;
    return e;
}

/*
QDomElement Termin::toQDomElement()
{
    QDomDocument doc;
    QDomElement myDom = doc.createElement("Termin");

    add_Param(myDom,"title",title);
    add_Param(myDom,"createDay",QString::number(createDay));
    add_Param(myDom,"recurrence",QString::number(recurrence));
    add_Param(myDom,"dayToPay",QString::number(dayToPay));
    add_Param(myDom,"numberAccount",numberAccount);
    add_Param(myDom,"normalCost",QString::number(normalCost));
    add_Param(myDom,"sourceBill",sourceBill);
    QDomElement transaction = doc.createElement("Transactions");
    QMapIterator<int, QString> i(getTitleTransaction());
    while (i.hasNext()) {
        i.next();
        QDomElement trans = doc.createElement("Transaction");
        QString boolText = getWhichToChange().value(i.key()) ? "true" : "false";
        add_Param(trans,"title",i.value());
        add_Param(trans,"changable",boolText);
        transaction.appendChild(trans);
    }
    myDom.appendChild(transaction);
    return myDom;
}
*/
void XmlHandler::add_Param(QDomElement &elem, const QString name, const QString value)
{
    QDomDocument doc;

    QDomElement e = doc.createElement(name);
    QDomText t=doc.createTextNode(value);
    e.appendChild(t);
    elem.appendChild(e);
}

QList<Element> XmlHandler::getList()
{
    QDomDocument doc(filename);
    QList<Element> elementers;
    QFile file(filelocation);
    if (!file.open(QIODevice::ReadOnly)) {
        output<<"Cannot open the file"<<endl;
        return elementers;
    }
    // Parse file
    if (!doc.setContent(&file)) {
        output<<"Cannot set content to file"<<endl;
        return elementers;
    }
    file.close();

    QDomNodeList listNode = doc.elementsByTagName("element");
    for(int x=0;x<listNode.size();x++)
    {
        QDomNode n = listNode.item(x);
        elementers.append(convertQDomNode(n));
    }

    return elementers;
}
