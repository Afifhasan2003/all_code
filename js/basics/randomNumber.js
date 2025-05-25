//THIS CODE IS DIRECTLY COPIED FROM GPT

//The names are given by me to understand the functions better

// 1. Generate a random decimal between 0 and 1
const getRandomDecimal = () => Math.random();
console.log("Random Decimal (0 to 1):", getRandomDecimal());

// 2. Generate a random integer (0 to a large number)
const getRandomInt = () => Math.floor(Math.random() * Number.MAX_SAFE_INTEGER);
console.log("Random Large Integer:", getRandomInt());

// 3. Generate a random integer in a given range (min to max)
const getRandomInRange = (min, max) => Math.floor(Math.random() * (max - min + 1)) + min;
console.log("Random Integer (10 to 100):", getRandomInRange(10, 100));

// 4. Generate a random negative or positive integer
const getRandomNegativeOrPositive = () => (Math.random() < 0.5 ? -1 : 1) * getRandomInt();
console.log("Random Positive or Negative Integer:", getRandomNegativeOrPositive());

// 5. Generate a random floating-point number in a range
const getRandomFloatInRange = (min, max) => Math.random() * (max - min) + min;
console.log("Random Float (1.5 to 5.5):", getRandomFloatInRange(1.5, 5.5));

// 6. Generate a random binary number (0 or 1)
const getRandomBinary = () => Math.random() < 0.5 ? 0 : 1;
console.log("Random Binary (0 or 1):", getRandomBinary());

// 7. Generate a random boolean (true or false)
const getRandomBoolean = () => Math.random() < 0.5;
console.log("Random Boolean (true or false):", getRandomBoolean());

// 8. Generate a random hexadecimal color code
const getRandomHexColor = () => '#' + Math.floor(Math.random() * 16777215).toString(16);
console.log("Random Hex Color:", getRandomHexColor());
