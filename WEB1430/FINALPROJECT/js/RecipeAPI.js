import { Recipe } from './Recipe.js';

export class RecipeAPI {
  constructor(apiKey = '79b8b544cc744cf7a1190098f8cea072') {
    this.apiKey = apiKey;
    this.baseUrl = 'https://api.spoonacular.com/recipes';
    this.lastRequestTime = 0;
    this.minIntervalMs = 500; // Basic rate-limit guard
  }

  async _throttle() {
    const now = Date.now();
    const elapsed = now - this.lastRequestTime;
    if (elapsed < this.minIntervalMs) {
      await new Promise((res) => setTimeout(res, this.minIntervalMs - elapsed));
    }
    this.lastRequestTime = Date.now();
  }

  /**
   * Searches recipes from Spoonacular (or returns built-in demo data if no key is set)
   */
  async searchRecipes({ query = '', type = '', diet = '', maxReadyTime = '' } = {}) {
    if (!this.apiKey || this.apiKey === '79b8b544cc744cf7a1190098f8cea072') {
      return this._getFallbackRecipes(query, type);
    }

    await this._throttle();

    const params = new URLSearchParams({
      apiKey: this.apiKey,
      query,
      number: '12',
      addRecipeInformation: 'true',
      addRecipeNutrition: 'true',
      fillIngredients: 'true',
    });

    if (type) params.append('type', type);
    if (diet) params.append('diet', diet);
    if (maxReadyTime) params.append('maxReadyTime', maxReadyTime);

    const response = await fetch(`${this.baseUrl}/complexSearch?${params.toString()}`);

    if (!response.ok) {
      if (response.status === 402 || response.status === 429) {
        throw new Error('API daily quota or rate limit reached. Try again later.');
      }
      throw new Error(`API Error (${response.status}): Could not fetch recipes.`);
    }

    const data = await response.json();
    return (data.results || []).map((item) => this._normalizeRecipe(item));
  }

  _normalizeRecipe(raw) {
    const nutrients = raw.nutrition?.nutrients || [];
    const findNutrient = (name) =>
      nutrients.find((n) => n.name.toLowerCase() === name.toLowerCase())?.amount || 0;

    const steps =
      raw.analyzedInstructions?.[0]?.steps?.map((s) => s.step) ||
      ['Follow standard preparation steps for this dish.'];

    const ingredients = (raw.extendedIngredients || []).map((ing) => ({
      name: ing.nameClean || ing.name,
      amount: ing.amount,
      unit: ing.unit,
    }));

    return new Recipe({
      id: raw.id,
      title: raw.title,
      image: raw.image,
      readyInMinutes: raw.readyInMinutes,
      servings: raw.servings,
      vegetarian: raw.vegetarian,
      glutenFree: raw.glutenFree,
      ingredients,
      instructions: steps,
      nutrition: {
        calories: findNutrient('Calories'),
        protein: findNutrient('Protein'),
        carbs: findNutrient('Carbohydrates'),
        fat: findNutrient('Fat'),
      },
    });
  }

  /**
   * Built-in sample dataset so the app works immediately before adding an API key
   */
  _getFallbackRecipes(query = '', type = '') {
    const samples = [
      {
        id: 1001,
        title: '15-Minute Garlic Herb Chickpea Bowl',
        image: 'https://images.unsplash.com/photo-1512621776951-a57141f2eefd?w=600&q=80',
        readyInMinutes: 15,
        servings: 2,
        vegetarian: true,
        glutenFree: true,
        category: 'lunch',
        ingredients: [
          { name: 'canned chickpeas, drained', amount: 15, unit: 'oz' },
          { name: 'olive oil', amount: 1, unit: 'tbsp' },
          { name: 'garlic cloves, minced', amount: 2, unit: 'cloves' },
          { name: 'baby spinach', amount: 2, unit: 'cups' },
          { name: 'cherry tomatoes', amount: 1, unit: 'cup' },
        ],
        instructions: [
          'Heat olive oil in a skillet over medium heat and sauté garlic for 30 seconds.',
          'Add chickpeas and spices; cook for 6–7 minutes until lightly crisp.',
          'Toss in baby spinach until wilted and serve over cherry tomatoes.',
        ],
        nutrition: { calories: 410, protein: 16, carbs: 52, fat: 14 },
      },
      {
        id: 1002,
        title: 'Lemon Pan-Seared Salmon & Asparagus',
        image: 'https://images.unsplash.com/photo-1467003909585-2f8a72700288?w=600&q=80',
        readyInMinutes: 22,
        servings: 2,
        vegetarian: false,
        glutenFree: true,
        category: 'main course',
        ingredients: [
          { name: 'salmon fillets', amount: 2, unit: 'fillets' },
          { name: 'asparagus spears', amount: 1, unit: 'bunch' },
          { name: 'lemon juice', amount: 2, unit: 'tbsp' },
          { name: 'butter', amount: 1, unit: 'tbsp' },
        ],
        instructions: [
          'Season salmon fillets with salt, pepper, and lemon juice.',
          'Sear salmon skin-side down in a hot pan for 5 minutes, then flip for 3 minutes.',
          'Add asparagus and butter to the pan during the final 4 minutes until tender-crisp.',
        ],
        nutrition: { calories: 520, protein: 42, carbs: 8, fat: 34 },
      },
      {
        id: 1003,
        title: 'Berry & Chia Overnight Oats',
        image: 'https://images.unsplash.com/photo-1517673132405-a56a62b18caf?w=600&q=80',
        readyInMinutes: 10,
        servings: 1,
        vegetarian: true,
        glutenFree: true,
        category: 'breakfast',
        ingredients: [
          { name: 'rolled oats', amount: 0.5, unit: 'cup' },
          { name: 'almond milk', amount: 0.75, unit: 'cup' },
          { name: 'chia seeds', amount: 1, unit: 'tbsp' },
          { name: 'mixed berries', amount: 0.5, unit: 'cup' },
        ],
        instructions: [
          'Combine oats, almond milk, and chia seeds in a mason jar.',
          'Stir well, cover, and refrigerate overnight (or at least 4 hours).',
          'Top with fresh mixed berries before serving.',
        ],
        nutrition: { calories: 330, protein: 11, carbs: 49, fat: 9 },
      },
      {
        id: 1004,
        title: 'Creamy Mushroom & Spinach Pasta',
        image: 'https://images.unsplash.com/photo-1621996346565-e3dbc646d9a9?w=600&q=80',
        readyInMinutes: 35,
        servings: 4,
        vegetarian: true,
        glutenFree: false,
        category: 'main course',
        ingredients: [
          { name: 'penne pasta', amount: 12, unit: 'oz' },
          { name: 'cremini mushrooms, sliced', amount: 8, unit: 'oz' },
          { name: 'heavy cream', amount: 0.5, unit: 'cup' },
          { name: 'parmesan cheese', amount: 0.5, unit: 'cup' },
        ],
        instructions: [
          'Boil pasta in salted water according to package directions; reserve 1/2 cup pasta water.',
          'Sauté sliced mushrooms until golden brown.',
          'Stir in cream, parmesan, spinach, and pasta water, then toss with drained pasta.',
        ],
        nutrition: { calories: 580, protein: 20, carbs: 68, fat: 24 },
      },
    ];

    const q = query.trim().toLowerCase();
    return samples
      .filter((r) => {
        const matchesQuery =
          !q ||
          r.title.toLowerCase().includes(q) ||
          r.ingredients.some((i) => i.name.toLowerCase().includes(q));
        const matchesType = !type || r.category === type;
        return matchesQuery && matchesType;
      })
      .map((item) => new Recipe(item));
  }
}