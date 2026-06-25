class User implements Cloneable{
    String institute;
    String country;
    String type;
    String permissionLevel;
    String name;
    String id;

    public User (String institute, String country, String type){
        this.institute = institute;
        this.country = country;
        this.type = type;
        this.permissionLevel = type; //suppose this is the db call, it takes time
    }
    public User (User user){
        this.institute = user.institute;
        this.country = user.country;
        this.type = user.type;
        this.permissionLevel = user.permissionLevel;  //this is now changed, wont do db call anymore, its done when creating the template
    }


    @Override
    public User clone(){
        return new User(this);
    }

    public User setName(String name){
        this.name = name;
        return this;
    }
    public User setID(String id){
        this.id = id;
        return  this;
    }

}



public class Main{
    public static void main(String[] args) {
        User studentTemplet = new User("DU","BD","Student");
        User teacherTemplet = new User("DU","BD","Teacher");
        User adminTemplet = new User("DU","BD","Admin");


        User st1 = studentTemplet.clone().setName("afif").setID("123");
        User teacher1 = teacherTemplet.clone().setName("hasan").setID("999");
    }

}