function printNumber(num, callback) {           //here callback will receive the function inside which 
                                                //we are calling the printNumber function again
  setTimeout(() => {
    console.log(num);
    callback();
  }, 2000);
}






// 😖 Callback Hell
printNumber(10, () => {
    console.log("First number printed");
  printNumber(20, () => {
    console.log("Second number printed");
    printNumber(30, () => {
        console.log("Third number printed");
      console.log("Done");
    });
  });
});
