import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class Problem3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int T = Integer.parseInt(s.nextLine());

        HashMap<String, Boolean> h = new HashMap<>();
        for(int i = 0; i < T; ++i) {
            String str1 = s.nextLine();
            String str = str1.toLowerCase();
            String end = str, front = str;
            boolean back = false, f = false;
            if(isP(str)){
                back = true;
                f = true;
            }
            while(end.length() > 0 && !back) {
                end = end.substring(0, end.length() - 1);
                back = h.containsKey(end) ? h.get(end) : isP(end);
                if(!h.containsKey(end))
                    h.put(end, back);

            }

            while(front.length() > 0 && !f) {
                front = front.substring(1);
                f = h.containsKey(front) ? h.get(front) : isP(front);
                if(!h.containsKey(front))
                    h.put(front, f);

            }
            int min = Math.min(str.length() - front.length(), str.length() - end.length());
            System.out.println(min + " character(s) need to be added to convert " + str1 + " into a palindrome.");


        }

    }
    public static boolean isP(String s) {
        for(int i = 0; i < s.length() / 2; ++i){
            if(s.charAt(i) != s.charAt(s.length() - 1 - i))
                return false;
        }
        return true;

    }
}
