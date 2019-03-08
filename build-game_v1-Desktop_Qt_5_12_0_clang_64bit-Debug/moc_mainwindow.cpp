/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../final_game/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "wait_for_gameone"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "go_to_gameone"
QT_MOC_LITERAL(4, 43, 16), // "wait_for_gametwo"
QT_MOC_LITERAL(5, 60, 13), // "go_to_gametwo"
QT_MOC_LITERAL(6, 74, 18), // "wait_for_gamethree"
QT_MOC_LITERAL(7, 93, 15), // "go_to_gamethree"
QT_MOC_LITERAL(8, 109, 10), // "go_to_main"
QT_MOC_LITERAL(9, 120, 11), // "win_gameone"
QT_MOC_LITERAL(10, 132, 11), // "win_gametwo"
QT_MOC_LITERAL(11, 144, 22), // "waitmore_for_gamethree"
QT_MOC_LITERAL(12, 167, 13), // "win_gamethree"
QT_MOC_LITERAL(13, 181, 14), // "go_to_losepage"
QT_MOC_LITERAL(14, 196, 8), // "turn_off"
QT_MOC_LITERAL(15, 205, 9), // "lose_life"
QT_MOC_LITERAL(16, 215, 14), // "wait_for_lose1"
QT_MOC_LITERAL(17, 230, 12), // "lose_gameone"
QT_MOC_LITERAL(18, 243, 12), // "lose_gametwo"
QT_MOC_LITERAL(19, 256, 14) // "wait_for_lose2"

    },
    "MainWindow\0wait_for_gameone\0\0go_to_gameone\0"
    "wait_for_gametwo\0go_to_gametwo\0"
    "wait_for_gamethree\0go_to_gamethree\0"
    "go_to_main\0win_gameone\0win_gametwo\0"
    "waitmore_for_gamethree\0win_gamethree\0"
    "go_to_losepage\0turn_off\0lose_life\0"
    "wait_for_lose1\0lose_gameone\0lose_gametwo\0"
    "wait_for_lose2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    0,  120,    2, 0x0a /* Public */,
      19,    0,  121,    2, 0x0a /* Public */,

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
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->wait_for_gameone(); break;
        case 1: _t->go_to_gameone(); break;
        case 2: _t->wait_for_gametwo(); break;
        case 3: _t->go_to_gametwo(); break;
        case 4: _t->wait_for_gamethree(); break;
        case 5: _t->go_to_gamethree(); break;
        case 6: _t->go_to_main(); break;
        case 7: _t->win_gameone(); break;
        case 8: _t->win_gametwo(); break;
        case 9: _t->waitmore_for_gamethree(); break;
        case 10: _t->win_gamethree(); break;
        case 11: _t->go_to_losepage(); break;
        case 12: _t->turn_off(); break;
        case 13: _t->lose_life(); break;
        case 14: _t->wait_for_lose1(); break;
        case 15: _t->lose_gameone(); break;
        case 16: _t->lose_gametwo(); break;
        case 17: _t->wait_for_lose2(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
