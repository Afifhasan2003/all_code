

class Student{
    String name;
    String roll;
    String father;
    String mother;
    private Student(StudentBuilder s){
        this.name = s.name;
        this.roll = s.roll;
        this.father = s.father;
        this.mother = s.mother;
    }
    public void printDetail(){
        System.out.println(father==null? "without parent" : "with parent");
    }

    public static class StudentBuilder{
    String name;
    String roll;
    String father = null;
    String mother = null;

    public StudentBuilder(String name, String roll){
        this.name = name;
        this.roll = roll;
    }

    StudentBuilder addFather(String father) {
        this.father = father;
        return this;
        }
    StudentBuilder addMother(String mother){
        this.mother = mother;
        return this;
    }

    Student build(){
        return new Student(this);
    }
    }

}

public class Main{  
    public static void main(String[] args) {
        
    Student st1 = new Student.StudentBuilder("afif","123").build();
    st1.printDetail();

    Student st2 = new Student.StudentBuilder("hasan","99")
        .addFather("farid")
        .addMother("meherun")
        .build();        

    st2.printDetail();

    }


}