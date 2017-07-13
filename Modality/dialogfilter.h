#ifndef DIALOGFILTER_H
#define DIALOGFILTER_H

#include <QDialog>
#include "element.h"

class DialogFilter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFilter(QList<Element> elements,QWidget *parent = 0);
    ~DialogFilter();

private:

};

#endif // DIALOGFILTER_H
