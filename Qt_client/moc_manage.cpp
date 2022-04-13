/****************************************************************************
** Meta object code from reading C++ file 'manage.h'
**
** Created: Tue Sep 3 16:00:44 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "manage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_manage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,    8,    7,    7, 0x05,
      55,   52,    7,    7, 0x05,
      87,    7,    7,    7, 0x05,
     105,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,   52,    7,    7, 0x08,
     148,    7,    7,    7, 0x08,
     167,    7,    7,    7, 0x08,
     186,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_manage[] = {
    "manage\0\0str,soc,\0account(QString,QTcpSocket*,Chat*)\0"
    ",,\0sendtomanage(Chat*,QString,int)\0"
    "transmsg(QString)\0recmsg(QString)\0"
    "setflag(Chat*,QString,int)\0"
    "recivemsg(QString)\0deletewin(QString)\0"
    "reciverec(QString)\0"
};

const QMetaObject manage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_manage,
      qt_meta_data_manage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &manage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *manage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *manage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_manage))
        return static_cast<void*>(const_cast< manage*>(this));
    return QWidget::qt_metacast(_clname);
}

int manage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: account((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2])),(*reinterpret_cast< Chat*(*)>(_a[3]))); break;
        case 1: sendtomanage((*reinterpret_cast< Chat*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: transmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: recmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: setflag((*reinterpret_cast< Chat*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: recivemsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: deletewin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: reciverec((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void manage::account(QString _t1, QTcpSocket * _t2, Chat * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void manage::sendtomanage(Chat * _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void manage::transmsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void manage::recmsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
