const http = require('http');

const server = http.createServer((req,res)=>{
// console.log(req)    //prints after getting responce(like refresh the browser)

if(req.url === '/'){
    res.end('welcome to out home page')
}
else if (req.url === '/about'){
    res.end('here is out short history')
}
else {res.end(`
    <h1>Ooops!! </h1>
    <p> we can't seem to find the page you are looking for </p>
    <a href="/">Back home </a>
    `)}

})

server.listen(5000) //opens at http://localhost:5000/