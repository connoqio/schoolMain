import { RecipeAPI } from './RecipeAPI.js';
import { MealPlanner } from './MealPlanner.js';
import { UI } from './UI.js';

// Paste your Spoonacular API key below (leave as-is to test with built-in demo recipes)
const API_KEY = '79b8b544cc744cf7a1190098f8cea072';

const api = new RecipeAPI(API_KEY);
const planner = new MealPlanner();
const ui = new UI();

let currentRecipes = [];
let activeFilter = 'all';

// Initialize persisted state & theme
function init() {
  planner.loadPlannerState();
  initTheme();
  ui.renderFavorites(planner.favorites);
  ui.renderPlanner(planner);


  performSearch();
  bindEvents();
}

function initTheme() {
  const savedTheme = localStorage.getItem('culinary_theme') || 'light';
  document.documentElement.setAttribute('data-theme', savedTheme);
  document.getElementById('theme-toggle').textContent = savedTheme === 'dark' ? '☀️' : '🌙';
}

async function performSearch() {
  const query = document.getElementById('search-input').value;
  const type = document.getElementById('category-select').value;

  ui.showLoadingSkeletons(4);

  try {
    currentRecipes = await api.searchRecipes({ query, type });
    applyFilterAndRender();
  } catch (err) {
    ui.showStatus(err.message);
    ui.renderRecipes([], planner);
  }
}

function applyFilterAndRender() {
  const filtered = currentRecipes.filter((recipe) => recipe.matchesFilter(activeFilter));
  ui.renderRecipes(filtered, planner);
}

function findRecipeById(id) {
  const numId = Number(id);
  return (
    currentRecipes.find((r) => r.id === numId) ||
    planner.favorites.find((r) => r.id === numId) ||
    planner.scheduledMeals.find((m) => m.recipe.id === numId)?.recipe
  );
}

function bindEvents() {
  // Search Form
  document.getElementById('search-form').addEventListener('submit', (e) => {
    e.preventDefault();
    performSearch();
  });

  // Filter Chips (Event Delegation)
  document.getElementById('filter-chips').addEventListener('click', (e) => {
    const chip = e.target.closest('.chip');
    if (!chip) return;

    document.querySelectorAll('.chip').forEach((c) => c.classList.remove('active'));
    chip.classList.add('active');
    activeFilter = chip.dataset.filter;
    applyFilterAndRender();
  });

  // Recipe Grid Actions (Event Delegation)
  document.getElementById('recipe-grid').addEventListener('click', (e) => {
    const actionEl = e.target.closest('[data-action]');
    const card = e.target.closest('.recipe-card');
    if (!actionEl || !card) return;

    const recipe = findRecipeById(card.dataset.id);
    if (!recipe) return;

    const action = actionEl.dataset.action;
    if (action === 'view') {
      ui.openRecipeModal(recipe, planner.isFavorite(recipe.id), (rec, slot) => {
        planner.addMealToPlan(rec, slot);
        ui.renderPlanner(planner);
      });
    } else if (action === 'favorite') {
      planner.toggleFavorite(recipe);
      applyFilterAndRender();
      ui.renderFavorites(planner.favorites);
    } else if (action === 'plan') {
      planner.addMealToPlan(recipe, 'Meal');
      ui.renderPlanner(planner);
    }
  });

  // Favorites List Actions (Event Delegation)
  document.getElementById('favorites-list').addEventListener('click', (e) => {
    const actionEl = e.target.closest('[data-action]');
    const item = e.target.closest('.list-item');
    if (!actionEl || !item) return;

    const recipe = findRecipeById(item.dataset.id);
    if (!recipe) return;

    const action = actionEl.dataset.action;
    if (action === 'view') {
      ui.openRecipeModal(recipe, true, (rec, slot) => {
        planner.addMealToPlan(rec, slot);
        ui.renderPlanner(planner);
      });
    } else if (action === 'plan') {
      planner.addMealToPlan(recipe, 'Meal');
      ui.renderPlanner(planner);
    } else if (action === 'remove-fav') {
      planner.toggleFavorite(recipe);
      applyFilterAndRender();
      ui.renderFavorites(planner.favorites);
    }
  });

  // Planner List Actions (Event Delegation)
  document.getElementById('planner-list').addEventListener('click', (e) => {
    const actionEl = e.target.closest('[data-action]');
    const item = e.target.closest('.list-item');
    if (!actionEl || !item) return;

    if (actionEl.dataset.action === 'remove-plan') {
      planner.removeMealFromPlan(item.dataset.entryId);
      ui.renderPlanner(planner);
    } else if (actionEl.dataset.action === 'view') {
      const recipe = findRecipeById(item.dataset.id);
      if (recipe) {
        ui.openRecipeModal(recipe, planner.isFavorite(recipe.id), (rec, slot) => {
          planner.addMealToPlan(rec, slot);
          ui.renderPlanner(planner);
        });
      }
    }
  });

  // Clear Planner
  document.getElementById('clear-planner-btn').addEventListener('click', () => {
    planner.clearPlan();
    ui.renderPlanner(planner);
  });

  // Modal Close
  document.getElementById('close-modal-btn').addEventListener('click', () => ui.closeModal());
  document.getElementById('recipe-modal').addEventListener('click', (e) => {
    if (e.target.id === 'recipe-modal') ui.closeModal();
  });

  // Dark / Light Theme Toggle
  document.getElementById('theme-toggle').addEventListener('click', () => {
    const current = document.documentElement.getAttribute('data-theme');
    const next = current === 'dark' ? 'light' : 'dark';
    document.documentElement.setAttribute('data-theme', next);
    localStorage.setItem('culinary_theme', next);
    document.getElementById('theme-toggle').textContent = next === 'dark' ? '☀️' : '🌙';
  });
}

init();