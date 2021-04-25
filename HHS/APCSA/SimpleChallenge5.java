import java.util.*;

public class SimpleChallenge5 {
    public static void main(String[] args) {
        // Ex 2
        // Whats wrong: the else statement is a part of the inner if statement as
        // opposed to the outer, which would output the wrong data
        if (total == MAX) {
            if (total < sum)
                System.out.println("total == MAX and < sum.");
        } else
            System.out.println("total is not equal to MAX");

        // EX3
        // an assignment operatoir is used as opposed to equality
        // the code will not compile(unless they were booleans for some reason)

        // EX4
        /*
         * apple orange pear
         */

        /*
         * EX5 lime grape
         */

        /*
         * EX7 5 9 13 17 21
         */

        /*
         * EX8 2 4 6 8 10 12 14 16 18
         * 
         */

        /*
         * EX9 count is never initialized, and there is a infinite loop present 1. Add
         * int next to count; 2. Do Count-- instead of count + 1; 3. Do while(count <=
         * 100) 4. Make count a byte so it overflows(xD) 5. Make it a for loop instead
         * of a while
         */

             /*
     * Ex 10
     */
        Scanner sc = new Scanner(System.in);
        int in= 0;
        try {
            in = sc.nextInt();
            if(in < 1) throw new Exception();
        }catch( Exception ex) {
            while(in < 1) {
               try{
                    in = sc.nextInt();
               } catch (Exception exInner){}
            }
        }

        /*
        Ex 11
        */
        String SENTINEL = "SENTINEL";
        do {
            String input = sc.nextLine();
            if(!input.equals(SENTINEL)) System.out.println(input);
        } while (!input.equals(SENTINEL));

    }
        // Ex 12;
        public static int maxOfTwo(int a, int b) { return Math.max(a, b); };
        
        //EX 13
        public static boolean larger(double a, double b) { return a > b;};
        //EX14
        public static boolean evenlyDivisble(int a, int b) { return (!(a == 0 || b == 0 || (!(a%b == 0 || b%a == 0)))); }
        //EX15
        public static boolean isAlpha(char c) { return ((c >= 65 && c<= 65+25) || (c >= 97 && c <=97+25));}
        //EX16
        public static boolean floatEquals(double a, double b, double c) { return Math.abbs(a-b) <= c; }
        //EX17
        public static boolean isIsoceles(int a, int b, int c) {return (a==b && a != c) || (a==c && a != b) || (b==c && a!=b);}

        //EX18
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
