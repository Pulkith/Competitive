import java.util.*;

public class j_novice {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt(), M = scan.nextInt();
		int[] colors = new int[N];
		TreeMap<Integer, Integer> ts = new TreeMap<>();
		for(int i = 0; i < N; i++) {
			int u = scan.nextInt();
			if(ts.containsKey(u)) ts.put(u, ts.get(u) + 1);
			else ts.put(u, 1);
		}
		for(int i = 0; i < M; i++)
			colors[i] = scan.nextInt();
		int ans = 0;
		for(int i = 0; i < M; ++i) {
			int ceil = ts.ceilingKey(colors[i]);
			ans += ceil - colors[i];
			if(ts.get(ceil) > 1) ts.put(ceil, ts.get(ceil) - 1);
			else ts.remove(ceil);
		}
		System.out.println(ans);
	}
}