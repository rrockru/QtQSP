#ifndef _QSP_TEXTBOX_H_
#define _QSP_TEXTBOX_H_

namespace Ui
{

class QspTextBox : public QTextEdit
{
	Q_OBJECT

public:
	QspTextBox(QWidget* parent = NULL);
	
	void SetContentUrl(QUrl srcUrl);
	void SetText(QString text);
	void SetIsHtml(bool isHtml) {m_isHtml = isHtml; }
	void LoadBackImage(QString filename);

protected:
	void mouseMoveEvent(QMouseEvent* e);
	void mousePressEvent(QMouseEvent *e);

private:
	QVariant loadResource(int type, const QUrl &name);

	QUrl srcUrl;
	bool m_isHtml;

signals: 
	void LinkClicked(QString);
};

} // namespace Ui

#endif // _QSP_TEXTBOX_H_
