export class UI {
  constructor() {
    this.recipeGrid = document.getElementById('recipe-grid');
    this.resultsCount = document.getElementById('results-count');
    this.favoritesList = document.getElementById('favorites-list');
    this.favoritesCount = document.getElementById('favorites-count');
    this.plannerList = document.getElementById('planner-list');
    this.statusBanner = document.getElementById('status-banner');

    this.totalCalories = document.getElementById('total-calories');
    this.totalProtein = document.getElementById('total-protein');
    this.totalCarbs = document.getElementById('total-carbs');
    this.totalFat = document.getElementById('total-fat');

    this.modal = document.getElementById('recipe-modal');
    this.modalBody = document.getElementById('modal-body');
  }

  showLoadingSkeletons(count = 4) {
    this.recipeGrid.innerHTML = Array.from({ length: count })
      .map(() => `<div class="skeleton skeleton-card"></div>`)
      .join('');
  }

  showStatus(message, isDemo = false) {
    if (!message) {
      this.statusBanner.classList.add('hidden');
      return;
    }
    this.statusBanner.textContent = message;
    this.statusBanner.classList.remove('hidden');
    if (!isDemo) {
      setTimeout(() => this.statusBanner.classList.add('hidden'), 5000);
    }
  }

  renderRecipes(recipes, planner) {
    this.resultsCount.textContent = `${recipes.length} recipe${recipes.length === 1 ? '' : 's'}`;

    if (!recipes.length) {
      this.recipeGrid.innerHTML = `<p class="empty-state">No recipes matched your search or active filter.</p>`;
      return;
    }

    this.recipeGrid.innerHTML = recipes
      .map((recipe) => {
        const isFav = planner.isFavorite(recipe.id);
        return `
          <article class="recipe-card" data-id="${recipe.id}">
            <div class="card-img-wrap" data-action="view">
              <img src="${recipe.image}" alt="${recipe.title}" loading="lazy" />
              <div class="card-tags">
                ${recipe.vegetarian ? '<span class="tag">Vegetarian</span>' : ''}
                ${recipe.glutenFree ? '<span class="tag">GF</span>' : ''}
              </div>
            </div>
            <div class="card-body">
              <h3 class="card-title" data-action="view">${recipe.title}</h3>
              <div class="card-meta">
                <span>⏱️ ${recipe.readyInMinutes} min</span>
                <span>🔥 ${recipe.nutrition.calories} kcal</span>
              </div>
              <div class="card-actions">
                <button class="btn btn-sm ${isFav ? 'btn-saved' : 'btn-outline'}" data-action="favorite">
                  ${isFav ? '♥ Saved' : '♡ Save'}
                </button>
                <button class="btn btn-sm btn-primary" data-action="plan">+ Plan</button>
              </div>
            </div>
          </article>
        `;
      })
      .join('');
  }

  renderFavorites(favorites) {
    this.favoritesCount.textContent = `Saved: ${favorites.length}`;

    if (!favorites.length) {
      this.favoritesList.innerHTML = `<li class="empty-state">No saved recipes yet. Click "Save" on any recipe!</li>`;
      return;
    }

    this.favoritesList.innerHTML = favorites
      .map(
        (recipe) => `
        <li class="list-item" data-id="${recipe.id}">
          <div class="list-item-info">
            <span class="list-item-title" data-action="view">${recipe.title}</span>
            <span class="list-item-sub">⏱️ ${recipe.readyInMinutes}m • 🔥 ${recipe.nutrition.calories} kcal</span>
          </div>
          <div class="list-item-actions">
            <button class="btn btn-sm btn-primary" data-action="plan">+ Plan</button>
            <button class="btn btn-sm btn-outline" data-action="remove-fav" aria-label="Remove favorite">✕</button>
          </div>
        </li>
      `
      )
      .join('');
  }

  renderPlanner(planner) {
    const totals = planner.getTotalNutrition();
    this.totalCalories.textContent = totals.calories;
    this.totalProtein.textContent = `${totals.protein}g`;
    this.totalCarbs.textContent = `${totals.carbs}g`;
    this.totalFat.textContent = `${totals.fat}g`;

    if (!planner.scheduledMeals.length) {
      this.plannerList.innerHTML = `<li class="empty-state">Add meals to calculate daily totals.</li>`;
      return;
    }

    this.plannerList.innerHTML = planner.scheduledMeals
      .map(
        ({ entryId, mealSlot, recipe }) => `
        <li class="list-item" data-entry-id="${entryId}" data-id="${recipe.id}">
          <div class="list-item-info">
            <span class="list-item-title" data-action="view">[${mealSlot}] ${recipe.title}</span>
            <span class="list-item-sub">${recipe.nutrition.calories} kcal • P: ${recipe.nutrition.protein}g • C: ${recipe.nutrition.carbs}g • F: ${recipe.nutrition.fat}g</span>
          </div>
          <button class="btn btn-sm btn-outline" data-action="remove-plan" aria-label="Remove from planner">✕</button>
        </li>
      `
      )
      .join('');
  }

  openRecipeModal(recipe, isFavorite, onAddToPlan) {
    let currentServings = recipe.servings;

    const renderModalContent = () => {
      const scaledIngredients = recipe.getScaledIngredients(currentServings);
      this.modalBody.innerHTML = `
        <img src="${recipe.image}" alt="${recipe.title}" class="modal-hero" />
        <h2 id="modal-title">${recipe.title}</h2>
        <p style="color: var(--text-secondary); margin-top: 0.25rem;">
          ⏱️ ${recipe.readyInMinutes} mins • 🔥 ${recipe.nutrition.calories} kcal •
          Protein: ${recipe.nutrition.protein}g • Carbs: ${recipe.nutrition.carbs}g • Fat: ${recipe.nutrition.fat}g
        </p>

        <div class="modal-controls">
          <div class="servings-control">
            <strong>Servings:</strong>
            <button type="button" class="btn btn-sm btn-outline" id="dec-servings">-</button>
            <span>${currentServings}</span>
            <button type="button" class="btn btn-sm btn-outline" id="inc-servings">+</button>
          </div>
          <div class="servings-control">
            <select id="modal-meal-slot" style="padding: 0.35rem; border-radius: 6px;">
              <option value="Breakfast">Breakfast</option>
              <option value="Lunch">Lunch</option>
              <option value="Dinner" selected>Dinner</option>
              <option value="Snack">Snack</option>
            </select>
            <button type="button" class="btn btn-sm btn-primary" id="modal-add-plan">+ Add to Planner</button>
          </div>
        </div>

        <h3>Ingredients Checklist</h3>
        <ul class="ingredient-list">
          ${scaledIngredients
            .map(
              (ing) => `
              <li>
                <label>
                  <input type="checkbox" />
                  <span>${ing.formatted}</span>
                </label>
              </li>
            `
            )
            .join('')}
        </ul>

        <h3>Cooking Instructions</h3>
        <ol class="instructions-list">
          ${recipe.instructions.map((step) => `<li>${step}</li>`).join('')}
        </ol>
      `;

      document.getElementById('dec-servings').addEventListener('click', () => {
        if (currentServings > 1) {
          currentServings--;
          renderModalContent();
        }
      });

      document.getElementById('inc-servings').addEventListener('click', () => {
        currentServings++;
        renderModalContent();
      });

      document.getElementById('modal-add-plan').addEventListener('click', () => {
        const slot = document.getElementById('modal-meal-slot').value;
        onAddToPlan(recipe, slot);
        this.closeModal();
      });
    };

    renderModalContent();
    this.modal.classList.remove('hidden');
  }

  closeModal() {
    this.modal.classList.add('hidden');
  }
}