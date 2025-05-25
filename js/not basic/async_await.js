
function printData(num){
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log("Data printed", num);
            resolve();
        }, 2000);
    });
}



// async function printNumbers() {     //await can only be used inside async function
//     await printData(10);        
//     await printData(20);
//     await printData(30);
// }

// printNumbers();

(async function printNumbers() {     //IIFE ,here dont have to call the function
    await printData(10);                //automatically called
    await printData(20);
    await printData(30);
})();