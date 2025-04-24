//WHILE CONSTRUCTOR INSIDE A CHILD CLASS

class person{
    constructor(){
        console.log("I am the bosss")
    }

    randomfunctions(){
        console.log('something random')
    }
}


class engineer extends person {

    constructor(type){
        console.log("this is child constructor starting")
        super()         // Must call super constructor in child class before accessing 'this' or returning from derived constructor at new engineer
        
        this.type=type
        
        console.log("this is child constructor ending")
    }
}

const afif = new engineer("good")


// console.log(afif)