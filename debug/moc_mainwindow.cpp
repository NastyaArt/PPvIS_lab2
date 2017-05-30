/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "SaveDataBase"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "filename"
QT_MOC_LITERAL(4, 34, 14), // "UploadDataBase"
QT_MOC_LITERAL(5, 49, 11), // "GetDataBase"
QT_MOC_LITERAL(6, 61, 13), // "ClearDataBase"
QT_MOC_LITERAL(7, 75, 10), // "UpdateData"
QT_MOC_LITERAL(8, 86, 14), // "QList<Student>"
QT_MOC_LITERAL(9, 101, 8), // "database"
QT_MOC_LITERAL(10, 110, 14), // "PushButtonSave"
QT_MOC_LITERAL(11, 125, 9), // "SaveState"
QT_MOC_LITERAL(12, 135, 2), // "ok"
QT_MOC_LITERAL(13, 138, 11), // "UploadState"
QT_MOC_LITERAL(14, 150, 8), // "DelState"
QT_MOC_LITERAL(15, 159, 6), // "colStd"
QT_MOC_LITERAL(16, 166, 15), // "DataBaseIsClear"
QT_MOC_LITERAL(17, 182, 14), // "PushButtonUpld"
QT_MOC_LITERAL(18, 197, 15), // "PushButtonClear"
QT_MOC_LITERAL(19, 213, 10), // "AddStudent"
QT_MOC_LITERAL(20, 224, 10), // "DelStudent"
QT_MOC_LITERAL(21, 235, 11) // "SrchStudent"

    },
    "MainWindow\0SaveDataBase\0\0filename\0"
    "UploadDataBase\0GetDataBase\0ClearDataBase\0"
    "UpdateData\0QList<Student>\0database\0"
    "PushButtonSave\0SaveState\0ok\0UploadState\0"
    "DelState\0colStd\0DataBaseIsClear\0"
    "PushButtonUpld\0PushButtonClear\0"
    "AddStudent\0DelStudent\0SrchStudent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    0,   95,    2, 0x06 /* Public */,
       6,    0,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   97,    2, 0x08 /* Private */,
      10,    0,  100,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,
      20,    0,  114,    2, 0x08 /* Private */,
      21,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Int,   15,
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
        case 0: _t->SaveDataBase((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->UploadDataBase((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->GetDataBase(); break;
        case 3: _t->ClearDataBase(); break;
        case 4: _t->UpdateData((*reinterpret_cast< QList<Student>(*)>(_a[1]))); break;
        case 5: _t->PushButtonSave(); break;
        case 6: _t->SaveState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->UploadState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->DelState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->DataBaseIsClear(); break;
        case 10: _t->PushButtonUpld(); break;
        case 11: _t->PushButtonClear(); break;
        case 12: _t->AddStudent(); break;
        case 13: _t->DelStudent(); break;
        case 14: _t->SrchStudent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SaveDataBase)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::UploadDataBase)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::GetDataBase)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ClearDataBase)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::SaveDataBase(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::UploadDataBase(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::GetDataBase()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::ClearDataBase()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
