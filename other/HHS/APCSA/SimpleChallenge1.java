import java.util.*;
import java.text.DecimalFormat;

public class SimpleChallenge1 {
    public static void main(String[] args) {
        //EX1
        String overview = "overview";
        System.out.println(overview.length());

        //EX2
        String introduction = "introduction";
        System.out.println(introduction.charAt(7));

        //EX3
        String name = "name";
        String str = name.toUpperCase();

        //EX4
        String original = "abcde";
        String change = original.replaceAll("e", "j");

        //EX5
        //Quest for the Holy Grail quest for the holy grail

        //EX6
        // It imports every class in the awt package

        //EX7
        /*
        a -> Number from 0 to 19
        b -> Random number from 1 to 8
        c -> Random number from 2 to 13
        d -> random number from 10 to 44
        e -> Random number from -50 to 49

        */

        //EX8
        Random rand = new Random();
        int a = rand.nextInt(11);
        int b = rand.nextInt(401);
        int c  = rand.nextInt(400)+1;
        int d = rand.nextInt(26) + 25;
        int e = rand.nextInt(26)-10;
        
        //EX9
        double num1 = 5, num2 = 20;
        double num3 = Math.sqrt(num1+num2);

        //EX10
        double total = num3;
        System.out.println(Math.abs(total));

        //EX11
        DecimalFormat df = new DecimalFormat("#.####");
        System.out.println(df.format(5.55555));

        //EX12
        Scanner s = new Scanner(System.in);
        double input = s.nextDouble();
        df = new DecimalFormat("#.###");
        System.out.println(df.format(Math.pow(input, 4)));

        //EX 14.
        /*
            They both use the left direction as increasing x, and the right direction as decreasing y. They are botha a 2D grid system with unit squares
            As for differences, the origin on java is top left, while on a cordinate system is the bottom left. For java increeasing y is down, while on the cordinate plane
            increasing y is up
        */

        //EX15
        /*
        a. ArithmeticException -> thrown when illegeal arithmetic is performed such as division by 0
        b. NullPointerException -> an attempt is made to access or use an object that has a null value
        c. NumberFormatException -> Error when numericla objects are unable to convert strings into their respective value types
        d. PatterSyntaxException -> thrown when there is a syntax error or malformed regex 
        e. IOException -> Thrown when an IO Operation fails, such as reading a file, writing to a file etc...
        f. ParseException -> thrown when parsing a string into a diffrent format, such an invalid strin to a date object
        h. ArrayIndexOutOfBoundsException -> Runtime error when the program tries to access an array index that does not exist
        i. StringIndexOutOfBoundsException -> Runtime error when the program tries to access an string index that does not exist
        k. ClassCastException -> thrown when the program tries to cast a class object to a related class, but of which the object is not an instance of
        l. IllegalArgumentException -> thrown when you attempt to pass invalid arguments into a method
        */


    }   
}