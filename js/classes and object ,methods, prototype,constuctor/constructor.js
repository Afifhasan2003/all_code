//constructor is a special type of method (function)
//it does not even need a name 

class superHero{

    constructor(hisName,age){
        console.log("everyone is good")
        this.hisName=hisName   //not necessarily both has to be same. could be be this.herName=hisName. just grabing the argument in a new variable
        this.age=age
    }

    save() {
        console.log('world is saved')
    }

    stop(){
        console.log('Stopped bad guy')
    }
    setPower(strength){
        this.power = strength
    }
}


    const spiderman = new superHero()  //this already shows the line in console 
    console.log('real name of spiderman is '+ spiderman.hisName) //real name of spiderman is undefined
    


    const superman = new superHero("clark",35)     //need constructor to pass argument at the time of itialization
    console.log('real name of superman is '+ superman.hisName)
    console.log('age of superman is '+ superman.age)  //age of superman is 35


    console.log(spiderman)      
    console.log(superman)       //now we can see how they are object


    //afte this inheritance.js 