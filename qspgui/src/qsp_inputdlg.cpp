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
		QUrl gamePath) 
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
		QLineEdit *inputStr = new QLineEdit;
		inputStr->setPalette(tmpPal);
		inputStr->setFont(font);

		QHBoxLayout *buttonBox = new QHBoxLayout;
		QPushButton *okButton = new QPushButton("OK");
		okButton->setPalette(tmpPal);
		okButton->setFont(font);
		QPushButton *cancelButton = new QPushButton("Cancel");
		cancelButton->setPalette(tmpPal);
		cancelButton->setFont(font);
		buttonBox->addWidget(okButton);
		buttonBox->addWidget(cancelButton);
		box->addWidget(_desc);
		box->addWidget((QWidget *)inputStr);
		setLayout(mainLayout);
		mainLayout->addLayout(box);
		mainLayout->addLayout(buttonBox);
		setFixedSize(_desc->sizeHint().width(), _desc->sizeHint().height());

		static const int minWidth = 420;
		static const int maxWidth = 550;
		static const int minHeight = 150;
		static const int maxHeight = 350;

		setMinimumSize(minWidth, minHeight);
		setMaximumSize(maxWidth, maxHeight);

		inputStr->setFocus();

	}

} // namespace Ui