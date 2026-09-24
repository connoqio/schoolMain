function initializeDashboard(){
    const container = document.getElementById('mission-container');

    const heading = document.createElement('h1');
    heading.textContent = 'Secret Agent Dashboard';
    container.prepend(heading);
}

initializeDashboard();