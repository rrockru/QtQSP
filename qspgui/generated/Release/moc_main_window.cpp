/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\src\main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ui__MainWindow_t {
    QByteArrayData data[16];
    char stringdata[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Ui__MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Ui__MainWindow_t qt_meta_stringdata_Ui__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 10),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 13),
QT_MOC_LITERAL(4, 41, 15),
QT_MOC_LITERAL(5, 57, 10),
QT_MOC_LITERAL(6, 68, 9),
QT_MOC_LITERAL(7, 78, 7),
QT_MOC_LITERAL(8, 86, 16),
QT_MOC_LITERAL(9, 103, 15),
QT_MOC_LITERAL(10, 119, 15),
QT_MOC_LITERAL(11, 135, 19),
QT_MOC_LITERAL(12, 155, 14),
QT_MOC_LITERAL(13, 170, 14),
QT_MOC_LITERAL(14, 185, 16),
QT_MOC_LITERAL(15, 202, 13)
    },
    "Ui::MainWindow\0OnOpenGame\0\0OnRestartGame\0"
    "OnOpenSavedGame\0OnSaveGame\0OnOptions\0"
    "OnAbout\0OnToggleCaptions\0OnToggleHotkeys\0"
    "OnToggleWinMode\0OnChangeSoundVolume\0"
    "OnActionChange\0OnObjectChange\0"
    "OnActionDblClick\0OnLinkClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ui__MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08,
       3,    0,   85,    2, 0x08,
       4,    0,   86,    2, 0x08,
       5,    0,   87,    2, 0x08,
       6,    0,   88,    2, 0x08,
       7,    0,   89,    2, 0x08,
       8,    0,   90,    2, 0x08,
       9,    0,   91,    2, 0x08,
      10,    0,   92,    2, 0x08,
      11,    0,   93,    2, 0x08,
      12,    0,   94,    2, 0x08,
      13,    0,   95,    2, 0x08,
      14,    0,   96,    2, 0x08,
      15,    2,   97,    2, 0x08,

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
    QMetaType::Void, QMetaType::QString, QMetaType::QPoint,    2,    2,

       0        // eod
};

void Ui::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->OnOpenGame(); break;
        case 1: _t->OnRestartGame(); break;
        case 2: _t->OnOpenSavedGame(); break;
        case 3: _t->OnSaveGame(); break;
        case 4: _t->OnOptions(); break;
        case 5: _t->OnAbout(); break;
        case 6: _t->OnToggleCaptions(); break;
        case 7: _t->OnToggleHotkeys(); break;
        case 8: _t->OnToggleWinMode(); break;
        case 9: _t->OnChangeSoundVolume(); break;
        case 10: _t->OnActionChange(); break;
        case 11: _t->OnObjectChange(); break;
        case 12: _t->OnActionDblClick(); break;
        case 13: _t->OnLinkClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Ui::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Ui__MainWindow.data,
      qt_meta_data_Ui__MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *Ui::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ui::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui__MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Ui::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
