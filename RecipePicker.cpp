#include "RecipePicker.h"

#include "GeneralTypes.h"
#include "AddRecipeDialog.h"

#include <qmessagebox.h>


RecipePicker::RecipePicker(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	SetupTableWidget();
}

RecipePicker::~RecipePicker()
{}

void RecipePicker::SetupTableWidget()
{
    //ui.tableWidgetRecipes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidgetRecipes->setColumnCount(TableColumns::NumberOfRecipeColumns);

    QStringList headerLabels;
    headerLabels.reserve(TableColumns::NumberOfRecipeColumns);

    for (int i = 0; i < TableColumns::NumberOfRecipeColumns; ++i)
    {
        headerLabels.push_back(TableColumns::RecipesColumnNames[i]);
    }

    ui.tableWidgetRecipes->setHorizontalHeaderLabels(headerLabels);
    ui.tableWidgetRecipes->resizeColumnsToContents();
}

void RecipePicker::AddNewRow(const std::vector<QTableWidgetItem*>& rowItems)
{
    const int numOfRows = ui.tableWidgetRecipes->rowCount();
    ui.tableWidgetRecipes->insertRow(numOfRows);

    int colCounter = 0;
    for (const auto& rowItem : rowItems)
    {
        ui.tableWidgetRecipes->setItem(numOfRows, colCounter, rowItem);
        ++colCounter;
    }
}

std::vector<QTableWidgetItem*> RecipePicker::CreateRow(const TableWidgetTypes::RecipeRow& row)
{
    std::vector<QTableWidgetItem*> items(TableColumns::NumberOfRecipeColumns);

    items[TableColumns::RecipeID] = new QTableWidgetItem();
    items[TableColumns::RecipeID]->setData(Qt::DisplayRole, row.RecipeID);
    items[TableColumns::RecipeName] = new QTableWidgetItem(row.RecipeName);
    items[TableColumns::RecipeMealTime] = new QTableWidgetItem(Recipe::RecipeMealtimeNames[row.RecipeMealtime]);
    items[TableColumns::RecipeMealTime]->setData(Qt::UserRole, row.RecipeMealtime);
    items[TableColumns::RecipeCategory] = new QTableWidgetItem(Recipe::RecipeCategoryNames[row.RecipeCategory]);
    items[TableColumns::RecipeCategory]->setData(Qt::UserRole, row.RecipeCategory);
    items[TableColumns::RecipeDifficulty] = new QTableWidgetItem(Recipe::RecipeDifficultyNames[row.RecipeDifficulty]);
    items[TableColumns::RecipeDifficulty]->setData(Qt::UserRole, row.RecipeDifficulty);

    return items;
}

TableWidgetTypes::RecipeRow RecipePicker::ExtractRow(int rowIndex) const
{
    TableWidgetTypes::RecipeRow row;

    row.RecipeID = ui.tableWidgetRecipes->item(rowIndex, TableColumns::RecipeID)->data(Qt::DisplayRole).toInt();
    row.RecipeName = ui.tableWidgetRecipes->item(rowIndex, TableColumns::RecipeName)->text();
    row.RecipeMealtime = ui.tableWidgetRecipes->item(rowIndex, TableColumns::RecipeMealTime)->data(Qt::UserRole).toInt();
    row.RecipeCategory = ui.tableWidgetRecipes->item(rowIndex, TableColumns::RecipeCategory)->data(Qt::UserRole).toInt();
    row.RecipeDifficulty = ui.tableWidgetRecipes->item(rowIndex, TableColumns::RecipeDifficulty)->data(Qt::UserRole).toInt();

    return row;
}

void RecipePicker::on_actionAddNewRecipe_triggered()
{
    AddRecipeDialog dlg(this);

    if (dlg.exec() == QDialog::Accepted)
    {        
        TableWidgetTypes::RecipeRow row;

        row.RecipeID = 0;
        row.RecipeName = dlg.GetRecipeName();
        row.RecipeMealtime = dlg.GetRecipeMealtime();
        row.RecipeCategory = dlg.GetRecipeCategory();
        row.RecipeDifficulty = dlg.GetRecipeDifficulty();

        AddNewRow(CreateRow(row));
        ui.tableWidgetRecipes->resizeColumnsToContents();
    }
}