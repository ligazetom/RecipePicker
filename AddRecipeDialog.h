#pragma once

#include <QDialog>
#include "ui_AddRecipeDialog.h"

class AddRecipeDialog : public QDialog
{
	Q_OBJECT

public:
	AddRecipeDialog(QWidget* parent);
	~AddRecipeDialog();

	QString GetRecipeName() const;
	int GetRecipeMealtime() const;
	int GetRecipeCategory() const;
	int GetRecipeDifficulty() const;

protected:
	void InitializeComboboxes();

private:
	Ui::AddRecipeDialog ui;

private slots:
	void on_pushButtonAdd_pressed();
	void on_pushButtonCancel_pressed();
};

