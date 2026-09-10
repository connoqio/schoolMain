const arr = [1, 2, 3, 4, 5]

arr.reverse(); // this is what makes tha array print backwards
arr.push(0); // this pushes 0 to the end of the array
arr.unshift(6); // this pushes 6 to the start of the array
console.log(arr);

const arr1 = [1, 2, 3, 4, 5, 6]
const arr2 = [6, 7, 8, 9, 10, 11]
const arr3 = [...arr1, ...arr2]

arr3.splice(6, 1);
console.log(arr3);