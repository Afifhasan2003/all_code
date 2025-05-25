// Example of a Promise in JavaScript

// Create a new Promise
const myPromise = new Promise((resolve, reject) => {
    let success = true; // Change this to false to test rejection

    if (success) {
        resolve("The operation was successful!(abc marked)");       //abc marked written to understand that i wrote error
    } else {
        reject("The operation failed(abc marked).");
    }
});
//print myPromise  in the bowser to feel the promise



// Using the Promise

myPromise.then(() => {
    console.log("Successss:" );
})
myPromise.catch(() => {
    console.log("Errorrrr:");
})






myPromise
    .then((message) => {
        console.log("Successss:", message);
    })
    .catch((err) => {
        console.error("Errorrrr:", err);
    })
    .finally(() => {
        console.log("Promise has been settled.");
    });