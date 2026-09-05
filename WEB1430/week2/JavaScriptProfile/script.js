
const firstName = prompt('What is your first name?');
const lastName = prompt('What is your last name?');
const nickName = prompt('What is your nickname?');

const fullName = firstName + ' ' + lastName;

console.log('Hello! My name is ' + fullName + ' but you can call me ' + nickName + '.');
console.log('Your full name has ' + fullName.length + ' characters.');

const heightCM = prompt('How tall are you in centimeters?');
const weightKG = prompt('How much do you weigh in kilograms?');

const heightIN = heightCM / 2.54;
const weightLB = weightKG * 2.20462;

console.log('Your height in inches is ' + heightIN.toFixed(2) + '.');
console.log('Your weight in pounds is ' + weightLB.toFixed(2) + '.');

const randomNumber = Math.floor(Math.random() * 3) + 1;

const funFactValue = randomNumber * 10;
console.log('Fun Fact: Did you know ' + funFactValue + ' is a cool number about me?');

const career = prompt('What career are you working towards?');
console.log('One of my goals is ' + career + '.')
console.log('This goal has ' + career.length + ' characters.');

const birthYear = prompt('What year were you born?');
const currentYear = new Date().getFullYear();
const age = currentYear - birthYear;
console.log('I am ' + age + ' years old, and ive lived approximately ' + (age * 365) + ' days so far.');

const currentDate = new Date();
const remainderOfDays = Math.ceil((new Date(currentYear, 11, 31) - currentDate) / (1000 * 60 * 60 * 24));
console.log('Today\'s date is ' + currentDate.toDateString() + ' and there are ' + remainderOfDays + ' days left in the year.');
