 "use strict";

/* ---------- Base class ---------- */
class Character {
  #experience = 0; // private: only code inside this class can touch it

  constructor(name, health, strength) {
    this.name = name;
    this.health = health;
    this.maxHealth = health;
    this.strength = strength;
  }

  // Getter that reads experience like a normal property
  get experience() {
    return this.#experience;
  }

  // Setter that allows experience to go up, or stay the same, never down
  set experience(value) {
    if (typeof value !== "number" || Number.isNaN(value) || value < this.#experience) {
      throw new RangeError("Experience can never decrease.");
    }
    this.#experience = value;
  }

  describe() {
    return `${this.name} is a character with ${this.health} health and ${this.strength} strength.`;
  }
}

//  Prototype methods
Character.prototype.takeDamage = function (amount) {
  this.health = Math.max(0, this.health - amount);
  return this.health;
};

Character.prototype.heal = function (amount) {
  if (this.health === 0) return this.health; // fallen characters can't be healed
  this.health = Math.min(this.maxHealth, this.health + amount);
  return this.health;
};

// Subclasses
class Warrior extends Character {
  constructor(name, health, strength, weapon) {
    super(name, health, strength);
    this.weapon = weapon;
  }

  describe() {
    return `${this.name} is a Warrior with ${this.health} health and ${this.strength} strength, wielding ${this.weapon}.`;
  }
}

class Mage extends Character {
  constructor(name, health, strength, spell) {
    super(name, health, strength);
    this.spell = spell;
  }

  describe() {
    return `${this.name} is a Mage with ${this.health} health and ${this.strength} strength, casting ${this.spell}.`;
  }
}

/* ---------- UI ---------- */
const form = document.getElementById("character-form");
const typeSelect = document.getElementById("type");
const specialLabel = document.getElementById("special-label");
const specialInput = document.getElementById("special");
const amountInput = document.getElementById("amount");
const cardsEl = document.getElementById("characters");
const emptyEl = document.getElementById("empty");
const messageEl = document.getElementById("message");

const characters = []; // each entry: { id, type, character }
let nextId = 1;

function getAmount() {
  const value = parseInt(amountInput.value, 10);
  return Number.isFinite(value) && value > 0 ? value : 1;
}

function say(text, isWarning = false) {
  messageEl.textContent = text;
  messageEl.classList.toggle("warn", isWarning);
}

// Swap the label/placeholder for the class-specific field
typeSelect.addEventListener("change", () => {
  const isWarrior = typeSelect.value === "warrior";
  specialLabel.textContent = isWarrior ? "Weapon" : "Spell";
  specialInput.placeholder = isWarrior ? "Iron greatsword" : "Arcane bolt";
});

// Create a character from the form
form.addEventListener("submit", (event) => {
  event.preventDefault();
  const data = new FormData(form);
  const name = data.get("name").trim();
  const health = Number(data.get("health"));
  const strength = Number(data.get("strength"));
  const special = data.get("special").trim();
  if (!name || !special) return;

  const type = data.get("type");
  const character = type === "warrior"
    ? new Warrior(name, health, strength, special)
    : new Mage(name, health, strength, special);

  characters.push({ id: nextId++, type, character });
  say(`${name} joined the roster.`);
  form.reset();
  typeSelect.dispatchEvent(new Event("change"));
  render();
});

// One listener handles every card button (event delegation)
cardsEl.addEventListener("click", (event) => {
  const button = event.target.closest("button[data-action]");
  if (!button) return;

  const id = Number(button.dataset.id);
  const index = characters.findIndex((entry) => entry.id === id);
  if (index === -1) return;

  const { character } = characters[index];
  const amount = getAmount();

  switch (button.dataset.action) {
    case "damage":
      character.takeDamage(amount);
      say(character.health === 0
        ? `${character.name} has fallen.`
        : `${character.name} took ${amount} damage.`);
      break;
    case "heal":
      if (character.health === 0) {
        say(`${character.name} has fallen and can't be healed.`, true);
      } else {
        character.heal(amount);
        say(`${character.name} healed up to ${character.health} health.`);
      }
      break;
    case "xp":
      character.experience = character.experience + amount;
      say(`${character.name} gained ${amount} XP.`);
      break;
    case "lower-xp":
      try {
        character.experience = character.experience - amount;
      } catch (error) {
        say(`${error.message} ${character.name} keeps ${character.experience} XP.`, true);
      }
      break;
    case "remove":
      characters.splice(index, 1);
      say(`${character.name} left the roster.`);
      break;
  }
  render();
});

function el(tag, className, text) {
  const node = document.createElement(tag);
  if (className) node.className = className;
  if (text !== undefined) node.textContent = text;
  return node;
}

function actionButton(label, action, id, className) {
  const button = el("button", className, label);
  button.type = "button";
  button.dataset.action = action;
  button.dataset.id = id;
  return button;
}

function stat(label, value, className) {
  const wrap = el("div", className);
  wrap.append(el("dt", "", label), el("dd", "", String(value)));
  return wrap;
}

function buildCard({ id, type, character }) {
  const card = el("article", `card ${type}${character.health === 0 ? " fallen" : ""}`);

  const top = el("div", "card-top");
  top.append(el("h3", "", character.name), el("span", "class-tag", type === "warrior" ? "Warrior" : "Mage"));

  const percent = Math.round((character.health / character.maxHealth) * 100);
  const barLabel = el("div", "bar-label");
  barLabel.append(el("span", "", "Health"), el("span", "", `${character.health} / ${character.maxHealth}`));
  const bar = el("div", "bar");
  const fill = el("span", percent <= 25 ? "low" : "");
  fill.style.width = `${percent}%`;
  bar.append(fill);

  const stats = el("dl", "stats");
  stats.append(
    stat("Strength", character.strength),
    stat(type === "warrior" ? "Weapon" : "Spell", type === "warrior" ? character.weapon : character.spell),
    stat("XP", character.experience, "xp")
  );

  const actions = el("div", "actions");
  actions.append(
    actionButton("Take damage", "damage", id, "danger"),
    actionButton("Heal", "heal", id),
    actionButton("Gain XP", "xp", id),
    actionButton("Try to lower XP", "lower-xp", id, "quiet"),
    actionButton("Remove", "remove", id, "quiet")
  );

  card.append(top, el("p", "description", character.describe()), barLabel, bar, stats, actions);
  return card;
}

function render() {
  cardsEl.replaceChildren(...characters.map(buildCard));
  emptyEl.hidden = characters.length > 0;
}

render();