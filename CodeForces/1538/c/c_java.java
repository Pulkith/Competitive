import java.util.*;

public class c_java {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int T = s.nextInt();
        while(T-- > 0) {
            int N = s.nextInt(), L = s.nextInt(), R = s.nextInt();
            int arr[] = new int[N];
            for(int i = 0; i < N; ++i)
                arr[i] = (s.nextInt());
            
            Arrays.sort(arr);

            long below_min = 0, max = 0;


            for(int i = 0; i < 2; ++i) {
                int k = N-1;
                long cur = 0;
                for(int j = 0; j < N-1 && j < k; ++j) {
                    while(k > j && arr[(k)] + arr[(j)] > (i == 0 ? L-1 : R))
                        --k;
                    cur += Math.max(k - j, 0);
                }
                if(i == 0) below_min = cur;
                else max = cur;
            }

            System.out.println(max - below_min);
        }
    }
}
