//asyncronus function to read a file
//this is callback hell 
const {readFile, writeFile} = require('fs')

console.log('start')

readFile('./content/first.txt','utf8',(err,result)=>{

    if(err){
        console.log(err)
        return;
    }
    // console.log(result)
    const first = result;
    readFile('./content/second.txt','utf8',(err,result)=>{
            if(err){
        console.log(err)
        return;
    }
    // console.log(result)
    const second = result;
        writeFile('./content/result-async.txt',`here is the result: ${first},${second}`,(err,result)=>{
            if(err){
                console.log(err)
                return;
            }
            console.log(result)     //undefined because writeFile does not return anything
            console.log('done with this task')  //this will be printed after the writeFile is done 
        })
    })
}) 
console.log('starting next task')  