#include "stdafx.h"
#include "main_window.h"
#include "callbacks_gui.h"
#include "qsp_tools.h"

int main(int argc, char **argv)
{
	QApplication application(argc, argv);
	application.setApplicationName("Quest Soft Player");
	application.setApplicationVersion("5.0.0");

	QSPInit();

	QString configFile(Ui::QSPTools::GetAppPath()+QSP_CONFIG);

	Ui::MainWindow *window = new Ui::MainWindow(configFile);
	Ui::QSPCallBacks::Init(window);
	window->LoadSettings();
	window->show();

	return application.exec();
}
