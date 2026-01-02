let name = "Afif";
let age = 21;
let hobby = "coding";
let today = new Date().toLocaleDateString();

//  Interpolation + Expression 
console.log(`Hey ${name}, next year you'll be ${age + 1}.`);

//  Multiline String
const bio = `
Name    : ${name}
Age     : ${age}
Hobby   : ${hobby}
Date    : ${today}
`;
console.log(bio);       //everything in bio will be printed in the same format


// Function inside Template
function greet() {
    return "Welcome back";
}
console.log(`${greet()}, ${name}!`);


//  Tagged Template
function bold(strings, ...values) {
    return strings.reduce((str, part, i) => str + part + (values[i] ? `[${values[i]}]` : ""), "");
}
console.log(bold`Sir ${name}, your hobby is ${hobby}.`);
