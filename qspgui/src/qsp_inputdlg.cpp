#include "stdafx.h"
#include "qsp_inputdlg.h"
#include "qsp_textbox.h"

namespace Ui
{
	QspInputDlg::QspInputDlg(QString caption, 
		QString text, 
		QColor backCol,
		QColor foreCol,
		QFont font,
		bool isHtml, 
		QUrl gamePath) :
		QDialog()
	{
		QVBoxLayout *mainLayout = new QVBoxLayout;
		QVBoxLayout *box = new QVBoxLayout();
		QspTextBox *_desc = new QspTextBox(this);
		_desc->SetContentUrl(gamePath);
		_desc->SetIsHtml(isHtml);
		_desc->SetText(text);
		QPalette tmpPal = _desc->palette();
		tmpPal.setColor(QPalette::Background, backCol);
		tmpPal.setColor(QPalette::Foreground, foreCol);
		_desc->setPalette(tmpPal);
		_desc->setFont(font);
		_text = new QLineEdit;
		_text->setPalette(tmpPal);
		_text->setFont(font);

		QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
			| QDialogButtonBox::Cancel);

		connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
		connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
		box->addWidget(_desc);
		box->addWidget((QWidget *)_text);
		setLayout(mainLayout);
		mainLayout->addLayout(box);
		mainLayout->addWidget(buttonBox);
		setFixedSize(_desc->sizeHint().width(), _desc->sizeHint().height());

		static const int minWidth = 420;
		static const int maxWidth = 550;
		static const int minHeight = 150;
		static const int maxHeight = 350;

		setMinimumSize(minWidth, minHeight);
		setMaximumSize(maxWidth, maxHeight);

		_text->setFocus();

	}

} // namespace Ui