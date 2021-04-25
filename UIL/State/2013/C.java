import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N = Integer.parseInt(s.nextLine());
        int tick = 100;
        for(int i  = 1; i <= N; ++i) {
            long seed = Long.parseLong(s.nextLine());
            Random ran = new Random(seed);
            //items -> tickets
            TreeMap<String, ArrayList<Integer>> mp1 = new TreeMap<>(String.CASE_INSENSITIVE_ORDER);
            //tickets -> name
            HashMap<Integer, String> mp2 = new HashMap<>();
            int cur = 0;
            int num = Integer.parseInt(s.nextLine());
            for(int j = 0; j < num; ++j) {
                String[] inputs = s.nextLine().split(" ");
                for(int k = 1; k < inputs.length; ++k) {
                    if(!mp1.containsKey(inputs[k]))
                        mp1.put(inputs[k],new ArrayList<Integer>());
                    ArrayList<Integer> list = mp1.get(inputs[k]);
                    list.add(tick);
                    mp2.put(tick++, inputs[0]);
                    ++cur;
                }
            }
            System.out.println("Day "+i + ": " + cur + " tickets given out");
            for(String str : mp1.keySet()) {
                int winner = mp1.get(str).get(ran.nextInt(mp1.get(str).size()));
                System.out.println(" "+str + ": " + mp2.get(winner) + " with ticket " + winner );
            }
        }
    }
}
