#include "xmlhandler.h"
#include <QDomDocument>
#include <QFile>
#include <QTextStream>

QTextStream output(stdout);

XmlHandler::XmlHandler(const QString &location):filelocation(location)
{
    filename="data";
}

void XmlHandler::save(const QList<Element> &elements)
{
    // Open file
    QDomDocument doc(filename);
    QFile file(filelocation);
    if (!file.open(QIODevice::ReadWrite)) {
         output<<"Cannot open the file"<<endl;
        return;
    }
    // Parse file
    /*if (!doc.setContent(&file)) {
        QDomProcessingInstruction xmlVers = doc.createProcessingInstruction("xml","version=\"1.0\" encoding='utf-8'");
        doc.appendChild(xmlVers);
    }*/
    QDomProcessingInstruction xmlVers = doc.createProcessingInstruction("xml","version=\"1.0\" encoding='utf-8'");
    doc.appendChild(xmlVers);
    file.close();

    // Modify content
    QDomElement root = doc.createElement("elements");
    doc.appendChild(root);


    for(Element e : elements)
    {
        root.appendChild(convertElement(e));
    }

    // Then do the same thing for somechild
    // Save content back to the file
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
    add_Param(elem,"age",QString::number(element.getAge()));

    return elem;
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

    // Modify content
    QDomNodeList listNode = doc.elementsByTagName("element");
    output<<"count of item"<<listNode.size()<<endl;
    for(int x=0;x<listNode.size();x++)
    {
        QDomNode node =listNode.item(x);
        QDomNodeList l = node.childNodes();
        QString name;
        int age;
        output<<"child of item"<<l.size()<<endl;
        for(int i=0;i<l.size();i++)
        {
            if(l.item(i).nodeName().contains("name"))
            {
                name=l.item(i).firstChild().nodeValue();
                output<<"name of item"<<name<<endl;
            }
            else if(l.item(i).nodeName().contains("age"))
            {
                age=l.item(i).firstChild().nodeValue().toInt();
                output<<"age of item"<<age<<endl;
            }
        }
        elementers.append(Element(name,age));
    }

    return elementers;
}
