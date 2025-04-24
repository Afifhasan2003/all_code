const number = 5
function addnumber(num1 = 1, num2 = 2){
    return num1 + num2;
}

console.log(addnumber(5,4)); //9
console.log(addnumber()); //3  by default value


const addnumbers = (num1=1, num2=2) => {//arrow function
    return num1 + num2;
}


console.log(addnumbers(5,4)); //9


const addnumberss = (num1=1, num2=2) => num1 + num2;    //arrow function with one line
console.log(addnumberss(5,4)); //9


//single peremeter

function isPositive(number) {
    return number >=0
}
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