let userScore = 0;
let NPCScore = 0;
const choices = ['rock', 'paper', 'scissors'];

const userScoreEl = document.getElementById('userScore');
const npcScoreEl = document.getElementById('NPCScore');
const resultEl = document.getElementById('result');
const resetBtn = document.getElementById('reset');

function play(playerChoice) {
  if (userScore >= 5 || NPCScore >= 5) return;

  const computerChoice = choices[Math.floor(Math.random() * choices.length)];

  if (playerChoice === computerChoice) {
    showResult(`Tie! Both picked ${playerChoice}.`);
    return;
  }

  const isUserWin = 
    (playerChoice === 'rock' && computerChoice === 'scissors') ||
    (playerChoice === 'paper' && computerChoice === 'rock') ||
    (playerChoice === 'scissors' && computerChoice === 'paper');

  if (isUserWin) {
    userScore++;
    userScoreEl.textContent = userScore;
  } else {
    NPCScore++;
    npcScoreEl.textContent = NPCScore;
  }

  checkGameOver(isUserWin, playerChoice, computerChoice);
}

function checkGameOver(isUserWin, playerChoice, computerChoice) {
  const roundText = isUserWin 
    ? `You win this round! ${playerChoice} beats ${computerChoice}.`
    : `You lose this round! ${computerChoice} beats ${playerChoice}.`;

  if (userScore === 5 || NPCScore === 5) {
    const winnerText = userScore === 5 ? "You won the game!" : "Computer won the game!";
    showResult(`${roundText} ${winnerText}`);
    resetBtn.style.display = 'inline-block';
  } else {
    showResult(roundText);
  }
}

function showResult(text) {
  resultEl.textContent = text;
}

function resetGame() {
  userScore = 0;
  NPCScore = 0;
  userScoreEl.textContent = 0;
  npcScoreEl.textContent = 0;
  showResult("Pick your move!");
  resetBtn.style.display = 'none';
}