import java.util.*;
import java.awt.*;
import java.io.*;



public class Problem1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int N = s.nextInt(), M = s.nextInt();
        boolean[][] vis = new boolean[N][N];
        ArrayList<Point>[][] light = new ArrayList<>[N][N];
        boolean[][] lit = new boolean[vis.length][vis.length];
        lit[0][0] = true;

        for(int i = 0; i < M; ++i) {
            light[s.nextInt()-1][s.nextInt()-1].add(new Point(s.nextInt(), s.nextInt()));
        }
        Point cur = new Point(0, 0);
        search(vis, light, 0 , new Point(0, 0), lit);


    }

    public static int search(boolean[][] vis, ArrayList<Point>[][] light, int roomsIllumned, Point cur, boolean[][] lit) {

        
        for(Point i : light[cur.x][cur.y]) {
            lit[i.x][i.y] = !lit[i.x][i.y];
            if(i.x > 1) {
                roomsIllumned += search(vis, light, roomsIllumned, new Point(cur.x-1, cur.y), lit);
            }
            if(i.x < light.length - 2){
                roomsIllumned += search(vis, light, roomsIllumned, new Point(cur.x +1 , cur.y), lit);
            }
            if(i.y > 1){
                roomsIllumned += search(vis, light, roomsIllumned, new Point(cur.x , cur.y-1), lit);
            }
            if(i.x < light.length - 2){
                roomsIllumned += search(vis, light, roomsIllumned, new Point(cur.x , cur.y+1), lit);
            }
        }
        light[cur.x][cur.y].clear();



        return roomsIllumned;
    }
}
