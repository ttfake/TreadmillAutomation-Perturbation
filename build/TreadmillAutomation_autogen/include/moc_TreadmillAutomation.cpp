/****************************************************************************
** Meta object code from reading C++ file 'TreadmillAutomation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/TreadmillAutomation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TreadmillAutomation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TreadmillAutomation_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreadmillAutomation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreadmillAutomation_t qt_meta_stringdata_TreadmillAutomation = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TreadmillAutomation"
QT_MOC_LITERAL(1, 20, 19), // "setUseLibraryStatus"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "setSocket"
QT_MOC_LITERAL(4, 51, 14), // "showDaqDataBox"
QT_MOC_LITERAL(5, 66, 9), // "showTimer"
QT_MOC_LITERAL(6, 76, 11), // "errorString"
QT_MOC_LITERAL(7, 88, 1), // "s"
QT_MOC_LITERAL(8, 90, 10), // "closeEvent"
QT_MOC_LITERAL(9, 101, 12), // "QCloseEvent*"
QT_MOC_LITERAL(10, 114, 5), // "event"
QT_MOC_LITERAL(11, 120, 10), // "emgUpdated"
QT_MOC_LITERAL(12, 131, 18) // "showAddTimeToDecel"

    },
    "TreadmillAutomation\0setUseLibraryStatus\0"
    "\0setSocket\0showDaqDataBox\0showTimer\0"
    "errorString\0s\0closeEvent\0QCloseEvent*\0"
    "event\0emgUpdated\0showAddTimeToDecel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreadmillAutomation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
      11,    0,   64,    2, 0x08 /* Private */,
      12,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TreadmillAutomation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TreadmillAutomation *_t = static_cast<TreadmillAutomation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setUseLibraryStatus(); break;
        case 1: _t->setSocket(); break;
        case 2: _t->showDaqDataBox(); break;
        case 3: _t->showTimer(); break;
        case 4: _t->errorString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 6: _t->emgUpdated(); break;
        case 7: _t->showAddTimeToDecel(); break;
        default: ;
        }
    }
}

const QMetaObject TreadmillAutomation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TreadmillAutomation.data,
      qt_meta_data_TreadmillAutomation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TreadmillAutomation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreadmillAutomation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TreadmillAutomation.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TreadmillAutomation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
