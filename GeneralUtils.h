#pragma once

#include <qstring>

namespace GeneralUtils
{
	void ShowMessageBox(const QString& title, const QString& text);
	bool ShowConfirmationBox(const QString& title, const QString& text);
};

