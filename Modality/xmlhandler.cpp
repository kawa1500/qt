#include "xmlhandler.h"
#include <QDomDocument>
#include <QFile>

XmlHandler::XmlHandler(const QString &location):filelocation(location)
{

}

void XmlHandler::save(const QList<Element> &elements)
{
    // Open file
    QDomDocument doc(filename);
    QFile file(filelocation);
    if (!file.open(QIODevice::ReadWrite)) {
         out<<"Cannot open the file"<<endl;
        return;
    }
    // Parse file
    if (!doc.setContent(&file)) {
        QDomProcessingInstruction xmlVers = doc.createProcessingInstruction("xml","version=\"1.0\" encoding='utf-8'");
        doc.appendChild(xmlVers);
    }
    file.close();

    // Modify content
    QDomNodeList roots = doc.elementsByTagName(rootName);
    QDomElement root;
    if (roots.size() < 1) {
       out<<"Cannot find root"<<endl;;
       out<<"Create Root"<<endl;
      root = doc.createElement(rootName);
      doc.appendChild(root);
    }
    else{
        root= roots.at(0).toElement();
    }

    for(Element e : elements)
    {
        root.appendChild(convertElement(e));
    }

    // Then do the same thing for somechild
    // Save content back to the file
    if (!file.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
       out<<"Basically, now we lost content of a file"<<endl;
        return;
    }
    QByteArray xml = doc.toByteArray();
    file.write(xml);
    file.close();
}

const QDomElement& XmlHandler::convertElement(const Element &element)
{

}
