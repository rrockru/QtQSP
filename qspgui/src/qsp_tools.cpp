#include "stdafx.h"
#include "qsp_tools.h"

namespace Ui
{
	QString QSPTools::GetAppPath()
	{
		return QApplication::applicationDirPath() + QDir::separator();
	}
} // namespace Ui