import java.util.*;

public class P17 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = Integer.parseInt(s.nextLine());
        while(T-- > 0) {
            String inputs[] = s.nextLine().split(" ");
            int R = Integer.parseInt(inputs[0]), C = Integer.parseInt(inputs[1]);
            String[][] grid = new String[R][C];
            for(int i = 0; i < R; ++i) {
                String in = s.nextLine();
                String nums[] = in.split(",");
                for(int j = 0; j < nums.length; ++j)
                    grid[i][j] = nums[j];
            }

            for(int i = 0; i < C; ++i){
                for(int j = 0; j < R; ++j)
                    System.out.print((grid[j][i] == null ? "" : grid[j][i]) + (j != R-1 ? "," : ""));
                System.out.println();
            }


        }
    }
}
