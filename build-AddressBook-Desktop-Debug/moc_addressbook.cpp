/****************************************************************************
** Meta object code from reading C++ file 'addressbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AddressBook/addressbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addressbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddressBook_t {
    QByteArrayData data[10];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddressBook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddressBook_t qt_meta_stringdata_AddressBook = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AddressBook"
QT_MOC_LITERAL(1, 12, 15), // "creationSuccess"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "creationError"
QT_MOC_LITERAL(4, 43, 4), // "type"
QT_MOC_LITERAL(5, 48, 13), // "deleteSuccess"
QT_MOC_LITERAL(6, 62, 13), // "createContact"
QT_MOC_LITERAL(7, 76, 15), // "getContactsList"
QT_MOC_LITERAL(8, 92, 5), // "split"
QT_MOC_LITERAL(9, 98, 13) // "deleteContact"

    },
    "AddressBook\0creationSuccess\0\0creationError\0"
    "type\0deleteSuccess\0createContact\0"
    "getContactsList\0split\0deleteContact"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddressBook[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    3,   54,    2, 0x02 /* Public */,
       7,    0,   61,    2, 0x02 /* Public */,
       8,    1,   62,    2, 0x02 /* Public */,
       9,    3,   65,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::QStringList,
    QMetaType::QStringList, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

       0        // eod
};

void AddressBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddressBook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->creationSuccess(); break;
        case 1: _t->creationError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->deleteSuccess(); break;
        case 3: _t->createContact((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: { QStringList _r = _t->getContactsList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QStringList _r = _t->split((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->deleteContact((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddressBook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddressBook::creationSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddressBook::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddressBook::creationError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AddressBook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddressBook::deleteSuccess)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddressBook::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AddressBook.data,
    qt_meta_data_AddressBook,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AddressBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddressBook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddressBook.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AddressBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AddressBook::creationSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AddressBook::creationError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AddressBook::deleteSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
