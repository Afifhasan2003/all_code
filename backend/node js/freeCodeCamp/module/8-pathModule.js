const path = require('path') 


console.log(path.sep)       // prints the platform-specific path segment separator (e.g., '/' on Unix, '\' on Windows)

const filePath = path.join('/content','subfolder','test.txt')   
console.log(filePath)   // /content/subfolder/test.txt

const base = path.basename(filePath)
console.log(base)       //test.txt

const absolute = path.resolve(__dirname,'content','subfolder','test.txt')
console.log(absolute)       // /home/afif/Downloads/Work/All file/code/backend/node js/freeCodeCamp/module/content/subfolder/test.txt

