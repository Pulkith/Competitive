public class SimpleChallenge2 {
    public static void main(String[] args) {
        /*
            Ex1 Superhero(Class) -> Superman(Object)
                Pet(Class) -> Rover(Object)
                Magezine(Clas) -> Time(Object)
                Holiday(Class) -> Christmas(Object)
        */

        /*
            Ex2 
            int width
            int height
            int diagonal
            Picture picutre
            replacePicture()
            insertPicture()
            removePicture()
            clean()
        */

        /*

        Ex3
            start()
            end()
            pause()/break()
            record()
            countParticipants()
            log()
            nextAgenda()
            listAgenda

            Item currentAgendaItem
            Person headPerson
            Person speaker
            int/double time
            String roomNumber
            getgRoomNumber()
            setRoomNumber()
        */

        /* 
        Ex4
        String Teacher
        String[] Alumni
        String[] Particanpts
        String[] Units
        String courseCategory
        String numCredits
        String Description

        listAlumni()
        listParticipants()
        getDescritpion()
        setDescription()
        */


    }

    /*
    Ex5
    */
    public static void lyrics() {
        System.out.println("Baby Shark do do do do do");
        System.out.println("Baby Shark do do do do do");
        System.out.println("Baby Shark do do do do do");
        System.out.println("Baby Shark");
        System.out.println("Mama Shark do do do do do");
        System.out.println("Mama Shark do do do do do");
        System.out.println("Mama Shark do do do do do");
        System.out.println("Mama Shark");
        System.out.println("Papa Shark do do do do do");
        System.out.println("Papa Shark do do do do do");
        System.out.println("Papa Shark do do do do do");
        System.out.println("Papa Shark");
    }
    //Ex 6
    public static int cube(int num) {
        return (int)Math.pow(num, 3);
    }
    //Ex 7
    public static int random100() {
        return (int)(Math.random*100) + 1;
    }
    //Ex 8
    public static int randomInRange(int num1, int num2) {
       return (int)(Math.random * (num1 - num2+ 1)) + num2;
    }
    //Ex 9
    public static Collector  randomColor() {
        return new Color((int)(Math.random() * 256),(int)(Math.random() * 256),(int)(Math.random() * 256));
    }
    //Ex 10
    class Movie  {
        private String title, director;
        public Movie(String title, String director) {
            this.title = title;
            this.director = director;
        }
    }

    //Ex 11
    class Child {
        int age;

        public int getAge() { return this.age; };
        public void setAge(int age) { this.age = age; };
    }

    //Ex 12
    class Child12 {
        double weight, height;

        double superWeight;

        public double doubleWeight() {
            double superWeight = weight*height;
            this.superWeight = superWeight;
            return superWeight;
        }

        public void setWeight(double weight) {
            this.weight = weight;
        }
        public void setHeight(double height) {
            this.height = height;
        }
        public double getWeight() { return this.weight;};
        public double getHeight() { return this.height; };
    }
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

