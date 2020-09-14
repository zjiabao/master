/****************************************************************************
** Meta object code from reading C++ file 'DYELogAnalyzeToolDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DYELogAnalyzeToolDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DYELogAnalyzeToolDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DYELogAnalyzeToolDlg_t {
    QByteArrayData data[8];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DYELogAnalyzeToolDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DYELogAnalyzeToolDlg_t qt_meta_stringdata_DYELogAnalyzeToolDlg = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DYELogAnalyzeToolDlg"
QT_MOC_LITERAL(1, 21, 25), // "OnBtnClkButtonOpenFileDlg"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 32), // "ReadTxtFileByQTextStreamReadLine"
QT_MOC_LITERAL(4, 81, 8), // "QString&"
QT_MOC_LITERAL(5, 90, 11), // "strFileName"
QT_MOC_LITERAL(6, 102, 32), // "OnBtnClkButtonAnalyzeTimeConsume"
QT_MOC_LITERAL(7, 135, 32) // "OnBtnClkButtonAnalyzeFailService"

    },
    "DYELogAnalyzeToolDlg\0OnBtnClkButtonOpenFileDlg\0"
    "\0ReadTxtFileByQTextStreamReadLine\0"
    "QString&\0strFileName\0"
    "OnBtnClkButtonAnalyzeTimeConsume\0"
    "OnBtnClkButtonAnalyzeFailService"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DYELogAnalyzeToolDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::QStringList, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DYELogAnalyzeToolDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DYELogAnalyzeToolDlg *_t = static_cast<DYELogAnalyzeToolDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->OnBtnClkButtonOpenFileDlg();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { QStringList _r = _t->ReadTxtFileByQTextStreamReadLine((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->OnBtnClkButtonAnalyzeTimeConsume(); break;
        case 3: _t->OnBtnClkButtonAnalyzeFailService(); break;
        default: ;
        }
    }
}

const QMetaObject DYELogAnalyzeToolDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DYELogAnalyzeToolDlg.data,
      qt_meta_data_DYELogAnalyzeToolDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DYELogAnalyzeToolDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DYELogAnalyzeToolDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DYELogAnalyzeToolDlg.stringdata0))
        return static_cast<void*>(const_cast< DYELogAnalyzeToolDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int DYELogAnalyzeToolDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
