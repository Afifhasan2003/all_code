const str='My name is afif';

console.log('length is = ' + str.length);
console.log(str.toUpperCase());
console.log(str.substring(11,15 ));
console.log(str[4]);

const str2= 'apple, mango, orange, grapes';
console.log(str2.split(', '));

const arr=str2.split(', ');
console.log("3rd fruit is "+ arr[2]);
console.log(arr)

//array
const balls = ['cricket', 'football', 'volleyball',true,10, ]
console.log(balls);
balls[5]= 'golf'
console.log(balls)
balls.push('marbel')
console.log(balls)
balls.unshift('tennis')
console.log(balls)
balls.pop()
console.log(balls)

console.log(Array.isArray(balls)) //dcheck if balls is an array

console.log('index of football is = ' + balls.indexOf('football'))

console.log('Displaying all balls by for loop:');
for(let ball of balls){
    console.log(ball)
}