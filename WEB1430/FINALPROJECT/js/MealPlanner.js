import { Recipe } from './Recipe.js';

export class MealPlanner {
  constructor() {
    this.FAV_KEY = 'culinary_explorer_favorites';
    this.PLAN_KEY = 'culinary_explorer_planner';
    this.favorites = this._loadFromStorage(this.FAV_KEY);
    this.scheduledMeals = this._loadFromStorage(this.PLAN_KEY);
  }

  _loadFromStorage(key) {
    try {
      const raw = localStorage.getItem(key);
      if (!raw) return [];
      return JSON.parse(raw).map((item) => new Recipe(item));
    } catch (err) {
      console.error(`Failed to parse ${key}:`, err);
      return [];
    }
  }

  _saveToStorage(key, list) {
    localStorage.setItem(key, JSON.stringify(list.map((r) => r.toJSON())));
  }

  isFavorite(recipeId) {
    return this.favorites.some((r) => r.id === Number(recipeId));
  }

  toggleFavorite(recipe) {
    const exists = this.isFavorite(recipe.id);
    if (exists) {
      this.favorites = this.favorites.filter((r) => r.id !== recipe.id);
    } else {
      this.favorites.push(recipe);
    }
    this._saveToStorage(this.FAV_KEY, this.favorites);
    return !exists;
  }

  addMealToPlan(recipe, mealSlot = 'Dinner') {
    this.scheduledMeals.push({
      entryId: Date.now() + Math.random(),
      mealSlot,
      recipe,
    });
    this._savePlan();
  }

  removeMealFromPlan(entryId) {
    this.scheduledMeals = this.scheduledMeals.filter((m) => m.entryId !== Number(entryId));
    this._savePlan();
  }

  clearPlan() {
    this.scheduledMeals = [];
    this._savePlan();
  }

  _savePlan() {
    const serialized = this.scheduledMeals.map((m) => ({
      entryId: m.entryId,
      mealSlot: m.mealSlot,
      recipe: m.recipe.toJSON(),
    }));
    localStorage.setItem(this.PLAN_KEY, JSON.stringify(serialized));
  }

  /**
   * Overrides default loader for scheduledMeals since each entry has a mealSlot
   */
  loadPlannerState() {
    try {
      const raw = localStorage.getItem(this.PLAN_KEY);
      if (!raw) {
        this.scheduledMeals = [];
        return;
      }
      this.scheduledMeals = JSON.parse(raw).map((entry) => ({
        entryId: entry.entryId,
        mealSlot: entry.mealSlot,
        recipe: new Recipe(entry.recipe),
      }));
    } catch {
      this.scheduledMeals = [];
    }
  }

  /**
   * Calculates total daily calories and macros using Array.reduce
   */
  getTotalNutrition() {
    return this.scheduledMeals.reduce(
      (totals, { recipe }) => {
        totals.calories += recipe.nutrition.calories;
        totals.protein += recipe.nutrition.protein;
        totals.carbs += recipe.nutrition.carbs;
        totals.fat += recipe.nutrition.fat;
        return totals;
      },
      { calories: 0, protein: 0, carbs: 0, fat: 0 }
    );
  }
}