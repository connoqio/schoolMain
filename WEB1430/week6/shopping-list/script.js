const itemForm = document.getElementById('item-form');
const itemInput = document.getElementById('item-input');
const itemList = document.getElementById('item-list');
const clearBtn = document.getElementById('clear');
const itemFilter = document.getElementById('filter');
const formBtn = document.querySelector('button');
let isEditMode = false;

function onAddItemSubmit(e) {
    e.preventDefault();

    const newItem = itemInput.value;

    // Validate input
    if(newItem === ''){
        alert('Please enter an item');
        return;
    }

    if (isEditMode){
        const itemToEdit = itemList.querySelector('.edit-mode');

        removeItemsFromStorage(itemToEdit.textContent);
        itemToEdit.classList.remove('edit-mode');
        itemToEdit.remove();
        isEditMode = false;
    } else{
        if(checkIfItemExists(newItem)){
            alert('Item already exists');
            return;
        }
    }

    itemInput.value = '';


    //create item DOM elements

    addItemToDOM(newItem);

    //add item to local storage
    addItemToStorage(newItem);

    checkUI();
}
function addItemToDOM(newItem){
    const li = document.createElement('li');
    li.appendChild(document.createTextNode(newItem));

    const button = createButton('remove-item btn-link text-red');

    li.appendChild(button); 
    itemList.appendChild(li);

    itemInput.value = '';
}
function addItemToStorage(item){
    let itemsFromStorage = getItemsFromStorage();

    itemsFromStorage.push(item);

    if(localStorage.getItem('items') === null){
        itemsFromStorage = [];
    } else {
        itemsFromStorage = JSON.parse(localStorage.getItem('items'));
    }

    itemsFromStorage.push(item);
    localStorage.setItem('items', JSON.stringify(itemsFromStorage));
}

function getItemsFromStorage(){
    let itemsFromStorage;
if(localStorage.getItem('items') === null){
        itemsFromStorage = [];
    } else {
        itemsFromStorage = JSON.parse(localStorage.getItem('items'));
    }
    return itemsFromStorage;
}

function displayItems(){
    const itemsFromStorage = getItemsFromStorage();

    itemsFromStorage.forEach((item) => {
       addItemToDOM(item);
       checkUI();
    })
}


function createButton(classes){
    const button = document.createElement('button');
    button.className = classes;

    const icon = createIcon('fa-solid fa-xmark');
    button.appendChild(icon);
    return button;
}

function createIcon(classes){
    const icon = document.createElement('i');
    icon.className = classes;

    return icon;
}

function onClickItem(e){
    if(e.target.parentElement.classList.contains('remove-item')){
            removeItem(e.target.parentElement.parentElement);
    } else {
        setItemToEdit(e.target);
    }
}

function setItemToEdit(item){
    isEditMode = true;
    item.classList.add('edit-mode');
    formBtn.innerHTML = '<i class="fa-solid fa-pen"></i> Update Item';
    formBtn.style.backgroundColor = '#228B22'
    itemInput.value = item.textContent;
}

function removeItem(item){
    if(confirm('Are you sure?')){
        item.remove();

        removeItemsFromStorage(item.textContent);

        checkUI();
    }
}

function removeItemsFromStorage(item){
    let itemsFromStorage = getItemsFromStorage();

    itemsFromStorage = itemsFromStorage.filter((i) => i !== item);
    localStorage.setItem('items', JSON.stringify(itemsFromStorage));
}

function clearItems(){
    if(confirm('Are you sure?')){
        while(itemList.firstChild){
            itemList.removeChild(itemList.firstChild);
        }
    }
    localStorage.removeItem('items');
    checkUI();
}

function checkIfItemExists(item){
    const itemsFromStorage = getItemsFromStorage();
    return itemsFromStorage.includes(item);
}

function checkUI(){
    itemInput.value = '';

    const items = itemList.querySelectorAll('li');

    if(items.length === 0){
        clearBtn.style.display = 'none';
        itemFilter.style.display = 'none';
    } else{
        clearBtn.style.display = 'block';
        itemFilter.style.display = 'block';
    }

    formBtn.innerHTML = '<i class="fa-solid fa-pen"></i> Add Item';
    formBtn.style.backgroundColor = '#333';

    isEditMode = false;
}

function filterItems(e){
    const items = itemList.querySelectorAll('li');
    const text = e.target.value.toLowerCase();

    items.forEach((item) => {
        const itemName = item.firstChild.textContent.toLowerCase();
        if (itemName.indexOf(text) != -1){
            item.style.display = 'flex';
        } else {
            item.style.display = 'none';
        }
    })
}

function init(){
    itemForm.addEventListener('submit', onAddItemSubmit);
    itemList.addEventListener('click', onClickItem);
    clearBtn.addEventListener('click', clearItems);
    itemFilter.addEventListener('input', filterItems);

    document.addEventListener('DOMContentLoaded', displayItems);

    checkUI();
}

init();
