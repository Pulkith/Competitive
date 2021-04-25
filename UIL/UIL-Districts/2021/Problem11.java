import java.util.*;
import java.util.*;

public class Problem11 {
    public static void main(String[] args) {
        int T = 0;
        Scanner s = new Scanner(System.in);

        T = Integer.parseInt(s.nextLine());
       
        for(int C = 1; C <= T; ++C) {
            String[] spl = s.nextLine().split(" ");
            int len = Integer.parseInt(spl[0]), clues = Integer.parseInt(spl[1]);

            //make char array for left half, while keeping center char if it is an odd-size string
            char [] arr = new char[(len%2==0) ? len/2: len/2+1];
            Arrays.fill(arr, ' ');
            boolean fal = false;
            //go through each clue
            for(int i = 0; i < clues; ++i) {
                spl = s.nextLine().split(" ");
                int index = Integer.parseInt(spl[0]) - 1;
                //make index of clue left-indexed
                index %= (len %2 == 0) ? len / 2 : (len/2+1);
                char ch = spl[1].charAt(0);
                //if an char already exists in the space, then the string cannot be a palindrome, so return 0
                if(arr[index] != ' ' && arr[index] != ch ){
                    fal = true;
                    break;
                }
                arr[(index)] = ch;
            }
            int c = 1;
            if(fal) 
                c = 0;
            if(!fal) {
            //if odd length string, and center is open, *= 26
            if(len % 2 != 0 && arr[len/2] == ' ') {
                c*= 26;
            }
            //go through the string and find empty spaces, for each one *= 26
                for(int i = 0; i < len/2; ++i) {
                    if((arr[i] == ' '))
                        c*= 26;
                }
            }
            System.out.println("Case #"+C+": " + (c));

        }
    }
}
/*
3
2 1
2 a
2 2
1 a
2 b
4 0



*/






/*
public class Problem11 {
    public static void main(String[] args) {
        int T = 0;
        Scanner s = new Scanner(System.in);

        T = Integer.parseInt(s.nextLine());
       
        for(int C = 1; C <= T; ++C) {
            String[] spl = s.nextLine().split(" ");
            int len = Integer.parseInt(spl[0]), clues = Integer.parseInt(spl[1]);

            char [] arr = new char[len];
            Arrays.fill(arr, ' ');
            boolean fal = false;
            for(int i = 0; i < clues; ++i) {
                spl = s.nextLine().split(" ");
                int index = Integer.parseInt(spl[0]);
                index -=1;
                index %= (len %2 == 0) ? len / 2 : (len/2+1);
                char ch = spl[1].charAt(0);
                if(arr[index] != ' ' && arr[index] != ch || arr[len - index-1] != ' ' && arr[len - index-1] != ch){
                    fal = true;
                    break;
                }
                arr[(index)] = ch;
                arr[arr.length - index - 1] = ch;
            }
            int c = 1;
            if(fal) 
                c = 0;
            if(!fal) {
            if(len % 2 != 0 && arr[arr.length/2] == ' ') {
                c*= 26;
            }
                for(int i = 0; i < arr.length/2; ++i) {
                   if(arr[i] != arr[arr.length - 1 - i] && ((arr[i] > 60) && ((arr[arr.length -1 - i] > 60)))) {
                      
                       c = 0;
                       break;
                   } else {
                       if((arr[i] == ' '))
                            c*= 26;
                   }
                }
            }
            System.out.println("Case #"+C+": " + (c));

        }
    }
}
*/