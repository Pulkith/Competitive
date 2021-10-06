import java.util.*;

public class practice {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt(), Q = scan.nextInt();
		int[] arr = new int[N];
		for(int i = 0; i < N; i++)
			arr[i] = scan.nextInt();
		long[] prefix = new long[N];
		for(int i = 0; i < N; ++i) {
			prefix[i] = arr[i];
			if(i > 0) prefix[i] += prefix[i-1];
		}
		for(int q = 0; q < Q; ++q) {
			int l = scan.nextInt(), r = scan.nextInt();
			if(l == 1) System.out.println(prefix[r-1]);
			else System.out.println(prefix[r-1] - prefix[l - 2]);
		}	
	}
}