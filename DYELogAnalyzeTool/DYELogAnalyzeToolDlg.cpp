#include "DYELogAnalyzeToolDlg.h"
#include "ui_DYELogAnalyzeToolDlg.h"

DYELogAnalyzeToolDlg::DYELogAnalyzeToolDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DYELogAnalyzeToolDlg)
{
    ui->setupUi(this);
	// 打开文件对话框选择文件
	connect(ui->PUSHBUTTON_OPENFILEDLG,			/*			控件				 */
			SIGNAL(clicked()),					/*			信号(消息)		 */
			this,								/*			窗口				 */
			SLOT(OnBtnClkButtonOpenFileDlg()));	/*			槽（消息相应函数）	 */
	// 读取文件内容
	connect(ui->PUSHBUTTON_OPENFILEDLG,
			SIGNAL(setText()),
			this,
			SLOT(ReadTxtFileByQTextStreamReadLine()));
	// 将文件路径显示在LineEdit
	connect(ui->PUSHBUTTON_OPENFILEDLG, 
			SIGNAL(setText()), 
			this, 
			SLOT(OnBtnClkButtonOpenFileDlg()));
	// 分析耗时操作
    connect(ui->PUSHBUTTON_ANALYZETIMECONSUME, 
			SIGNAL(clicked()),
			this, 
			SLOT(OnBtnClkButtonAnalyzeTimeConsume()));
	// 将分析耗时操作结果显示在LISTWIDGET_SHOWANALYZERESULT
	connect(ui->LISTWIDGET_SHOWANALYZERESULT,
			SIGNAL(addItems()),
			this,
			SLOT(OnBtnClkButtonAnalyzeTimeConsume()));
	// 分析业务失败
	connect(ui->PUSHBUTTON_ANALYZEFAILSERVICE,
			SIGNAL(clicked()),
			this,
			SLOT(OnBtnClkButtonAnalyzeFailService()));
	// 将分析业务失败结果显示在LISTWIDGET_SHOWANALYZERESULT
	connect(ui->LISTWIDGET_SHOWANALYZERESULT,
			SIGNAL(addItems()),
			this,
			SLOT(OnBtnClkButtonAnalyzeFailService()));
}

DYELogAnalyzeToolDlg::~DYELogAnalyzeToolDlg()
{
    delete ui;
}

bool DYELogAnalyzeToolDlg::OnBtnClkButtonOpenFileDlg()
{
	QString strCurSysPath = QDir::currentPath();//获取系统当前目录
	QString szFilter = tr("日志文件(*.log);;文本文件(*.txt);;所有文件(*.*)"); //文件过滤器
	m_strFileName = QFileDialog::getOpenFileName(this, tr("选择文件"), strCurSysPath, szFilter);
	QFile isTxtFileExists(m_strFileName);

	if (m_strFileName.isEmpty())
	{
		QMessageBox::information(NULL, tr("Warning"), tr("请选择日志文件！"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return false;
	}
// 	if (!isTxtFileExists.exists())
// 	{
// 		QMessageBox::information(NULL, "Warning", "文件不存在！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
// 		return false;
// 	}
	if (!isTxtFileExists.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	isTxtFileExists.close();

	ui->LINEEDIT_FILEFULLPATH->setText(m_strFileName);

	ReadTxtFileByQTextStreamReadLine(m_strFileName);
}


void DYELogAnalyzeToolDlg::OnBtnClkButtonAnalyzeTimeConsume()
{
// 	if (m_strFileName.isEmpty())
// 	{
// 		QMessageBox::information(NULL, tr("Warning"), tr("请先选择日志文件！"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
// 		return;
// 	}

// 	for (int i = 0; i < ui->LISTWIDGET_SHOWANALYZERESULT->count(); i++)
// 	{
// 		QListWidgetItem *item1;
// 		QListWidgetItem *item2;
// 
// 		item1 = ui->LISTWIDGET_SHOWANALYZERESULT->takeItem(0);
// 		item2 = ui->LISTWIDGET_SHOWTXTCONTEXT->takeItem(0);
// 	}

	QStringList m_findResult;	// 查询结果
	QString nNZtimelist;	// 用时不为0的操作所在行的字符串
	QString strRow;				// 进行操作的行的字符串
	QString timenode;			// 以字符串形式保存操作用时

	int lindex = 0;
	int rindex = 0;
	int j = 0;
	int iTimeLen = 0;

	// 获取用时 > 0ms的操作日志所在的行
	for (int i = 0; i < m_saResult.count(); i++)	// 获得编辑框内容的行数m_saResult.GetSize()
	{
		strRow = m_saResult.at(i);				// 将编辑框存放在CStringArray类型的m_saResult逐行赋值给strRow以便字符串匹配和保存
							/* 中文字符串匹配有问题 */
		lindex = strRow.indexOf("用时 ", Qt::CaseInsensitive);			// 字符串匹配
		rindex = strRow.indexOf(" ms", Qt::CaseInsensitive);
		iTimeLen = rindex - lindex;

		if (lindex == -1 || rindex == -1)
		{
			continue;
		}

		timenode = strRow.mid(lindex + 3, iTimeLen - 3);	// 从strRow中获取“用时 ”后的时间字符，保存到timnode

		if (timenode != '0')			// 判断用时是否为0ms
		{
			nNZtimelist.append(timenode);	// 将非零的代表操作用时的字符串timenode以CString格式保存到NZtimelist
			m_ResultIndex[j] = i;		// 存放非零用时所在行的索引，i为索引号
			m_findResult.append(strRow);		// 保存通过字符串匹配的每一行字符串strRow到m_findResult中
			m_ItemsCount = m_ResultIndex[j];
			j++;
		}
	}

	// 如果日志中显示操作记录的时间均为0ms，返回
	if (nNZtimelist.count() == 0)
	{
		QMessageBox::information(NULL, "About", "日志文件中显示所有操作记录用时均为 0 ms！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}

// 	nNZtimelist.sort();
// 	for (int i = nNZtimelist.count(); i >= 0; i++)
// 	{
// 
// 	}

	// 先将CStringArray NZtimelist转换成int
	int length = nNZtimelist.count();
	int* p = new int[length];

	for (int i = 0; i < length; i++)
	{
		p[i] = nNZtimelist.at(i).unicode();
	}

	// 将NZtimelist中的代表用时的字符从大到小排序
	int iTimetemp = 0;
	int iIndextemp = 0;

	for (int i = 0; i < length - 1; i++)
		for (j = 0; j < length - i - 1; j++)
		{
			if (p[j] <= p[j + 1])
			{
				iTimetemp = p[j + 1];
				iIndextemp = m_ResultIndex[j + 1];

				p[j + 1] = p[j];
				m_ResultIndex[j + 1] = m_ResultIndex[j];

				p[j] = iTimetemp;
				m_ResultIndex[j] = iIndextemp;
			}
		}
	delete p;

	// 将排序后的NZtimelist中的前20个字符所在的行输出到Gird
	QStringList saResult;	// saResult————排好序的n个字符串
	QString strDivTemp;
	for (int i = 0; i < ITEMS_CHECK; i++)
	{
		saResult.append(m_saResult.at(m_ResultIndex[i]));
	}

	for (int i = 0; i < ITEMS_CHECK; i++)
	{
		int nRowIndex = i;
		int nColumnIndex = 0;
		QString strTempText = "";

		strTempText = saResult.at(i);
        ui->LISTWIDGET_SHOWANALYZERESULT->addItem(strTempText);
		updatesEnabled();
	}

}


void DYELogAnalyzeToolDlg::OnBtnClkButtonAnalyzeFailService()
{
	QString strPathEdit = "";
	strPathEdit = ui->LINEEDIT_FILEFULLPATH->text();
// 	if (strPathEdit.isEmpty())
// 	{
// 		QMessageBox::information(NULL, "", "", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
// 		return;
// 	}

// 	for (int i = 0; i < ui->LISTWIDGET_SHOWANALYZERESULT->count(); i++)
// 	{
// 		QListWidgetItem *item1;
// 		QListWidgetItem *item2;
// 
// 		item1 = ui->LISTWIDGET_SHOWANALYZERESULT->takeItem(0);
// 		item2 = ui->LISTWIDGET_SHOWTXTCONTEXT->takeItem(0);
// 	}

	QString strRow;
	int j = 0;
	for (int i = 0; i < m_saResult.count(); i++)	// 获得编辑框内容的行数m_saResult.GetSize()
	{
		strRow = m_saResult.at(i);				// 将编辑框存放在CStringArray类型的m_saResult逐行赋值给strRow以便字符串匹配和保存
		int nIndex = strRow.lastIndexOf(tr("失败"));			// 字符串匹配

		if (nIndex == -1)
		{
			continue;
		}
		m_ResultIndex[j] = i;		// 存放非零用时所在行的索引，i为索引号
		m_findResult.join(strRow);		// 保存通过字符串匹配的每一行字符串strRow到m_findResult中
		m_ItemsCount = m_ResultIndex[j];
		j++;
	}

	for (int i = 0; i < m_findResult.count(); i++)
	{
		int nColumnIndex = 0;
		QString strTempText = m_findResult.at(i);

		ui->LISTWIDGET_SHOWANALYZERESULT->addItem(strTempText);
	}
}


QStringList DYELogAnalyzeToolDlg::ReadTxtFileByQTextStreamReadLine(QString &strFileName)
{
	QFile qReadTxtFile(strFileName);

	if (qReadTxtFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream qReadByTxtStream(&qReadTxtFile); // 用文本流读取文件
													 //	qReadByTxtStream.setAutoDetectUnicode(true); // 自动检测Unicode,才能正常显示文档内的汉字
		while (!qReadByTxtStream.atEnd())
		{
			QString str = qReadByTxtStream.readLine();// 读取文件的一行
//			ui->LISTWIDGET_SHOWTXTCONTEXT->addItem(str); //添加到文本框显示
			m_saResult.append(str);
		}
	}

	qReadTxtFile.close();
	return  m_saResult;
}
