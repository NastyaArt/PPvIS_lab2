/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataBase_t {
    QByteArrayData data[34];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBase_t qt_meta_stringdata_DataBase = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DataBase"
QT_MOC_LITERAL(1, 9, 12), // "SendDataBase"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "QList<Student>"
QT_MOC_LITERAL(4, 38, 8), // "database"
QT_MOC_LITERAL(5, 47, 9), // "SaveState"
QT_MOC_LITERAL(6, 57, 2), // "ok"
QT_MOC_LITERAL(7, 60, 11), // "UploadState"
QT_MOC_LITERAL(8, 72, 15), // "DataBaseIsClear"
QT_MOC_LITERAL(9, 88, 8), // "DelState"
QT_MOC_LITERAL(10, 97, 6), // "colStd"
QT_MOC_LITERAL(11, 104, 9), // "SrchState"
QT_MOC_LITERAL(12, 114, 12), // "SendDataSrch"
QT_MOC_LITERAL(13, 127, 8), // "students"
QT_MOC_LITERAL(14, 136, 13), // "ClearDataBase"
QT_MOC_LITERAL(15, 150, 14), // "RecieveDataAdd"
QT_MOC_LITERAL(16, 165, 7), // "Student"
QT_MOC_LITERAL(17, 173, 3), // "std"
QT_MOC_LITERAL(18, 177, 12), // "SaveDataBase"
QT_MOC_LITERAL(19, 190, 8), // "filename"
QT_MOC_LITERAL(20, 199, 14), // "UploadDataBase"
QT_MOC_LITERAL(21, 214, 15), // "RecieveDataDel1"
QT_MOC_LITERAL(22, 230, 3), // "fio"
QT_MOC_LITERAL(23, 234, 5), // "group"
QT_MOC_LITERAL(24, 240, 15), // "RecieveDataDel2"
QT_MOC_LITERAL(25, 256, 7), // "surname"
QT_MOC_LITERAL(26, 264, 4), // "work"
QT_MOC_LITERAL(27, 269, 15), // "RecieveDataDel3"
QT_MOC_LITERAL(28, 285, 7), // "timemin"
QT_MOC_LITERAL(29, 293, 7), // "timemax"
QT_MOC_LITERAL(30, 301, 16), // "RecieveDataSrch1"
QT_MOC_LITERAL(31, 318, 16), // "RecieveDataSrch2"
QT_MOC_LITERAL(32, 335, 16), // "RecieveDataSrch3"
QT_MOC_LITERAL(33, 352, 11) // "GetDataBase"

    },
    "DataBase\0SendDataBase\0\0QList<Student>\0"
    "database\0SaveState\0ok\0UploadState\0"
    "DataBaseIsClear\0DelState\0colStd\0"
    "SrchState\0SendDataSrch\0students\0"
    "ClearDataBase\0RecieveDataAdd\0Student\0"
    "std\0SaveDataBase\0filename\0UploadDataBase\0"
    "RecieveDataDel1\0fio\0group\0RecieveDataDel2\0"
    "surname\0work\0RecieveDataDel3\0timemin\0"
    "timemax\0RecieveDataSrch1\0RecieveDataSrch2\0"
    "RecieveDataSrch3\0GetDataBase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       7,    1,  110,    2, 0x06 /* Public */,
       8,    0,  113,    2, 0x06 /* Public */,
       9,    1,  114,    2, 0x06 /* Public */,
      11,    1,  117,    2, 0x06 /* Public */,
      12,    1,  120,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  123,    2, 0x0a /* Public */,
      15,    1,  124,    2, 0x0a /* Public */,
      18,    1,  127,    2, 0x0a /* Public */,
      20,    1,  130,    2, 0x0a /* Public */,
      21,    2,  133,    2, 0x0a /* Public */,
      24,    2,  138,    2, 0x0a /* Public */,
      27,    4,  143,    2, 0x0a /* Public */,
      30,    2,  152,    2, 0x0a /* Public */,
      31,    2,  157,    2, 0x0a /* Public */,
      32,    4,  162,    2, 0x0a /* Public */,
      33,    0,  171,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 3,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   22,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString,   25,   28,   29,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   22,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString,   25,   28,   29,   26,
    QMetaType::Void,

       0        // eod
};

void DataBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataBase *_t = static_cast<DataBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendDataBase((*reinterpret_cast< QList<Student>(*)>(_a[1]))); break;
        case 1: _t->SaveState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->UploadState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->DataBaseIsClear(); break;
        case 4: _t->DelState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SrchState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SendDataSrch((*reinterpret_cast< QList<Student>(*)>(_a[1]))); break;
        case 7: _t->ClearDataBase(); break;
        case 8: _t->RecieveDataAdd((*reinterpret_cast< Student(*)>(_a[1]))); break;
        case 9: _t->SaveDataBase((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->UploadDataBase((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->RecieveDataDel1((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->RecieveDataDel2((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->RecieveDataDel3((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 14: _t->RecieveDataSrch1((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->RecieveDataSrch2((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: _t->RecieveDataSrch3((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 17: _t->GetDataBase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataBase::*_t)(QList<Student> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBase::SendDataBase)) {
                *result = 0;
            }
        }
        {
            typedef void (DataBase::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBase::SaveState)) {
                *result = 1;
            }
        }
        {
            typedef void (DataBase::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBase::UploadState)) {
                *result = 2;
            }
        }
        {
            typedef void (DataBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBase::DataBaseIsClear)) {
                *result = 3;
            }
        }
        {
            typedef void (DataBase::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBase::DelState)) {
                *result = 4;
            }
        }
        {
            typedef void (DataBase::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBase::SrchState)) {
                *result = 5;
            }
        }
        {
            typedef void (DataBase::*_t)(QList<Student> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataBase::SendDataSrch)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject DataBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataBase.data,
      qt_meta_data_DataBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DataBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DataBase.stringdata0))
        return static_cast<void*>(const_cast< DataBase*>(this));
    return QObject::qt_metacast(_clname);
}

int DataBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void DataBase::SendDataBase(QList<Student> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataBase::SaveState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataBase::UploadState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataBase::DataBaseIsClear()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DataBase::DelState(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DataBase::SrchState(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DataBase::SendDataSrch(QList<Student> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
