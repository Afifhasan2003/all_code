class superHero{
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
console.log(typeof superHero)         //function
const spiderman = new superHero ()    

console.log(typeof spiderman)         //object

console.log(spiderman.save())
spiderman.setPower("very strong")
console.log("spiderman is " + spiderman.power)      //spiderman is very strong

const superman = new superHero()
superman.setPower("weak")
console.log("superman is "+superman.power)

//if we check the prototype of any object we will see there is already a constructor created by default
//AFTER THIS constructor.js
