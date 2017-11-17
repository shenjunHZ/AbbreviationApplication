/****************************************************************************
** Meta object code from reading C++ file 'AbbreviationFunctionSearch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AbbreviationFunctionSearch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AbbreviationFunctionSearch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainApp__AbbreviationFunctionSearch_t {
    QByteArrayData data[8];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainApp__AbbreviationFunctionSearch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainApp__AbbreviationFunctionSearch_t qt_meta_stringdata_mainApp__AbbreviationFunctionSearch = {
    {
QT_MOC_LITERAL(0, 0, 35), // "mainApp::AbbreviationFunction..."
QT_MOC_LITERAL(1, 36, 18), // "OnDeleteDefinition"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 8), // "uint64_t"
QT_MOC_LITERAL(4, 65, 11), // "iPrimaryKey"
QT_MOC_LITERAL(5, 77, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 94, 5), // "pItem"
QT_MOC_LITERAL(7, 100, 19) // "OnItemDoubleClicked"

    },
    "mainApp::AbbreviationFunctionSearch\0"
    "OnDeleteDefinition\0\0uint64_t\0iPrimaryKey\0"
    "QListWidgetItem*\0pItem\0OnItemDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainApp__AbbreviationFunctionSearch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x08 /* Private */,
       7,    1,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void mainApp::AbbreviationFunctionSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbbreviationFunctionSearch *_t = static_cast<AbbreviationFunctionSearch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnDeleteDefinition((*reinterpret_cast< uint64_t(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 1: _t->OnItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject mainApp::AbbreviationFunctionSearch::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainApp__AbbreviationFunctionSearch.data,
      qt_meta_data_mainApp__AbbreviationFunctionSearch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mainApp::AbbreviationFunctionSearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainApp::AbbreviationFunctionSearch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mainApp__AbbreviationFunctionSearch.stringdata0))
        return static_cast<void*>(const_cast< AbbreviationFunctionSearch*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainApp::AbbreviationFunctionSearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
