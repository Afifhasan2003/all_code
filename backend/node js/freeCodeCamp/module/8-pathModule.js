const path = require('path')


console.log(path.sep)

const filePath = path.join('/contest','subfolder','test.txt')
console.log(filePath)

const base = path.basename(filePath)
console.log(base)       //test.txt

const absolute = path.resolve(__dirname,'content','subfolder','test.txt')
console.log(absolute)

