
interface Animal{
    int eyes=2;
    void walks();
    // void eats(){};  //interface can not have block inside method
    // Animal(){};  //interface can not have constractiona
}

interface Herbivore{
    default void eats(){
        System.out.println("only eat plants");
    }
}

class Horse implements Animal,Herbivore{
    public void walks(){
        System.out.println("walks in 4 legs");
    }
}










public class Abstraction2 {
    public static void main(String[] args){
        Horse horse = new Horse();
        horse.walks();
        horse.eats();
        // horse.eyes = 3;       can not change it 
        System.out.println("eye number "+ horse.eyes);

    }
}
