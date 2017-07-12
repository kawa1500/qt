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

    operationMenu->addAction(exportElementsAction);

    connect(updateElementAction,SIGNAL(triggered(bool)),this,SLOT(clickUpdateElement()));
    connect(createElement,SIGNAL(triggered(bool)),this, SLOT(clickCreateNewElement()));
    connect(deleteElementAction,SIGNAL(triggered(bool)),this,SLOT(clickDeleteElement()));
    connect(exportElementsAction,SIGNAL(triggered(bool)),this,SLOT(clickExportElements()));

    if(elements.size()==0)
    {
        deleteElementAction->setEnabled(false);
        updateElementAction->setEnabled(false);
        exportElementsAction->setEnabled(false);
    }
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
}

void MainWindow::finishedDialog(Element element)
{
    elements.append(element);
    update();
    if(!deleteElementAction->isEnabled())
    {
        deleteElementAction->setEnabled(true);
        updateElementAction->setEnabled(true);
        exportElementsAction->setEnabled(true);
    }
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
    if(elements.size()==0)
    {
        deleteElementAction->setEnabled(false);
        updateElementAction->setEnabled(false);
        exportElementsAction->setEnabled(false);
    }
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
