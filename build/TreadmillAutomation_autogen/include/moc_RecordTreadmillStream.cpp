/****************************************************************************
** Meta object code from reading C++ file 'RecordTreadmillStream.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/RecordTreadmillStream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RecordTreadmillStream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecordTreadmillStream_t {
    QByteArrayData data[7];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecordTreadmillStream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecordTreadmillStream_t qt_meta_stringdata_RecordTreadmillStream = {
    {
QT_MOC_LITERAL(0, 0, 21), // "RecordTreadmillStream"
QT_MOC_LITERAL(1, 22, 16), // "treadmillStarted"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 15), // "setEmitComplete"
QT_MOC_LITERAL(4, 56, 9), // "setRecord"
QT_MOC_LITERAL(5, 66, 20), // "treadmillStartedSlot"
QT_MOC_LITERAL(6, 87, 10) // "stopThread"

    },
    "RecordTreadmillStream\0treadmillStarted\0"
    "\0setEmitComplete\0setRecord\0"
    "treadmillStartedSlot\0stopThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecordTreadmillStream[] = {

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
       3,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   43,    2, 0x0a /* Public */,
       5,    1,   44,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

       0        // eod
};

void RecordTreadmillStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecordTreadmillStream *_t = static_cast<RecordTreadmillStream *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->treadmillStarted((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setEmitComplete(); break;
        case 2: _t->setRecord(); break;
        case 3: _t->treadmillStartedSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->stopThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RecordTreadmillStream::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecordTreadmillStream::treadmillStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RecordTreadmillStream::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecordTreadmillStream::setEmitComplete)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RecordTreadmillStream::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RecordTreadmillStream.data,
      qt_meta_data_RecordTreadmillStream,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RecordTreadmillStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecordTreadmillStream::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecordTreadmillStream.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RecordTreadmillStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void RecordTreadmillStream::treadmillStarted(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RecordTreadmillStream::setEmitComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
