function hello(){
    console.log("hi helloo")
}

setTimeout(hello, 3000) //this will call the function after 3 seconds

setTimeout(function(){
    console.log("hi helloo")
}
, 3000) //this will call the function after 3 seconds