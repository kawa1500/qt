#include "dialoggenerate.h"
#include <QtWidgets>
#include <QPrinter>
#include "tableprinter.h"
#include "mymodel.h"

DialogGenerate::DialogGenerate(QWidget *parent, QList<Element> elements) :
    QDialog(parent),elements(elements)
{
    months<<"Styczeń"<<"Luty"<<"Marzec"<<"Kwiecień";
    years<<"2017"<<"2018";
    generatePushButton = new QPushButton("Generate");
    monthCombo = new QComboBox;
    monthCombo->addItems(months);
    yearCombo = new QComboBox;
    yearCombo->addItems(years);

    QGroupBox *option = new QGroupBox;
    QGridLayout *lOption = new QGridLayout;
    lOption->addWidget(monthCombo,0,0);
    lOption->addWidget(yearCombo,0,1);
    option->setLayout(lOption);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(option,0,0);
    mainLayout->addWidget(generatePushButton,1,0);

    setLayout(mainLayout);

    connect(generatePushButton,SIGNAL(clicked(bool)),this,SLOT(clickGenerate()));
}

DialogGenerate::~DialogGenerate()
{

}

void DialogGenerate::clickGenerate()
{
    QTextDocument doc;
    QString s1="<html><head><style>h1 {color:red;} p {color:blue;} table {width:100%;} table, th, td { border: 1px solid black;}</style></head>";
    QString s2="<body><h1>Rachunek za miesiąc maj 2017</h1><div><h2>Instrukcja</h2><p>Jak rachunaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaek zostanie opłacony należy zanaczyć X w kolumnie <i>Zapłacono</i></p></div>";
    QString s3="<div><table><tr><th> Nazwa </th><th> Kwota </th><th> Data wystawienia </th><th> Data płatności </th><th> Zapłacono? </th></tr>";
    QString total=s1+s2+s3;
    for(Element e :elements)
    {
        total+=generateRow(e);
    }
    QString s5="</table></div></body></html> ";
    total+=s5;
    doc.setHtml(total);

    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOutputFileName("test.pdf");
    QPainter painter;
    doc.print(printer);
        painter.end();
}

QString DialogGenerate::generateRow(Element element)
{
    QTextStream ooo(stdout);
    actualMonth=QString::number(monthCombo->currentIndex()+1);
    actualYear=years.at(yearCombo->currentIndex());
    ooo<<actualMonth<<" - "<<actualYear<<endl;
    QDate generateDate = QDate::fromString(QString::number(element.getCreateDay())+"/"+actualMonth+"/"+actualYear,"d/M/yyyy");
    QDate payDate = generateDate.addDays(element.getDaysToPay());
    QString genrateDateString = generateDate.toString("d-M-yyyy");
    QString payDateString = payDate.toString("d-M-yyyy");
    ooo<<genrateDateString<<" - "<<payDateString<<endl;
    QString s="<tr><td>"+element.getName()+"</td><td>"+QString::number(element.getValue())+"</td><td>"+genrateDateString+"</td><td>"+payDateString+"</td><td> </td></tr>";
    return s;

    close();
}
