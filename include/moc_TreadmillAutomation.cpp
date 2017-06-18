/****************************************************************************
** Meta object code from reading C++ file 'TreadmillAutomation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TreadmillAutomation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TreadmillAutomation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TreadmillAutomation_t {
    QByteArrayData data[14];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreadmillAutomation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreadmillAutomation_t qt_meta_stringdata_TreadmillAutomation = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TreadmillAutomation"
QT_MOC_LITERAL(1, 20, 14), // "onClickConnect"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "onClickDisconnect"
QT_MOC_LITERAL(4, 54, 9), // "connected"
QT_MOC_LITERAL(5, 64, 12), // "disconnected"
QT_MOC_LITERAL(6, 77, 9), // "readyRead"
QT_MOC_LITERAL(7, 87, 5), // "error"
QT_MOC_LITERAL(8, 93, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 122, 13), // "sendSetpoints"
QT_MOC_LITERAL(10, 136, 12), // "SetpointType"
QT_MOC_LITERAL(11, 149, 1), // "t"
QT_MOC_LITERAL(12, 151, 21), // "sendSetpointsDirectly"
QT_MOC_LITERAL(13, 173, 20) // "sendSetpointsLibrary"

    },
    "TreadmillAutomation\0onClickConnect\0\0"
    "onClickDisconnect\0connected\0disconnected\0"
    "readyRead\0error\0QAbstractSocket::SocketError\0"
    "sendSetpoints\0SetpointType\0t\0"
    "sendSetpointsDirectly\0sendSetpointsLibrary"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreadmillAutomation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    1,   69,    2, 0x0a /* Public */,
       9,    1,   72,    2, 0x0a /* Public */,
       9,    0,   75,    2, 0x2a /* Public | MethodCloned */,
      12,    1,   76,    2, 0x0a /* Public */,
      13,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void TreadmillAutomation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TreadmillAutomation *_t = static_cast<TreadmillAutomation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClickConnect(); break;
        case 1: _t->onClickDisconnect(); break;
        case 2: _t->connected(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->readyRead(); break;
        case 5: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->sendSetpoints((*reinterpret_cast< SetpointType(*)>(_a[1]))); break;
        case 7: _t->sendSetpoints(); break;
        case 8: _t->sendSetpointsDirectly((*reinterpret_cast< SetpointType(*)>(_a[1]))); break;
        case 9: _t->sendSetpointsLibrary((*reinterpret_cast< SetpointType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject TreadmillAutomation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TreadmillAutomation.data,
      qt_meta_data_TreadmillAutomation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TreadmillAutomation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreadmillAutomation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TreadmillAutomation.stringdata0))
        return static_cast<void*>(const_cast< TreadmillAutomation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TreadmillAutomation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
