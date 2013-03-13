#include "stdafx.h"
#include "qsp_textbox.h"
#include "qsp_msgdlg.h"

namespace Ui
{
	QSPMsgDlg::QSPMsgDlg(QString caption, 
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
		tmpPal.setColor(QPalette::Base, backCol);
		tmpPal.setColor(QPalette::Text, foreCol);
		setPalette(tmpPal);
		_desc->setPalette(tmpPal);
		_desc->setFont(font);

		QHBoxLayout *buttonBox = new QHBoxLayout;
		QPushButton *okButton = new QPushButton("OK");
		okButton->setPalette(tmpPal);
		okButton->setFont(font);
		buttonBox->addWidget(okButton);

		connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

		box->addWidget(_desc);
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
	}
}