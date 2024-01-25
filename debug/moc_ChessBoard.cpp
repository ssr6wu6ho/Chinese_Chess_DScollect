/****************************************************************************
** Meta object code from reading C++ file 'ChessBoard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ChessBoard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChessBoard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChessBoard_t {
    QByteArrayData data[18];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChessBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChessBoard_t qt_meta_stringdata_ChessBoard = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChessBoard"
QT_MOC_LITERAL(1, 11, 14), // "startAlphaBeta"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "int*"
QT_MOC_LITERAL(4, 32, 19), // "startAlphaBetaAndTT"
QT_MOC_LITERAL(5, 52, 15), // "QVector<Step*>&"
QT_MOC_LITERAL(6, 68, 24), // "startAlphaBetaAndHistory"
QT_MOC_LITERAL(7, 93, 19), // "startAlphaBeta_TTHH"
QT_MOC_LITERAL(8, 113, 16), // "startIDAlphaBeta"
QT_MOC_LITERAL(9, 130, 13), // "endComputerGo"
QT_MOC_LITERAL(10, 144, 9), // "startGame"
QT_MOC_LITERAL(11, 154, 6), // "goBack"
QT_MOC_LITERAL(12, 161, 11), // "rotateBoard"
QT_MOC_LITERAL(13, 173, 13), // "computerRelay"
QT_MOC_LITERAL(14, 187, 9), // "pauseGame"
QT_MOC_LITERAL(15, 197, 10), // "computerGo"
QT_MOC_LITERAL(16, 208, 5), // "Step*"
QT_MOC_LITERAL(17, 214, 12) // "doComputerGo"

    },
    "ChessBoard\0startAlphaBeta\0\0int*\0"
    "startAlphaBetaAndTT\0QVector<Step*>&\0"
    "startAlphaBetaAndHistory\0startAlphaBeta_TTHH\0"
    "startIDAlphaBeta\0endComputerGo\0startGame\0"
    "goBack\0rotateBoard\0computerRelay\0"
    "pauseGame\0computerGo\0Step*\0doComputerGo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChessBoard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   79,    2, 0x06 /* Public */,
       4,    6,   90,    2, 0x06 /* Public */,
       6,    5,  103,    2, 0x06 /* Public */,
       7,    6,  114,    2, 0x06 /* Public */,
       8,    6,  127,    2, 0x06 /* Public */,
       9,    0,  140,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  141,    2, 0x0a /* Public */,
      11,    0,  142,    2, 0x0a /* Public */,
      12,    0,  143,    2, 0x0a /* Public */,
      13,    0,  144,    2, 0x0a /* Public */,
      14,    0,  145,    2, 0x0a /* Public */,
      15,    1,  146,    2, 0x0a /* Public */,
      17,    0,  149,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int, 0x80000000 | 5,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int, 0x80000000 | 5,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int, 0x80000000 | 5,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void,

       0        // eod
};

void ChessBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChessBoard *_t = static_cast<ChessBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startAlphaBeta((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->startAlphaBetaAndTT((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QVector<Step*>(*)>(_a[6]))); break;
        case 2: _t->startAlphaBetaAndHistory((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->startAlphaBeta_TTHH((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QVector<Step*>(*)>(_a[6]))); break;
        case 4: _t->startIDAlphaBeta((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int*(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QVector<Step*>(*)>(_a[6]))); break;
        case 5: _t->endComputerGo(); break;
        case 6: _t->startGame(); break;
        case 7: _t->goBack(); break;
        case 8: _t->rotateBoard(); break;
        case 9: _t->computerRelay(); break;
        case 10: _t->pauseGame(); break;
        case 11: _t->computerGo((*reinterpret_cast< Step*(*)>(_a[1]))); break;
        case 12: _t->doComputerGo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ChessBoard::*_t)(int * , int * , int * , bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessBoard::startAlphaBeta)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)(int * , int * , int * , bool , int , QVector<Step*> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessBoard::startAlphaBetaAndTT)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)(int * , int * , int * , bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessBoard::startAlphaBetaAndHistory)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)(int * , int * , int * , bool , int , QVector<Step*> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessBoard::startAlphaBeta_TTHH)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)(int * , int * , int * , bool , int , QVector<Step*> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessBoard::startIDAlphaBeta)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessBoard::endComputerGo)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject ChessBoard::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ChessBoard.data,
      qt_meta_data_ChessBoard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChessBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChessBoard.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChessBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ChessBoard::startAlphaBeta(int * _t1, int * _t2, int * _t3, bool _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChessBoard::startAlphaBetaAndTT(int * _t1, int * _t2, int * _t3, bool _t4, int _t5, QVector<Step*> & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChessBoard::startAlphaBetaAndHistory(int * _t1, int * _t2, int * _t3, bool _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChessBoard::startAlphaBeta_TTHH(int * _t1, int * _t2, int * _t3, bool _t4, int _t5, QVector<Step*> & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ChessBoard::startIDAlphaBeta(int * _t1, int * _t2, int * _t3, bool _t4, int _t5, QVector<Step*> & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ChessBoard::endComputerGo()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
