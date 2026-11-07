const global = {
  currentPage: window.location.pathname,
  search: {
    term: '',
    type: 'movie',
    page: 1,
    totalPages: 1,
    totalResults: 0,
  },
  api: {
    apiKey: '6c75c8311a960f0d3a9d21d504670e1f',
    apiUrl: 'https://api.themoviedb.org/3/',
  },
};

let activeRequests = 0;
const FAVORITES_KEY = 'flixx-favorites';

/* ---------- Router ---------- */

function init() {
  const page = global.currentPage.split('/').pop();

  switch (page) {
    case '':
    case 'index.html':
      displaySlider();
      displayPopularMovies();
      break;
    case 'shows.html':
      displayPopularShows();
      break;
    case 'movie-details.html':
      displayMovieDetails();
      break;
    case 'tv-details.html':
      displayShowDetails();
      break;
    case 'search.html':
      search();
      break;
    case 'favorites.html':
      displayFavorites();
      break;
  }

  highlightActiveLink();
}

document.addEventListener('DOMContentLoaded', init);

function highlightActiveLink() {
  const currentFile = global.currentPage.split('/').pop() || 'index.html';

  document.querySelectorAll('.nav-link').forEach((link) => {
    if (link.getAttribute('href') === currentFile) {
      link.classList.add('active');
    }
  });
}

/* ---------- Helpers ---------- */

function escapeHTML(text = '') {
  return String(text)
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;')
    .replace(/"/g, '&quot;')
    .replace(/'/g, '&#39;');
}

function addCommasToNumber(number) {
  return number.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',');
}

function posterImage(path, alt) {
  const src = path
    ? `https://image.tmdb.org/t/p/w500${path}`
    : 'images/no-image.jpg';
  return `<img src="${src}" class="card-img-top" alt="${escapeHTML(alt)}" />`;
}

function createCard({ id, type, title, posterPath, dateLabel, date, extra = '' }) {
  const div = document.createElement('div');
  div.classList.add('card');
  div.innerHTML = `
    <a href="${type === 'movie' ? 'movie-details.html' : 'tv-details.html'}?id=${id}">
      ${posterImage(posterPath, title)}
    </a>
    <div class="card-body">
      <h5 class="card-title">${escapeHTML(title)}</h5>
      <p class="card-text">
        <small class="text-muted">${dateLabel}: ${date || 'N/A'}</small>
      </p>
      ${extra}
    </div>
  `;
  return div;
}

/* ---------- API ---------- */

async function fetchAPIData(endpoint) {
  const { apiKey, apiUrl } = global.api;

  showSpinner();
  try {
    const response = await fetch(
      `${apiUrl}${endpoint}?api_key=${apiKey}&language=en-US`
    );
    if (!response.ok) throw new Error(`Request failed (${response.status})`);
    return await response.json();
  } finally {
    hideSpinner();
  }
}

async function searchAPIData() {
  const { apiKey, apiUrl } = global.api;
  const { type, term, page } = global.search;

  showSpinner();
  try {
    const response = await fetch(
      `${apiUrl}search/${type}?api_key=${apiKey}&language=en-US&query=${encodeURIComponent(
        term
      )}&page=${page}`
    );
    if (!response.ok) throw new Error(`Request failed (${response.status})`);
    return await response.json();
  } finally {
    hideSpinner();
  }
}

/* ---------- Spinner & alerts ---------- */

function showSpinner() {
  activeRequests++;
  const spinner = document.querySelector('.spinner');
  if (spinner) spinner.classList.add('show');
}

function hideSpinner() {
  activeRequests = Math.max(0, activeRequests - 1);
  if (activeRequests === 0) {
    const spinner = document.querySelector('.spinner');
    if (spinner) spinner.classList.remove('show');
  }
}

function showAlert(message, className = 'error') {
  const container = document.querySelector('#alert');
  if (!container) return;

  const alertEl = document.createElement('div');
  alertEl.classList.add('alert', className);
  alertEl.appendChild(document.createTextNode(message));
  container.appendChild(alertEl);

  setTimeout(() => alertEl.remove(), 3000);
}

/* ---------- Home page ---------- */

async function displaySlider() {
  const { results } = await fetchAPIData('movie/now_playing');
  const wrapper = document.querySelector('.swiper-wrapper');

  results.forEach((movie) => {
    const div = document.createElement('div');
    div.classList.add('swiper-slide');
    div.innerHTML = `
      <a href="movie-details.html?id=${movie.id}">
        <img
          src="${
            movie.poster_path
              ? `https://image.tmdb.org/t/p/w500${movie.poster_path}`
              : 'images/no-image.jpg'
          }"
          alt="${escapeHTML(movie.title)}"
        />
      </a>
      <h4 class="swiper-rating">
        <i class="fas fa-star text-secondary"></i> ${movie.vote_average.toFixed(1)} / 10
      </h4>
    `;
    wrapper.appendChild(div);
  });

  initSwiper();
}

function initSwiper() {
  new Swiper('.swiper', {
    slidesPerView: 1,
    spaceBetween: 30,
    freeMode: true,
    loop: true,
    autoplay: {
      delay: 4000,
      disableOnInteraction: false,
    },
    breakpoints: {
      500: { slidesPerView: 2 },
      700: { slidesPerView: 3 },
      1200: { slidesPerView: 4 },
    },
  });
}

async function displayPopularMovies() {
  const { results } = await fetchAPIData('movie/popular');
  const grid = document.querySelector('#popular-movies');

  results.forEach((movie) => {
    grid.appendChild(
      createCard({
        id: movie.id,
        type: 'movie',
        title: movie.title,
        posterPath: movie.poster_path,
        dateLabel: 'Release',
        date: movie.release_date,
      })
    );
  });
}

/* ---------- Shows page ---------- */

async function displayPopularShows() {
  const { results } = await fetchAPIData('tv/popular');
  const grid = document.querySelector('#popular-shows');

  results.forEach((show) => {
    grid.appendChild(
      createCard({
        id: show.id,
        type: 'tv',
        title: show.name,
        posterPath: show.poster_path,
        dateLabel: 'First Air Date',
        date: show.first_air_date,
      })
    );
  });
}

/* ---------- Detail pages ---------- */

async function displayMovieDetails() {
  const movieId = new URLSearchParams(window.location.search).get('id');
  const movie = await fetchAPIData(`movie/${movieId}`);

  displayBackgroundImage('movie', movie.backdrop_path);

  const div = document.createElement('div');
  div.innerHTML = `
    <div class="details-top">
      <div>
        ${posterImage(movie.poster_path, movie.title)}
      </div>
      <div>
        <h2>${escapeHTML(movie.title)}</h2>
        <p>
          <i class="fas fa-star text-primary"></i>
          ${movie.vote_average.toFixed(1)} / 10
        </p>
        <p class="text-muted">Release Date: ${movie.release_date || 'N/A'}</p>
        <p>${movie.overview}</p>
        <h5>Genres</h5>
        <ul class="list-group">
          ${movie.genres.map((genre) => `<li>${genre.name}</li>`).join('')}
        </ul>
        <div class="details-actions">
          ${
            movie.homepage
              ? `<a href="${movie.homepage}" target="_blank" class="btn">Visit Movie Homepage</a>`
              : ''
          }
          <button type="button" class="btn" id="favorite-btn"></button>
        </div>
      </div>
    </div>
    <div class="details-bottom">
      <h2>Movie Info</h2>
      <ul>
        <li><span class="text-secondary">Budget:</span> $${addCommasToNumber(movie.budget)}</li>
        <li><span class="text-secondary">Revenue:</span> $${addCommasToNumber(movie.revenue)}</li>
        <li><span class="text-secondary">Runtime:</span> ${movie.runtime} minutes</li>
        <li><span class="text-secondary">Status:</span> ${movie.status}</li>
      </ul>
      <h4>Production Companies</h4>
      <div class="list-group">
        ${movie.production_companies.map((company) => company.name).join(', ')}
      </div>
    </div>
  `;

  document.querySelector('#movie-details').appendChild(div);

  setupFavoriteButton({
    id: movie.id,
    type: 'movie',
    title: movie.title,
    posterPath: movie.poster_path,
    date: movie.release_date,
  });
}

async function displayShowDetails() {
  const showId = new URLSearchParams(window.location.search).get('id');
  const show = await fetchAPIData(`tv/${showId}`);

  displayBackgroundImage('tv', show.backdrop_path);

  const div = document.createElement('div');
  div.innerHTML = `
    <div class="details-top">
      <div>
        ${posterImage(show.poster_path, show.name)}
      </div>
      <div>
        <h2>${escapeHTML(show.name)}</h2>
        <p>
          <i class="fas fa-star text-primary"></i>
          ${show.vote_average.toFixed(1)} / 10
        </p>
        <p class="text-muted">First Air Date: ${show.first_air_date || 'N/A'}</p>
        <p>${show.overview}</p>
        <h5>Genres</h5>
        <ul class="list-group">
          ${show.genres.map((genre) => `<li>${genre.name}</li>`).join('')}
        </ul>
        <div class="details-actions">
          ${
            show.homepage
              ? `<a href="${show.homepage}" target="_blank" class="btn">Visit Show Homepage</a>`
              : ''
          }
          <button type="button" class="btn" id="favorite-btn"></button>
        </div>
      </div>
    </div>
    <div class="details-bottom">
      <h2>Show Info</h2>
      <ul>
        <li><span class="text-secondary">Number Of Episodes:</span> ${show.number_of_episodes}</li>
        <li><span class="text-secondary">Last Episode To Air:</span> ${
          show.last_episode_to_air ? show.last_episode_to_air.name : 'N/A'
        }</li>
        <li><span class="text-secondary">Status:</span> ${show.status}</li>
      </ul>
      <h4>Production Companies</h4>
      <div class="list-group">
        ${show.production_companies.map((company) => company.name).join(', ')}
      </div>
    </div>
  `;

  document.querySelector('#show-details').appendChild(div);

  setupFavoriteButton({
    id: show.id,
    type: 'tv',
    title: show.name,
    posterPath: show.poster_path,
    date: show.first_air_date,
  });
}

function displayBackgroundImage(type, backgroundPath) {
  if (!backgroundPath) return;

  const overlayDiv = document.createElement('div');

  overlayDiv.style.backgroundImage = `url(https://image.tmdb.org/t/p/original${backgroundPath})`;
  overlayDiv.style.backgroundSize = 'cover';
  overlayDiv.style.backgroundPosition = 'center';
  overlayDiv.style.backgroundRepeat = 'no-repeat';
  overlayDiv.style.height = '100vh';
  overlayDiv.style.width = '100vw';
  overlayDiv.style.position = 'absolute';
  overlayDiv.style.top = '0';
  overlayDiv.style.left = '0';
  overlayDiv.style.zIndex = '-1';
  overlayDiv.style.opacity = '0.1';

  if (type === 'movie') {
    document.querySelector('#movie-details').appendChild(overlayDiv);
  } else {
    document.querySelector('#show-details').appendChild(overlayDiv);
  }
}

/* ---------- Search ---------- */

async function search() {
  const params = new URLSearchParams(window.location.search);
  const type = params.get('type') === 'tv' ? 'tv' : 'movie';
  const term = (params.get('search-term') || '').trim();

  global.search.type = type;
  global.search.term = term;
  global.search.page = 1;

  // Keep the radio button and input in sync with the URL
  const radio = document.querySelector(`#${type}`);
  if (radio) radio.checked = true;
  document.querySelector('#search-term').value = term;

  if (term === '') {
    showAlert('Please enter a search term');
    return;
  }

  const data = await searchAPIData();

  global.search.page = data.page;
  global.search.totalPages = data.total_pages;
  global.search.totalResults = data.total_results;

  if (data.results.length === 0) {
    showAlert('No results found');
    return;
  }

  displaySearchResults(data.results);
}

function displaySearchResults(results) {
  const resultsEl = document.querySelector('#search-results');
  const headingEl = document.querySelector('#search-results-heading');

  // Clear the previous page of results
  resultsEl.innerHTML = '';
  headingEl.innerHTML = '';
  document.querySelector('#pagination').innerHTML = '';

  const { type } = global.search;

  results.forEach((result) => {
    resultsEl.appendChild(
      createCard({
        id: result.id,
        type,
        title: type === 'movie' ? result.title : result.name,
        posterPath: result.poster_path,
        dateLabel: type === 'movie' ? 'Release' : 'First Air Date',
        date: type === 'movie' ? result.release_date : result.first_air_date,
      })
    );
  });

  const h2 = document.createElement('h2');
  h2.textContent = `${results.length} of ${global.search.totalResults} results for "${global.search.term}"`;
  headingEl.appendChild(h2);

  displayPagination();
}

function displayPagination() {
  const { page, totalPages } = global.search;

  const div = document.createElement('div');
  div.classList.add('pagination');
  div.innerHTML = `
    <button class="btn btn-primary" id="prev">Prev</button>
    <button class="btn btn-primary" id="next">Next</button>
    <div class="page-counter">Page ${page} of ${totalPages}</div>
  `;
  document.querySelector('#pagination').appendChild(div);

  const prevBtn = document.querySelector('#prev');
  const nextBtn = document.querySelector('#next');

  if (page === 1) prevBtn.disabled = true;
  if (page >= totalPages) nextBtn.disabled = true;

  nextBtn.addEventListener('click', () => goToPage(global.search.page + 1));
  prevBtn.addEventListener('click', () => goToPage(global.search.page - 1));
}

async function goToPage(newPage) {
  global.search.page = newPage;

  const data = await searchAPIData();
  global.search.totalPages = data.total_pages;
  global.search.totalResults = data.total_results;

  displaySearchResults(data.results);
  window.scrollTo({ top: 0, behavior: 'smooth' });
}

/* ---------- Favorites (extra feature) ---------- */

function getFavorites() {
  try {
    return JSON.parse(localStorage.getItem(FAVORITES_KEY)) || [];
  } catch (error) {
    return [];
  }
}

function saveFavorites(favorites) {
  localStorage.setItem(FAVORITES_KEY, JSON.stringify(favorites));
}

function isFavorite(type, id) {
  return getFavorites().some((fav) => fav.type === type && fav.id === Number(id));
}

function toggleFavorite(item) {
  const favorites = getFavorites();
  const index = favorites.findIndex(
    (fav) => fav.type === item.type && fav.id === item.id
  );

  if (index >= 0) {
    favorites.splice(index, 1);
  } else {
    favorites.push(item);
  }

  saveFavorites(favorites);
}

function setupFavoriteButton(item) {
  const btn = document.querySelector('#favorite-btn');
  if (!btn) return;

  const updateLabel = () => {
    btn.innerHTML = isFavorite(item.type, item.id)
      ? '<i class="fas fa-heart"></i> Remove From Favorites'
      : '<i class="fas fa-heart"></i> Add To Favorites';
  };

  updateLabel();

  btn.addEventListener('click', () => {
    toggleFavorite(item);
    updateLabel();
  });
}

function displayFavorites() {
  const container = document.querySelector('#favorites');

  container.addEventListener('click', (e) => {
    const btn = e.target.closest('.remove-favorite');
    if (!btn) return;

    const type = btn.dataset.type;
    const id = Number(btn.dataset.id);
    saveFavorites(getFavorites().filter((fav) => !(fav.type === type && fav.id === id)));
    renderFavorites();
  });

  renderFavorites();
}

function renderFavorites() {
  const container = document.querySelector('#favorites');
  const emptyMessage = document.querySelector('#favorites-empty');
  const favorites = getFavorites();

  container.innerHTML = '';
  emptyMessage.style.display = favorites.length ? 'none' : 'block';

  favorites.forEach((fav) => {
    container.appendChild(
      createCard({
        id: fav.id,
        type: fav.type,
        title: fav.title,
        posterPath: fav.posterPath,
        dateLabel: fav.type === 'movie' ? 'Release' : 'First Air Date',
        date: fav.date,
        extra: `<button type="button" class="btn remove-favorite" data-type="${fav.type}" data-id="${fav.id}">Remove</button>`,
      })
    );
  });
}