
//DIRECT WAY TO CREATE AN OBJECT 
const person ={
    firstname: 'afif',
    lastname: 'hasan',
    age: 25,
    hobbies: ['music', 'movies', 'sports'],
    address: {
        city: 'mymensingh',
        town: 'gafargaon',
        street: 96
    }

 }
 console.log(person.firstname)          //afif
 console.log(person.address.town)       //gafargaon
 console.log(person.hobbies[2])       //sports

//  console.log(person.address)
//  console.log(person)
person.email='afif@gmail'
console.log(person)                     //this print the whole object