const http = require('http')    
const {readFileSync} = require('fs') // to read files synchronously

const homePage = readFileSync('./navbar-app/index.html')
const homeStyle = readFileSync('./navbar-app/styles.css')
const homeImage = readFileSync('./navbar-app/logo.svg')
const homeLogic = readFileSync('./navbar-app/browser-app.js')



const server = http.createServer((req,res)=>{
    // console.log('user hit the server')

    //console.log(req)       // req is an object that contains information about the request
    // console.log(req.method) // shows what the user is trying to do
    console.log(req.url)   // shows the url the user is trying to access

    const url = req.url;

    if(url === '/'){
        res.writeHead(200,{'content-type':'text/html'})
        res.write(homePage)
        res.end()
    }

    else if(url === '/styles.css'){
        res.writeHead(200,{'content-type':'text/css'})
        res.write(homeStyle)
        res.end()
    }
    else if(url ==='/logo.svg'){
        res.writeHead(200,{'content-type':'image/svg+xml'})
        res.write(homeImage)
        res.end()
    }
    else if(url === '/browser-app.js'){
        res.writeHead(200,{'content-type':'text/javascript'})
        res.write(homeLogic)
        res.end()
    }








    // res.end()  //res.end() is a must to finish the response
   else  res.end('<h1>Page not found</h1>')

})
 
server.listen(5000)