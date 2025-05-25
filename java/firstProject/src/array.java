import java.util.Arrays;  //this package is for sort function

public class array {
    public static void main(String[] args){

        int arr1[]={1,2,3};     //initailize with value
        int[] arr2 = {4,5,6};
        
        System.out.println(arr1[1]);
        System.out.println(arr2[1]);
        
        // int arr5[3];arr5[1] = 5;  cannot do this

        int[] arr3 = new int[3];                                     //initialize with zero
        arr3[1] =5;
        arr3[2] = 2;
        System.out.println(arr3[0]+" "+ arr3[1]);

        System.out.println("length of array is " + arr3.length);  //not length()

        //sorting
        Arrays.sort(arr3);                                        //in accending order
        System.out.println(arr3[0]+" "+ arr3[1]);



        //2D array

        int arrD[][] = {{1,2,3},{7,8,9}};
        System.out.println("first element of first row is " + arrD[0][0]);
    }
}
