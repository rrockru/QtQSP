#ifndef _QSP_INPUTDLG_H_
#define _QSP_INPUTDLG_H_

namespace Ui
{

	class QspInputDlg : public QDialog
	{
		Q_OBJECT

	public:
		QspInputDlg(QString caption,
			QString text,
			QColor backCol,
			QColor foreCol,
			QFont font,
			bool isHtml,
			QUrl gamePath);

		QString GetText() { return _text->text(); }

	private:
		QLineEdit *_text;

	};
} // namespace Ui

#endif // _QSP_INPUTDLG_H_