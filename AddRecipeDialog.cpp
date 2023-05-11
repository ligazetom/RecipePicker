#include "AddRecipeDialog.h"

#include "GeneralTypes.h"
#include "GeneralUtils.h"

AddRecipeDialog::AddRecipeDialog(QWidget* parent) : QDialog(parent)
{
	ui.setupUi(this);
	InitializeComboboxes();
}

AddRecipeDialog::~AddRecipeDialog()
{
}

QString AddRecipeDialog::GetRecipeName() const
{
	return ui.lineEditRecipeName->text().trimmed();
}

int AddRecipeDialog::GetRecipeMealtime() const
{
	return ui.comboBoxMealtime->currentData().toInt();
}

int AddRecipeDialog::GetRecipeCategory() const
{
	return ui.comboBoxCategory->currentData().toInt();
}

int AddRecipeDialog::GetRecipeDifficulty() const
{
	return ui.comboBoxDifficulty->currentData().toInt();
}

void AddRecipeDialog::InitializeComboboxes()
{
	for (int i = 0; i < Recipe::NumberOfMealtimes; ++i)
	{
		ui.comboBoxMealtime->addItem(Recipe::RecipeMealtimeNames[i], i);
	}

	for (int i = 0; i < Recipe::NumberOfCategories; ++i)
	{
		ui.comboBoxCategory->addItem(Recipe::RecipeCategoryNames[i], i);
	}

	for (int i = 0; i < Recipe::NumberOfDifficulties; ++i)
	{
		ui.comboBoxDifficulty->addItem(Recipe::RecipeDifficultyNames[i], i);
	}	
}

void AddRecipeDialog::on_pushButtonAdd_pressed()
{
	QString recipeName = ui.lineEditRecipeName->text();
	recipeName = recipeName.trimmed();

	if (recipeName.isEmpty())
	{
		GeneralUtils::ShowMessageBox("Warning", "Recipe name cannot be empty!");
		return;
	}

	accept();
}

void AddRecipeDialog::on_pushButtonCancel_pressed()
{
	reject();
}
