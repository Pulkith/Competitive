public class SimpleChallenge8 {
    public static void main(String[] args) {
        // EX1
        /**
         * a. Invalid, need square brackets b valid, has type, name, square brackets and
         * initalizers list c: invalid, need "new" keyword d: invalid, cant have "new"
         * with an intializaer list d: Valid, has name, type, square brackets, and
         * proper intialization e: Valid, has type, name, square brackets and
         * initalizers list f: invalid, need a size in the square brakcets
         */

        // EX2
        /**
         * Program to find max of 10+ numbers Program to find average of 10+ numbers
         * Progam to sort 100 numbers Proram to find if a word is a pangram Program to
         * find the mean and std of stock data
         */

        // EX3
        /**
         * The elements are sort in a an array contiguosuly in memory. THe name is a
         * reference to the array object at the beginig of the ierator of the data in
         * memory. To compute the address of a particular element, the address of the
         * first data element is multiplied by the index (25) and the size of the array
         * element. That is why array indexes begin at zero.
         * 
         */

        // EX4
        /**
         * It skips the first element and tries to access a nonexistenent elemnt. Can be
         * fixed by starting at 0 and using < instead of <=
         */

        // EX5a
        String[] students = new String[25];
        //EX5b
        int[] grades = new int[40];

        // EX5c
        Transactions[] charges = new Transactions[MAX];
        public class Transactions {
            private int transactionNumber;
            private String merchantName;
            private  charge;
        }

        //EX5d
        Student[] myClass = new Student[MAX];
        public class Student {
            private String name; 
            private int[] grades; // etc.
        }
        //EX6e
        Employee[]employees = new Employee[MAX];
            public class Employee {
                private int employeeNumber;
                private String hireDate;
                private double raise[] = new double[5]; // etc.
            }
        //EX6
        for (int index = 0; index < nums.length; index++) nums[index] = INITIAL;
        
        //EX7
        for (int index = names.length-1; index >= 0; index--)
            System.out.println(names[index])
        //EX8
        for (int index = 0; index < flags.length; index++) flags[index] = (index%2 == 0);

    }

    // EX9
    public float sumArray(float[] values) {
        float sum = 0;
        for (int index = 0; index < values.length; index++)
            sum += values[index];
        return sum;
    }

    // EX10
    public void switchThem(int[] first, int[] second) {
        if (first.length == second.length) {
            // copy contents of first into temp int [] temp = new int[first.length]; for
            // (int i=0; I < first.length; i++)
            temp[i] = first[i];

            // copy contents of second into first for (int i=0; I < first.length; i++)
            first[i] = second[i];
            // copy contents of temp into second for (int i=0; I < first.length; i++)
            second[i] = temp[i];
        } else
            System.out.println("Arrays are of different sizes");
    }


    //EX11
    /**
     * A prgoram tracking orders for a business would need an arraylist becuase the numbber shsould be able
     * to change dynamically. A program that is a planner, would use an array, becuase the number of horus remains the samwe
     * every day
     */

     //EX12
     /**
      * If the program listened instead for a mouse released event, the position and appearance of the dot would
       be determined at the time of the release, and wouldn’t appear until the mouse button was released.
        Similarly, if the program listened for a mouse clicked event, the position and appearance of the 
        dot would be determined at the time of a click (which requires a press followed by a release).
      */

      //EX13
      /**
       * Currently, the event handler processing the choice box selection only stops the current song and 
       * sets the new current song. To play a new song immediately when it's selected, the following 
       * line could be added at the end of the processChoice method:
        current.play();
       */
      //EX14
      /**
       * The program is largely data-driven, so the song names would have to be added to the names array 
       * and the corresponding audio files would have to be added to the audioFiles array. The program is 
       * designed to work for any size array.
       */

}
