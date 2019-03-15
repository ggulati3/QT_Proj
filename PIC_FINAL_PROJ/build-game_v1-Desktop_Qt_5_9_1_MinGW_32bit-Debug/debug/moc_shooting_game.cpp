/****************************************************************************
** Meta object code from reading C++ file 'shooting_game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../game_v6_final/shooting_game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shooting_game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_player_t {
    QByteArrayData data[3];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_player_t qt_meta_stringdata_player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "player"
QT_MOC_LITERAL(1, 7, 5), // "spawn"
QT_MOC_LITERAL(2, 13, 0) // ""

    },
    "player\0spawn\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        player *_t = static_cast<player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->spawn(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject player::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_player.data,
      qt_meta_data_player,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_player.stringdata0))
        return static_cast<void*>(const_cast< player*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< player*>(this));
    return QObject::qt_metacast(_clname);
}

int player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_shooting_game_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_shooting_game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_shooting_game_t qt_meta_stringdata_shooting_game = {
    {
QT_MOC_LITERAL(0, 0, 13), // "shooting_game"
QT_MOC_LITERAL(1, 14, 8), // "won_game"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "lose_game"
QT_MOC_LITERAL(4, 34, 17) // "update_scoreboard"

    },
    "shooting_game\0won_game\0\0lose_game\0"
    "update_scoreboard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_shooting_game[] = {

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
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void shooting_game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        shooting_game *_t = static_cast<shooting_game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->won_game(); break;
        case 1: _t->lose_game(); break;
        case 2: _t->update_scoreboard(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (shooting_game::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&shooting_game::won_game)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (shooting_game::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&shooting_game::lose_game)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject shooting_game::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_shooting_game.data,
      qt_meta_data_shooting_game,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *shooting_game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *shooting_game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_shooting_game.stringdata0))
        return static_cast<void*>(const_cast< shooting_game*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int shooting_game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void shooting_game::won_game()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void shooting_game::lose_game()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_bullet_t {
    QByteArrayData data[3];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_bullet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_bullet_t qt_meta_stringdata_bullet = {
    {
QT_MOC_LITERAL(0, 0, 6), // "bullet"
QT_MOC_LITERAL(1, 7, 4), // "move"
QT_MOC_LITERAL(2, 12, 0) // ""

    },
    "bullet\0move\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bullet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void bullet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        bullet *_t = static_cast<bullet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->move(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject bullet::staticMetaObject = {
    { &player::staticMetaObject, qt_meta_stringdata_bullet.data,
      qt_meta_data_bullet,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *bullet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bullet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bullet.stringdata0))
        return static_cast<void*>(const_cast< bullet*>(this));
    return player::qt_metacast(_clname);
}

int bullet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = player::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_enemy_t {
    QByteArrayData data[3];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_enemy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_enemy_t qt_meta_stringdata_enemy = {
    {
QT_MOC_LITERAL(0, 0, 5), // "enemy"
QT_MOC_LITERAL(1, 6, 4), // "move"
QT_MOC_LITERAL(2, 11, 0) // ""

    },
    "enemy\0move\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_enemy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void enemy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        enemy *_t = static_cast<enemy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->move(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject enemy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_enemy.data,
      qt_meta_data_enemy,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *enemy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *enemy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_enemy.stringdata0))
        return static_cast<void*>(const_cast< enemy*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< enemy*>(this));
    return QObject::qt_metacast(_clname);
}

int enemy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
