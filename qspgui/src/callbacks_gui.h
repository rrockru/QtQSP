#ifndef _QSP_CALLBACKS_H_
#define _QSP_CALLBACKS_H_
#include "main_window.h"
#include "qsp_inputdlg.h"

namespace Ui
{

class QSPCallBacks
{
public:
	static void Init(MainWindow * m_window);
	static void RefreshInt(QSP_BOOL isRedraw);
	static void ShowPane(int type, QSP_BOOL isShow);
	static void PlayerVersion(const QSP_CHAR *text, QSP_CHAR *buffer, int maxLen);
	static void Input(const QSP_CHAR *text, QSP_CHAR *buffer, int maxLen);
private:
	static MainWindow * m_window;
	static QString m_gamePath;
	static bool m_isHtml;
	static QUrl m_gameUrl;

	static void UpdateGamePath();
};

} // namespace Ui

#endif // _QSP_CALLBACKS_H_