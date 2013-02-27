#include "stdafx.h"
#include "qsp_listbox.h"

namespace Ui
{

QspListBox::QspListBox( QWidget* parent ) :
	QListWidget(parent)
{
	setItemDelegate(new QspListItemDelegate);
	viewport()->setMouseTracking(true);
	QPalette pal = palette();
	pal.setColor(QPalette::Inactive, QPalette::Highlight, pal.color(QPalette::Active, QPalette::Highlight));
	setPalette(pal);
}

void QspListBox::ClearItems()
{
	clear();
}

void QspListBox::AddItem(const QString& image, const QString& desc)
{
	QListWidgetItem *item = new QListWidgetItem();
	QString text = QString("<TABLE CELLSPACING = \"4\" CELLPADDING = \"0\"><TR><TD WIDTH =\"100%\">%1</TD></TR></TABLE>").arg(desc);
	item->setText(text);
	item->setFont(_fontName);
	addItem(item);
}

void QspListBox::mouseMoveEvent(QMouseEvent *event)
{
	QListWidgetItem *curItem = itemAt(event->pos());
	if (curItem != NULL)
	{
		setCurrentItem(curItem);
	}
	QListWidget::mouseMoveEvent(event);
}

void QspListBox::SetTextFont(QFont font)
{
	_fontName = font;
	if (this->count() > 0)
	{
		QListWidgetItem *curItem;
		for (int i = 0; i < this->count(); i++)
		{
			curItem = this->item(i);
			curItem->setFont(font);
		}
	}
}

} // namespace Ui
