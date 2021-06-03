import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = Integer.parseInt(scan.nextLine());

        while(T-- > 0) {
            int N = Integer.parseInt(scan.nextLine());
            TreeMap<Character, Integer> mp = new TreeMap<>();

            for(int i = 0; i < N; ++i) {
                String s = scan.nextLine();
                for(char c : s.toCharArray()) {
                    if(mp.containsKey(c))
                        mp.put(c, mp.get(c) + 1);
                    else
                        mp.put(c, 1);
                }
            }
            boolean ok = true;
            for(Map.Entry<Character,Integer> entry : mp.entrySet()) {
                Integer value = entry.getValue();
                if(value % N != 0) {
                    System.out.println("NO");
                    ok = false;
                    break;
                }
            }
            if(ok) {
                System.out.println("YES");
            }
        }
    }
}
