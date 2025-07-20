const os = require('os');       //could say const abc = require('os'); to rename

//info about current user
const user = os.userInfo()
console.log(user)




console.log(`the system uptime is ${os.uptime()} seconds `)


const currentOs ={
    name: os.type(),
    release:os.release(), 
    totalMem: os.totalmem(),
    freeMem: os.freemem(),
}
console.log(currentOs)


