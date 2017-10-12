/****************************************************************************
** Meta object code from reading C++ file 'MccDaqInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/MccDaqInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MccDaqInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MccDaqInterface_t {
    QByteArrayData data[19];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MccDaqInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MccDaqInterface_t qt_meta_stringdata_MccDaqInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MccDaqInterface"
QT_MOC_LITERAL(1, 16, 8), // "finished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "setDaqTitleText"
QT_MOC_LITERAL(4, 42, 5), // "title"
QT_MOC_LITERAL(5, 48, 22), // "updateDaqDataBoxSignal"
QT_MOC_LITERAL(6, 71, 4), // "data"
QT_MOC_LITERAL(7, 76, 14), // "updateRowCount"
QT_MOC_LITERAL(8, 91, 9), // "mRowCount"
QT_MOC_LITERAL(9, 101, 9), // "updateCol"
QT_MOC_LITERAL(10, 111, 9), // "mColCount"
QT_MOC_LITERAL(11, 121, 14), // "getActiveState"
QT_MOC_LITERAL(12, 136, 8), // "mchannel"
QT_MOC_LITERAL(13, 145, 14), // "getChannelType"
QT_MOC_LITERAL(14, 160, 11), // "getGainType"
QT_MOC_LITERAL(15, 172, 17), // "setCurrentChannel"
QT_MOC_LITERAL(16, 190, 19), // "beginDataCollection"
QT_MOC_LITERAL(17, 210, 16), // "setDaqButtonText"
QT_MOC_LITERAL(18, 227, 12) // "daqTitleText"

    },
    "MccDaqInterface\0finished\0\0setDaqTitleText\0"
    "title\0updateDaqDataBoxSignal\0data\0"
    "updateRowCount\0mRowCount\0updateCol\0"
    "mColCount\0getActiveState\0mchannel\0"
    "getChannelType\0getGainType\0setCurrentChannel\0"
    "beginDataCollection\0setDaqButtonText\0"
    "daqTitleText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MccDaqInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       7,    1,   76,    2, 0x06 /* Public */,
       9,    1,   79,    2, 0x06 /* Public */,
      11,    1,   82,    2, 0x06 /* Public */,
      13,    1,   85,    2, 0x06 /* Public */,
      14,    1,   88,    2, 0x06 /* Public */,
      15,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,   94,    2, 0x0a /* Public */,
      17,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void MccDaqInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MccDaqInterface *_t = static_cast<MccDaqInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->setDaqTitleText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateDaqDataBoxSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->updateRowCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateCol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->getActiveState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->getChannelType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->getGainType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setCurrentChannel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->beginDataCollection(); break;
        case 10: _t->setDaqButtonText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MccDaqInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::setDaqTitleText)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::updateDaqDataBoxSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::updateRowCount)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::updateCol)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::getActiveState)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::getChannelType)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::getGainType)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MccDaqInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MccDaqInterface::setCurrentChannel)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject MccDaqInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MccDaqInterface.data,
      qt_meta_data_MccDaqInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MccDaqInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MccDaqInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MccDaqInterface.stringdata0))
        return static_cast<void*>(const_cast< MccDaqInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int MccDaqInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MccDaqInterface::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MccDaqInterface::setDaqTitleText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MccDaqInterface::updateDaqDataBoxSignal(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MccDaqInterface::updateRowCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MccDaqInterface::updateCol(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MccDaqInterface::getActiveState(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MccDaqInterface::getChannelType(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MccDaqInterface::getGainType(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MccDaqInterface::setCurrentChannel(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
