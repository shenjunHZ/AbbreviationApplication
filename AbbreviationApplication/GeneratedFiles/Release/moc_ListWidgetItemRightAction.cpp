/****************************************************************************
** Meta object code from reading C++ file 'ListWidgetItemRightAction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ListWidgetItemRightAction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListWidgetItemRightAction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainApp__ListWidgetItemRightAction_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainApp__ListWidgetItemRightAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainApp__ListWidgetItemRightAction_t qt_meta_stringdata_mainApp__ListWidgetItemRightAction = {
    {
QT_MOC_LITERAL(0, 0, 34), // "mainApp::ListWidgetItemRightA..."
QT_MOC_LITERAL(1, 35, 19), // "sgnDeleteDefinition"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 8), // "uint64_t"
QT_MOC_LITERAL(4, 65, 11), // "iPrimaryKey"
QT_MOC_LITERAL(5, 77, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 94, 5) // "pItem"

    },
    "mainApp::ListWidgetItemRightAction\0"
    "sgnDeleteDefinition\0\0uint64_t\0iPrimaryKey\0"
    "QListWidgetItem*\0pItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainApp__ListWidgetItemRightAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void mainApp::ListWidgetItemRightAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListWidgetItemRightAction *_t = static_cast<ListWidgetItemRightAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sgnDeleteDefinition((*reinterpret_cast< uint64_t(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ListWidgetItemRightAction::*_t)(uint64_t , QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListWidgetItemRightAction::sgnDeleteDefinition)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject mainApp::ListWidgetItemRightAction::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_mainApp__ListWidgetItemRightAction.data,
      qt_meta_data_mainApp__ListWidgetItemRightAction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mainApp::ListWidgetItemRightAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainApp::ListWidgetItemRightAction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mainApp__ListWidgetItemRightAction.stringdata0))
        return static_cast<void*>(const_cast< ListWidgetItemRightAction*>(this));
    return QObject::qt_metacast(_clname);
}

int mainApp::ListWidgetItemRightAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void mainApp::ListWidgetItemRightAction::sgnDeleteDefinition(uint64_t _t1, QListWidgetItem * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
