/****************************************************************************
** Meta object code from reading C++ file 'MainAppWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainAppWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainAppWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainApp__MainAppWidget_t {
    QByteArrayData data[14];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainApp__MainAppWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainApp__MainAppWidget_t qt_meta_stringdata_mainApp__MainAppWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "mainApp::MainAppWidget"
QT_MOC_LITERAL(1, 23, 16), // "sgnShowNotifyDlg"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "QString&"
QT_MOC_LITERAL(4, 50, 9), // "strNotify"
QT_MOC_LITERAL(5, 60, 21), // "OnCurrentIndexChanged"
QT_MOC_LITERAL(6, 82, 6), // "nIndex"
QT_MOC_LITERAL(7, 89, 18), // "OnSearchBtnClicked"
QT_MOC_LITERAL(8, 108, 13), // "strSearchWord"
QT_MOC_LITERAL(9, 122, 18), // "OnConfigWidgetShow"
QT_MOC_LITERAL(10, 141, 15), // "OnShowNotifyDlg"
QT_MOC_LITERAL(11, 157, 12), // "OnConnectSQL"
QT_MOC_LITERAL(12, 170, 17), // "SQLConnectInfo_s&"
QT_MOC_LITERAL(13, 188, 4) // "info"

    },
    "mainApp::MainAppWidget\0sgnShowNotifyDlg\0"
    "\0QString&\0strNotify\0OnCurrentIndexChanged\0"
    "nIndex\0OnSearchBtnClicked\0strSearchWord\0"
    "OnConfigWidgetShow\0OnShowNotifyDlg\0"
    "OnConnectSQL\0SQLConnectInfo_s&\0info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainApp__MainAppWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,
      10,    1,   54,    2, 0x08 /* Private */,
      11,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void mainApp::MainAppWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainAppWidget *_t = static_cast<MainAppWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sgnShowNotifyDlg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OnCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnSearchBtnClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->OnConfigWidgetShow(); break;
        case 4: _t->OnShowNotifyDlg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->OnConnectSQL((*reinterpret_cast< SQLConnectInfo_s(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainAppWidget::*_t)(QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainAppWidget::sgnShowNotifyDlg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject mainApp::MainAppWidget::staticMetaObject = {
    { &DSGUI::DSDialog::staticMetaObject, qt_meta_stringdata_mainApp__MainAppWidget.data,
      qt_meta_data_mainApp__MainAppWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mainApp::MainAppWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainApp::MainAppWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mainApp__MainAppWidget.stringdata0))
        return static_cast<void*>(const_cast< MainAppWidget*>(this));
    return DSGUI::DSDialog::qt_metacast(_clname);
}

int mainApp::MainAppWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DSGUI::DSDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void mainApp::MainAppWidget::sgnShowNotifyDlg(QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
