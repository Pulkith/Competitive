import java.util.*;

public class c {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		while(T-- > 0) {
			int t = s.nextInt(), B = s.nextInt(), N = s.nextInt();
			String bs = Integer.toString(N, B);
			int ans = 0;
			for(char c : bs.toCharArray()) {
				if(c > '9') {
					int k = 10 + (c - 'a');
					ans += k * k;
				} else {
					int k = c - 48;
					ans += k * k;
				}
			}
			System.out.println(t + " " + ans);
		}
	}
}