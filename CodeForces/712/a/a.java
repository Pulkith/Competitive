import java.util.*;
 class Problem1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int T = Integer.parseInt(s.nextLine());

        while(T-- > 0) {
            String str = s.nextLine();
            String poss = "";
            int left = 0, right = 0;
            boolean same = true;
            for(int i = 0; i < str.length(); ++i) {
                if(i > 0 && !(str.charAt(i)==str.charAt(i-1))) {
                    same = false;
                }
                if(str.charAt(i) == 'A' || str.charAt(i) == 'a') {
                    if (((str.length() % 2 == 0 && i >= str.length() / 2) || (str.length() % 2 == 1 && i > str.length() / 2))) {
                        ++right;
                    } else {
                        if (!(str.length() % 2 == 1 && i == str.length() / 2))
                            ++left;
                    }
                }
            }
            if(same) {
               poss = "NO";
            } else if(left == right || right > left) {
                poss = "Yes\n"+str + "a";
            }
            else  {
                poss = "Yes\n"+"a" + str;
            }
            System.out.println(poss);
/*
2
a
aa
        */
        }
    }
    // public static boolean isPal(String s) {
    //     for(int i = 0; i < s.length()/2; ++i) {
    //         if(s.charAt(i) != s.charAt(s.length() - 1 - i))
    //             return false;
    //     }
    //     return true;
    // }
}