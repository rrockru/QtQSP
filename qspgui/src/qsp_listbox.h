#ifndef _QSP_LISTBOX_H_
#define _QSP_LISTBOX_H_

#include "qsp_listitemdelegate.h"

namespace Ui
{

class QspListBox : public QListWidget
{
public:
	QspListBox(QWidget* parent = NULL);

	void ClearItems();
	void AddItem(const QString& image, const QString& desc);
	void SetTextFont(QFont font);

protected:
	void mouseMoveEvent(QMouseEvent *event);

private:
	QFont		_fontName;

};

} // namespace Ui

#endif // _QSP_LISTBOX_H_
