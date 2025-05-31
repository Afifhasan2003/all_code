//syncronus 
// const {readFileSync} = require('fs')

// const fs = requite('fs')
// fs.read                        //this would be same

const {readFileSync, writeFileSync} = require('fs')  // readFileSync is a method of fs module 

const first = readFileSync('./content/first.txt','utf8')        // terminal have to opened inside module folder
const second = readFileSync('./content/second.txt','utf8')
console.log(first,second)   

// writeFileSync('./content/result-sync.txt',`here is the result: ${first},${second}`) //if file does not exist, it will create a new file , else it will overwrite the existing file
writeFileSync('./content/result-sync.txt',`here is the result: ${first},${second}`,{flag: 'a'})  // flag: 'a' is used to append the content to the file if it already exists
