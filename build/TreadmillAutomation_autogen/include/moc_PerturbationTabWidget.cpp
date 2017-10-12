/****************************************************************************
** Meta object code from reading C++ file 'PerturbationTabWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/PerturbationTabWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PerturbationTabWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PerturbationTabWidget_t {
    QByteArrayData data[44];
    char stringdata0[681];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PerturbationTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PerturbationTabWidget_t qt_meta_stringdata_PerturbationTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "PerturbationTabWidget"
QT_MOC_LITERAL(1, 22, 9), // "showTimer"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "state"
QT_MOC_LITERAL(4, 39, 30), // "updateDaqDataStreamTableWidget"
QT_MOC_LITERAL(5, 70, 4), // "data"
QT_MOC_LITERAL(6, 75, 9), // "updateCol"
QT_MOC_LITERAL(7, 85, 6), // "mColNo"
QT_MOC_LITERAL(8, 92, 14), // "getActiveState"
QT_MOC_LITERAL(9, 107, 7), // "channel"
QT_MOC_LITERAL(10, 115, 14), // "getChannelType"
QT_MOC_LITERAL(11, 130, 11), // "getGainType"
QT_MOC_LITERAL(12, 142, 10), // "setChannel"
QT_MOC_LITERAL(13, 153, 8), // "mchannel"
QT_MOC_LITERAL(14, 162, 11), // "randomDelay"
QT_MOC_LITERAL(15, 174, 16), // "saveVelocityData"
QT_MOC_LITERAL(16, 191, 22), // "setLeftFrontSpeedValue"
QT_MOC_LITERAL(17, 214, 20), // "mleftFrontSpeedValue"
QT_MOC_LITERAL(18, 235, 23), // "setRightFrontSpeedValue"
QT_MOC_LITERAL(19, 259, 21), // "mrightFrontSpeedValue"
QT_MOC_LITERAL(20, 281, 20), // "setAccelerationValue"
QT_MOC_LITERAL(21, 302, 18), // "maccelerationValue"
QT_MOC_LITERAL(22, 321, 24), // "setAccelerationTimeValue"
QT_MOC_LITERAL(23, 346, 15), // "maccelTimeValue"
QT_MOC_LITERAL(24, 362, 20), // "setDecelerationValue"
QT_MOC_LITERAL(25, 383, 11), // "mdecelValue"
QT_MOC_LITERAL(26, 395, 24), // "setDecelerationTimeValue"
QT_MOC_LITERAL(27, 420, 15), // "mdecelTimeValue"
QT_MOC_LITERAL(28, 436, 14), // "startTreadmill"
QT_MOC_LITERAL(29, 451, 15), // "startDecelTimer"
QT_MOC_LITERAL(30, 467, 11), // "slotTimeout"
QT_MOC_LITERAL(31, 479, 18), // "setDaqConnectColor"
QT_MOC_LITERAL(32, 498, 17), // "setDaqRecordColor"
QT_MOC_LITERAL(33, 516, 16), // "setDaqRecordBool"
QT_MOC_LITERAL(34, 533, 11), // "addChannels"
QT_MOC_LITERAL(35, 545, 16), // "scanForDaqDevice"
QT_MOC_LITERAL(36, 562, 10), // "setDaqText"
QT_MOC_LITERAL(37, 573, 7), // "daqText"
QT_MOC_LITERAL(38, 581, 19), // "setupDataCollection"
QT_MOC_LITERAL(39, 601, 25), // "startDataCollectionThread"
QT_MOC_LITERAL(40, 627, 11), // "setRowCount"
QT_MOC_LITERAL(41, 639, 9), // "mRowCount"
QT_MOC_LITERAL(42, 649, 17), // "setDaqLogFileName"
QT_MOC_LITERAL(43, 667, 13) // "treadmillWait"

    },
    "PerturbationTabWidget\0showTimer\0\0state\0"
    "updateDaqDataStreamTableWidget\0data\0"
    "updateCol\0mColNo\0getActiveState\0channel\0"
    "getChannelType\0getGainType\0setChannel\0"
    "mchannel\0randomDelay\0saveVelocityData\0"
    "setLeftFrontSpeedValue\0mleftFrontSpeedValue\0"
    "setRightFrontSpeedValue\0mrightFrontSpeedValue\0"
    "setAccelerationValue\0maccelerationValue\0"
    "setAccelerationTimeValue\0maccelTimeValue\0"
    "setDecelerationValue\0mdecelValue\0"
    "setDecelerationTimeValue\0mdecelTimeValue\0"
    "startTreadmill\0startDecelTimer\0"
    "slotTimeout\0setDaqConnectColor\0"
    "setDaqRecordColor\0setDaqRecordBool\0"
    "addChannels\0scanForDaqDevice\0setDaqText\0"
    "daqText\0setupDataCollection\0"
    "startDataCollectionThread\0setRowCount\0"
    "mRowCount\0setDaqLogFileName\0treadmillWait"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PerturbationTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  159,    2, 0x0a /* Public */,
       4,    1,  162,    2, 0x0a /* Public */,
       6,    1,  165,    2, 0x0a /* Public */,
       8,    1,  168,    2, 0x0a /* Public */,
      10,    1,  171,    2, 0x0a /* Public */,
      11,    1,  174,    2, 0x0a /* Public */,
      12,    1,  177,    2, 0x0a /* Public */,
      14,    0,  180,    2, 0x0a /* Public */,
      15,    0,  181,    2, 0x0a /* Public */,
      16,    1,  182,    2, 0x08 /* Private */,
      18,    1,  185,    2, 0x08 /* Private */,
      20,    1,  188,    2, 0x08 /* Private */,
      22,    1,  191,    2, 0x08 /* Private */,
      24,    1,  194,    2, 0x08 /* Private */,
      26,    1,  197,    2, 0x08 /* Private */,
      28,    0,  200,    2, 0x08 /* Private */,
      29,    0,  201,    2, 0x08 /* Private */,
      30,    0,  202,    2, 0x08 /* Private */,
      31,    0,  203,    2, 0x08 /* Private */,
      32,    0,  204,    2, 0x08 /* Private */,
      33,    0,  205,    2, 0x08 /* Private */,
      34,    0,  206,    2, 0x08 /* Private */,
      35,    0,  207,    2, 0x08 /* Private */,
      36,    1,  208,    2, 0x08 /* Private */,
      38,    0,  211,    2, 0x08 /* Private */,
      39,    0,  212,    2, 0x08 /* Private */,
      40,    1,  213,    2, 0x08 /* Private */,
      42,    0,  216,    2, 0x08 /* Private */,
      43,    1,  217,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Double,   25,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void PerturbationTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PerturbationTabWidget *_t = static_cast<PerturbationTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showTimer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateDaqDataStreamTableWidget((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->updateCol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->getActiveState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->getChannelType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->getGainType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setChannel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->randomDelay(); break;
        case 8: _t->saveVelocityData(); break;
        case 9: _t->setLeftFrontSpeedValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setRightFrontSpeedValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setAccelerationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->setAccelerationTimeValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->setDecelerationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setDecelerationTimeValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->startTreadmill(); break;
        case 16: _t->startDecelTimer(); break;
        case 17: _t->slotTimeout(); break;
        case 18: _t->setDaqConnectColor(); break;
        case 19: _t->setDaqRecordColor(); break;
        case 20: _t->setDaqRecordBool(); break;
        case 21: _t->addChannels(); break;
        case 22: _t->scanForDaqDevice(); break;
        case 23: _t->setDaqText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->setupDataCollection(); break;
        case 25: _t->startDataCollectionThread(); break;
        case 26: _t->setRowCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->setDaqLogFileName(); break;
        case 28: _t->treadmillWait((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PerturbationTabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PerturbationTabWidget.data,
      qt_meta_data_PerturbationTabWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PerturbationTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PerturbationTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
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
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
