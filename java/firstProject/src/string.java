public class string {

    public static void  main(String[] args){
        String name1 = "afif";
        String name2="hasan";
        System.out.println(name1);

        String name3=name1 + " " + name2;
        System.out.println("full name is " + name3);

        System.out.println("Second character is " + name1.charAt(1));

        System.out.println("string length is " + name3.length());

        String name4 = name3.replace('a', 'x');
        System.out.println("altered name is " + name4); //name3 will not change , string are immutable in java

        String name5 = name3.substring(0, 5);           // (include, doesnt include) =(0,5)
        System.out.println("fisrt name is "+name5);
        System.out.println("first name is "+name3.substring(0,5)); //this works too

        
    }
    
} 
