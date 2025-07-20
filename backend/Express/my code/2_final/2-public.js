const express = require('express')
const path = require('path')

const app = express()

//setup static and middleware 
app.use(express.static('../public'))


app.get('/',(req,res)=>{
    console.log('user hit the resource')
    res.sendFile(path.resolve(__dirname,'../navbar-app/index.html'))
})


app.get('/about',(req,res)=>{
    res.status(200).send('about page')
})
app.all('/*splat',(req,res)=>{          //splat is for express version 5
    res.status(404).send('<h1> Resource not found </h1>')

}) 


app.listen(5000,()=>{
    console.log('server is listneing on port 5000...')
})
