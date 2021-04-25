import java.util.*;

public class L {
    public static void main(String[] args) {
        Scanner st = new Scanner(System.in);

        int T = Integer.parseInt(st.nextLine());
        while (T-- > 0) {
            String[] inputs = st.nextLine().split(" ");
            int r = Integer.parseInt(inputs[0]), c = Integer.parseInt(inputs[1]);
            char grid[][] = new char[r][c];
            for (int i = 0; i < r; ++i) {
                System.arraycopy(st.nextLine().toCharArray(), 0, grid[i], 0, c);
            }
            String words[] = st.nextLine().split(" ");

            HashMap<String, Integer> freq = new HashMap<>();
            for(String s : words)
                freq.put(s, 0);

            //rows
            ArrayList<String> poss = new ArrayList<>();
            for(String s : words)
                poss.add(s);
            for(char [] ar : grid) {
                String str = String.valueOf(ar);
                for(int i = 0; i < poss.size(); ++i) {
                    String s = poss.get(i);
                    if(str.contains(s)) {
                        freq.put(s, freq.get(s)+1);
                        poss.remove(s);
                        --i;
                    }
                }
            }
            for(int z = 0; z < c; ++ z) {
                String str = "";
                for(int i =0; i < r; ++i)
                    str += grid[i][z];
                    for(int i = 0; i < poss.size(); ++i) {
                        String s = poss.get(i);
                        if(str.contains(s)) {
                            freq.put(s, freq.get(s)+1);
                            poss.remove(s);
                            --i;
                        }
                    }
            }
            

            for(String s : words){
                System.out.println(s + " " + freq.get(s));
            }
        }
    }
}
