var http = require('http');
var fs = require('fs');

http
    .createServer(function(req,res){

        //here we are reading the whole file at once and sending it to the client
        //this is not efficient for large files as it will block the event loop

        // const text = fs.readFileSync('./content/big.txt' , 'utf8')
        // res.end(text)



        //OR 
        //here the difference is that we are not reading the whole file at once
        //we are reading it in chunks and sending it to the client
        //this is more efficient for large files
        
        const fileStream = fs.createReadStream('./content/big.txt','utf8');
        fileStream.on('open',()=>{
            fileStream.pipe(res)
        })
        fileStream.on('error',(err)=>{
            res.end(err)
        })


    })

    .listen(5000)