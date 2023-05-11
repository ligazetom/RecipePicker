#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RecipePicker.h"

#include "GeneralTypes.h"

#include <vector>

class RecipePicker : public QMainWindow
{
    Q_OBJECT

public:
    RecipePicker(QWidget *parent = nullptr);
    ~RecipePicker();

protected:
    void SetupTableWidget();

    void AddNewRow(const std::vector<QTableWidgetItem*>& rowItems);

    static std::vector<QTableWidgetItem*> CreateRow(const TableWidgetTypes::RecipeRow& row);
    TableWidgetTypes::RecipeRow ExtractRow(int rowIndex) const;

private:
    Ui::RecipePickerClass ui;

private slots:
    void on_actionAddNewRecipe_triggered();
};
