#ifndef _QSP_LISTITEMDELEGATE_H_
#define _QSP_LISTITEMDELEGATE_H_

namespace Ui
{
	class QspListItemDelegate : public QStyledItemDelegate
	{
	protected:
		void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
		QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;
	};
} // namespace Ui

#endif // _QSP_LISTITEMDELEGATE_H_
