import java.util.*;
import java.io.*;

public class Ishika {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T -- > 0) {
			int N = sc.nextInt();
			int a[] = new int[N];
			int freq[] = new int[100];
			TreeSet<Integer> nums = new TreeSet<>();
			for(int i = 0; i < N; ++i){
				a[i] = sc.nextInt();
				nums.add(a[i]);
				++freq[a[i]];
			}
			int ans = 30000;



			for(int i = 0; i < N; ++i) {
				Integer need = Math.max(0, 20  - a[i]);
				Integer res = nums.ceiling(need);
				if(res != null) {
					if((int)res == a[i] && freq[a[i]] == 1) 
						res = nums.higher(res);
					if(res != null)
						ans = Math.min(ans, res + a[i]);
				}
			}

			if(ans != 30000) System.out.println(ans);
			else System.out.println("NOT POSSUBLE");


		}
 	}
}
