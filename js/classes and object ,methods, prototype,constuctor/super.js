//WHILE CONSTRUCTOR INSIDE A CHILD CLASS

class person{
    constructor(age){
        console.log("I am the bosss")
        this.age = age;
        console.log("age in parent: " + age)
    }

    randomfunctions(){
        console.log('something random')
    }
}


class engineer extends person {

    constructor(age){
        console.log("this is child constructor starting")

        // super(age);      //this was sending age to parent

        super()         // Must call super constructor in child class before accessing 'this' or 
                        // returning from derived constructor at new engineer
        


        this.age=age
        
        console.log("this is child constructor ending")
        console.log("age is: " +this.age)

        super.randomfunctions() //calling function from parent
      
    }
}

const afif = new engineer(22)

