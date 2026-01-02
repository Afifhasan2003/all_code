//call back is a function that is passed as an argument to another function



function sum(a,b){
    console.log(a+b);
}
function calc(a,b,callback){            //callback will receive the function sum
    callback(a,b);            
}
calc(2,3,sum);          //5


calc(2,3,(a,b) => {            //here we are passing the entire function as a callback 
    console.log(a+b);
})          //5
 



let arr = [1,2,3];

arr.forEach(function printvalue(val){               //val is the value of each element in the array send by forEach
    console.log(val);
})

arr.forEach((val) => {                              //same but without function name
    console.log(val);
})

arr.forEach(val => console.log(val));              //same but in one line

let funcVar = (val) => {                              
    console.log(val);
    }

arr.forEach(funcVar)            //we can do this too


arr.forEach(function printvalue(val, indx){               //val is the value of each element in the array send by forEach
    console.log("Value:", val, "Index:", indx);
})

arr.forEach((val, indx) => {                              //same but without function name
    console.log("Value:", val, "Index:", indx);
})




arr.forEach((val,indx,arr) => {                              //(variable, index, array) => {
    console.log("Value:", val, "Index:", indx, "Array:", arr);
})