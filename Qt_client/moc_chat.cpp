/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created: Tue Sep 3 16:00:42 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Chat[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   23,    5,    5, 0x08,
      46,    5,    5,    5, 0x08,
      70,    5,    5,    5, 0x08,
      96,    5,    5,    5, 0x08,
     104,    5,    5,    5, 0x08,
     130,    5,    5,    5, 0x08,
     157,  148,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Chat[] = {
    "Chat\0\0account(QString)\0str2\0"
    "handData(QString)\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0clean()\0"
    "on_pushButton_3_clicked()\0recivrec(QString)\0"
    "str,soc,\0revinf(QString,QTcpSocket*,Chat*)\0"
};

const QMetaObject Chat::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Chat,
      qt_meta_data_Chat, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Chat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Chat))
        return static_cast<void*>(const_cast< Chat*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: account((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: handData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: on_pushButton_clicked(); break;
        case 3: on_pushButton_2_clicked(); break;
        case 4: clean(); break;
        case 5: on_pushButton_3_clicked(); break;
        case 6: recivrec((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: revinf((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2])),(*reinterpret_cast< Chat*(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Chat::account(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
