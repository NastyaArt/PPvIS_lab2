/****************************************************************************
** Meta object code from reading C++ file 'delwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../delwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'delwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DelWindow_t {
    QByteArrayData data[16];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DelWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DelWindow_t qt_meta_stringdata_DelWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DelWindow"
QT_MOC_LITERAL(1, 10, 12), // "SendDataDel1"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "surname"
QT_MOC_LITERAL(4, 32, 5), // "gpoup"
QT_MOC_LITERAL(5, 38, 12), // "SendDataDel2"
QT_MOC_LITERAL(6, 51, 4), // "work"
QT_MOC_LITERAL(7, 56, 12), // "SendDataDel3"
QT_MOC_LITERAL(8, 69, 7), // "timemin"
QT_MOC_LITERAL(9, 77, 7), // "timemax"
QT_MOC_LITERAL(10, 85, 14), // "PushButtonDel1"
QT_MOC_LITERAL(11, 100, 14), // "PushButtonClr1"
QT_MOC_LITERAL(12, 115, 14), // "PushButtonDel2"
QT_MOC_LITERAL(13, 130, 14), // "PushButtonClr2"
QT_MOC_LITERAL(14, 145, 14), // "PushButtonDel3"
QT_MOC_LITERAL(15, 160, 14) // "PushButtonClr3"

    },
    "DelWindow\0SendDataDel1\0\0surname\0gpoup\0"
    "SendDataDel2\0work\0SendDataDel3\0timemin\0"
    "timemax\0PushButtonDel1\0PushButtonClr1\0"
    "PushButtonDel2\0PushButtonClr2\0"
    "PushButtonDel3\0PushButtonClr3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DelWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       5,    2,   64,    2, 0x06 /* Public */,
       7,    4,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    8,    9,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DelWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DelWindow *_t = static_cast<DelWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendDataDel1((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SendDataDel2((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->SendDataDel3((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->PushButtonDel1(); break;
        case 4: _t->PushButtonClr1(); break;
        case 5: _t->PushButtonDel2(); break;
        case 6: _t->PushButtonClr2(); break;
        case 7: _t->PushButtonDel3(); break;
        case 8: _t->PushButtonClr3(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DelWindow::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DelWindow::SendDataDel1)) {
                *result = 0;
            }
        }
        {
            typedef void (DelWindow::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DelWindow::SendDataDel2)) {
                *result = 1;
            }
        }
        {
            typedef void (DelWindow::*_t)(QString , int , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DelWindow::SendDataDel3)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject DelWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DelWindow.data,
      qt_meta_data_DelWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DelWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DelWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DelWindow.stringdata0))
        return static_cast<void*>(const_cast< DelWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int DelWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DelWindow::SendDataDel1(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DelWindow::SendDataDel2(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DelWindow::SendDataDel3(QString _t1, int _t2, int _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
