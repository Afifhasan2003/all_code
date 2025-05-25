//this example is not pure abstraction

abstract class Animal {
    abstract void walk();       //abstract method does not have body

    public void eat(){
        System.out.println("yes he eats");
    }

    Animal(){
        System.out.println("You are creating new Animal");
    }

}

class Horse extends Animal{
    public void walk(){
        System.out.println("walks on 4 leg");
    }
    Horse(){
        System.out.println("created a horse");
    }
}

class Chicken extends Animal{
    public void walk(){
        System.out.println("walks on 2legs");
    }
    Chicken(){
        System.out.println("created a chicken");
    }
}

public class Abstraction1 {

    public static void main(String[] args){
        
        // Animal a1= new Animal() ;       //this is wrong, coz animal is abstract

        Horse h1= new Horse(); //This prints two line -> You are creating new Animal ,created a horse, yes he eats

        h1.eat();       // yes he eats
        h1.walk();      //walks on 4 leg


    }
    
}