/****************************************************************************
** Meta object code from reading C++ file 'DataCollection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/DataCollection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataCollection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataCollection_t {
    QByteArrayData data[11];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataCollection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataCollection_t qt_meta_stringdata_DataCollection = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataCollection"
QT_MOC_LITERAL(1, 15, 16), // "treadmillStarted"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "stopThread"
QT_MOC_LITERAL(4, 44, 8), // "finished"
QT_MOC_LITERAL(5, 53, 14), // "startRecording"
QT_MOC_LITERAL(6, 68, 9), // "readyRead"
QT_MOC_LITERAL(7, 78, 19), // "startDataCollection"
QT_MOC_LITERAL(8, 98, 15), // "setEmitComplete"
QT_MOC_LITERAL(9, 114, 5), // "error"
QT_MOC_LITERAL(10, 120, 28) // "QAbstractSocket::SocketError"

    },
    "DataCollection\0treadmillStarted\0\0"
    "stopThread\0finished\0startRecording\0"
    "readyRead\0startDataCollection\0"
    "setEmitComplete\0error\0"
    "QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataCollection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    0,   62,    2, 0x06 /* Public */,
       4,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   64,    2, 0x0a /* Public */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,

       0        // eod
};

void DataCollection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataCollection *_t = static_cast<DataCollection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->treadmillStarted((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->stopThread(); break;
        case 2: _t->finished(); break;
        case 3: _t->startRecording(); break;
        case 4: _t->readyRead(); break;
        case 5: _t->startDataCollection(); break;
        case 6: _t->setEmitComplete(); break;
        case 7: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 8: _t->error(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DataCollection::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCollection::treadmillStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataCollection::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCollection::stopThread)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataCollection::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataCollection::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DataCollection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataCollection.data,
      qt_meta_data_DataCollection,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataCollection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataCollection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataCollection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataCollection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DataCollection::treadmillStarted(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataCollection::stopThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DataCollection::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
