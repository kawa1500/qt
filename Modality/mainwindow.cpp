#include "mainwindow.h"
#include <QtWidgets>
#include "dialogedit.h"
#include<QTextStream>

QTextStream out(stdout);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    fileMenu = menuBar()->addMenu("Element");
    createElement = new QAction("Create",this);
    createElement->setShortcut(QKeySequence::New);
    createElement->setStatusTip("Create new element");
    deleteElementAction = new QAction("Delete",this);
    deleteElementAction->setShortcut(QKeySequence::Delete);
    deleteElementAction->setStatusTip("Delete current element");
    connect(createElement,SIGNAL(triggered(bool)),this, SLOT(createNewElement()));
    connect(deleteElementAction,SIGNAL(triggered(bool)),this,SLOT(deleteElement()));
    fileMenu->addAction(createElement);
    fileMenu->addAction(deleteElementAction);

    listOfElementWidget = new QListWidget;    // make the ListWidgetItems, and assign them to the list_widget

    mainLayout = new QGridLayout;
    mainLayout->addWidget(listOfElementWidget);

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);


}

MainWindow::~MainWindow()
{

}

void MainWindow::finishedDialog(Element element)
{
    out<<"Finished with code: "<<element.info()<<endl;
    elements.append(element);
    update();
}

void MainWindow::createNewElement()
{
    DialogEdit *d = new DialogEdit(this);
    d->show();
    d->setModal(true);

    connect(d,SIGNAL(generate(Element)),this,SLOT(finishedDialog(Element)));
}

void MainWindow::update()
{
    listOfElementWidget->clear();
    for(Element e:elements)
    {
        listOfElementWidget->addItem(e.info());
    }
}

void MainWindow::deleteElement()
{
    int i = listOfElementWidget->currentIndex().row();
    elements.removeAt(i);
    update();
}
