//This consists of the arrays for the adventure game data
const adventure = {
    locations: ["Ancient Ruins", "Forbidden Forest", "Sunken Ship", "Mountain Peak", "Hidden Valley"],
    actions: ["explore", "escape", "discover treasure in", "climb", "navigate"],
    characters: ["an intrepid explorer", "a cunning pirate", "a mysterious stranger", "a daring adventurer", "a curious wizard"]
};

// This function is what gets a random item from each of the arrays
function getRandomItem(array)
{
    const randIndex = Math.floor(Math.random() * array.length);
    return array[randIndex];
}

// this is what gets the random location, action and adventure and the outputs that to the console
function GenerateAdventure()
{
    const randomLocation = getRandomItem(adventure.locations);
    const randomAction = getRandomItem(adventure.actions);
    const randomCharacter = getRandomItem(adventure.characters);

    const sentence = `You will ${randomAction} ${randomLocation} with ${randomCharacter}!`;
    console.log(sentence);
}

// this adds the mystic cave, destroy and a spooky sorcerer to their respective arrays
function addAdventureOption(array, newOption)
{
    array.push(newOption);
    console.log("Updated Array: ", array);
}

addAdventureOption(adventure.locations, "Mystic Cave")
addAdventureOption(adventure.actions, "destroy")
addAdventureOption(adventure.characters, "A spooky sorcerer")

GenerateAdventure();
GenerateAdventure();
GenerateAdventure();
