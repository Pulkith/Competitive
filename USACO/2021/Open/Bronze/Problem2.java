import java.util.*;
import java.io.*;
import java.awt.*;


public class Problem2 {
  public static void main(String[] args) throws Exception {
     Scanner s = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    String nums[] = s.nextLine().split(" ");
    int N = Integer.parseInt(nums[0]);
    int R = Integer.parseInt(nums[1]);

    HashMap<String, Integer> names = new HashMap<>();
    ArrayList<String> stor = new ArrayList<>();
    String nm[] = s.nextLine().split(" ");
    for(int i = 0; i < R; ++i) {
        names.put(nm[i], i);
        stor.add(nm[i]);
    }
    int[][] grid = new int[R][R];
    for(int i = 0; i < N; ++i) {
        String line[] = s.nextLine().split(" ");
        for(int j = 1; j < line.length; ++j) {
            if(line[j-1].compareTo(line[j]) > 0) {
                int ind = names.get(line[j]);
                boolean before = false;
                for(int k  = j-1; k >= 0; --k) {
                    if(before || line[k].compareTo(line[k+1]) > 0){
                        System.out.println(link[k] + " " + link[j]);
                        int ind2 = names.get(line[k]);
                        grid[ind][ind2] = 1;
                        grid[ind2][ind] = -1;
                        before = true;
                    }
                }
            }
        }
    }
    for(int i = 0; i < stor.size(); ++i) {
        for(int j = 0; j < stor.size(); ++j) {
            String res = "";
            if(i == j) res = "B";
            else if(grid[i][j] == -1) res = "0";
            else if(grid[i][j] == 0) res = "?";
            else res = "1";
            System.out.print(res);
        }
        System.out.println();
    }

    out.close();
  }  
}
/*
2 3
elsie mildred dean
elsie mildred dean
elsie dean mildred
*/