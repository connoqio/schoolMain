

const inventory = [
    {id: 1, name: "Mouse", category: "Electronics", quantity: 50, price: 49.99},
    {id: 2, name: "Lamp", category: "Electronics", quantity: 10, price: 29.99},
    {id: 3, name: "speaker", category: "Electronics", quantity: 5, price: 99.99},
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
    console.log("\n====== INVENTORY REPORT ======");

    inventory.forEach((item) => {
        if (item.quantity < 10){
        console.log(`%c${item.name + " " +  item.category}`, "background-color: red")
        }

        else {
            console.log(item)
        }
    }
    

    )




};


console.log(inventory);

addProduct("Cable", "Electronics", 40, 9.99);

removeProduct(1);

updateProductQuantity(2, 30);

generateReport()