/********************************************************************************
** Form generated from reading UI file 'DYELogAnalyzeToolDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYELOGANALYZETOOLDLG_H
#define UI_DYELOGANALYZETOOLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DYELogAnalyzeToolDlg
{
public:
    QPushButton *PUSHBUTTON_OPENFILEDLG;
    QPushButton *PUSHBUTTON_ANALYZETIMECONSUME;
    QPushButton *PUSHBUTTON_ANALYZEFAILSERVICE;
    QLabel *LABEL_FILEFULLPATH;
    QLineEdit *LINEEDIT_FILEFULLPATH;
    QListWidget *LISTWIDGET_SHOWANALYZERESULT;
    QListWidget *LISTWIDGET_SHOWTXTCONTEXT;

    void setupUi(QWidget *DYELogAnalyzeToolDlg)
    {
        if (DYELogAnalyzeToolDlg->objectName().isEmpty())
            DYELogAnalyzeToolDlg->setObjectName(QStringLiteral("DYELogAnalyzeToolDlg"));
        DYELogAnalyzeToolDlg->resize(901, 668);
        PUSHBUTTON_OPENFILEDLG = new QPushButton(DYELogAnalyzeToolDlg);
        PUSHBUTTON_OPENFILEDLG->setObjectName(QStringLiteral("PUSHBUTTON_OPENFILEDLG"));
        PUSHBUTTON_OPENFILEDLG->setGeometry(QRect(640, 20, 75, 23));
        PUSHBUTTON_ANALYZETIMECONSUME = new QPushButton(DYELogAnalyzeToolDlg);
        PUSHBUTTON_ANALYZETIMECONSUME->setObjectName(QStringLiteral("PUSHBUTTON_ANALYZETIMECONSUME"));
        PUSHBUTTON_ANALYZETIMECONSUME->setGeometry(QRect(20, 50, 91, 23));
        PUSHBUTTON_ANALYZEFAILSERVICE = new QPushButton(DYELogAnalyzeToolDlg);
        PUSHBUTTON_ANALYZEFAILSERVICE->setObjectName(QStringLiteral("PUSHBUTTON_ANALYZEFAILSERVICE"));
        PUSHBUTTON_ANALYZEFAILSERVICE->setGeometry(QRect(130, 50, 91, 23));
        LABEL_FILEFULLPATH = new QLabel(DYELogAnalyzeToolDlg);
        LABEL_FILEFULLPATH->setObjectName(QStringLiteral("LABEL_FILEFULLPATH"));
        LABEL_FILEFULLPATH->setGeometry(QRect(20, 20, 54, 21));
        LINEEDIT_FILEFULLPATH = new QLineEdit(DYELogAnalyzeToolDlg);
        LINEEDIT_FILEFULLPATH->setObjectName(QStringLiteral("LINEEDIT_FILEFULLPATH"));
        LINEEDIT_FILEFULLPATH->setGeometry(QRect(90, 20, 521, 20));
        LINEEDIT_FILEFULLPATH->setReadOnly(true);
        LISTWIDGET_SHOWANALYZERESULT = new QListWidget(DYELogAnalyzeToolDlg);
        LISTWIDGET_SHOWANALYZERESULT->setObjectName(QStringLiteral("LISTWIDGET_SHOWANALYZERESULT"));
        LISTWIDGET_SHOWANALYZERESULT->setGeometry(QRect(20, 80, 861, 261));
        LISTWIDGET_SHOWTXTCONTEXT = new QListWidget(DYELogAnalyzeToolDlg);
        LISTWIDGET_SHOWTXTCONTEXT->setObjectName(QStringLiteral("LISTWIDGET_SHOWTXTCONTEXT"));
        LISTWIDGET_SHOWTXTCONTEXT->setGeometry(QRect(20, 350, 861, 301));

        retranslateUi(DYELogAnalyzeToolDlg);

        QMetaObject::connectSlotsByName(DYELogAnalyzeToolDlg);
    } // setupUi

    void retranslateUi(QWidget *DYELogAnalyzeToolDlg)
    {
        DYELogAnalyzeToolDlg->setWindowTitle(QApplication::translate("DYELogAnalyzeToolDlg", "DYELogAnalyzeToolDlg", Q_NULLPTR));
        PUSHBUTTON_OPENFILEDLG->setText(QApplication::translate("DYELogAnalyzeToolDlg", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        PUSHBUTTON_ANALYZETIMECONSUME->setText(QApplication::translate("DYELogAnalyzeToolDlg", "\345\210\206\346\236\220\350\200\227\346\227\266\346\223\215\344\275\234", Q_NULLPTR));
        PUSHBUTTON_ANALYZEFAILSERVICE->setText(QApplication::translate("DYELogAnalyzeToolDlg", "\345\210\206\346\236\220\344\270\232\345\212\241\345\244\261\350\264\245", Q_NULLPTR));
        LABEL_FILEFULLPATH->setText(QApplication::translate("DYELogAnalyzeToolDlg", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DYELogAnalyzeToolDlg: public Ui_DYELogAnalyzeToolDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYELOGANALYZETOOLDLG_H
