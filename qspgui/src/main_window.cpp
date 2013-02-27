#include "stdafx.h"
#include "main_window.h"

namespace Ui
{

MainWindow::MainWindow(QString configFile) :
	QMainWindow(),
	_configFile(configFile),
	_configDefPath(configFile)
{
	setMinimumSize(QSize(300, 200));
	setWindowTitle(TITLE);
	setDockNestingEnabled(true);
	resize(850, 650);

	// Set QMainWindow in the center of desktop
	_defRect = geometry();
	_defRect.moveCenter(QApplication::desktop()->availableGeometry().center());
	setGeometry(_defRect);

	_mainDescTextBox = new QspTextBox(this);
	setCentralWidget(_mainDescTextBox);
	connect(_mainDescTextBox, SIGNAL(LinkClicked(QString)), this, SLOT(OnLinkClicked(QString)));

	CreateDockWindows();
	CreateMenuBar();
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::LoadSettings()
{
	//if (QFile::exists(_configFile))
	//{
		QSettings settings(_configFile, QSettings::IniFormat);

		const char defState[] = "\0\0\0\xff\0\0\0\0\xfd\0\0\0\x2\0\0\0\x1\0\0\0\x9f\0\0\x1\x8d\xfc\x2\0\0\0\x1\xfb\xff\xff\xff\xff\x1\0\0\0\x15\0\0\x1\x8d\0\0\0_\0\xff\xff\xff\0\0\0\x3\0\0\x3R\0\0\0\xe4\xfc\x2\0\0\0\x1\xfc\0\0\x1\xa6\0\0\0\xe4\0\0\0\x91\0\xff\xff\xff\xfc\x1\0\0\0\x2\xfc\0\0\0\0\0\0\x2N\0\0\0P\0\xff\xff\xff\xfc\x2\0\0\0\x2\xfb\xff\xff\xff\xff\x1\0\0\x1\xa6\0\0\0\xb2\0\0\0_\0\xff\xff\xff\xfb\xff\xff\xff\xff\x1\0\0\x2\\\0\0\0.\0\0\0.\0\0\0.\xfb\xff\xff\xff\xff\x1\0\0\x2R\0\0\x1\0\0\0\0P\0\xff\xff\xff\0\0\x2\xaf\0\0\x1\x8d\0\0\0\x4\0\0\0\x4\0\0\0\b\0\0\0\b\xfc\0\0\0";

		QByteArray state = QByteArray::fromRawData(defState, sizeof(defState));

		setGeometry(settings.value("Geometry", _defRect).toRect());
		restoreState(settings.value("WindowState", state).toByteArray());

		if (settings.value("IsMaximized", 0).toBool())
			showMaximized();

		_lastPath = settings.value("LastPath", "").toString();
		QString panels = QString("layout2|") +
			"name=imgview;state=1080035327;dir=1;layer=0;row=0;pos=0;prop=100000;bestw=832;besth=150;minw=50;minh=50;maxw=-1;maxh=-1;floatx=175;floaty=148;floatw=518;floath=372|" +
			"name=desc;state=768;dir=5;layer=0;row=0;pos=0;prop=100000;bestw=613;besth=341;minw=-1;minh=-1;maxw=-1;maxh=-1;floatx=-1;floaty=-1;floatw=-1;floath=-1|" +
			"name=objs;state=6293500;dir=2;layer=0;row=0;pos=0;prop=100000;bestw=213;besth=324;minw=50;minh=50;maxw=-1;maxh=-1;floatx=-1;floaty=-1;floatw=-1;floath=-1|" +
			"name=acts;state=6293500;dir=3;layer=0;row=0;pos=0;prop=117349;bestw=475;besth=185;minw=50;minh=50;maxw=-1;maxh=-1;floatx=-1;floaty=-1;floatw=-1;floath=-1|" +
			"name=vars;state=6293500;dir=3;layer=0;row=0;pos=1;prop=82651;bestw=351;besth=185;minw=50;minh=50;maxw=-1;maxh=-1;floatx=-1;floaty=-1;floatw=-1;floath=-1|" +
			"name=input;state=2099196;dir=3;layer=1;row=0;pos=0;prop=100000;bestw=832;besth=22;minw=50;minh=20;maxw=-1;maxh=-1;floatx=-1;floaty=-1;floatw=-1;floath=-1|" +
			"dock_size(5,0,0)=22|dock_size(2,0,0)=215|dock_size(3,0,0)=204|dock_size(3,1,0)=41|";
		_panels = settings.value("Panels", panels).toString();

		_fontName = settings.value("Font/FontName", QApplication::font().family()).toString();
		_fontSize = settings.value("Font/FontSize", QApplication::font().pointSize()).toInt();
		_isUseFontSize = settings.value("Font/UseFontSize", 0).toBool();
		
	//}
}

void MainWindow::SaveSettings()
{
	QSettings settings(_configFile, QSettings::IniFormat);

	bool maximized = isMaximized();

	if (maximized) showNormal();

	settings.setValue("Geometry", geometry());
	settings.setValue("WindowState", saveState());
	settings.setValue("IsMaximized", maximized);
	settings.setValue("LastPath", _lastPath);
	settings.setValue("LastPath", _lastPath);
	settings.setValue("Panels", _panels);

	settings.setValue("Font/FontName", _fontName);
	settings.setValue("Font/FontSize", _fontSize);
	settings.setValue("Font/UseFontSize", _isUseFontSize);
	ApplyFontName(_fontName);
}

void MainWindow::CreateMenuBar()
{
	//------------------------------------------------------------------
	// File menu
	_fileMenu = menuBar()->addMenu(tr("&Quest"));

	// Open item
	_fileMenu->addAction(QIcon(":/menu/open"), tr("Open game..."),
		this, SLOT(OnOpenGame()), QKeySequence(Qt::ALT + Qt::Key_O));

	// New game item
	_fileMenu->addAction(QIcon(":/menu/new"),tr("Restart game"),
		this, SLOT(OnRestartGame()), QKeySequence(Qt::ALT + Qt::Key_N));

	_fileMenu->addSeparator();

	// Exit item
	_fileMenu->addAction(QIcon(":/menu/exit"), tr("Exit"),
		this, SLOT(close()), QKeySequence(Qt::ALT + Qt::Key_X));
	//------------------------------------------------------------------
	// Game menu
	_gameMenu = menuBar()->addMenu(tr("&Game"));

	// Open saved game item
	_gameMenu->addAction(QIcon(":/menu/statusopen"), tr("Open saved game..."),
		this, SLOT(OnOpenSavedGame()), QKeySequence(Qt::CTRL + Qt::Key_O));

	// Save game item
	_gameMenu->addAction(QIcon(":/menu/statussave"), tr("Save game..."),
		this, SLOT(OnSaveGame()), QKeySequence(Qt::CTRL + Qt::Key_S));
	//------------------------------------------------------------------
	// Settings menu
	_settingsMenu = menuBar()->addMenu(tr("&Settings"));
	
	// Show / Hide submenu
	_showHideMenu = _settingsMenu->addMenu(tr("Show / Hide"));

	// Objects item 
	QAction* action = _objectsWidget->toggleViewAction();
	action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_1));
	_showHideMenu->addAction(action);

	// Actions item 
	action = _actionsWidget->toggleViewAction();
	action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_2));
	_showHideMenu->addAction(action);

	// Additional desc item 
	action = _descWidget->toggleViewAction();
	action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_3));
	_showHideMenu->addAction(action);

	// Input area item 
	action = _inputWidget->toggleViewAction();
	action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_4));
	_showHideMenu->addAction(action);

	_showHideMenu->addSeparator();

	// Captions item
	_showHideMenu->addAction(tr("Captions"), this, SLOT(OnToggleCaptions()),
		QKeySequence(Qt::CTRL + Qt::Key_5));

	// Hotkeys for actions item
	_showHideMenu->addAction(tr("Hotkeys for actions"), this, SLOT(OnToggleHotkeys()),
		QKeySequence(Qt::CTRL + Qt::Key_6));
		
	// Sound volume item
	_settingsMenu->addAction(tr("Sound volume..."),
		this, SLOT(OnChangeSoundVolume()), QKeySequence(Qt::ALT + Qt::Key_V));

	// Window / Fullscreen mode item
	_settingsMenu->addAction(QIcon(":/menu/windowmode"), tr("Window / Fullscreen mode"),
		this, SLOT(OnToggleWinMode()), QKeySequence(Qt::ALT + Qt::Key_Enter));

	_settingsMenu->addSeparator();

	// Options item
	_settingsMenu->addAction(tr("Options..."),
		this, SLOT(OnOptions()), QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_O));
	//------------------------------------------------------------------
	// Help menu
	QMenu* helpMenu(menuBar()->addMenu(tr("&Help")));

	// About item
	helpMenu->addAction(QIcon(":/menu/about"), tr("About..."),
		this, SLOT(OnAbout()), QKeySequence(Qt::CTRL + Qt::Key_H));
}

void MainWindow::CreateDockWindows()
{
	// "Objects" widget
	_objectsWidget = new QDockWidget(tr("Objects"), this);
	addDockWidget(Qt::RightDockWidgetArea, _objectsWidget, Qt::Vertical);
	_objectsListBox = new QspListBox(this);
	_objectsWidget->setWidget(_objectsListBox);
	connect(_objectsListBox, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(OnObjectChange()));

	// "Actions" widget
	_actionsWidget = new QDockWidget(tr("Actions"), this);
	addDockWidget(Qt::BottomDockWidgetArea, _actionsWidget, Qt::Vertical);
	_actionsListBox = new QspListBox(this);
	_actionsWidget->setWidget(_actionsListBox);
	connect(_actionsListBox, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
		this, SLOT(OnActionChange()));
	connect(_actionsListBox, SIGNAL(itemClicked(QListWidgetItem *)),
		this, SLOT(OnActionDblClick()));

	// "Additional desc" widget
	_descWidget = new QDockWidget(tr("Additional desc"), this);
	addDockWidget(Qt::BottomDockWidgetArea, _descWidget, Qt::Horizontal);
	_descTextBox = new QspTextBox(this);
	_descWidget->setWidget(_descTextBox);
	connect(_descTextBox, SIGNAL(LinkClicked(QString)), this, SLOT(OnLinkClicked(QString)));

	// "Input area" widget
	_inputWidget = new QDockWidget(tr("Input area"), this);
	addDockWidget(Qt::BottomDockWidgetArea, _inputWidget, Qt::Vertical);
	_inputTextBox = new QspInputBox(this);
	_inputTextBox->setFixedHeight(24);

	_inputWidget->setWidget(_inputTextBox);

	splitDockWidget(_actionsWidget, _inputWidget, Qt::Vertical);
}

void MainWindow::OnOpenGame()
{
	QFileDialog *dlg = new QFileDialog();
	QString filename = dlg->getOpenFileName(this, NULL, _lastPath, "QSP games (*.qsp;*.gam)|*.qsp;*.gam");
	if (!filename.isEmpty())
	{
		QFileInfo fi(filename);
		_lastPath = fi.absoluteFilePath();
		OpenGameFile(filename);
	}
}

void MainWindow::OnRestartGame()
{
	if (!QSPRestartGame(QSP_TRUE))
		ShowError();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	SaveSettings();
	QMainWindow::closeEvent(event);
}

void MainWindow::OnAbout()
{

}

void MainWindow::OnOptions()
{

}

void MainWindow::OnOpenSavedGame()
{

}

void MainWindow::OnSaveGame()
{

}

void MainWindow::OnToggleCaptions()
{

}

void MainWindow::OnToggleHotkeys()
{

}

void MainWindow::OnToggleWinMode()
{
	if(this->isFullScreen())
		this->showNormal();
	else
		this->showFullScreen();
}

void MainWindow::OnChangeSoundVolume()
{

}

void MainWindow::OpenGameFile(QString filename)
{
	if(QSPLoadGameWorld(filename.toStdWString().c_str()))
	{
		QFileInfo gameFile(filename);
		QString configFile(gameFile.absoluteDir().absolutePath() + QDir::separator() + QSP_CONFIG);
		QString newFile = QFile::exists(configFile) ? configFile : _configDefPath;
		if (newFile != _configFile)
		{
			//SaveSettings();
			_configFile = newFile;
			LoadSettings();
		}
		OnRestartGame();
	}
	else
		ShowError();
}

void MainWindow::ShowError()
{
	QSP_CHAR *loc;
	int code, actIndex, line;
	QSPGetLastErrorData(&code, &loc, &actIndex, &line);
	QString desc = QString::fromWCharArray(QSPGetErrorDesc(code));
	QMessageBox dlg;
	QString msg = QString("Location: %1\nArea: %2\nLine: %3\nCode: %4\nDesc: %5").arg(
		QString::fromWCharArray(loc), 
		(actIndex < 0 ? "on visit" : "on action"),
		QString::number((size_t)line),
		QString::number((size_t)code),
		desc);
	dlg.setText(msg);
	dlg.exec();
}

void MainWindow::ShowPane(int type, QSP_BOOL isShow)
{
	switch (type)
	{
	case ID_ACTIONS:
		_actionsWidget->setVisible(isShow);
		break;
	case ID_OBJECTS:
		_objectsWidget->setVisible(isShow);
		break;
	case ID_VARSDESC:
		_descWidget->setVisible(isShow);
		break;
	case ID_INPUT:
		_inputWidget->setVisible(isShow);
		break;
	}
}

void MainWindow::OnObjectChange()
{
	if (!QSPSetSelObjectIndex(_objectsListBox->currentRow(), QSP_TRUE))
		ShowError();
}

void MainWindow::OnActionChange()
{
	if (!QSPSetSelActionIndex(_actionsListBox->currentRow(), QSP_TRUE))
		ShowError();
}

void MainWindow::OnActionDblClick()
{
	if (!QSPExecuteSelActionCode(QSP_TRUE))
		ShowError();
}

void MainWindow::ApplyParams()
{
	int numVal;
	QSP_CHAR *strVal;
	bool isFontChanged = false;

	QString setFontName;
	int setFontSize;

	if (_isUseFontSize)
		setFontSize = _fontSize;
	else
		setFontSize = ((QSPGetVarValues(QSP_FMT("FSIZE"), 0, &numVal, &strVal) && numVal) ? numVal : _fontSize);
	if (setFontSize != _descTextBox->font().pointSize());
	{
		ApplyFontSize(setFontSize);
	}

	(QSPGetVarValues(QSP_FMT("FNAME"), 0, &numVal, &strVal) && strVal && *strVal);
	setFontName = ((QSPGetVarValues(QSP_FMT("FNAME"), 0, &numVal, &strVal) && strVal && *strVal) ? QString::fromWCharArray(strVal) : _fontName);
	QFont newFont(setFontName);
	QFont oldFont(_mainDescTextBox->font());
	if (!newFont.isCopyOf(oldFont))
	{
		ApplyFontName(setFontName);
	}

}

void MainWindow::ApplyFontName(QString fname)
{
	QFont newFont(_mainDescTextBox->font());
	newFont.setFamily(fname);
	ApplyFont(newFont);
}

void MainWindow::ApplyFontSize(int fsize)
{
	QFont newFont(_mainDescTextBox->font());
	qDebug() << fsize;
	newFont.setPointSize(fsize);
	ApplyFont(newFont);
}

void MainWindow::ApplyFont(QFont newFont)
{
	_mainDescTextBox->setFont(newFont);
	_objectsListBox->SetTextFont(newFont);
	_actionsListBox->SetTextFont(newFont);
	_descTextBox->setFont(newFont);
	_inputTextBox->setFont(newFont);
}

void MainWindow::OnLinkClicked(QString href)
{
	if (href.toUpper().startsWith("EXEC:"))
	{
		if (!QSPExecString((const QSP_CHAR *)href.mid(5).toStdWString().c_str(), QSP_TRUE)) ShowError();
	}
}

} // namespace Ui
