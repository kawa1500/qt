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
    QListWidget *listOfElementWidget;
    QGridLayout *mainLayout;
    QMenu *fileMenu;
    QAction *createElement;
    QAction *deleteElementAction;
    QAction *updateElementAction;
    QMenu *operationMenu;
    QAction *exportElementsAction;
    QAction *importElementsAction;
    QMenu *filterElementMenu;
    QMenu *sortElementMenu;
    QAction *sortByNameAction;
    QAction *sortByAgeAction;

private slots:
    void finishedDialog(Element element);
    void updatedDialog(Element element);
    void updatedDialog(QList<Element> elements);
    void clickCreateNewElement();
    void clickDeleteElement();
    void clickUpdateElement();
    void clickExportElements();
    void clickImportElements();
    void sortByName();
    void sortByAge();

private:
    void update();
    void createMenu();
    void createView();
};

#endif // MAINWINDOW_H
