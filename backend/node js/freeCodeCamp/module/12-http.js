const http = require('http');

const server = http.createServer((req,res)=>{
// console.log(req)    //prints after getting responce(like refresh the browser)

if(req.url === '/'){
    res.end('welcome to out home page')
}
else if (req.url === '/about'){
    res.end('here is out short history')
}
else if(req.url === '/try'){
    res.end(`
            <h1 style="color: #333; text-align: center;">Welcome Sir</h1>

<div style="background-color: white; padding: 15px; border-radius: 10px; box-shadow: 0 0 10px rgba(0,0,0,0.1); max-width: 600px; margin: 20px auto;">
    <p style="color: #555; line-height: 1.6;">This page uses inline CSS. Good for small tweaks, but not ideal for large projects.</p>
</div>

<div style="background-color: #e0ffe0; padding: 15px; border-radius: 10px; box-shadow: 0 0 5px rgba(0,0,0,0.1); max-width: 600px; margin: 20px auto;">
    <p style="color: #2a2; font-weight: bold;">Green box with bold text. Perfect for notices or success messages.</p>
</div>

<div style="background-color: #ffe0e0; padding: 15px; border-radius: 10px; box-shadow: 0 0 5px rgba(0,0,0,0.1); max-width: 600px; margin: 20px auto;">
    <p style="color: #a22; font-style: italic;">Red box with italic text. Useful for warnings or errors.</p>
</div>

<div style="background-color: #e0e0ff; padding: 15px; border-radius: 10px; box-shadow: 0 0 5px rgba(0,0,0,0.1); max-width: 600px; margin: 20px auto;">
    <p style="color: #224; text-decoration: underline;">Blue box with underlined text. Good for info or links.</p>
</div>


         `)
}
else {res.end(`
    <h1>Ooops!! </h1>
    <p> we can't seem to find the page you are looking for </p>
    <a href="/">Back home </a>
    `)}

})

server.listen(5000,()=>{//opens at http://localhost:5000/
    console.log('listening on server 5000')
}) 