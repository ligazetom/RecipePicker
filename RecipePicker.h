#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RecipePicker.h"

class RecipePicker : public QMainWindow
{
    Q_OBJECT

public:
    RecipePicker(QWidget *parent = nullptr);
    ~RecipePicker();

private:
    Ui::RecipePickerClass ui;
};
