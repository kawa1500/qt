#include "mainwindow.h"
#include <QtWidgets>
#include "dialogedit.h"
#include<QTextStream>
#include "xmlhandler.h"

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

    fileMenu->addAction(createElement);
    fileMenu->addAction(deleteElementAction);
    fileMenu->addAction(updateElementAction);

    operationMenu = menuBar()->addMenu("Operation");

    exportElementsAction = new QAction("Export",this);
    exportElementsAction->setShortcut(QKeySequence::Save);
    exportElementsAction->setStatusTip("Export all elements to File XML");

    importElementsAction = new QAction("Import",this);
    importElementsAction->setShortcut(QKeySequence::Open);
    importElementsAction->setStatusTip("Import all elements from XML file");

    operationMenu->addAction(exportElementsAction);
    operationMenu->addAction(importElementsAction);

    connect(updateElementAction,SIGNAL(triggered(bool)),this,SLOT(clickUpdateElement()));
    connect(createElement,SIGNAL(triggered(bool)),this, SLOT(clickCreateNewElement()));
    connect(deleteElementAction,SIGNAL(triggered(bool)),this,SLOT(clickDeleteElement()));
    connect(exportElementsAction,SIGNAL(triggered(bool)),this,SLOT(clickExportElements()));
    connect(importElementsAction,SIGNAL(triggered(bool)),this,SLOT(clickImportElements()));
}

void MainWindow::createView()
{
    listOfElementWidget = new QListWidget;
    mainLayout = new QGridLayout;
    mainLayout->addWidget(listOfElementWidget);
}

void MainWindow::update()
{
    listOfElementWidget->clear();
    for(Element e:elements)
    {
        listOfElementWidget->addItem(e.info());
    }
    bool enable=true;
    if(elements.size()<=0)enable=false;
    deleteElementAction->setEnabled(enable);
    updateElementAction->setEnabled(enable);
    exportElementsAction->setEnabled(enable);
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
