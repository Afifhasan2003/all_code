//modules - encapsulated coe (only share minimum)
//// CommonJS, every file is a module (by default)


const names = require('./3-moduleFrom'); // import the module
const sayHi = require('./4-moduleFunc'); // import the function

// console.log(names)  //name is object with john and peter


// sayHi('susan'); 
// sayHi(names.john); 

// const data = require('./5-alternative'); 
// console.log(data) 

require('./6-module4');     //directly runs 