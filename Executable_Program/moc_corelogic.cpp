/****************************************************************************
** Meta object code from reading C++ file 'corelogic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tetris/corelogic.h"
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
    QByteArrayData data[33];
    char stringdata0[387];
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
QT_MOC_LITERAL(5, 52, 17), // "pieceColorChanged"
QT_MOC_LITERAL(6, 70, 19), // "dynamicPieceChanged"
QT_MOC_LITERAL(7, 90, 11), // "gameRunning"
QT_MOC_LITERAL(8, 102, 13), // "getBoardIndex"
QT_MOC_LITERAL(9, 116, 1), // "x"
QT_MOC_LITERAL(10, 118, 1), // "y"
QT_MOC_LITERAL(11, 120, 15), // "setPieceAtBoard"
QT_MOC_LITERAL(12, 136, 19), // "checkForCompleteRow"
QT_MOC_LITERAL(13, 156, 15), // "getCurrentPiece"
QT_MOC_LITERAL(14, 172, 15), // "setCurrentPiece"
QT_MOC_LITERAL(15, 188, 5), // "piece"
QT_MOC_LITERAL(16, 194, 14), // "getRandomColor"
QT_MOC_LITERAL(17, 209, 11), // "canMoveLeft"
QT_MOC_LITERAL(18, 221, 12), // "canMoveRight"
QT_MOC_LITERAL(19, 234, 11), // "canMoveDown"
QT_MOC_LITERAL(20, 246, 9), // "canRotate"
QT_MOC_LITERAL(21, 256, 11), // "rotatePiece"
QT_MOC_LITERAL(22, 268, 13), // "movePieceDown"
QT_MOC_LITERAL(23, 282, 14), // "movePieceRight"
QT_MOC_LITERAL(24, 297, 13), // "movePieceLeft"
QT_MOC_LITERAL(25, 311, 10), // "resetPiece"
QT_MOC_LITERAL(26, 322, 10), // "startTimer"
QT_MOC_LITERAL(27, 333, 9), // "stopTimer"
QT_MOC_LITERAL(28, 343, 5), // "board"
QT_MOC_LITERAL(29, 349, 12), // "dynamicPiece"
QT_MOC_LITERAL(30, 362, 6), // "pieceX"
QT_MOC_LITERAL(31, 369, 6), // "pieceY"
QT_MOC_LITERAL(32, 376, 10) // "pieceColor"

    },
    "CoreLogic\0boardChanged\0\0pieceXChanged\0"
    "pieceYChanged\0pieceColorChanged\0"
    "dynamicPieceChanged\0gameRunning\0"
    "getBoardIndex\0x\0y\0setPieceAtBoard\0"
    "checkForCompleteRow\0getCurrentPiece\0"
    "setCurrentPiece\0piece\0getRandomColor\0"
    "canMoveLeft\0canMoveRight\0canMoveDown\0"
    "canRotate\0rotatePiece\0movePieceDown\0"
    "movePieceRight\0movePieceLeft\0resetPiece\0"
    "startTimer\0stopTimer\0board\0dynamicPiece\0"
    "pieceX\0pieceY\0pieceColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoreLogic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       5,  158, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x06 /* Public */,
       3,    0,  130,    2, 0x06 /* Public */,
       4,    0,  131,    2, 0x06 /* Public */,
       5,    0,  132,    2, 0x06 /* Public */,
       6,    0,  133,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  134,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    2,  135,    2, 0x02 /* Public */,
      11,    0,  140,    2, 0x02 /* Public */,
      12,    0,  141,    2, 0x02 /* Public */,
      13,    0,  142,    2, 0x02 /* Public */,
      14,    1,  143,    2, 0x02 /* Public */,
      16,    0,  146,    2, 0x02 /* Public */,
      17,    0,  147,    2, 0x02 /* Public */,
      18,    0,  148,    2, 0x02 /* Public */,
      19,    0,  149,    2, 0x02 /* Public */,
      20,    0,  150,    2, 0x02 /* Public */,
      21,    0,  151,    2, 0x02 /* Public */,
      22,    0,  152,    2, 0x02 /* Public */,
      23,    0,  153,    2, 0x02 /* Public */,
      24,    0,  154,    2, 0x02 /* Public */,
      25,    0,  155,    2, 0x02 /* Public */,
      26,    0,  156,    2, 0x02 /* Public */,
      27,    0,  157,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int, QMetaType::Double, QMetaType::Double,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   15,
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
      28, QMetaType::QStringList, 0x00495103,
      29, QMetaType::QStringList, 0x00495103,
      30, QMetaType::Double, 0x00495103,
      31, QMetaType::Double, 0x00495103,
      32, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       4,
       1,
       2,
       3,

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
        case 3: _t->pieceColorChanged(); break;
        case 4: _t->dynamicPieceChanged(); break;
        case 5: _t->gameRunning(); break;
        case 6: { int _r = _t->getBoardIndex((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setPieceAtBoard(); break;
        case 8: _t->checkForCompleteRow(); break;
        case 9: { int _r = _t->getCurrentPiece();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setCurrentPiece((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: { QString _r = _t->getRandomColor();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->canMoveLeft();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->canMoveRight();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->canMoveDown();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->canRotate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->rotatePiece(); break;
        case 17: _t->movePieceDown(); break;
        case 18: _t->movePieceRight(); break;
        case 19: _t->movePieceLeft(); break;
        case 20: _t->resetPiece(); break;
        case 21: _t->startTimer(); break;
        case 22: _t->stopTimer(); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::pieceColorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CoreLogic::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreLogic::dynamicPieceChanged)) {
                *result = 4;
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
        case 4: *reinterpret_cast< QString*>(_v) = _t->pieceColor(); break;
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
        case 4: _t->setPieceColor(*reinterpret_cast< QString*>(_v)); break;
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
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
void CoreLogic::pieceColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CoreLogic::dynamicPieceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
