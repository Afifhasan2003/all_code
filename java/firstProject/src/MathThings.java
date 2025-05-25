public class MathThings{
    public static void main(String[] args){

        final float PI= 3.1416F; //or final double PI=3.1416
        System.out.println(PI);

        int a=2, b=6;
        System.out.println("Bigest number is " + Math.max(a,b));
        System.out.println("Smallest number is " + Math.min(a,b));

        //random
        System.out.println(Math.random());                 //(0.0 , 1,0)
        System.out.println((int)(Math.random()*100));        //(1,100);
        
    }
}
