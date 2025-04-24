// Example of a Promise in JavaScript

// Create a new Promise
const myPromise = new Promise((resolve, reject) => {
    let success = false; // Change this to false to test rejection

    if (success) {
        resolve("The operation was successful!");
    } else {
        reject("The operation failed.");
    }
});

// Using the Promise
myPromise
    .then((message) => {
        console.log("Success:", message);
    })
    .catch((error) => {
        console.error("Error:", error);
    })
    .finally(() => {
        console.log("Promise has been settled.");
    });