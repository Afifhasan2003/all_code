public class Storage {

    public static void main(String[] args){

        Iit s1 = new Iit();
        s1.bsse1615 = "afif";
        s1.roll = 15;
        s1.setPassword("afif@gmail.com");

        System.out.println(s1.bsse1615);

        System.out.println(s1);  //this is how we print customised total object. 
                                 // we cant directly print full object like sturct in C
        
    }
}

class Iit{
    public String bsse1615;
    protected int roll;
    private String email; 
    public void setPassword(String pass) {      //this trick is called setter
        this.email=pass;
    }     
    @Override
    public String toString() {
        return "Name: " + bsse1615 + ", Roll: " + roll;
    }
}