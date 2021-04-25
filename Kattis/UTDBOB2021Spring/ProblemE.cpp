import java.util.*;
public class CollectingBeepers {
    public static void main(String args []) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 0; t < T; t++) {
            in.nextInt();
            in.nextInt();
            int sR = in.nextInt(), sC = in.nextInt();
            int N = in.nextInt();
            if (N == 0) {
                System.out.println(0);
                continue;
            }
            int[][] pos = new int[N][2];
            for (int i = 0; i < N; i++) {
                pos[i] = new int[]{in.nextInt(), in.nextInt()};
            }
            List<Integer> options = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                options.add(i);
            }
            Help res = new Help();
            res.min = Integer.MAX_VALUE;
            search(res, sR, sC, pos, options, new ArrayList<>());
            System.out.println(res.min);
        }
    }
    public static void search(Help res, int sR, int sC, int[][] pos, List<Integer> options, List<Integer> current) {
        if (options.isEmpty()) {
            res.min = Math.min(res.min, check(sR, sC, pos, current));
            return;
        }
        for (int i = 0; i < options.size(); i++) {
            int n = options.remove(i);
            current.add(n);
            search(res, sR, sC, pos, options, current);
            current.remove(current.size() - 1);
            options.add(i, n);
        }
    }
    public static int check(int sR, int sC, int[][] pos, List<Integer> order) {
        int dist = Math.abs(pos[order.get(0)][0] - sR) + Math.abs(pos[order.get(0)][1] - sC);
        for (int i = 1; i < order.size(); i++) {
            dist += Math.abs(pos[order.get(i)][0] - pos[order.get(i - 1)][0]) + Math.abs(pos[order.get(i)][1] - pos[order.get(i - 1)][1]);
        }
        dist += Math.abs(pos[order.get(order.size() - 1)][0] - sR) + Math.abs(pos[order.get(order.size() - 1)][1] - sC);
        return dist;
    }
}
class Help {
    int min;
}