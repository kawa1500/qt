/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "finishedDialog"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "Element"
QT_MOC_LITERAL(4, 35, 7), // "element"
QT_MOC_LITERAL(5, 43, 13), // "updatedDialog"
QT_MOC_LITERAL(6, 57, 14), // "QList<Element>"
QT_MOC_LITERAL(7, 72, 8), // "elements"
QT_MOC_LITERAL(8, 81, 12), // "filterDialog"
QT_MOC_LITERAL(9, 94, 21), // "clickCreateNewElement"
QT_MOC_LITERAL(10, 116, 18), // "clickDeleteElement"
QT_MOC_LITERAL(11, 135, 18), // "clickUpdateElement"
QT_MOC_LITERAL(12, 154, 19), // "clickExportElements"
QT_MOC_LITERAL(13, 174, 19), // "clickImportElements"
QT_MOC_LITERAL(14, 194, 19), // "clickFilterElements"
QT_MOC_LITERAL(15, 214, 10), // "sortByName"
QT_MOC_LITERAL(16, 225, 11), // "sortByValue"
QT_MOC_LITERAL(17, 237, 21) // "clickGenerateElements"

    },
    "MainWindow\0finishedDialog\0\0Element\0"
    "element\0updatedDialog\0QList<Element>\0"
    "elements\0filterDialog\0clickCreateNewElement\0"
    "clickDeleteElement\0clickUpdateElement\0"
    "clickExportElements\0clickImportElements\0"
    "clickFilterElements\0sortByName\0"
    "sortByValue\0clickGenerateElements"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       5,    1,   85,    2, 0x08 /* Private */,
       8,    1,   88,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishedDialog((*reinterpret_cast< Element(*)>(_a[1]))); break;
        case 1: _t->updatedDialog((*reinterpret_cast< Element(*)>(_a[1]))); break;
        case 2: _t->updatedDialog((*reinterpret_cast< QList<Element>(*)>(_a[1]))); break;
        case 3: _t->filterDialog((*reinterpret_cast< QList<Element>(*)>(_a[1]))); break;
        case 4: _t->clickCreateNewElement(); break;
        case 5: _t->clickDeleteElement(); break;
        case 6: _t->clickUpdateElement(); break;
        case 7: _t->clickExportElements(); break;
        case 8: _t->clickImportElements(); break;
        case 9: _t->clickFilterElements(); break;
        case 10: _t->sortByName(); break;
        case 11: _t->sortByValue(); break;
        case 12: _t->clickGenerateElements(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
