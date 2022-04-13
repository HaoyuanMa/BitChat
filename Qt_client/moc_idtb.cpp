/****************************************************************************
** Meta object code from reading C++ file 'idtb.h'
**
** Created: Wed Sep 4 09:31:46 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "idtb.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'idtb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Idtb[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    6,    5,    5, 0x05,
      53,   50,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Idtb[] = {
    "Idtb\0\0str,soc,\0account(QString,QTcpSocket*,Chat*)\0"
    ",,\0sendtomanage(Chat*,QString,int)\0"
    "openwin()\0"
};

const QMetaObject Idtb::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_Idtb,
      qt_meta_data_Idtb, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Idtb::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Idtb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Idtb::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Idtb))
        return static_cast<void*>(const_cast< Idtb*>(this));
    return QToolButton::qt_metacast(_clname);
}

int Idtb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: account((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2])),(*reinterpret_cast< Chat*(*)>(_a[3]))); break;
        case 1: sendtomanage((*reinterpret_cast< Chat*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: openwin(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Idtb::account(QString _t1, QTcpSocket * _t2, Chat * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Idtb::sendtomanage(Chat * _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
