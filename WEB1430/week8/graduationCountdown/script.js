let countdownInterval;

function initializeCountdown() {

    const gradH1 = document.createElement('h1');
    gradH1.textContent = "Graduation Countdown Timer";
    document.body.appendChild(gradH1);

    const display = document.createElement('p');
    display.id = 'countdown-display';
    display.textContent = startCountdown();
    document.body.appendChild(display);

    //start countdown button
    const startButton = document.createElement('button');
    startButton.textContent = "Start Countdown";
    document.body.appendChild(startButton);

    //stop countdown button
    const stopButton = document.createElement('button');
    stopButton.textContent = "Stop Countdown";
    document.body.appendChild(stopButton);

    //set countdown to 0
    const resetButton = document.createElement('button');
    resetButton.textContent = "Reset Countdown";
    document.body.appendChild(resetButton);
}

function startCountdown(){
    const countdownDate = new Date("June 1, 2027 00:00:00").getTime();

    const curDate = new Date().getTime();
    const distance = countdownDate - curDate;

    const days = Math.floor(distance / (1000 * 60 * 60 * 24));
    const hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    const minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
    const seconds = Math.floor((distance % (1000 * 60)) / 1000);

    return `${days}d ${hours}h ${minutes}m ${seconds}s`;
}

initializeCountdown();
startCountdown();