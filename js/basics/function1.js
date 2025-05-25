const number = 5

//basic function
function addnumber(num1 = 1, num2 = 2){
    return num1 + num2;
}
console.log(addnumber(5,4)); //9
console.log(addnumber()); //3  by default value


//arrow function
    (num1 = 1, num2 = 2) => {           //this is an arrow function 
        return num1 + num2;
    }   

let addnumbers = (num1=1, num2=2) => {                //here addnumbers is a variable containing the function
    return num1 + num2; 
}
console.log(addnumbers(5,4)); //9
console.log(addnumbers()); //3  by default value
console.log(addnumbers(5)); //7  by default value of num2
console.log(addnumbers(5,4,3,2)); //9  by default value of num2
    addnumber = 10;                                      //we can treat addnumber as a variable



//arrow function with one line
const addnumberss = (num1=1, num2=2) => num1 + num2;    
console.log(addnumberss(5,4)); //9




//single peremeter

function isPositive(number) {
    return number >=0
}
//this is same as above function
const isPositive2 = number => number >=0  //arrow function in one line with one peremeter

console.log(isPositive(number))
console.log(isPositive2(number))



//no peremeter

function randomNumber(){
    return Math.random()
}

const randomNumber2 = () => Math.random()

console.log(randomNumber())
console.log(randomNumber2())


//annonymous function (no name)

//we will need html to check this
document.addEventListener('click', function(){
    console.log('you clicked')
})

document.addEventListener('click', () => console.log('you clicked'))