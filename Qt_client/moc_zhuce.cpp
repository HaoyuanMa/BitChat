/****************************************************************************
** Meta object code from reading C++ file 'zhuce.h'
**
** Created: Tue Sep 3 16:00:27 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "zhuce.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zhuce.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZhuCe[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      31,    6,    6,    6, 0x08,
      47,    6,    6,    6, 0x08,
      58,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ZhuCe[] = {
    "ZhuCe\0\0on_pushButton_clicked()\0"
    "handConnected()\0handData()\0clean()\0"
};

const QMetaObject ZhuCe::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZhuCe,
      qt_meta_data_ZhuCe, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZhuCe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZhuCe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZhuCe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZhuCe))
        return static_cast<void*>(const_cast< ZhuCe*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZhuCe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: handConnected(); break;
        case 2: handData(); break;
        case 3: clean(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
