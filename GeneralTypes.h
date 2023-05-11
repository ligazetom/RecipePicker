#pragma once

namespace Recipe
{
	enum Mealtime
	{
		Dessert = 0,
		Breakfast,
		Lunch,
		Dinner,
		NumberOfMealtimes
	};

	constexpr const char* RecipeMealtimeNames[NumberOfMealtimes] = { "Dessert", "Breakfast", "Lunch", "Dinner" };

	enum Category
	{
		Vegetarian = 0,
		Meat,
		NumberOfCategories
	};

	constexpr const char* RecipeCategoryNames[NumberOfCategories] = { "Vegetarian", "Meat" };

	enum Difficulty
	{
		Easy = 0,
		Medium,
		Hard,
		NumberOfDifficulties
	};

	constexpr const char* RecipeDifficultyNames[NumberOfDifficulties] = { "Easy", "Medium", "Hard" };
}

namespace TableColumns
{
	enum Recipes
	{
		RecipeID = 0,
		RecipeName,
		RecipeMealTime,
		RecipeCategory,
		RecipeDifficulty,
		NumberOfRecipeColumns,		
	};

	constexpr const char* RecipesColumnNames[NumberOfRecipeColumns] = { "Recipe ID", "Name", "Category", "Meal time", "Difficulty" };
}

namespace TableWidgetTypes
{
	struct RecipeRow
	{
		int64_t RecipeID;
		QString RecipeName;
		int RecipeMealtime;
		int RecipeCategory;		
		int RecipeDifficulty;
	};
}