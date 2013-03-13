#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include "qsp_textbox.h"
#include "qsp_listbox.h"
#include "qsp_inputbox.h"
#include "qsp_imgcanvas.h"

#define TITLE "Quest Soft Player 5"
#define QSP_CONFIG "qspgui.cfg"

enum
{
	ID_MAINDESC,
	ID_VARSDESC,
	ID_OBJECTS,
	ID_ACTIONS,
	ID_VIEWPIC,
	ID_INPUT,
	ID_TIMER,

	ID_DUMMY
};

namespace Ui
{

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QString configFile);
	~MainWindow();

	QspTextBox * GetDesc() const { return _mainDescTextBox; }
	QspListBox * GetActions() const { return _actionsListBox; }
	QspListBox * GetObjects() const { return _objectsListBox; }
	QspTextBox * GetVars() const { return _descTextBox; }

	void ShowPane(int type, QSP_BOOL isShow);
	void ApplyParams();
	void LoadSettings();
	void SaveSettings();
	void DeleteMenu();
	void AddMenuItem(QString, QString);
	int ShowMenu();

private:
	void CreateMenuBar();
	void CreateDockWindows();
	void closeEvent(QCloseEvent *event);
	void OpenGameFile(QString);
	void ShowError();
	void ApplyFont(QFont);
	void ApplyFontSize(int);
	void ApplyFontName(QString);
	void ApplyBackColor(QColor);
	void ApplyFontColor(QColor);
	void ApplyLinkColor(QColor);

private:

	QMenu*			_fileMenu;
	QMenu*			_gameMenu;
	QMenu*			_settingsMenu;
	QMenu*			_showHideMenu;
	QMenu*			_popupMenu;
	QspTextBox*		_mainDescTextBox;
	QspListBox*		_objectsListBox;
	QspListBox*		_actionsListBox;
	QspTextBox*		_descTextBox;
	QspInputBox*	_inputTextBox;
	QDockWidget*	_objectsWidget;
	QDockWidget*	_actionsWidget;
	QDockWidget*	_descWidget;
	QDockWidget*	_inputWidget;
	QColor			_backColor;
	QColor			_fontColor;
	QColor			_linkColor;
	QPoint			_linkClickPos;
	QRect			_defRect;
	QString			_lastPath;
	QString			_fontName;
	QString			_configFile;
	QString			_configDefPath;
	QString			_panels;
	bool			_isUseFontSize;
	int				_fontSize;
	int				_menuIndex;
	

private slots:
	void OnOpenGame();
	void OnRestartGame();
	void OnOpenSavedGame();
	void OnSaveGame();
	void OnOptions();
	void OnAbout();
	void OnToggleCaptions();
	void OnToggleHotkeys();
	void OnToggleWinMode();
	void OnChangeSoundVolume();
	void OnActionChange();
	void OnObjectChange();
	void OnActionDblClick();
	void OnLinkClicked(QString, QPoint);
	void OnMenu(QAction *);
};

} // namespace Ui

#endif // _MAIN_WINDOW_H_
