import java.util.*;
import java.io.*;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0) {
            long seed = sc.nextLong();
            Random rand = new Random(seed);

            boolean turn = true;
            int sa = 0, sb = 0;

            int count = 14;
            ArrayList<Integer> arr = new ArrayList<>();
            for(int i = 0; i < 14; ++i)
                arr.add((i+1)*5);
            while(count-- > 0) {
                int flip = rand.nextInt(2);
                if(turn) {
                    sa += (flip == 1) ? arr.get(0) : arr.get(arr.size()-1);
                }
                else {
                    sb += (flip == 1) ? arr.get(0) : arr.get(arr.size()-1);
                }
                turn = !turn;
                arr.remove((flip==1?0:arr.size()-1));
            }
            System.out.println((sa > sb) ? "PLAYER A WON" : (sb > sa) ? "PLAYER B WON" : "TIE");
        }
    }
}