//carry the properties of another class

class allperson{
    eat(){
        console.log(' can eat')
    }
    sleep() {
        console.log(' can sleep')
    }
}

class deadman{
    live(){
        console.log('not alive')
    }
}

class engineer extends allperson{     //here engineer is a child of allperson
    work(){
        console.log('can solve problem')
    }
}


const thanos = new deadman()
const afif = new engineer()         //afif is a object of engineer class

console.log(afif.eat)
console.log(afif.eat())   
console.log(thanos.eat)         //print undefined
console.log(thanos.eat())       // returns error


//after this super.js