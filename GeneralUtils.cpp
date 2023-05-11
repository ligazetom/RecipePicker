#include "GeneralUtils.h"

#include <qmessagebox.h>

void GeneralUtils::ShowMessageBox(const QString& title, const QString& text)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.exec();
}

bool GeneralUtils::ShowConfirmationBox(const QString& title, const QString& text)
{
    const QMessageBox::StandardButton reply = QMessageBox::question(nullptr, title, text, QMessageBox::Yes | QMessageBox::No);

    return reply == QMessageBox::Yes;
}
