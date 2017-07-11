#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "element.h"

class QListWidget;
class QGridLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QList<Element> elements;
    QMenu *fileMenu;
    QAction *createElement;
    QAction *deleteElementAction;
    QAction *updateElementAction;
    QListWidget *listOfElementWidget;
    QGridLayout *mainLayout;
    QMenu *operationMenu;
    QAction *exportElements;

private slots:
    void finishedDialog(Element element);
    void updatedDialog(Element element);
    void createNewElement();
    void deleteElement();
    void updateElement();
    void clickExportElements();

private:
    void update();
};

#endif // MAINWINDOW_H
