import java.util.*;

public class Problem11Simple {
    public static void main(String[] args) {
        int T = 0;
        Scanner s = new Scanner(System.in);

        T = Integer.parseInt(s.nextLine());
       
        for(int C = 1; C <= T; ++C) {
            String[] spl = s.nextLine().split(" ");
            int len = Integer.parseInt(spl[0]), clues = Integer.parseInt(spl[1]);

            char [] arr = new char[(len%2==0) ? len/2: len/2+1];
            Arrays.fill(arr, ' ');
            boolean fal = false;
            for(int i = 0; i < clues; ++i) {
                spl = s.nextLine().split(" ");
                int index = Integer.parseInt(spl[0]);
                index -=1;
                index %= (len %2 == 0) ? len / 2 : (len/2+1);
                char ch = spl[1].charAt(0);
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
            if(len % 2 != 0 && arr[len/2] == ' ') {
                c*= 26;
            }
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