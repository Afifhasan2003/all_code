const express = require('express')
const app = express()
const logger = require('../logger')
const authorize = require('../authorize')
//  req =>middleware => res

//1. use vs route
//2. options - our own(so far, did this)/ express(will do now) /third party (morgan)

app.use(express.static('./public'))  //static is express's build in middleware




app.get('/',(req,res)=>{
    
    res.send('this is home')
})

//app.use('/api',logger)  //all the link with api will have logger

app.get('/about',(req,res)=>{
    res.send('this is about')
})

app.get('/api/products',(req,res) =>{
    res.send('products')
})

//app.get('/api/items',[authorize,logger],(req,res)=>{   if not declared app.use 
app.get('/api/items',(req,res)=>{
    console.log(req.user )
    res.send('this is items')
})






app.listen(5000,()=>{
    console.log('server is listening on port 5000000.. ')
})