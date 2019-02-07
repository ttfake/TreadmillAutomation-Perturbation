/****************************************************************************
** Meta object code from reading C++ file 'ConfigTabWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/ConfigTabWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigTabWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfigTabWidget_t {
    QByteArrayData data[18];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigTabWidget_t qt_meta_stringdata_ConfigTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ConfigTabWidget"
QT_MOC_LITERAL(1, 16, 18), // "timerUpdatedSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 10), // "emgUpdated"
QT_MOC_LITERAL(4, 47, 10), // "setDaqText"
QT_MOC_LITERAL(5, 58, 5), // "title"
QT_MOC_LITERAL(6, 64, 17), // "setDaqLogFileName"
QT_MOC_LITERAL(7, 82, 25), // "startDataCollectionThread"
QT_MOC_LITERAL(8, 108, 18), // "setDaqConnectColor"
QT_MOC_LITERAL(9, 127, 16), // "setDaqRecordBool"
QT_MOC_LITERAL(10, 144, 17), // "setDaqRecordColor"
QT_MOC_LITERAL(11, 162, 11), // "addChannels"
QT_MOC_LITERAL(12, 174, 16), // "timerUpdatedSlot"
QT_MOC_LITERAL(13, 191, 10), // "setEmgData"
QT_MOC_LITERAL(14, 202, 14), // "getActiveState"
QT_MOC_LITERAL(15, 217, 7), // "channel"
QT_MOC_LITERAL(16, 225, 14), // "getChannelType"
QT_MOC_LITERAL(17, 240, 11) // "getGainType"

    },
    "ConfigTabWidget\0timerUpdatedSignal\0\0"
    "emgUpdated\0setDaqText\0title\0"
    "setDaqLogFileName\0startDataCollectionThread\0"
    "setDaqConnectColor\0setDaqRecordBool\0"
    "setDaqRecordColor\0addChannels\0"
    "timerUpdatedSlot\0setEmgData\0getActiveState\0"
    "channel\0getChannelType\0getGainType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   86,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      16,    1,  100,    2, 0x08 /* Private */,
      17,    1,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void ConfigTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigTabWidget *_t = static_cast<ConfigTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timerUpdatedSignal(); break;
        case 1: _t->emgUpdated(); break;
        case 2: _t->setDaqText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setDaqLogFileName(); break;
        case 4: _t->startDataCollectionThread(); break;
        case 5: _t->setDaqConnectColor(); break;
        case 6: _t->setDaqRecordBool(); break;
        case 7: _t->setDaqRecordColor(); break;
        case 8: _t->addChannels(); break;
        case 9: _t->timerUpdatedSlot(); break;
        case 10: _t->setEmgData(); break;
        case 11: _t->getActiveState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->getChannelType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->getGainType((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ConfigTabWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigTabWidget::timerUpdatedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ConfigTabWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigTabWidget::emgUpdated)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ConfigTabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConfigTabWidget.data,
      qt_meta_data_ConfigTabWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConfigTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ConfigTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ConfigTabWidget::timerUpdatedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConfigTabWidget::emgUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
