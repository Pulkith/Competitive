public class SimpleChallenge7 {
    //EX1
    public double average(int num1, int num2) {
        return(num1 + num2) / 2.0; 
    }
    //EX2
    public double average(int num1, int num2, int num3) {
        return (num1 + num2 + num3) / 3.0; 
    }

    //EX3
    public double average(int num1, int num2, int num3, int num4) {
    return (num1 + num2 + num3 + num4) / 4.0; 
    }
    //EX4
    public String multiConcat(String text, int count) {
        String result = text;
        if (repeats > 1)
        for (int i=2; i <= count; i++)
        result += text;
        return result; 
    }

    //EX5
    public String multiConcat(String text) {
        return text + text;
    }
    //EX6
    public void makeCircle(int centerX, int centerY, int radius, Color color) {
        Circle circle = new Circle(centerX, centerY, radius); circle.setFill(color);
        return circle;
    }   
    //EX7
    public void makeCircle(int centerX, int centerY, int radius) {
        Circle circle = new Circle(centerX, centerY, radius); circle.setFill(Color.RED);
        return circle;
    }
    //EX8
    public void makeCircle(int centerX, int centerY, Color color) {
    Random generator = new Random();
    int radius = generator.nextInt(11) + 10;
    Circle circle = new Circle(centerX, centerY, radius); circle.setFill(color);
    return circle;
    }
    //EX9
    public void makeCircle(int centerX, int centerY) {
        Circle circle = new Circle(centerX, centerY, 40); circle.setFill(Color.GREEN);
        return circle;
    
    }
    /**
     * EX 10
     * Java passes paramtets by value. THe value passes from the actual paramter to the formla paramter and
     * can then e used in the method. With primities a value is sent, and for objects, the reference of the object
     * is passed, and so the object itself is updated/mutated in the method. This bbehaior is unique for objects
     * 
     */

     /**
      * 
      * EX11
      Static methods are called through the class rather then an object, while the opposite is true for instance varibales
      thus, a method cannot use na instance variable that was never instantiated, and so cannot call them
      */

      /**
       * EX12
       * Yes a class can, as long are impkemntations are present. It satisfies the requirements for both
       * of the interfaces so it is good
       */


    public static void main(String[] args) {
        
    }
}
//13
public interface Visible {
    public boolean makeVisible();
    public boolean makeInvisible(); 
}
// a class that has this interface would implement it in its header, and would have two method signaures that match those in the interface
/**
 * |--------------------------|                |-----------------|
 * |  <<Interface>> Visible   |                |    ControlPanel |
 * | -------------------------| <<realize>>    |-----------------|
 * | +makeVisible(): boolean  | <------------  |  -red: JSlider  |
 * | +makeInvsible(): boolean |                |  -green: JSlider|
 * |--------------------------|                |  -blue: JSlider |
 *                                             |-----------------|
 *                                             |+getColor():Color|
 */                                            |-----------------|
    
