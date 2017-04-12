/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[448];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 29), // "on_factorPrimesButton_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 64, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 88, 27), // "on_random_composite_clicked"
QT_MOC_LITERAL(6, 116, 21), // "on_hashButton_clicked"
QT_MOC_LITERAL(7, 138, 27), // "on_randomSaltButton_clicked"
QT_MOC_LITERAL(8, 166, 22), // "on_crackButton_clicked"
QT_MOC_LITERAL(9, 189, 19), // "update_crack_result"
QT_MOC_LITERAL(10, 209, 20), // "update_factor_result"
QT_MOC_LITERAL(11, 230, 24), // "on_drawFactoring_clicked"
QT_MOC_LITERAL(12, 255, 19), // "update_factor_graph"
QT_MOC_LITERAL(13, 275, 26), // "on_plotCrackButton_clicked"
QT_MOC_LITERAL(14, 302, 18), // "update_crack_graph"
QT_MOC_LITERAL(15, 321, 31), // "on_hashLogScaleCheckBox_clicked"
QT_MOC_LITERAL(16, 353, 33), // "on_factorLogScaleCheckBox_cli..."
QT_MOC_LITERAL(17, 387, 28), // "on_cancelCrackButton_clicked"
QT_MOC_LITERAL(18, 416, 31) // "on_stopFactorPushButton_clicked"

    },
    "MainWindow\0on_factorPrimesButton_clicked\0"
    "\0on_pushButton_clicked\0on_pushButton_3_clicked\0"
    "on_random_composite_clicked\0"
    "on_hashButton_clicked\0on_randomSaltButton_clicked\0"
    "on_crackButton_clicked\0update_crack_result\0"
    "update_factor_result\0on_drawFactoring_clicked\0"
    "update_factor_graph\0on_plotCrackButton_clicked\0"
    "update_crack_graph\0on_hashLogScaleCheckBox_clicked\0"
    "on_factorLogScaleCheckBox_clicked\0"
    "on_cancelCrackButton_clicked\0"
    "on_stopFactorPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_factorPrimesButton_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_random_composite_clicked(); break;
        case 4: _t->on_hashButton_clicked(); break;
        case 5: _t->on_randomSaltButton_clicked(); break;
        case 6: _t->on_crackButton_clicked(); break;
        case 7: _t->update_crack_result(); break;
        case 8: _t->update_factor_result(); break;
        case 9: _t->on_drawFactoring_clicked(); break;
        case 10: _t->update_factor_graph(); break;
        case 11: _t->on_plotCrackButton_clicked(); break;
        case 12: _t->update_crack_graph(); break;
        case 13: _t->on_hashLogScaleCheckBox_clicked(); break;
        case 14: _t->on_factorLogScaleCheckBox_clicked(); break;
        case 15: _t->on_cancelCrackButton_clicked(); break;
        case 16: _t->on_stopFactorPushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
