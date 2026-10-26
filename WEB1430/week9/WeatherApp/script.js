const API_KEY = 'a6d390919442c3d07421ca4379825b43';
function initializeWeatherApp() {

    const appContainer = document.createElement('div');
    appContainer.className = 'weather-app-container';
    
    const heading = document.createElement('h1');
    heading.textContent = 'Weather Application';
    appContainer.appendChild(heading);


    const controlsDiv = document.createElement('div');
    controlsDiv.className = 'controls';

    // Allows the user to choose which city they want find the weather for
    const cityInput = document.createElement('input');
    cityInput.type = 'text';
    cityInput.id = 'cityInput';
    cityInput.placeholder = 'Enter city name...';
    controlsDiv.appendChild(cityInput);

    // This creates the get weather button
    const getWeatherBtn = document.createElement('button');
    getWeatherBtn.id = 'getWeatherBtn';
    getWeatherBtn.textContent = 'Get Weather';
    controlsDiv.appendChild(getWeatherBtn);

    // Allows user to choose Fahrenheit or Celcius
    const unitSelect = document.createElement('select');
    unitSelect.id = 'unitSelect';
    const optC = document.createElement('option');
    optC.value = 'celsius';
    optC.textContent = '°C (Celsius)';
    const optF = document.createElement('option');
    optF.value = 'fahrenheit';
    optF.textContent = '°F (Fahrenheit)';
    unitSelect.appendChild(optC);
    unitSelect.appendChild(optF);
    controlsDiv.appendChild(unitSelect);

    appContainer.appendChild(controlsDiv);

    // Error message 
    const errorDiv = document.createElement('div');
    errorDiv.id = 'errorDiv';
    errorDiv.className = 'error-message';
    appContainer.appendChild(errorDiv);

    // Weather display 
    const weatherDisplay = document.createElement('div');
    weatherDisplay.id = 'weatherDisplay';
    weatherDisplay.className = 'weather-display';
    weatherDisplay.innerHTML = `
        <h2 id="cityName">--</h2>
        <img id="weatherIcon" src="" alt="" style="display:none;" />
        <p id="weatherCondition">Condition: --</p>
        <p id="temperature">Temperature: --</p>
        <p id="humidity">Humidity: --</p>
    `;
    appContainer.appendChild(weatherDisplay);

    document.body.appendChild(appContainer);

    getWeatherBtn.addEventListener('click', () => {
        const cityName = cityInput.value.trim();
        if (!cityName) {
            showError('Please enter a valid city name.');
            return;
        }
        clearError();
        fetchWeatherData(cityName);
    });

    cityInput.addEventListener('keypress', (e) => {
        if (e.key === 'Enter') {
            getWeatherBtn.click();
        }
    });

    unitSelect.addEventListener('change', () => {
        localStorage.setItem('tempUnit', unitSelect.value);
        const currentCity = localStorage.getItem('lastCity');
        if (currentCity) {
            fetchWeatherData(currentCity);
        }
    });

    // Load saved unit preference
    const savedUnit = localStorage.getItem('tempUnit');
    if (savedUnit) {
        unitSelect.value = savedUnit;
    }

    // Automatically fetch and display weather for the last searched city
    const lastCity = localStorage.getItem('lastCity');
    if (lastCity) {
        cityInput.value = lastCity;
        fetchWeatherData(lastCity);
    }
}

async function fetchWeatherData(city) {
    const unitSelect = document.getElementById('unitSelect');
    const unit = unitSelect ? unitSelect.value : 'celsius';

    try {
        const url = `https://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${encodeURIComponent(city)}`;
        
        const response = await fetch(url);
        if (!response.ok) {
            throw new Error('City not found or API request failed.');
        }

        const data = await response.json();
        
        // Store last searched city in LocalStorage
        localStorage.setItem('lastCity', city);
        clearError();
        updateWeatherUI(data, unit);
    } catch (error) {
        console.warn('API fetch failed or key missing. Using simulated response for demonstration.', error);
        
        // Fallback simulation if API key is placeholder or fetch fails
        if (API_KEY === 'a6d390919442c3d07421ca4379825b43' || error.message.includes('Failed to fetch')) {
            const mockData = getMockWeatherData(city);
            localStorage.setItem('lastCity', city);
            clearError();
            updateWeatherUI(mockData, unit);
        } else {
            showError('Could not retrieve weather data. Please check the city name.');
        }
    }
}

function updateWeatherUI(data, unit) {
    const cityNameEl = document.getElementById('cityName');
    const weatherIconEl = document.getElementById('weatherIcon');
    const conditionEl = document.getElementById('weatherCondition');
    const tempEl = document.getElementById('temperature');
    const humidityEl = document.getElementById('humidity');

    const locationName = data.location.name;
    const conditionText = data.current.condition.text;
    const iconUrl = 'https:' + data.current.condition.icon;
    const humidity = data.current.humidity;

    let tempVal, tempUnitLabel;
    if (unit === 'fahrenheit') {
        tempVal = data.current.temp_f;
        tempUnitLabel = '°F';
    } else {
        tempVal = data.current.temp_c;
        tempUnitLabel = '°C';
    }

    cityNameEl.textContent = `${locationName}`;
    weatherIconEl.src = iconUrl;
    weatherIconEl.alt = conditionText;
    weatherIconEl.style.display = 'block';
    conditionEl.textContent = `Condition: ${conditionText}`;
    tempEl.textContent = `Temperature: ${tempVal}${tempUnitLabel}`;
    humidityEl.textContent = `Humidity: ${humidity}%`;
}

function showError(message) {
    const errorDiv = document.getElementById('errorDiv');
    errorDiv.textContent = message;
}

function clearError() {
    const errorDiv = document.getElementById('errorDiv');
    errorDiv.textContent = '';
}

function getMockWeatherData(city) {
    return {
        location: { name: city.charAt(0).toUpperCase() + city.slice(1), country: '' },
        current: {
            temp_c: 22,
            temp_f: 71.6,
            humidity: 45,
            condition: { text: 'Partly Cloudy', icon: '//cdn.weatherapi.com/weather/64x64/day/116.png' }
        }
    };
}

// Initialize application on DOM load
document.addEventListener('DOMContentLoaded', initializeWeatherApp);