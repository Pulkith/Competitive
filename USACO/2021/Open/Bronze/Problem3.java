import java.io.*;
import java.util.*;
import java.awt.*;

public class Problem3 {
    public static void main(String[] args) throws IOException {
        BufferedReader st = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = st.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]), M = Integer.parseInt(inputs[1]);
        int pairs_found = 0;
        HashSet<String> pairs = new HashSet<>();
        char[][] grid = new char[N][M];
        for (int i = 0; i < N; ++i)
            if (M >= 0)
                System.arraycopy(st.readLine().toCharArray(), 0, grid[i], 0, M);
        HashMap<String, Integer> IDS = new HashMap<>();
        ArrayList<Map.Entry<String, Integer>> grass = new ArrayList<>();
        HashMap<String, ArrayList<String>> gCows = new HashMap<>();
        int[][] perm = { { -1, 0, 1, 0 }, { 0, 1, 0, -1 } };
        int num_on = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 'C') {
                    String cowPoint = i + " " + j;
                    IDS.put(cowPoint, num_on++);
                }

                if (grid[i][j] == 'G') {
                    int grass_count = 0;
                    ArrayList<String> cur_cows = new ArrayList<>();
                    for (int k = 0; k < 4; ++k) {
                        int x = i + perm[0][k], y = j + perm[1][k];
                        if (x >= 0 && x < N && y >= 0 && y < M) {
                            if (grid[x][y] == 'C') {
                                grass_count += 1;
                                cur_cows.add(x + " " + y);
                            }
                        }
                    }
                    if (grass_count > 1) {
                        grass.add(new AbstractMap.SimpleEntry<String, Integer>(i + " " + j, grass_count));
                        gCows.put(i + " " + j, cur_cows);
                    }
                }
            }
        }
        long total = (num_on * (num_on + 1)) / 2;
        grass.sort(new Comparator<Map.Entry<String, Integer>>() {
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o1.getValue().compareTo(o2.getValue());
            }
        });
        for (Map.Entry<String, Integer> entry : grass) {
            String g = entry.getKey();
            ArrayList<String> grassCows = gCows.get(g);
            pairs_found += make_pairs(grassCows, pairs, IDS) ? 1 : 0;
            if (pairs_found == total)
                break;
        }
        System.out.println(pairs_found);

    }

    public static boolean make_pairs(ArrayList<String> possible_cows, HashSet<String> pairs,
            HashMap<String, Integer> IDS) {
        int permutations[][] = { { 0, 0, 1, 0, 1, 2 }, { 1, 2, 2, 3, 3, 3 } };
        int size = possible_cows.size();
        int pos = (size * (size - 1)) / 2;
        for (int i = 0; i < pos; ++i) {
            String i1 = possible_cows.get(permutations[0][i]), i2 = possible_cows.get(permutations[1][i]);
            int cow1 = IDS.get(i1), cow2 = IDS.get(i2), c1 = Math.max(cow1, cow2), c2 = Math.min(cow1, cow2);
            if (pairs.add(c1 + " " + c2))
                return true;
        }
        return false;
    }
}