import java.util.*;

public class Problem2 {
    public static void main(String[] args ){
        Scanner s = new Scanner(System.in);
        String[] inp = s.nextLine().split(" ");
        int N = Integer.parseInt(inp[0]);
        int K = Integer.parseInt(inp[1]);
        int adjust = 1 << K;
        int pl [] = new int[adjust];
        Arrays.fill(pl, Integer.MAX_VALUE);
        Queue<Integer> q = new LinkedList<>();
        int cur = 0, high = 0;
        for(int i = 0; i < N; ++i){
            String str = s.nextLine();
            int num = Integer.parseInt(str, 2);
            pl[num] = 0;
            q.add(num);
        }
        while(q.size() > 0) {
            int on = q.poll();
            for(int i = 1; i < adjust; i<<=1) {
                int next = on ^ i;
                if(pl[next] == Integer.MAX_VALUE){ pl[next] = pl[on]+1;
                    q.add(next);
                    if(pl[next] > high ){
                        cur = next;
                        high = pl[next];
                    }

                }
            }
        }
        String fin = Integer.toBinaryString(cur);
        String add = "";
        while(fin.length() + add.length() < K)
            add += "0";
        System.out.println(add+fin);
        
        s.close();
    }
}
