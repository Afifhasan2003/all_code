const express = require('express')
const app = express()


//  req =>middleware => res
const logger = (req,res,next) =>{
    const method = req.method;
    const url = req.url;
    const time = new Date().getFullYear()
    console.log(method,url,time) 
    // res.send('testing')
    next()  //passed on the next middleware (Must)
}

app.get('/',logger,(req,res)=>{
    
    res.send('this is home')
})

//app.use('/api',logger)  //all the link with api will have logger
app.use(logger)     //if use this, wont need to write logger in each app.get, automatically sobar sateh set hoye jabe
                    //order matters

app.get('/about',(req,res)=>{
    res.send('this is about')
})

app.get('/api/products',(req,res) =>{
    res.send('products')
})






app.listen(5000,()=>{
    console.log('server is listening on port 5000000.. ')
})