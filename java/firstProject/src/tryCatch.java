public class tryCatch {
    public static void main(String[] args){
        int[] arr={1,2,3};

        // System.out.println(arr[4]);

        try{
            System.out.println(arr[4]);
        }catch(Exception abc){
            System.out.println("something went wrong");
            System.out.println("error is "+ abc);
            System.out.println("error is "+ abc.getMessage());  //just message
            abc.printStackTrace();      //shows where
        }


        System.out.println("program finished successfully");
    }
}
