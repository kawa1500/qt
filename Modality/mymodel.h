#ifndef MYMODEL_H
#define MYMODEL_H

#include<QAbstractTableModel>

class MyModel: public QAbstractTableModel
{
public:
    MyModel(QObject *parent);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // MYMODEL_H
