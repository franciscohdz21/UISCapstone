/****************************************************************************
** Meta object code from reading C++ file 'corelogic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../corelogic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'corelogic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CoreLogic_t {
    QByteArrayData data[38];
    char stringdata0[479];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CoreLogic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CoreLogic_t qt_meta_stringdata_CoreLogic = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CoreLogic"
QT_MOC_LITERAL(1, 10, 12), // "boardChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "pieceXChanged"
QT_MOC_LITERAL(4, 38, 13), // "pieceYChanged"
QT_MOC_LITERAL(5, 52, 19), // "dynamicPieceChanged"
QT_MOC_LITERAL(6, 72, 16), // "gameLevelChanged"
QT_MOC_LITERAL(7, 89, 32), // "dynamicPieceMovedDownOnceChanged"
QT_MOC_LITERAL(8, 122, 15), // "gameOverChanged"
QT_MOC_LITERAL(9, 138, 11), // "gameRunning"
QT_MOC_LITERAL(10, 150, 13), // "getBoardIndex"
QT_MOC_LITERAL(11, 164, 1), // "x"
QT_MOC_LITERAL(12, 166, 1), // "y"
QT_MOC_LITERAL(13, 168, 15), // "setPieceAtBoard"
QT_MOC_LITERAL(14, 184, 19), // "checkForCompleteRow"
QT_MOC_LITERAL(15, 204, 15), // "getCurrentPiece"
QT_MOC_LITERAL(16, 220, 15), // "setCurrentPiece"
QT_MOC_LITERAL(17, 236, 5), // "piece"
QT_MOC_LITERAL(18, 242, 9), // "resetGame"
QT_MOC_LITERAL(19, 252, 14), // "getRandomColor"
QT_MOC_LITERAL(20, 267, 11), // "canMoveLeft"
QT_MOC_LITERAL(21, 279, 12), // "canMoveRight"
QT_MOC_LITERAL(22, 292, 11), // "canMoveDown"
QT_MOC_LITERAL(23, 304, 9), // "canRotate"
QT_MOC_LITERAL(24, 314, 11), // "rotatePiece"
QT_MOC_LITERAL(25, 326, 13), // "movePieceDown"
QT_MOC_LITERAL(26, 340, 14), // "movePieceRight"
QT_MOC_LITERAL(27, 355, 13), // "movePieceLeft"
QT_MOC_LITERAL(28, 369, 10), // "resetPiece"
QT_MOC_LITERAL(29, 380, 10), // "startTimer"
QT_MOC_LITERAL(30, 391, 9), // "stopTimer"
QT_MOC_LITERAL(31, 401, 5), // "board"
QT_MOC_LITERAL(32, 407, 12), // "dynamicPiece"
QT_MOC_LITERAL(33, 420, 6), // "pieceX"
QT_MOC_LITERAL(34, 427, 6), // "pieceY"
QT_MOC_LITERAL(35, 434, 9), // "gameLevel"
QT_MOC_LITERAL(36, 444, 25), // "dynamicPieceMovedDownOnce"
QT_MOC_LITERAL(37, 470, 8) // "gameOver"

    },
    "CoreLogic\0boardChanged\0\0pieceXChanged\0"
    "pieceYChanged\0dynamicPieceChanged\0"
    "gameLevelChanged\0dynamicPieceMovedDownOnceChanged\0"
    "gameOverChanged\0gameRunning\0getBoardIndex\0"
    "x\0y\0setPieceAtBoard\0checkForCompleteRow\0"
    "getCurrentPiece\0setCurrentPiece\0piece\0"
    "resetGame\0getRandomColor\0canMoveLeft\0"
    "canMoveRight\0canMoveDown\0canRotate\0"
    "rotatePiece\0movePieceDown\0movePieceRight\0"
    "movePieceLeft\0resetPiece\0startTimer\0"
    "stopTimer\0board\0dynamicPiece\0pieceX\0"
    "pieceY\0gameLevel\0dynamicPieceMovedDownOnce\0"
    "gameOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoreLogic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       7,  176, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x06 /* Public */,
       3,    0,  145,    2, 0x06 /* Public */,
       4,    0,  146,    2, 0x06 /* Public */,
       5,    0,  147,    2, 0x06 /* Public */,
       6,    0,  148,    2, 0x06 /* Public */,
       7,    0,  149,    2, 0x06 /* Public */,
       8,    0,  150,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  151,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    2,  152,    2, 0x02 /* Public */,
      13,    0,  157,    2, 0x02 /* Public */,
      14,    0,  158,    2, 0x02 /* Public */,
      15,    0,  159,    2, 0x02 /* Public */,
      16,    1,  160,    2, 0x02 /* Public */,
      18,    0,  163,    2, 0x02 /* Public */,
      19,    0,  164,    2, 0x02 /* Public */,
      20,    0,  165,    2, 0x02 /* Public */,
      21,    0,  166,    2, 0x02 /* Public */,
      22,    0,  167,    2, 0x02 /* Public */,
      23,    0,  168,    2, 0x02 /* Public */,
      24,    0,  169,    2, 0x02 /* Public */,
      25,    0,  170,    2, 0x02 /* Public */,
      26,    0,  171,    2, 0x02 /* Public */,
      27,    0,  172,    2, 0x02 /* Public */,
      28,    0,  173,    2, 0x02 /* Public */,
      29,    0,  174,    2, 0x02 /* Public */,
      30,    0,  175,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int, QMetaType::Double, QMetaType::Double,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      31, QMetaType::QStringList, 0x00495103,
      32, QMetaType::QStringList, 0x00495103,
      33, QMetaType::Double, 0x00495103,
      34, QMetaType::Double, 0x00495103,
      35, QMetaType::Int, 0x00495103,
      36, QMetaType::Bool, 0x00495103,
      37, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       3,
       1,
       2,
       4,
       5,
       6,

       0        // eod
};

void CoreLogic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CoreLogic *_t = static_cast<CoreLogic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boardChanged(); break;
        case 1: _t->pieceXChanged(); break;
        case 2: _t->pieceYChanged(); break;
        case 3: _t->dynamicPieceChanged(); break;
        case 4: _t->gameLevelChanged(); break;
        case 5: _t->dynamicPieceMovedDownOnceChanged(); break;
        case 6: _t->gameOverChanged(); break;
        case 7: _t->gameRunning(); break;
        case 8: { int _r = _t->getBoardIndex((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setPieceAtBoard(); break;
        case 10: _t->checkForCompleteRow(); break;
        case 11: { int _r = _t->getCurrentPiece();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->setCurrentPiece((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->resetGame(); break;
        case 14: { QString _r = _t->getRandomColor();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->canMoveLeft();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->canMoveRight();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->canMoveDown();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->canRotate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->rotatePiece(); break;
        case 20: _t->movePieceDown(); break;
        case 21: _t->movePieceRight(); break;
        case 22: _t->movePieceLeft(); break;
        case 23: _t->resetPiece(); break;
        case 24: _t->startTimer(); break;
        case 25: _t->stopTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::boardChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::pieceXChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::pieceYChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::dynamicPieceChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::gameLevelChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::dynamicPieceMovedDownOnceChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::gameOverChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CoreLogic *_t = static_cast<CoreLogic *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->board(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->dynamicPiece(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->pieceX(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->pieceY(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->gameLevel(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->dynamicPieceMovedDownOnce(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->gameOver(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CoreLogic *_t = static_cast<CoreLogic *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBoard(*reinterpret_cast< QStringList*>(_v)); break;
        case 1: _t->setDynamicPiece(*reinterpret_cast< QStringList*>(_v)); break;
        case 2: _t->setPieceX(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setPieceY(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setGameLevel(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setDynamicPieceMovedDownOnce(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setGameOver(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject CoreLogic::staticMetaObject = {
    { &QTimer::staticMetaObject, qt_meta_stringdata_CoreLogic.data,
      qt_meta_data_CoreLogic,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CoreLogic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoreLogic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CoreLogic.stringdata0))
        return static_cast<void*>(this);
    return QTimer::qt_metacast(_clname);
}

int CoreLogic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CoreLogic::boardChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CoreLogic::pieceXChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CoreLogic::pieceYChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CoreLogic::dynamicPieceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CoreLogic::gameLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CoreLogic::dynamicPieceMovedDownOnceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CoreLogic::gameOverChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
