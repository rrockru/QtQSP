#include "stdafx.h"
#include "qsp_textbox.h"

namespace Ui
{

QspTextBox::QspTextBox(QWidget* parent) :
	QTextEdit(parent)
{
	setReadOnly(true);

	viewport()->setMouseTracking(true);
}

QVariant QspTextBox::loadResource(int type, const QUrl &name)
{
	if (type == QTextDocument::ImageResource) {
		QFile file(srcUrl.resolved(name).toLocalFile());
		if (file.open(QIODevice::ReadOnly))
			return file.readAll();
	}
	return QTextEdit::loadResource(type, name);
}

void QspTextBox::SetContentUrl(QUrl srcUrl)
{
	this->srcUrl = srcUrl;
}

void QspTextBox::SetText(QString text)
{
	QString txt;
	if (m_isHtml)
		txt = text.replace("\n", "<br />");
	else
		txt = Qt::convertFromPlainText(text);
	QTextDocument *doc = this->document();
	//QString css = "";
	//doc->addResource(QTextDocument::StyleSheetResource, QUrl("SlipSummary.css"), css);
	//doc->setHtml(QString("<html><head><link rel='stylesheet' type='text/css' href='SlipSummary.css'></head><body>%1</body></html>").arg(txt));
	doc->setHtml(txt);
	this->setDocument(doc);
}

void QspTextBox::LoadBackImage(QString filename)
{
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Base, QBrush(QPixmap(filename))); 
	setPalette(palette); 
}

void QspTextBox::mouseMoveEvent(QMouseEvent* e)
{
	QPoint p = e->pos();
	QCursor cursor = viewport()->cursor();

	if ( !anchorAt( p ).isEmpty() )
	{
		cursor.setShape(Qt::PointingHandCursor);
		viewport()->setCursor(cursor);
	}
	else
	{
		cursor.setShape(Qt::ArrowCursor);
		viewport()->setCursor(cursor);
	}
}

void QspTextBox::mousePressEvent(QMouseEvent *e)
{
	QPoint p = e->pos();
	if ( !anchorAt( p ).isEmpty() )
	{
		emit LinkClicked(anchorAt(p));
	}
}

} // namespace Ui
