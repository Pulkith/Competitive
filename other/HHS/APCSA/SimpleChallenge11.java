public class SimpleChallenge11 {
    public static void main(String[] args) {
        /**
         * EX1
         * https://imgur.com/C6PKMCd
         */
        
         /* 
         * EX2
         * If the try statement were removed from the level1 method, the ArithmeticException, when thrown, would propagate to the main method (which calledthelevel1method). 
         * Sincethereisnotrystatementinthemainmethod,the program would terminate, producing the message associated with the exception.
         */

         /**
          * EX3
          * If the try statement were moved from the level1 method to the level2 method, the exception thrown in level3 would propogate only to level2, 
          where it would be caught and handled. The level2 method would then be allowed to finish execution.
          */

     
        /*

        EX4
        a. ArithmeticException -> thrown when illegeal arithmetic is performed such as division by 0
        b. NullPointerException -> an attempt is made to access or use an object that has a null value
        c. NumberFormatException -> Error when numericla objects are unable to convert strings into their respective value types
        d. PatterSyntaxException -> thrown when there is a syntax error or malformed regex  
        */

        /**
         * EX5
         * You might disable a button used to move to the next step of a process until the current step has been completed or until the data being requested is filled in and validated.
         */

         /**
          * EX6
          The property binding binds the width of the image view to the width of the pane in which the image is displayed. So if that properyt binding wasn't set 
          up, the image size would dictate the window size, which might vary from one image to the next.
          */
    }
}
