import java.util.*;
import java.io.*;
import java.awt.*;


class Problem2 {
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(new File("angry.in"));
        //Scanner s = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("angry.out")));
        //PrintWriter out = new PrintWriter(System.out);
        int N = s.nextInt();
        boolean arr []= new boolean[1000000+1];
        while(N-- > 0)
            arr[s.nextInt()] = true;
        int max = 1;
        for(int i = 0; i < arr.length; ++i) {
            if(arr[i]) {
                int cur = 0;
                int l = i, r = i;
                int ld = 1, rd = 1;
                boolean ldone = true, rdone = true;
                ++cur;
                while(ldone && l > -1) {
                    int last = l;
                    do {
                        int con = cur;
                        int j;
                        for(j = last-1; j >= last-ld && j > -1; --j){
                            cur += arr[j] ? 1 : 0;
                            last = arr[j] ? j : last;
                        }
                        if(cur > con && j > -1){
                            ++ld;
                        }
                        else
                            ldone = false;

                    } while(ldone);
                }
                while(rdone && r < arr.length) {
                    int last = r;
                    do {
                        int con = cur;
                        int j;
                        for(j = last+1; j <= last+rd && j < arr.length; ++j){
                            cur += arr[j] ? 1 : 0;
                            last = arr[j] ? j : last;
                        }
                        if(cur > con && j < arr.length){
                            ++rd;
                        }
                        else
                            rdone = false;

                    } while(rdone);
                }
                max = Math.max(cur, max);
            }

        }
        out.println(max);



        out.close();
    }
}
