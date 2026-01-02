function func1(){
    return new Promise((resolve,reject) =>{
        setTimeout(() => {
            console.log("this is data 1")
            resolve("success1")
        }, 4000);
    })
}

function func2(){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log("this is data 2")
            resolve("success2")
        }, 4000);
    })
}



// console.log("fetching data1 ...")
// let p1 = func1()
// p1.then((res)=>{
//     console.log("result of func1: " ,res)
//     let p2 = func2()
//     console.log("fetching data2")
//     p2.then((res)=>{
//         console.log("result of func2: ",res)
//     })
// })

//OR doing the same thing

// console.log("fetching data1 ...")
// func1().then((res)=>{
//     console.log("result of func1:" , res)

//     console.log("fetching data2")
//     func2().then((res)=>{
//         console.log("result of func2: ",res)
//     })
// })


//OR doing the same thing

//promise chaining

console.log("fetching data1 ...")
func1().then((res) => {
        
        console.log("fetching data2");
        return func2(); // Return the second promise
    }).then((res) => {
        console.log("result of func2:", res);
    })
    