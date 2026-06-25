

interface GradingSystem{
    double provideGrade(double number);
}

//this code is existing for a long time, can not edit it
class OldGradingSystem{
    public String lagacyGrade(double number){
        if(number < 33){
            return "F";
        }else if (number > 33 && number < 50) {
            return "C";
        }else if(number < 60){
            return "B-";
        }else if(number < 70){
            return "B";
        }
        else if(number<80){
            return "A";
        }
        else{
            return "A+";
        }
    }
}

//this is the adapter(that connects existing code with new)
class Adapter implements GradingSystem{

    OldGradingSystem old;
    

    public Adapter(OldGradingSystem old) {
        this.old = old;
    }

     @Override
     public double provideGrade(double number){

        String grade = old.lagacyGrade(number);

        if(grade.equals("A+")) return 4.00;
        else if(grade.equals("A")) return 3.75;
        else if(grade.equals("B")) return 3.5;
        else if(grade.equals("B-")) return 3.25;
        else if(grade.equals("C")) return 3.0;
        else return 0;

     }
}

//using new code
class ReportCard{
    OldGradingSystem old;
    double number;
    double cg;
    GradingSystem newGrading = new Adapter(old);

    public ReportCard(OldGradingSystem old){
        this.old = old;
    }

    public ReportCard(OldGradingSystem old, double number) {
        this.old = old;
        this.number = number;
        this.cg = newGrading.provideGrade(number);
    }

}

public class Main {
    public static void main(String[] args) {
        OldGradingSystem old = new OldGradingSystem();
        ReportCard rc = new ReportCard(old, 75.0);
        System.out.println("CGPA: " + rc.cg);
    }
}