let a=5 ,b=10
console.log('a = ',a)
console.log('b = ',b)
console.log('a+b = ',a+b)
// console.log('a+c = ',a+c)  this will give error and stop the program here

try{
    console.log('a+c = ',a+c)
}catch(err){
    // console.log(err)            //now the program wont stop
}
console.log('a-b = ',a-b)
console.log('a*b = ',a*b)
