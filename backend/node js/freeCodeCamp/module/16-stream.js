const  {createReadStream} = require('fs')

const stream = createReadStream('./content/big.txt',{
    highWaterMark:90000,
    encoding: 'utf8'
})  //stream is a variable here 


//default 64kb
//last buffer - remainder
//highwatermark - control size
//encoding - controls the output






stream.on('data',(result)=>{
    console.log(result)
})


stream.on('error',(err)=>{   //if there is an error, this will be executed
    console.log(err)
})