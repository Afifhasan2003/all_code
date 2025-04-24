//constructor function
function Person(firstName, lastName, dob) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
    /* this.getBirthYear = function() {
        return this.dob.getFullYear();
    } */
    /*  this.getFullName = function() {
        return `${this.firstName} ${this.lastName}`;
    }   */
 }

                        //Prototype methods
    Person.prototype.getBirthYear = function() {  
        return this.dob.getFullYear();
    }
     
    Person.prototype.getFullName = function() {
        return `${this.firstName} ${this.lastName}`;
    }
    //now they wont appear in the object but in the prototype
    //but they can be accessed by the object


// Instantiate object




//OR WE CAN USE Classes

 /*
   class Person {
    constructor(firstName, lastName, dob) {
        this.firstName = firstName;
        this.lastName = lastName;   
        this.dob = new Date(dob);
    }
    getBirthYear() {
        return this.dob.getFullYear();
    }
    getFullName() {
        return `${this.firstName} ${this.lastName}`;
    }
} 
    
*/
//they are the same thing but prettier






const person1 = new Person('John', 'Doe', '4-3-1980');
const person2 = new Person('Steve', 'Smith', '3-4-1990');

console.log(person1);
console.log(person2);
console.log(person1.dob);
console.log(person2.dob);   
console.log(person2.dob.getFullYear()); //1990
console.log(person1.getBirthYear()); //1980 
console.log(person1.getFullName()); //John Doe