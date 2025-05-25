//READ THIS FIRST FROM THIS FOLDER



//A method in an object is just a function inside an object. Let's take an example of a person object.
let person = {
  name: 'John',
  age: 25,
  greet: function() {       //this is a method
    console.log('Hello!');  
  }
};

person.greet(); // Hello!

//shorter way to write method
let person2 = {
  name: 'John',
  age: 25,
  greet() {                 //this is a method , this is same as greet: function() { console.log('Hello!'); }
    console.log('Hello!');  
  }
};

person2.greet(); // Hello!

//this keyword
//The this keyword refers to the object that the method belongs to. we need this because we can't access the object's properties directly from the method.
//For example, in the greet method, we can't access the name property directly. We have to use this.name to access the name property.
let person3 = {
  name: 'John',
  age: 25,
  greet() {
    console.log('Hello ' + this.name); //this refers to the object person3
  }
};
person3.greet(); // Hello John



//after this prototype.js