import java.util.Scanner;

public class basic {
    public static void main(String[] args){
        int a; float f; String name , sentense;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter integer ");
        a= sc.nextInt();
        System.out.println("Enter float value ");
        f= sc.nextFloat();
        sc.nextLine();                          //to clear any leftover newline
        System.out.println("Enter stiring ");
        name = sc.next();
        sc.nextLine();                          //to clear any leftover newline
       
        System.out.println("Enter a line ");    
        sentense = sc.nextLine();


        System.out.println(a + " " +f + " "+ name);
        System.out.println(sentense);
    }
}
