const name='john';
const age=25;
const cg=4.5;
const smart=true;
const x=null;
const y=undefined;
let z;

console.log(typeof name);
console.log(typeof smart);

//concatenation
console.log('my name is ' + name + ' and I am ' + age);

//Template string
console.log(`My name is ${name} and I am ${age}`);

//OR 
const what= `My name is ${name} and I am ${age}`;
console.log(what);

console.log("name length is " + name.length);