// Strings are immutable in JS — string methods return new strings.


const str='My name is afif';

console.log('length is = ' + str.length);
console.log(str.toUpperCase());                     //MY NAME IS AFIF
console.log(str.toLowerCase());                     //my name is afif
console.log(str.indexOf('name'));                   //3
console.log(str.lastIndexOf('a'));                 //11

console.log(str.substring(11,15 ));                 //afif
console.log(str[4]);                               //a

const str2= 'apple, mango, orange, grapes';         
console.log(str2.split(', '));                      //[ 'apple', 'mango', 'orange', 'grapes' ]    

const arr=str2.split(', ');
console.log("3rd fruit is "+ arr[2]);               //orange
console.log(arr)                                //[ 'apple', 'mango', 'orange', 'grapes' ]

//array
const balls = ['cricket', 'football', 'volleyball',true,10, ]
console.log(balls);
balls[5]= 'golf'
console.log(balls)  
balls.push('marbel')
console.log(balls)
balls.unshift('tennis')        //add at the beginning
console.log(balls)
balls.pop()
console.log(balls)              //remove last element

console.log(Array.isArray(balls)) //check if balls is an array          this print true

console.log('index of football is = ' + balls.indexOf('football'))

console.log('Displaying all balls by for loop:');
for(let ball of balls){
    console.log(ball)
}





const str3 = "   afif   hasan    ";
console.log(str3.trim()); //remove extra spaces
console.log(str3.trimStart()); //remove extra spaces from start
console.log(str3.trimEnd()); //remove extra spaces from end
console.log(str3.replace('afif', 'ahmed')); //replace afif with ahmed
console.log(str3.replaceAll('a', 'A')); //replace all a with A
console.log(str3.includes('afif')); //check if afif is in str2


const str4 = "Hello, World!";


// const str5 = str4 + str3 + " adding something new "; //Hello, World!   afif   hasan adding something new
const str5 = str4.concat(str3); //Hello, World!   afif   hasan

console.log(str5.slice(0, 5)); //Hello
console.log(str5.slice(17));    //fif   hasan (from 17th index to end)
console.log(str5.slice(-5));   //hasan (last 5 characters)


let str6 = "afif hasan";    //const str6 = "afif hasan"; //this will not work as const can not be changed
str6[1] = 'b'; //this will not change the character 
console.log(str6); //afif hasan
str6.replace('f', 'b'); //this will not change the character
console.log(str6); //afif hasan
str6 = str6.replace('f', 'b'); //this will change the character
console.log(str6); //abif hasan