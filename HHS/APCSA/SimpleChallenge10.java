public class SimpleChallenge10 {
    public static void main(String[] args) {
        /**
         * EX1
         * 
         * https://imgur.com/XlgUsNP
         * The abstract method assignCourses is established in the FacultyMember class, ensuring that child classes will implement it. That way, each class can 
         * have a definition of assignCourses that makes sense for it (depending on the rank and other issues). A program that manages a list of various faculty 
         * member objects could then assign courses to everyone by making a polymorphic call to assignCourses for each faculty member.
         */

         /**
          * EX2
          https://imgur.com/AfVfJSt
          The abstract method feedingInstructions is established in the ZooAnimal class, ensuring that child classes will implement it. That way, each class can 
          have a definition of feedingInstructions that makes sense for it. A program that manages a list of various animal objects could then print feeding instructions 
          for all animals by making a polymorphic call to feedingInstructions for each animal.
          */

          /**
           * EX3
           * https://imgur.com/uRmI2qX
           * The abstract method purchase is established in the Sale class, ensuring that child classes will implement it. That way, each class can have a definition 
           * of purchase that makes sense for it, as opposed to the computeTax method, which is implemented in Sale and used by all child classes as is. A program that 
           * manages the sales transactions as they occur could then conduct the transaction by making a polymorphic call to purchase no matter what the transaction type is.
           */

           /**
            * EX4
            By defining the pay method in StaffMember, all child classes must implement it (or be abstract themselves). So if pay were not defined in StaffMember, 
            the child classes would not have to implement it and the ability to pay all staff members through a polymorphic reference would not exist. It is only by formally
             establishing that all children of StaffMember have a pay method that makes it safe to pay them all.
            */

            /**
             * EX5
             * You could bind the property representing the end point of a horizontal line to the width of the scene so that the line is always long enough to span the scene.

             */
            /**
             * EX6 
             * myCircle.radiusProperty().bind(mySlider.valueProperty());
             */
    }
}
