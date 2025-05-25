console.log(window); // this includes all the properties and methods of the window object in the browser console


console.log('hello')
window.console.log('hello'); // this is same as console.log('hello') 

//means methods like console.log ,alert etc. are all properties of the window object. 
//but we dont have to include manually


console.log(window.document); // this will give the entire html document 
console.dir(window.document); // this will give the entire html document in a tree structure

//this is document in document object model (DOM) we talk about 


console.log(window.document.body); // this will give the body of the html document
console.dir(window.document.body); // this will give the body of the html document in a tree structure