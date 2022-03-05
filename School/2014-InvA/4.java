import java.util.*;

class P4 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = Integer.parseInt(s.nextLine());
		while(T -- > 0) {
			String[] S = s.nextLine().split(" ");
			HashMap<String, Integer> ll = new HashMap<>();
			for(String w : S) {
				if(ll.containsKey(w)) ll.put(w, ll.get(w) + 1);
				else ll.put(w, 1);
			}
			int mx = 0;
			for(String k : ll.keySet()) {
				mx = Math.max(mx, ll.get(k));
			}
			ArrayList<String> ans = new ArrayList<>();
			for(String k : ll.keySet()) {
				if(ll.get(k) == mx) {
					ans.add(k);
				}
			}
			Collections.sort(ans);
			for(int i = 0; i < ans.size(); ++i)
				System.out.print((i == 0 ? "" : " ") + ans.get(i));
			System.out.println();
		}
	}	
}
