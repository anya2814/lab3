/****************************************************************************
** Meta object code from reading C++ file 'chartwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lab3/chartwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChartWidget_t {
    QByteArrayData data[11];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChartWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChartWidget_t qt_meta_stringdata_ChartWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ChartWidget"
QT_MOC_LITERAL(1, 12, 11), // "dataChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "dataReadFailed"
QT_MOC_LITERAL(4, 40, 15), // "dataChangedSlot"
QT_MOC_LITERAL(5, 56, 18), // "dataReadFailedSlot"
QT_MOC_LITERAL(6, 75, 16), // "CBtypeChosenSlot"
QT_MOC_LITERAL(7, 92, 14), // "PBprintPDFSlot"
QT_MOC_LITERAL(8, 107, 27), // "CBchartTypeIndexChangedSlot"
QT_MOC_LITERAL(9, 135, 5), // "index"
QT_MOC_LITERAL(10, 141, 29) // "CBcolorSchemeIndexChangedSlot"

    },
    "ChartWidget\0dataChanged\0\0dataReadFailed\0"
    "dataChangedSlot\0dataReadFailedSlot\0"
    "CBtypeChosenSlot\0PBprintPDFSlot\0"
    "CBchartTypeIndexChangedSlot\0index\0"
    "CBcolorSchemeIndexChangedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChartWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   58,    2, 0x0a /* Public */,
       5,    1,   59,    2, 0x0a /* Public */,
       6,    0,   62,    2, 0x08 /* Private */,
       7,    0,   63,    2, 0x08 /* Private */,
       8,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void ChartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChartWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: _t->dataReadFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->dataChangedSlot(); break;
        case 3: _t->dataReadFailedSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->CBtypeChosenSlot(); break;
        case 5: _t->PBprintPDFSlot(); break;
        case 6: _t->CBchartTypeIndexChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->CBcolorSchemeIndexChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChartWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartWidget::dataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChartWidget::*)(QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChartWidget::dataReadFailed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChartWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ChartWidget.data,
    qt_meta_data_ChartWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChartWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ChartWidget::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChartWidget::dataReadFailed(QString const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
