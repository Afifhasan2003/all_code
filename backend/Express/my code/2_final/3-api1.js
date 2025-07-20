const express = require('express');
const app = express()

const {products} = require('../data')
app.get('/',(req,res) =>{
    // res.json([{name:'john'},{name:'afif'}])
    // res.json(products)
    res.send('<h1> Home page</h1> <a href="/api/products">products')

})
app.get('/api/products',(req,res)=>{
    // res.json(products)
    const newProducts = products.map((product)=>{
        const{id,name,image} = product;
        return {id,name,image}
    })
    res.json(newProducts)

})
app.get('/api/products/:productID',(req,res)=>{
    // console.log(req)
    // console.log(req.params)
    const {productID} = req.params;
    const singleProduct = products.find(
        (product)=> product.id ===Number(productID))    //productID was string

    if(!singleProduct){
        return res.status(404).send('product doesnt exist')
    }

    console.log(singleProduct.id)
    return res.json(singleProduct)
 
})

app.get('/api/products/:productID/reviews/:reviewID',(req,res)=>{
    console.log(req.params)
    res.send('this is hello')
})
app.get('/api/v1/query',(req,res) =>{
    console.log(req.query)
    const {search,limit} = req.query 
    let sortedProducts = [...products];

    if(search){
        sortedProducts = sortedProducts.filter((product)=>{
            return product.name.startsWith(search)
        })
    }
    if(limit){
        sortedProducts= sortedProducts.slice(0,Number(limit))
    }
    if(sortedProducts.length<1){
        res.status(200).send('no product to show')
        // return res.status(200).json({success: true,data:[]})
    }
    else
        res.status(200).json(sortedProducts)
        

    // res.send("this is query")
    // res.send(req.query)
})


app.listen(5000,()=>{
    console.log('server is listening to post 500000... ')
})