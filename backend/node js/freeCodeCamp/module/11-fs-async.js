//here we will use async await



// const { readFile, writeFile } = require('fs')
// // Using promisify to convert callback-based functions to promise-based
// const util = require('util')
// const readFilePromise = util.promisify(readFile)        
// const writeFilePromise = util.promisify(writeFile)

// const start1 = async () => {
//     try {
//         const first = await readFilePromise('./content/first.txt', 'utf8')
//         const second = await readFilePromise('./content/second.txt', 'utf8')
//         await writeFilePromise(
//         './content/result-async.txt',
//         `Here is the result: ${first}, ${second}`,
//         { flag: 'a' }
//         )
//         console.log(first, second)
//     } catch (error) {
//         console.log(error)
//     }
//     }

// start1()





//this is same as above but using fs.promises 

const { readFile, writeFile } = require('fs').promises

const start = async () => {
  try {
    const first = await readFile('./content/first.txt', 'utf8')
    const second = await readFile('./content/second.txt', 'utf8')
    await writeFile(
      './content/result-mind-grenade.txt',
      `THIS IS AWESOME : ${first} ${second}`,
      { flag: 'a' }
    )
    console.log(first, second)
  } catch (error) {
    console.log(error)
  }
}

start()