import java.util.*;
import java.io.*;

public class Sheal {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while (T-- > 0) {
			String s = sc.next();
			int N = sc.nextInt();

			TreeSet<String> words = new TreeSet<>();
			ArrayList<Character> left = new ArrayList<>();
			for(char c : s.toCharArray())
				left.add(c);
			p(words, left, "");
			ArrayList<String> res = new ArrayList<>();
			for(String c : words)
				res.add(c);
			System.out.println(res.get(N));
		}
	}

	public static void p(TreeSet<String> ans, ArrayList<Character> opts, String cur) {
		ans.add(cur);
		for(int i = 0; i < opts.size(); ++i) {
			char c = opts.get(i);
			opts.remove(i);
			p(ans, opts, cur + c);
			opts.add(i, c);
		}
	}
}
