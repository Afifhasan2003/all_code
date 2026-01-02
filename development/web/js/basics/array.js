const items = ["pen", "book", "pencil", "bottle", "food"];

// ✅ Add/Remove
items.push("mouse");          // Add to end
items.unshift("notebook");    // Add to start
items.pop();                  // Remove from end
items.shift();                // Remove from start

// ✅ Check & Find
console.log(items.includes("pen"));       // true
console.log(items.indexOf("book"));       // 1
console.log(items.find(item => item === "pencil")); // "pencil"

// ✅ Looping
items.forEach(item => console.log("Item:", item));

//original array is ["pen", "book", "pencil", "bottle", "food"]

// ✅ Slice (non-destructive meaning it does not change the original array)
const someItems = items.slice(1, 3); // from index 1 to 2
console.log("sliced from 1 to 3",someItems);

// ✅ Splice (destructive meaning it changes the original array)  
//used to add or remove items
items.splice(1, 2); // remove 2 items from index 1
items.splice(1, 0, "book"); // remove 0 items at index 1, insert "book"
items.splice(1,0,"pencil","bottle","food"); // remove 0 items at index 1, insert "pencil", "bottle", "food"
items.splice(2, 1, "marker"); // remove 1 item at index 2, insert "marker"

console.log("after spliceee: ",items); // ["pen" , "pencil", "marker", "food","book", "bottle, "food"]

const itemsCopy = items.slice(); // copy of the array
const itemsAfter2 = items.slice(2); // copy of the array from index 2  ["marker", "food","book", "bottle, "food"]

const itemsCopy3 = items.concat(); // copy of the array







// ✅ Transform
const upperItems = items.map(item => item.toUpperCase());  // newarr = arr.map(variable => function) 
console.log("upperItems",upperItems);  // ["PEN", "BOOK", "PENCIL", "BOTTLE", "FOOD"] upperItems is a new array
                                    

// ✅ Filter
const filtered = items.filter(item => item.length > 4);  //newarr = arr.filter( variable => condition )
console.log("filtered by length>4: ",filtered);  // Items with name length > 4

// ✅ Reduce(this )
const totalLength = items.reduce((sum, item) => sum + item.length, 0); // newarr = arr.reduce( (accumulator, variable) => function, initialValue )
console.log("Total characters:", totalLength);       //its like sum = sum + item.length in loop

// ✅ Sort (alphabetical)
const sorted = [...items].sort(); //
console.log("Sorted:", sorted);  // ["book", "bottle", "food", "pen", "pencil"]


// ✅ Reverse
const reversed = [...items].reverse();   // not reverse sorted 
console.log("reversed: ",reversed);     // ["food", "bottle", "pencil", "book", "pen"]





// ✅ Flatten nested array
const nested = [1, [2, [3, [4]]]];
console.log(nested.flat(2));  // [1, 2, 3, [4]]

// ✅ Merge arrays
const a = [1, 2], b = [3, 4];
const merged = a.concat(b);  // [1, 2, 3, 4]
const mergedAB = [...a, ...b]; //this is the same as above but better
console.log("merged :  ",merged);  // [1, 2, 3, 4]
console.log("merged :  ",mergedAB);  // [1, 2, 3, 4]

// ✅ Remove duplicates
const nums = [1, 2, 2, 3, 1];
const unique = [...new Set(nums)];
console.log(unique);  // [1, 2, 3]

// ✅ Destructuring
const [first, second, ...rest] = items;
console.log(first,second);  // "pen" "book"
console.log(first, second, rest);   // "pen" "book" ["pencil", "bottle", "food"]

// ✅ Fill
const filled = new Array(5).fill("empty");
console.log(filled);  // ["empty", "empty", "empty", "empty", "empty"]

// ✅ Convert string to array
const str = "Afif";
console.log(str.split(""));  // ["A", "f", "i", "f"]

// ✅ Join array to string
console.log(items.join(", "));  // "pen, book, pencil..."


//toString
const strArray = items.toString();
console.log(strArray);  // "pen,book,pencil,bottle,food" it is a string






const arr1 = [1,2,3,4,5,6,7]

// const sqrOfArr1 = arr1.map( val =>val*val)
const sqrOfArr1 = arr1.map((val)=> {return val*val})   //both same ,have to say return inside bracket
console.log(sqrOfArr1)


const getEvenNumber = arr1.filter(val =>{
    return val%2 ===0;      //if true then return val to the array
})
console.log("even numbers are: ",getEvenNumber)


const sumOfNum = arr1.reduce((result ,val)=>{               //reduce always returns a single value 
    return result +val                                      
}) 
console.log("result is ",sumOfNum)
const maxNum = arr1.reduce((result,val)=>{
    return result<val ? val:result;                         //returning bigger number inside result
})
console.log("max number is : ",maxNum)