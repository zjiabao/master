#ifndef DYELOGANALYZETOOLDLG_H
#define DYELOGANALYZETOOLDLG_H

#pragma EXECUTION_CHARACTER_SET("utf-8")
#pragma execution_character_set("GBK")
#pragma execution_character_set("ANSI")

#define ITEMS_CHECK 20

#include <QWidget>
#include <QListWidgetItem>
#include "qfiledialog.h"
#include "qfileinfo.h"
#include "qfile.h"
#include "qmessagebox.h"
#include "qiodevice.h"
#include "qtextstream.h"
#include "qtextcodec.h"
#include "qtextedit.h"
#include "qlistview.h"
#include "qlistwidget.h"

namespace Ui {
class DYELogAnalyzeToolDlg;
}

class DYELogAnalyzeToolDlg : public QWidget
{
    Q_OBJECT

public:
    explicit DYELogAnalyzeToolDlg(QWidget *parent = 0);
    ~DYELogAnalyzeToolDlg();

private:
    Ui::DYELogAnalyzeToolDlg *ui;

// private signals:
// 	QStringList ReadLogFileToQStringList(QString &strFileName);

private slots:
	bool OnBtnClkButtonOpenFileDlg();
	QStringList ReadTxtFileByQTextStreamReadLine(QString &strFileName);
	void OnBtnClkButtonAnalyzeTimeConsume();
	void OnBtnClkButtonAnalyzeFailService();

private:
	QString									m_strFileName;
	QStringList								m_saResult;
	QStringList								m_findResult;
	int										m_ItemsCount;
	int										m_ResultIndex[999] = { '0' };
};

#endif // DYELOGANALYZETOOLDLG_H
