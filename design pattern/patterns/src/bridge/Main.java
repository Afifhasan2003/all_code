interface Render{
    void renderCircle(double r);
    void renderSquare(double s);
}

class VectorRender implements Render{
    @Override 
    public void renderCircle(double radius){
        System.out.println("rendered circle by vector");
    }
    @Override
    public void renderSquare(double side){
        System.out.println("rendered square by vector");
    }
}

class RasterRender implements Render{
    @Override 
    public void renderCircle(double radius){
        System.out.println("rendered circle by Raster");
    }
    @Override
    public void renderSquare(double side){
        System.out.println("rendered square by Raster");
    }
}


abstract class Shape{
    Render renderer;  //here is the link(this is called bridge)



    public Shape(Render renderer){
        this.renderer = renderer;
    }

    public abstract void draw();

}

class Circle extends Shape{
    double radius;

    public Circle(Render renderer, double radius){
        super(renderer);
        this.radius = radius;

    }
    @Override
    public void draw(){
        renderer.renderCircle(radius);
    }
}
class Square extends Shape{
    double side;

    public Square(Render renderer, double side){
        super(renderer);
        this.side = side;

    }
    @Override
    public void draw(){
        renderer.renderSquare(side);
    }
}


// now if we want to add a new render
class SvgRender implements Render{
    @Override 
    public void renderCircle(double radius){
        System.out.println("rendered circle by svg");
    }
    @Override
    public void renderSquare(double side){
        System.out.println("rendered square by svg");
    }
}







public class Main {
    public static void main(String[] args) {
        Render r1 = new VectorRender();
        Render r2 = new RasterRender();

        Shape c1 = new Circle(r1, 5);
        c1.draw();

    }
}