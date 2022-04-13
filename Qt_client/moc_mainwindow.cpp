/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Sep 4 09:31:46 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,
      33,   12,   11,   11, 0x05,
      47,   12,   11,   11, 0x05,
      61,   12,   11,   11, 0x05,
      75,   12,   11,   11, 0x05,
      89,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     105,   11,   11,   11, 0x08,
     120,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0str\0passinf(QString)\0"
    "dmsg(QString)\0smsg(QString)\0rmsg(QString)\0"
    "mmsg(QString)\0recmsg(QString)\0"
    "revid(QString)\0searchresult(QString)\0"
    "refresult(QString)\0handConnect()\0"
    "on_pushButton_2_clicked()\0solvebuf()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: passinf((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: dmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: smsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: rmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: mmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: recmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: revid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: searchresult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: refresult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: handConnect(); break;
        case 10: on_pushButton_2_clicked(); break;
        case 11: solvebuf(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::passinf(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::dmsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::smsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::rmsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::mmsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::recmsg(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
