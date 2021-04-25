public class SimpleChallenge6 {
    public static void main(String[] args) {
        //EX1
        /*
        a-> 20
        b-> 20
        c -> 15
        d -> 19
        e -> 10
        f -> 5


        */

        //EX2
       /*
        0, 2, 4....198,200
       */

        //EX3
        // All numbbers from 200 -> 1 except numbeers divisnble by 0

        //EX4
        int num = 1;
        do {
            ++num;
            System.out.println(num);
        } while(num < 20);
        //EX5
        for(int i = 01; i < 20; ++i)
            System.out.println(i);
        //EX6;
        Scaner sc = new Scanner(System.in);
        int val = sc.nextInt();
        do {
           val = sc.nextInt(); 
        } while(!(sc % 2 == 0));

        //EX7
        for (int value = 1; value <= 99; value +=2)
            System.out.println(value);
        
        //EX8
        for (int value = 300; value >= 3, value -= 3)
            System.out.println(value);

        //EX9
        Scanner scan = new Scanner(System.in); 
        int max, number; 
        System.out.print("Enter an integer: "); 
        max = scan.nextInt();
        for (int count = 2; count <= 10; count++) {
            System.out.print ("Enter another integer: "); number = scan.nextInt();
            if (number > max)
            max = number; 
        }
        System.out.println("The highest value is :" + max);

        //EX10
        int count = 0;
        for (int index = 0; index < name.length(); index++)
        if (name.charAt(index) == 'a') count++;
        System.out.println("The character \'a\' appears " + count + " time(s)");

        //EX11
        for (int index = str.length()-1; index >= 0; index--) 
            System.out.print(str.charAt(index));
        System.out.println();
        //EX12
        for (int index = 0; index < word.length(); index +=2) 
            System.out.println(word.charAt(index));
    }

    // 13
    public void powersOfTwo() {
        int base = 2;
        for (int power = 1; power <= 10; power++)
            System.out.println(Math.pow(base, power));
    }

    // 14
    public void alarm(int number) {
        if (number < 1)
            System.out.println("ERROR: Number is less than 1.");
        else
            for (int count = 1; count <= number; count++)
                System.out.println("Alarm!");
    }

    // 15
    public int sum100() {
        int sum = 0;
        for (int count = 1; count <= 100; count++)
            sum += count;
        return sum;
    }

    // 16
    public int sumRange(int start, int end) {
        int sum = 0;
        if (end < start)
            System.out.println("ERROR: Invalid Range");
        else
            for (int num = start; num <= end; num++)
                sum += num;
        return sum;
    }

    // 17
    public int countA(String text) {
        int count = 0;
        for (int index = 0; index < text.length(); index++)
            if (text.charAt(index) == 'A')
                count++;
        return count;
    }
    //18
    public String reverse(String text) {
        String result = "";
        for (int place = text.length()-1; place >= 0; place--) result += text.charAt(place);
        return result; 
    }

    //19
    /**
     * The color was first white, and then its changed to red. they then alternate with black.
     */

     //20
     /**
      * It will be yellow, becuase that is the first condition checked.If the box is narrow, the height isnt checked
      */

      //21
      if (width < 10 && height < 10) fill = Color.ORANGE;
      else if (width < 10) fill = Color.YELLOW;
      else if (height < 10) fill = Color.GREEN;

      //22
      rec.setTranslateX(50); 
      rec.setTranslateY(10); 
      rec.setScaleX(0.5);
      rec.setScaleY(0.5);

      //23
      pic.setRotate(180); 
      pic.setScaleX(2.0); 
      pic.setScaleY(2.0);

      //24: The transformation is applied to each node in the group.

}
