#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

class Element
{
public:
    Element(const QString& name);
    Element();
    void setName(const QString& name);
    void setValue(const double& value);
    void setAddresRecipient(const QString& address);
    void setNameRecipient(const QString& name);
    void setNumberAccount(const QString& number);
    void setCreateDay(const int& day);
    void setDaysToPay(const int& day);
    void setTitle(const QString& title);
    void setTemplateTitle(const QString& templateTitle);
    void setChangable(const bool& changable);
    void setParityMonth(const bool& parity);
    void setNonParityMonth(const bool& nonParity);
    const QString& getName();
    const int& getCreateDay();
    const int& getDaysToPay();
    const QString& getNameRecipient();
    const QString& getAddresRecipient();
    const QString& getNumberAccount();
    const double& getValue();
    const QString& getTitle();
    const QString& getTemplateTitle();
    const bool& isChangableTitle();
    const bool& isParityMonth();
    const bool& isNonParityMonth();
    const QString info();

private:
    QString name;
    int createDay;
    int daysToPay;
    QString nameRecipient;
    QString addresRecipient;
    QString numberAccount;
    double value;
    QString title;
    bool chanabletitle;
    QString templateTitle;
    bool parityMonth;
    bool nonParityMonth;


public:
    static bool sortByName(const Element &s1, const Element &s2);
    static bool sortByValue(const Element &s1, const Element &s2);

};

#endif // ELEMENT_H
