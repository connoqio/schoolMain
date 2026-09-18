

const inventory = [
    {id: 1, name: "Mouse", category: "Electronics", quantity: 50, price: 49.99},
    {id: 2, name: "Lamp", category: "Electronics", quantity: 10, price: 29.99},
    {id: 3, name: "Speaker", category: "Electronics", quantity: 5, price: 99.99},
    {id: 4, name: "Mouse Pad", category: "Office Supplies", quantity: 10, price: 15.99},
    {id: 5, name: "Pencil", category: "Office Supplies", quantity: 200, price: .99}
]

// this function is what adds to the inventory array
function addProduct(name, category, quantity, price){
    if (quantity <= 0 || price <= 0){
        console.error(
            `Error: cannot add "${name}". The quantity and price must be positive.`
        );
        return;
    }

    const newId = inventory.length > 0 ? Math.max(...inventory.map((item) => item.id)) + 1 : 1;

    const newProduct = {
        id: newId,
        name,
        category,
        quantity,
        price
    };

    inventory.push(newProduct);
    console.log(`Added product: "${name}" (id: ${newId})`)

};

//this function removes a product based on its id
function removeProduct(id){
    const index = inventory.findIndex((item) => item.id === id);

    if (index === -1) {
        console.error(`Error: cannot remove "${id}", it does not exist.`);
        return;
    }

    const removed = inventory.splice(index, 1)[0];
    console.log(`Removed product: "${removed.name}" (id: ${id})`)

};

//this function updates the quantity of an item
function updateProductQuantity(id, newQuantity){
    if (newQuantity <= 0){
        console.error(`Error: cannot update "${id}" quantity must be more then 0.`);
        return;
    }

    const product = inventory.find((item)=> item.id === id);

    if (!product) {
        console.error(`Error: product with id ${id} cannot `);
        return;
    }

    product.quantity= newQuantity;
    console.log(`Updated "${product.name}" (id: ${id}) to quantity ${newQuantity}`);

};

// this function is what generates a report
function generateReport() {
    console.log("\n====== INVENTORY REPORT ======\n   Low-stock is highlighted");

    inventory.forEach((item) => {
        if (item.quantity < 10){
        console.log(`%cID: ${item.id} Item: ${item.name} Category: ${item.category} \
Quantity: ${item.quantity} Price: $${item.price}`, "background-color: #7a4343")
        }

        else {
            console.log(`ID: ${item.id} Item: ${item.name} Category: ${item.category} \
Quantity: ${item.quantity} Price: $${item.price}`)
        }
    }
    )
};

//this filters by category
function filterByCategory(items, category){
    const filtered = items.filter(item => item.category.toLowerCase() === category.toLowerCase());

    if (filtered.length === 0) {
        return `No items found in category "${category}".`;
    }

    return filtered
        .map(item => `ID: ${item.id} | Item: ${item.name} | Qty: ${item.quantity} | Price: $${item.price}`)
        .join("\n");
};

// this function calculates the total value of everything in the array
function calculateTotalInventoryValue(){
    const totalValue = inventory.reduce((total, item) => total + 
    item.quantity * item.price, 0);

    console.log(`Total inventory value: $${totalValue.toFixed(2)}`);
  return totalValue;
};


// these are all the function calls
console.log(inventory);

addProduct("Cable", "Electronics", 40, 9.99);
addProduct("Dongle",  "Electronics", 15, 13.99)

removeProduct(1);
removeProduct(5)

updateProductQuantity(2, 7);
updateProductQuantity(7, 3);

generateReport()

console.log("\n" + filterByCategory(inventory, "electronics"))
console.log("\n" + filterByCategory(inventory, "office supplies"))


calculateTotalInventoryValue()

