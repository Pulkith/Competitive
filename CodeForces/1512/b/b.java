import java.util.*;
 
public class b {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int T = Integer.parseInt(s.nextLine());
        while(T-- > 0) {
            int N = Integer.parseInt(s.nextLine());
            char grid[][] = new char[N][N];
            int p1x = 0, p1y = 0, p2x = 0, p2y = 0;
            int pt = 0;
            for(int i = 0; i < N; ++i){
                String x = s.nextLine();
                for(int j = 0; j < N; ++j){
                    char c = x.charAt(j);
                    if(c == '*'){
                        if(pt == 0) {
                            p1x = i;
                            p1y = j;
                            ++pt;
                        } else {
                            p2x = i;
                            p2y = j;
                        }
                    }
                    grid[i][j] = c;
                }
            }
            if(p1x == p2x){
                int adj = (p1x == 0 ? 1 : -1);
                grid[p1x+adj][p1y] = '*';
                grid[p2x+adj][p2y] = '*';
            }
            else if(p1y == p2y){
                int adj = (p2y == 0)  ? 1 : -1;
                grid[p1x][p1y+adj] = '*';
                grid[p2x][p1y+adj] = '*';
            }
            else {
                grid[p1x][p2y] = '*';
                grid[p2x][p1y] = '*';
            }
 
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    System.out.print(grid[i][j]);
                }
                System.out.println();
            }
 
 
        }
    }
}