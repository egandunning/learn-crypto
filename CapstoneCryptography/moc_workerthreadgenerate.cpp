/****************************************************************************
** Meta object code from reading C++ file 'workerthreadgenerate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/workerthreadgenerate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workerthreadgenerate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorkerThreadGenerate_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkerThreadGenerate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkerThreadGenerate_t qt_meta_stringdata_WorkerThreadGenerate = {
    {
QT_MOC_LITERAL(0, 0, 20), // "WorkerThreadGenerate"
QT_MOC_LITERAL(1, 21, 8), // "finished"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 20), // "std::vector<QPointF>"
QT_MOC_LITERAL(4, 52, 17), // "updateProgressBar"
QT_MOC_LITERAL(5, 70, 14) // "pointGenerated"

    },
    "WorkerThreadGenerate\0finished\0\0"
    "std::vector<QPointF>\0updateProgressBar\0"
    "pointGenerated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerThreadGenerate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void WorkerThreadGenerate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkerThreadGenerate *_t = static_cast<WorkerThreadGenerate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< std::vector<QPointF>(*)>(_a[1]))); break;
        case 1: _t->updateProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->pointGenerated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkerThreadGenerate::*_t)(std::vector<QPointF> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerThreadGenerate::finished)) {
                *result = 0;
            }
        }
        {
            typedef void (WorkerThreadGenerate::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerThreadGenerate::updateProgressBar)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WorkerThreadGenerate::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_WorkerThreadGenerate.data,
      qt_meta_data_WorkerThreadGenerate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkerThreadGenerate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerThreadGenerate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkerThreadGenerate.stringdata0))
        return static_cast<void*>(const_cast< WorkerThreadGenerate*>(this));
    return QThread::qt_metacast(_clname);
}

int WorkerThreadGenerate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void WorkerThreadGenerate::finished(std::vector<QPointF> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkerThreadGenerate::updateProgressBar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
