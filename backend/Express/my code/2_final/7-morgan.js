//morgan is a third-party middleware that logs HTTP requests and responses in a predefined format.
// is has different formats like 'dev', 'tiny', etc.

/*
  Why we use Morgan:
  - It automatically logs all incoming HTTP requests.
  - Helps us monitor traffic and debug issues easily.
  - Shows method, URL, status code, response time, and size.
  - Saves us from writing custom logging logic.
*/


const express = require('express')
const app = express()
const morgan = require('morgan') //third party middleware
const logger = require('../logger')
const authorize = require('../authorize')

//  req =>middleware => res  


// app.use(morgan('dev')) //
app.use(morgan('tiny'))  //will be used for all the routes


app.get('/',(req,res)=>{
    
    res.send('this is home')
}) 
app.get('/about',(req,res)=>{
    res.send('this is about')
})
app.get('/api/products',(req,res) =>{
    res.send('products')
})






app.listen(5000,()=>{
    console.log('server is listening on port 5000000.. ')
}) 