import java.util.*;

public class prob9 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = Integer.parseInt(s.nextLine());
        while(T-- > 0) {
           double d = Double.parseDouble(s.nextLine());
            long n = (long)(d*100);
            long[] res = new long[11];
            for(int i = 0; i < 11; ++i)
                res[i] = 0;
            double a[] = {10000, 5000, 2000, 1000, 500, 200, 100, 25, 10, 5, 1};
                for(int i = 0; i < 11; ++i){
                    while(n - a[i] >= 0 && n > 0) {
                        ++res[i];
                        n -= a[i];
                    }
                }
            for(long i : res)
                System.out.print(i);
            System.out.println();
        }
    }
}