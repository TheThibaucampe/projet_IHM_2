/****************************************************************************
** Meta object code from reading C++ file 'automate_morceaux.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/automate_morceaux.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'automate_morceaux.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Automate_morceaux_t {
    QByteArrayData data[17];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Automate_morceaux_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Automate_morceaux_t qt_meta_stringdata_Automate_morceaux = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Automate_morceaux"
QT_MOC_LITERAL(1, 18, 13), // "signalMachine"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "signalType"
QT_MOC_LITERAL(4, 44, 2), // "on"
QT_MOC_LITERAL(5, 47, 6), // "param1"
QT_MOC_LITERAL(6, 54, 6), // "param2"
QT_MOC_LITERAL(7, 61, 11), // "signalPause"
QT_MOC_LITERAL(8, 73, 10), // "signalPlay"
QT_MOC_LITERAL(9, 84, 13), // "signalConnect"
QT_MOC_LITERAL(10, 98, 15), // "signalDeconnect"
QT_MOC_LITERAL(11, 114, 15), // "signalModeRadio"
QT_MOC_LITERAL(12, 130, 7), // "setPlay"
QT_MOC_LITERAL(13, 138, 4), // "play"
QT_MOC_LITERAL(14, 143, 10), // "setConnect"
QT_MOC_LITERAL(15, 154, 7), // "setMode"
QT_MOC_LITERAL(16, 162, 5) // "radio"

    },
    "Automate_morceaux\0signalMachine\0\0"
    "signalType\0on\0param1\0param2\0signalPause\0"
    "signalPlay\0signalConnect\0signalDeconnect\0"
    "signalModeRadio\0setPlay\0play\0setConnect\0"
    "setMode\0radio"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Automate_morceaux[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   74,    2, 0x06 /* Public */,
       1,    3,   83,    2, 0x26 /* Public | MethodCloned */,
       1,    2,   90,    2, 0x26 /* Public | MethodCloned */,
       1,    1,   95,    2, 0x26 /* Public | MethodCloned */,
       7,    0,   98,    2, 0x06 /* Public */,
       8,    0,   99,    2, 0x06 /* Public */,
       9,    0,  100,    2, 0x06 /* Public */,
      10,    0,  101,    2, 0x06 /* Public */,
      11,    0,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  103,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      15,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int, QMetaType::Int,    2,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int,    2,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    4,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,   16,

       0        // eod
};

void Automate_morceaux::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Automate_morceaux *_t = static_cast<Automate_morceaux *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalMachine((*reinterpret_cast< signalType(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->signalMachine((*reinterpret_cast< signalType(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->signalMachine((*reinterpret_cast< signalType(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->signalMachine((*reinterpret_cast< signalType(*)>(_a[1]))); break;
        case 4: _t->signalPause(); break;
        case 5: _t->signalPlay(); break;
        case 6: _t->signalConnect(); break;
        case 7: _t->signalDeconnect(); break;
        case 8: _t->signalModeRadio(); break;
        case 9: _t->setPlay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setConnect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Automate_morceaux::*_t)(signalType , bool , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automate_morceaux::signalMachine)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Automate_morceaux::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automate_morceaux::signalPause)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Automate_morceaux::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automate_morceaux::signalPlay)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Automate_morceaux::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automate_morceaux::signalConnect)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Automate_morceaux::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automate_morceaux::signalDeconnect)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Automate_morceaux::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Automate_morceaux::signalModeRadio)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject Automate_morceaux::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Automate_morceaux.data,
      qt_meta_data_Automate_morceaux,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Automate_morceaux::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Automate_morceaux::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Automate_morceaux.stringdata0))
        return static_cast<void*>(const_cast< Automate_morceaux*>(this));
    return QObject::qt_metacast(_clname);
}

int Automate_morceaux::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Automate_morceaux::signalMachine(signalType _t1, bool _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 4
void Automate_morceaux::signalPause()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Automate_morceaux::signalPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Automate_morceaux::signalConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void Automate_morceaux::signalDeconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void Automate_morceaux::signalModeRadio()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE