import java.util.*;
import java.io.*;

public class Problem1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        long N = sc.nextLong(), L = sc.nextLong();
        ArrayList<Integer> cits = new ArrayList<>();
        for(int i = 0; i < N ; ++i) {
            cits.add(sc.nextInt());
        }

        long[] count = new long[100002];
        double[] sum = new double[100002];
        int max = -1;
        int min = Integer.MAX_VALUE;
        for(int i : cits){
            ++count[i];
            max = Math.max(max, i);
            min = Math.min(min, i);
        }
        sum[max] = count[max];
        for(int i = max-1; i >= min; --i){
            sum[i] = count[i] + sum[i+1];
        }
        int hindex = 0;
        for(int i = min; i <= max; ++i) {
            if(sum[i] >= i)
                hindex = Math.max(hindex, i);
        }
        if(L == 0) {
            System.out.println(hindex);
        } 
        else {
            if(max == 0)
                System.out.println(1);
            else{
                long fin = 0;
                for(int i = max+1; i >= min; --i) {
                    if(sum[i-1]>= i && (i - (sum[i])) <= L) {
                        fin = i;
                        break;
                    }
                }
                System.out.println(Math.max(fin, hindex));
            }
        }
    }
    
}
