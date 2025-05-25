
 class Dog {
    String name; 
    int age;    


    // 1. Default No-Args Constructor (Added Explicitly)
    public Dog() {
        System.out.println("-> Dog() No-Args Constructor Called! (Explicit)");
        
    }

    // 2. Parameterized Constructor (String name)
    public Dog(String name) {
        System.out.println("-> Dog(String name) Constructor Called!");
        this.name = name; 
    }

    // 3. Parameterized Constructor (int age) 
    public Dog(int age) {
        System.out.println("-> Dog(int age) Constructor Called!");
        this.age = age;
       
    }

    // 4. Parameterized Constructor (String name, int age)
    
    public Dog(String name, int age) {
        System.out.println("-> Dog(String name, int age) Constructor Called!");
        this.name = name;
        this.age = age;
    }

    // Helper method to display dog's info
    public void displayInfo() {
        System.out.println("Dog Info: Name = " + this.name + ", Age = " + this.age);
    }

    // Alternative using toString() - often preferred
    @Override    //this is an annotation to indicate that this method overrides a method in the superclass
    public String toString() {
        return "Dog [name=" + name + ", age=" + age + "]";
    }
}

// ======================================================


class Constants {
    
    public static final int NUMBER_OF_MONTHS_IN_A_YEAR = 12;
    public static final int NUMBER_OF_DAYS_IN_A_WEEK = 7;
    public static final String MY_NAME = "John"; // As used in the video

    // 5. Private Constructor
    private Constants() {
        System.out.println("-> Constants() Private Constructor Called! (Shouldn't happen from outside)");
        // This constructor typically remains empty.
    }

    // Static method example (could be part of a utility class)
    public static void printMyName() {
        System.out.println("My name constant is: " + MY_NAME);
    }
}

// ======================================================


public class Polymorphism {

    public static void main(String[] args) {
        System.out.println("--- Demonstrating Dog Constructors ---");

        // No-Args constructor
        System.out.println("\nCreating dog1 using new Dog():");
        Dog dog1 = new Dog();
        System.out.println(dog1); // Uses toString()

        //only a name (String)
        System.out.println("\nCreating dog2 using new Dog(\"Jerry\"):");
        Dog dog2 = new Dog("Jerry"); // Like the video example
        System.out.println(dog2);

        // only an age (int)
        System.out.println("\nCreating dog3 using new Dog(4):");
        Dog dog3 = new Dog(4);
        System.out.println(dog3);

        // takes both name (String) and age (int)
        System.out.println("\nCreating dog4 using new Dog(\"George\", 33):");
        Dog dog4 = new Dog("George", 33); // Like the video example
        System.out.println(dog4);


        System.out.println("\n\n--- Demonstrating Constants Class ---");

        // Accessing static members directly without creating an object
        System.out.println("Accessing static constant: Constants.NUMBER_OF_DAYS_IN_A_WEEK = " + Constants.NUMBER_OF_DAYS_IN_A_WEEK);
        Constants.printMyName(); // Calling static method


        System.out.println("\nAttempting to create Constants object (will cause compile error):");
        // Constants myConsts = new Constants(); // Uncommenting this line will give a compile error:
                                                 // "Constants() has private access in Constants"

        System.out.println("-> Successfully prevented instantiation of Constants class due to private constructor.");
    }
    
}