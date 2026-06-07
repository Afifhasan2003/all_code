



interface Nav{
    void print();
}
interface Body{void print();}
interface Footer{void print();}

class ModernNav implements Nav{
    @Override
    public void print(){
        System.out.print("modern nav\n");
    }
}
class ModernBody implements Body{
    @Override
    public void print(){
        System.out.print("modern body\n");
    }
}
class ModernFooter implements Footer{
    @Override
    public void print(){
        System.out.print("modern footer\n");
    }
}
class ClassicNav implements Nav{
    @Override
    public void print(){
        System.out.print("classic nav\n");
    }
}
class ClassicBody implements Body{
    @Override
    public void print(){
        System.out.print("classic body\n");
    }
}
class ClassicFooter implements Footer{
    @Override
    public void print(){
        System.out.print("classic body\n");
    }
}

//this is the abstract factory that we learning
interface DevFactory{
    Nav createNav();
    Body createBody();
    Footer createFooter();
}

class ModernDevFactory implements DevFactory{
    public Nav createNav(){
        return new ModernNav();
    }
    public Body createBody(){
        return new ModernBody();
    }
    public Footer createFooter(){
        return new ModernFooter();
    }
}
class ClassicDevFactory implements DevFactory{
    public Nav createNav(){
        return new ClassicNav();
    }
    public Body createBody(){
        return new ClassicBody();
    }
    public Footer createFooter(){
        return new ClassicFooter();
    }
}

class developWeb{
    Nav nav;
    Body body;
    Footer footer;
    public developWeb(DevFactory web){  //this doesnt know which style we are using
        this.nav = web.createNav();
        this.body = web.createBody();
        this.footer = web.createFooter();
    }

    public void generateWeb(){
        nav.print();
        body.print();
        footer.print();
    }
}



public class Main{

    static void genModernWebsite(){
        DevFactory cc = new ModernDevFactory();
        developWeb dWeb = new developWeb(cc);
        dWeb.generateWeb();
    }

    static void genClassicWebsite(){
        DevFactory cc = new ClassicDevFactory();
        developWeb dWeb = new developWeb(cc);
        dWeb.generateWeb();
    }
    public static void main(String[] args) {
        genModernWebsite();
        genClassicWebsite();
    }
}