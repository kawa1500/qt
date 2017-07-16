#include "mainwindow.h"
#include <QtWidgets>
#include "dialogedit.h"
#include<QTextStream>
#include "xmlhandler.h"
#include "dialogfilter.h"
#include "dialoggenerate.h"

QTextStream out(stdout);//stream to console output
int last;//store index of element to edit

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createMenu();
    createView();

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);

    update();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu("Element");

    createElement = new QAction("Create",this);
    createElement->setShortcut(QKeySequence::New);
    createElement->setStatusTip("Create new element");

    deleteElementAction = new QAction("Delete",this);
    deleteElementAction->setShortcut(QKeySequence::Delete);
    deleteElementAction->setStatusTip("Delete current element");

    updateElementAction = new QAction("Edit",this);
    updateElementAction->setShortcut(QKeySequence::Forward);
    updateElementAction->setStatusTip("Update select element");

    filterElementMenu = new QAction("Filter",this);//create description

    fileMenu->addAction(createElement);
    fileMenu->addAction(deleteElementAction);
    fileMenu->addAction(updateElementAction);
    fileMenu->addAction(filterElementMenu);
    sortElementMenu = fileMenu->addMenu("Sort by");

    sortByNameAction = new QAction("Name",this);
    sortByNameAction->setStatusTip("Sort element by name");

    sortByValueAction = new QAction("Value",this);
    sortByValueAction->setStatusTip("Sort element by value");

    sortElementMenu->addAction(sortByNameAction);
    sortElementMenu->addAction(sortByValueAction);

    operationMenu = menuBar()->addMenu("Operation");

    exportElementsAction = new QAction("Export",this);
    exportElementsAction->setShortcut(QKeySequence::Save);
    exportElementsAction->setStatusTip("Export all elements to File XML");

    importElementsAction = new QAction("Import",this);
    importElementsAction->setShortcut(QKeySequence::Open);
    importElementsAction->setStatusTip("Import all elements from XML file");

    operationMenu->addAction(exportElementsAction);
    operationMenu->addAction(importElementsAction);

    generateElementsMenu = menuBar()->addMenu("Generate Month");
    billAction = new QAction("Bill",this);
    generateElementsMenu->addAction(billAction);

    connect(updateElementAction,SIGNAL(triggered(bool)),this,SLOT(clickUpdateElement()));
    connect(createElement,SIGNAL(triggered(bool)),this, SLOT(clickCreateNewElement()));
    connect(deleteElementAction,SIGNAL(triggered(bool)),this,SLOT(clickDeleteElement()));
    connect(exportElementsAction,SIGNAL(triggered(bool)),this,SLOT(clickExportElements()));
    connect(importElementsAction,SIGNAL(triggered(bool)),this,SLOT(clickImportElements()));
    connect(sortByNameAction,SIGNAL(triggered(bool)),this,SLOT(sortByName()));
    connect(sortByValueAction,SIGNAL(triggered(bool)),this,SLOT(sortByValue()));
    connect(filterElementMenu,SIGNAL(triggered(bool)),this,SLOT(clickFilterElements()));
    connect(billAction,SIGNAL(triggered(bool)),this,SLOT(clickGenerateElements()));
}

void MainWindow::createView()
{
    listOfElementWidget = new QListWidget;
    mainLayout = new QGridLayout;
    mainLayout->addWidget(listOfElementWidget);
    setWindowIcon(QIcon(":/icon.png"));

    connect(listOfElementWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(clickUpdateElement()));
}

void MainWindow::update()
{
    update(elements);
}

void MainWindow::update(QList<Element> mElements)
{
    listOfElementWidget->clear();
    for(Element e:mElements)
    {
        listOfElementWidget->addItem(e.info());
    }
    bool enable=true;
    if(mElements.size()<=0)enable=false;
    deleteElementAction->setEnabled(enable);
    updateElementAction->setEnabled(enable);
    exportElementsAction->setEnabled(enable);
    filterElementMenu->setEnabled(enable);
    sortElementMenu->setEnabled(enable);
}

void MainWindow::finishedDialog(Element element)
{
    elements.append(element);
    update();
}

void MainWindow::updatedDialog(Element element)
{
    elements.replace(last,element);
    update();
}

void MainWindow::updatedDialog(QList<Element> elements)
{
    this->elements=elements;
    update();
}

void MainWindow::clickCreateNewElement()
{
    DialogEdit *d = new DialogEdit(this);
    d->show();
    d->setModal(true);

    connect(d,SIGNAL(generate(Element)),this,SLOT(finishedDialog(Element)));
}

void MainWindow::clickDeleteElement()
{
    int i = listOfElementWidget->currentIndex().row();
    elements.removeAt(i);
    update();
}

void MainWindow::clickUpdateElement()
{
    last = listOfElementWidget->currentIndex().row();
    DialogEdit *d = new DialogEdit(this,elements.at(last));
    d->show();
    d->setModal(true);

    connect(d,SIGNAL(update(Element)),this,SLOT(updatedDialog(Element)));
}

void MainWindow::clickExportElements()
{
    QString dir = QFileDialog::getSaveFileName(this,"Create File",QDir::currentPath(),"*.xml");
    out<<dir<<endl;
    XmlHandler xml(dir);
    xml.save(elements);
}

void MainWindow::clickImportElements()
{
    QString dir = QFileDialog::getOpenFileName(this,"Open File",QDir::currentPath(),"*.xml");
    out<<dir<<endl;
    XmlHandler xml(dir);
    elements = xml.getList();
    update();
}

void MainWindow::sortByName()
{
    qSort(elements.begin(), elements.end(), Element::sortByName);
    update();
}

void MainWindow::sortByValue()
{
    qSort(elements.begin(), elements.end(), Element::sortByValue);
    update();
}

void MainWindow::clickFilterElements()
{
    DialogFilter *d = new DialogFilter(elements,this);
    d->show();
    d->setModal(true);

    connect(d,SIGNAL(filter(QList<Element>)),this,SLOT(filterDialog(QList<Element>)));
}

void MainWindow::filterDialog(QList<Element> elements)
{
    update(elements);
}

void MainWindow::clickGenerateElements()
{
    out<<"click Generate"<<endl;
    DialogGenerate *d = new DialogGenerate(this,elements);
    d->show();
    d->setModal(true);
}
