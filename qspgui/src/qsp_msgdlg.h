#ifndef _QSP_MSGDLG_H_
#define _QSP_MSGDLG_H_

namespace Ui
{

	class QSPMsgDlg : public QDialog
	{
		Q_OBJECT

	public:
		QSPMsgDlg(QString caption, 
			QString text, 
			QColor backCol,
			QColor foreCol,
			QFont font,
			bool isHtml, 
			QUrl gamePath);
	};
} // namespace Ui

#endif // _QSP_MSGDLG_H_