/****************************************************************************
** Meta object code from reading C++ file 'PerturbationTabWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "PerturbationTabWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PerturbationTabWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PerturbationTabWidget_t {
    QByteArrayData data[26];
    char stringdata0[428];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PerturbationTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PerturbationTabWidget_t qt_meta_stringdata_PerturbationTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "PerturbationTabWidget"
QT_MOC_LITERAL(1, 22, 22), // "setLeftFrontSpeedValue"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 20), // "mleftFrontSpeedValue"
QT_MOC_LITERAL(4, 67, 23), // "setRightFrontSpeedValue"
QT_MOC_LITERAL(5, 91, 21), // "mrightFrontSpeedValue"
QT_MOC_LITERAL(6, 113, 20), // "setAccelerationValue"
QT_MOC_LITERAL(7, 134, 18), // "maccelerationValue"
QT_MOC_LITERAL(8, 153, 24), // "setAccelerationTimeValue"
QT_MOC_LITERAL(9, 178, 15), // "maccelTimeValue"
QT_MOC_LITERAL(10, 194, 20), // "setDecelerationValue"
QT_MOC_LITERAL(11, 215, 11), // "mdecelValue"
QT_MOC_LITERAL(12, 227, 24), // "setDecelerationTimeValue"
QT_MOC_LITERAL(13, 252, 15), // "mdecelTimeValue"
QT_MOC_LITERAL(14, 268, 15), // "startAccelTimer"
QT_MOC_LITERAL(15, 284, 13), // "sendSetpoints"
QT_MOC_LITERAL(16, 298, 17), // "TreadmillProperty"
QT_MOC_LITERAL(17, 316, 9), // "mproperty"
QT_MOC_LITERAL(18, 326, 12), // "SetpointType"
QT_MOC_LITERAL(19, 339, 2), // "mt"
QT_MOC_LITERAL(20, 342, 21), // "sendSetpointsDirectly"
QT_MOC_LITERAL(21, 364, 20), // "sendSetpointsLibrary"
QT_MOC_LITERAL(22, 385, 15), // "startDecelTimer"
QT_MOC_LITERAL(23, 401, 11), // "slotTimeout"
QT_MOC_LITERAL(24, 413, 8), // "addTimer"
QT_MOC_LITERAL(25, 422, 5) // "state"

    },
    "PerturbationTabWidget\0setLeftFrontSpeedValue\0"
    "\0mleftFrontSpeedValue\0setRightFrontSpeedValue\0"
    "mrightFrontSpeedValue\0setAccelerationValue\0"
    "maccelerationValue\0setAccelerationTimeValue\0"
    "maccelTimeValue\0setDecelerationValue\0"
    "mdecelValue\0setDecelerationTimeValue\0"
    "mdecelTimeValue\0startAccelTimer\0"
    "sendSetpoints\0TreadmillProperty\0"
    "mproperty\0SetpointType\0mt\0"
    "sendSetpointsDirectly\0sendSetpointsLibrary\0"
    "startDecelTimer\0slotTimeout\0addTimer\0"
    "state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PerturbationTabWidget[] = {

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
       4,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       8,    1,   88,    2, 0x08 /* Private */,
      10,    1,   91,    2, 0x08 /* Private */,
      12,    1,   94,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    2,   98,    2, 0x08 /* Private */,
      20,    2,  103,    2, 0x08 /* Private */,
      21,    1,  108,    2, 0x08 /* Private */,
      22,    0,  111,    2, 0x08 /* Private */,
      23,    0,  112,    2, 0x08 /* Private */,
      24,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,

       0        // eod
};

void PerturbationTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PerturbationTabWidget *_t = static_cast<PerturbationTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setLeftFrontSpeedValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setRightFrontSpeedValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setAccelerationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setAccelerationTimeValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setDecelerationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setDecelerationTimeValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->startAccelTimer(); break;
        case 7: _t->sendSetpoints((*reinterpret_cast< TreadmillProperty(*)>(_a[1])),(*reinterpret_cast< SetpointType(*)>(_a[2]))); break;
        case 8: _t->sendSetpointsDirectly((*reinterpret_cast< TreadmillProperty(*)>(_a[1])),(*reinterpret_cast< SetpointType(*)>(_a[2]))); break;
        case 9: _t->sendSetpointsLibrary((*reinterpret_cast< SetpointType(*)>(_a[1]))); break;
        case 10: _t->startDecelTimer(); break;
        case 11: _t->slotTimeout(); break;
        case 12: _t->addTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PerturbationTabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PerturbationTabWidget.data,
      qt_meta_data_PerturbationTabWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PerturbationTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PerturbationTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PerturbationTabWidget.stringdata0))
        return static_cast<void*>(const_cast< PerturbationTabWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PerturbationTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
