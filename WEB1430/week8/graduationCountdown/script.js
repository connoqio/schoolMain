let countdownInterval;

function initializeCountdown() {

    const gradH1 = document.createElement('h1');
    gradH1.textContent = "Graduation Countdown Timer";
    document.body.appendChild(gradH1);

    const display = document.createElement('p');
    display.id = 'countdown-display';
    display.textContent = startCountdown();
    document.body.appendChild(display);

    countdownInterval = setInterval(() => {
        display.textContent = startCountdown();
    }, 1000);

    checkCountdownZero(display);

    //start countdown button
    const startButton = document.createElement('button');
    startButton.textContent = "Start Countdown";
    if (!countdownInterval) {
        startButton.addEventListener('click', () => {
            countdownInterval = setInterval(() => {
                display.textContent = startCountdown();
            }, 1000);
        });
    }
    document.body.appendChild(startButton);

    //stop countdown button
    const stopButton = document.createElement('button');
    stopButton.textContent = "Stop Countdown";
    stopButton.addEventListener('click', () => {
        clearInterval(countdownInterval);
        countdownInterval = null;
    });
    document.body.appendChild(stopButton);

    //set countdown to 0
    const resetButton = document.createElement('button');
    resetButton.textContent = "Reset Countdown";
    resetButton.addEventListener('click', () => {
        clearInterval(countdownInterval);
        countdownInterval = null;
        display.textContent = "0d 0h 0m 0s";
    });
    document.body.appendChild(resetButton);
}

function startCountdown(){
    const countdownDate = new Date("June 1, 2027 00:00:00").getTime();

    const curDate = new Date().getTime();
    const distance = countdownDate - curDate;

    if (distance <= 0) return "0d 0h 0m 0s";
    

    const days = Math.floor(distance / (1000 * 60 * 60 * 24));
    const hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    const minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
    const seconds = Math.floor((distance % (1000 * 60)) / 1000);

    return `${days}d ${hours}h ${minutes}m ${seconds}s`;
}

// function fetchCelebrationMessageCallback(callback) {
//     const xhr = new XMLHttpRequest();
//     xhr.open('GET', 'celebrations.json', true);
    
//     xhr.onload = function() {
//         if (xhr.status === 200) {
//             const messages = JSON.parse(xhr.responseText);
//             const randomMessage = messages[Math.floor(Math.random() * messages.length)];
            
//             // Update the page with the message
//             let display = document.getElementById('celebration-display');
//             if (!display) {
//                 display = document.createElement('div');
//                 display.id = 'celebration-display';
//                 document.body.appendChild(display);
//             }
//             display.textContent = randomMessage;
            
//             // Return the message using the callback function
//             if (typeof callback === 'function') {
//                 callback(randomMessage);
//             }
//         }
//     };
    
//     xhr.send();
// }

function fetchCelebrationMessagePromise() {
    return new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest();
        xhr.open('GET', 'celebrations.json', true);
        
        xhr.onload = function() {
            if (xhr.status === 200) {
                const messages = JSON.parse(xhr.responseText);
                const randomMessage = messages[Math.floor(Math.random() * messages.length)];
                resolve(randomMessage);
            } else {
                reject(new Error('Failed to load celebrations.json'));
            }
        };
        
        xhr.onerror = function() {
            reject(new Error('Network error'));
        };
        
        xhr.send();
    });
}

    function checkCountdownZero(displayElement) {
    const countdownDate = new Date("June 1, 2027 00:00:00").getTime();
    const distance = countdownDate - new Date().getTime();

    if (distance <= 0) {
        fetchCelebrationMessagePromise()
            .then(randomMessage => {
                displayElement.textContent = randomMessage;
            })
            .catch(error => {
                console.error(error);
            });
    }
}

initializeCountdown();
startCountdown();
