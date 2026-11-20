export class Recipe {
  constructor(data) {
    this.id = data.id;
    this.title = data.title || 'Untitled Recipe';
    this.image = data.image || 'https://placehold.co/600x400?text=No+Image';
    this.readyInMinutes = data.readyInMinutes || 25;
    this.servings = data.servings || 2;
    this.vegetarian = Boolean(data.vegetarian);
    this.glutenFree = Boolean(data.glutenFree);
    this.ingredients = data.ingredients || [];
    this.instructions = data.instructions || [];
    this.nutrition = {
      calories: Math.round(data.nutrition?.calories || 0),
      protein: Math.round(data.nutrition?.protein || 0),
      carbs: Math.round(data.nutrition?.carbs || 0),
      fat: Math.round(data.nutrition?.fat || 0),
    };
  }

  /**
   * Scales ingredient quantities dynamically based on desired servings
   */
  getScaledIngredients(targetServings = this.servings) {
    const factor = targetServings / this.servings;
    return this.ingredients.map(({ name, amount, unit }) => {
      const scaledAmount = amount ? Number((amount * factor).toFixed(2)) : '';
      return {
        name,
        amount: scaledAmount,
        unit: unit || '',
        formatted: `${scaledAmount} ${unit || ''} ${name}`.trim(),
      };
    });
  }

  /**
   * Matches active UI filter chip ('all', 'vegetarian', 'glutenFree', 'quick')
   */
  matchesFilter(filterType) {
    if (filterType === 'all') return true;
    if (filterType === 'vegetarian') return this.vegetarian;
    if (filterType === 'glutenFree') return this.glutenFree;
    if (filterType === 'quick') return this.readyInMinutes < 30;
    return true;
  }

  /**
   * Serializes clean object for localStorage persistence
   */
  toJSON() {
    return {
      id: this.id,
      title: this.title,
      image: this.image,
      readyInMinutes: this.readyInMinutes,
      servings: this.servings,
      vegetarian: this.vegetarian,
      glutenFree: this.glutenFree,
      ingredients: this.ingredients,
      instructions: this.instructions,
      nutrition: this.nutrition,
    };
  }
}