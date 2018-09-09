/****************************************************************************
** Meta object code from reading C++ file 'tabdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KalkHead/tabdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TabDialog_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabDialog_t qt_meta_stringdata_TabDialog = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TabDialog"
QT_MOC_LITERAL(1, 10, 11), // "helpPressed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "errInputSlot"
QT_MOC_LITERAL(4, 36, 17), // "errSecondTreeSlot"
QT_MOC_LITERAL(5, 54, 18), // "triggerHuffmanTest"
QT_MOC_LITERAL(6, 73, 11), // "errNodeSlot"
QT_MOC_LITERAL(7, 85, 11), // "errTreeSlot"
QT_MOC_LITERAL(8, 97, 10) // "errDelSlot"

    },
    "TabDialog\0helpPressed\0\0errInputSlot\0"
    "errSecondTreeSlot\0triggerHuffmanTest\0"
    "errNodeSlot\0errTreeSlot\0errDelSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TabDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabDialog *_t = static_cast<TabDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->helpPressed(); break;
        case 1: _t->errInputSlot(); break;
        case 2: _t->errSecondTreeSlot(); break;
        case 3: _t->triggerHuffmanTest(); break;
        case 4: _t->errNodeSlot(); break;
        case 5: _t->errTreeSlot(); break;
        case 6: _t->errDelSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TabDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TabDialog.data,
      qt_meta_data_TabDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TabDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TabDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TabDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_Tab_t {
    QByteArrayData data[18];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tab_t qt_meta_stringdata_Tab = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Tab"
QT_MOC_LITERAL(1, 4, 12), // "auxiliaryIns"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 13), // "auxiliaryLine"
QT_MOC_LITERAL(4, 32, 12), // "auxiliaryDel"
QT_MOC_LITERAL(5, 45, 15), // "auxiliarySearch"
QT_MOC_LITERAL(6, 61, 12), // "auxiliaryMax"
QT_MOC_LITERAL(7, 74, 12), // "auxiliaryMin"
QT_MOC_LITERAL(8, 87, 13), // "auxiliaryDelT"
QT_MOC_LITERAL(9, 101, 14), // "auxiliaryShowT"
QT_MOC_LITERAL(10, 116, 13), // "insertClicked"
QT_MOC_LITERAL(11, 130, 11), // "linePressed"
QT_MOC_LITERAL(12, 142, 13), // "deleteClicked"
QT_MOC_LITERAL(13, 156, 13), // "searchClicked"
QT_MOC_LITERAL(14, 170, 10), // "maxClicked"
QT_MOC_LITERAL(15, 181, 10), // "minClicked"
QT_MOC_LITERAL(16, 192, 17), // "deleteTreeClicked"
QT_MOC_LITERAL(17, 210, 15) // "showTreeClicked"

    },
    "Tab\0auxiliaryIns\0\0auxiliaryLine\0"
    "auxiliaryDel\0auxiliarySearch\0auxiliaryMax\0"
    "auxiliaryMin\0auxiliaryDelT\0auxiliaryShowT\0"
    "insertClicked\0linePressed\0deleteClicked\0"
    "searchClicked\0maxClicked\0minClicked\0"
    "deleteTreeClicked\0showTreeClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,
       7,    0,   99,    2, 0x06 /* Public */,
       8,    0,  100,    2, 0x06 /* Public */,
       9,    0,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tab *_t = static_cast<Tab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->auxiliaryIns(); break;
        case 1: _t->auxiliaryLine(); break;
        case 2: _t->auxiliaryDel(); break;
        case 3: _t->auxiliarySearch(); break;
        case 4: _t->auxiliaryMax(); break;
        case 5: _t->auxiliaryMin(); break;
        case 6: _t->auxiliaryDelT(); break;
        case 7: _t->auxiliaryShowT(); break;
        case 8: _t->insertClicked(); break;
        case 9: _t->linePressed(); break;
        case 10: _t->deleteClicked(); break;
        case 11: _t->searchClicked(); break;
        case 12: _t->maxClicked(); break;
        case 13: _t->minClicked(); break;
        case 14: _t->deleteTreeClicked(); break;
        case 15: _t->showTreeClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliaryIns)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliaryLine)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliaryDel)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliarySearch)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliaryMax)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliaryMin)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliaryDelT)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab::auxiliaryShowT)) {
                *result = 7;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tab.data,
      qt_meta_data_Tab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tab.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Tab::auxiliaryIns()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tab::auxiliaryLine()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Tab::auxiliaryDel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Tab::auxiliarySearch()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Tab::auxiliaryMax()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Tab::auxiliaryMin()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Tab::auxiliaryDelT()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Tab::auxiliaryShowT()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
struct qt_meta_stringdata_BinarySearchTab_t {
    QByteArrayData data[8];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BinarySearchTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BinarySearchTab_t qt_meta_stringdata_BinarySearchTab = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BinarySearchTab"
QT_MOC_LITERAL(1, 16, 13), // "auxiliaryKeep"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "auxiliaryPlus"
QT_MOC_LITERAL(4, 45, 14), // "auxiliaryMinus"
QT_MOC_LITERAL(5, 60, 11), // "keepClicked"
QT_MOC_LITERAL(6, 72, 11), // "plusClicked"
QT_MOC_LITERAL(7, 84, 12) // "minusClicked"

    },
    "BinarySearchTab\0auxiliaryKeep\0\0"
    "auxiliaryPlus\0auxiliaryMinus\0keepClicked\0"
    "plusClicked\0minusClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BinarySearchTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BinarySearchTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BinarySearchTab *_t = static_cast<BinarySearchTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->auxiliaryKeep(); break;
        case 1: _t->auxiliaryPlus(); break;
        case 2: _t->auxiliaryMinus(); break;
        case 3: _t->keepClicked(); break;
        case 4: _t->plusClicked(); break;
        case 5: _t->minusClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BinarySearchTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinarySearchTab::auxiliaryKeep)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BinarySearchTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinarySearchTab::auxiliaryPlus)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BinarySearchTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinarySearchTab::auxiliaryMinus)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BinarySearchTab::staticMetaObject = {
    { &Tab::staticMetaObject, qt_meta_stringdata_BinarySearchTab.data,
      qt_meta_data_BinarySearchTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BinarySearchTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BinarySearchTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BinarySearchTab.stringdata0))
        return static_cast<void*>(this);
    return Tab::qt_metacast(_clname);
}

int BinarySearchTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tab::qt_metacall(_c, _id, _a);
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
void BinarySearchTab::auxiliaryKeep()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BinarySearchTab::auxiliaryPlus()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BinarySearchTab::auxiliaryMinus()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_AvlTab_t {
    QByteArrayData data[6];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AvlTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AvlTab_t qt_meta_stringdata_AvlTab = {
    {
QT_MOC_LITERAL(0, 0, 6), // "AvlTab"
QT_MOC_LITERAL(1, 7, 16), // "auxiliarySubTPre"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "auxiliarySubTInv"
QT_MOC_LITERAL(4, 42, 14), // "subTPreClicked"
QT_MOC_LITERAL(5, 57, 14) // "subTInvClicked"

    },
    "AvlTab\0auxiliarySubTPre\0\0auxiliarySubTInv\0"
    "subTPreClicked\0subTInvClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AvlTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AvlTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AvlTab *_t = static_cast<AvlTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->auxiliarySubTPre(); break;
        case 1: _t->auxiliarySubTInv(); break;
        case 2: _t->subTPreClicked(); break;
        case 3: _t->subTInvClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AvlTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AvlTab::auxiliarySubTPre)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AvlTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AvlTab::auxiliarySubTInv)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AvlTab::staticMetaObject = {
    { &Tab::staticMetaObject, qt_meta_stringdata_AvlTab.data,
      qt_meta_data_AvlTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AvlTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AvlTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AvlTab.stringdata0))
        return static_cast<void*>(this);
    return Tab::qt_metacast(_clname);
}

int AvlTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tab::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AvlTab::auxiliarySubTPre()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AvlTab::auxiliarySubTInv()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_HuffmanTab_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HuffmanTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HuffmanTab_t qt_meta_stringdata_HuffmanTab = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HuffmanTab"
QT_MOC_LITERAL(1, 11, 13), // "auxiliaryKeep"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "auxiliaryPlus"
QT_MOC_LITERAL(4, 40, 17), // "auxiliaryCompress"
QT_MOC_LITERAL(5, 58, 11), // "keepClicked"
QT_MOC_LITERAL(6, 70, 11), // "plusClicked"
QT_MOC_LITERAL(7, 82, 15) // "compressClicked"

    },
    "HuffmanTab\0auxiliaryKeep\0\0auxiliaryPlus\0"
    "auxiliaryCompress\0keepClicked\0plusClicked\0"
    "compressClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HuffmanTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HuffmanTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HuffmanTab *_t = static_cast<HuffmanTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->auxiliaryKeep(); break;
        case 1: _t->auxiliaryPlus(); break;
        case 2: _t->auxiliaryCompress(); break;
        case 3: _t->keepClicked(); break;
        case 4: _t->plusClicked(); break;
        case 5: _t->compressClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (HuffmanTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HuffmanTab::auxiliaryKeep)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (HuffmanTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HuffmanTab::auxiliaryPlus)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (HuffmanTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HuffmanTab::auxiliaryCompress)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject HuffmanTab::staticMetaObject = {
    { &Tab::staticMetaObject, qt_meta_stringdata_HuffmanTab.data,
      qt_meta_data_HuffmanTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HuffmanTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HuffmanTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HuffmanTab.stringdata0))
        return static_cast<void*>(this);
    return Tab::qt_metacast(_clname);
}

int HuffmanTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tab::qt_metacall(_c, _id, _a);
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
void HuffmanTab::auxiliaryKeep()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HuffmanTab::auxiliaryPlus()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HuffmanTab::auxiliaryCompress()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_TwoThreeTab_t {
    QByteArrayData data[6];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TwoThreeTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TwoThreeTab_t qt_meta_stringdata_TwoThreeTab = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TwoThreeTab"
QT_MOC_LITERAL(1, 12, 15), // "auxiliarySubPre"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "auxiliarySubInv"
QT_MOC_LITERAL(4, 45, 13), // "subPreClicked"
QT_MOC_LITERAL(5, 59, 13) // "subInvClicked"

    },
    "TwoThreeTab\0auxiliarySubPre\0\0"
    "auxiliarySubInv\0subPreClicked\0"
    "subInvClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TwoThreeTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TwoThreeTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TwoThreeTab *_t = static_cast<TwoThreeTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->auxiliarySubPre(); break;
        case 1: _t->auxiliarySubInv(); break;
        case 2: _t->subPreClicked(); break;
        case 3: _t->subInvClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TwoThreeTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoThreeTab::auxiliarySubPre)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TwoThreeTab::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoThreeTab::auxiliarySubInv)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TwoThreeTab::staticMetaObject = {
    { &Tab::staticMetaObject, qt_meta_stringdata_TwoThreeTab.data,
      qt_meta_data_TwoThreeTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TwoThreeTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TwoThreeTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TwoThreeTab.stringdata0))
        return static_cast<void*>(this);
    return Tab::qt_metacast(_clname);
}

int TwoThreeTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tab::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TwoThreeTab::auxiliarySubPre()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TwoThreeTab::auxiliarySubInv()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
