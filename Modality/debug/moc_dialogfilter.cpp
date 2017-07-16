/****************************************************************************
** Meta object code from reading C++ file 'dialogfilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogfilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogfilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogFilter_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogFilter_t qt_meta_stringdata_DialogFilter = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DialogFilter"
QT_MOC_LITERAL(1, 13, 6), // "filter"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "QList<Element>"
QT_MOC_LITERAL(4, 36, 8), // "elements"
QT_MOC_LITERAL(5, 45, 11), // "clickCancel"
QT_MOC_LITERAL(6, 57, 12) // "clickConfirm"

    },
    "DialogFilter\0filter\0\0QList<Element>\0"
    "elements\0clickCancel\0clickConfirm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogFilter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogFilter *_t = static_cast<DialogFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filter((*reinterpret_cast< QList<Element>(*)>(_a[1]))); break;
        case 1: _t->clickCancel(); break;
        case 2: _t->clickConfirm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DialogFilter::*_t)(QList<Element> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DialogFilter::filter)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DialogFilter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogFilter.data,
      qt_meta_data_DialogFilter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DialogFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogFilter.stringdata0))
        return static_cast<void*>(const_cast< DialogFilter*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DialogFilter::filter(QList<Element> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
