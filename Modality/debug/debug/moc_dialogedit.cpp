/****************************************************************************
** Meta object code from reading C++ file 'dialogedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialogedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogEdit_t {
    QByteArrayData data[9];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogEdit_t qt_meta_stringdata_DialogEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DialogEdit"
QT_MOC_LITERAL(1, 11, 8), // "generate"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "Element"
QT_MOC_LITERAL(4, 29, 7), // "element"
QT_MOC_LITERAL(5, 37, 6), // "update"
QT_MOC_LITERAL(6, 44, 17), // "clickCancelButton"
QT_MOC_LITERAL(7, 62, 17), // "clickCreateButton"
QT_MOC_LITERAL(8, 80, 17) // "clickUpdateButton"

    },
    "DialogEdit\0generate\0\0Element\0element\0"
    "update\0clickCancelButton\0clickCreateButton\0"
    "clickUpdateButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogEdit *_t = static_cast<DialogEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->generate((*reinterpret_cast< Element(*)>(_a[1]))); break;
        case 1: _t->update((*reinterpret_cast< Element(*)>(_a[1]))); break;
        case 2: _t->clickCancelButton(); break;
        case 3: _t->clickCreateButton(); break;
        case 4: _t->clickUpdateButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogEdit::*_t)(Element );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogEdit::generate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DialogEdit::*_t)(Element );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogEdit::update)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DialogEdit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogEdit.data,
      qt_meta_data_DialogEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogEdit.stringdata0))
        return static_cast<void*>(const_cast< DialogEdit*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DialogEdit::generate(Element _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DialogEdit::update(Element _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
