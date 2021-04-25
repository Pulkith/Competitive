import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Problem7 {
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(new File("joyce.dat"));

        int T = Integer.parseInt(s.nextLine());


        for(int i = 0; i < T; ++i) {
            int[] hold = new int[26];
            String str = s.nextLine().toLowerCase();
            char[] x = str.toCharArray();
            for(char c : x) {
                if((int) c >= 97 && (int)c <= (97+25)) {
                    ++hold[c-97];
                }
            }
            String missing = "";
            boolean perfect=  true;
            for(int h = 0; h < 26; ++h) {
                missing += (hold[h] < 1) ? ((char)(h+97)) : "";
                if(hold[h] > 1)
                    perfect = false;
            }
            System.out.println((missing.length() > 0) ? ("miss" +
                    "ing " + missing) : (perfect) ? "perfect pangram" : "pangram");



        }
    }
}
