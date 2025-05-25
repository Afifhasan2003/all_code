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


    //console.log(person1.getBirthYear()); //1980




//OR WE CAN USE Classes

//ES6 Class syntax
   class Student {
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

const student1 = new Student('afif', 'hasan', '07-31-2003');
const student2 = new Student('sami', 'rahman', '07-31-2005');
console.log(student1);
console.log(student2);
console.log(student1.dob);
console.log(student2.dob);
console.log(student2.dob.getFullYear()); //2005         fgetullYear() is a method of Date object in JS
console.log(student1.getBirthYear()); //2003            getBirthYear() is a method of Person object defined by us
console.log(student1.getFullName()); //afif hasan
console.log(student2.getFullName()); //sami rahman
console.log(student2.getBirthYear()); //2005

