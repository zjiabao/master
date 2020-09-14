#include "DYELogAnalyzeToolDlg.h"
#include "ui_DYELogAnalyzeToolDlg.h"

DYELogAnalyzeToolDlg::DYELogAnalyzeToolDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DYELogAnalyzeToolDlg)
{
    ui->setupUi(this);
	// ���ļ��Ի���ѡ���ļ�
	connect(ui->PUSHBUTTON_OPENFILEDLG,			/*			�ؼ�				 */
			SIGNAL(clicked()),					/*			�ź�(��Ϣ)		 */
			this,								/*			����				 */
			SLOT(OnBtnClkButtonOpenFileDlg()));	/*			�ۣ���Ϣ��Ӧ������	 */
	// ��ȡ�ļ�����
	connect(ui->PUSHBUTTON_OPENFILEDLG,
			SIGNAL(setText()),
			this,
			SLOT(ReadTxtFileByQTextStreamReadLine()));
	// ���ļ�·����ʾ��LineEdit
	connect(ui->PUSHBUTTON_OPENFILEDLG, 
			SIGNAL(setText()), 
			this, 
			SLOT(OnBtnClkButtonOpenFileDlg()));
	// ������ʱ����
    connect(ui->PUSHBUTTON_ANALYZETIMECONSUME, 
			SIGNAL(clicked()),
			this, 
			SLOT(OnBtnClkButtonAnalyzeTimeConsume()));
	// ��������ʱ���������ʾ��LISTWIDGET_SHOWANALYZERESULT
	connect(ui->LISTWIDGET_SHOWANALYZERESULT,
			SIGNAL(addItems()),
			this,
			SLOT(OnBtnClkButtonAnalyzeTimeConsume()));
	// ����ҵ��ʧ��
	connect(ui->PUSHBUTTON_ANALYZEFAILSERVICE,
			SIGNAL(clicked()),
			this,
			SLOT(OnBtnClkButtonAnalyzeFailService()));
	// ������ҵ��ʧ�ܽ����ʾ��LISTWIDGET_SHOWANALYZERESULT
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
	QString strCurSysPath = QDir::currentPath();//��ȡϵͳ��ǰĿ¼
	QString szFilter = tr("��־�ļ�(*.log);;�ı��ļ�(*.txt);;�����ļ�(*.*)"); //�ļ�������
	m_strFileName = QFileDialog::getOpenFileName(this, tr("ѡ���ļ�"), strCurSysPath, szFilter);
	QFile isTxtFileExists(m_strFileName);

	if (m_strFileName.isEmpty())
	{
		QMessageBox::information(NULL, tr("Warning"), tr("��ѡ����־�ļ���"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return false;
	}
// 	if (!isTxtFileExists.exists())
// 	{
// 		QMessageBox::information(NULL, "Warning", "�ļ������ڣ�", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
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
// 		QMessageBox::information(NULL, tr("Warning"), tr("����ѡ����־�ļ���"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
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

	QStringList m_findResult;	// ��ѯ���
	QString nNZtimelist;	// ��ʱ��Ϊ0�Ĳ��������е��ַ���
	QString strRow;				// ���в������е��ַ���
	QString timenode;			// ���ַ�����ʽ���������ʱ

	int lindex = 0;
	int rindex = 0;
	int j = 0;
	int iTimeLen = 0;

	// ��ȡ��ʱ > 0ms�Ĳ�����־���ڵ���
	for (int i = 0; i < m_saResult.count(); i++)	// ��ñ༭�����ݵ�����m_saResult.GetSize()
	{
		strRow = m_saResult.at(i);				// ���༭������CStringArray���͵�m_saResult���и�ֵ��strRow�Ա��ַ���ƥ��ͱ���
							/* �����ַ���ƥ�������� */
		lindex = strRow.indexOf("��ʱ ", Qt::CaseInsensitive);			// �ַ���ƥ��
		rindex = strRow.indexOf(" ms", Qt::CaseInsensitive);
		iTimeLen = rindex - lindex;

		if (lindex == -1 || rindex == -1)
		{
			continue;
		}

		timenode = strRow.mid(lindex + 3, iTimeLen - 3);	// ��strRow�л�ȡ����ʱ �����ʱ���ַ������浽timnode

		if (timenode != '0')			// �ж���ʱ�Ƿ�Ϊ0ms
		{
			nNZtimelist.append(timenode);	// ������Ĵ��������ʱ���ַ���timenode��CString��ʽ���浽NZtimelist
			m_ResultIndex[j] = i;		// ��ŷ�����ʱ�����е�������iΪ������
			m_findResult.append(strRow);		// ����ͨ���ַ���ƥ���ÿһ���ַ���strRow��m_findResult��
			m_ItemsCount = m_ResultIndex[j];
			j++;
		}
	}

	// �����־����ʾ������¼��ʱ���Ϊ0ms������
	if (nNZtimelist.count() == 0)
	{
		QMessageBox::information(NULL, "About", "��־�ļ�����ʾ���в�����¼��ʱ��Ϊ 0 ms��", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}

// 	nNZtimelist.sort();
// 	for (int i = nNZtimelist.count(); i >= 0; i++)
// 	{
// 
// 	}

	// �Ƚ�CStringArray NZtimelistת����int
	int length = nNZtimelist.count();
	int* p = new int[length];

	for (int i = 0; i < length; i++)
	{
		p[i] = nNZtimelist.at(i).unicode();
	}

	// ��NZtimelist�еĴ�����ʱ���ַ��Ӵ�С����
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

	// ��������NZtimelist�е�ǰ20���ַ����ڵ��������Gird
	QStringList saResult;	// saResult���������ź����n���ַ���
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
	for (int i = 0; i < m_saResult.count(); i++)	// ��ñ༭�����ݵ�����m_saResult.GetSize()
	{
		strRow = m_saResult.at(i);				// ���༭������CStringArray���͵�m_saResult���и�ֵ��strRow�Ա��ַ���ƥ��ͱ���
		int nIndex = strRow.lastIndexOf(tr("ʧ��"));			// �ַ���ƥ��

		if (nIndex == -1)
		{
			continue;
		}
		m_ResultIndex[j] = i;		// ��ŷ�����ʱ�����е�������iΪ������
		m_findResult.join(strRow);		// ����ͨ���ַ���ƥ���ÿһ���ַ���strRow��m_findResult��
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
		QTextStream qReadByTxtStream(&qReadTxtFile); // ���ı�����ȡ�ļ�
													 //	qReadByTxtStream.setAutoDetectUnicode(true); // �Զ����Unicode,����������ʾ�ĵ��ڵĺ���
		while (!qReadByTxtStream.atEnd())
		{
			QString str = qReadByTxtStream.readLine();// ��ȡ�ļ���һ��
//			ui->LISTWIDGET_SHOWTXTCONTEXT->addItem(str); //��ӵ��ı�����ʾ
			m_saResult.append(str);
		}
	}

	qReadTxtFile.close();
	return  m_saResult;
}
