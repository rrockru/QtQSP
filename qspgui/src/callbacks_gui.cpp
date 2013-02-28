#include "stdafx.h"
#include "callbacks_gui.h"

namespace Ui
{
	MainWindow *QSPCallBacks::m_window;
	QString QSPCallBacks::m_gamePath;
	bool QSPCallBacks::m_isHtml;
	QUrl QSPCallBacks::m_gameUrl;

	void QSPCallBacks::Init(MainWindow * window)
	{
		m_window = window;

		QSPSetCallBack(QSP_CALL_REFRESHINT, (QSP_CALLBACK)&RefreshInt);
		QSPSetCallBack(QSP_CALL_SHOWWINDOW, (QSP_CALLBACK)&ShowPane);
		QSPSetCallBack(QSP_CALL_INPUTBOX, (QSP_CALLBACK)&Input);
		QSPSetCallBack(QSP_CALL_DELETEMENU, (QSP_CALLBACK)&DeleteMenu);
		QSPSetCallBack(QSP_CALL_ADDMENUITEM, (QSP_CALLBACK)&AddMenuItem);
		QSPSetCallBack(QSP_CALL_SHOWMENU, (QSP_CALLBACK)&ShowMenu);
		QSPSetCallBack(QSP_CALL_SHOWMSGSTR, (QSP_CALLBACK)&Msg);

	}

	void QSPCallBacks::RefreshInt(QSP_BOOL isRedraw)
	{
		int i, numVal;
		bool isScroll, isCanSave;
		QSP_CHAR *strVal, *imgPath;

		UpdateGamePath();

		const QSP_CHAR *mainDesc = QSPGetMainDesc();
		const QSP_CHAR *varsDesc = QSPGetVarsDesc();

		m_isHtml = QSPGetVarValues(QSP_FMT("USEHTML"), 0, &numVal, &strVal) && numVal;

		m_window->GetVars()->SetIsHtml(m_isHtml);
		if (QSPIsVarsDescChanged())
			m_window->GetVars()->SetText(QString::fromWCharArray(varsDesc)/*, isScroll */);

		m_window->GetDesc()->SetIsHtml(m_isHtml);
		if (QSPIsMainDescChanged())
			m_window->GetDesc()->SetText(QString::fromWCharArray(mainDesc));

		if (QSPIsActionsChanged())
		{
			m_window->GetActions()->ClearItems();
			int actionsCount = QSPGetActionsCount();
			for (i = 0; i < actionsCount; i++)
			{
				QSPGetActionData(i, &imgPath, &strVal);
				m_window->GetActions()->AddItem(QString::fromWCharArray(imgPath), QString::fromWCharArray(strVal));
			}
		}
		m_window->GetActions()->setCurrentRow(QSPGetSelActionIndex());
		if (QSPIsObjectsChanged())
		{
			int objectsCount = QSPGetObjectsCount();
			m_window->GetObjects()->ClearItems();
			for (i = 0; i < objectsCount; ++i)
			{
				QSPGetObjectData(i, &imgPath, &strVal);
				m_window->GetObjects()->AddItem(QString::fromWCharArray(imgPath), QString::fromWCharArray(strVal));
			}
		}
		m_window->GetObjects()->setCurrentRow(QSPGetSelObjectIndex());
		if (QSPGetVarValues(QSP_FMT("BACKIMAGE"), 0, &numVal, &strVal) && strVal && *strVal)
			m_window->GetDesc()->LoadBackImage(m_gamePath + QString::fromWCharArray(strVal));
		else
			m_window->GetDesc()->LoadBackImage("");

		m_window->ApplyParams();
	}

	void QSPCallBacks::ShowPane(int type, QSP_BOOL isShow)
	{
		switch (type)
		{
		case QSP_WIN_ACTS:
			m_window->ShowPane(ID_ACTIONS, isShow != QSP_FALSE);
			break;
		case QSP_WIN_OBJS:
			m_window->ShowPane(ID_OBJECTS, isShow != QSP_FALSE);
			break;
		case QSP_WIN_VARS:
			m_window->ShowPane(ID_VARSDESC, isShow != QSP_FALSE);
			break;
		case QSP_WIN_INPUT:
			m_window->ShowPane(ID_INPUT, isShow != QSP_FALSE);
			break;
		}
	}

	void QSPCallBacks::UpdateGamePath()
	{
		QFileInfo fi(QString::fromWCharArray(QSPGetQstFullPath()));
		m_gamePath = fi.absoluteDir().path() + QDir::separator();
		m_gameUrl = QUrl::fromLocalFile(fi.absoluteFilePath());
		m_window->GetDesc()->SetContentUrl(m_gameUrl);
		m_window->GetVars()->SetContentUrl(m_gameUrl);
	}

	void QSPCallBacks::Input(const QSP_CHAR *text, QSP_CHAR *buffer, int maxLen)
	{
		QspInputDlg *dlg = new QspInputDlg("Input data",
			QString::fromWCharArray(text),
			m_window->GetDesc()->palette().color(QPalette::Base),
			m_window->GetDesc()->palette().color(QPalette::Text),
			m_window->GetDesc()->font(),
			m_isHtml,
			m_gameUrl);
		dlg->exec();
#ifdef _UNICODE
		wcsncpy(buffer, dlg->GetText().toStdWString().c_str(), maxLen);
#else
		strncpy(buffer, dlg->GetText().toStdString().c_str(), maxLen);
#endif
	}

	void QSPCallBacks::DeleteMenu()
	{
		m_window->DeleteMenu();
	}

	void QSPCallBacks::AddMenuItem(const QSP_CHAR *name, const QSP_CHAR *imgPath)
	{
		m_window->AddMenuItem(QString::fromWCharArray(name), QString::fromWCharArray(imgPath));
	}

	int QSPCallBacks::ShowMenu()
	{
		return m_window->ShowMenu();
	}

	void QSPCallBacks::Msg(const QSP_CHAR *str)
	{
		QSPMsgDlg *dlg = new QSPMsgDlg("Input data",
			QString::fromWCharArray(str),
			m_window->GetDesc()->palette().color(QPalette::Base),
			m_window->GetDesc()->palette().color(QPalette::Text),
			m_window->GetDesc()->font(),
			m_isHtml,
			m_gameUrl);
		dlg->exec();
	}

} // namespace Ui