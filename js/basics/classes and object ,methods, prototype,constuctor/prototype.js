const employee = {
  name: 'John',
  calcTax() {
    console.log('tax is 10%')
  } 
}

const newEmployee = {
    name: 'Steve',

}
// console.log(employee);
// console.log(newEmployee);
newEmployee.__proto__ = employee;
console.log(newEmployee.calcTax());     //even though calcTax is not defined in newEmployee, it is inherited from employee object
                                        //along with some other proterties in the prototype chain
                                        //for example lenght property of string object is inherited from string.prototype object




//after this classe1.js                                      